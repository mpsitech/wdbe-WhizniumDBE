/**
	* \file PnlWdbeSilRec_evals.cpp
	* job handler for job PnlWdbeSilRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeSilRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refSil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

