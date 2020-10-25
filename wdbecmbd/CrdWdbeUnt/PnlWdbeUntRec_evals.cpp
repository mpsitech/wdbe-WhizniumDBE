/**
	* \file PnlWdbeUntRec_evals.cpp
	* job handler for job PnlWdbeUntRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeUntRec::evalPnlsil1nunitAvail(
			DbsWdbe* dbswdbe
		) {
	// unt.inSbs(sil)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetUnt & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeUntRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUnt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

