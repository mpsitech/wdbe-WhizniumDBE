/**
	* \file PnlWdbeLibAMakefile_evals.cpp
	* job handler for job PnlWdbeLibAMakefile (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeLibAMakefile::evalButNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLibIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeLibAMakefile::evalButDuplicateAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLibIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeLibAMakefile::evalButDuplicateActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeLibAMakefile::evalButDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccLibIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeLibAMakefile::evalButDeleteActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

