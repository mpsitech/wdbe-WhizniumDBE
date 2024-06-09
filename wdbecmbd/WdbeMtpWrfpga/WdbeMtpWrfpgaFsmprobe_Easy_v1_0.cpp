/**
	* \file WdbeMtpWrfpgaFsmprobe_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaFsmprobe_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaFsmprobe_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaFsmprobe_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Fsmprobe.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeMtpWrfpgaFsmprobe_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	WdbeMFsm* fsm = NULL;

	string capts; // ex. tkclksrc.op;camif.stream

	vector<string> ss, ss2;

	bool first;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "capts", capts)) StrMod::stringToVector(capts, ss, ';');

	// --- impl.op.state
	outfile << "-- IP impl.op.state --- IBEGIN" << endl;

	outfile << "\tstate <=";

	first = true;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() == 2) {
			if (first) first = false;
			else outfile << "\t\t\t\telse";

			outfile << " " << ss2[0] << "State" << StrMod::cap(ss2[1]) << " when tixVSource=tixVSource" << StrMod::cap(ss2[0]) << StrMod::cap(ss2[1]) << endl;
		};
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " (others => '1');" << endl;

	outfile << "-- IP impl.op.state --- IEND" << endl;

	// --- impl.op.bcdNotHex
	outfile << "-- IP impl.op.bcdNotHex --- IBEGIN" << endl;

	outfile << "\tbcdNotHex <=";

	first = true;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() == 2) {
			if (dbswdbe->tblwdbemfsm->loadRecBySQL("SELECT TblWdbeMFsm.* FROM TblWdbeMModule, TblWdbeMProcess, TblWdbeMFsm WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
						+ " AND TblWdbeMModule.hkUref = " + to_string(mdl->hkUref) + " AND TblWdbeMModule.sref = '" + ss2[0] + "' AND TblWdbeMProcess.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMProcess.sref = '"
						+ ss2[1] + "' AND TblWdbeMFsm.refWdbeMProcess = TblWdbeMProcess.ref", &fsm)) {
				if (fsm->ixVDbgtaptype == VecWdbeVMFsmDbgtaptype::LIN) {
					if (first) {
						outfile << " '0' when";
						first = false;
					} else outfile << " or";
					outfile << " tixVSource=tixVSource" << StrMod::cap(ss2[0]) << StrMod::cap(ss2[1]);
				};

				delete fsm;
			};
		};
	};

	if (!first) {
		outfile << endl;
		outfile << "\t\t\t\telse";
	};
	outfile << " '1'" << endl;

	outfile << "-- IP impl.op.bcdNotHex --- IEND" << endl;
};
// IP cust --- IEND
