/**
	* \file WdbeMtpWrfpgaIrq_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaIrq_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaIrq_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaIrq_Easy_v1_0::run(
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

		// xxxx/IrqXyz.vhd
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
void WdbeMtpWrfpgaIrq_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	string capt; // ex. xyz.32
	bool strbNotVal, zeroCountNotIgnore;

	vector<string> ss;
	string s;
	
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "capt", capt)) {
		StrMod::stringToVector(capt, ss, '.');

		if (ss.size() == 2) {
			strbNotVal = false;
			if (Wdbe::getMpa(dbswdbe, mdl->ref, "strbNotVal", s)) strbNotVal = (s == "true");

			zeroCountNotIgnore = false;
			if (Wdbe::getMpa(dbswdbe, mdl->ref, "zeroCountNotIgnore", s)) zeroCountNotIgnore = (s == "true");

			// --- varlast
			outfile << "-- IP varlast --- IBEGIN" << endl;
			if (!strbNotVal) {
				outfile << "\t\tvariable " << ss[0] << "_last: ";
				if (atoi(ss[1].c_str()) == 1) outfile << "std_logic;" << endl;
				else outfile << "std_logic_vector(" << (atoi(ss[1].c_str())-1) << " downto 0);" << endl;
			};
			outfile << "-- IP varlast --- IEND" << endl;

			// --- sample1
			outfile << "-- IP sample1 --- IBEGIN" << endl;
			if (!strbNotVal) outfile << "\t\t\t\t\t" << ss[0] << "_last := " << ss[0] << ";" << endl;
			outfile << "-- IP sample1 --- IEND" << endl;

			// --- compare
			outfile << "-- IP compare --- IBEGIN" << endl;
			outfile << "\t\t\t\t\tif ";

			if (!strbNotVal) {
				outfile << ss[0] << "/=" << ss[0] << "_last";

				if (!zeroCountNotIgnore) {
					if (atoi(ss[1].c_str()) == 1) outfile << " and " << ss[0] << "='1'";
					else outfile << " and to_integer(unsigned(" << ss[0] << "))/=0";
				};

			} else outfile << ss[0] << "='1'";

			outfile << " then" << endl;

			outfile << "\t\t\t\t\t\tirq_sig <= '1';" << endl;
			outfile << "\t\t\t\t\tend if;" << endl;
			outfile << "-- IP compare --- IEND" << endl;

			// --- sample2
			outfile << "-- IP sample2 --- IBEGIN" << endl;
			if (!strbNotVal) outfile << "\t\t\t\t" << ss[0] << "_last := " << ss[0] << ";" << endl;
			outfile << "-- IP sample2 --- IEND" << endl;
		};
	};
};
// IP cust --- IEND
