/**
	* \file WdbecmbdAppsrv.h
	* application server for Wdbe combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBECMBDAPPSRV_H
#define WDBECMBDAPPSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "RootWdbe.h"

/**
	* WdbecmbdAppsrv
	*/
namespace WdbecmbdAppsrv {
	MHD_Daemon* start(XchgWdbecmbd* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
#ifdef _WIN32
	int MhdFilesend(void* con_cls, uint64_t pos, char* buf, int max);
#else
	ssize_t MhdFilesend(void* con_cls, uint64_t pos, char* buf, size_t max);
#endif
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	bool validateIp(XchgWdbecmbd* xchg, ReqWdbe* req);
	bool validateJrefNotify(XchgWdbecmbd* xchg, ReqWdbe* req);
	Sbecore::uint readDpchApp(XchgWdbecmbd* xchg, ReqWdbe* req);
	void writeDpchEng(XchgWdbecmbd* xchg, ReqWdbe* req);
};

#endif
