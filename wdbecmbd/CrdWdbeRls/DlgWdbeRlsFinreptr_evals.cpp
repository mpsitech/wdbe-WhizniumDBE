/**
	* \file DlgWdbeRlsFinreptr_evals.cpp
	* job handler for job DlgWdbeRlsFinreptr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeRlsFinreptr::evalFinButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalFinButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(finidle|pack|commit)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::FINIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::PACK);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::COMMIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResDldAvail(
			DbsWdbe* dbswdbe
		) {
	// !pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResTxtPrgAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResSep1Avail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResButPsgAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalResButPsgActive(
			DbsWdbe* dbswdbe
		) {
	// sge(findone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FINDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsFinreptr::evalButDneActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};
