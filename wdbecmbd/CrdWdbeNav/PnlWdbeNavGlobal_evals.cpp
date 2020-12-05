/**
	* \file PnlWdbeNavGlobal_evals.cpp
	* job handler for job PnlWdbeNavGlobal (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavGlobal::evalLstMchAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalButMchViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstMch.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMch != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalLstLibAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalButLibViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstLib.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLib != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalLstFamAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFam()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalButFamViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstFam.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFam != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalLstSilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalButSilViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstSil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSil != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalLstMtpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavGlobal::evalButMtpViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstMtp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMtp != 0);
	args.push_back(a);

	return(args.back());
};



