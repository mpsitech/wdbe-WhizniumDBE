/**
	* \file PnlWdbeModRec_evals.cpp
	* job handler for job PnlWdbeModRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeModRec::evalPnlctrref1ncommandAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.ctrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModRec::evalPnlctrhk1nvectorAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.ctrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModRec::evalPnlctrref1nerrorAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.ctrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModRec::evalPnlctrmncommandAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.ctrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refMod()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref) != 0);
	args.push_back(a);

	return(args.back());
};
