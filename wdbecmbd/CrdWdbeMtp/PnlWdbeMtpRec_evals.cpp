/**
	* \file PnlWdbeMtpRec_evals.cpp
	* job handler for job PnlWdbeMtpRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeMtpRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refMtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

