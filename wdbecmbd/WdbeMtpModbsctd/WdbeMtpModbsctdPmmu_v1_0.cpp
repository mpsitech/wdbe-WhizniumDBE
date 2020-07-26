/**
	* \file WdbeMtpModbsctdPmmu_v1_0.cpp
	* Wdbe operation processor - adapt buffer sizes (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbsctdPmmu_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbsctd;

/******************************************************************************
 namespace WdbeMtpModbsctdPmmu_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbsctdPmmu_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbsctd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	string size;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizePg", size)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'inbuf0'", ref))
			Wdbe::setMpa(dbswdbe, ref, "size", to_string(2*atoi(size.c_str())));

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'outbuf0'", ref))
			Wdbe::setMpa(dbswdbe, ref, "size", to_string(2*atoi(size.c_str())));
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeTocbuf", size))
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'tocbuf'", ref))
			Wdbe::setMpa(dbswdbe, ref, "size", size);
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


