/**
	* \file DlgWdbeUtlIexconv_evals.cpp
	* job handler for job DlgWdbeUtlIexconv (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeUtlIexconv::evalSrcUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlIexconv::evalCnvButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(ulddone|upkdone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::ULDDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlIexconv::evalCnvButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(conv)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CONV);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlIexconv::evalResDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlIexconv::evalButDneActive(
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

