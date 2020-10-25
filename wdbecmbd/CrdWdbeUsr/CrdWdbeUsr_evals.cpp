/**
	* \file CrdWdbeUsr_evals.cpp
	* job handler for job CrdWdbeUsr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWdbeUsr::evalMitCrdMkpAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccUsrIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref) & VecWdbeWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWdbeUsr::evalMitCrdMkpActive(
			DbsWdbe* dbswdbe
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

