/**
	* \file WdbeopdEngsrv.cpp
	* engine server for Wdbe operation daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbeopd.h"

#include "WdbeopdEngsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeopdEngsrv
 ******************************************************************************/

MHD_Daemon* WdbeopdEngsrv::start(
			XchgWdbeopd* xchg
		) {
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwdbeopd.engsrvportbase + xchg->stgwdbeopd.engsrvportofs, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void WdbeopdEngsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

MHD_Result WdbeopdEngsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

MHD_Result WdbeopdEngsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWdbeopd* xchg = (XchgWdbeopd*) cls;

	MHD_Response* response;
	MHD_Result retval = MHD_YES;

	ReqopWdbe* req = NULL;

	ReqopWdbe* prcreq = NULL;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string scrOref;

	uint ixWdbeVDpch;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s;

	if (*con_cls == NULL) {
		// new request
		addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

		if (addr->sa_family == AF_INET) {
#ifdef _WIN32
			ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
			inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
			ip = ipstr;
#endif
		};

		// only allow requests from engine
		if (ip == xchg->stgwdbeopd.engip) {
			s = string(url);

			if (strcmp(method, "GET") == 0) {
				if (s.find("/poll") != string::npos) {
					// always "/poll/abcd1234efgh5678"
					req = new ReqopWdbe(ReqopWdbe::VecVBasetype::POLL, ReqopWdbe::VecVState::RECEIVE);
					*con_cls = req;

					scrOref = s.substr(s.find("/poll/")+6);
				};

			} else if (strcmp(method, "POST") == 0) {
				if (s.find("/dpch") != string::npos) {
					// always "/dpch"
					req = new ReqopWdbe(ReqopWdbe::VecVBasetype::DPCHINV, ReqopWdbe::VecVState::RECEIVE);
					*con_cls = req;

					// prepare POST processor
					req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);
					retval = MHD_YES;
				};
			};
		};

		if (req == NULL) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			if (req->ixVBasetype == ReqopWdbe::VecVBasetype::POLL) {
				// send return dispatch or progress update
				prcreq = xchg->getPrcreqByScrOref(scrOref);
				
				if (prcreq) {
					if (prcreq->ixVState == ReqopWdbe::VecVState::REPLY) {
						xchg->pullPrcreq(scrOref);
						delete req;

						req = prcreq;
						*con_cls = req;

					} else {
						req->dpchret = new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, prcreq->dpchinv->scrOref, prcreq->dpchinv->scrJref, VecOpVOpres::PROGRESS, prcreq->pdone);
					};
					prcreq->cReady.unlockMutex("WdbeopdEngsrv", "MhdCallback");

				} else {
					req->dpchret = new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, scrOref, "", VecOpVOpres::PROGRESS, 0);
				};

				if (req->dpchret) {
					writeDpchRet(req);
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				} else {
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active request (GET: should not go through here ; POST: DPCHINV)
		req = (ReqopWdbe*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

				retval = MHD_YES;

			} else {
				// POST done
				// cout << "MhdCallback() request complete" << endl;

				if (req->request) {
					//cout << string(req->request, req->requestlen) << endl;
					ixWdbeVDpch = readDpchInv(req);

					if (ixWdbeVDpch == VecWdbeVDpch::DPCHWDBEDQUIT) {
						writeDpchAck(req);
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

						// notify main thread by signalling termination condition
						xchg->cTerm.signal("WdbeopdEngsrv", "MhdCallback");

					} else if (req->dpchinv) {
						// pass to opprc
						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WdbeopdEngsrv", "MhdCallback");
						if (req->ixVState != ReqopWdbe::VecVState::REPLY) req->cReady.timedwait(5000000, "WdbeopdEngsrv", "MhdCallback");

						if (req->ixVState == ReqopWdbe::VecVState::REPLY) {
							xchg->pullPrcreq(req->dpchinv->scrOref);

							req->cReady.unlockMutex("WdbeopdEngsrv", "MhdCallback");

						} else {
							prcreq = req;

							req = new ReqopWdbe(ReqopWdbe::VecVBasetype::POLL, ReqopWdbe::VecVState::REPLY);
							*con_cls = req;

							req->dpchret = new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, prcreq->dpchinv->scrOref, prcreq->dpchinv->scrJref, VecOpVOpres::PROGRESS, prcreq->pdone);

							prcreq->cReady.unlockMutex("WdbeopdEngsrv", "MhdCallback");
						};

						if (req->dpchret) {
							writeDpchRet(req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

				} else {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};
	};

	return retval;
};

MHD_Result WdbeopdEngsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqopWdbe* req = (ReqopWdbe*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	// copy data into req->request (append if required)
	if (strcmp(key, "xml") != 0) return MHD_NO;

	if (size > 0) {
		if (!req->request) {
			req->request = new char[size];
			memcpy(req->request, data, size);
			req->requestlen = size;

		} else {
			olddata = req->request;

			req->request = new char[req->requestlen + size];
			memcpy(req->request, olddata, req->requestlen);
			memcpy(&(req->request[req->requestlen]), data, size);
			req->requestlen = req->requestlen + size;

			delete[] olddata;
		};
	};

	return MHD_YES;
};

void WdbeopdEngsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqopWdbe* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqopWdbe*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

uint WdbeopdEngsrv::readDpchInv(
			ReqopWdbe* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixWdbeVDpch = VecWdbeVDpch::getIx(extractRoot(doc));

	if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBE) {
		req->dpchinv = new DpchInvWdbe();
		((DpchInvWdbe*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
		req->dpchinv = new DpchInvWdbeMtpPlhfpga();
		((DpchInvWdbeMtpPlhfpga*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
		req->dpchinv = new DpchInvWdbeMtpPlhmcu();
		((DpchInvWdbeMtpPlhmcu*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU) {
		req->dpchinv = new DpchInvWdbeMtpCplmstbu();
		((DpchInvWdbeMtpCplmstbu*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD) {
		req->dpchinv = new DpchInvWdbeMtpCplmsttd();
		((DpchInvWdbeMtpCplmsttd*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
		req->dpchinv = new DpchInvWdbeMtpGenfst();
		((DpchInvWdbeMtpGenfst*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA) {
		req->dpchinv = new DpchInvWdbeMtpWrfpga();
		((DpchInvWdbeMtpWrfpga*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
		req->dpchinv = new DpchInvWdbeMtpWrmcu();
		((DpchInvWdbeMtpWrmcu*) (req->dpchinv))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWdbeVDpch;
};

void WdbeopdEngsrv::writeDpchAck(
			ReqopWdbe* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchWdbeopdAck::writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

void WdbeopdEngsrv::writeDpchRet(
			ReqopWdbe* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		req->dpchret->writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};
