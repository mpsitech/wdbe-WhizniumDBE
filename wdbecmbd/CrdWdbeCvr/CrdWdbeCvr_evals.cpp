/**
	* \file CrdWdbeCvr_evals.cpp
	* job handler for job CrdWdbeCvr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeCvr::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdIbsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdIbsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdIdsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdIdsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMspCrd2Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdWcoAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdWcoAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdWcoAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvrIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCvr::evalMitCrdWcoActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

