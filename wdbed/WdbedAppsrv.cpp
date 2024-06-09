/**
	* \file WdbedAppsrv.cpp
	* application server for Wdbe daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbed.h"

#include "WdbedAppsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbedAppsrv
 ******************************************************************************/

MHD_Daemon* WdbedAppsrv::start(
			XchgWdbed* xchg
		) {
	if (xchg->stgwdbeappsrv.https) {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL | MHD_USE_SSL, xchg->stgwdbeappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_HTTPS_MEM_KEY, xchg->key.c_str(), MHD_OPTION_HTTPS_MEM_CERT, xchg->cert.c_str(), MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	} else {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwdbeappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	};
};

void WdbedAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

MHD_Result WdbedAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

MHD_Result WdbedAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWdbe* xchg = (XchgWdbe*) cls;

	MHD_Response* response;
	MHD_Result retval = MHD_YES;

	ReqWdbe* req;

	uint ixVBasetype = ReqWdbe::VecVBasetype::NONE;
	string filename;
	bool jsonNotXml = false;
	string scrJref;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixWdbeVDpch;

	ubigint jrefNotify;

	DcolWdbe* dcol;

	vector<string> ss;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		StrMod::stringToVector(string(url), ss, '/');

		if (strcmp(method, "OPTIONS") == 0) {
			if (ss.size() >= 1) if (ss[0] == "") {
				if ((ss[1] == "dpch") || (ss[1] == "notify") || (ss[1] == "poll") || (ss[1] == "upload")) ixVBasetype = ReqWdbe::VecVBasetype::PREFLIGHT;
			};

		} else if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << string(url) << "'" << endl;

			if (ss.size() >= 1) if (ss[0] == "") {

				if (ss.size() == 2) {
					if (ss[1] == "") ixVBasetype = ReqWdbe::VecVBasetype::REDIRECT;

				} else if (ss.size() >= 3) {
					if (ss[1] == "web") {
						// ex. "/web/CrdWdbeNav/CrdWdbeNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url
						ixVBasetype = ReqWdbe::VecVBasetype::WEB;

						filename = xchg->stgwdbepath.webpath;

						for (unsigned int i = 2; i < ss.size(); i++) {
							// inhibit requests to ../ directories
							if (ss[i] != "..") filename += "/" + ss[i];
							else {
								ixVBasetype = ReqWdbe::VecVBasetype::NONE;
								break;
							};
						};

						if (ixVBasetype == ReqWdbe::VecVBasetype::WEB) {
							// cout << "request for '" << s << "' by html transfer" << endl;

							// check if file exists
							if (access(filename.c_str(), R_OK) != 0) ixVBasetype = ReqWdbe::VecVBasetype::NONE;
						};

					} else {
						if (ss[1] == "notify") ixVBasetype = ReqWdbe::VecVBasetype::NOTIFY;
						else if (ss[1] == "poll") ixVBasetype = ReqWdbe::VecVBasetype::POLL;
						else if (ss[1] == "download") ixVBasetype = ReqWdbe::VecVBasetype::DOWNLOAD;

						if (ixVBasetype != ReqWdbe::VecVBasetype::NONE) {
							// ex. "/{notify/poll/download}[/{json vs. xml}]/abcd1234efgh5678"
							if (ss.size() == 3) scrJref = ss[2];
							else if (ss.size() == 4) {
								jsonNotXml = (ss[2] == "json");

								if (jsonNotXml || (ss[2] == "xml")) scrJref = ss[3];
								else ixVBasetype = ReqWdbe::VecVBasetype::NONE;

							} else ixVBasetype = ReqWdbe::VecVBasetype::NONE;
						};
					};
				};
			};

		} else if (strcmp(method, "POST") == 0) {

			if (ss.size() >= 1) if (ss[0] == "") {

				if ((ss.size() == 2) && (ss[1] == "dpch")) {
					// always "/dpch"
					ixVBasetype = ReqWdbe::VecVBasetype::DPCHAPP;

				} else if ((ss.size() == 3) && (ss[1] == "upload")) {
					// ex. "/upload/abcd1234efgh5678"
					ixVBasetype = ReqWdbe::VecVBasetype::UPLOAD;
					scrJref = ss[2];
				};
			};
		};

		if (ixVBasetype == ReqWdbe::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else if (ixVBasetype == ReqWdbe::VecVBasetype::REDIRECT) {
			ss = {"index.html", "CrdWdbeStart/CrdWdbeStart.html"};

			for (unsigned int i = 0; i < ss.size(); i++) {
				filename = xchg->stgwdbepath.webpath + "/" + ss[i];
				valid = (access(filename.c_str(), R_OK) == 0);

				if (valid) {
					filename = "/web/" + ss[i];
					break;
				};
			};

			if (valid) {
				response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
				MHD_add_response_header(response, MHD_HTTP_HEADER_LOCATION, filename.c_str());
				retval = MHD_queue_response(connection, MHD_HTTP_MOVED_PERMANENTLY, response);
				MHD_destroy_response(response);
			};

			if (!valid) {
				response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
				retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
				MHD_destroy_response(response);
			};

		} else if (ixVBasetype == ReqWdbe::VecVBasetype::PREFLIGHT) {
			response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
			MHD_add_response_header(response, MHD_HTTP_HEADER_ALLOW, "OPTIONS, GET, POST");
			MHD_add_response_header(response, MHD_HTTP_HEADER_ACCEPT, MHD_HTTP_POST_ENCODING_FORM_URLENCODED);
			if (xchg->stgwdbeappsrv.cors != "") MHD_add_response_header(response, MHD_HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN, xchg->stgwdbeappsrv.cors.c_str());
			MHD_add_response_header(response, "Access-Control-Allow-Methods", "GET, POST");
			MHD_add_response_header(response, "Access-Control-Allow-Headers", "*");
			retval = MHD_queue_response(connection, MHD_HTTP_NO_CONTENT, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqWdbe(ixVBasetype, ReqWdbe::VecVState::RECEIVE, ip);
			*con_cls = req;

			if (req->ixVBasetype == ReqWdbe::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = filename;

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecWdbeVMimetype::getTitle(VecWdbeVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecWdbeVMimetype::getTitle(VecWdbeVMimetype::TXT);
					MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_TYPE, mimetype.c_str());					

					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jsonNotXml = jsonNotXml;

				req->jref = Scr::descramble(scrJref);
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixWdbeVLocale = dcol->ixWdbeVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngWdbeAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("WdbedAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngWdbeSuspend(req->jref);

							dcol->unlockAccess("WdbedAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngWdbeAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							req->cReady.lockMutex("WdbedAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("WdbedAppsrv", "MhdCallback[3]");
							req->cReady.timedwait(15000000, "WdbedAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							req->cReady.unlockMutex("WdbedAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("WdbedAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngWdbeConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqWdbe::VecVState::REPLY;

						// send reply ; note that the result of timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						if (xchg->stgwdbeappsrv.cors != "") MHD_add_response_header(response, MHD_HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN, xchg->stgwdbeappsrv.cors.c_str());
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("WdbedAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqWdbe::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						if (xchg->stgwdbeappsrv.cors != "") MHD_add_response_header(response, MHD_HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN, xchg->stgwdbeappsrv.cors.c_str());
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jsonNotXml = jsonNotXml;

				req->jref = Scr::descramble(scrJref);
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixWdbeVLocale = dcol->ixWdbeVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngWdbeAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("WdbedAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqWdbe::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(scrJref);

				// generate file in tmp directory, and open it
				req->filename = xchg->stgwdbepath.tmppath + "/" + Tmp::newfile(xchg->stgwdbepath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(scrJref);

				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					req->cReady.lockMutex("WdbedAppsrv", "MhdCallback[2]");
					if (req->ixVState != ReqWdbe::VecVState::REPLY) req->cReady.wait("WdbedAppsrv", "MhdCallback[1]");
					req->cReady.unlockMutex("WdbedAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: DPCHAPP, UPLOAD)
		req = (ReqWdbe*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() DPCHAPP request complete" << endl;
					valid = req->request;
					
					if (valid) {
						// cout << string(req->request, req->requestlen) << endl;
						ixWdbeVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPROOTWDBELOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WdbedAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqWdbe::VecVState::REPLY) req->cReady.wait("WdbedAppsrv", "MhdCallback[2]");
						req->cReady.unlockMutex("WdbedAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							if (xchg->stgwdbeappsrv.cors != "") MHD_add_response_header(response, MHD_HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN, xchg->stgwdbeappsrv.cors.c_str());
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						req->cReady.lockMutex("WdbedAppsrv", "MhdCallback[4]");
						if (req->ixVState != ReqWdbe::VecVState::REPLY) req->cReady.wait("WdbedAppsrv", "MhdCallback[3]");
						req->cReady.unlockMutex("WdbedAppsrv", "MhdCallback[4]");

						if (req->reply) response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						else response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
						if (xchg->stgwdbeappsrv.cors != "") MHD_add_response_header(response, MHD_HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN, xchg->stgwdbeappsrv.cors.c_str());
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int WdbedAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t WdbedAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqWdbe* req = (ReqWdbe*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

MHD_Result WdbedAppsrv::MhdPostrecv(
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
	ReqWdbe* req = (ReqWdbe*) con_cls;

	// cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		// --- copy data into req->request (append if required)
		req->jsonNotXml = (strcmp(key, "json") == 0);
		if (!req->jsonNotXml) if (strcmp(key, "xml") != 0) return MHD_NO;

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

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void WdbedAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqWdbe* req;

	// cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqWdbe*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool WdbedAppsrv::validateIp(
			XchgWdbed* xchg
			, ReqWdbe* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		if (xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBESUSPSESS, req->jref))
					if (req->jref != xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, req->jref)) retval = false;

		if (retval) {
			ip = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEIP, req->jref);
			if (ip != req->ip) retval = false;
		};
	};

	return retval;
};

bool WdbedAppsrv::validateJrefNotify(
			XchgWdbed* xchg
			, ReqWdbe* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolWdbe* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecWdbeVCall::CALLWDBEREFPRESET, dcol->jref, VecWdbeVPreset::PREWDBEJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("WdbedAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint WdbedAppsrv::readDpchApp(
			XchgWdbed* xchg
			, ReqWdbe* req
		) {
	uint ixWdbeVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	Json::Reader reader;
	Json::Value root;
	Json::Value::Members members;

	if (!req->jsonNotXml) {
		try {
			parseBuffer(req->request, req->requestlen, &doc, &docctx);

			ixWdbeVDpch = VecWdbeVDpch::getIx(extractRoot(doc));

			if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECPRNEWDATA) {
				req->dpchapp = new DlgWdbeCprNew::DpchAppData();
				((DlgWdbeCprNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECPRNEWDO) {
				req->dpchapp = new DlgWdbeCprNew::DpchAppDo();
				((DlgWdbeCprNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDATA) {
				req->dpchapp = new DlgWdbeCvrBsccd::DpchAppData();
				((DlgWdbeCvrBsccd::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDO) {
				req->dpchapp = new DlgWdbeCvrBsccd::DpchAppDo();
				((DlgWdbeCvrBsccd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDATA) {
				req->dpchapp = new DlgWdbeCvrDetcd::DpchAppData();
				((DlgWdbeCvrDetcd::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDO) {
				req->dpchapp = new DlgWdbeCvrDetcd::DpchAppDo();
				((DlgWdbeCvrDetcd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDATA) {
				req->dpchapp = new DlgWdbeCvrNew::DpchAppData();
				((DlgWdbeCvrNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDO) {
				req->dpchapp = new DlgWdbeCvrNew::DpchAppDo();
				((DlgWdbeCvrNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDATA) {
				req->dpchapp = new DlgWdbeCvrWrite::DpchAppData();
				((DlgWdbeCvrWrite::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDO) {
				req->dpchapp = new DlgWdbeCvrWrite::DpchAppDo();
				((DlgWdbeCvrWrite::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILDOWNLOADDO) {
				req->dpchapp = new DlgWdbeFilDownload::DpchAppDo();
				((DlgWdbeFilDownload::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDATA) {
				req->dpchapp = new DlgWdbeFilNew::DpchAppData();
				((DlgWdbeFilNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDO) {
				req->dpchapp = new DlgWdbeFilNew::DpchAppDo();
				((DlgWdbeFilNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDATA) {
				req->dpchapp = new DlgWdbeNavLoaini::DpchAppData();
				((DlgWdbeNavLoaini::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDO) {
				req->dpchapp = new DlgWdbeNavLoaini::DpchAppDo();
				((DlgWdbeNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDATA) {
				req->dpchapp = new DlgWdbeNavMnglic::DpchAppData();
				((DlgWdbeNavMnglic::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDO) {
				req->dpchapp = new DlgWdbeNavMnglic::DpchAppDo();
				((DlgWdbeNavMnglic::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDATA) {
				req->dpchapp = new DlgWdbePrjImpex::DpchAppData();
				((DlgWdbePrjImpex::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDO) {
				req->dpchapp = new DlgWdbePrjImpex::DpchAppDo();
				((DlgWdbePrjImpex::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDATA) {
				req->dpchapp = new DlgWdbePrjNew::DpchAppData();
				((DlgWdbePrjNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDO) {
				req->dpchapp = new DlgWdbePrjNew::DpchAppDo();
				((DlgWdbePrjNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDATA) {
				req->dpchapp = new DlgWdbeRlsFinreptr::DpchAppData();
				((DlgWdbeRlsFinreptr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDO) {
				req->dpchapp = new DlgWdbeRlsFinreptr::DpchAppDo();
				((DlgWdbeRlsFinreptr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDATA) {
				req->dpchapp = new DlgWdbeRlsStareptr::DpchAppData();
				((DlgWdbeRlsStareptr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDO) {
				req->dpchapp = new DlgWdbeRlsStareptr::DpchAppDo();
				((DlgWdbeRlsStareptr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDATA) {
				req->dpchapp = new DlgWdbeRlsWrite::DpchAppData();
				((DlgWdbeRlsWrite::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDO) {
				req->dpchapp = new DlgWdbeRlsWrite::DpchAppDo();
				((DlgWdbeRlsWrite::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUSRMNGKEYPAIRDO) {
				req->dpchapp = new DlgWdbeUsrMngkeypair::DpchAppDo();
				((DlgWdbeUsrMngkeypair::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLEXTRIPDATA) {
				req->dpchapp = new DlgWdbeUtlExtrip::DpchAppData();
				((DlgWdbeUtlExtrip::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLEXTRIPDO) {
				req->dpchapp = new DlgWdbeUtlExtrip::DpchAppDo();
				((DlgWdbeUtlExtrip::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDATA) {
				req->dpchapp = new DlgWdbeUtlMrgip::DpchAppData();
				((DlgWdbeUtlMrgip::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDO) {
				req->dpchapp = new DlgWdbeUtlMrgip::DpchAppDo();
				((DlgWdbeUtlMrgip::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCMDSETDATA) {
				req->dpchapp = new DlgWdbeVerCmdset::DpchAppData();
				((DlgWdbeVerCmdset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCMDSETDO) {
				req->dpchapp = new DlgWdbeVerCmdset::DpchAppDo();
				((DlgWdbeVerCmdset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCUSTFSTDATA) {
				req->dpchapp = new DlgWdbeVerCustfst::DpchAppData();
				((DlgWdbeVerCustfst::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCUSTFSTDO) {
				req->dpchapp = new DlgWdbeVerCustfst::DpchAppDo();
				((DlgWdbeVerCustfst::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDEPLOYDATA) {
				req->dpchapp = new DlgWdbeVerDeploy::DpchAppData();
				((DlgWdbeVerDeploy::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDEPLOYDO) {
				req->dpchapp = new DlgWdbeVerDeploy::DpchAppDo();
				((DlgWdbeVerDeploy::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDFLALGDATA) {
				req->dpchapp = new DlgWdbeVerDflalg::DpchAppData();
				((DlgWdbeVerDflalg::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDFLALGDO) {
				req->dpchapp = new DlgWdbeVerDflalg::DpchAppDo();
				((DlgWdbeVerDflalg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDATA) {
				req->dpchapp = new DlgWdbeVerFinmod::DpchAppData();
				((DlgWdbeVerFinmod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDO) {
				req->dpchapp = new DlgWdbeVerFinmod::DpchAppDo();
				((DlgWdbeVerFinmod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERGENFSTDO) {
				req->dpchapp = new DlgWdbeVerGenfst::DpchAppDo();
				((DlgWdbeVerGenfst::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERMDLSTRDATA) {
				req->dpchapp = new DlgWdbeVerMdlstr::DpchAppData();
				((DlgWdbeVerMdlstr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERMDLSTRDO) {
				req->dpchapp = new DlgWdbeVerMdlstr::DpchAppDo();
				((DlgWdbeVerMdlstr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDATA) {
				req->dpchapp = new DlgWdbeVerNew::DpchAppData();
				((DlgWdbeVerNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDO) {
				req->dpchapp = new DlgWdbeVerNew::DpchAppDo();
				((DlgWdbeVerNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPROOTWDBELOGIN) {
				req->dpchapp = new RootWdbe::DpchAppLogin();
				((RootWdbe::DpchAppLogin*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
				req->dpchapp = new DpchAppWdbeAlert();
				((DpchAppWdbeAlert*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDATA) {
				req->dpchapp = new PnlWdbeBnk1NPin::DpchAppData();
				((PnlWdbeBnk1NPin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDO) {
				req->dpchapp = new PnlWdbeBnk1NPin::DpchAppDo();
				((PnlWdbeBnk1NPin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDATA) {
				req->dpchapp = new PnlWdbeBnkDetail::DpchAppData();
				((PnlWdbeBnkDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDO) {
				req->dpchapp = new PnlWdbeBnkDetail::DpchAppDo();
				((PnlWdbeBnkDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDO) {
				req->dpchapp = new CrdWdbeBnk::DpchAppDo();
				((CrdWdbeBnk::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKLISTDATA) {
				req->dpchapp = new PnlWdbeBnkList::DpchAppData();
				((PnlWdbeBnkList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKLISTDO) {
				req->dpchapp = new PnlWdbeBnkList::DpchAppDo();
				((PnlWdbeBnkList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKRECDO) {
				req->dpchapp = new PnlWdbeBnkRec::DpchAppDo();
				((PnlWdbeBnkRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDATA) {
				req->dpchapp = new PnlWdbeCdcDetail::DpchAppData();
				((PnlWdbeCdcDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDO) {
				req->dpchapp = new PnlWdbeCdcDetail::DpchAppDo();
				((PnlWdbeCdcDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDO) {
				req->dpchapp = new CrdWdbeCdc::DpchAppDo();
				((CrdWdbeCdc::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCLISTDATA) {
				req->dpchapp = new PnlWdbeCdcList::DpchAppData();
				((PnlWdbeCdcList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCLISTDO) {
				req->dpchapp = new PnlWdbeCdcList::DpchAppDo();
				((PnlWdbeCdcList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCMNSIGNALDATA) {
				req->dpchapp = new PnlWdbeCdcMNSignal::DpchAppData();
				((PnlWdbeCdcMNSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCMNSIGNALDO) {
				req->dpchapp = new PnlWdbeCdcMNSignal::DpchAppDo();
				((PnlWdbeCdcMNSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCRECDO) {
				req->dpchapp = new PnlWdbeCdcRec::DpchAppDo();
				((PnlWdbeCdcRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDAINVPARDATA) {
				req->dpchapp = new PnlWdbeCmdAInvpar::DpchAppData();
				((PnlWdbeCmdAInvpar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDAINVPARDO) {
				req->dpchapp = new PnlWdbeCmdAInvpar::DpchAppDo();
				((PnlWdbeCmdAInvpar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDARETPARDATA) {
				req->dpchapp = new PnlWdbeCmdARetpar::DpchAppData();
				((PnlWdbeCmdARetpar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDARETPARDO) {
				req->dpchapp = new PnlWdbeCmdARetpar::DpchAppDo();
				((PnlWdbeCmdARetpar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDATA) {
				req->dpchapp = new PnlWdbeCmdDetail::DpchAppData();
				((PnlWdbeCmdDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDO) {
				req->dpchapp = new PnlWdbeCmdDetail::DpchAppDo();
				((PnlWdbeCmdDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDO) {
				req->dpchapp = new CrdWdbeCmd::DpchAppDo();
				((CrdWdbeCmd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDLISTDATA) {
				req->dpchapp = new PnlWdbeCmdList::DpchAppData();
				((PnlWdbeCmdList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDLISTDO) {
				req->dpchapp = new PnlWdbeCmdList::DpchAppDo();
				((PnlWdbeCmdList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDMNCONTROLLERDATA) {
				req->dpchapp = new PnlWdbeCmdMNController::DpchAppData();
				((PnlWdbeCmdMNController::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDMNCONTROLLERDO) {
				req->dpchapp = new PnlWdbeCmdMNController::DpchAppDo();
				((PnlWdbeCmdMNController::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDRECDO) {
				req->dpchapp = new PnlWdbeCmdRec::DpchAppDo();
				((PnlWdbeCmdRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMP1NRELEASEDATA) {
				req->dpchapp = new PnlWdbeCmp1NRelease::DpchAppData();
				((PnlWdbeCmp1NRelease::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMP1NRELEASEDO) {
				req->dpchapp = new PnlWdbeCmp1NRelease::DpchAppDo();
				((PnlWdbeCmp1NRelease::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDETAILDATA) {
				req->dpchapp = new PnlWdbeCmpDetail::DpchAppData();
				((PnlWdbeCmpDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDETAILDO) {
				req->dpchapp = new PnlWdbeCmpDetail::DpchAppDo();
				((PnlWdbeCmpDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDO) {
				req->dpchapp = new CrdWdbeCmp::DpchAppDo();
				((CrdWdbeCmp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPLISTDATA) {
				req->dpchapp = new PnlWdbeCmpList::DpchAppData();
				((PnlWdbeCmpList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPLISTDO) {
				req->dpchapp = new PnlWdbeCmpList::DpchAppDo();
				((PnlWdbeCmpList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPMNLIBRARYDATA) {
				req->dpchapp = new PnlWdbeCmpMNLibrary::DpchAppData();
				((PnlWdbeCmpMNLibrary::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPMNLIBRARYDO) {
				req->dpchapp = new PnlWdbeCmpMNLibrary::DpchAppDo();
				((PnlWdbeCmpMNLibrary::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPRECDO) {
				req->dpchapp = new PnlWdbeCmpRec::DpchAppDo();
				((PnlWdbeCmpRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPR1NCOREVERSIONDATA) {
				req->dpchapp = new PnlWdbeCpr1NCoreversion::DpchAppData();
				((PnlWdbeCpr1NCoreversion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPR1NCOREVERSIONDO) {
				req->dpchapp = new PnlWdbeCpr1NCoreversion::DpchAppDo();
				((PnlWdbeCpr1NCoreversion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDETAILDATA) {
				req->dpchapp = new PnlWdbeCprDetail::DpchAppData();
				((PnlWdbeCprDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDETAILDO) {
				req->dpchapp = new PnlWdbeCprDetail::DpchAppDo();
				((PnlWdbeCprDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDO) {
				req->dpchapp = new CrdWdbeCpr::DpchAppDo();
				((CrdWdbeCpr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRLISTDATA) {
				req->dpchapp = new PnlWdbeCprList::DpchAppData();
				((PnlWdbeCprList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRLISTDO) {
				req->dpchapp = new PnlWdbeCprList::DpchAppDo();
				((PnlWdbeCprList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRMNPERSONDATA) {
				req->dpchapp = new PnlWdbeCprMNPerson::DpchAppData();
				((PnlWdbeCprMNPerson::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRMNPERSONDO) {
				req->dpchapp = new PnlWdbeCprMNPerson::DpchAppDo();
				((PnlWdbeCprMNPerson::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRRECDO) {
				req->dpchapp = new PnlWdbeCprRec::DpchAppDo();
				((PnlWdbeCprRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAIPDATA) {
				req->dpchapp = new PnlWdbeCvrAIp::DpchAppData();
				((PnlWdbeCvrAIp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAIPDO) {
				req->dpchapp = new PnlWdbeCvrAIp::DpchAppDo();
				((PnlWdbeCvrAIp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAPLHDATA) {
				req->dpchapp = new PnlWdbeCvrAPlh::DpchAppData();
				((PnlWdbeCvrAPlh::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAPLHDO) {
				req->dpchapp = new PnlWdbeCvrAPlh::DpchAppDo();
				((PnlWdbeCvrAPlh::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRBCV1NCOREVERSIONDATA) {
				req->dpchapp = new PnlWdbeCvrBcv1NCoreversion::DpchAppData();
				((PnlWdbeCvrBcv1NCoreversion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRBCV1NCOREVERSIONDO) {
				req->dpchapp = new PnlWdbeCvrBcv1NCoreversion::DpchAppDo();
				((PnlWdbeCvrBcv1NCoreversion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDATA) {
				req->dpchapp = new PnlWdbeCvrDetail::DpchAppData();
				((PnlWdbeCvrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDO) {
				req->dpchapp = new PnlWdbeCvrDetail::DpchAppDo();
				((PnlWdbeCvrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDO) {
				req->dpchapp = new CrdWdbeCvr::DpchAppDo();
				((CrdWdbeCvr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeCvrHk1NModule::DpchAppData();
				((PnlWdbeCvrHk1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeCvrHk1NModule::DpchAppDo();
				((PnlWdbeCvrHk1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRLISTDATA) {
				req->dpchapp = new PnlWdbeCvrList::DpchAppData();
				((PnlWdbeCvrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRLISTDO) {
				req->dpchapp = new PnlWdbeCvrList::DpchAppDo();
				((PnlWdbeCvrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRRECDO) {
				req->dpchapp = new PnlWdbeCvrRec::DpchAppDo();
				((PnlWdbeCvrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRAPARDATA) {
				req->dpchapp = new PnlWdbeErrAPar::DpchAppData();
				((PnlWdbeErrAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRAPARDO) {
				req->dpchapp = new PnlWdbeErrAPar::DpchAppDo();
				((PnlWdbeErrAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDATA) {
				req->dpchapp = new PnlWdbeErrDetail::DpchAppData();
				((PnlWdbeErrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDO) {
				req->dpchapp = new PnlWdbeErrDetail::DpchAppDo();
				((PnlWdbeErrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDO) {
				req->dpchapp = new CrdWdbeErr::DpchAppDo();
				((CrdWdbeErr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRLISTDATA) {
				req->dpchapp = new PnlWdbeErrList::DpchAppData();
				((PnlWdbeErrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRLISTDO) {
				req->dpchapp = new PnlWdbeErrList::DpchAppDo();
				((PnlWdbeErrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRRECDO) {
				req->dpchapp = new PnlWdbeErrRec::DpchAppDo();
				((PnlWdbeErrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAM1NUNITDATA) {
				req->dpchapp = new PnlWdbeFam1NUnit::DpchAppData();
				((PnlWdbeFam1NUnit::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAM1NUNITDO) {
				req->dpchapp = new PnlWdbeFam1NUnit::DpchAppDo();
				((PnlWdbeFam1NUnit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDATA) {
				req->dpchapp = new PnlWdbeFamDetail::DpchAppData();
				((PnlWdbeFamDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDO) {
				req->dpchapp = new PnlWdbeFamDetail::DpchAppDo();
				((PnlWdbeFamDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDO) {
				req->dpchapp = new CrdWdbeFam::DpchAppDo();
				((CrdWdbeFam::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMLISTDATA) {
				req->dpchapp = new PnlWdbeFamList::DpchAppData();
				((PnlWdbeFamList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMLISTDO) {
				req->dpchapp = new PnlWdbeFamList::DpchAppDo();
				((PnlWdbeFamList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMRECDO) {
				req->dpchapp = new PnlWdbeFamRec::DpchAppDo();
				((PnlWdbeFamRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDETAILDATA) {
				req->dpchapp = new PnlWdbeFilDetail::DpchAppData();
				((PnlWdbeFilDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDETAILDO) {
				req->dpchapp = new PnlWdbeFilDetail::DpchAppDo();
				((PnlWdbeFilDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDO) {
				req->dpchapp = new CrdWdbeFil::DpchAppDo();
				((CrdWdbeFil::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILLISTDATA) {
				req->dpchapp = new PnlWdbeFilList::DpchAppData();
				((PnlWdbeFilList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILLISTDO) {
				req->dpchapp = new PnlWdbeFilList::DpchAppDo();
				((PnlWdbeFilList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILRECDO) {
				req->dpchapp = new PnlWdbeFilRec::DpchAppDo();
				((PnlWdbeFilRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDATA) {
				req->dpchapp = new PnlWdbeFstAStep::DpchAppData();
				((PnlWdbeFstAStep::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDO) {
				req->dpchapp = new PnlWdbeFstAStep::DpchAppDo();
				((PnlWdbeFstAStep::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDETAILDATA) {
				req->dpchapp = new PnlWdbeFstDetail::DpchAppData();
				((PnlWdbeFstDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDETAILDO) {
				req->dpchapp = new PnlWdbeFstDetail::DpchAppDo();
				((PnlWdbeFstDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDO) {
				req->dpchapp = new CrdWdbeFst::DpchAppDo();
				((CrdWdbeFst::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTLISTDATA) {
				req->dpchapp = new PnlWdbeFstList::DpchAppData();
				((PnlWdbeFstList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTLISTDO) {
				req->dpchapp = new PnlWdbeFstList::DpchAppDo();
				((PnlWdbeFstList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTRECDO) {
				req->dpchapp = new PnlWdbeFstRec::DpchAppDo();
				((PnlWdbeFstRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDATA) {
				req->dpchapp = new PnlWdbeGenDetail::DpchAppData();
				((PnlWdbeGenDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDO) {
				req->dpchapp = new PnlWdbeGenDetail::DpchAppDo();
				((PnlWdbeGenDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDO) {
				req->dpchapp = new CrdWdbeGen::DpchAppDo();
				((CrdWdbeGen::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENLISTDATA) {
				req->dpchapp = new PnlWdbeGenList::DpchAppData();
				((PnlWdbeGenList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENLISTDO) {
				req->dpchapp = new PnlWdbeGenList::DpchAppDo();
				((PnlWdbeGenList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENRECDO) {
				req->dpchapp = new PnlWdbeGenRec::DpchAppDo();
				((PnlWdbeGenRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
				req->dpchapp = new DpchAppWdbeInit();
				((DpchAppWdbeInit*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDETAILDATA) {
				req->dpchapp = new PnlWdbeIntDetail::DpchAppData();
				((PnlWdbeIntDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDETAILDO) {
				req->dpchapp = new PnlWdbeIntDetail::DpchAppDo();
				((PnlWdbeIntDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDO) {
				req->dpchapp = new CrdWdbeInt::DpchAppDo();
				((CrdWdbeInt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTLISTDATA) {
				req->dpchapp = new PnlWdbeIntList::DpchAppData();
				((PnlWdbeIntList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTLISTDO) {
				req->dpchapp = new PnlWdbeIntList::DpchAppDo();
				((PnlWdbeIntList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTRECDO) {
				req->dpchapp = new PnlWdbeIntRec::DpchAppDo();
				((PnlWdbeIntRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeIntSrc1NSensitivity::DpchAppData();
				((PnlWdbeIntSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeIntSrc1NSensitivity::DpchAppDo();
				((PnlWdbeIntSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBAMAKEFILEDATA) {
				req->dpchapp = new PnlWdbeLibAMakefile::DpchAppData();
				((PnlWdbeLibAMakefile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBAMAKEFILEDO) {
				req->dpchapp = new PnlWdbeLibAMakefile::DpchAppDo();
				((PnlWdbeLibAMakefile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDETAILDATA) {
				req->dpchapp = new PnlWdbeLibDetail::DpchAppData();
				((PnlWdbeLibDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDETAILDO) {
				req->dpchapp = new PnlWdbeLibDetail::DpchAppDo();
				((PnlWdbeLibDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDO) {
				req->dpchapp = new CrdWdbeLib::DpchAppDo();
				((CrdWdbeLib::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBLISTDATA) {
				req->dpchapp = new PnlWdbeLibList::DpchAppData();
				((PnlWdbeLibList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBLISTDO) {
				req->dpchapp = new PnlWdbeLibList::DpchAppDo();
				((PnlWdbeLibList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBMNCOMPONENTDATA) {
				req->dpchapp = new PnlWdbeLibMNComponent::DpchAppData();
				((PnlWdbeLibMNComponent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBMNCOMPONENTDO) {
				req->dpchapp = new PnlWdbeLibMNComponent::DpchAppDo();
				((PnlWdbeLibMNComponent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBRECDO) {
				req->dpchapp = new PnlWdbeLibRec::DpchAppDo();
				((PnlWdbeLibRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCH1NRELEASEDATA) {
				req->dpchapp = new PnlWdbeMch1NRelease::DpchAppData();
				((PnlWdbeMch1NRelease::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCH1NRELEASEDO) {
				req->dpchapp = new PnlWdbeMch1NRelease::DpchAppDo();
				((PnlWdbeMch1NRelease::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAMAKEFILEDATA) {
				req->dpchapp = new PnlWdbeMchAMakefile::DpchAppData();
				((PnlWdbeMchAMakefile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAMAKEFILEDO) {
				req->dpchapp = new PnlWdbeMchAMakefile::DpchAppDo();
				((PnlWdbeMchAMakefile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDATA) {
				req->dpchapp = new PnlWdbeMchAPar::DpchAppData();
				((PnlWdbeMchAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDO) {
				req->dpchapp = new PnlWdbeMchAPar::DpchAppDo();
				((PnlWdbeMchAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDETAILDATA) {
				req->dpchapp = new PnlWdbeMchDetail::DpchAppData();
				((PnlWdbeMchDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDETAILDO) {
				req->dpchapp = new PnlWdbeMchDetail::DpchAppDo();
				((PnlWdbeMchDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDO) {
				req->dpchapp = new CrdWdbeMch::DpchAppDo();
				((CrdWdbeMch::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHLISTDATA) {
				req->dpchapp = new PnlWdbeMchList::DpchAppData();
				((PnlWdbeMchList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHLISTDO) {
				req->dpchapp = new PnlWdbeMchList::DpchAppDo();
				((PnlWdbeMchList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHRECDO) {
				req->dpchapp = new PnlWdbeMchRec::DpchAppDo();
				((PnlWdbeMchRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHSUP1NMACHINEDATA) {
				req->dpchapp = new PnlWdbeMchSup1NMachine::DpchAppData();
				((PnlWdbeMchSup1NMachine::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHSUP1NMACHINEDO) {
				req->dpchapp = new PnlWdbeMchSup1NMachine::DpchAppDo();
				((PnlWdbeMchSup1NMachine::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NCDCDATA) {
				req->dpchapp = new PnlWdbeMod1NCdc::DpchAppData();
				((PnlWdbeMod1NCdc::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NCDCDO) {
				req->dpchapp = new PnlWdbeMod1NCdc::DpchAppDo();
				((PnlWdbeMod1NCdc::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NPROCESSDATA) {
				req->dpchapp = new PnlWdbeMod1NProcess::DpchAppData();
				((PnlWdbeMod1NProcess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NPROCESSDO) {
				req->dpchapp = new PnlWdbeMod1NProcess::DpchAppDo();
				((PnlWdbeMod1NProcess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODAPARDATA) {
				req->dpchapp = new PnlWdbeModAPar::DpchAppData();
				((PnlWdbeModAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODAPARDO) {
				req->dpchapp = new PnlWdbeModAPar::DpchAppDo();
				((PnlWdbeModAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCORMNMODULEDATA) {
				req->dpchapp = new PnlWdbeModCorMNModule::DpchAppData();
				((PnlWdbeModCorMNModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCORMNMODULEDO) {
				req->dpchapp = new PnlWdbeModCorMNModule::DpchAppDo();
				((PnlWdbeModCorMNModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTDMNMODULEDATA) {
				req->dpchapp = new PnlWdbeModCtdMNModule::DpchAppData();
				((PnlWdbeModCtdMNModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTDMNMODULEDO) {
				req->dpchapp = new PnlWdbeModCtdMNModule::DpchAppDo();
				((PnlWdbeModCtdMNModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeModCtrHk1NVector::DpchAppData();
				((PnlWdbeModCtrHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeModCtrHk1NVector::DpchAppDo();
				((PnlWdbeModCtrHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRMNCOMMANDDATA) {
				req->dpchapp = new PnlWdbeModCtrMNCommand::DpchAppData();
				((PnlWdbeModCtrMNCommand::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRMNCOMMANDDO) {
				req->dpchapp = new PnlWdbeModCtrMNCommand::DpchAppDo();
				((PnlWdbeModCtrMNCommand::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeModCtrRef1NCommand::DpchAppData();
				((PnlWdbeModCtrRef1NCommand::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeModCtrRef1NCommand::DpchAppDo();
				((PnlWdbeModCtrRef1NCommand::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeModCtrRef1NError::DpchAppData();
				((PnlWdbeModCtrRef1NError::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NERRORDO) {
				req->dpchapp = new PnlWdbeModCtrRef1NError::DpchAppDo();
				((PnlWdbeModCtrRef1NError::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDATA) {
				req->dpchapp = new PnlWdbeModDetail::DpchAppData();
				((PnlWdbeModDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDO) {
				req->dpchapp = new PnlWdbeModDetail::DpchAppDo();
				((PnlWdbeModDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDO) {
				req->dpchapp = new CrdWdbeMod::DpchAppDo();
				((CrdWdbeMod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODHSM1NPIPELINEDATA) {
				req->dpchapp = new PnlWdbeModHsm1NPipeline::DpchAppData();
				((PnlWdbeModHsm1NPipeline::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODHSM1NPIPELINEDO) {
				req->dpchapp = new PnlWdbeModHsm1NPipeline::DpchAppDo();
				((PnlWdbeModHsm1NPipeline::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbeModKHdltype::DpchAppData();
				((PnlWdbeModKHdltype::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODKHDLTYPEDO) {
				req->dpchapp = new PnlWdbeModKHdltype::DpchAppDo();
				((PnlWdbeModKHdltype::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODLISTDATA) {
				req->dpchapp = new PnlWdbeModList::DpchAppData();
				((PnlWdbeModList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODLISTDO) {
				req->dpchapp = new PnlWdbeModList::DpchAppDo();
				((PnlWdbeModList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NGENERICDATA) {
				req->dpchapp = new PnlWdbeModMdl1NGeneric::DpchAppData();
				((PnlWdbeModMdl1NGeneric::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NGENERICDO) {
				req->dpchapp = new PnlWdbeModMdl1NGeneric::DpchAppDo();
				((PnlWdbeModMdl1NGeneric::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NPORTDATA) {
				req->dpchapp = new PnlWdbeModMdl1NPort::DpchAppData();
				((PnlWdbeModMdl1NPort::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NPORTDO) {
				req->dpchapp = new PnlWdbeModMdl1NPort::DpchAppDo();
				((PnlWdbeModMdl1NPort::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeModMge1NSignal::DpchAppData();
				((PnlWdbeModMge1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbeModMge1NSignal::DpchAppDo();
				((PnlWdbeModMge1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeModMNPeripheral::DpchAppData();
				((PnlWdbeModMNPeripheral::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDO) {
				req->dpchapp = new PnlWdbeModMNPeripheral::DpchAppDo();
				((PnlWdbeModMNPeripheral::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODRECDO) {
				req->dpchapp = new PnlWdbeModRec::DpchAppDo();
				((PnlWdbeModRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeModRef1NSensitivity::DpchAppData();
				((PnlWdbeModRef1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeModRef1NSensitivity::DpchAppDo();
				((PnlWdbeModRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeModRef1NSignal::DpchAppData();
				((PnlWdbeModRef1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeModRef1NSignal::DpchAppDo();
				((PnlWdbeModRef1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbeModRef1NVariable::DpchAppData();
				((PnlWdbeModRef1NVariable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbeModRef1NVariable::DpchAppDo();
				((PnlWdbeModRef1NVariable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODSUP1NMODULEDATA) {
				req->dpchapp = new PnlWdbeModSup1NModule::DpchAppData();
				((PnlWdbeModSup1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODSUP1NMODULEDO) {
				req->dpchapp = new PnlWdbeModSup1NModule::DpchAppDo();
				((PnlWdbeModSup1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPAPARDATA) {
				req->dpchapp = new PnlWdbeMtpAPar::DpchAppData();
				((PnlWdbeMtpAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPAPARDO) {
				req->dpchapp = new PnlWdbeMtpAPar::DpchAppDo();
				((PnlWdbeMtpAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDATA) {
				req->dpchapp = new PnlWdbeMtpDetail::DpchAppData();
				((PnlWdbeMtpDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDO) {
				req->dpchapp = new PnlWdbeMtpDetail::DpchAppDo();
				((PnlWdbeMtpDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDO) {
				req->dpchapp = new CrdWdbeMtp::DpchAppDo();
				((CrdWdbeMtp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPHSM1NPIPELINEDATA) {
				req->dpchapp = new PnlWdbeMtpHsm1NPipeline::DpchAppData();
				((PnlWdbeMtpHsm1NPipeline::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPHSM1NPIPELINEDO) {
				req->dpchapp = new PnlWdbeMtpHsm1NPipeline::DpchAppDo();
				((PnlWdbeMtpHsm1NPipeline::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbeMtpKHdltype::DpchAppData();
				((PnlWdbeMtpKHdltype::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKHDLTYPEDO) {
				req->dpchapp = new PnlWdbeMtpKHdltype::DpchAppDo();
				((PnlWdbeMtpKHdltype::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKPARKEYDATA) {
				req->dpchapp = new PnlWdbeMtpKParKey::DpchAppData();
				((PnlWdbeMtpKParKey::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKPARKEYDO) {
				req->dpchapp = new PnlWdbeMtpKParKey::DpchAppDo();
				((PnlWdbeMtpKParKey::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPLISTDATA) {
				req->dpchapp = new PnlWdbeMtpList::DpchAppData();
				((PnlWdbeMtpList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPLISTDO) {
				req->dpchapp = new PnlWdbeMtpList::DpchAppDo();
				((PnlWdbeMtpList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NGENERICDATA) {
				req->dpchapp = new PnlWdbeMtpMdl1NGeneric::DpchAppData();
				((PnlWdbeMtpMdl1NGeneric::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NGENERICDO) {
				req->dpchapp = new PnlWdbeMtpMdl1NGeneric::DpchAppDo();
				((PnlWdbeMtpMdl1NGeneric::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NPORTDATA) {
				req->dpchapp = new PnlWdbeMtpMdl1NPort::DpchAppData();
				((PnlWdbeMtpMdl1NPort::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NPORTDO) {
				req->dpchapp = new PnlWdbeMtpMdl1NPort::DpchAppDo();
				((PnlWdbeMtpMdl1NPort::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeMtpMge1NSignal::DpchAppData();
				((PnlWdbeMtpMge1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbeMtpMge1NSignal::DpchAppDo();
				((PnlWdbeMtpMge1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPRECDO) {
				req->dpchapp = new PnlWdbeMtpRec::DpchAppDo();
				((PnlWdbeMtpRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NFILEDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NFile::DpchAppData();
				((PnlWdbeMtpRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NFILEDO) {
				req->dpchapp = new PnlWdbeMtpRef1NFile::DpchAppDo();
				((PnlWdbeMtpRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NSensitivity::DpchAppData();
				((PnlWdbeMtpRef1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeMtpRef1NSensitivity::DpchAppDo();
				((PnlWdbeMtpRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NVariable::DpchAppData();
				((PnlWdbeMtpRef1NVariable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbeMtpRef1NVariable::DpchAppDo();
				((PnlWdbeMtpRef1NVariable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPSUP1NMODULEDATA) {
				req->dpchapp = new PnlWdbeMtpSup1NModule::DpchAppData();
				((PnlWdbeMtpSup1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPSUP1NMODULEDO) {
				req->dpchapp = new PnlWdbeMtpSup1NModule::DpchAppDo();
				((PnlWdbeMtpSup1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPTPL1NMODULEDATA) {
				req->dpchapp = new PnlWdbeMtpTpl1NModule::DpchAppData();
				((PnlWdbeMtpTpl1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPTPL1NMODULEDO) {
				req->dpchapp = new PnlWdbeMtpTpl1NModule::DpchAppDo();
				((PnlWdbeMtpTpl1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVADMINDATA) {
				req->dpchapp = new PnlWdbeNavAdmin::DpchAppData();
				((PnlWdbeNavAdmin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVADMINDO) {
				req->dpchapp = new PnlWdbeNavAdmin::DpchAppDo();
				((PnlWdbeNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVAUXFCTDO) {
				req->dpchapp = new PnlWdbeNavAuxfct::DpchAppDo();
				((PnlWdbeNavAuxfct::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDATA) {
				req->dpchapp = new PnlWdbeNavCoredev::DpchAppData();
				((PnlWdbeNavCoredev::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDO) {
				req->dpchapp = new PnlWdbeNavCoredev::DpchAppDo();
				((PnlWdbeNavCoredev::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDATA) {
				req->dpchapp = new PnlWdbeNavDeploy::DpchAppData();
				((PnlWdbeNavDeploy::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDO) {
				req->dpchapp = new PnlWdbeNavDeploy::DpchAppDo();
				((PnlWdbeNavDeploy::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA) {
				req->dpchapp = new PnlWdbeNavDevdev::DpchAppData();
				((PnlWdbeNavDevdev::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO) {
				req->dpchapp = new PnlWdbeNavDevdev::DpchAppDo();
				((PnlWdbeNavDevdev::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDO) {
				req->dpchapp = new CrdWdbeNav::DpchAppDo();
				((CrdWdbeNav::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDATA) {
				req->dpchapp = new PnlWdbeNavGlobal::DpchAppData();
				((PnlWdbeNavGlobal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDO) {
				req->dpchapp = new PnlWdbeNavGlobal::DpchAppDo();
				((PnlWdbeNavGlobal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDATA) {
				req->dpchapp = new PnlWdbeNavHigh::DpchAppData();
				((PnlWdbeNavHigh::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDO) {
				req->dpchapp = new PnlWdbeNavHigh::DpchAppDo();
				((PnlWdbeNavHigh::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDATA) {
				req->dpchapp = new PnlWdbeNavLow::DpchAppData();
				((PnlWdbeNavLow::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDO) {
				req->dpchapp = new PnlWdbeNavLow::DpchAppDo();
				((PnlWdbeNavLow::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVPREDO) {
				req->dpchapp = new PnlWdbeNavPre::DpchAppDo();
				((PnlWdbeNavPre::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINAPARDATA) {
				req->dpchapp = new PnlWdbePinAPar::DpchAppData();
				((PnlWdbePinAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINAPARDO) {
				req->dpchapp = new PnlWdbePinAPar::DpchAppDo();
				((PnlWdbePinAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDATA) {
				req->dpchapp = new PnlWdbePinDetail::DpchAppData();
				((PnlWdbePinDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDO) {
				req->dpchapp = new PnlWdbePinDetail::DpchAppDo();
				((PnlWdbePinDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDO) {
				req->dpchapp = new CrdWdbePin::DpchAppDo();
				((CrdWdbePin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINLISTDATA) {
				req->dpchapp = new PnlWdbePinList::DpchAppData();
				((PnlWdbePinList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINLISTDO) {
				req->dpchapp = new PnlWdbePinList::DpchAppDo();
				((PnlWdbePinList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINRECDO) {
				req->dpchapp = new PnlWdbePinRec::DpchAppDo();
				((PnlWdbePinRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHAPARDATA) {
				req->dpchapp = new PnlWdbePphAPar::DpchAppData();
				((PnlWdbePphAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHAPARDO) {
				req->dpchapp = new PnlWdbePphAPar::DpchAppDo();
				((PnlWdbePphAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDETAILDATA) {
				req->dpchapp = new PnlWdbePphDetail::DpchAppData();
				((PnlWdbePphDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDETAILDO) {
				req->dpchapp = new PnlWdbePphDetail::DpchAppDo();
				((PnlWdbePphDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDO) {
				req->dpchapp = new CrdWdbePph::DpchAppDo();
				((CrdWdbePph::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHLISTDATA) {
				req->dpchapp = new PnlWdbePphList::DpchAppData();
				((PnlWdbePphList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHLISTDO) {
				req->dpchapp = new PnlWdbePphList::DpchAppDo();
				((PnlWdbePphList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHMNMODULEDATA) {
				req->dpchapp = new PnlWdbePphMNModule::DpchAppData();
				((PnlWdbePphMNModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHMNMODULEDO) {
				req->dpchapp = new PnlWdbePphMNModule::DpchAppDo();
				((PnlWdbePphMNModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHRECDO) {
				req->dpchapp = new PnlWdbePphRec::DpchAppDo();
				((PnlWdbePphRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDATA) {
				req->dpchapp = new PnlWdbePplDetail::DpchAppData();
				((PnlWdbePplDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDO) {
				req->dpchapp = new PnlWdbePplDetail::DpchAppDo();
				((PnlWdbePplDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDO) {
				req->dpchapp = new CrdWdbePpl::DpchAppDo();
				((CrdWdbePpl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLLISTDATA) {
				req->dpchapp = new PnlWdbePplList::DpchAppData();
				((PnlWdbePplList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLLISTDO) {
				req->dpchapp = new PnlWdbePplList::DpchAppDo();
				((PnlWdbePplList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLPPL1NSEGMENTDATA) {
				req->dpchapp = new PnlWdbePplPpl1NSegment::DpchAppData();
				((PnlWdbePplPpl1NSegment::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLPPL1NSEGMENTDO) {
				req->dpchapp = new PnlWdbePplPpl1NSegment::DpchAppDo();
				((PnlWdbePplPpl1NSegment::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLRECDO) {
				req->dpchapp = new PnlWdbePplRec::DpchAppDo();
				((PnlWdbePplRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDATA) {
				req->dpchapp = new PnlWdbePrcDetail::DpchAppData();
				((PnlWdbePrcDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDO) {
				req->dpchapp = new PnlWdbePrcDetail::DpchAppDo();
				((PnlWdbePrcDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDO) {
				req->dpchapp = new CrdWdbePrc::DpchAppDo();
				((CrdWdbePrc::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMFSM1NFSMSTATEDATA) {
				req->dpchapp = new PnlWdbePrcFsmFsm1NFsmstate::DpchAppData();
				((PnlWdbePrcFsmFsm1NFsmstate::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMFSM1NFSMSTATEDO) {
				req->dpchapp = new PnlWdbePrcFsmFsm1NFsmstate::DpchAppDo();
				((PnlWdbePrcFsmFsm1NFsmstate::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbePrcFsmHk1NVector::DpchAppData();
				((PnlWdbePrcFsmHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMHK1NVECTORDO) {
				req->dpchapp = new PnlWdbePrcFsmHk1NVector::DpchAppDo();
				((PnlWdbePrcFsmHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbePrcKHdltype::DpchAppData();
				((PnlWdbePrcKHdltype::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCKHDLTYPEDO) {
				req->dpchapp = new PnlWdbePrcKHdltype::DpchAppDo();
				((PnlWdbePrcKHdltype::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCLISTDATA) {
				req->dpchapp = new PnlWdbePrcList::DpchAppData();
				((PnlWdbePrcList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCLISTDO) {
				req->dpchapp = new PnlWdbePrcList::DpchAppDo();
				((PnlWdbePrcList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbePrcMge1NSignal::DpchAppData();
				((PnlWdbePrcMge1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbePrcMge1NSignal::DpchAppDo();
				((PnlWdbePrcMge1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCRECDO) {
				req->dpchapp = new PnlWdbePrcRec::DpchAppDo();
				((PnlWdbePrcRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbePrcRef1NSensitivity::DpchAppData();
				((PnlWdbePrcRef1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbePrcRef1NSensitivity::DpchAppDo();
				((PnlWdbePrcRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbePrcRef1NVariable::DpchAppData();
				((PnlWdbePrcRef1NVariable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbePrcRef1NVariable::DpchAppDo();
				((PnlWdbePrcRef1NVariable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDETAILDATA) {
				req->dpchapp = new PnlWdbePrjDetail::DpchAppData();
				((PnlWdbePrjDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDETAILDO) {
				req->dpchapp = new PnlWdbePrjDetail::DpchAppDo();
				((PnlWdbePrjDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDO) {
				req->dpchapp = new CrdWdbePrj::DpchAppDo();
				((CrdWdbePrj::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJLISTDATA) {
				req->dpchapp = new PnlWdbePrjList::DpchAppData();
				((PnlWdbePrjList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJLISTDO) {
				req->dpchapp = new PnlWdbePrjList::DpchAppDo();
				((PnlWdbePrjList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJMNPERSONDATA) {
				req->dpchapp = new PnlWdbePrjMNPerson::DpchAppData();
				((PnlWdbePrjMNPerson::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJMNPERSONDO) {
				req->dpchapp = new PnlWdbePrjMNPerson::DpchAppDo();
				((PnlWdbePrjMNPerson::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJPRJ1NVERSIONDATA) {
				req->dpchapp = new PnlWdbePrjPrj1NVersion::DpchAppData();
				((PnlWdbePrjPrj1NVersion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJPRJ1NVERSIONDO) {
				req->dpchapp = new PnlWdbePrjPrj1NVersion::DpchAppDo();
				((PnlWdbePrjPrj1NVersion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJRECDO) {
				req->dpchapp = new PnlWdbePrjRec::DpchAppDo();
				((PnlWdbePrjRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSADETAILDATA) {
				req->dpchapp = new PnlWdbePrsADetail::DpchAppData();
				((PnlWdbePrsADetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSADETAILDO) {
				req->dpchapp = new PnlWdbePrsADetail::DpchAppDo();
				((PnlWdbePrsADetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDETAILDATA) {
				req->dpchapp = new PnlWdbePrsDetail::DpchAppData();
				((PnlWdbePrsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDETAILDO) {
				req->dpchapp = new PnlWdbePrsDetail::DpchAppDo();
				((PnlWdbePrsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDO) {
				req->dpchapp = new CrdWdbePrs::DpchAppDo();
				((CrdWdbePrs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSLISTDATA) {
				req->dpchapp = new PnlWdbePrsList::DpchAppData();
				((PnlWdbePrsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSLISTDO) {
				req->dpchapp = new PnlWdbePrsList::DpchAppDo();
				((PnlWdbePrsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNCOREPROJECTDATA) {
				req->dpchapp = new PnlWdbePrsMNCoreproject::DpchAppData();
				((PnlWdbePrsMNCoreproject::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNCOREPROJECTDO) {
				req->dpchapp = new PnlWdbePrsMNCoreproject::DpchAppDo();
				((PnlWdbePrsMNCoreproject::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNPROJECTDATA) {
				req->dpchapp = new PnlWdbePrsMNProject::DpchAppData();
				((PnlWdbePrsMNProject::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNPROJECTDO) {
				req->dpchapp = new PnlWdbePrsMNProject::DpchAppDo();
				((PnlWdbePrsMNProject::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSRECDO) {
				req->dpchapp = new PnlWdbePrsRec::DpchAppDo();
				((PnlWdbePrsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDATA) {
				req->dpchapp = new PnlWdbePrtDetail::DpchAppData();
				((PnlWdbePrtDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDO) {
				req->dpchapp = new PnlWdbePrtDetail::DpchAppDo();
				((PnlWdbePrtDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDO) {
				req->dpchapp = new CrdWdbePrt::DpchAppDo();
				((CrdWdbePrt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTLISTDATA) {
				req->dpchapp = new PnlWdbePrtList::DpchAppData();
				((PnlWdbePrtList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTLISTDO) {
				req->dpchapp = new PnlWdbePrtList::DpchAppDo();
				((PnlWdbePrtList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTRECDO) {
				req->dpchapp = new PnlWdbePrtRec::DpchAppDo();
				((PnlWdbePrtRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbePrtSrc1NSensitivity::DpchAppData();
				((PnlWdbePrtSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbePrtSrc1NSensitivity::DpchAppDo();
				((PnlWdbePrtSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERESUME) {
				req->dpchapp = new DpchAppWdbeResume();
				((DpchAppWdbeResume*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDETAILDATA) {
				req->dpchapp = new PnlWdbeRlsDetail::DpchAppData();
				((PnlWdbeRlsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDETAILDO) {
				req->dpchapp = new PnlWdbeRlsDetail::DpchAppDo();
				((PnlWdbeRlsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDO) {
				req->dpchapp = new CrdWdbeRls::DpchAppDo();
				((CrdWdbeRls::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSLISTDATA) {
				req->dpchapp = new PnlWdbeRlsList::DpchAppData();
				((PnlWdbeRlsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSLISTDO) {
				req->dpchapp = new PnlWdbeRlsList::DpchAppDo();
				((PnlWdbeRlsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSRECDO) {
				req->dpchapp = new PnlWdbeRlsRec::DpchAppDo();
				((PnlWdbeRlsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDATA) {
				req->dpchapp = new PnlWdbeSegDetail::DpchAppData();
				((PnlWdbeSegDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDO) {
				req->dpchapp = new PnlWdbeSegDetail::DpchAppDo();
				((PnlWdbeSegDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDO) {
				req->dpchapp = new CrdWdbeSeg::DpchAppDo();
				((CrdWdbeSeg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGLISTDATA) {
				req->dpchapp = new PnlWdbeSegList::DpchAppData();
				((PnlWdbeSegList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGLISTDO) {
				req->dpchapp = new PnlWdbeSegList::DpchAppDo();
				((PnlWdbeSegList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGRECDO) {
				req->dpchapp = new PnlWdbeSegRec::DpchAppDo();
				((PnlWdbeSegRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGSUP1NSEGMENTDATA) {
				req->dpchapp = new PnlWdbeSegSup1NSegment::DpchAppData();
				((PnlWdbeSegSup1NSegment::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGSUP1NSEGMENTDO) {
				req->dpchapp = new PnlWdbeSegSup1NSegment::DpchAppDo();
				((PnlWdbeSegSup1NSegment::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDATA) {
				req->dpchapp = new PnlWdbeSigDetail::DpchAppData();
				((PnlWdbeSigDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDO) {
				req->dpchapp = new PnlWdbeSigDetail::DpchAppDo();
				((PnlWdbeSigDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDO) {
				req->dpchapp = new CrdWdbeSig::DpchAppDo();
				((CrdWdbeSig::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGLISTDATA) {
				req->dpchapp = new PnlWdbeSigList::DpchAppData();
				((PnlWdbeSigList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGLISTDO) {
				req->dpchapp = new PnlWdbeSigList::DpchAppDo();
				((PnlWdbeSigList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGMNCDCDATA) {
				req->dpchapp = new PnlWdbeSigMNCdc::DpchAppData();
				((PnlWdbeSigMNCdc::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGMNCDCDO) {
				req->dpchapp = new PnlWdbeSigMNCdc::DpchAppDo();
				((PnlWdbeSigMNCdc::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGRECDO) {
				req->dpchapp = new PnlWdbeSigRec::DpchAppDo();
				((PnlWdbeSigRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeSigSrc1NSensitivity::DpchAppData();
				((PnlWdbeSigSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeSigSrc1NSensitivity::DpchAppDo();
				((PnlWdbeSigSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NBANKDATA) {
				req->dpchapp = new PnlWdbeSil1NBank::DpchAppData();
				((PnlWdbeSil1NBank::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NBANKDO) {
				req->dpchapp = new PnlWdbeSil1NBank::DpchAppDo();
				((PnlWdbeSil1NBank::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NINTERRUPTDATA) {
				req->dpchapp = new PnlWdbeSil1NInterrupt::DpchAppData();
				((PnlWdbeSil1NInterrupt::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NINTERRUPTDO) {
				req->dpchapp = new PnlWdbeSil1NInterrupt::DpchAppDo();
				((PnlWdbeSil1NInterrupt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeSil1NPeripheral::DpchAppData();
				((PnlWdbeSil1NPeripheral::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NPERIPHERALDO) {
				req->dpchapp = new PnlWdbeSil1NPeripheral::DpchAppDo();
				((PnlWdbeSil1NPeripheral::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDATA) {
				req->dpchapp = new PnlWdbeSilDetail::DpchAppData();
				((PnlWdbeSilDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDO) {
				req->dpchapp = new PnlWdbeSilDetail::DpchAppDo();
				((PnlWdbeSilDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDO) {
				req->dpchapp = new CrdWdbeSil::DpchAppDo();
				((CrdWdbeSil::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeSilHk1NModule::DpchAppData();
				((PnlWdbeSilHk1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeSilHk1NModule::DpchAppDo();
				((PnlWdbeSilHk1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeSilHk1NVector::DpchAppData();
				((PnlWdbeSilHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeSilHk1NVector::DpchAppDo();
				((PnlWdbeSilHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILLISTDATA) {
				req->dpchapp = new PnlWdbeSilList::DpchAppData();
				((PnlWdbeSilList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILLISTDO) {
				req->dpchapp = new PnlWdbeSilList::DpchAppDo();
				((PnlWdbeSilList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILRECDO) {
				req->dpchapp = new PnlWdbeSilRec::DpchAppDo();
				((PnlWdbeSilRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeSilRef1NCommand::DpchAppData();
				((PnlWdbeSilRef1NCommand::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeSilRef1NCommand::DpchAppDo();
				((PnlWdbeSilRef1NCommand::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeSilRef1NError::DpchAppData();
				((PnlWdbeSilRef1NError::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NERRORDO) {
				req->dpchapp = new PnlWdbeSilRef1NError::DpchAppDo();
				((PnlWdbeSilRef1NError::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeSilRef1NSignal::DpchAppData();
				((PnlWdbeSilRef1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeSilRef1NSignal::DpchAppDo();
				((PnlWdbeSilRef1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILSIL1NUNITDATA) {
				req->dpchapp = new PnlWdbeSilSil1NUnit::DpchAppData();
				((PnlWdbeSilSil1NUnit::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILSIL1NUNITDO) {
				req->dpchapp = new PnlWdbeSilSil1NUnit::DpchAppDo();
				((PnlWdbeSilSil1NUnit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDATA) {
				req->dpchapp = new PnlWdbeSnsDetail::DpchAppData();
				((PnlWdbeSnsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDO) {
				req->dpchapp = new PnlWdbeSnsDetail::DpchAppDo();
				((PnlWdbeSnsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDO) {
				req->dpchapp = new CrdWdbeSns::DpchAppDo();
				((CrdWdbeSns::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSLISTDATA) {
				req->dpchapp = new PnlWdbeSnsList::DpchAppData();
				((PnlWdbeSnsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSLISTDO) {
				req->dpchapp = new PnlWdbeSnsList::DpchAppDo();
				((PnlWdbeSnsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSRECDO) {
				req->dpchapp = new PnlWdbeSnsRec::DpchAppDo();
				((PnlWdbeSnsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NBANKDATA) {
				req->dpchapp = new PnlWdbeUnt1NBank::DpchAppData();
				((PnlWdbeUnt1NBank::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NBANKDO) {
				req->dpchapp = new PnlWdbeUnt1NBank::DpchAppDo();
				((PnlWdbeUnt1NBank::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NINTERRUPTDATA) {
				req->dpchapp = new PnlWdbeUnt1NInterrupt::DpchAppData();
				((PnlWdbeUnt1NInterrupt::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NINTERRUPTDO) {
				req->dpchapp = new PnlWdbeUnt1NInterrupt::DpchAppDo();
				((PnlWdbeUnt1NInterrupt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeUnt1NPeripheral::DpchAppData();
				((PnlWdbeUnt1NPeripheral::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NPERIPHERALDO) {
				req->dpchapp = new PnlWdbeUnt1NPeripheral::DpchAppDo();
				((PnlWdbeUnt1NPeripheral::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDETAILDATA) {
				req->dpchapp = new PnlWdbeUntDetail::DpchAppData();
				((PnlWdbeUntDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDETAILDO) {
				req->dpchapp = new PnlWdbeUntDetail::DpchAppDo();
				((PnlWdbeUntDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDO) {
				req->dpchapp = new CrdWdbeUnt::DpchAppDo();
				((CrdWdbeUnt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeUntHk1NModule::DpchAppData();
				((PnlWdbeUntHk1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeUntHk1NModule::DpchAppDo();
				((PnlWdbeUntHk1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeUntHk1NVector::DpchAppData();
				((PnlWdbeUntHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeUntHk1NVector::DpchAppDo();
				((PnlWdbeUntHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTLISTDATA) {
				req->dpchapp = new PnlWdbeUntList::DpchAppData();
				((PnlWdbeUntList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTLISTDO) {
				req->dpchapp = new PnlWdbeUntList::DpchAppDo();
				((PnlWdbeUntList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTRECDO) {
				req->dpchapp = new PnlWdbeUntRec::DpchAppDo();
				((PnlWdbeUntRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeUntRef1NCommand::DpchAppData();
				((PnlWdbeUntRef1NCommand::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeUntRef1NCommand::DpchAppDo();
				((PnlWdbeUntRef1NCommand::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeUntRef1NError::DpchAppData();
				((PnlWdbeUntRef1NError::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NERRORDO) {
				req->dpchapp = new PnlWdbeUntRef1NError::DpchAppDo();
				((PnlWdbeUntRef1NError::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeUntRef1NSignal::DpchAppData();
				((PnlWdbeUntRef1NSignal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeUntRef1NSignal::DpchAppDo();
				((PnlWdbeUntRef1NSignal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTSIL1NUNITDATA) {
				req->dpchapp = new PnlWdbeUntSil1NUnit::DpchAppData();
				((PnlWdbeUntSil1NUnit::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTSIL1NUNITDO) {
				req->dpchapp = new PnlWdbeUntSil1NUnit::DpchAppDo();
				((PnlWdbeUntSil1NUnit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGAACCESSDATA) {
				req->dpchapp = new PnlWdbeUsgAAccess::DpchAppData();
				((PnlWdbeUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGAACCESSDO) {
				req->dpchapp = new PnlWdbeUsgAAccess::DpchAppDo();
				((PnlWdbeUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDETAILDATA) {
				req->dpchapp = new PnlWdbeUsgDetail::DpchAppData();
				((PnlWdbeUsgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDETAILDO) {
				req->dpchapp = new PnlWdbeUsgDetail::DpchAppDo();
				((PnlWdbeUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDO) {
				req->dpchapp = new CrdWdbeUsg::DpchAppDo();
				((CrdWdbeUsg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGLISTDATA) {
				req->dpchapp = new PnlWdbeUsgList::DpchAppData();
				((PnlWdbeUsgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGLISTDO) {
				req->dpchapp = new PnlWdbeUsgList::DpchAppDo();
				((PnlWdbeUsgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGMNUSERDATA) {
				req->dpchapp = new PnlWdbeUsgMNUser::DpchAppData();
				((PnlWdbeUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGMNUSERDO) {
				req->dpchapp = new PnlWdbeUsgMNUser::DpchAppDo();
				((PnlWdbeUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGRECDO) {
				req->dpchapp = new PnlWdbeUsgRec::DpchAppDo();
				((PnlWdbeUsgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSR1NSESSIONDATA) {
				req->dpchapp = new PnlWdbeUsr1NSession::DpchAppData();
				((PnlWdbeUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSR1NSESSIONDO) {
				req->dpchapp = new PnlWdbeUsr1NSession::DpchAppDo();
				((PnlWdbeUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRAACCESSDATA) {
				req->dpchapp = new PnlWdbeUsrAAccess::DpchAppData();
				((PnlWdbeUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRAACCESSDO) {
				req->dpchapp = new PnlWdbeUsrAAccess::DpchAppDo();
				((PnlWdbeUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDETAILDATA) {
				req->dpchapp = new PnlWdbeUsrDetail::DpchAppData();
				((PnlWdbeUsrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDETAILDO) {
				req->dpchapp = new PnlWdbeUsrDetail::DpchAppDo();
				((PnlWdbeUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDO) {
				req->dpchapp = new CrdWdbeUsr::DpchAppDo();
				((CrdWdbeUsr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRLISTDATA) {
				req->dpchapp = new PnlWdbeUsrList::DpchAppData();
				((PnlWdbeUsrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRLISTDO) {
				req->dpchapp = new PnlWdbeUsrList::DpchAppDo();
				((PnlWdbeUsrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRMNUSERGROUPDATA) {
				req->dpchapp = new PnlWdbeUsrMNUsergroup::DpchAppData();
				((PnlWdbeUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRMNUSERGROUPDO) {
				req->dpchapp = new PnlWdbeUsrMNUsergroup::DpchAppDo();
				((PnlWdbeUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRRECDO) {
				req->dpchapp = new PnlWdbeUsrRec::DpchAppDo();
				((PnlWdbeUsrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUTLDO) {
				req->dpchapp = new CrdWdbeUtl::DpchAppDo();
				((CrdWdbeUtl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDATA) {
				req->dpchapp = new PnlWdbeVarDetail::DpchAppData();
				((PnlWdbeVarDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDO) {
				req->dpchapp = new PnlWdbeVarDetail::DpchAppDo();
				((PnlWdbeVarDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDO) {
				req->dpchapp = new CrdWdbeVar::DpchAppDo();
				((CrdWdbeVar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARLISTDATA) {
				req->dpchapp = new PnlWdbeVarList::DpchAppData();
				((PnlWdbeVarList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARLISTDO) {
				req->dpchapp = new PnlWdbeVarList::DpchAppDo();
				((PnlWdbeVarList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARRECDO) {
				req->dpchapp = new PnlWdbeVarRec::DpchAppDo();
				((PnlWdbeVarRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDATA) {
				req->dpchapp = new PnlWdbeVecDetail::DpchAppData();
				((PnlWdbeVecDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDO) {
				req->dpchapp = new PnlWdbeVecDetail::DpchAppDo();
				((PnlWdbeVecDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDO) {
				req->dpchapp = new CrdWdbeVec::DpchAppDo();
				((CrdWdbeVec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECLISTDATA) {
				req->dpchapp = new PnlWdbeVecList::DpchAppData();
				((PnlWdbeVecList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECLISTDO) {
				req->dpchapp = new PnlWdbeVecList::DpchAppDo();
				((PnlWdbeVecList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECRECDO) {
				req->dpchapp = new PnlWdbeVecRec::DpchAppDo();
				((PnlWdbeVecRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECVEC1NVECTORITEMDATA) {
				req->dpchapp = new PnlWdbeVecVec1NVectoritem::DpchAppData();
				((PnlWdbeVecVec1NVectoritem::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECVEC1NVECTORITEMDO) {
				req->dpchapp = new PnlWdbeVecVec1NVectoritem::DpchAppDo();
				((PnlWdbeVecVec1NVectoritem::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NCOMPONENTDATA) {
				req->dpchapp = new PnlWdbeVer1NComponent::DpchAppData();
				((PnlWdbeVer1NComponent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NCOMPONENTDO) {
				req->dpchapp = new PnlWdbeVer1NComponent::DpchAppDo();
				((PnlWdbeVer1NComponent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NUNITDATA) {
				req->dpchapp = new PnlWdbeVer1NUnit::DpchAppData();
				((PnlWdbeVer1NUnit::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NUNITDO) {
				req->dpchapp = new PnlWdbeVer1NUnit::DpchAppDo();
				((PnlWdbeVer1NUnit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERBVR1NVERSIONDATA) {
				req->dpchapp = new PnlWdbeVerBvr1NVersion::DpchAppData();
				((PnlWdbeVerBvr1NVersion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERBVR1NVERSIONDO) {
				req->dpchapp = new PnlWdbeVerBvr1NVersion::DpchAppDo();
				((PnlWdbeVerBvr1NVersion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDATA) {
				req->dpchapp = new PnlWdbeVerDetail::DpchAppData();
				((PnlWdbeVerDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDO) {
				req->dpchapp = new PnlWdbeVerDetail::DpchAppDo();
				((PnlWdbeVerDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDO) {
				req->dpchapp = new CrdWdbeVer::DpchAppDo();
				((CrdWdbeVer::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERLISTDATA) {
				req->dpchapp = new PnlWdbeVerList::DpchAppData();
				((PnlWdbeVerList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERLISTDO) {
				req->dpchapp = new PnlWdbeVerList::DpchAppDo();
				((PnlWdbeVerList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERRECDO) {
				req->dpchapp = new PnlWdbeVerRec::DpchAppDo();
				((PnlWdbeVerRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERREF1NFILEDATA) {
				req->dpchapp = new PnlWdbeVerRef1NFile::DpchAppData();
				((PnlWdbeVerRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERREF1NFILEDO) {
				req->dpchapp = new PnlWdbeVerRef1NFile::DpchAppDo();
				((PnlWdbeVerRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDETAILDATA) {
				req->dpchapp = new PnlWdbeVitDetail::DpchAppData();
				((PnlWdbeVitDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDETAILDO) {
				req->dpchapp = new PnlWdbeVitDetail::DpchAppDo();
				((PnlWdbeVitDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDO) {
				req->dpchapp = new CrdWdbeVit::DpchAppDo();
				((CrdWdbeVit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITLISTDATA) {
				req->dpchapp = new PnlWdbeVitList::DpchAppData();
				((PnlWdbeVitList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITLISTDO) {
				req->dpchapp = new PnlWdbeVitList::DpchAppDo();
				((PnlWdbeVitList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITRECDO) {
				req->dpchapp = new PnlWdbeVitRec::DpchAppDo();
				((PnlWdbeVitRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			};
		} catch (SbeException& e) {
		};

		if (docctx) xmlXPathFreeContext(docctx);
		if (doc) xmlFreeDoc(doc);

	} else {
		try {
			reader.parse(string(req->request), root);

			members = root.getMemberNames();
			if (members.size() == 1) ixWdbeVDpch = VecWdbeVDpch::getIx(members[0]);

			if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECPRNEWDATA) {
				req->dpchapp = new DlgWdbeCprNew::DpchAppData();
				((DlgWdbeCprNew::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECPRNEWDO) {
				req->dpchapp = new DlgWdbeCprNew::DpchAppDo();
				((DlgWdbeCprNew::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDATA) {
				req->dpchapp = new DlgWdbeCvrBsccd::DpchAppData();
				((DlgWdbeCvrBsccd::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDO) {
				req->dpchapp = new DlgWdbeCvrBsccd::DpchAppDo();
				((DlgWdbeCvrBsccd::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDATA) {
				req->dpchapp = new DlgWdbeCvrDetcd::DpchAppData();
				((DlgWdbeCvrDetcd::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDO) {
				req->dpchapp = new DlgWdbeCvrDetcd::DpchAppDo();
				((DlgWdbeCvrDetcd::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDATA) {
				req->dpchapp = new DlgWdbeCvrNew::DpchAppData();
				((DlgWdbeCvrNew::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDO) {
				req->dpchapp = new DlgWdbeCvrNew::DpchAppDo();
				((DlgWdbeCvrNew::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDATA) {
				req->dpchapp = new DlgWdbeCvrWrite::DpchAppData();
				((DlgWdbeCvrWrite::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDO) {
				req->dpchapp = new DlgWdbeCvrWrite::DpchAppDo();
				((DlgWdbeCvrWrite::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILDOWNLOADDO) {
				req->dpchapp = new DlgWdbeFilDownload::DpchAppDo();
				((DlgWdbeFilDownload::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDATA) {
				req->dpchapp = new DlgWdbeFilNew::DpchAppData();
				((DlgWdbeFilNew::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDO) {
				req->dpchapp = new DlgWdbeFilNew::DpchAppDo();
				((DlgWdbeFilNew::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDATA) {
				req->dpchapp = new DlgWdbeNavLoaini::DpchAppData();
				((DlgWdbeNavLoaini::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDO) {
				req->dpchapp = new DlgWdbeNavLoaini::DpchAppDo();
				((DlgWdbeNavLoaini::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDATA) {
				req->dpchapp = new DlgWdbeNavMnglic::DpchAppData();
				((DlgWdbeNavMnglic::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDO) {
				req->dpchapp = new DlgWdbeNavMnglic::DpchAppDo();
				((DlgWdbeNavMnglic::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDATA) {
				req->dpchapp = new DlgWdbePrjImpex::DpchAppData();
				((DlgWdbePrjImpex::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDO) {
				req->dpchapp = new DlgWdbePrjImpex::DpchAppDo();
				((DlgWdbePrjImpex::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDATA) {
				req->dpchapp = new DlgWdbePrjNew::DpchAppData();
				((DlgWdbePrjNew::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDO) {
				req->dpchapp = new DlgWdbePrjNew::DpchAppDo();
				((DlgWdbePrjNew::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDATA) {
				req->dpchapp = new DlgWdbeRlsFinreptr::DpchAppData();
				((DlgWdbeRlsFinreptr::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDO) {
				req->dpchapp = new DlgWdbeRlsFinreptr::DpchAppDo();
				((DlgWdbeRlsFinreptr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDATA) {
				req->dpchapp = new DlgWdbeRlsStareptr::DpchAppData();
				((DlgWdbeRlsStareptr::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDO) {
				req->dpchapp = new DlgWdbeRlsStareptr::DpchAppDo();
				((DlgWdbeRlsStareptr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDATA) {
				req->dpchapp = new DlgWdbeRlsWrite::DpchAppData();
				((DlgWdbeRlsWrite::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDO) {
				req->dpchapp = new DlgWdbeRlsWrite::DpchAppDo();
				((DlgWdbeRlsWrite::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUSRMNGKEYPAIRDO) {
				req->dpchapp = new DlgWdbeUsrMngkeypair::DpchAppDo();
				((DlgWdbeUsrMngkeypair::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLEXTRIPDATA) {
				req->dpchapp = new DlgWdbeUtlExtrip::DpchAppData();
				((DlgWdbeUtlExtrip::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLEXTRIPDO) {
				req->dpchapp = new DlgWdbeUtlExtrip::DpchAppDo();
				((DlgWdbeUtlExtrip::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDATA) {
				req->dpchapp = new DlgWdbeUtlMrgip::DpchAppData();
				((DlgWdbeUtlMrgip::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDO) {
				req->dpchapp = new DlgWdbeUtlMrgip::DpchAppDo();
				((DlgWdbeUtlMrgip::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCMDSETDATA) {
				req->dpchapp = new DlgWdbeVerCmdset::DpchAppData();
				((DlgWdbeVerCmdset::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCMDSETDO) {
				req->dpchapp = new DlgWdbeVerCmdset::DpchAppDo();
				((DlgWdbeVerCmdset::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCUSTFSTDATA) {
				req->dpchapp = new DlgWdbeVerCustfst::DpchAppData();
				((DlgWdbeVerCustfst::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERCUSTFSTDO) {
				req->dpchapp = new DlgWdbeVerCustfst::DpchAppDo();
				((DlgWdbeVerCustfst::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDEPLOYDATA) {
				req->dpchapp = new DlgWdbeVerDeploy::DpchAppData();
				((DlgWdbeVerDeploy::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDEPLOYDO) {
				req->dpchapp = new DlgWdbeVerDeploy::DpchAppDo();
				((DlgWdbeVerDeploy::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDFLALGDATA) {
				req->dpchapp = new DlgWdbeVerDflalg::DpchAppData();
				((DlgWdbeVerDflalg::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDFLALGDO) {
				req->dpchapp = new DlgWdbeVerDflalg::DpchAppDo();
				((DlgWdbeVerDflalg::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDATA) {
				req->dpchapp = new DlgWdbeVerFinmod::DpchAppData();
				((DlgWdbeVerFinmod::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDO) {
				req->dpchapp = new DlgWdbeVerFinmod::DpchAppDo();
				((DlgWdbeVerFinmod::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERGENFSTDO) {
				req->dpchapp = new DlgWdbeVerGenfst::DpchAppDo();
				((DlgWdbeVerGenfst::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERMDLSTRDATA) {
				req->dpchapp = new DlgWdbeVerMdlstr::DpchAppData();
				((DlgWdbeVerMdlstr::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERMDLSTRDO) {
				req->dpchapp = new DlgWdbeVerMdlstr::DpchAppDo();
				((DlgWdbeVerMdlstr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDATA) {
				req->dpchapp = new DlgWdbeVerNew::DpchAppData();
				((DlgWdbeVerNew::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDO) {
				req->dpchapp = new DlgWdbeVerNew::DpchAppDo();
				((DlgWdbeVerNew::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPROOTWDBELOGIN) {
				req->dpchapp = new RootWdbe::DpchAppLogin();
				((RootWdbe::DpchAppLogin*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
				req->dpchapp = new DpchAppWdbeAlert();
				((DpchAppWdbeAlert*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDATA) {
				req->dpchapp = new PnlWdbeBnk1NPin::DpchAppData();
				((PnlWdbeBnk1NPin::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDO) {
				req->dpchapp = new PnlWdbeBnk1NPin::DpchAppDo();
				((PnlWdbeBnk1NPin::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDATA) {
				req->dpchapp = new PnlWdbeBnkDetail::DpchAppData();
				((PnlWdbeBnkDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDO) {
				req->dpchapp = new PnlWdbeBnkDetail::DpchAppDo();
				((PnlWdbeBnkDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDO) {
				req->dpchapp = new CrdWdbeBnk::DpchAppDo();
				((CrdWdbeBnk::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKLISTDATA) {
				req->dpchapp = new PnlWdbeBnkList::DpchAppData();
				((PnlWdbeBnkList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKLISTDO) {
				req->dpchapp = new PnlWdbeBnkList::DpchAppDo();
				((PnlWdbeBnkList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKRECDO) {
				req->dpchapp = new PnlWdbeBnkRec::DpchAppDo();
				((PnlWdbeBnkRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDATA) {
				req->dpchapp = new PnlWdbeCdcDetail::DpchAppData();
				((PnlWdbeCdcDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDO) {
				req->dpchapp = new PnlWdbeCdcDetail::DpchAppDo();
				((PnlWdbeCdcDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDO) {
				req->dpchapp = new CrdWdbeCdc::DpchAppDo();
				((CrdWdbeCdc::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCLISTDATA) {
				req->dpchapp = new PnlWdbeCdcList::DpchAppData();
				((PnlWdbeCdcList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCLISTDO) {
				req->dpchapp = new PnlWdbeCdcList::DpchAppDo();
				((PnlWdbeCdcList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCMNSIGNALDATA) {
				req->dpchapp = new PnlWdbeCdcMNSignal::DpchAppData();
				((PnlWdbeCdcMNSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCMNSIGNALDO) {
				req->dpchapp = new PnlWdbeCdcMNSignal::DpchAppDo();
				((PnlWdbeCdcMNSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCRECDO) {
				req->dpchapp = new PnlWdbeCdcRec::DpchAppDo();
				((PnlWdbeCdcRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDAINVPARDATA) {
				req->dpchapp = new PnlWdbeCmdAInvpar::DpchAppData();
				((PnlWdbeCmdAInvpar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDAINVPARDO) {
				req->dpchapp = new PnlWdbeCmdAInvpar::DpchAppDo();
				((PnlWdbeCmdAInvpar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDARETPARDATA) {
				req->dpchapp = new PnlWdbeCmdARetpar::DpchAppData();
				((PnlWdbeCmdARetpar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDARETPARDO) {
				req->dpchapp = new PnlWdbeCmdARetpar::DpchAppDo();
				((PnlWdbeCmdARetpar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDATA) {
				req->dpchapp = new PnlWdbeCmdDetail::DpchAppData();
				((PnlWdbeCmdDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDO) {
				req->dpchapp = new PnlWdbeCmdDetail::DpchAppDo();
				((PnlWdbeCmdDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDO) {
				req->dpchapp = new CrdWdbeCmd::DpchAppDo();
				((CrdWdbeCmd::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDLISTDATA) {
				req->dpchapp = new PnlWdbeCmdList::DpchAppData();
				((PnlWdbeCmdList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDLISTDO) {
				req->dpchapp = new PnlWdbeCmdList::DpchAppDo();
				((PnlWdbeCmdList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDMNCONTROLLERDATA) {
				req->dpchapp = new PnlWdbeCmdMNController::DpchAppData();
				((PnlWdbeCmdMNController::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDMNCONTROLLERDO) {
				req->dpchapp = new PnlWdbeCmdMNController::DpchAppDo();
				((PnlWdbeCmdMNController::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDRECDO) {
				req->dpchapp = new PnlWdbeCmdRec::DpchAppDo();
				((PnlWdbeCmdRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMP1NRELEASEDATA) {
				req->dpchapp = new PnlWdbeCmp1NRelease::DpchAppData();
				((PnlWdbeCmp1NRelease::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMP1NRELEASEDO) {
				req->dpchapp = new PnlWdbeCmp1NRelease::DpchAppDo();
				((PnlWdbeCmp1NRelease::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDETAILDATA) {
				req->dpchapp = new PnlWdbeCmpDetail::DpchAppData();
				((PnlWdbeCmpDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDETAILDO) {
				req->dpchapp = new PnlWdbeCmpDetail::DpchAppDo();
				((PnlWdbeCmpDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPDO) {
				req->dpchapp = new CrdWdbeCmp::DpchAppDo();
				((CrdWdbeCmp::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPLISTDATA) {
				req->dpchapp = new PnlWdbeCmpList::DpchAppData();
				((PnlWdbeCmpList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPLISTDO) {
				req->dpchapp = new PnlWdbeCmpList::DpchAppDo();
				((PnlWdbeCmpList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPMNLIBRARYDATA) {
				req->dpchapp = new PnlWdbeCmpMNLibrary::DpchAppData();
				((PnlWdbeCmpMNLibrary::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPMNLIBRARYDO) {
				req->dpchapp = new PnlWdbeCmpMNLibrary::DpchAppDo();
				((PnlWdbeCmpMNLibrary::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMPRECDO) {
				req->dpchapp = new PnlWdbeCmpRec::DpchAppDo();
				((PnlWdbeCmpRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPR1NCOREVERSIONDATA) {
				req->dpchapp = new PnlWdbeCpr1NCoreversion::DpchAppData();
				((PnlWdbeCpr1NCoreversion::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPR1NCOREVERSIONDO) {
				req->dpchapp = new PnlWdbeCpr1NCoreversion::DpchAppDo();
				((PnlWdbeCpr1NCoreversion::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDETAILDATA) {
				req->dpchapp = new PnlWdbeCprDetail::DpchAppData();
				((PnlWdbeCprDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDETAILDO) {
				req->dpchapp = new PnlWdbeCprDetail::DpchAppDo();
				((PnlWdbeCprDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRDO) {
				req->dpchapp = new CrdWdbeCpr::DpchAppDo();
				((CrdWdbeCpr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRLISTDATA) {
				req->dpchapp = new PnlWdbeCprList::DpchAppData();
				((PnlWdbeCprList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRLISTDO) {
				req->dpchapp = new PnlWdbeCprList::DpchAppDo();
				((PnlWdbeCprList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRMNPERSONDATA) {
				req->dpchapp = new PnlWdbeCprMNPerson::DpchAppData();
				((PnlWdbeCprMNPerson::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRMNPERSONDO) {
				req->dpchapp = new PnlWdbeCprMNPerson::DpchAppDo();
				((PnlWdbeCprMNPerson::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECPRRECDO) {
				req->dpchapp = new PnlWdbeCprRec::DpchAppDo();
				((PnlWdbeCprRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAIPDATA) {
				req->dpchapp = new PnlWdbeCvrAIp::DpchAppData();
				((PnlWdbeCvrAIp::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAIPDO) {
				req->dpchapp = new PnlWdbeCvrAIp::DpchAppDo();
				((PnlWdbeCvrAIp::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAPLHDATA) {
				req->dpchapp = new PnlWdbeCvrAPlh::DpchAppData();
				((PnlWdbeCvrAPlh::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRAPLHDO) {
				req->dpchapp = new PnlWdbeCvrAPlh::DpchAppDo();
				((PnlWdbeCvrAPlh::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRBCV1NCOREVERSIONDATA) {
				req->dpchapp = new PnlWdbeCvrBcv1NCoreversion::DpchAppData();
				((PnlWdbeCvrBcv1NCoreversion::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRBCV1NCOREVERSIONDO) {
				req->dpchapp = new PnlWdbeCvrBcv1NCoreversion::DpchAppDo();
				((PnlWdbeCvrBcv1NCoreversion::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDATA) {
				req->dpchapp = new PnlWdbeCvrDetail::DpchAppData();
				((PnlWdbeCvrDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDO) {
				req->dpchapp = new PnlWdbeCvrDetail::DpchAppDo();
				((PnlWdbeCvrDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDO) {
				req->dpchapp = new CrdWdbeCvr::DpchAppDo();
				((CrdWdbeCvr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeCvrHk1NModule::DpchAppData();
				((PnlWdbeCvrHk1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeCvrHk1NModule::DpchAppDo();
				((PnlWdbeCvrHk1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRLISTDATA) {
				req->dpchapp = new PnlWdbeCvrList::DpchAppData();
				((PnlWdbeCvrList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRLISTDO) {
				req->dpchapp = new PnlWdbeCvrList::DpchAppDo();
				((PnlWdbeCvrList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRRECDO) {
				req->dpchapp = new PnlWdbeCvrRec::DpchAppDo();
				((PnlWdbeCvrRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRAPARDATA) {
				req->dpchapp = new PnlWdbeErrAPar::DpchAppData();
				((PnlWdbeErrAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRAPARDO) {
				req->dpchapp = new PnlWdbeErrAPar::DpchAppDo();
				((PnlWdbeErrAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDATA) {
				req->dpchapp = new PnlWdbeErrDetail::DpchAppData();
				((PnlWdbeErrDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDO) {
				req->dpchapp = new PnlWdbeErrDetail::DpchAppDo();
				((PnlWdbeErrDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDO) {
				req->dpchapp = new CrdWdbeErr::DpchAppDo();
				((CrdWdbeErr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRLISTDATA) {
				req->dpchapp = new PnlWdbeErrList::DpchAppData();
				((PnlWdbeErrList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRLISTDO) {
				req->dpchapp = new PnlWdbeErrList::DpchAppDo();
				((PnlWdbeErrList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRRECDO) {
				req->dpchapp = new PnlWdbeErrRec::DpchAppDo();
				((PnlWdbeErrRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAM1NUNITDATA) {
				req->dpchapp = new PnlWdbeFam1NUnit::DpchAppData();
				((PnlWdbeFam1NUnit::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAM1NUNITDO) {
				req->dpchapp = new PnlWdbeFam1NUnit::DpchAppDo();
				((PnlWdbeFam1NUnit::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDATA) {
				req->dpchapp = new PnlWdbeFamDetail::DpchAppData();
				((PnlWdbeFamDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDO) {
				req->dpchapp = new PnlWdbeFamDetail::DpchAppDo();
				((PnlWdbeFamDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMDO) {
				req->dpchapp = new CrdWdbeFam::DpchAppDo();
				((CrdWdbeFam::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMLISTDATA) {
				req->dpchapp = new PnlWdbeFamList::DpchAppData();
				((PnlWdbeFamList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMLISTDO) {
				req->dpchapp = new PnlWdbeFamList::DpchAppDo();
				((PnlWdbeFamList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFAMRECDO) {
				req->dpchapp = new PnlWdbeFamRec::DpchAppDo();
				((PnlWdbeFamRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDETAILDATA) {
				req->dpchapp = new PnlWdbeFilDetail::DpchAppData();
				((PnlWdbeFilDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDETAILDO) {
				req->dpchapp = new PnlWdbeFilDetail::DpchAppDo();
				((PnlWdbeFilDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILDO) {
				req->dpchapp = new CrdWdbeFil::DpchAppDo();
				((CrdWdbeFil::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILLISTDATA) {
				req->dpchapp = new PnlWdbeFilList::DpchAppData();
				((PnlWdbeFilList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILLISTDO) {
				req->dpchapp = new PnlWdbeFilList::DpchAppDo();
				((PnlWdbeFilList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFILRECDO) {
				req->dpchapp = new PnlWdbeFilRec::DpchAppDo();
				((PnlWdbeFilRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDATA) {
				req->dpchapp = new PnlWdbeFstAStep::DpchAppData();
				((PnlWdbeFstAStep::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDO) {
				req->dpchapp = new PnlWdbeFstAStep::DpchAppDo();
				((PnlWdbeFstAStep::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDETAILDATA) {
				req->dpchapp = new PnlWdbeFstDetail::DpchAppData();
				((PnlWdbeFstDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDETAILDO) {
				req->dpchapp = new PnlWdbeFstDetail::DpchAppDo();
				((PnlWdbeFstDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTDO) {
				req->dpchapp = new CrdWdbeFst::DpchAppDo();
				((CrdWdbeFst::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTLISTDATA) {
				req->dpchapp = new PnlWdbeFstList::DpchAppData();
				((PnlWdbeFstList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTLISTDO) {
				req->dpchapp = new PnlWdbeFstList::DpchAppDo();
				((PnlWdbeFstList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEFSTRECDO) {
				req->dpchapp = new PnlWdbeFstRec::DpchAppDo();
				((PnlWdbeFstRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDATA) {
				req->dpchapp = new PnlWdbeGenDetail::DpchAppData();
				((PnlWdbeGenDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDO) {
				req->dpchapp = new PnlWdbeGenDetail::DpchAppDo();
				((PnlWdbeGenDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDO) {
				req->dpchapp = new CrdWdbeGen::DpchAppDo();
				((CrdWdbeGen::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENLISTDATA) {
				req->dpchapp = new PnlWdbeGenList::DpchAppData();
				((PnlWdbeGenList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENLISTDO) {
				req->dpchapp = new PnlWdbeGenList::DpchAppDo();
				((PnlWdbeGenList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENRECDO) {
				req->dpchapp = new PnlWdbeGenRec::DpchAppDo();
				((PnlWdbeGenRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
				req->dpchapp = new DpchAppWdbeInit();
				((DpchAppWdbeInit*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDETAILDATA) {
				req->dpchapp = new PnlWdbeIntDetail::DpchAppData();
				((PnlWdbeIntDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDETAILDO) {
				req->dpchapp = new PnlWdbeIntDetail::DpchAppDo();
				((PnlWdbeIntDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTDO) {
				req->dpchapp = new CrdWdbeInt::DpchAppDo();
				((CrdWdbeInt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTLISTDATA) {
				req->dpchapp = new PnlWdbeIntList::DpchAppData();
				((PnlWdbeIntList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTLISTDO) {
				req->dpchapp = new PnlWdbeIntList::DpchAppDo();
				((PnlWdbeIntList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTRECDO) {
				req->dpchapp = new PnlWdbeIntRec::DpchAppDo();
				((PnlWdbeIntRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeIntSrc1NSensitivity::DpchAppData();
				((PnlWdbeIntSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINTSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeIntSrc1NSensitivity::DpchAppDo();
				((PnlWdbeIntSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBAMAKEFILEDATA) {
				req->dpchapp = new PnlWdbeLibAMakefile::DpchAppData();
				((PnlWdbeLibAMakefile::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBAMAKEFILEDO) {
				req->dpchapp = new PnlWdbeLibAMakefile::DpchAppDo();
				((PnlWdbeLibAMakefile::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDETAILDATA) {
				req->dpchapp = new PnlWdbeLibDetail::DpchAppData();
				((PnlWdbeLibDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDETAILDO) {
				req->dpchapp = new PnlWdbeLibDetail::DpchAppDo();
				((PnlWdbeLibDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBDO) {
				req->dpchapp = new CrdWdbeLib::DpchAppDo();
				((CrdWdbeLib::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBLISTDATA) {
				req->dpchapp = new PnlWdbeLibList::DpchAppData();
				((PnlWdbeLibList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBLISTDO) {
				req->dpchapp = new PnlWdbeLibList::DpchAppDo();
				((PnlWdbeLibList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBMNCOMPONENTDATA) {
				req->dpchapp = new PnlWdbeLibMNComponent::DpchAppData();
				((PnlWdbeLibMNComponent::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBMNCOMPONENTDO) {
				req->dpchapp = new PnlWdbeLibMNComponent::DpchAppDo();
				((PnlWdbeLibMNComponent::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBELIBRECDO) {
				req->dpchapp = new PnlWdbeLibRec::DpchAppDo();
				((PnlWdbeLibRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCH1NRELEASEDATA) {
				req->dpchapp = new PnlWdbeMch1NRelease::DpchAppData();
				((PnlWdbeMch1NRelease::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCH1NRELEASEDO) {
				req->dpchapp = new PnlWdbeMch1NRelease::DpchAppDo();
				((PnlWdbeMch1NRelease::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAMAKEFILEDATA) {
				req->dpchapp = new PnlWdbeMchAMakefile::DpchAppData();
				((PnlWdbeMchAMakefile::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAMAKEFILEDO) {
				req->dpchapp = new PnlWdbeMchAMakefile::DpchAppDo();
				((PnlWdbeMchAMakefile::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDATA) {
				req->dpchapp = new PnlWdbeMchAPar::DpchAppData();
				((PnlWdbeMchAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDO) {
				req->dpchapp = new PnlWdbeMchAPar::DpchAppDo();
				((PnlWdbeMchAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDETAILDATA) {
				req->dpchapp = new PnlWdbeMchDetail::DpchAppData();
				((PnlWdbeMchDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDETAILDO) {
				req->dpchapp = new PnlWdbeMchDetail::DpchAppDo();
				((PnlWdbeMchDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHDO) {
				req->dpchapp = new CrdWdbeMch::DpchAppDo();
				((CrdWdbeMch::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHLISTDATA) {
				req->dpchapp = new PnlWdbeMchList::DpchAppData();
				((PnlWdbeMchList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHLISTDO) {
				req->dpchapp = new PnlWdbeMchList::DpchAppDo();
				((PnlWdbeMchList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHRECDO) {
				req->dpchapp = new PnlWdbeMchRec::DpchAppDo();
				((PnlWdbeMchRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHSUP1NMACHINEDATA) {
				req->dpchapp = new PnlWdbeMchSup1NMachine::DpchAppData();
				((PnlWdbeMchSup1NMachine::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHSUP1NMACHINEDO) {
				req->dpchapp = new PnlWdbeMchSup1NMachine::DpchAppDo();
				((PnlWdbeMchSup1NMachine::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NCDCDATA) {
				req->dpchapp = new PnlWdbeMod1NCdc::DpchAppData();
				((PnlWdbeMod1NCdc::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NCDCDO) {
				req->dpchapp = new PnlWdbeMod1NCdc::DpchAppDo();
				((PnlWdbeMod1NCdc::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NPROCESSDATA) {
				req->dpchapp = new PnlWdbeMod1NProcess::DpchAppData();
				((PnlWdbeMod1NProcess::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMOD1NPROCESSDO) {
				req->dpchapp = new PnlWdbeMod1NProcess::DpchAppDo();
				((PnlWdbeMod1NProcess::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODAPARDATA) {
				req->dpchapp = new PnlWdbeModAPar::DpchAppData();
				((PnlWdbeModAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODAPARDO) {
				req->dpchapp = new PnlWdbeModAPar::DpchAppDo();
				((PnlWdbeModAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCORMNMODULEDATA) {
				req->dpchapp = new PnlWdbeModCorMNModule::DpchAppData();
				((PnlWdbeModCorMNModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCORMNMODULEDO) {
				req->dpchapp = new PnlWdbeModCorMNModule::DpchAppDo();
				((PnlWdbeModCorMNModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTDMNMODULEDATA) {
				req->dpchapp = new PnlWdbeModCtdMNModule::DpchAppData();
				((PnlWdbeModCtdMNModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTDMNMODULEDO) {
				req->dpchapp = new PnlWdbeModCtdMNModule::DpchAppDo();
				((PnlWdbeModCtdMNModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeModCtrHk1NVector::DpchAppData();
				((PnlWdbeModCtrHk1NVector::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeModCtrHk1NVector::DpchAppDo();
				((PnlWdbeModCtrHk1NVector::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRMNCOMMANDDATA) {
				req->dpchapp = new PnlWdbeModCtrMNCommand::DpchAppData();
				((PnlWdbeModCtrMNCommand::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRMNCOMMANDDO) {
				req->dpchapp = new PnlWdbeModCtrMNCommand::DpchAppDo();
				((PnlWdbeModCtrMNCommand::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeModCtrRef1NCommand::DpchAppData();
				((PnlWdbeModCtrRef1NCommand::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeModCtrRef1NCommand::DpchAppDo();
				((PnlWdbeModCtrRef1NCommand::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeModCtrRef1NError::DpchAppData();
				((PnlWdbeModCtrRef1NError::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODCTRREF1NERRORDO) {
				req->dpchapp = new PnlWdbeModCtrRef1NError::DpchAppDo();
				((PnlWdbeModCtrRef1NError::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDATA) {
				req->dpchapp = new PnlWdbeModDetail::DpchAppData();
				((PnlWdbeModDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDO) {
				req->dpchapp = new PnlWdbeModDetail::DpchAppDo();
				((PnlWdbeModDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDO) {
				req->dpchapp = new CrdWdbeMod::DpchAppDo();
				((CrdWdbeMod::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODHSM1NPIPELINEDATA) {
				req->dpchapp = new PnlWdbeModHsm1NPipeline::DpchAppData();
				((PnlWdbeModHsm1NPipeline::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODHSM1NPIPELINEDO) {
				req->dpchapp = new PnlWdbeModHsm1NPipeline::DpchAppDo();
				((PnlWdbeModHsm1NPipeline::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbeModKHdltype::DpchAppData();
				((PnlWdbeModKHdltype::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODKHDLTYPEDO) {
				req->dpchapp = new PnlWdbeModKHdltype::DpchAppDo();
				((PnlWdbeModKHdltype::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODLISTDATA) {
				req->dpchapp = new PnlWdbeModList::DpchAppData();
				((PnlWdbeModList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODLISTDO) {
				req->dpchapp = new PnlWdbeModList::DpchAppDo();
				((PnlWdbeModList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NGENERICDATA) {
				req->dpchapp = new PnlWdbeModMdl1NGeneric::DpchAppData();
				((PnlWdbeModMdl1NGeneric::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NGENERICDO) {
				req->dpchapp = new PnlWdbeModMdl1NGeneric::DpchAppDo();
				((PnlWdbeModMdl1NGeneric::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NPORTDATA) {
				req->dpchapp = new PnlWdbeModMdl1NPort::DpchAppData();
				((PnlWdbeModMdl1NPort::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMDL1NPORTDO) {
				req->dpchapp = new PnlWdbeModMdl1NPort::DpchAppDo();
				((PnlWdbeModMdl1NPort::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeModMge1NSignal::DpchAppData();
				((PnlWdbeModMge1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbeModMge1NSignal::DpchAppDo();
				((PnlWdbeModMge1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeModMNPeripheral::DpchAppData();
				((PnlWdbeModMNPeripheral::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDO) {
				req->dpchapp = new PnlWdbeModMNPeripheral::DpchAppDo();
				((PnlWdbeModMNPeripheral::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODRECDO) {
				req->dpchapp = new PnlWdbeModRec::DpchAppDo();
				((PnlWdbeModRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeModRef1NSensitivity::DpchAppData();
				((PnlWdbeModRef1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeModRef1NSensitivity::DpchAppDo();
				((PnlWdbeModRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeModRef1NSignal::DpchAppData();
				((PnlWdbeModRef1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeModRef1NSignal::DpchAppDo();
				((PnlWdbeModRef1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbeModRef1NVariable::DpchAppData();
				((PnlWdbeModRef1NVariable::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbeModRef1NVariable::DpchAppDo();
				((PnlWdbeModRef1NVariable::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODSUP1NMODULEDATA) {
				req->dpchapp = new PnlWdbeModSup1NModule::DpchAppData();
				((PnlWdbeModSup1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODSUP1NMODULEDO) {
				req->dpchapp = new PnlWdbeModSup1NModule::DpchAppDo();
				((PnlWdbeModSup1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPAPARDATA) {
				req->dpchapp = new PnlWdbeMtpAPar::DpchAppData();
				((PnlWdbeMtpAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPAPARDO) {
				req->dpchapp = new PnlWdbeMtpAPar::DpchAppDo();
				((PnlWdbeMtpAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDATA) {
				req->dpchapp = new PnlWdbeMtpDetail::DpchAppData();
				((PnlWdbeMtpDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDO) {
				req->dpchapp = new PnlWdbeMtpDetail::DpchAppDo();
				((PnlWdbeMtpDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDO) {
				req->dpchapp = new CrdWdbeMtp::DpchAppDo();
				((CrdWdbeMtp::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPHSM1NPIPELINEDATA) {
				req->dpchapp = new PnlWdbeMtpHsm1NPipeline::DpchAppData();
				((PnlWdbeMtpHsm1NPipeline::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPHSM1NPIPELINEDO) {
				req->dpchapp = new PnlWdbeMtpHsm1NPipeline::DpchAppDo();
				((PnlWdbeMtpHsm1NPipeline::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbeMtpKHdltype::DpchAppData();
				((PnlWdbeMtpKHdltype::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKHDLTYPEDO) {
				req->dpchapp = new PnlWdbeMtpKHdltype::DpchAppDo();
				((PnlWdbeMtpKHdltype::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKPARKEYDATA) {
				req->dpchapp = new PnlWdbeMtpKParKey::DpchAppData();
				((PnlWdbeMtpKParKey::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPKPARKEYDO) {
				req->dpchapp = new PnlWdbeMtpKParKey::DpchAppDo();
				((PnlWdbeMtpKParKey::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPLISTDATA) {
				req->dpchapp = new PnlWdbeMtpList::DpchAppData();
				((PnlWdbeMtpList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPLISTDO) {
				req->dpchapp = new PnlWdbeMtpList::DpchAppDo();
				((PnlWdbeMtpList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NGENERICDATA) {
				req->dpchapp = new PnlWdbeMtpMdl1NGeneric::DpchAppData();
				((PnlWdbeMtpMdl1NGeneric::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NGENERICDO) {
				req->dpchapp = new PnlWdbeMtpMdl1NGeneric::DpchAppDo();
				((PnlWdbeMtpMdl1NGeneric::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NPORTDATA) {
				req->dpchapp = new PnlWdbeMtpMdl1NPort::DpchAppData();
				((PnlWdbeMtpMdl1NPort::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMDL1NPORTDO) {
				req->dpchapp = new PnlWdbeMtpMdl1NPort::DpchAppDo();
				((PnlWdbeMtpMdl1NPort::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeMtpMge1NSignal::DpchAppData();
				((PnlWdbeMtpMge1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbeMtpMge1NSignal::DpchAppDo();
				((PnlWdbeMtpMge1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPRECDO) {
				req->dpchapp = new PnlWdbeMtpRec::DpchAppDo();
				((PnlWdbeMtpRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NFILEDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NFile::DpchAppData();
				((PnlWdbeMtpRef1NFile::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NFILEDO) {
				req->dpchapp = new PnlWdbeMtpRef1NFile::DpchAppDo();
				((PnlWdbeMtpRef1NFile::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NSensitivity::DpchAppData();
				((PnlWdbeMtpRef1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeMtpRef1NSensitivity::DpchAppDo();
				((PnlWdbeMtpRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbeMtpRef1NVariable::DpchAppData();
				((PnlWdbeMtpRef1NVariable::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbeMtpRef1NVariable::DpchAppDo();
				((PnlWdbeMtpRef1NVariable::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPSUP1NMODULEDATA) {
				req->dpchapp = new PnlWdbeMtpSup1NModule::DpchAppData();
				((PnlWdbeMtpSup1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPSUP1NMODULEDO) {
				req->dpchapp = new PnlWdbeMtpSup1NModule::DpchAppDo();
				((PnlWdbeMtpSup1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPTPL1NMODULEDATA) {
				req->dpchapp = new PnlWdbeMtpTpl1NModule::DpchAppData();
				((PnlWdbeMtpTpl1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPTPL1NMODULEDO) {
				req->dpchapp = new PnlWdbeMtpTpl1NModule::DpchAppDo();
				((PnlWdbeMtpTpl1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVADMINDATA) {
				req->dpchapp = new PnlWdbeNavAdmin::DpchAppData();
				((PnlWdbeNavAdmin::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVADMINDO) {
				req->dpchapp = new PnlWdbeNavAdmin::DpchAppDo();
				((PnlWdbeNavAdmin::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVAUXFCTDO) {
				req->dpchapp = new PnlWdbeNavAuxfct::DpchAppDo();
				((PnlWdbeNavAuxfct::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDATA) {
				req->dpchapp = new PnlWdbeNavCoredev::DpchAppData();
				((PnlWdbeNavCoredev::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDO) {
				req->dpchapp = new PnlWdbeNavCoredev::DpchAppDo();
				((PnlWdbeNavCoredev::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDATA) {
				req->dpchapp = new PnlWdbeNavDeploy::DpchAppData();
				((PnlWdbeNavDeploy::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDO) {
				req->dpchapp = new PnlWdbeNavDeploy::DpchAppDo();
				((PnlWdbeNavDeploy::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA) {
				req->dpchapp = new PnlWdbeNavDevdev::DpchAppData();
				((PnlWdbeNavDevdev::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO) {
				req->dpchapp = new PnlWdbeNavDevdev::DpchAppDo();
				((PnlWdbeNavDevdev::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDO) {
				req->dpchapp = new CrdWdbeNav::DpchAppDo();
				((CrdWdbeNav::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDATA) {
				req->dpchapp = new PnlWdbeNavGlobal::DpchAppData();
				((PnlWdbeNavGlobal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDO) {
				req->dpchapp = new PnlWdbeNavGlobal::DpchAppDo();
				((PnlWdbeNavGlobal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDATA) {
				req->dpchapp = new PnlWdbeNavHigh::DpchAppData();
				((PnlWdbeNavHigh::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDO) {
				req->dpchapp = new PnlWdbeNavHigh::DpchAppDo();
				((PnlWdbeNavHigh::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDATA) {
				req->dpchapp = new PnlWdbeNavLow::DpchAppData();
				((PnlWdbeNavLow::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDO) {
				req->dpchapp = new PnlWdbeNavLow::DpchAppDo();
				((PnlWdbeNavLow::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVPREDO) {
				req->dpchapp = new PnlWdbeNavPre::DpchAppDo();
				((PnlWdbeNavPre::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINAPARDATA) {
				req->dpchapp = new PnlWdbePinAPar::DpchAppData();
				((PnlWdbePinAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINAPARDO) {
				req->dpchapp = new PnlWdbePinAPar::DpchAppDo();
				((PnlWdbePinAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDATA) {
				req->dpchapp = new PnlWdbePinDetail::DpchAppData();
				((PnlWdbePinDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDO) {
				req->dpchapp = new PnlWdbePinDetail::DpchAppDo();
				((PnlWdbePinDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDO) {
				req->dpchapp = new CrdWdbePin::DpchAppDo();
				((CrdWdbePin::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINLISTDATA) {
				req->dpchapp = new PnlWdbePinList::DpchAppData();
				((PnlWdbePinList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINLISTDO) {
				req->dpchapp = new PnlWdbePinList::DpchAppDo();
				((PnlWdbePinList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINRECDO) {
				req->dpchapp = new PnlWdbePinRec::DpchAppDo();
				((PnlWdbePinRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHAPARDATA) {
				req->dpchapp = new PnlWdbePphAPar::DpchAppData();
				((PnlWdbePphAPar::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHAPARDO) {
				req->dpchapp = new PnlWdbePphAPar::DpchAppDo();
				((PnlWdbePphAPar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDETAILDATA) {
				req->dpchapp = new PnlWdbePphDetail::DpchAppData();
				((PnlWdbePphDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDETAILDO) {
				req->dpchapp = new PnlWdbePphDetail::DpchAppDo();
				((PnlWdbePphDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHDO) {
				req->dpchapp = new CrdWdbePph::DpchAppDo();
				((CrdWdbePph::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHLISTDATA) {
				req->dpchapp = new PnlWdbePphList::DpchAppData();
				((PnlWdbePphList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHLISTDO) {
				req->dpchapp = new PnlWdbePphList::DpchAppDo();
				((PnlWdbePphList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHMNMODULEDATA) {
				req->dpchapp = new PnlWdbePphMNModule::DpchAppData();
				((PnlWdbePphMNModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHMNMODULEDO) {
				req->dpchapp = new PnlWdbePphMNModule::DpchAppDo();
				((PnlWdbePphMNModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPHRECDO) {
				req->dpchapp = new PnlWdbePphRec::DpchAppDo();
				((PnlWdbePphRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDATA) {
				req->dpchapp = new PnlWdbePplDetail::DpchAppData();
				((PnlWdbePplDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDO) {
				req->dpchapp = new PnlWdbePplDetail::DpchAppDo();
				((PnlWdbePplDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDO) {
				req->dpchapp = new CrdWdbePpl::DpchAppDo();
				((CrdWdbePpl::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLLISTDATA) {
				req->dpchapp = new PnlWdbePplList::DpchAppData();
				((PnlWdbePplList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLLISTDO) {
				req->dpchapp = new PnlWdbePplList::DpchAppDo();
				((PnlWdbePplList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLPPL1NSEGMENTDATA) {
				req->dpchapp = new PnlWdbePplPpl1NSegment::DpchAppData();
				((PnlWdbePplPpl1NSegment::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLPPL1NSEGMENTDO) {
				req->dpchapp = new PnlWdbePplPpl1NSegment::DpchAppDo();
				((PnlWdbePplPpl1NSegment::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLRECDO) {
				req->dpchapp = new PnlWdbePplRec::DpchAppDo();
				((PnlWdbePplRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDATA) {
				req->dpchapp = new PnlWdbePrcDetail::DpchAppData();
				((PnlWdbePrcDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDO) {
				req->dpchapp = new PnlWdbePrcDetail::DpchAppDo();
				((PnlWdbePrcDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDO) {
				req->dpchapp = new CrdWdbePrc::DpchAppDo();
				((CrdWdbePrc::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMFSM1NFSMSTATEDATA) {
				req->dpchapp = new PnlWdbePrcFsmFsm1NFsmstate::DpchAppData();
				((PnlWdbePrcFsmFsm1NFsmstate::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMFSM1NFSMSTATEDO) {
				req->dpchapp = new PnlWdbePrcFsmFsm1NFsmstate::DpchAppDo();
				((PnlWdbePrcFsmFsm1NFsmstate::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbePrcFsmHk1NVector::DpchAppData();
				((PnlWdbePrcFsmHk1NVector::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCFSMHK1NVECTORDO) {
				req->dpchapp = new PnlWdbePrcFsmHk1NVector::DpchAppDo();
				((PnlWdbePrcFsmHk1NVector::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCKHDLTYPEDATA) {
				req->dpchapp = new PnlWdbePrcKHdltype::DpchAppData();
				((PnlWdbePrcKHdltype::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCKHDLTYPEDO) {
				req->dpchapp = new PnlWdbePrcKHdltype::DpchAppDo();
				((PnlWdbePrcKHdltype::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCLISTDATA) {
				req->dpchapp = new PnlWdbePrcList::DpchAppData();
				((PnlWdbePrcList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCLISTDO) {
				req->dpchapp = new PnlWdbePrcList::DpchAppDo();
				((PnlWdbePrcList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCMGE1NSIGNALDATA) {
				req->dpchapp = new PnlWdbePrcMge1NSignal::DpchAppData();
				((PnlWdbePrcMge1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCMGE1NSIGNALDO) {
				req->dpchapp = new PnlWdbePrcMge1NSignal::DpchAppDo();
				((PnlWdbePrcMge1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCRECDO) {
				req->dpchapp = new PnlWdbePrcRec::DpchAppDo();
				((PnlWdbePrcRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbePrcRef1NSensitivity::DpchAppData();
				((PnlWdbePrcRef1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbePrcRef1NSensitivity::DpchAppDo();
				((PnlWdbePrcRef1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NVARIABLEDATA) {
				req->dpchapp = new PnlWdbePrcRef1NVariable::DpchAppData();
				((PnlWdbePrcRef1NVariable::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCREF1NVARIABLEDO) {
				req->dpchapp = new PnlWdbePrcRef1NVariable::DpchAppDo();
				((PnlWdbePrcRef1NVariable::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDETAILDATA) {
				req->dpchapp = new PnlWdbePrjDetail::DpchAppData();
				((PnlWdbePrjDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDETAILDO) {
				req->dpchapp = new PnlWdbePrjDetail::DpchAppDo();
				((PnlWdbePrjDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJDO) {
				req->dpchapp = new CrdWdbePrj::DpchAppDo();
				((CrdWdbePrj::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJLISTDATA) {
				req->dpchapp = new PnlWdbePrjList::DpchAppData();
				((PnlWdbePrjList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJLISTDO) {
				req->dpchapp = new PnlWdbePrjList::DpchAppDo();
				((PnlWdbePrjList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJMNPERSONDATA) {
				req->dpchapp = new PnlWdbePrjMNPerson::DpchAppData();
				((PnlWdbePrjMNPerson::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJMNPERSONDO) {
				req->dpchapp = new PnlWdbePrjMNPerson::DpchAppDo();
				((PnlWdbePrjMNPerson::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJPRJ1NVERSIONDATA) {
				req->dpchapp = new PnlWdbePrjPrj1NVersion::DpchAppData();
				((PnlWdbePrjPrj1NVersion::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJPRJ1NVERSIONDO) {
				req->dpchapp = new PnlWdbePrjPrj1NVersion::DpchAppDo();
				((PnlWdbePrjPrj1NVersion::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRJRECDO) {
				req->dpchapp = new PnlWdbePrjRec::DpchAppDo();
				((PnlWdbePrjRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSADETAILDATA) {
				req->dpchapp = new PnlWdbePrsADetail::DpchAppData();
				((PnlWdbePrsADetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSADETAILDO) {
				req->dpchapp = new PnlWdbePrsADetail::DpchAppDo();
				((PnlWdbePrsADetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDETAILDATA) {
				req->dpchapp = new PnlWdbePrsDetail::DpchAppData();
				((PnlWdbePrsDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDETAILDO) {
				req->dpchapp = new PnlWdbePrsDetail::DpchAppDo();
				((PnlWdbePrsDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSDO) {
				req->dpchapp = new CrdWdbePrs::DpchAppDo();
				((CrdWdbePrs::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSLISTDATA) {
				req->dpchapp = new PnlWdbePrsList::DpchAppData();
				((PnlWdbePrsList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSLISTDO) {
				req->dpchapp = new PnlWdbePrsList::DpchAppDo();
				((PnlWdbePrsList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNCOREPROJECTDATA) {
				req->dpchapp = new PnlWdbePrsMNCoreproject::DpchAppData();
				((PnlWdbePrsMNCoreproject::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNCOREPROJECTDO) {
				req->dpchapp = new PnlWdbePrsMNCoreproject::DpchAppDo();
				((PnlWdbePrsMNCoreproject::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNPROJECTDATA) {
				req->dpchapp = new PnlWdbePrsMNProject::DpchAppData();
				((PnlWdbePrsMNProject::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSMNPROJECTDO) {
				req->dpchapp = new PnlWdbePrsMNProject::DpchAppDo();
				((PnlWdbePrsMNProject::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRSRECDO) {
				req->dpchapp = new PnlWdbePrsRec::DpchAppDo();
				((PnlWdbePrsRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDATA) {
				req->dpchapp = new PnlWdbePrtDetail::DpchAppData();
				((PnlWdbePrtDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDO) {
				req->dpchapp = new PnlWdbePrtDetail::DpchAppDo();
				((PnlWdbePrtDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDO) {
				req->dpchapp = new CrdWdbePrt::DpchAppDo();
				((CrdWdbePrt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTLISTDATA) {
				req->dpchapp = new PnlWdbePrtList::DpchAppData();
				((PnlWdbePrtList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTLISTDO) {
				req->dpchapp = new PnlWdbePrtList::DpchAppDo();
				((PnlWdbePrtList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTRECDO) {
				req->dpchapp = new PnlWdbePrtRec::DpchAppDo();
				((PnlWdbePrtRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbePrtSrc1NSensitivity::DpchAppData();
				((PnlWdbePrtSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbePrtSrc1NSensitivity::DpchAppDo();
				((PnlWdbePrtSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERESUME) {
				req->dpchapp = new DpchAppWdbeResume();
				((DpchAppWdbeResume*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDETAILDATA) {
				req->dpchapp = new PnlWdbeRlsDetail::DpchAppData();
				((PnlWdbeRlsDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDETAILDO) {
				req->dpchapp = new PnlWdbeRlsDetail::DpchAppDo();
				((PnlWdbeRlsDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDO) {
				req->dpchapp = new CrdWdbeRls::DpchAppDo();
				((CrdWdbeRls::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSLISTDATA) {
				req->dpchapp = new PnlWdbeRlsList::DpchAppData();
				((PnlWdbeRlsList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSLISTDO) {
				req->dpchapp = new PnlWdbeRlsList::DpchAppDo();
				((PnlWdbeRlsList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSRECDO) {
				req->dpchapp = new PnlWdbeRlsRec::DpchAppDo();
				((PnlWdbeRlsRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDATA) {
				req->dpchapp = new PnlWdbeSegDetail::DpchAppData();
				((PnlWdbeSegDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDO) {
				req->dpchapp = new PnlWdbeSegDetail::DpchAppDo();
				((PnlWdbeSegDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDO) {
				req->dpchapp = new CrdWdbeSeg::DpchAppDo();
				((CrdWdbeSeg::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGLISTDATA) {
				req->dpchapp = new PnlWdbeSegList::DpchAppData();
				((PnlWdbeSegList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGLISTDO) {
				req->dpchapp = new PnlWdbeSegList::DpchAppDo();
				((PnlWdbeSegList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGRECDO) {
				req->dpchapp = new PnlWdbeSegRec::DpchAppDo();
				((PnlWdbeSegRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGSUP1NSEGMENTDATA) {
				req->dpchapp = new PnlWdbeSegSup1NSegment::DpchAppData();
				((PnlWdbeSegSup1NSegment::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGSUP1NSEGMENTDO) {
				req->dpchapp = new PnlWdbeSegSup1NSegment::DpchAppDo();
				((PnlWdbeSegSup1NSegment::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDATA) {
				req->dpchapp = new PnlWdbeSigDetail::DpchAppData();
				((PnlWdbeSigDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDO) {
				req->dpchapp = new PnlWdbeSigDetail::DpchAppDo();
				((PnlWdbeSigDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDO) {
				req->dpchapp = new CrdWdbeSig::DpchAppDo();
				((CrdWdbeSig::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGLISTDATA) {
				req->dpchapp = new PnlWdbeSigList::DpchAppData();
				((PnlWdbeSigList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGLISTDO) {
				req->dpchapp = new PnlWdbeSigList::DpchAppDo();
				((PnlWdbeSigList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGMNCDCDATA) {
				req->dpchapp = new PnlWdbeSigMNCdc::DpchAppData();
				((PnlWdbeSigMNCdc::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGMNCDCDO) {
				req->dpchapp = new PnlWdbeSigMNCdc::DpchAppDo();
				((PnlWdbeSigMNCdc::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGRECDO) {
				req->dpchapp = new PnlWdbeSigRec::DpchAppDo();
				((PnlWdbeSigRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGSRC1NSENSITIVITYDATA) {
				req->dpchapp = new PnlWdbeSigSrc1NSensitivity::DpchAppData();
				((PnlWdbeSigSrc1NSensitivity::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGSRC1NSENSITIVITYDO) {
				req->dpchapp = new PnlWdbeSigSrc1NSensitivity::DpchAppDo();
				((PnlWdbeSigSrc1NSensitivity::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NBANKDATA) {
				req->dpchapp = new PnlWdbeSil1NBank::DpchAppData();
				((PnlWdbeSil1NBank::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NBANKDO) {
				req->dpchapp = new PnlWdbeSil1NBank::DpchAppDo();
				((PnlWdbeSil1NBank::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NINTERRUPTDATA) {
				req->dpchapp = new PnlWdbeSil1NInterrupt::DpchAppData();
				((PnlWdbeSil1NInterrupt::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NINTERRUPTDO) {
				req->dpchapp = new PnlWdbeSil1NInterrupt::DpchAppDo();
				((PnlWdbeSil1NInterrupt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeSil1NPeripheral::DpchAppData();
				((PnlWdbeSil1NPeripheral::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NPERIPHERALDO) {
				req->dpchapp = new PnlWdbeSil1NPeripheral::DpchAppDo();
				((PnlWdbeSil1NPeripheral::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDATA) {
				req->dpchapp = new PnlWdbeSilDetail::DpchAppData();
				((PnlWdbeSilDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDO) {
				req->dpchapp = new PnlWdbeSilDetail::DpchAppDo();
				((PnlWdbeSilDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDO) {
				req->dpchapp = new CrdWdbeSil::DpchAppDo();
				((CrdWdbeSil::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeSilHk1NModule::DpchAppData();
				((PnlWdbeSilHk1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeSilHk1NModule::DpchAppDo();
				((PnlWdbeSilHk1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeSilHk1NVector::DpchAppData();
				((PnlWdbeSilHk1NVector::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeSilHk1NVector::DpchAppDo();
				((PnlWdbeSilHk1NVector::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILLISTDATA) {
				req->dpchapp = new PnlWdbeSilList::DpchAppData();
				((PnlWdbeSilList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILLISTDO) {
				req->dpchapp = new PnlWdbeSilList::DpchAppDo();
				((PnlWdbeSilList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILRECDO) {
				req->dpchapp = new PnlWdbeSilRec::DpchAppDo();
				((PnlWdbeSilRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeSilRef1NCommand::DpchAppData();
				((PnlWdbeSilRef1NCommand::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeSilRef1NCommand::DpchAppDo();
				((PnlWdbeSilRef1NCommand::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeSilRef1NError::DpchAppData();
				((PnlWdbeSilRef1NError::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NERRORDO) {
				req->dpchapp = new PnlWdbeSilRef1NError::DpchAppDo();
				((PnlWdbeSilRef1NError::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeSilRef1NSignal::DpchAppData();
				((PnlWdbeSilRef1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeSilRef1NSignal::DpchAppDo();
				((PnlWdbeSilRef1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILSIL1NUNITDATA) {
				req->dpchapp = new PnlWdbeSilSil1NUnit::DpchAppData();
				((PnlWdbeSilSil1NUnit::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILSIL1NUNITDO) {
				req->dpchapp = new PnlWdbeSilSil1NUnit::DpchAppDo();
				((PnlWdbeSilSil1NUnit::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDATA) {
				req->dpchapp = new PnlWdbeSnsDetail::DpchAppData();
				((PnlWdbeSnsDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDO) {
				req->dpchapp = new PnlWdbeSnsDetail::DpchAppDo();
				((PnlWdbeSnsDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDO) {
				req->dpchapp = new CrdWdbeSns::DpchAppDo();
				((CrdWdbeSns::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSLISTDATA) {
				req->dpchapp = new PnlWdbeSnsList::DpchAppData();
				((PnlWdbeSnsList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSLISTDO) {
				req->dpchapp = new PnlWdbeSnsList::DpchAppDo();
				((PnlWdbeSnsList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSRECDO) {
				req->dpchapp = new PnlWdbeSnsRec::DpchAppDo();
				((PnlWdbeSnsRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NBANKDATA) {
				req->dpchapp = new PnlWdbeUnt1NBank::DpchAppData();
				((PnlWdbeUnt1NBank::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NBANKDO) {
				req->dpchapp = new PnlWdbeUnt1NBank::DpchAppDo();
				((PnlWdbeUnt1NBank::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NINTERRUPTDATA) {
				req->dpchapp = new PnlWdbeUnt1NInterrupt::DpchAppData();
				((PnlWdbeUnt1NInterrupt::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NINTERRUPTDO) {
				req->dpchapp = new PnlWdbeUnt1NInterrupt::DpchAppDo();
				((PnlWdbeUnt1NInterrupt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NPERIPHERALDATA) {
				req->dpchapp = new PnlWdbeUnt1NPeripheral::DpchAppData();
				((PnlWdbeUnt1NPeripheral::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNT1NPERIPHERALDO) {
				req->dpchapp = new PnlWdbeUnt1NPeripheral::DpchAppDo();
				((PnlWdbeUnt1NPeripheral::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDETAILDATA) {
				req->dpchapp = new PnlWdbeUntDetail::DpchAppData();
				((PnlWdbeUntDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDETAILDO) {
				req->dpchapp = new PnlWdbeUntDetail::DpchAppDo();
				((PnlWdbeUntDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDO) {
				req->dpchapp = new CrdWdbeUnt::DpchAppDo();
				((CrdWdbeUnt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NMODULEDATA) {
				req->dpchapp = new PnlWdbeUntHk1NModule::DpchAppData();
				((PnlWdbeUntHk1NModule::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NMODULEDO) {
				req->dpchapp = new PnlWdbeUntHk1NModule::DpchAppDo();
				((PnlWdbeUntHk1NModule::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NVECTORDATA) {
				req->dpchapp = new PnlWdbeUntHk1NVector::DpchAppData();
				((PnlWdbeUntHk1NVector::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTHK1NVECTORDO) {
				req->dpchapp = new PnlWdbeUntHk1NVector::DpchAppDo();
				((PnlWdbeUntHk1NVector::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTLISTDATA) {
				req->dpchapp = new PnlWdbeUntList::DpchAppData();
				((PnlWdbeUntList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTLISTDO) {
				req->dpchapp = new PnlWdbeUntList::DpchAppDo();
				((PnlWdbeUntList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTRECDO) {
				req->dpchapp = new PnlWdbeUntRec::DpchAppDo();
				((PnlWdbeUntRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NCOMMANDDATA) {
				req->dpchapp = new PnlWdbeUntRef1NCommand::DpchAppData();
				((PnlWdbeUntRef1NCommand::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NCOMMANDDO) {
				req->dpchapp = new PnlWdbeUntRef1NCommand::DpchAppDo();
				((PnlWdbeUntRef1NCommand::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NERRORDATA) {
				req->dpchapp = new PnlWdbeUntRef1NError::DpchAppData();
				((PnlWdbeUntRef1NError::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NERRORDO) {
				req->dpchapp = new PnlWdbeUntRef1NError::DpchAppDo();
				((PnlWdbeUntRef1NError::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NSIGNALDATA) {
				req->dpchapp = new PnlWdbeUntRef1NSignal::DpchAppData();
				((PnlWdbeUntRef1NSignal::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTREF1NSIGNALDO) {
				req->dpchapp = new PnlWdbeUntRef1NSignal::DpchAppDo();
				((PnlWdbeUntRef1NSignal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTSIL1NUNITDATA) {
				req->dpchapp = new PnlWdbeUntSil1NUnit::DpchAppData();
				((PnlWdbeUntSil1NUnit::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTSIL1NUNITDO) {
				req->dpchapp = new PnlWdbeUntSil1NUnit::DpchAppDo();
				((PnlWdbeUntSil1NUnit::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGAACCESSDATA) {
				req->dpchapp = new PnlWdbeUsgAAccess::DpchAppData();
				((PnlWdbeUsgAAccess::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGAACCESSDO) {
				req->dpchapp = new PnlWdbeUsgAAccess::DpchAppDo();
				((PnlWdbeUsgAAccess::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDETAILDATA) {
				req->dpchapp = new PnlWdbeUsgDetail::DpchAppData();
				((PnlWdbeUsgDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDETAILDO) {
				req->dpchapp = new PnlWdbeUsgDetail::DpchAppDo();
				((PnlWdbeUsgDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGDO) {
				req->dpchapp = new CrdWdbeUsg::DpchAppDo();
				((CrdWdbeUsg::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGLISTDATA) {
				req->dpchapp = new PnlWdbeUsgList::DpchAppData();
				((PnlWdbeUsgList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGLISTDO) {
				req->dpchapp = new PnlWdbeUsgList::DpchAppDo();
				((PnlWdbeUsgList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGMNUSERDATA) {
				req->dpchapp = new PnlWdbeUsgMNUser::DpchAppData();
				((PnlWdbeUsgMNUser::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGMNUSERDO) {
				req->dpchapp = new PnlWdbeUsgMNUser::DpchAppDo();
				((PnlWdbeUsgMNUser::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSGRECDO) {
				req->dpchapp = new PnlWdbeUsgRec::DpchAppDo();
				((PnlWdbeUsgRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSR1NSESSIONDATA) {
				req->dpchapp = new PnlWdbeUsr1NSession::DpchAppData();
				((PnlWdbeUsr1NSession::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSR1NSESSIONDO) {
				req->dpchapp = new PnlWdbeUsr1NSession::DpchAppDo();
				((PnlWdbeUsr1NSession::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRAACCESSDATA) {
				req->dpchapp = new PnlWdbeUsrAAccess::DpchAppData();
				((PnlWdbeUsrAAccess::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRAACCESSDO) {
				req->dpchapp = new PnlWdbeUsrAAccess::DpchAppDo();
				((PnlWdbeUsrAAccess::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDETAILDATA) {
				req->dpchapp = new PnlWdbeUsrDetail::DpchAppData();
				((PnlWdbeUsrDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDETAILDO) {
				req->dpchapp = new PnlWdbeUsrDetail::DpchAppDo();
				((PnlWdbeUsrDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRDO) {
				req->dpchapp = new CrdWdbeUsr::DpchAppDo();
				((CrdWdbeUsr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRLISTDATA) {
				req->dpchapp = new PnlWdbeUsrList::DpchAppData();
				((PnlWdbeUsrList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRLISTDO) {
				req->dpchapp = new PnlWdbeUsrList::DpchAppDo();
				((PnlWdbeUsrList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRMNUSERGROUPDATA) {
				req->dpchapp = new PnlWdbeUsrMNUsergroup::DpchAppData();
				((PnlWdbeUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRMNUSERGROUPDO) {
				req->dpchapp = new PnlWdbeUsrMNUsergroup::DpchAppDo();
				((PnlWdbeUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRRECDO) {
				req->dpchapp = new PnlWdbeUsrRec::DpchAppDo();
				((PnlWdbeUsrRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUTLDO) {
				req->dpchapp = new CrdWdbeUtl::DpchAppDo();
				((CrdWdbeUtl::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDATA) {
				req->dpchapp = new PnlWdbeVarDetail::DpchAppData();
				((PnlWdbeVarDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDO) {
				req->dpchapp = new PnlWdbeVarDetail::DpchAppDo();
				((PnlWdbeVarDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDO) {
				req->dpchapp = new CrdWdbeVar::DpchAppDo();
				((CrdWdbeVar::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARLISTDATA) {
				req->dpchapp = new PnlWdbeVarList::DpchAppData();
				((PnlWdbeVarList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARLISTDO) {
				req->dpchapp = new PnlWdbeVarList::DpchAppDo();
				((PnlWdbeVarList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARRECDO) {
				req->dpchapp = new PnlWdbeVarRec::DpchAppDo();
				((PnlWdbeVarRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDATA) {
				req->dpchapp = new PnlWdbeVecDetail::DpchAppData();
				((PnlWdbeVecDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDO) {
				req->dpchapp = new PnlWdbeVecDetail::DpchAppDo();
				((PnlWdbeVecDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDO) {
				req->dpchapp = new CrdWdbeVec::DpchAppDo();
				((CrdWdbeVec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECLISTDATA) {
				req->dpchapp = new PnlWdbeVecList::DpchAppData();
				((PnlWdbeVecList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECLISTDO) {
				req->dpchapp = new PnlWdbeVecList::DpchAppDo();
				((PnlWdbeVecList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECRECDO) {
				req->dpchapp = new PnlWdbeVecRec::DpchAppDo();
				((PnlWdbeVecRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECVEC1NVECTORITEMDATA) {
				req->dpchapp = new PnlWdbeVecVec1NVectoritem::DpchAppData();
				((PnlWdbeVecVec1NVectoritem::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECVEC1NVECTORITEMDO) {
				req->dpchapp = new PnlWdbeVecVec1NVectoritem::DpchAppDo();
				((PnlWdbeVecVec1NVectoritem::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NCOMPONENTDATA) {
				req->dpchapp = new PnlWdbeVer1NComponent::DpchAppData();
				((PnlWdbeVer1NComponent::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NCOMPONENTDO) {
				req->dpchapp = new PnlWdbeVer1NComponent::DpchAppDo();
				((PnlWdbeVer1NComponent::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NUNITDATA) {
				req->dpchapp = new PnlWdbeVer1NUnit::DpchAppData();
				((PnlWdbeVer1NUnit::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVER1NUNITDO) {
				req->dpchapp = new PnlWdbeVer1NUnit::DpchAppDo();
				((PnlWdbeVer1NUnit::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERBVR1NVERSIONDATA) {
				req->dpchapp = new PnlWdbeVerBvr1NVersion::DpchAppData();
				((PnlWdbeVerBvr1NVersion::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERBVR1NVERSIONDO) {
				req->dpchapp = new PnlWdbeVerBvr1NVersion::DpchAppDo();
				((PnlWdbeVerBvr1NVersion::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDATA) {
				req->dpchapp = new PnlWdbeVerDetail::DpchAppData();
				((PnlWdbeVerDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDO) {
				req->dpchapp = new PnlWdbeVerDetail::DpchAppDo();
				((PnlWdbeVerDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDO) {
				req->dpchapp = new CrdWdbeVer::DpchAppDo();
				((CrdWdbeVer::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERLISTDATA) {
				req->dpchapp = new PnlWdbeVerList::DpchAppData();
				((PnlWdbeVerList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERLISTDO) {
				req->dpchapp = new PnlWdbeVerList::DpchAppDo();
				((PnlWdbeVerList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERRECDO) {
				req->dpchapp = new PnlWdbeVerRec::DpchAppDo();
				((PnlWdbeVerRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERREF1NFILEDATA) {
				req->dpchapp = new PnlWdbeVerRef1NFile::DpchAppData();
				((PnlWdbeVerRef1NFile::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERREF1NFILEDO) {
				req->dpchapp = new PnlWdbeVerRef1NFile::DpchAppDo();
				((PnlWdbeVerRef1NFile::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDETAILDATA) {
				req->dpchapp = new PnlWdbeVitDetail::DpchAppData();
				((PnlWdbeVitDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDETAILDO) {
				req->dpchapp = new PnlWdbeVitDetail::DpchAppDo();
				((PnlWdbeVitDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITDO) {
				req->dpchapp = new CrdWdbeVit::DpchAppDo();
				((CrdWdbeVit::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITLISTDATA) {
				req->dpchapp = new PnlWdbeVitList::DpchAppData();
				((PnlWdbeVitList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITLISTDO) {
				req->dpchapp = new PnlWdbeVitList::DpchAppDo();
				((PnlWdbeVitList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVITRECDO) {
				req->dpchapp = new PnlWdbeVitRec::DpchAppDo();
				((PnlWdbeVitRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			};
		} catch (exception& e) {
		};
	};

	return ixWdbeVDpch;
};

void WdbedAppsrv::writeDpchEng(
			XchgWdbed* xchg
			, ReqWdbe* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	Json::Value root;
	ostringstream str;

	if (!req->jsonNotXml) {
		startwriteBuffer(&wr, &buf);

		if (req->dpcheng) {
			req->dpcheng->writeXML(req->ixWdbeVLocale, wr);
		} else {
			DpchEngWdbeConfirm dpchconfirm(false, req->jref, "");
			dpchconfirm.writeXML(req->ixWdbeVLocale, wr);
		};

		closewriteBuffer(wr);

		req->replylen = buf->use;
		req->reply = new char[req->replylen];
		memcpy(req->reply, buf->content, req->replylen);

		xmlBufferFree(buf);

	} else {
		if (req->dpcheng) {
			req->dpcheng->writeJSON(req->ixWdbeVLocale, root);
		} else {
			DpchEngWdbeConfirm dpchconfirm(false, req->jref, "");
			dpchconfirm.writeJSON(req->ixWdbeVLocale, root);
		};

		str << root;
		// cout << root << endl;

		req->replylen = str.str().length();
		req->reply = new char[req->replylen];
		memcpy(req->reply, str.str().c_str(), req->replylen);
	};
};
