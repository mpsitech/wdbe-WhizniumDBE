/**
	* \file WdbeMtpWrfpgaI2cmaster_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaI2cmaster_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaI2cmaster_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaI2cmaster_v1_0::run(
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

		// xxxx/I2c_v1_0.vhd
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
void WdbeMtpWrfpgaI2cmaster_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	bool threeNotInout;

	string s;

	Wdbe::getMpa(dbswdbe, mdl->ref, "threeNotInout", s);
	threeNotInout = (s == "true");

	// --- sigs.inout*
	if (!threeNotInout) outfile << "-- IP sigs.inout --- AFFIRM" << endl;
	else outfile << "-- IP sigs.inout --- REMOVE" << endl;

	// --- impl.wiring.inout*
	if (!threeNotInout) outfile << "-- IP impl.wiring.inout --- AFFIRM" << endl;
	else outfile << "-- IP impl.wiring.inout --- REMOVE" << endl;

	// --- impl.wiring.three*
	if (threeNotInout) outfile << "-- IP impl.wiring.three --- AFFIRM" << endl;
	else outfile << "-- IP impl.wiring.three --- REMOVE" << endl;
};
// IP cust --- IEND
