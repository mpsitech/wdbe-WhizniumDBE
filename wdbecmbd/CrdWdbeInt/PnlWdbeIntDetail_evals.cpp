/**
	* \file PnlWdbeIntDetail_evals.cpp
	* job handler for job PnlWdbeIntDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbeIntDetail::evalButSaveAvail(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccIntIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeIntDetail::evalButSaveActive(
			DbsWdbe* dbswdbe
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeIntDetail::evalTxtSrfActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccIntIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeIntDetail::evalTxtUntActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccIntIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWdbeIntDetail::evalButUntViewAvail(
			DbsWdbe* dbswdbe
		) {
	// int.untEq(0)|((pre.ixCrdaccUnt()&pre.refVer())|(pre.ixCrdaccSil()&int.unt.inSbs(sil)))

	vector<bool> args;
	bool a, b;

	a = false; a = (recInt.refWdbeMUnit == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref) != 0);
	args.push_back(a);
	a = false; a = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recInt.refWdbeMUnit) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0);
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

bool PnlWdbeIntDetail::evalButUntViewActive(
			DbsWdbe* dbswdbe
		) {
	// !int.untEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recInt.refWdbeMUnit == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbeIntDetail::evalTxfCmtActive(
			DbsWdbe* dbswdbe
		) {
	// pre.ixCrdaccIntIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref) & VecWdbeWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
