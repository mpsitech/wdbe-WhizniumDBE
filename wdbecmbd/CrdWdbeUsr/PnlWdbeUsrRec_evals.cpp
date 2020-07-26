/**
	* \file PnlWdbeUsrRec_evals.cpp
	* job handler for job PnlWdbeUsrRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeUsrRec::evalButRegularizeActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

