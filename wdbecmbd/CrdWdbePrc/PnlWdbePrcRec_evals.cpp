/**
	* \file PnlWdbePrcRec_evals.cpp
	* job handler for job PnlWdbePrcRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbePrcRec::evalPnlfsmfsm1nfsmstateAvail(
			DbsWdbe* dbswdbe
		) {
	// !prc.fsmEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPrc.refWdbeMFsm == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrcRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refPrc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref) != 0);
	args.push_back(a);

	return(args.back());
};
