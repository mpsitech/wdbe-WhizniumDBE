/**
	* \file WdbeopdOpprc.cpp
	* operation processor for Wdbe operation daemon wdbeopd1 (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "Wdbeopd.h"

#include "WdbeopdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeopdOpprc
 ******************************************************************************/

void* WdbeopdOpprc::run(
			void* arg
		) {
	XchgWdbeopd* xchg = (XchgWdbeopd*) arg;

	ReqopWdbe* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWdbe dbswdbe;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswdbe.init(xchg->stgwdbedatabase.ixDbsVDbstype, xchg->stgwdbedatabase.dbspath, xchg->stgwdbedatabase.dbsname, xchg->stgwdbedatabase.ip
						, xchg->stgwdbedatabase.port, xchg->stgwdbedatabase.username, xchg->stgwdbedatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WdbeopdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WdbeopdOpprc", "run");

	try {
		// main loop: wait for ops in execution list
		while (true) {
			xchg->cOpprcs.lockMutex("WdbeopdOpprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cOpprcs.wait("WdbeopdOpprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cOpprcs.unlockMutex("WdbeopdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WdbeopdOpprc", "run");

			// perform op corresponding to req's invoc
			if (req->dpchinv) {
				// perform op
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUBASE) {
				req->dpchret = WdbeWrmcuBase::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUCTRFWDCTR) {
				req->dpchret = WdbeWrmcuCtrFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuCtrFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUDEPLOY) {
				req->dpchret = WdbeWrmcuDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUEHOSTIF) {
				req->dpchret = WdbeWrmcuEhostif::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLFINE) {
				req->dpchret = WdbeWrmcuMdlfine::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlfine*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLRAW) {
				req->dpchret = WdbeWrmcuMdlraw::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlraw*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGABASE) {
				req->dpchret = WdbeWrfpgaBase::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGACTRFWDCTR) {
				req->dpchret = WdbeWrfpgaCtrFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaCtrFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGADEPLOY) {
				req->dpchret = WdbeWrfpgaDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAEHOSTIF) {
				req->dpchret = WdbeWrfpgaEhostif::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAHOSTIF) {
				req->dpchret = WdbeWrfpgaHostif::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaHostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAIPCLR) {
				req->dpchret = WdbeWrfpgaIpclr::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaIpclr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLFINE) {
				req->dpchret = WdbeWrfpgaMdlfine::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaMdlfine*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW) {
				req->dpchret = WdbeWrfpgaMdlraw::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaMdlraw*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVBASE) {
				req->dpchret = WdbeWrdevBase::run(xchg, &dbswdbe, (DpchInvWdbeWrdevBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVCTR) {
				req->dpchret = WdbeWrdevCtr::run(xchg, &dbswdbe, (DpchInvWdbeWrdevCtr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVDEPLOY) {
				req->dpchret = WdbeWrdevDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrdevDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVSYS) {
				req->dpchret = WdbeWrdevSys::run(xchg, &dbswdbe, (DpchInvWdbeWrdevSys*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVUNT) {
				req->dpchret = WdbeWrdevUnt::run(xchg, &dbswdbe, (DpchInvWdbeWrdevUnt*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEEXTRACT) {
				req->dpchret = WdbePrctreeExtract::run(xchg, &dbswdbe, (DpchInvWdbePrctreeExtract*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEMERGE) {
				req->dpchret = WdbePrctreeMerge::run(xchg, &dbswdbe, (DpchInvWdbePrctreeMerge*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEVALIDATE) {
				req->dpchret = WdbePrctreeValidate::run(xchg, &dbswdbe, (DpchInvWdbePrctreeValidate*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILECONCAT) {
				req->dpchret = WdbePrcfileConcat::run(xchg, &dbswdbe, (DpchInvWdbePrcfileConcat*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILEIEXCONV) {
				req->dpchret = WdbePrcfileIexconv::run(xchg, &dbswdbe, (DpchInvWdbePrcfileIexconv*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILEPLHRPL) {
				req->dpchret = WdbePrcfilePlhrpl::run(xchg, &dbswdbe, (DpchInvWdbePrcfilePlhrpl*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF) {
				req->dpchret = WdbePlhmcuEhostif::run(xchg, &dbswdbe, (DpchInvWdbePlhmcuEhostif*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDINV) {
				req->dpchret = WdbePlhfpgaCmdinv::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaCmdinv*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDRET) {
				req->dpchret = WdbePlhfpgaCmdret::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaCmdret*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGAEHOSTIF) {
				req->dpchret = WdbePlhfpgaEhostif::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGAFWDCTR) {
				req->dpchret = WdbePlhfpgaFwdctr::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaFwdctr*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETCMDBUS) {
				req->dpchret = WdbeModdetCmdbus::run(xchg, &dbswdbe, (DpchInvWdbeModdetCmdbus*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETCTRFWDCTR) {
				req->dpchret = WdbeModdetCtrFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeModdetCtrFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETECTR) {
				req->dpchret = WdbeModdetEctr::run(xchg, &dbswdbe, (DpchInvWdbeModdetEctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETEHOSTIF) {
				req->dpchret = WdbeModdetEhostif::run(xchg, &dbswdbe, (DpchInvWdbeModdetEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETIMBUF) {
				req->dpchret = WdbeModdetImbuf::run(xchg, &dbswdbe, (DpchInvWdbeModdetImbuf*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETUNT) {
				req->dpchret = WdbeModdetUnt::run(xchg, &dbswdbe, (DpchInvWdbeModdetUnt*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODDETWIRING) {
				req->dpchret = WdbeModdetWiring::run(xchg, &dbswdbe, (DpchInvWdbeModdetWiring*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCCTRTD) {
				req->dpchret = WdbeModbscCtrtd::run(xchg, &dbswdbe, (DpchInvWdbeModbscCtrtd*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCFWDCTRTD) {
				req->dpchret = WdbeModbscFwdctrtd::run(xchg, &dbswdbe, (DpchInvWdbeModbscFwdctrtd*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCIMBUFTD) {
				req->dpchret = WdbeModbscImbuftd::run(xchg, &dbswdbe, (DpchInvWdbeModbscImbuftd*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCSYS) {
				req->dpchret = WdbeModbscSys::run(xchg, &dbswdbe, (DpchInvWdbeModbscSys*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCTPLCPY) {
				req->dpchret = WdbeModbscTplcpy::run(xchg, &dbswdbe, (DpchInvWdbeModbscTplcpy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMODBSCUNT) {
				req->dpchret = WdbeModbscUnt::run(xchg, &dbswdbe, (DpchInvWdbeModbscUnt*) req->dpchinv);
			};
			};

			req->setStateReply();
		};

	} catch (WdbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, VecWdbeVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void WdbeopdOpprc::cleanup(
			void* arg
		) {
	XchgWdbeopd* xchg = (XchgWdbeopd*) arg;

	xchg->cOpprcs.unlockMutex("WdbeopdOpprc", "cleanup");
};

