/**
	* \file WdbeMtpCplmstbuGpio_Easy_v1_0.cpp
	* Wdbe operation processor - adapt port widths and commands (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Jun 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuGpio_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
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
		// - ports
		if (!threeNotInout && bidirNotUnidir) {
			refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_in'", refC);
			if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits", w);

		} else {
			dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits'");

			if (!bidirNotUnidir && !inNotOut) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_in'");
			else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_in", w);

			if (!bidirNotUnidir && inNotOut) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_out'");
			else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_out", w);

			if (!bidirNotUnidir) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_tri'");
			else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_tri", w);
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
