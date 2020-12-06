/**
	* \file PnlWdbeLibRec_evals.cpp
	* job handler for job PnlWdbeLibRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeLibRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};
