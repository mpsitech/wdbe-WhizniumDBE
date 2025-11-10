/**
	* \file PnlWdbePrfLicense.cpp
	* job handler for job PnlWdbePrfLicense (implementation)
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

#include "PnlWdbePrfLicense.h"

#include "PnlWdbePrfLicense_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePrfLicense
 ******************************************************************************/

PnlWdbePrfLicense::PnlWdbePrfLicense(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPRFLICENSE, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	setPref(dbswdbe); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWdbePrfLicense::~PnlWdbePrfLicense() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWdbePrfLicense::getPref(
			JobWdbeLicense::Stg*& _stgjobwdbelicense
		) {
	if (!(statshr.Txf1Clean && statshr.Txf2Clean && statshr.Txf3Clean && statshr.Txf4Clean && statshr.Txf5Clean && statshr.Txf6Clean && statshr.Txf7Clean && statshr.Txf8Clean && statshr.Txf9Clean && statshr.Txf10Clean)) {
		_stgjobwdbelicense = &stgjobwdbelicense;
		stgjobwdbelicense.engip = contiac.Txf1;
		stgjobwdbelicense.engport = atol(contiac.Txf2.c_str());
		stgjobwdbelicense.username = contiac.Txf3;
		stgjobwdbelicense.password = contiac.Txf4;
		stgjobwdbelicense.licenseBase = contiac.Txf5;
		stgjobwdbelicense.licenseFull = contiac.Txf6;
		stgjobwdbelicense.licenseTpl = contiac.Txf7;
		stgjobwdbelicense.lastAttempt = contiac.Txf8;
		stgjobwdbelicense.lastSuccess = contiac.Txf9;
		stgjobwdbelicense.lastSync = contiac.Txf10;
	};

};

void PnlWdbePrfLicense::setPref(
			DbsWdbe* dbswdbe
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Txf1 = JobWdbeLicense::stg.engip;
	contiac.Txf2 = to_string(JobWdbeLicense::stg.engport);
	contiac.Txf3 = JobWdbeLicense::stg.username;
	contiac.Txf4 = JobWdbeLicense::stg.password;
	contiac.Txf5 = JobWdbeLicense::stg.licenseBase;
	contiac.Txf6 = JobWdbeLicense::stg.licenseFull;
	contiac.Txf7 = JobWdbeLicense::stg.licenseTpl;
	contiac.Txf8 = JobWdbeLicense::stg.lastAttempt;
	contiac.Txf9 = JobWdbeLicense::stg.lastSuccess;
	contiac.Txf10 = JobWdbeLicense::stg.lastSync;

	if (_refresh) {
		refresh(dbswdbe, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWdbe* PnlWdbePrfLicense::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbePrfLicense::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- BEGIN
	// statshr
	statshr.Txf1Clean = (contiac.Txf1 == JobWdbeLicense::stg.engip);
	statshr.Txf2Clean = (contiac.Txf2 == to_string(JobWdbeLicense::stg.engport));
	statshr.Txf3Clean = (contiac.Txf3 == JobWdbeLicense::stg.username);
	statshr.Txf4Clean = (contiac.Txf4 == JobWdbeLicense::stg.password);
	statshr.Txf5Clean = (contiac.Txf5 == JobWdbeLicense::stg.licenseBase);
	statshr.Txf6Clean = (contiac.Txf6 == JobWdbeLicense::stg.licenseFull);
	statshr.Txf7Clean = (contiac.Txf7 == JobWdbeLicense::stg.licenseTpl);
	statshr.Txf8Clean = (contiac.Txf8 == JobWdbeLicense::stg.lastAttempt);
	statshr.Txf9Clean = (contiac.Txf9 == JobWdbeLicense::stg.lastSuccess);
	statshr.Txf10Clean = (contiac.Txf10 == JobWdbeLicense::stg.lastSync);

	// IP refresh --- END

	muteRefresh = false;
};

void PnlWdbePrfLicense::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDO) {
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

void PnlWdbePrfLicense::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePrfLicense::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::TXF1)) contiac.Txf1 = _contiac->Txf1;
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;
	if (has(diffitems, ContIac::TXF3)) contiac.Txf3 = _contiac->Txf3;
	if (has(diffitems, ContIac::TXF4)) contiac.Txf4 = _contiac->Txf4;
	if (has(diffitems, ContIac::TXF5)) contiac.Txf5 = _contiac->Txf5;
	if (has(diffitems, ContIac::TXF6)) contiac.Txf6 = _contiac->Txf6;
	if (has(diffitems, ContIac::TXF7)) contiac.Txf7 = _contiac->Txf7;
	if (has(diffitems, ContIac::TXF8)) contiac.Txf8 = _contiac->Txf8;
	if (has(diffitems, ContIac::TXF9)) contiac.Txf9 = _contiac->Txf9;
	if (has(diffitems, ContIac::TXF10)) contiac.Txf10 = _contiac->Txf10;

	if (!diffitems.empty()) refresh(dbswdbe, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbePrfLicense::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWdbeVExpstate = VecWdbeVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWdbePrfLicense::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
