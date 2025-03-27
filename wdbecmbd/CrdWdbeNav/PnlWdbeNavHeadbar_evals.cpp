/**
	* \file PnlWdbeNavHeadbar_evals.cpp
	* job handler for job PnlWdbeNavHeadbar (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeNavHeadbar::evalMenCrdAvail(
			DbsWdbe* dbswdbe
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()|MspCrd4Avail()|MspCrd5Avail()|MspCrd6Avail()|MspCrd7Avail()|MspCrd8Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd4Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd5Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd6Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd7Avail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMspCrd8Avail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd1Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdFilAvail()|MitCrdPrfAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdPrfAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdUsgAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdUsrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPrsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdFilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPrfAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd2Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdMchAvail()|MitCrdLibAvail()|MitCrdFamAvail()|MitCrdSilAvail()|MitCrdMtpAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdMchAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdLibAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdFamAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdSilAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdMtpAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdMchAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdLibAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdFamAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFam()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdSilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdMtpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd3Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdPrjAvail()|MitCrdVerAvail()|MitCrdUntAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPrjAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdVerAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdUntAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPrjAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdVerAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdUntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd4Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdCprAvail()|MitCrdCvrAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdCprAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdCvrAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdCprAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdCvrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd5Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdPphAvail()|MitCrdModAvail()|MitCrdVecAvail()|MitCrdCmdAvail()|MitCrdErrAvail()|MitCrdPplAvail()|MitCrdSegAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPphAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdModAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdVecAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdCmdAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdErrAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdPplAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdSegAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPphAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPph()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdModAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMod()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdVecAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdCmdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdErrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPplAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPpl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdSegAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd6Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdBnkAvail()|MitCrdPinAvail()|MitCrdIntAvail()|MitCrdSigAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdBnkAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdPinAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdIntAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdSigAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdBnkAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccBnk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdPinAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPin()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdIntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccInt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdSigAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd7Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdCmpAvail()|MitCrdRlsAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdCmpAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitCrdRlsAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdCmpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdRlsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMspCrd8Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdUtlAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUtlAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeNavHeadbar::evalMitCrdUtlAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
