/**
	* \file WdbeMtpWrfpgaGpio_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaGpio_Easy_v1_0::run(
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

		// xxxx/Gpio.vhd
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
void WdbeMtpWrfpgaGpio_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	bool bidirNotUnidir = false;
	bool inNotOut = false;

	bool cmdConfig, cmdGet, cmdSet;

	string s;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "bidirNotUnidir", s)) bidirNotUnidir = (s == "true");
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "inNotOut", s)) inNotOut = (s == "true");

	cmdConfig = bidirNotUnidir;
	cmdGet = !(!bidirNotUnidir && !inNotOut);
	cmdSet = !(!bidirNotUnidir && inNotOut);

	if (cmdConfig) {
		// --- impl.op.init.invConfig
		outfile << "-- IP impl.op.init.invConfig --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tbitsDir_sig <= (bitsDir_sig and not configMask) or (configMask and configOutNotIn);" << endl;
		outfile << "\t\t\t\t\tackInvConfig_sig <= '1';" << endl;
		if (cmdSet) outfile << "\t\t\t\t\tackInvSet_sig <= '0';" << endl;
		outfile << "-- IP impl.op.init.invConfig --- IEND" << endl;
	};

	if (cmdSet) {
		// --- impl.op.init.invSet
		outfile << "-- IP impl.op.init.invSet --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tbitsOut_sig <= (bitsOut_sig and not setMask) or (setMask and setBits);" << endl;
		if (cmdConfig) outfile << "\t\t\t\t\tackInvConfig_sig <= '0';" << endl;
		outfile << "\t\t\t\t\tackInvSet_sig <= '1';" << endl;
		outfile << "-- IP impl.op.init.invSet --- IEND" << endl;
	};

	if (cmdConfig || cmdSet) {
		// --- impl.op.inv
		outfile << "-- IP impl.op.inv --- IBEGIN" << endl;
		if (cmdConfig) outfile << "\t\t\t\t\tackInvConfig_sig <= '0';" << endl;
		if (cmdSet) outfile << "\t\t\t\t\tackInvSet_sig <= '0';" << endl;
		outfile << "-- IP impl.op.inv --- IEND" << endl;
	};

	// --- impl.op.run
	outfile << "-- IP impl.op.run --- IBEGIN" << endl;
	if (cmdGet) outfile << "\t\t\t\tgetBits_sig <= bitsIn_sig;" << endl;
	outfile << "-- IP impl.op.run --- IEND" << endl;
};
// IP cust --- IEND
