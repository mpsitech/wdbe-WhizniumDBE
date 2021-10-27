/**
	* \file WdbeopdOpprc.cpp
	* operation processor for Wdbe operation daemon wdbeopd1 (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTCTRECTR) {
				req->dpchret = WdbeCplmstCtrEctr::run(xchg, &dbswdbe, (DpchInvWdbeCplmstCtrEctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTFWDCTR) {
				req->dpchret = WdbeCplmstFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeCplmstFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTIMBUF) {
				req->dpchret = WdbeCplmstImbuf::run(xchg, &dbswdbe, (DpchInvWdbeCplmstImbuf*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTSYS) {
				req->dpchret = WdbeCplmstSys::run(xchg, &dbswdbe, (DpchInvWdbeCplmstSys*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTTPLCPY) {
				req->dpchret = WdbeCplmstTplcpy::run(xchg, &dbswdbe, (DpchInvWdbeCplmstTplcpy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTUNT) {
				req->dpchret = WdbeCplmstUnt::run(xchg, &dbswdbe, (DpchInvWdbeCplmstUnt*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENSTDVEC) {
				req->dpchret = WdbeGenStdvec::run(xchg, &dbswdbe, (DpchInvWdbeGenStdvec*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENTEST) {
				req->dpchret = WdbeGenTest::run(xchg, &dbswdbe, (DpchInvWdbeGenTest*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENWIRING) {
				req->dpchret = WdbeGenWiring::run(xchg, &dbswdbe, (DpchInvWdbeGenWiring*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCMDBUS) {
				req->dpchret = WdbeGenfstCmdbus::run(xchg, &dbswdbe, (DpchInvWdbeGenfstCmdbus*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCTRFWDCTR) {
				req->dpchret = WdbeGenfstCtrFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeGenfstCtrFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTECTR) {
				req->dpchret = WdbeGenfstEctr::run(xchg, &dbswdbe, (DpchInvWdbeGenfstEctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTEHOSTIF) {
				req->dpchret = WdbeGenfstEhostif::run(xchg, &dbswdbe, (DpchInvWdbeGenfstEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTHOSTIF) {
				req->dpchret = WdbeGenfstHostif::run(xchg, &dbswdbe, (DpchInvWdbeGenfstHostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTIMBUF) {
				req->dpchret = WdbeGenfstImbuf::run(xchg, &dbswdbe, (DpchInvWdbeGenfstImbuf*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTPPL) {
				req->dpchret = WdbeGenfstPpl::run(xchg, &dbswdbe, (DpchInvWdbeGenfstPpl*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTTOP) {
				req->dpchret = WdbeGenfstTop::run(xchg, &dbswdbe, (DpchInvWdbeGenfstTop*) req->dpchinv);
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUECTR) {
				req->dpchret = WdbePlhmcuEctr::run(xchg, &dbswdbe, (DpchInvWdbePlhmcuEctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF) {
				req->dpchret = WdbePlhmcuEhostif::run(xchg, &dbswdbe, (DpchInvWdbePlhmcuEhostif*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILECONCAT) {
				req->dpchret = WdbePrcfileConcat::run(xchg, &dbswdbe, (DpchInvWdbePrcfileConcat*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILEPLHRPL) {
				req->dpchret = WdbePrcfilePlhrpl::run(xchg, &dbswdbe, (DpchInvWdbePrcfilePlhrpl*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEEXTRACT) {
				req->dpchret = WdbePrctreeExtract::run(xchg, &dbswdbe, (DpchInvWdbePrctreeExtract*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEMERGE) {
				req->dpchret = WdbePrctreeMerge::run(xchg, &dbswdbe, (DpchInvWdbePrctreeMerge*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEVALIDATE) {
				req->dpchret = WdbePrctreeValidate::run(xchg, &dbswdbe, (DpchInvWdbePrctreeValidate*) req->dpchinv);
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
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGATOP) {
				req->dpchret = WdbeWrfpgaTop::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaTop*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUBASE) {
				req->dpchret = WdbeWrmcuBase::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUCTRFWDCTR) {
				req->dpchret = WdbeWrmcuCtrFwdctr::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuCtrFwdctr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUDEPLOY) {
				req->dpchret = WdbeWrmcuDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLFINE) {
				req->dpchret = WdbeWrmcuMdlfine::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlfine*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLRAW) {
				req->dpchret = WdbeWrmcuMdlraw::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlraw*) req->dpchinv);
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

	pthread_cleanup_pop(1);

	return(NULL);
};

void WdbeopdOpprc::cleanup(
			void* arg
		) {
	XchgWdbeopd* xchg = (XchgWdbeopd*) arg;

	xchg->cOpprcs.unlockMutex("WdbeopdOpprc", "cleanup");
};
