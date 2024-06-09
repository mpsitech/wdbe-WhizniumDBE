/**
	* \file PnlWdbeCmpRec_evals.cpp
	* job handler for job PnlWdbeCmpRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeCmpRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};
