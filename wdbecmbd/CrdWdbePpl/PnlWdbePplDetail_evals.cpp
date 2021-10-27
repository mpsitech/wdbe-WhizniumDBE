/**
	* \file PnlWdbePplDetail_evals.cpp
	* job handler for job PnlWdbePplDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbePplDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxtHsmActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalButHsmViewAvail(
			DbsWdbe* dbswdbe
		) {
	// ppl.hsmEq(0)|((pre.ixCrdaccMod()&ppl.hsm.inSbs(mod)&pre.refUnt())|(pre.ixCrdaccMod()&ppl.hsm.inSbs(mod)&pre.refCvr())|(pre.ixCrdaccMtp()&ppl.hsm.inSbs(mtp)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recPpl.hsmRefWdbeMModule == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbePplDetail::evalButHsmViewActive(
			DbsWdbe* dbswdbe
		) {
	// !ppl.hsmEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPpl.hsmRefWdbeMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxtClkActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalButClkViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxtClgActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalButClgViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxtAsrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalButAsrViewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxfDptActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePplDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPplIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
