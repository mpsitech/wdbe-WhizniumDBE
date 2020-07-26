/**
	* \file PnlWdbeTrgRec_evals.cpp
	* job handler for job PnlWdbeTrgRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeTrgRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refTrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFTRG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

