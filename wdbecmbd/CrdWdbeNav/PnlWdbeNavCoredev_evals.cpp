/**
	* \file PnlWdbeNavCoredev_evals.cpp
	* job handler for job PnlWdbeNavCoredev (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavCoredev::evalLstCprAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavCoredev::evalButCprViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstCpr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCpr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavCoredev::evalLstCvrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavCoredev::evalButCvrViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstCvr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCvr != 0);
	args.push_back(a);

	return(args.back());
};
