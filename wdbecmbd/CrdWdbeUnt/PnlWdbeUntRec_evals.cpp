/**
	* \file PnlWdbeUntRec_evals.cpp
	* job handler for job PnlWdbeUntRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeUntRec::evalPnlsil1nunitAvail(
			DbsWdbe* dbswdbe
		) {
	// unt.inSbs(sil)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetUnt & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeUntRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};
