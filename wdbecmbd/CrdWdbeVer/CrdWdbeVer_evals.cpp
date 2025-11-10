/**
	* \file CrdWdbeVer_evals.cpp
	* job handler for job CrdWdbeVer (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeVer::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdPcvAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdPcvActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd3Avail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd3Active(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIdpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIdpActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(newcre|newimp)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::NEWCRE, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::NEWIMP, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd4Avail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd4Active(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdImdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdImdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsndeploy|dsnmdlstr)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNDEPLOY, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNMDLSTR, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIcsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIcsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsnmdlstr|dsncmdset)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNMDLSTR, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNCMDSET, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIdaAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIdaActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsnmdlstr|dsncmdset|dsndflalg)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNMDLSTR, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNCMDSET, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNDFLALG, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd5Avail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd5Active(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdGfsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdGfsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsnmdlstr|dsncmdset|dsndflalg)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNMDLSTR, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNCMDSET, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNDFLALG, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIfsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIfsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsngenfst|dsncustfst)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNGENFST, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNCUSTFST, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd6Avail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeVer::evalMspCrd6Active(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdFnmAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdFnmActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsngenfst|dsncustfst)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNGENFST, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNCUSTFST, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};
