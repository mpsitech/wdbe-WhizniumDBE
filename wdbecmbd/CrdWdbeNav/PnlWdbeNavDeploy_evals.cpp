/**
	* \file PnlWdbeNavDeploy_evals.cpp
	* job handler for job PnlWdbeNavDeploy (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavDeploy::evalLstCmpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDeploy::evalButCmpViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstCmp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCmp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDeploy::evalLstRlsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDeploy::evalButRlsViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstRls.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRls != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDeploy::evalButRlsNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};
