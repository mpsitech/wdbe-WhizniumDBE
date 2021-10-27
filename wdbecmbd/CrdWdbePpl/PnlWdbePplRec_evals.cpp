/**
	* \file PnlWdbePplRec_evals.cpp
	* job handler for job PnlWdbePplRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbePplRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refPpl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
