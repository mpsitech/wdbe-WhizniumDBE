/**
	* \file CrdWdbeNav_evals.cpp
	* job handler for job CrdWdbeNav (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeNav::evalPnlpreAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.refCvr()|pre.refUnt()|pre.refVer()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
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

bool CrdWdbeNav::evalPnladminAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccFil()|pre.ixCrdaccPrf()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRF, jref) != 0);
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

bool CrdWdbeNav::evalPnlglobalAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMch()|pre.ixCrdaccLib()|pre.ixCrdaccFam()|pre.ixCrdaccSil()|pre.ixCrdaccMtp()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
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

bool CrdWdbeNav::evalPnldevdevAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrj()|pre.ixCrdaccVer()|pre.ixCrdaccUnt()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeNav::evalPnlcoredevAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCpr()|pre.ixCrdaccCvr()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeNav::evalPnlhighAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPph()|pre.ixCrdaccMod()|pre.ixCrdaccVec()|pre.ixCrdaccVit()|pre.ixCrdaccCmd()|pre.ixCrdaccErr()|pre.ixCrdaccPpl()|pre.ixCrdaccSeg()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
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

bool CrdWdbeNav::evalPnllowAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccBnk()|pre.ixCrdaccPin()|pre.ixCrdaccInt()|pre.ixCrdaccSns()|pre.ixCrdaccVar()|pre.ixCrdaccGen()|pre.ixCrdaccPrt()|pre.ixCrdaccSig()|pre.ixCrdaccCdc()|pre.ixCrdaccPrc()|pre.ixCrdaccFst()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSNS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCDC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) != 0);
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

bool CrdWdbeNav::evalPnldeployAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmp()|pre.ixCrdaccRls()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeNav::evalPnlauxfctAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitSesSpsAvail(
			DbsWdbe* dbswdbe
		) {
	// stgwdbebehavior.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwdbebehavior.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd1Avail(
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

bool CrdWdbeNav::evalMitCrdUsgAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdUsrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPrsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdFilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPrfAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd2Avail(
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

bool CrdWdbeNav::evalMitCrdMchAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdLibAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdFamAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFam()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdSilAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdMtpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd3Avail(
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

bool CrdWdbeNav::evalMitCrdPrjAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdVerAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdUntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdUntActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd4Avail(
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

bool CrdWdbeNav::evalMitCrdCprAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCpr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdCvrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCvr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd5Avail(
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

bool CrdWdbeNav::evalMitCrdPphAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPph()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPphActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdModAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMod()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdModActive(
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

bool CrdWdbeNav::evalMitCrdVecAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdVecActive(
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

bool CrdWdbeNav::evalMitCrdCmdAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdCmdActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdErrAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdErrActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPplAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPpl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPplActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdSegAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSeg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdSegActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd6Avail(
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

bool CrdWdbeNav::evalMitCrdBnkAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccBnk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdBnkActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPinAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccPin()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdPinActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdIntAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccInt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdIntActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdSigAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccSig()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdSigActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd7Avail(
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

bool CrdWdbeNav::evalMitCrdCmpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdRlsAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdRlsActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspCrd8Avail(
			DbsWdbe* dbswdbe
		) {
	// MitCrdUtlAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUtlAvail(dbswdbe);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitCrdUtlAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMspApp2Avail(
			DbsWdbe* dbswdbe
		) {
	// MitAppMlcAvail()|MitAppLoiAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitAppMlcAvail(dbswdbe);
	args.push_back(a);
	a = false; a = evalMitAppLoiAvail(dbswdbe);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWdbeNav::evalMitAppMlcAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeNav::evalMitAppLoiAvail(
			DbsWdbe* dbswdbe
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};
