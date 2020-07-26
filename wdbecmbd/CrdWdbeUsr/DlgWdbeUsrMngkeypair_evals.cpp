/**
	* \file DlgWdbeUsrMngkeypair_evals.cpp
	* job handler for job DlgWdbeUsrMngkeypair (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeUsrMngkeypair::evalDetButDelAvail(
			DbsWdbe* dbswdbe
		) {
	// sge(found)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FOUND);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUsrMngkeypair::evalDetButGenAvail(
			DbsWdbe* dbswdbe
		) {
	// sge(nf)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::NF);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUsrMngkeypair::evalDetDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(found)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FOUND);
	args.push_back(a);

	return(args.back());
};

