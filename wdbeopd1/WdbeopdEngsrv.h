/**
	* \file WdbeopdEngsrv.h
	* engine server for Wdbe operation daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEOPDENGSRV_H
#define WDBEOPDENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "WdbeCplmst_blks.h"
#include "WdbeGen_blks.h"
#include "WdbeGenfst_blks.h"
#include "WdbePlhfpga_blks.h"
#include "WdbePlhmcu_blks.h"
#include "WdbePrcfile_blks.h"
#include "WdbePrctree_blks.h"
#include "WdbeWrdev_blks.h"
#include "WdbeWrfpga_blks.h"
#include "WdbeWrmcu_blks.h"

/**
	* WdbeopdEngsrv
	*/
namespace WdbeopdEngsrv {
	MHD_Daemon* start(XchgWdbeopd* xchg);
	void stop(MHD_Daemon* d);

	MHD_Result MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	MHD_Result MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	MHD_Result MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpchInv(ReqopWdbe* req);
	void writeDpchAck(ReqopWdbe* req);
	void writeDpchRet(ReqopWdbe* req);
};

#endif
