/**
	* \file DlgWdbeVerDetdd_evals.cpp
	* job handler for job DlgWdbeVerDetdd (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeVerDetdd::evalIfiUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalImpButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(prsdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::PRSDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalImpButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(impidle|import)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IMPIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::IMPORT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalPprButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(impdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IMPDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalPprButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(postprc1|postprc2|postprc3)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::POSTPRC1);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::POSTPRC2);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::POSTPRC3);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalLfiDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeVerDetdd::evalButDneActive(
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
