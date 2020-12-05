/**
	* \file CrdWdbeFil_evals.cpp
	* job handler for job CrdWdbeFil (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeFil::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeFil::evalMitCrdNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFilIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWdbeFil::evalMitCrdDldAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFilIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeFil::evalMitCrdDldActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};



