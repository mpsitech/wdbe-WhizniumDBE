/**
	* \file WdbedOpengcli.cpp
	* operation engine client for Wdbe daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbed.h"

#include "WdbedOpengcli.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbedOpengcli
 ******************************************************************************/

void* WdbedOpengcli::run(
			void* arg
		) {
	XchgWdbed* xchg = (XchgWdbed*) arg;

	NodeWdbe* node = NULL;

	pthread_attr_t attr;

	WdbedOpprc_arg* opprc_arg = NULL;

	multimap<ubigint,pthread_t> opprcs;

	string url;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	ubigint nref_backup;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, 0);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	xchg->cStable.signal("WdbedOpengcli", "run");

	while (true) {
		xchg->cOpengcli.lockMutex("WdbedOpengcli", "run");
		while (!xchg->termOpengcli && !run_checkNodes(xchg)) xchg->cOpengcli.wait("WdbedOpengcli", "run");

		xchg->rwmNodes.wlock("WdbedOpengcli", "run");

		for (auto it = xchg->nodes.begin(); it != xchg->nodes.end(); it++) {
			node = it->second;
			
			if (xchg->termOpengcli || (node->ixVState == NodeWdbe::VecVState::ERROR) || (node->ixVState == NodeWdbe::VecVState::TERM)) {
				auto rng = opprcs.equal_range(node->nref);
				for (auto it2 = rng.first; it2 != rng.second; it2++) {
					pthread_cancel(it2->second);
					pthread_join(it2->second, NULL);
				};
				opprcs.erase(rng.first, rng.second);

				if ((node->ixVState == NodeWdbe::VecVState::READY) || (node->ixVState == NodeWdbe::VecVState::TERM)) {
					// POST content (DpchWdbedQuit)
					Xmlio::startwriteBuffer(&wr, &xbuf);
						DpchWdbedQuit::writeXML(wr);
					Xmlio::closewriteBuffer(wr);

					if (CurlPostDpch("http://" + node->ip + ":" + to_string(node->port) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
						// evaluate reply
						if (rplydpch == "dpchwdbeopdack") {
							// acknowledged
						};

					} else {
						// cout << "\terror notifying op engine!" << endl;
					};

					if (docctx) xmlXPathFreeContext(docctx);
					if (doc) xmlFreeDoc(doc);
					xmlBufferFree(xbuf);
				};

				node->ixVState = NodeWdbe::VecVState::DONE;

			} else if (node->ixVState == NodeWdbe::VecVState::IDLE) {
				for (unsigned int i = 0; i < node->opprcn; i++) {
					opprc_arg = new WdbedOpprc_arg(); // will be deleted by new thread

					opprc_arg->xchg = xchg;
					opprc_arg->node = node;

					auto it2 = opprcs.insert(pair<ubigint,pthread_t>(node->nref, 0));
					pthread_create(&(it2->second), &attr, &WdbedOpprc::run, (void*) opprc_arg);
				};

				node->ixVState = NodeWdbe::VecVState::READY;
			};
		};

		for (auto it = xchg->nodes.begin(); it != xchg->nodes.end();) {
			node = it->second;

			if (xchg->termOpengcli || (node->ixVState == NodeWdbe::VecVState::DONE)) {
				nref_backup = it->first;

				delete it->second;
				it = xchg->nodes.erase(it);

				xchg->mon.eventRemoveNode(nref_backup);

				xchg->triggerCall(NULL, VecWdbeVCall::CALLWDBENODECHG, xchg->jrefRoot);

			} else it++;
		};

		xchg->rwmNodes.wunlock("WdbedOpengcli", "run");
		xchg->cOpengcli.unlockMutex("WdbedOpengcli", "run");

		if (xchg->termOpengcli) break;
	};

	return NULL;
};

bool WdbedOpengcli::run_checkNodes(
			XchgWdbe* xchg
		) {
	bool retval = false;

	NodeWdbe* node = NULL;

	xchg->rwmNodes.rlock("WdbedOpengcli", "run_checkNodes");

	for (auto it = xchg->nodes.begin(); it != xchg->nodes.end(); it++) {
		node = it->second;

		if ((node->ixVState == NodeWdbe::VecVState::IDLE) || (node->ixVState == NodeWdbe::VecVState::ERROR) || (node->ixVState == NodeWdbe::VecVState::TERM)) {
			retval = true;
			break;
		};
	};

	xchg->rwmNodes.runlock("WdbedOpengcli", "run_checkNodes");

	return retval;
};

bool WdbedOpengcli::CurlPostDpch(
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

	WdbedOpengcli_curlarg curlarg = {.buf = NULL, .buflen = 0};

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
  	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlarg);

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

		curlres = curl_easy_perform(curl);

		delete[] buf;

		// evaluate result
		if ((curlres == CURLE_OK) && curlarg.buf) {
			// check for root XML node
			Xmlio::parseBuffer(curlarg.buf, curlarg.buflen, rplydoc, rplydocctx);
			rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));

			retval = true;
		};

		if (curlarg.buf) {
			delete[] curlarg.buf;
			curlarg.buf = NULL;

			curlarg.buflen = 0;
		};

		curl_slist_free_all(chunk);

		curl_easy_cleanup(curl);
	};

	return retval;
};

uint WdbedOpengcli::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _arg
		) {
	WdbedOpengcli_curlarg* arg = (WdbedOpengcli_curlarg*) _arg;

	char* olddata;

	if (size > 0) {
		if (!arg->buf) {
			arg->buf = new char[size*blocksize];
			memcpy(arg->buf, data, size*blocksize);
			arg->buflen = size*blocksize;

		} else {
			olddata = arg->buf;

			arg->buf = new char[arg->buflen + size*blocksize];
			memcpy(arg->buf, olddata, arg->buflen);
			memcpy(&(arg->buf[arg->buflen]), data, size*blocksize);
			arg->buflen = arg->buflen + size*blocksize;

			delete[] olddata;
		};
	};

	return(size*blocksize);
};
