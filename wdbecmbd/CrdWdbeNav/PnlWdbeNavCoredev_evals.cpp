/**
	* \file PnlWdbeNavCoredev_evals.cpp
	* job handler for job PnlWdbeNavCoredev (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

