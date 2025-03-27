/**
	* \file WdbedJobprc.cpp
	* job processor for Wdbe daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbed.h"

#include "WdbedJobprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbedJobprc
 ******************************************************************************/

void* WdbedJobprc::run(
			void* arg
		) {
	XchgWdbed* xchg = (XchgWdbed*) arg;

	ReqWdbe* req = NULL;
	JobWdbe* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWdbe dbswdbe;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswdbe.init(xchg->stgwdbedatabase.ixDbsVDbstype, xchg->stgwdbedatabase.dbspath, xchg->stgwdbedatabase.dbsname, xchg->stgwdbedatabase.ip,
						xchg->stgwdbedatabase.port, xchg->stgwdbedatabase.username, xchg->stgwdbedatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WdbedJobprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WdbedJobprc", "run");

	try {
		// main loop: wait for requests
		while (true) {
			xchg->cJobprcs.lockMutex("WdbedJobprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cJobprcs.wait("WdbedJobprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cJobprcs.unlockMutex("WdbedJobprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cJobprcs.signal("WdbedJobprc", "run");

			// --- handle request
			if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
				xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

				// pass on to job
				accessJob(xchg, &dbswdbe, req);

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
				if (req->dpchapp) {
					//cout << "WdbedJobprc::run() DPCHAPP request: '" << VecWdbeVDpch::getSref(req->dpchapp->ixWdbeVDpch) << "'" << endl;
					eref = xchg->mon.eventHandleReqDpchapp(req->jref, VecWdbeVDpch::getSref(req->dpchapp->ixWdbeVDpch), req->dpchapp->getSrefsMask(), "");

					// pass on to job
					accessJob(xchg, &dbswdbe, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngWdbeAck(req->jref);
				xchg->mon.eventReplyReqDpchapp(eref, req->jref, VecWdbeVDpch::getSref(req->dpcheng->ixWdbeVDpch), req->dpcheng->getSrefsMask(), "");

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
				//cout << "WdbedJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
				xchg->mon.eventHandleReqUpload(req->jref, req->filename);

				// pass on to job
				accessJob(xchg, &dbswdbe, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
				eref = xchg->mon.eventHandleReqDownload(req->jref);

				// pass on to job
				accessJob(xchg, &dbswdbe, req);

				xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
				if (req->dpchret) {
					//cout << "WdbedJobprc::run() DPCHRET request: '" << VecWdbeVDpch::getSref(req->dpchret->ixWdbeVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					xchg->mon.eventHandleReqDpchret(req->jref, VecWdbeVDpch::getSref(req->dpchret->ixWdbeVDpch), "", req->dpchret->oref);

					accessJob(xchg, &dbswdbe, req);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::METHOD) {
				if (req->method) {
					//cout << "WdbedJobprc::run() METHOD request: '" << VecWdbeVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
					xchg->mon.eventHandleReqMethod(req->jref, VecWdbeVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

					// pass on to job
					accessJob(xchg, &dbswdbe, req);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);

				if (job) if (req->wref >= job->wrefMin) {
					xchg->mon.eventHandleReqTimer(req->jref, req->sref);
					accessJob(xchg, &dbswdbe, req);
				};

			} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::EXTCALL) {
				xchg->triggerCall(&dbswdbe, req->call);
			};

			if ((req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) || (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) || (req->ixVBasetype == ReqWdbe::VecVBasetype::EXTCALL)) {
				// ret, timer and extcall requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};

	} catch (WdbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(1);

	return(NULL);
};

void WdbedJobprc::cleanup(
			void* arg
		) {
	XchgWdbed* xchg = (XchgWdbed*) arg;

	xchg->cJobprcs.unlockMutex("WdbedJobprc", "cleanup");
};

void WdbedJobprc::accessJob(
			XchgWdbed* xchg
			, DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	time_t rawtime;

	JobWdbe* job = NULL;

	if ((req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) || (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) || (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) || (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD)) {
		if ((xchg->stgwdbebehavior.roottterm != 0) || (xchg->stgwdbebehavior.sesstterm != 0)) {
			time(&rawtime);
			xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, req->jref, VecWdbeVPreset::PREWDBETLAST, rawtime);
		};
	};

	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("WdbedJobprc", "accessJob");

		req->ixWdbeVLocale = job->ixWdbeVLocale;
		job->handleRequest(dbswdbe, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("WdbedJobprc", "accessJob");
	};
};
