/**
	* \file PnlWdbeNavLow_evals.cpp
	* job handler for job PnlWdbeNavLow (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavLow::evalLstBnkAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccBnk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButBnkViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstBnk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstBnk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButBnkNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstPinAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPin()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButPinViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPin.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPin != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButPinNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstIntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccInt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButIntViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstInt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstInt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButIntNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstSnsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSns()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSNS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButSnsViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstSns.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSns != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstVarAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButVarViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVar.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVar != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstGenAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccGen()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButGenViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstGen.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstGen != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstPrtAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButPrtViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstSigAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButSigViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstSig.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSig != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButSigNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstPrcAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButPrcViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalLstFstAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavLow::evalButFstViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstFst.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFst != 0);
	args.push_back(a);

	return(args.back());
};
