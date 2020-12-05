/**
	* \file WdbeopdOpprc.cpp
	* operation processor for Wdbe operation daemon wdbeopd2 (implementation)
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA) {
				if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdbus_v1_0") req->dpchret = WdbeMtpWrfpgaCmdbus_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdinv_v1_0") req->dpchret = WdbeMtpWrfpgaCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdret_v1_0") req->dpchret = WdbeMtpWrfpgaCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_32_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaDpbram_v1_0") req->dpchret = WdbeMtpWrfpgaDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaPmmu_v1_0") req->dpchret = WdbeMtpWrfpgaPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaSpbram_v1_0") req->dpchret = WdbeMtpWrfpgaSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaSpifwd_v1_0") req->dpchret = WdbeMtpWrfpgaSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaTkclksrc_v1_0") req->dpchret = WdbeMtpWrfpgaTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaTop_v1_0") req->dpchret = WdbeMtpWrfpgaTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPMODDET) {
				if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetPmmu_v1_0") req->dpchret = WdbeMtpModdetPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetSpifwd_v1_0") req->dpchret = WdbeMtpModdetSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetTkclksrc_v1_0") req->dpchret = WdbeMtpModdetTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetTop_v1_0") req->dpchret = WdbeMtpModdetTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPMODBSCTD) {
				if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdCmdinv_v1_0") req->dpchret = WdbeMtpModbsctdCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdCmdret_v1_0") req->dpchret = WdbeMtpModbsctdCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdDpbram_v1_0") req->dpchret = WdbeMtpModbsctdDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdPmmu_v1_0") req->dpchret = WdbeMtpModbsctdPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdSpbram_v1_0") req->dpchret = WdbeMtpModbsctdSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPMODBSCBU) {
				if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuAdd_v12_0") req->dpchret = WdbeMtpModbscbuAdd_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuAxihostif_Easy_v1_0") req->dpchret = WdbeMtpModbscbuAxihostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuAxihostif_Easy_v2_0") req->dpchret = WdbeMtpModbscbuAxihostif_Easy_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuAxihostif_v1_0") req->dpchret = WdbeMtpModbscbuAxihostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuCmdinv_v1_0") req->dpchret = WdbeMtpModbscbuCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuCmdret_v1_0") req->dpchret = WdbeMtpModbscbuCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDft_v4_0") req->dpchret = WdbeMtpModbscbuDft_v4_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDiv_v3_0") req->dpchret = WdbeMtpModbscbuDiv_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDiv_v5_1") req->dpchret = WdbeMtpModbscbuDiv_v5_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDotmx2x16_v1_0") req->dpchret = WdbeMtpModbscbuDotmx2x16_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDpbram_v1_0") req->dpchret = WdbeMtpModbscbuDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDpbram_v8_4") req->dpchret = WdbeMtpModbscbuDpbram_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDsp48_v3_0_aMultB") req->dpchret = WdbeMtpModbscbuDsp48_v3_0_aMultB::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC") req->dpchret = WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuMult_v12_0") req->dpchret = WdbeMtpModbscbuMult_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuOled128x32_v1_0") req->dpchret = WdbeMtpModbscbuOled128x32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuPmmu_v1_0") req->dpchret = WdbeMtpModbscbuPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuSpbram_v1_0") req->dpchret = WdbeMtpModbscbuSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuSpifwd_v1_0") req->dpchret = WdbeMtpModbscbuSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuSpihostif_Easy_v1_0") req->dpchret = WdbeMtpModbscbuSpihostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuSpihostif_v1_0") req->dpchret = WdbeMtpModbscbuSpihostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuSub_v12_0") req->dpchret = WdbeMtpModbscbuSub_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuUarthostif_Easy_v1_0") req->dpchret = WdbeMtpModbscbuUarthostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuUarthostif_v1_0") req->dpchret = WdbeMtpModbscbuUarthostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuXadc_v3_3") req->dpchret = WdbeMtpModbscbuXadc_v3_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuZynq_ip_AXI_v1_0") req->dpchret = WdbeMtpModbscbuZynq_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuZynq_ip_AXI_v2_0") req->dpchret = WdbeMtpModbscbuZynq_ip_AXI_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbscbu*) req->dpchinv)->srefKCustop == "WdbeMtpModbscbuZynq_ip_v1_0") req->dpchret = WdbeMtpModbscbuZynq_ip_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbscbu*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
				if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaPmmu_v1_0") req->dpchret = WdbeMtpPlhfpgaPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
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




