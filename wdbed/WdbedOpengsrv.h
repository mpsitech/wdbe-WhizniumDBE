/**
	* \file WdbedOpengsrv.h
	* op engine server for Wdbe daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEDOPENGSRV_H
#define WDBEDOPENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
	* WdbedOpengsrv
	*/
namespace WdbedOpengsrv {
	MHD_Daemon* start(XchgWdbe* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpch(XchgWdbed* xchg, ReqopengconWdbe* req);
	void writeDpchAck(ReqopengconWdbe* req);
	void writeDpchReg(XchgWdbed* xchg, ReqopengconWdbe* req, const Sbecore::ubigint nref);
};

#endif

