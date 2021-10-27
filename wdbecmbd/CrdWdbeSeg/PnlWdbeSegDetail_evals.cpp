/**
	* \file PnlWdbeSegDetail_evals.cpp
	* job handler for job PnlWdbeSegDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeSegDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalLstCluActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButCluViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButCluClusterAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)&seg.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSeg.refWdbeCSegment == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButCluUnclusterAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)&!seg.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSeg.refWdbeCSegment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxtPplActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButPplViewAvail(
			DbsWdbe* dbswdbe
		) {
	// seg.pplEq(0)|(pre.ixCrdaccPpl()&pre.refUnt())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSeg.pplRefWdbeMPipeline == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButPplViewActive(
			DbsWdbe* dbswdbe
		) {
	// !seg.pplEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSeg.pplRefWdbeMPipeline == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxtSupActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButSupViewAvail(
			DbsWdbe* dbswdbe
		) {
	// seg.supEq(0)|((pre.ixCrdaccSeg()&pre.refPpl())|(pre.ixCrdaccSeg()&pre.refUnt()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSeg.supRefWdbeMSegment == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeSegDetail::evalButSupViewActive(
			DbsWdbe* dbswdbe
		) {
	// !seg.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSeg.supRefWdbeMSegment == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxfIfmActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxfOfmActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxfLcyActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSegDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSegIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
