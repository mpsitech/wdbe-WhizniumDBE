/**
	* \file CrdWdbeRls_evals.cpp
	* job handler for job CrdWdbeRls (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeRls::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRlsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdSrtAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdSrtActive(
			DbsWdbe* dbswdbe
		) {
	// !pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdCrtAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdCrtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdFrtAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdFrtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdWcoAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeRls::evalMitCrdWcoActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
