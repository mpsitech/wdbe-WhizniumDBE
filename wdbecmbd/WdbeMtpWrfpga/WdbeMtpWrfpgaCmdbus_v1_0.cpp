/**
	* \file WdbeMtpWrfpgaCmdbus_v1_0.cpp
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

#include "WdbeMtpWrfpgaCmdbus_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaCmdbus_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCmdbus_v1_0::run(
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

		// xxxx/Cmdbus.vhd
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
void WdbeMtpWrfpgaCmdbus_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	WdbeMVector* vec = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMSignal, TblWdbeMVector WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(mdl->supRefWdbeMModule)
				+ " AND TblWdbeMSignal.sref = 'req" + StrMod::cap(mdl->sref) + "' AND TblWdbeMVector.ref = TblWdbeMSignal.refWdbeMVector", &vec)) {

		dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

		// --- impl.arb.spec
		outfile << "-- IP impl.arb.spec --- IBEGIN" << endl;
		outfile << "\tprocess (reset, clk_sig)" << endl;
		outfile << "\t\tvariable reqrdy: std_logic_vector(" << (vits.nodes.size()-1) << " downto 0);" << endl;
		outfile << endl;

		outfile << "\tbegin" << endl;
		outfile << "\t\tif reset='1' then" << endl;
		outfile << "\t\t\tack_sig <= (others => '0');" << endl;
		outfile << endl;
		
		outfile << "\t\telsif rising_edge(clk_sig) then" << endl;
		outfile << "\t\t\tif ack_sig=" << valToSlv("0", vits.nodes.size()) << " then" << endl;
		outfile << "\t\t\t\t-- start new transfer" << endl;
		outfile << "\t\t\t\treqrdy := req and rdy;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\t\t\t";
			if (i != 0) outfile << "els";

			outfile << "if reqrdy(ix" << vec->sref.substr(3) << StrMod::cap(vit->sref) << ")='1' then" << endl;
			outfile << "\t\t\t\t\tack_sig <= (ix" << vec->sref.substr(3) << StrMod::cap(vit->sref) << " => '1', others => '0');" << endl;
		};

		outfile << "\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\tack_sig <= (others => '0');" << endl;
		outfile << "\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\telsif ((ack_sig and req)=" << valToSlv("0", vits.nodes.size()) << ") then" << endl;
		outfile << "\t\t\t\t-- end transfer currently active" << endl;
		outfile << "\t\t\t\tack_sig <= (others => '0');" << endl;
		outfile << "\t\t\tend if;" << endl;

		outfile << "\t\tend if;" << endl;
		outfile << "\tend process;" << endl;

		outfile << "-- IP impl.arb.spec --- IEND" << endl;

		delete vec;
	};
};
// IP cust --- IEND
