/**
	* \file PnlWdbeNavPre_evals.cpp
	* job handler for job PnlWdbeNavPre (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavPre::evalTxtCvrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.refCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavPre::evalTxtUntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavPre::evalTxtVerAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};



