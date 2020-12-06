/**
	* \file PnlWdbeCvrDetail_evals.cpp
	* job handler for job PnlWdbeCvrDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeCvrDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalTxtCprActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButCprViewAvail(
			DbsWdbe* dbswdbe
		) {
	// cvr.cprEq(0)|(pre.ixCrdaccCpr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCvr.refWdbeMCoreproject == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButCprViewActive(
			DbsWdbe* dbswdbe
		) {
	// !cvr.cprEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCvr.refWdbeMCoreproject == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalTxfMajActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalTxfMinActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalTxfSubActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalTxtBcvActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButBcvViewAvail(
			DbsWdbe* dbswdbe
		) {
	// cvr.bcvEq(0)|((pre.ixCrdaccCvr()&pre.refCpr())|(pre.ixCrdaccCvr()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCvr.bcvRefWdbeMCoreversion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCPR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButBcvViewActive(
			DbsWdbe* dbswdbe
		) {
	// !cvr.bcvEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCvr.bcvRefWdbeMCoreversion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalPupJstActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalButJstEditAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalPupSteActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCvrDetail::evalLstStyActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
