/**
	* \file PnlWdbeNavDevdev_evals.cpp
	* job handler for job PnlWdbeNavDevdev (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavDevdev::evalLstPrjAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalButPrjViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalLstVerAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalButVerViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVer.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVer != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalLstUntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalButUntViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstUnt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUnt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDevdev::evalButUntNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};
