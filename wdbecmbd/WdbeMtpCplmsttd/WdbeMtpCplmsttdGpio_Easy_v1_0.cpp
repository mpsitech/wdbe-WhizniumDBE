/**
	* \file WdbeMtpCplmsttdGpio_Easy_v1_0.cpp
	* Wdbe operation processor - infer tristate primitives and adapt commands (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 23 Nov 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdGpio_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string s;

	unsigned int w = 32;
	bool threeNotInout = false;
	bool bidirNotUnidir = false;
	bool inNotOut = false;

	bool cmdConfig, cmdGet, cmdSet;
	uint ixWdbeVPartype = VecWdbeVPartype::UINT32;

	string srefKVendor;

	string srefTplIobuf;
	ubigint refMtp = 0;

	ubigint ref, refC;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "threeNotInout", s)) threeNotInout = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "bidirNotUnidir", s)) bidirNotUnidir = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "inNotOut", s)) inNotOut = (s == "true");

	cmdConfig = bidirNotUnidir;
	cmdGet = !(!bidirNotUnidir && !inNotOut);
	cmdSet = !(!bidirNotUnidir && inNotOut);

	if (w == 8) ixWdbeVPartype = VecWdbeVPartype::UINT8;
	else if (w == 16) ixWdbeVPartype = VecWdbeVPartype::UINT16;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (!threeNotInout && bidirNotUnidir) {
			srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

			if (srefKVendor == "lttc") srefTplIobuf = "BB";
			else if (srefKVendor == "mchp") srefTplIobuf = "BIBUF";
			else if (srefKVendor == "xlnx") srefTplIobuf = "IOBUF";

			refMtp = Wdbe::getRefMtp(dbswdbe, srefTplIobuf);
		};

		// - sub-modules
		if (refMtp) {
			dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + " + to_string(w) + " WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
			for (unsigned int i = 0; i < w; i++) dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1+i, refWdbeMModule, refMtp, 0, 0, StrMod::lc(srefTplIobuf) + to_string(i), "", "", "");
		};

		// - commands
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'config'", ref)) {
			if (cmdConfig) {
				dbswdbe->executeQuery("UPDATE TblWdbeAMCommandInvpar SET ixWdbeVPartype = " + to_string(ixWdbeVPartype) + " WHERE cmdRefWdbeMCommand = " + to_string(ref) + " AND sref = 'outmask'");

			} else {
				dbswdbe->executeQuery("DELETE FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(ref));
				dbswdbe->tblwdbemcommand->removeRecByRef(ref);
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'get'", ref)) {
			if (cmdGet) {
				dbswdbe->executeQuery("UPDATE TblWdbeAMCommandRetpar SET ixWdbeVPartype = " + to_string(ixWdbeVPartype) + " WHERE cmdRefWdbeMCommand = " + to_string(ref) + " AND sref = 'bits'");

			} else {
				dbswdbe->executeQuery("DELETE FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(ref));
				dbswdbe->tblwdbemcommand->removeRecByRef(ref);
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'set'", ref)) {
			if (cmdSet) {
				dbswdbe->executeQuery("UPDATE TblWdbeAMCommandInvpar SET ixWdbeVPartype = " + to_string(ixWdbeVPartype) + " WHERE cmdRefWdbeMCommand = " + to_string(ref) + " AND sref = 'mask'");
				dbswdbe->executeQuery("UPDATE TblWdbeAMCommandInvpar SET ixWdbeVPartype = " + to_string(ixWdbeVPartype) + " WHERE cmdRefWdbeMCommand = " + to_string(ref) + " AND sref = 'bits'");

			} else {
				dbswdbe->executeQuery("DELETE FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(ref));
				dbswdbe->tblwdbemcommand->removeRecByRef(ref);
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
