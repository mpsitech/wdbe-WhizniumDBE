/**
	* \file PnlWdbeNavDescr_evals.cpp
	* job handler for job PnlWdbeNavDescr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavDescr::evalLstModAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMod()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButModViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstMod.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMod != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButModNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()|pre.refCvr()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstVecAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButVecViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVec.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVec != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButVecNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()|pre.refCvr()|pre.refVer()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstVitAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButVitViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVit.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVit != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstCmdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButCmdViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstCmd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCmd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButCmdNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstErrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButErrViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstErr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstErr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButErrNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstPphAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPph()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPphViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPph.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPph != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPphNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstBnkAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccBnk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButBnkViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstBnk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstBnk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButBnkNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstPinAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPin()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPinViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPin.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPin != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPinNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstGenAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccGen()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButGenViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstGen.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstGen != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstPrtAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPrtViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstSigAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButSigViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstSig.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSig != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstPrcAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButPrcViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPrc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstFstAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButFstViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstFst.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFst != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalLstVarAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavDescr::evalButVarViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVar.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVar != 0);
	args.push_back(a);

	return(args.back());
};
