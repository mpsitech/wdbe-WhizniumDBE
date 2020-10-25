/**
	* \file PnlWdbeCmdDetail_evals.cpp
	* job handler for job PnlWdbeCmdDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeCmdDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxfFsrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxtReuActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalButReuViewAvail(
			DbsWdbe* dbswdbe
		) {
	// cmd.reuEq(0)|((pre.ixCrdaccMod()&cmd.retEq(ctr)&cmd.reu.mdl.inSbs(mod)&pre.refUnt())|(pre.ixCrdaccMod()&cmd.retEq(ctr)&cmd.reu.mdl.inSbs(mod)&pre.refCvr())|(pre.ixCrdaccMtp()&cmd.retEq(ctr)&cmd.reu.mdl.inSbs(mtp))|(pre.ixCrdaccUnt()&cmd.retEq(unt)&pre.refVer())|(pre.ixCrdaccSil()&cmd.retEq(unt)&cmd.reu.inSbs(sil)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCmd.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
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
	a = false; a = (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0);
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
	a = false; a = (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);
	a = false; a = (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::UNT);
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
	a = false; a = (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::UNT);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCmd.refUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0);
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

bool PnlWdbeCmdDetail::evalButReuViewActive(
			DbsWdbe* dbswdbe
		) {
	// !cmd.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCmd.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalPupRtyActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxtIvrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxtRvrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxtRerActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeCmdDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

