/**
	* \file PnlWdbeVecRec_evals.cpp
	* job handler for job PnlWdbeVecRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeVecRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

