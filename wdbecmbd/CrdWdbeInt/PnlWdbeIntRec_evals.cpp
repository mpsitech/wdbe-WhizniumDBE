/**
	* \file PnlWdbeIntRec_evals.cpp
	* job handler for job PnlWdbeIntRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeIntRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refInt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFINT, jref) != 0);
	args.push_back(a);

	return(args.back());
};
