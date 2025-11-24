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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
				if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaCohostif_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaCohostif_v1_0") req->dpchret = WdbeMtpPlhfpgaCohostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaCrcspec_v2_0") req->dpchret = WdbeMtpPlhfpgaCrcspec_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaCrcspec_v3_0") req->dpchret = WdbeMtpPlhfpgaCrcspec_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaGptrack_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaHostif_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaHostif_v1_0") req->dpchret = WdbeMtpPlhfpgaHostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaIdent_Easy_v1_0") req->dpchret = WdbeMtpPlhfpgaIdent_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaOscoll_v1_0") req->dpchret = WdbeMtpPlhfpgaOscoll_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU) {
				if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAximmcohostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuAximmcohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAxislave_v1_0") req->dpchret = WdbeMtpCplmstbuAxislave_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCmdinv_v2_0") req->dpchret = WdbeMtpCplmstbuCmdinv_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCmdret_v2_0") req->dpchret = WdbeMtpCplmstbuCmdret_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCmult_xlnx_v6_0") req->dpchret = WdbeMtpCplmstbuCmult_xlnx_v6_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCohostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCohostif_v1_0") req->dpchret = WdbeMtpCplmstbuCohostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCrcspec_v2_0") req->dpchret = WdbeMtpCplmstbuCrcspec_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCrcspec_v3_0") req->dpchret = WdbeMtpCplmstbuCrcspec_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3") req->dpchret = WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDdrmux_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDft_xlnx_v4_0") req->dpchret = WdbeMtpCplmstbuDft_xlnx_v4_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDiv_xlnx_v3_0") req->dpchret = WdbeMtpCplmstbuDiv_xlnx_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDiv_xlnx_v5_1") req->dpchret = WdbeMtpCplmstbuDiv_xlnx_v5_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDotmx2x16_v1_0") req->dpchret = WdbeMtpCplmstbuDotmx2x16_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_efnx_v6_1") req->dpchret = WdbeMtpCplmstbuDpbram_efnx_v6_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_v1_0") req->dpchret = WdbeMtpCplmstbuDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_xlnx_v8_4") req->dpchret = WdbeMtpCplmstbuDpbram_xlnx_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpebram_lttc_v1_2") req->dpchret = WdbeMtpCplmstbuDpebram_lttc_v1_2::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDphy_rx_lttc_v1_4_csi") req->dpchret = WdbeMtpCplmstbuDphy_rx_lttc_v1_4_csi::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpram_efnx_v1_0") req->dpchret = WdbeMtpCplmstbuDpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpsram_mchp_v1_1_110") req->dpchret = WdbeMtpCplmstbuDpsram_mchp_v1_1_110::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuEbrom_lttc_v1_3") req->dpchret = WdbeMtpCplmstbuEbrom_lttc_v1_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuEFX_DPRAM10") req->dpchret = WdbeMtpCplmstbuEFX_DPRAM10::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuEFX_RAM10") req->dpchret = WdbeMtpCplmstbuEFX_RAM10::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuFifo_lttc_v1_3") req->dpchret = WdbeMtpCplmstbuFifo_lttc_v1_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuFsmprobe_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuFsmprobe_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuGpio_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuGptrack_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuHostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuHostif_v1_0") req->dpchret = WdbeMtpCplmstbuHostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuI2cmaster_v1_0") req->dpchret = WdbeMtpCplmstbuI2cmaster_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuI2c_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuI2c_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIdent_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuIdent_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx") req->dpchret = WdbeMtpCplmstbuIod_mchp_v1_0_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIrq_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuIrq_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipidec_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuMipidec_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipirx_xlnx_v5_1") req->dpchret = WdbeMtpCplmstbuMipirx_xlnx_v5_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMult_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuMult_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuOled128x32_v1_0") req->dpchret = WdbeMtpCplmstbuOled128x32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuOscoll_v1_0") req->dpchret = WdbeMtpCplmstbuOscoll_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx") req->dpchret = WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSmartreg_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuSmartreg_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSmartreg_v1_0") req->dpchret = WdbeMtpCplmstbuSmartreg_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpbram_efnx_v6_1") req->dpchret = WdbeMtpCplmstbuSpbram_efnx_v6_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpbram_v1_0") req->dpchret = WdbeMtpCplmstbuSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpbram_xlnx_v8_4") req->dpchret = WdbeMtpCplmstbuSpbram_xlnx_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpebram_lttc_v1_4") req->dpchret = WdbeMtpCplmstbuSpebram_lttc_v1_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpram_efnx_v1_0") req->dpchret = WdbeMtpCplmstbuSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuToc_v1_0") req->dpchret = WdbeMtpCplmstbuToc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTop_v1_0") req->dpchret = WdbeMtpCplmstbuTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTpsram_mchp_v1_1_108") req->dpchret = WdbeMtpCplmstbuTpsram_mchp_v1_1_108::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUartrx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUartrx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarttx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUarttx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUart_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuUart_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuXadc_xlnx_v3_3") req->dpchret = WdbeMtpCplmstbuXadc_xlnx_v3_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuXfft_xlnx_v9_1") req->dpchret = WdbeMtpCplmstbuXfft_xlnx_v9_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD) {
				if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdinv_v2_0") req->dpchret = WdbeMtpCplmsttdCmdinv_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdret_v2_0") req->dpchret = WdbeMtpCplmsttdCmdret_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCohostif_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCohostif_v1_0") req->dpchret = WdbeMtpCplmsttdCohostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDdrmux_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDpbram_v1_0") req->dpchret = WdbeMtpCplmsttdDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDpram_efnx_v1_0") req->dpchret = WdbeMtpCplmsttdDpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdGpio_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdGptrack_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdHostif_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdHostif_v1_0") req->dpchret = WdbeMtpCplmsttdHostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdI2cmaster_v1_0") req->dpchret = WdbeMtpCplmsttdI2cmaster_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdSpbram_v1_0") req->dpchret = WdbeMtpCplmsttdSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdSpram_efnx_v1_0") req->dpchret = WdbeMtpCplmsttdSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_v1_0") req->dpchret = WdbeMtpCplmsttdTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
				if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstBtshuffle_v1_0") req->dpchret = WdbeMtpGenfstBtshuffle_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstCohostif_Easy_v1_0") req->dpchret = WdbeMtpGenfstCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstDdrmux_Easy_v1_0") req->dpchret = WdbeMtpGenfstDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpGenfstFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstGpio_Easy_v1_0") req->dpchret = WdbeMtpGenfstGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstGptrack_Easy_v1_0") req->dpchret = WdbeMtpGenfstGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstHostif_Easy_v1_0") req->dpchret = WdbeMtpGenfstHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_Easy_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUarthostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpGenfstUarthostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA) {
				if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaAximmcohostif_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaAximmcohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaBtshuffle_v1_0") req->dpchret = WdbeMtpWrfpgaBtshuffle_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdinv_v2_0") req->dpchret = WdbeMtpWrfpgaCmdinv_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdret_v2_0") req->dpchret = WdbeMtpWrfpgaCmdret_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCohostif_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCohostif_v1_0") req->dpchret = WdbeMtpWrfpgaCohostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_32_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v2_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v3_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaDdrmux_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaDpbram_v1_0") req->dpchret = WdbeMtpWrfpgaDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaDpram_efnx_v1_0") req->dpchret = WdbeMtpWrfpgaDpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaFsmprobe_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaFsmprobe_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaGpio_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaGptrack_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaHostif_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaHostif_v1_0") req->dpchret = WdbeMtpWrfpgaHostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaI2cmaster_v1_0") req->dpchret = WdbeMtpWrfpgaI2cmaster_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaIdent_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaIdent_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaIrq_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaIrq_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaSpbram_v1_0") req->dpchret = WdbeMtpWrfpgaSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaSpram_efnx_v1_0") req->dpchret = WdbeMtpWrfpgaSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaTkclksrc_v1_0") req->dpchret = WdbeMtpWrfpgaTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
				if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUarthostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpWrmcuUarthostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUsbhostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpWrmcuUsbhostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
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
