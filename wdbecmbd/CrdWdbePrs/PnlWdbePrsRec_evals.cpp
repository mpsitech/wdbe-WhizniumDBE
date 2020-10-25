/**
	* \file PnlWdbePrsRec_evals.cpp
	* job handler for job PnlWdbePrsRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbePrsRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

