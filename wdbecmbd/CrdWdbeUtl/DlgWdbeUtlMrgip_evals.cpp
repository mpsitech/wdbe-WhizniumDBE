/**
	* \file DlgWdbeUtlMrgip_evals.cpp
	* job handler for job DlgWdbeUtlMrgip (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeUtlMrgip::evalButDneActive(
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

bool DlgWdbeUtlMrgip::evalResDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlMrgip::evalLfiDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlMrgip::evalMrgButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(tupdone|tuldone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::TUPDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::TULDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlMrgip::evalMrgButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(merge|pack)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::MERGE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::PACK);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlMrgip::evalTrgUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(supdone|suldone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::SUPDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::SULDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlMrgip::evalSrcUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

