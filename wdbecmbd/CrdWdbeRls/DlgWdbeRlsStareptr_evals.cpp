/**
	* \file DlgWdbeRlsStareptr_evals.cpp
	* job handler for job DlgWdbeRlsStareptr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeRlsStareptr::evalDetButStaActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalIniUldAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixBasereptypeEq(uld)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::ULD);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalIniUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(stadone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::STADONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalIniTxtPrgAvail(
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

bool DlgWdbeRlsStareptr::evalIniSep1Avail(
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

bool DlgWdbeRlsStareptr::evalIniButClgAvail(
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

bool DlgWdbeRlsStareptr::evalIniButClgActive(
			DbsWdbe* dbswdbe
		) {
	// sge(stadone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::STADONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalExtButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(upkdone|clgdone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::CLGDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalExtButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(extract)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::EXTRACT);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalLfiDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeRlsStareptr::evalButDneActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle|fail|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

