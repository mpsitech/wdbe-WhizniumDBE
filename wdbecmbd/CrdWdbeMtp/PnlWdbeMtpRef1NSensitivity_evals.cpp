/**
	* \file PnlWdbeMtpRef1NSensitivity_evals.cpp
	* job handler for job PnlWdbeMtpRef1NSensitivity (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeMtpRef1NSensitivity::evalButDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMtpRef1NSensitivity::evalButDeleteActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
