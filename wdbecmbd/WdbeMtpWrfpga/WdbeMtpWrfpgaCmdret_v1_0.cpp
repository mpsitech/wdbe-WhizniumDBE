/**
	* \file WdbeMtpWrfpgaCmdret_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaCmdret_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaCmdret_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCmdret_v1_0::run(
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

		// xxxx/Cmdret.vhd
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
void WdbeMtpWrfpgaCmdret_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	WdbeMModule* top = NULL;

	WdbeMModule* cmdbus = NULL;
	string Cmdbussref;

	WdbeMModule* cmdret = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	set<string> srefsCtrs;

	unsigned int cnt;

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::TOP), &top)) {
		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDBUS), &cmdbus)) {
			Cmdbussref = StrMod::cap(cmdbus->sref);

			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDRET), &cmdret)) {

				dbswdbe->tblwdbemvectoritem->loadRstBySQL("SELECT TblWdbeMVectoritem.* FROM TblWdbeMSignal, TblWdbeMVectoritem WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(top->ref) + " AND TblWdbeMSignal.sref = 'req"
							+ Cmdbussref + "' AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMSignal.refWdbeMVector AND TblWdbeMVectoritem.sref LIKE '%To" + StrMod::cap(cmdret->sref) + "' ORDER BY TblWdbeMVectoritem.vecNum ASC", false, vits);

				for (unsigned int i = 0; i < vits.nodes.size(); i++) {
					vit = vits.nodes[i];
					srefsCtrs.insert(vit->sref.substr(0, vit->sref.length()-cmdret->sref.length()-2));
				};

				delete cmdret;
			};
			delete cmdbus;
		};
		delete top;
	};

	// --- impl.buf.rdy
	outfile << "-- IP impl.buf.rdy --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\trdy" << Cmdbussref << "From" << StrMod::cap(*it) << " <= rdy" << Cmdbussref << "FromAny;" << endl;
	};
	outfile << "-- IP impl.buf.rdy --- IEND" << endl;

	// --- impl.buf.rd
	outfile << "-- IP impl.buf.rd --- IBEGIN" << endl;
	if (!srefsCtrs.empty()) {
		cnt = 0;

		outfile << "\trd" << Cmdbussref << "FromAny <= '1' when (";
		for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
			if (it != srefsCtrs.begin()) {
				if ((cnt%5) == 0) outfile << endl << "\t\t\t\tor ";
				else outfile << " or ";
			};

			outfile << "rd" << Cmdbussref << "From" << StrMod::cap(*it) << "='1'";

			cnt++;
		};
		outfile << ") else '0';" << endl;
	};
	outfile << "-- IP impl.buf.rd --- IEND" << endl;
};
// IP cust --- IEND
