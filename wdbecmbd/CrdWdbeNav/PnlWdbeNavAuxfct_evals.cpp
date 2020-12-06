/**
	* \file PnlWdbeNavAuxfct_evals.cpp
	* job handler for job PnlWdbeNavAuxfct (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavAuxfct::evalButUtlNewcrdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
