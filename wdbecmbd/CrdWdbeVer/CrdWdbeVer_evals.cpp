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

bool CrdWdbeVer::evalMitCrdIbsAvail(
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

bool CrdWdbeVer::evalMitCrdIbsActive(
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

bool CrdWdbeVer::evalMitCrdIdsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeVer::evalMitCrdIdsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()&ver.steEq(dsnbscdd)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBEVER_STEEQ, statshr.jrefRec, VecWdbeVMVersionState::DSNBSCDD, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};
