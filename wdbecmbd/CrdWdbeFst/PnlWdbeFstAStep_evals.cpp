/**
	* \file PnlWdbeFstAStep_evals.cpp
	* job handler for job PnlWdbeFstAStep (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeFstAStep::evalButUpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButUpActive(
			DbsWdbe* dbswdbe
		) {
	// sel()&!sel.first()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == 1);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDownAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDownActive(
			DbsWdbe* dbswdbe
		) {
	// sel()&!sel.last()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == qry->statshr.ntot);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButNewAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDuplicateAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDuplicateActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccFstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeFstAStep::evalButDeleteActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
