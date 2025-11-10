/**
	* \file PnlWdbePrfDaemon_evals.cpp
	* job handler for job PnlWdbePrfDaemon (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWdbePrfDaemon::evalSep2Avail(
			DbsWdbe* dbswdbe
		) {
	// !cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalHdg201Avail(
			DbsWdbe* dbswdbe
		) {
	// !cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalTxf202Avail(
			DbsWdbe* dbswdbe
		) {
	// !cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalTxf203Avail(
			DbsWdbe* dbswdbe
		) {
	// !cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalChk204Avail(
			DbsWdbe* dbswdbe
		) {
	// !cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalSep3Avail(
			DbsWdbe* dbswdbe
		) {
	// cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalHdg301Avail(
			DbsWdbe* dbswdbe
		) {
	// cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalTxf302Avail(
			DbsWdbe* dbswdbe
		) {
	// cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalTxf303Avail(
			DbsWdbe* dbswdbe
		) {
	// cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);

	return(args.back());
};

bool PnlWdbePrfDaemon::evalChk304Avail(
			DbsWdbe* dbswdbe
		) {
	// cmbdNotD()

	vector<bool> args;
	bool a;

	a = false;
#ifdef WDBECMBD
	a = true;
#endif
	args.push_back(a);

	return(args.back());
};
