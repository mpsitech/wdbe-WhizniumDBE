/**
	* \file PnlWdbePrfDaemon.cpp
	* job handler for job PnlWdbePrfDaemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbePrfDaemon.h"

#include "PnlWdbePrfDaemon_blks.cpp"
#include "PnlWdbePrfDaemon_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePrfDaemon
 ******************************************************************************/

PnlWdbePrfDaemon::PnlWdbePrfDaemon(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPRFDAEMON, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPup402.tag = "FeedFPup402";
	feedFPup706.tag = "FeedFPup706";

	// IP constructor.cust1 --- INSERT

	setPref(dbswdbe); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWdbePrfDaemon::~PnlWdbePrfDaemon() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWdbePrfDaemon::getPref(
#ifdef WDBED
			StgWdbeBehavior*& _stgwdbebehavior
			,  StgWdbeAppsrv*& _stgwdbeappsrv
			,  StgWdbed*& _stgwdbed
			,  StgWdbeDatabase*& _stgwdbedatabase
			,  StgWdbePath*& _stgwdbepath
			,  StgWdbeTenant*& _stgwdbetenant
			,  StgWdbeMonitor*& _stgwdbemonitor
#endif
#ifdef WDBECMBD
			StgWdbeBehavior*& _stgwdbebehavior
			,  StgWdbeAppsrv*& _stgwdbeappsrv
			,  StgWdbecmbd*& _stgwdbecmbd
			,  StgWdbeDatabase*& _stgwdbedatabase
			,  StgWdbePath*& _stgwdbepath
			,  StgWdbeTenant*& _stgwdbetenant
			,  StgWdbeMonitor*& _stgwdbemonitor
#endif
		) {
	if (!(statshr.Txf2Clean && statshr.Chk3Clean && statshr.Txf4Clean && statshr.Txf5Clean && statshr.Txf6Clean)) {
		_stgwdbebehavior = &stgwdbebehavior;
		stgwdbebehavior.histlength = atoi(contiac.Txf2.c_str());
		stgwdbebehavior.suspsess = contiac.Chk3;
		stgwdbebehavior.sesstterm = atol(contiac.Txf4.c_str());
		stgwdbebehavior.sesstwarn = atol(contiac.Txf5.c_str());
		stgwdbebehavior.roottterm = atol(contiac.Txf6.c_str());
	};

	if (!(statshr.Txf102Clean && statshr.Chk103Clean && statshr.Txf104Clean)) {
		_stgwdbeappsrv = &stgwdbeappsrv;
		stgwdbeappsrv.port = atoi(contiac.Txf102.c_str());
		stgwdbeappsrv.https = contiac.Chk103;
		stgwdbeappsrv.cors = contiac.Txf104;
	};

#ifdef WDBED
	if (!(statshr.Txf202Clean && statshr.Txf203Clean && statshr.Chk204Clean)) {
		_stgwdbed = &stgwdbed;
		stgwdbed.jobprcn = atoi(contiac.Txf202.c_str());
		stgwdbed.opengsrvport = atoi(contiac.Txf203.c_str());
		stgwdbed.appsrv = contiac.Chk204;
	};
#endif

#ifdef WDBECMBD
	if (!(statshr.Txf302Clean && statshr.Txf303Clean && statshr.Chk304Clean)) {
		_stgwdbecmbd = &stgwdbecmbd;
		stgwdbecmbd.jobprcn = atoi(contiac.Txf302.c_str());
		stgwdbecmbd.opprcn = atoi(contiac.Txf303.c_str());
		stgwdbecmbd.appsrv = contiac.Chk304;
	};
#endif

	if (!(statshr.Pup402Clean && statshr.Txf403Clean && statshr.Txf404Clean && statshr.Txf405Clean && statshr.Txf406Clean && statshr.Txf407Clean && statshr.Txf408Clean)) {
		_stgwdbedatabase = &stgwdbedatabase;
		stgwdbedatabase.ixDbsVDbstype = feedFPup402.getIxByNum(contiac.numFPup402);
		stgwdbedatabase.dbspath = contiac.Txf403;
		stgwdbedatabase.dbsname = contiac.Txf404;
		stgwdbedatabase.username = contiac.Txf405;
		stgwdbedatabase.password = contiac.Txf406;
		stgwdbedatabase.ip = contiac.Txf407;
		stgwdbedatabase.port = atoi(contiac.Txf408.c_str());
	};

	if (!(statshr.Txf502Clean && statshr.Txf503Clean && statshr.Txf504Clean && statshr.Txf505Clean && statshr.Txf506Clean && statshr.Txf507Clean)) {
		_stgwdbepath = &stgwdbepath;
		stgwdbepath.acvpath = contiac.Txf502;
		stgwdbepath.keypath = contiac.Txf503;
		stgwdbepath.monpath = contiac.Txf504;
		stgwdbepath.tmppath = contiac.Txf505;
		stgwdbepath.webpath = contiac.Txf506;
		stgwdbepath.helpurl = contiac.Txf507;
	};

	if (!(statshr.Txf602Clean && statshr.Txf603Clean)) {
		_stgwdbetenant = &stgwdbetenant;
		stgwdbetenant.orgname = contiac.Txf602;
		stgwdbetenant.orgweb = contiac.Txf603;
	};

	if (!(statshr.Txf702Clean && statshr.Txf703Clean && statshr.Txf704Clean && statshr.Txf705Clean && statshr.Pup706Clean && statshr.Txf707Clean && statshr.Txf708Clean && statshr.Txf709Clean && statshr.Txf710Clean)) {
		_stgwdbemonitor = &stgwdbemonitor;
		stgwdbemonitor.username = contiac.Txf702;
		stgwdbemonitor.password = contiac.Txf703;
		stgwdbemonitor.ip = contiac.Txf704;
		stgwdbemonitor.port = atoi(contiac.Txf705.c_str());
		stgwdbemonitor.ixDbsVDbstype = feedFPup706.getIxByNum(contiac.numFPup706);
		stgwdbemonitor.dbspath = contiac.Txf707;
		stgwdbemonitor.dbsname = contiac.Txf708;
		stgwdbemonitor.dbsusername = contiac.Txf709;
		stgwdbemonitor.dbspassword = contiac.Txf710;
	};

};

void PnlWdbePrfDaemon::setPref(
			DbsWdbe* dbswdbe
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Txf2 = to_string(xchg->stgwdbebehavior.histlength);
	contiac.Chk3 = xchg->stgwdbebehavior.suspsess;
	contiac.Txf4 = to_string(xchg->stgwdbebehavior.sesstterm);
	contiac.Txf5 = to_string(xchg->stgwdbebehavior.sesstwarn);
	contiac.Txf6 = to_string(xchg->stgwdbebehavior.roottterm);

	contiac.Txf102 = to_string(xchg->stgwdbeappsrv.port);
	contiac.Chk103 = xchg->stgwdbeappsrv.https;
	contiac.Txf104 = xchg->stgwdbeappsrv.cors;

#ifdef WDBED
	contiac.Txf202 = to_string(xchg->stgwdbed.jobprcn);
	contiac.Txf203 = to_string(xchg->stgwdbed.opengsrvport);
	contiac.Chk204 = xchg->stgwdbed.appsrv;
#endif

#ifdef WDBECMBD
	contiac.Txf302 = to_string(xchg->stgwdbecmbd.jobprcn);
	contiac.Txf303 = to_string(xchg->stgwdbecmbd.opprcn);
	contiac.Chk304 = xchg->stgwdbecmbd.appsrv;
#endif

	contiac.numFPup402 = feedFPup402.getNumByIx(xchg->stgwdbedatabase.ixDbsVDbstype);
	contiac.Txf403 = xchg->stgwdbedatabase.dbspath;
	contiac.Txf404 = xchg->stgwdbedatabase.dbsname;
	contiac.Txf405 = xchg->stgwdbedatabase.username;
	contiac.Txf406 = xchg->stgwdbedatabase.password;
	contiac.Txf407 = xchg->stgwdbedatabase.ip;
	contiac.Txf408 = to_string(xchg->stgwdbedatabase.port);

	contiac.Txf502 = xchg->stgwdbepath.acvpath;
	contiac.Txf503 = xchg->stgwdbepath.keypath;
	contiac.Txf504 = xchg->stgwdbepath.monpath;
	contiac.Txf505 = xchg->stgwdbepath.tmppath;
	contiac.Txf506 = xchg->stgwdbepath.webpath;
	contiac.Txf507 = xchg->stgwdbepath.helpurl;

	contiac.Txf602 = xchg->stgwdbetenant.orgname;
	contiac.Txf603 = xchg->stgwdbetenant.orgweb;

	contiac.Txf702 = xchg->stgwdbemonitor.username;
	contiac.Txf703 = xchg->stgwdbemonitor.password;
	contiac.Txf704 = xchg->stgwdbemonitor.ip;
	contiac.Txf705 = to_string(xchg->stgwdbemonitor.port);
	contiac.numFPup706 = feedFPup706.getNumByIx(xchg->stgwdbemonitor.ixDbsVDbstype);
	contiac.Txf707 = xchg->stgwdbemonitor.dbspath;
	contiac.Txf708 = xchg->stgwdbemonitor.dbsname;
	contiac.Txf709 = xchg->stgwdbemonitor.dbsusername;
	contiac.Txf710 = xchg->stgwdbemonitor.dbspassword;

	if (_refresh) {
		refresh(dbswdbe, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWdbe* PnlWdbePrfDaemon::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFPup402, &feedFPup706, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbePrfDaemon::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.Txf2Clean = (contiac.Txf2 == to_string(xchg->stgwdbebehavior.histlength));
	statshr.Chk3Clean = (contiac.Chk3 == xchg->stgwdbebehavior.suspsess);
	statshr.Txf4Clean = (contiac.Txf4 == to_string(xchg->stgwdbebehavior.sesstterm));
	statshr.Txf5Clean = (contiac.Txf5 == to_string(xchg->stgwdbebehavior.sesstwarn));
	statshr.Txf6Clean = (contiac.Txf6 == to_string(xchg->stgwdbebehavior.roottterm));

	statshr.Txf102Clean = (contiac.Txf102 == to_string(xchg->stgwdbeappsrv.port));
	statshr.Chk103Clean = (contiac.Chk103 == xchg->stgwdbeappsrv.https);
	statshr.Txf104Clean = (contiac.Txf104 == xchg->stgwdbeappsrv.cors);

	statshr.Sep2Avail = evalSep2Avail(dbswdbe);
	statshr.Hdg201Avail = evalHdg201Avail(dbswdbe);
	statshr.Txf202Avail = evalTxf202Avail(dbswdbe);
	statshr.Txf203Avail = evalTxf203Avail(dbswdbe);
	statshr.Chk204Avail = evalChk204Avail(dbswdbe);

#ifdef WDBED
	statshr.Txf202Clean = (contiac.Txf202 == to_string(xchg->stgwdbed.jobprcn));
	statshr.Txf203Clean = (contiac.Txf203 == to_string(xchg->stgwdbed.opengsrvport));
	statshr.Chk204Clean = (contiac.Chk204 == xchg->stgwdbed.appsrv);
#endif

	statshr.Sep3Avail = evalSep3Avail(dbswdbe);
	statshr.Hdg301Avail = evalHdg301Avail(dbswdbe);
	statshr.Txf302Avail = evalTxf302Avail(dbswdbe);
	statshr.Txf303Avail = evalTxf303Avail(dbswdbe);
	statshr.Chk304Avail = evalChk304Avail(dbswdbe);

#ifdef WDBECMBD
	statshr.Txf302Clean = (contiac.Txf302 == to_string(xchg->stgwdbecmbd.jobprcn));
	statshr.Txf303Clean = (contiac.Txf303 == to_string(xchg->stgwdbecmbd.opprcn));
	statshr.Chk304Clean = (contiac.Chk304 == xchg->stgwdbecmbd.appsrv);
#endif

	statshr.Pup402Clean = (contiac.numFPup402 == feedFPup402.getNumByIx(xchg->stgwdbedatabase.ixDbsVDbstype));
	statshr.Txf403Clean = (contiac.Txf403 == xchg->stgwdbedatabase.dbspath);
	statshr.Txf404Clean = (contiac.Txf404 == xchg->stgwdbedatabase.dbsname);
	statshr.Txf405Clean = (contiac.Txf405 == xchg->stgwdbedatabase.username);
	statshr.Txf406Clean = (contiac.Txf406 == xchg->stgwdbedatabase.password);
	statshr.Txf407Clean = (contiac.Txf407 == xchg->stgwdbedatabase.ip);
	statshr.Txf408Clean = (contiac.Txf408 == to_string(xchg->stgwdbedatabase.port));

	statshr.Txf502Clean = (contiac.Txf502 == xchg->stgwdbepath.acvpath);
	statshr.Txf503Clean = (contiac.Txf503 == xchg->stgwdbepath.keypath);
	statshr.Txf504Clean = (contiac.Txf504 == xchg->stgwdbepath.monpath);
	statshr.Txf505Clean = (contiac.Txf505 == xchg->stgwdbepath.tmppath);
	statshr.Txf506Clean = (contiac.Txf506 == xchg->stgwdbepath.webpath);
	statshr.Txf507Clean = (contiac.Txf507 == xchg->stgwdbepath.helpurl);

	statshr.Txf602Clean = (contiac.Txf602 == xchg->stgwdbetenant.orgname);
	statshr.Txf603Clean = (contiac.Txf603 == xchg->stgwdbetenant.orgweb);

	statshr.Txf702Clean = (contiac.Txf702 == xchg->stgwdbemonitor.username);
	statshr.Txf703Clean = (contiac.Txf703 == xchg->stgwdbemonitor.password);
	statshr.Txf704Clean = (contiac.Txf704 == xchg->stgwdbemonitor.ip);
	statshr.Txf705Clean = (contiac.Txf705 == to_string(xchg->stgwdbemonitor.port));
	statshr.Pup706Clean = (contiac.numFPup706 == feedFPup706.getNumByIx(xchg->stgwdbemonitor.ixDbsVDbstype));
	statshr.Txf707Clean = (contiac.Txf707 == xchg->stgwdbemonitor.dbspath);
	statshr.Txf708Clean = (contiac.Txf708 == xchg->stgwdbemonitor.dbsname);
	statshr.Txf709Clean = (contiac.Txf709 == xchg->stgwdbemonitor.dbsusername);
	statshr.Txf710Clean = (contiac.Txf710 == xchg->stgwdbemonitor.dbspassword);

	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbePrfDaemon::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
			handleDpchAppWdbeInit(dbswdbe, (DpchAppWdbeInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbePrfDaemon::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePrfDaemon::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;
	if (has(diffitems, ContIac::CHK3)) contiac.Chk3 = _contiac->Chk3;
	if (has(diffitems, ContIac::TXF4)) contiac.Txf4 = _contiac->Txf4;
	if (has(diffitems, ContIac::TXF5)) contiac.Txf5 = _contiac->Txf5;
	if (has(diffitems, ContIac::TXF6)) contiac.Txf6 = _contiac->Txf6;

	if (has(diffitems, ContIac::TXF102)) contiac.Txf102 = _contiac->Txf102;
	if (has(diffitems, ContIac::CHK103)) contiac.Chk103 = _contiac->Chk103;
	if (has(diffitems, ContIac::TXF104)) contiac.Txf104 = _contiac->Txf104;

	if (has(diffitems, ContIac::TXF202)) contiac.Txf202 = _contiac->Txf202;
	if (has(diffitems, ContIac::TXF203)) contiac.Txf203 = _contiac->Txf203;
	if (has(diffitems, ContIac::CHK204)) contiac.Chk204 = _contiac->Chk204;

	if (has(diffitems, ContIac::TXF302)) contiac.Txf302 = _contiac->Txf302;
	if (has(diffitems, ContIac::TXF303)) contiac.Txf303 = _contiac->Txf303;
	if (has(diffitems, ContIac::CHK304)) contiac.Chk304 = _contiac->Chk304;

	if (has(diffitems, ContIac::NUMFPUP402)) {
		if (feedFPup402.getIxByNum(_contiac->numFPup402) != 0) contiac.numFPup402 = _contiac->numFPup402;
		else contiac.numFPup402 = 1;
	};
	if (has(diffitems, ContIac::TXF403)) contiac.Txf403 = _contiac->Txf403;
	if (has(diffitems, ContIac::TXF404)) contiac.Txf404 = _contiac->Txf404;
	if (has(diffitems, ContIac::TXF405)) contiac.Txf405 = _contiac->Txf405;
	if (has(diffitems, ContIac::TXF406)) contiac.Txf406 = _contiac->Txf406;
	if (has(diffitems, ContIac::TXF407)) contiac.Txf407 = _contiac->Txf407;
	if (has(diffitems, ContIac::TXF408)) contiac.Txf408 = _contiac->Txf408;

	if (has(diffitems, ContIac::TXF502)) contiac.Txf502 = _contiac->Txf502;
	if (has(diffitems, ContIac::TXF503)) contiac.Txf503 = _contiac->Txf503;
	if (has(diffitems, ContIac::TXF504)) contiac.Txf504 = _contiac->Txf504;
	if (has(diffitems, ContIac::TXF505)) contiac.Txf505 = _contiac->Txf505;
	if (has(diffitems, ContIac::TXF506)) contiac.Txf506 = _contiac->Txf506;
	if (has(diffitems, ContIac::TXF507)) contiac.Txf507 = _contiac->Txf507;

	if (has(diffitems, ContIac::TXF602)) contiac.Txf602 = _contiac->Txf602;
	if (has(diffitems, ContIac::TXF603)) contiac.Txf603 = _contiac->Txf603;

	if (has(diffitems, ContIac::TXF702)) contiac.Txf702 = _contiac->Txf702;
	if (has(diffitems, ContIac::TXF703)) contiac.Txf703 = _contiac->Txf703;
	if (has(diffitems, ContIac::TXF704)) contiac.Txf704 = _contiac->Txf704;
	if (has(diffitems, ContIac::TXF705)) contiac.Txf705 = _contiac->Txf705;
	if (has(diffitems, ContIac::NUMFPUP706)) {
		if (feedFPup706.getIxByNum(_contiac->numFPup706) != 0) contiac.numFPup706 = _contiac->numFPup706;
		else contiac.numFPup706 = 1;
	};
	if (has(diffitems, ContIac::TXF707)) contiac.Txf707 = _contiac->Txf707;
	if (has(diffitems, ContIac::TXF708)) contiac.Txf708 = _contiac->Txf708;
	if (has(diffitems, ContIac::TXF709)) contiac.Txf709 = _contiac->Txf709;
	if (has(diffitems, ContIac::TXF710)) contiac.Txf710 = _contiac->Txf710;

	if (!diffitems.empty()) refresh(dbswdbe, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbePrfDaemon::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWdbeVExpstate = VecWdbeVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWdbePrfDaemon::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
