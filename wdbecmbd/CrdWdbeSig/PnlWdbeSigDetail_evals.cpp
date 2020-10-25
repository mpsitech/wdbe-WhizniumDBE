/**
	* \file PnlWdbeSigDetail_evals.cpp
	* job handler for job PnlWdbeSigDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeSigDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalPupTypActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalLstCluActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButCluViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButCluClusterAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)&sig.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSig.refWdbeCSignal == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButCluUnclusterAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)&!sig.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSig.refWdbeCSignal == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxtMdlActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButMdlViewAvail(
			DbsWdbe* dbswdbe
		) {
	// sig.mdlEq(0)|((pre.ixCrdaccMod()&pre.refUnt())|(pre.ixCrdaccMod()&pre.refCvr()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSig.mdlRefWdbeMModule == 0);
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

bool PnlWdbeSigDetail::evalButMdlViewActive(
			DbsWdbe* dbswdbe
		) {
	// !sig.mdlEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSig.mdlRefWdbeMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxtMguActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButMguViewAvail(
			DbsWdbe* dbswdbe
		) {
	// sig.mguEq(0)|((pre.ixCrdaccMod()&sig.mgtEq(mdl)&sig.mgu.inSbs(mod)&pre.refUnt())|(pre.ixCrdaccMod()&sig.mgtEq(mdl)&sig.mgu.inSbs(mod)&pre.refCvr())|(pre.ixCrdaccMtp()&sig.mgtEq(mdl)&sig.mgu.inSbs(mtp))|(pre.ixCrdaccPrc()&sig.mgtEq(prc)&pre.refMtp())|(pre.ixCrdaccPrc()&sig.mgtEq(prc)&pre.refMod()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSig.mgeUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);
	a = false; a = (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref) != 0);
	args.push_back(a);
	a = false; a = (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref) != 0);
	args.push_back(a);
	a = false; a = (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref) != 0);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButMguViewActive(
			DbsWdbe* dbswdbe
		) {
	// !sig.mguEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSig.mgeUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxtVecActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButVecViewAvail(
			DbsWdbe* dbswdbe
		) {
	// sig.vecEq(0)|((pre.ixCrdaccVec()&pre.refUnt())|(pre.ixCrdaccVec()&pre.refCvr())|(pre.ixCrdaccVec()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSig.refWdbeMVector == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
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

bool PnlWdbeSigDetail::evalButVecViewActive(
			DbsWdbe* dbswdbe
		) {
	// !sig.vecEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSig.refWdbeMVector == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalChkConActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalPupHtyActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButHtyEditAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfWidActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfMmxActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfCmbActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfOnvActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfOfvActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalChkDfoActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxtDrvActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalButDrvViewAvail(
			DbsWdbe* dbswdbe
		) {
	// sig.drvEq(0)|((pre.ixCrdaccPrt()&pre.refMtp())|(pre.ixCrdaccPrt()&pre.refMod()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSig.drvRefWdbeMPort == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref) != 0);
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

bool PnlWdbeSigDetail::evalButDrvViewActive(
			DbsWdbe* dbswdbe
		) {
	// !sig.drvEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSig.drvRefWdbeMPort == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeSigDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSigIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

