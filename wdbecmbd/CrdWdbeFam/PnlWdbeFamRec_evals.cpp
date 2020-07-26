/**
	* \file PnlWdbeFamRec_evals.cpp
	* job handler for job PnlWdbeFamRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeFamRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refFam()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFFAM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

