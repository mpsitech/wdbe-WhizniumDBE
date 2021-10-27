/**
	* \file Wdbecmbd_exe.cpp
	* Wdbe combined daemon main (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbeopd.h"

#include "Wdbeopd_exe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

Wdbeopd* wdbeopd;

/******************************************************************************
 class Wdbeopd
 ******************************************************************************/

Wdbeopd::Wdbeopd(
			const string& exedir
			, const usmallint engsrvportofs
		) {
	pthread_attr_t attr;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	srand(time(NULL));

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	mysql_library_init(0, NULL, NULL);
#endif

	// 1. create exchange object
	xchg = new XchgWdbeopd();
	xchg->exedir = exedir;

	// 2. load preferences
	loadPref();

	if (engsrvportofs != 0) xchg->stgwdbeopd.engsrvportofs = engsrvportofs;

	// 3. connect to database
	dbswdbe.init(xchg->stgwdbedatabase.ixDbsVDbstype, xchg->stgwdbedatabase.dbspath, xchg->stgwdbedatabase.dbsname, xchg->stgwdbedatabase.ip
			, xchg->stgwdbedatabase.port, xchg->stgwdbedatabase.username, xchg->stgwdbedatabase.password);

	// 4. initialize shared data
	xchg->shrdatOpprc.init(xchg, &dbswdbe);

	// 5. start op processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	cout << "\tstarting " << xchg->stgwdbeopd.opprcn << " operation processor threads ... {" << flush;

	for (unsigned int i = 0; i < xchg->stgwdbeopd.opprcn; i++) {
		if (i != 0) cout << ", " << flush;

		xchg->cStable.lockMutex("Wdbeopd", "Wdbeopd");

		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &WdbeopdOpprc::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Wdbeopd", "Wdbeopd");
	};

	cout << "} success" << endl;

	pthread_attr_destroy(&attr);

	// 6. start engine server
	cout << "\tstarting engine server ..." << flush;
	engsrv = WdbeopdEngsrv::start(xchg);
	cout << " success" << endl;

	// 7. cURL to WdbedOpengsrv with DpchWdbeopdReg to retrieve scrNref
	Xmlio::startwriteBuffer(&wr, &xbuf);
		DpchWdbeopdReg::writeXML(wr, xchg->stgwdbeopd.engsrvportbase + xchg->stgwdbeopd.engsrvportofs, VecWdbeVOpengtype::WDBEOPD2, xchg->stgwdbeopd.opprcn);
	Xmlio::closewriteBuffer(wr);

	if (CurlPostDpch("http://" + xchg->stgwdbeopd.engip + ":" + to_string(xchg->stgwdbeopd.engport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
		// evaluate reply
		if (rplydpch == "dpchwdbedreg") {
			DpchWdbedReg* dpchwdbedreg = new DpchWdbedReg();
			dpchwdbedreg->readXML(docctx, "/", true);

			xchg->scrNref = dpchwdbedreg->scrNref;

			delete dpchwdbedreg;
		};

		xmlXPathFreeContext(docctx);
		xmlFreeDoc(doc);

	} else {
		xmlBufferFree(xbuf);

		throw SbeException(SbeException::ENGCONN, {});
	};

	xmlBufferFree(xbuf);
};

Wdbeopd::~Wdbeopd() {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	// 1. cURL to WdbedOpengsrv with DpchWdbeOpengUnreg ; note that this will fail in case the termination was initiated by the engine

	// POST content (DpchWdbeopdUnreg)
	Xmlio::startwriteBuffer(&wr, &xbuf);
		DpchWdbeopdUnreg::writeXML(wr, xchg->scrNref);
	Xmlio::closewriteBuffer(wr);

	if (CurlPostDpch("http://" + xchg->stgwdbeopd.engip + ":" + to_string(xchg->stgwdbeopd.engport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
		// evaluate reply
		if (rplydpch == "dpchwdbedack") {
			// acknowledged
		};

	} else {
		// cout << "\terror disconnecting from engine!" << endl;
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	xmlBufferFree(xbuf);

	// 2. stop engine server
	WdbeopdEngsrv::stop(engsrv);

	// 3. end op processor threads
	for (unsigned int i = 0; i < opprcs.size(); i++) {
		//if (opprcs[i]) {
			pthread_cancel(opprcs[i]);
			pthread_join(opprcs[i], NULL);
		//};
	};

	// 4. terminate shared data
	xchg->shrdatOpprc.term(xchg);

	// 5. store preferences
	if (xchg->stgwdbeopd.engsrvportofs == 0) storePref();

	// 6. delete exchange object
	delete xchg;
};

bool Wdbeopd::CurlPostDpch(
			const string& url
			, xmlBuffer* xbuf
			, xmlDoc** rplydoc
			, xmlXPathContext** rplydocctx
			, string& rplydpch
		) {
	bool retval = false;

	CURL* curl;
	CURLcode curlres;
	curl_slist* chunk = NULL;

	char* buf;
	char* buf_old;
	size_t buflen;

	curl = curl_easy_init();

	if (curl) {
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

		curl_easy_setopt(curl, CURLOPT_POST, 1);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
  	curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);

		// string to be sent is "xml=<xbuf (URI encoded)>"
		buflen = xbuf->use + 4;
		buf = new char[buflen];

		buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '-';
		memcpy(&(buf[4]), xbuf->content, xbuf->use);

		buf_old = buf;
		buf = curl_easy_escape(curl, buf, buflen);
		delete[] buf_old;

		buf[3] = '=';

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);

		// receive buffer
		if (curlbuf) delete[] curlbuf;
		curlbuf = NULL;
		curlbuflen = 0;

		curlres = curl_easy_perform(curl);

		delete[] buf;

		// evaluate result
		if ((curlres == CURLE_OK) && curlbuf) {
			// check for root XML node
			Xmlio::parseBuffer(curlbuf, curlbuflen, rplydoc, rplydocctx);
			rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));

			retval = true;
		};

		if (curlbuf) {
			delete[] curlbuf;
			curlbuf = NULL;

			curlbuflen = 0;
		};

		curl_slist_free_all(chunk);

		curl_easy_cleanup(curl);
	};

	return retval;
};

uint Wdbeopd::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _inst
		) {
	Wdbeopd* inst = (Wdbeopd*) _inst;

	char* olddata;

	if (size > 0) {
		if (!inst->curlbuf) {
			inst->curlbuf = new char[size*blocksize];
			memcpy(inst->curlbuf, data, size*blocksize);
			inst->curlbuflen = size*blocksize;

		} else {
			olddata = inst->curlbuf;

			inst->curlbuf = new char[inst->curlbuflen + size*blocksize];
			memcpy(inst->curlbuf, olddata, inst->curlbuflen);
			memcpy(&(inst->curlbuf[inst->curlbuflen]), data, size*blocksize);
			inst->curlbuflen = inst->curlbuflen + size*blocksize;

			delete[] olddata;
		};
	};

	return(size*blocksize);
};

void Wdbeopd::loadPref() {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	string basexpath;

	parseFile(xchg->exedir + "/PrefWdbeopd.xml", &doc, &docctx);

	if (checkUclcXPaths(docctx, basexpath, "/", "PrefWdbeopd")) {
		xchg->stgwdbedatabase.readXML(docctx, basexpath, true);
		xchg->stgwdbemonitor.readXML(docctx, basexpath, true);
		xchg->stgwdbeopd.readXML(docctx, basexpath, true);
		xchg->stgwdbepath.readXML(docctx, basexpath, true);
	};

	closeParsed(doc, docctx);

	xchg->acvpath = xchg->stgwdbepath.acvpath;
#ifdef _WIN32
	if (_access(xchg->acvpath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#else
	if (access(xchg->acvpath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#endif

	xchg->tmppath = xchg->stgwdbepath.tmppath;
#ifdef _WIN32
	if (_access(xchg->tmppath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#else
	if (access(xchg->tmppath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#endif

	xchg->helpurl = xchg->stgwdbepath.helpurl;
};

void Wdbeopd::storePref() {
	xmlTextWriter* wr = NULL;

	startwriteFile(xchg->exedir + "/PrefWdbeopd.xml", &wr);
	xmlTextWriterStartElement(wr, BAD_CAST "PrefWdbeopd");
		xchg->stgwdbedatabase.writeXML(wr);
		xchg->stgwdbemonitor.writeXML(wr);
		xchg->stgwdbeopd.writeXML(wr);
		xchg->stgwdbepath.writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};

/******************************************************************************
 settings for operation packs and operations
 ******************************************************************************/

/******************************************************************************
 shared data for operation packs and operations
 ******************************************************************************/

/******************************************************************************
 main program
 ******************************************************************************/

void handleSignal(
			int sig
		) {
	// deleting wdbed forces PrefWdbeopd to be written
	if (wdbeopd) delete wdbeopd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	string s;
	usmallint engsrvportofs = 0;

	XchgWdbeopd* xchg;

	wdbeopd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// evaluate command line options
	for (int i = 1; i < argc; i++) {
		s = argv[i];

		if (s.find("-exedir=") == 0) exedir = s.substr(8);
		else if (s.find("-engsrvportofs=") == 0) engsrvportofs = atoi(s.substr(15).c_str());
	};

	if (exedir == "") {
		// determine executable path
		buf = new char[4096];

		if (readlink("/proc/self/exe", buf, 4096) >= 1) {
			exedir = buf;

		} else {
			if (strlen(argv[0]) >= 1) {
				exedir = argv[0];

				if (exedir[0] != '/') {
					if (getcwd(buf, 4096)) {
						exedir = "/" + exedir;
						exedir = buf + exedir;
					};
				};
			};
		};

		delete[] buf;

		ptr = exedir.rfind('/');
		if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);
	};

	try {
		// calls wdbeopd.init()
		wdbeopd = new Wdbeopd(exedir, engsrvportofs);
		xchg = wdbeopd->xchg;

		cout << "Connected and ready." << endl;

		// wait on term condition (triggered on termination of wdbed and signals)
		xchg->cTerm.lockMutex("", "main");
		xchg->cTerm.wait("", "main");
		xchg->cTerm.unlockMutex("", "main");

		delete wdbeopd;

	} catch (WdbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;
	};

	return(0);
};
