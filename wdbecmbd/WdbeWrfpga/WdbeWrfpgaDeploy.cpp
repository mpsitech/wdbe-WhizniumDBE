/**
	* \file WdbeWrfpgaDeploy.cpp
	* Wdbe operation processor - write FPGA code deployment scripts (implementation)
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

#include "WdbeWrfpgaDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaDeploy
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaDeploy::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaDeploy* dpchinv
		) {
	ubigint refWdbeMRelease = dpchinv->refWdbeMRelease;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMRelease* rls = NULL;

	ListWdbeMUnit unts;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls)) {
		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMComponent, TblWdbeMUnit WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER)
					+ " AND TblWdbeMUnit.refUref = TblWdbeMComponent.refWdbeMVersion AND TblWdbeMComponent.ref = " + to_string(rls->refWdbeMComponent) + " ORDER BY sref ASC", false, unts);

		// checkout.sh
		s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
		outfile.open(s.c_str(), ios::out);
		writeChkoutSh(dbswdbe, outfile, unts);
		outfile.close();

		delete rls;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaDeploy::writeChkoutSh(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, ListWdbeMUnit& unts
		) {
	WdbeMUnit* unt = NULL;

	bool first;

	// --- all
	outfile << "# IP all --- IBEGIN" << endl;
	outfile << "\tunts=(";

	first = true;

	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		if (unt->ixVBasetype == VecWdbeVMUnitBasetype::FPGA) {
			if (first) first = false;
			else outfile << " ";

			outfile << "\"" << unt->sref << "\"";
		};
	};
	outfile << ")" << endl;
	outfile << "# IP all --- IEND" << endl;

	// --- iseunts
	outfile << "# IP iseunts --- IBEGIN" << endl;
	outfile << "\tif";

	first = true;

	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		if (unt->ixVBasetype == VecWdbeVMUnitBasetype::FPGA) {
			if (unt->srefKToolch == "ise") {
				if (first) first = false;
				else outfile << " ||";

				outfile << " [ \"$var\" = \"" << unt->sref << "\" ]";
			};
		};
	};

	if (first) outfile << " [ 0 == 1 ]";

	outfile << "; then" << endl;
	outfile << "# IP iseunts --- IEND" << endl;
};
// IP cust --- IEND
