/**
	* \file PnlWdbeNavAdmin_evals.cpp
	* job handler for job PnlWdbeNavAdmin (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavAdmin::evalLstUsgAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalButUsgViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalLstUsrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalButUsrViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalLstPrsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalButPrsViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalLstFilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavAdmin::evalButFilViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};

