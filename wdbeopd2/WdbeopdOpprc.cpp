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
				if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu") req->dpchret = WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
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
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
				if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstPmmu_v1_0") req->dpchret = WdbeMtpGenfstPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstSpifwd_v1_0") req->dpchret = WdbeMtpGenfstSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu") req->dpchret = WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD) {
				if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdinv_v1_0") req->dpchret = WdbeMtpCplmsttdCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdret_v1_0") req->dpchret = WdbeMtpCplmsttdCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDpbram_v1_0") req->dpchret = WdbeMtpCplmsttdDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdPmmu_v1_0") req->dpchret = WdbeMtpCplmsttdPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdSpbram_v1_0") req->dpchret = WdbeMtpCplmsttdSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_lttc_v1_0") req->dpchret = WdbeMtpCplmsttdTop_lttc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_mchp_v1_0") req->dpchret = WdbeMtpCplmsttdTop_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_xlnx_v1_0") req->dpchret = WdbeMtpCplmsttdTop_xlnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU) {
				if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAdd_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuAdd_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAxihostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuAxihostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAxihostif_Easy_v2_0") req->dpchret = WdbeMtpCplmstbuAxihostif_Easy_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAxihostif_v1_0") req->dpchret = WdbeMtpCplmstbuAxihostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCmdinv_v1_0") req->dpchret = WdbeMtpCplmstbuCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCmdret_v1_0") req->dpchret = WdbeMtpCplmstbuCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDft_xlnx_v4_0") req->dpchret = WdbeMtpCplmstbuDft_xlnx_v4_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDiv_xlnx_v3_0") req->dpchret = WdbeMtpCplmstbuDiv_xlnx_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDiv_xlnx_v5_1") req->dpchret = WdbeMtpCplmstbuDiv_xlnx_v5_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDotmx2x16_v1_0") req->dpchret = WdbeMtpCplmstbuDotmx2x16_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_v1_0") req->dpchret = WdbeMtpCplmstbuDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_xlnx_v8_4") req->dpchret = WdbeMtpCplmstbuDpbram_xlnx_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpsram_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuDpsram_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB") req->dpchret = WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aPlusDPlusC") req->dpchret = WdbeMtpCplmstbuDsp48_xlnx_v3_0_aPlusDPlusC::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx") req->dpchret = WdbeMtpCplmstbuIod_mchp_v1_0_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipidec_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuMipidec_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMpfs_ip_AXI_v1_0") req->dpchret = WdbeMtpCplmstbuMpfs_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMult_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuMult_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuOled128x32_v1_0") req->dpchret = WdbeMtpCplmstbuOled128x32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuPmmu_v1_0") req->dpchret = WdbeMtpCplmstbuPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipicsi") req->dpchret = WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipicsi::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx") req->dpchret = WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpbram_v1_0") req->dpchret = WdbeMtpCplmstbuSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpifwd_v1_0") req->dpchret = WdbeMtpCplmstbuSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpihostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuSpihostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpihostif_v1_0") req->dpchret = WdbeMtpCplmstbuSpihostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSub_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuSub_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTop_lttc_v1_0") req->dpchret = WdbeMtpCplmstbuTop_lttc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTop_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuTop_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTop_xlnx_v1_0") req->dpchret = WdbeMtpCplmstbuTop_xlnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTpsram_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuTpsram_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarthostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuUarthostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarthostif_v1_0") req->dpchret = WdbeMtpCplmstbuUarthostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUartrx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUartrx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarttx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUarttx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuXadc_xlnx_v3_3") req->dpchret = WdbeMtpCplmstbuXadc_xlnx_v3_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuZynq_ip_AXI_v1_0") req->dpchret = WdbeMtpCplmstbuZynq_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuZynq_ip_AXI_v2_0") req->dpchret = WdbeMtpCplmstbuZynq_ip_AXI_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
				if (((DpchInvWdbeMtpPlhmcu*) req->dpchinv)->srefKCustop == "WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhmcu*) req->dpchinv);
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

	pthread_cleanup_pop(1);

	return(NULL);
};

void WdbeopdOpprc::cleanup(
			void* arg
		) {
	XchgWdbeopd* xchg = (XchgWdbeopd*) arg;

	xchg->cOpprcs.unlockMutex("WdbeopdOpprc", "cleanup");
};
