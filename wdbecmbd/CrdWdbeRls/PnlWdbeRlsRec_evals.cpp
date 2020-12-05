/**
	* \file PnlWdbeRlsRec_evals.cpp
	* job handler for job PnlWdbeRlsRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeRlsRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};



