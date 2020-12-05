/**
	* \file PnlWdbeMchDetail_evals.cpp
	* job handler for job PnlWdbeMchDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeMchDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalTxtSupActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalButSupViewAvail(
			DbsWdbe* dbswdbe
		) {
	// mch.supEq(0)|(pre.ixCrdaccMch())

	vector<bool> args;
	bool a, b;

	a = false; a = (recMch.supRefWdbeMMachine == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeMchDetail::evalButSupViewActive(
			DbsWdbe* dbswdbe
		) {
	// !mch.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMch.supRefWdbeMMachine == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalTxtCchActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalButCchViewAvail(
			DbsWdbe* dbswdbe
		) {
	// mch.cchEq(0)|(pre.ixCrdaccMch())

	vector<bool> args;
	bool a, b;

	a = false; a = (recMch.cchRefWdbeMMachine == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeMchDetail::evalButCchViewActive(
			DbsWdbe* dbswdbe
		) {
	// !mch.cchEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMch.cchRefWdbeMMachine == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeMchDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};



