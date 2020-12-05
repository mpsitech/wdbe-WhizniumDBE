/**
	* \file WdbecmbdOpprc.cpp
	* operation processor for Wdbe combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbecmbd.h"

#include "WdbecmbdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbecmbdOpprc
 ******************************************************************************/

void* WdbecmbdOpprc::run(
			void* arg
		) {
	XchgWdbecmbd* xchg = (XchgWdbecmbd*) arg;

	ReqWdbe* req = NULL;
	DpchInvWdbe* inv = NULL;

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
				e.vals["object"] = "WdbecmbdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WdbecmbdOpprc", "run");

	try {
		// main loop: wait for operation invocations
		while (true) {
			xchg->cOpprcs.lockMutex("WdbecmbdOpprc", "run");
			inv = xchg->pullFirstInv();

			while (!inv) {
				xchg->cOpprcs.wait("WdbecmbdOpprc", "run");
				inv = xchg->pullFirstInv();
			};

			xchg->cOpprcs.unlockMutex("WdbecmbdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WdbecmbdOpprc", "run");

			// prepare request
			req = new ReqWdbe(ReqWdbe::VecVBasetype::DPCHRET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPMODBSCTD) {
				if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdCmdinv_v1_0") req->dpchret = WdbeMtpModbsctdCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdCmdret_v1_0") req->dpchret = WdbeMtpModbsctdCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdDpbram_v1_0") req->dpchret = WdbeMtpModbsctdDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdPmmu_v1_0") req->dpchret = WdbeMtpModbsctdPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
				else if (((DpchInvWdbeMtpModbsctd*) req->dpchinv)->srefKCustop == "WdbeMtpModbsctdSpbram_v1_0") req->dpchret = WdbeMtpModbsctdSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModbsctd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPMODDET) {
				if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetPmmu_v1_0") req->dpchret = WdbeMtpModdetPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetSpifwd_v1_0") req->dpchret = WdbeMtpModdetSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetTkclksrc_v1_0") req->dpchret = WdbeMtpModdetTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
				else if (((DpchInvWdbeMtpModdet*) req->dpchinv)->srefKCustop == "WdbeMtpModdetTop_v1_0") req->dpchret = WdbeMtpModdetTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpModdet*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
				if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaPmmu_v1_0") req->dpchret = WdbeMtpPlhfpgaPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF) {
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
			};
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

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
			};
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

void WdbecmbdOpprc::cleanup(
			void* arg
		) {
	XchgWdbecmbd* xchg = (XchgWdbecmbd*) arg;

	xchg->cOpprcs.unlockMutex("WdbecmbdOpprc", "cleanup");
};



