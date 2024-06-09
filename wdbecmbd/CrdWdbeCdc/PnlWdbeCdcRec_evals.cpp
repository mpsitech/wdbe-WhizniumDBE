/**
	* \file PnlWdbeCdcRec_evals.cpp
	* job handler for job PnlWdbeCdcRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeCdcRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refCdc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCDC, jref) != 0);
	args.push_back(a);

	return(args.back());
};
