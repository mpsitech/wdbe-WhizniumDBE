/**
	* \file WdbeopdEngsrv.h
	* engine server for Wdbe operation daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEOPDENGSRV_H
#define WDBEOPDENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "WdbeMtpWrmcu_blks.h"
#include "WdbeMtpWrfpga_blks.h"
#include "WdbeMtpModdet_blks.h"
#include "WdbeMtpModbsctd_blks.h"
#include "WdbeMtpModbscbu_blks.h"
#include "WdbeMtpPlhmcu_blks.h"
#include "WdbeMtpPlhfpga_blks.h"

/**
	* WdbeopdEngsrv
	*/
namespace WdbeopdEngsrv {
	MHD_Daemon* start(XchgWdbeopd* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpchInv(ReqopWdbe* req);
	void writeDpchAck(ReqopWdbe* req);
	void writeDpchRet(ReqopWdbe* req);
};

#endif

