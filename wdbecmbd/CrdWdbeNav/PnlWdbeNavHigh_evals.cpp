/**
	* \file PnlWdbeNavHigh_evals.cpp
	* job handler for job PnlWdbeNavHigh (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavHigh::evalLstPphAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPph()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButPphViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPph.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPph != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButPphNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalLstModAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMod()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButModViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstMod.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMod != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButModNewcrdActive(
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

bool PnlWdbeNavHigh::evalLstVecAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButVecViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVec.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVec != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButVecNewcrdActive(
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

bool PnlWdbeNavHigh::evalLstVitAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButVitViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstVit.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVit != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalLstCmdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButCmdViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstCmd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCmd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButCmdNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalLstErrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButErrViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstErr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstErr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButErrNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalLstPplAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPpl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButPplViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstPpl.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPpl != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButPplNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalLstSegAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButSegViewActive(
			DbsWdbe* dbswdbe
		) {
	// LstSeg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSeg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHigh::evalButSegNewcrdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};
