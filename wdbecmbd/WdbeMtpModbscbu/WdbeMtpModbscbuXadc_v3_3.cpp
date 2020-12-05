/**
	* \file WdbeMtpModbscbuXadc_v3_3.cpp
	* Wdbe operation processor - add analog input ports (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuXadc_v3_3.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuXadc_v3_3
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuXadc_v3_3::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string Naux, aux;

	ubigint refC;
	uint mdlNum;

	vector<string> ss;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "Naux", Naux) && Wdbe::getMpa(dbswdbe, refWdbeMModule, "aux", aux)) {
		StrMod::stringToVector(aux, ss);

		if (ss.size() == atoi(Naux.c_str())) {
			dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule), mdlNum);
			mdlNum++;

			for (unsigned int i = 0; i < ss.size(); i++) {
				refC = dbswdbe->tblwdbecport->getNewRef();

				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTEPIN, "vauxn" + ss[i], VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTEPIN, "vauxp" + ss[i], VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



