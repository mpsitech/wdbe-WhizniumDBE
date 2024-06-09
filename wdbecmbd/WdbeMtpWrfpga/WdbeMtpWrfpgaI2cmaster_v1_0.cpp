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
	ubigint refBb, refBibuf, refIobuf;

	refBb = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'bbSda'", refBb);
	refBibuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'bibufSda'", refBibuf);
	refIobuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'iobufSda'", refIobuf);

	// --- sigs.sdan_sig*
	if (refBibuf) outfile << "-- IP sigs.sdan_sig --- AFFIRM" << endl;
	else outfile << "-- IP sigs.sdan_sig --- REMOVE" << endl;

	// --- sigs.sda_in*
	if (refBb + refBibuf + refIobuf) outfile << "-- IP sigs.sda_in --- AFFIRM" << endl;
	else outfile << "-- IP sigs.sda_in --- REMOVE" << endl;

	// --- impl.wiring.inoutdir*
	if ((refBb + refBibuf + refIobuf) == 0) outfile << "-- IP impl.wiring.inoutdir --- AFFIRM" << endl;
	else outfile << "-- IP impl.wiring.inoutdir --- REMOVE" << endl;

	// --- impl.wiring.bufTri*
	if (refBibuf) outfile << "-- IP impl.wiring.bufTri --- AFFIRM" << endl;
	else outfile << "-- IP impl.wiring.bufTri --- REMOVE" << endl;
};
// IP cust --- IEND
