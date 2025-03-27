/**
	* \file PnlWdbeModDetail_evals.cpp
	* job handler for job PnlWdbeModDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeModDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalPupVndActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButVndEditAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalPupTypActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxtHkuActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButHkuViewAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.hkuEq(0)|((pre.ixCrdaccCvr()&mdl.hktEq(cvr))|(pre.ixCrdaccUnt()&mdl.hktEq(unt)&pre.refVer())|(pre.ixCrdaccSil()&mdl.hktEq(unt)&mdl.hku.inSbs(sil)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recMdl.hkUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);
	a = false; a = (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::CVR);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);
	a = false; a = (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::UNT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);
	a = false; a = (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::UNT);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
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

bool PnlWdbeModDetail::evalButHkuViewActive(
			DbsWdbe* dbswdbe
		) {
	// !mdl.hkuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.hkUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxtSupActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButSupViewAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.supEq(0)|((pre.ixCrdaccMod()&mdl.sup.inSbs(mod)&pre.refUnt())|(pre.ixCrdaccMod()&mdl.sup.inSbs(mod)&pre.refCvr())|(pre.ixCrdaccMtp()&mdl.sup.inSbs(mtp)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recMdl.supRefWdbeMModule == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
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
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
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
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0);
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

bool PnlWdbeModDetail::evalButSupViewActive(
			DbsWdbe* dbswdbe
		) {
	// !mdl.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.supRefWdbeMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxtTplActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButTplViewAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.tplEq(0)|(pre.ixCrdaccMtp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recMdl.tplRefWdbeMModule == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeModDetail::evalButTplViewActive(
			DbsWdbe* dbswdbe
		) {
	// !mdl.tplEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.tplRefWdbeMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfSrrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalSepImbAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.inSbs(mib)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetMdl & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMIB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalHdgImbAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.inSbs(mib)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetMdl & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMIB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButImbNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)&mdl.imbEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeModDetail::evalButImbDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)&!mdl.imbEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbFsrAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.imbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbFsrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalPupImbRtyAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.imbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalPupImbRtyActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbWidAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.imbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbWidActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbMmxAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.imbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbMmxActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbPriAvail(
			DbsWdbe* dbswdbe
		) {
	// !mdl.imbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMdl.refWdbeMImbuf == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfImbPriActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalSepCtrAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.inSbs(mct)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetMdl & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMCT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalHdgCtrAvail(
			DbsWdbe* dbswdbe
		) {
	// mdl.inSbs(mct)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetMdl & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMCT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButCtrNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)&mdl.ctrEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeModDetail::evalButCtrDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)&!mdl.ctrEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recMdl.refWdbeMController == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxfCtrFsrAvail(
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

bool PnlWdbeModDetail::evalTxfCtrFsrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalTxtCtrClrAvail(
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

bool PnlWdbeModDetail::evalTxtCtrClrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccModIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeModDetail::evalButCtrClrViewAvail(
			DbsWdbe* dbswdbe
		) {
	// ctr.clrEq(0)|(pre.ixCrdaccSig()&pre.refMod())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCtr.clrRefWdbeMSignal == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeModDetail::evalButCtrClrViewActive(
			DbsWdbe* dbswdbe
		) {
	// !ctr.clrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCtr.clrRefWdbeMSignal == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};
