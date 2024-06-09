/**
	* \file PnlWdbeCdcDetail_evals.cpp
	* job handler for job PnlWdbeCdcDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeCdcDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxtFckActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButFckViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxtSckActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButSckViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxtMdlActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButMdlViewAvail(
			DbsWdbe* dbswdbe
		) {
	// cdc.mdlEq(0)|((pre.ixCrdaccMod()&pre.refUnt())|(pre.ixCrdaccMod()&pre.refCvr()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCdc.refWdbeMModule == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
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

bool PnlWdbeCdcDetail::evalButMdlViewActive(
			DbsWdbe* dbswdbe
		) {
	// !cdc.mdlEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCdc.refWdbeMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxtFarActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButFarViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxtSarActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalButSarViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCdcDetail::evalTxfRatActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCdcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
