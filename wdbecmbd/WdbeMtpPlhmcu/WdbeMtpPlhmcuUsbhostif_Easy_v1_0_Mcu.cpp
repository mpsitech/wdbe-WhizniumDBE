/**
	* \file WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu
 ******************************************************************************/

DpchRetWdbeMtpPlhmcu* WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhmcu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// sizeBuf

	WdbeMModule* mdl = NULL;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;

	unsigned int sizeRxbuf, sizeTxbuf, len, len2;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Wdbe::getHostifSizeRxtxbuf(dbswdbe, mdl->hkUref, sizeRxbuf, sizeTxbuf);
		len = sizeRxbuf;
		if (sizeTxbuf > sizeRxbuf) len = sizeTxbuf;

		dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT TblWdbeMImbuf.* FROM TblWdbeMImbuf, TblWdbeRMModuleMModule WHERE TblWdbeRMModuleMModule.corRefWdbeMModule = " + to_string(refWdbeMModule) 
					+ " AND TblWdbeMImbuf.refWdbeMModule = TblWdbeRMModuleMModule.ctdRefWdbeMModule", false, imbs);

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			len2 = Wdbe::getMinmaxMax(imb->Minmax) + 2;
			if (len2 > len) len = len2;
		};

		keys.push_back("sizeBuf");
		vals.push_back(to_string(len));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhmcu("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
