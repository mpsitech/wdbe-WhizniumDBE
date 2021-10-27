/**
	* \file PnlWdbeSegSup1NSegment_evals.cpp
	* job handler for job PnlWdbeSegSup1NSegment (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeSegSup1NSegment::evalButViewAvail(
			DbsWdbe* dbswdbe
		) {
	// !sel()|((pre.ixCrdaccSeg()&pre.refPpl())|(pre.ixCrdaccSeg()&pre.refUnt()))

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWdbeSegSup1NSegment::evalButViewActive(
			DbsWdbe* dbswdbe
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
