/**
	* \file CrdWdbeCpr_evals.cpp
	* job handler for job CrdWdbeCpr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeCpr::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeCpr::evalMitCrdNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCprIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
