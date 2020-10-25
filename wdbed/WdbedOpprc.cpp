/**
	* \file WdbedOpprc.cpp
	* remote operation processor for Wdbe daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "Wdbed.h"

#include "WdbedOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbedOpprc
 ******************************************************************************/

void* WdbedOpprc::run(
			void* _arg
		) {
	WdbedOpprc_arg* arg = (WdbedOpprc_arg*) _arg;
	XchgWdbed* xchg = arg->xchg;
	NodeWdbe* node = arg->node;

	delete arg;

	CURL* curl = NULL;
	CURLcode curlres;
	curl_slist* chunk = NULL;

	ReqWdbe* req = NULL;

	DpchInvWdbe* inv = NULL;

	ubigint oref, jref;

	string url;

	unsigned int deltat;

	bool term = false;

	WdbedOpprc_cuarg* cuarg = new WdbedOpprc_cuarg();
	cuarg->xchg = xchg;
	cuarg->req = &req;
	cuarg->oref = &oref;
	cuarg->jref = &jref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, cuarg);

	curl = curl_easy_init();

	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

	chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);

	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

	curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);

	// main loop: wait for operation invocations
	while (true) {
		xchg->cOpprcs.lockMutex("WdbedOpprc", "run");
		inv = xchg->pullFirstInv(node);

		while (!inv) {
			xchg->cOpprcs.wait("WdbedOpprc", "run");
			inv = xchg->pullFirstInv(node);
		};

		xchg->cOpprcs.unlockMutex("WdbedOpprc", "run");

		req = new ReqWdbe(ReqWdbe::VecVBasetype::DPCHRET);

		req->jref = inv->jref;
		req->dpchinv = inv;
		writeDpchInv(curl, xchg, req);

		oref = inv->oref;
		jref = inv->jref;

		url = "http://" + node->ip + ":" + to_string(node->port) + "/dpch";
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		curl_easy_setopt(curl, CURLOPT_POST, 1);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, req);

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, req->request);

		curlres = curl_easy_perform(curl);

		if ((curlres == CURLE_OK) && req->reply) {
			//cout << string(req->reply, req->replylen) << endl;
			readDpchRet(xchg, req);

			deltat = 5;

			while ((req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBE) && (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS)) {
				xchg->addReq(req); // req is destroyed in the process

				req = new ReqWdbe(ReqWdbe::VecVBasetype::DPCHRET);
				req->jref = jref;

				sleep(deltat);

				if (deltat == 5) deltat = 10;
				else if (deltat == 10) deltat = 20;
				else if (deltat == 20) deltat = 40;
				else deltat = 60;

				url = "http://" + node->ip + ":" + to_string(node->port) + "/poll/" + Scr::scramble(oref);
				curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

				curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

				curl_easy_setopt(curl, CURLOPT_WRITEDATA, req);

				curlres = curl_easy_perform(curl);

				if ((curlres == CURLE_OK) && req->reply) {
					//cout << string(req->reply, req->replylen) << endl;
					readDpchRet(xchg, req);

				} else {
					req->dpchret = new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", VecOpVOpres::COMMERR, 0);
					req->dpchret->oref = oref;
					req->dpchret->jref = jref;

					term = true;
					break;
				};
			};

			xchg->addReq(req); // req is destroyed in the process
			req = NULL;

		} else {
			// something went wrong, return inv to list
			xchg->returnInv(inv);

			req->dpchinv = NULL;
			delete req;
			req = NULL;

			term = true;
		};

		if (term) break;
	};

	curl_slist_free_all(chunk);

	curl_easy_cleanup(curl);

	// notify opengcli of troubled state of node ; arrive here only if communication error was detected by this thread
	xchg->setNodeState(node, NodeWdbe::VecVState::ERROR);

	pthread_cleanup_pop(0);

	return(NULL);
};

void WdbedOpprc::cleanup(
			void* _arg
		) {
	WdbedOpprc_cuarg* arg = (WdbedOpprc_cuarg*) _arg;
	XchgWdbed* xchg = arg->xchg;
	ReqWdbe* req = *(arg->req);
	ubigint oref = *(arg->oref);
	ubigint jref = *(arg->jref);

	delete arg;

	if (req) {
		req->dpchret = new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", VecOpVOpres::COMMERR, 0);
		req->dpchret->oref = oref;
		req->dpchret->jref = jref;

		xchg->addReq(req);
	};

	xchg->cOpprcs.unlockMutex("WdbedOpprc", "cleanup");
};

uint WdbedOpprc::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _req
		) {
	ReqWdbe* req = (ReqWdbe*) _req;

	char* olddata;

	if (size > 0) {
		if (!req->reply) {
			req->reply = new char[size*blocksize];
			memcpy(req->reply, data, size*blocksize);
			req->replylen = size*blocksize;

		} else {
			olddata = req->reply;

			req->reply = new char[req->replylen + size*blocksize];
			memcpy(req->reply, olddata, req->replylen);
			memcpy(&(req->reply[req->replylen]), data, size*blocksize);
			req->replylen = req->replylen + size*blocksize;

			delete[] olddata;
		};
	};

	return(size*blocksize);
};

void WdbedOpprc::writeDpchInv(
			CURL* curl
			, XchgWdbed* xchg
			, ReqWdbe* req
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	char* buf;
	char* buf_old;
	size_t buflen;

	startwriteBuffer(&wr, &xbuf);
		req->dpchinv->writeXML(wr);
	closewriteBuffer(wr);

	// string to be sent is "xml=<xbuf>"
	buflen = xbuf->use + 4;
	buf = new char[buflen];

	buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '-';
	memcpy(&(buf[4]), xbuf->content, xbuf->use);

	xmlBufferFree(xbuf);

	buf_old = buf;
	buf = curl_easy_escape(curl, buf, buflen);
	delete[] buf_old;

	buf[3] = '=';

	req->request = buf;
	req->requestlen = strlen(buf);
};

uint WdbedOpprc::readDpchRet(
			XchgWdbed* xchg
			, ReqWdbe* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->reply, req->replylen, &doc, &docctx);

	uint ixWdbeVDpch = VecWdbeVDpch::getIx(extractRoot(doc));

	if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBE) {
		req->dpchret = new DpchRetWdbe();
		((DpchRetWdbe*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMODDETWIRING) {
		req->dpchret = new DpchRetWdbeModdetWiring();
		((DpchRetWdbeModdetWiring*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMTPPLHFPGA) {
		req->dpchret = new DpchRetWdbeMtpPlhfpga();
		((DpchRetWdbeMtpPlhfpga*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMTPPLHMCU) {
		req->dpchret = new DpchRetWdbeMtpPlhmcu();
		((DpchRetWdbeMtpPlhmcu*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGACMDINV) {
		req->dpchret = new DpchRetWdbePlhfpgaCmdinv();
		((DpchRetWdbePlhfpgaCmdinv*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGACMDRET) {
		req->dpchret = new DpchRetWdbePlhfpgaCmdret();
		((DpchRetWdbePlhfpgaCmdret*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGAEHOSTIF) {
		req->dpchret = new DpchRetWdbePlhfpgaEhostif();
		((DpchRetWdbePlhfpgaEhostif*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGAFWDCTR) {
		req->dpchret = new DpchRetWdbePlhfpgaFwdctr();
		((DpchRetWdbePlhfpgaFwdctr*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHMCUEHOSTIF) {
		req->dpchret = new DpchRetWdbePlhmcuEhostif();
		((DpchRetWdbePlhmcuEhostif*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPRCTREEEXTRACT) {
		req->dpchret = new DpchRetWdbePrctreeExtract();
		((DpchRetWdbePrctreeExtract*) (req->dpchret))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPRCTREEMERGE) {
		req->dpchret = new DpchRetWdbePrctreeMerge();
		((DpchRetWdbePrctreeMerge*) (req->dpchret))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWdbeVDpch;
};

