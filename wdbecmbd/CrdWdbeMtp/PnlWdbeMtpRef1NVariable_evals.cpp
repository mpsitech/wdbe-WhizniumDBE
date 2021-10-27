/**
	* \file PnlWdbeMtpRef1NVariable_evals.cpp
	* job handler for job PnlWdbeMtpRef1NVariable (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeMtpRef1NVariable::evalButUpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMtpRef1NVariable::evalButUpActive(
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

bool PnlWdbeMtpRef1NVariable::evalButDownAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMtpRef1NVariable::evalButDownActive(
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

bool PnlWdbeMtpRef1NVariable::evalButDeleteAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccMtpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeMtpRef1NVariable::evalButDeleteActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
