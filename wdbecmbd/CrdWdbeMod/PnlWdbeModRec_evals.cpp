/**
	* \file PnlWdbeModRec_evals.cpp
	* job handler for job PnlWdbeModRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

