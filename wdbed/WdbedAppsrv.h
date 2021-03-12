/**
	* \file WdbedAppsrv.h
	* application server for Wdbe daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEDAPPSRV_H
#define WDBEDAPPSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "RootWdbe.h"

/**
	* WdbedAppsrv
	*/
namespace WdbedAppsrv {
	constexpr const char* empty = "\n";
	constexpr const char* invalid = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	MHD_Daemon* start(XchgWdbed* xchg);
	void stop(MHD_Daemon* d);

	MHD_Result MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	MHD_Result MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
#ifdef _WIN32
	int MhdFilesend(void* con_cls, uint64_t pos, char* buf, int max);
#else
	ssize_t MhdFilesend(void* con_cls, uint64_t pos, char* buf, size_t max);
#endif
	MHD_Result MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	bool validateIp(XchgWdbed* xchg, ReqWdbe* req);
	bool validateJrefNotify(XchgWdbed* xchg, ReqWdbe* req);
	Sbecore::uint readDpchApp(XchgWdbed* xchg, ReqWdbe* req);
	void writeDpchEng(XchgWdbed* xchg, ReqWdbe* req);
};

#endif
