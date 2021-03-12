/**
	* \file DlgWdbeUtlExtrip_evals.cpp
	* job handler for job DlgWdbeUtlExtrip (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWdbeUtlExtrip::evalResDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlExtrip::evalButDneActive(
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

bool DlgWdbeUtlExtrip::evalLfiDldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWdbeUtlExtrip::evalExtButRunActive(
			DbsWdbe* dbswdbe
		) {
	// sge(upkdone|ulddone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::ULDDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlExtrip::evalExtButStoActive(
			DbsWdbe* dbswdbe
		) {
	// sge(extract|pack)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::EXTRACT);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::PACK);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWdbeUtlExtrip::evalSrcUldActive(
			DbsWdbe* dbswdbe
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};
