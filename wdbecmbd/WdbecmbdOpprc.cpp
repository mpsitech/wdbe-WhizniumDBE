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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTCTRECTRHOSTIFEHOSTIF) {
				req->dpchret = WdbeCplmstCtrEctrHostifEhostif::run(xchg, &dbswdbe, (DpchInvWdbeCplmstCtrEctrHostifEhostif*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTIMBUF) {
				req->dpchret = WdbeCplmstImbuf::run(xchg, &dbswdbe, (DpchInvWdbeCplmstImbuf*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTTPLCPY) {
				req->dpchret = WdbeCplmstTplcpy::run(xchg, &dbswdbe, (DpchInvWdbeCplmstTplcpy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTUNT) {
				req->dpchret = WdbeCplmstUnt::run(xchg, &dbswdbe, (DpchInvWdbeCplmstUnt*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENAUX) {
				req->dpchret = WdbeGenAux::run(xchg, &dbswdbe, (DpchInvWdbeGenAux*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENSTDVEC) {
				req->dpchret = WdbeGenStdvec::run(xchg, &dbswdbe, (DpchInvWdbeGenStdvec*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENWIRING) {
				req->dpchret = WdbeGenWiring::run(xchg, &dbswdbe, (DpchInvWdbeGenWiring*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCMDBUS) {
				req->dpchret = WdbeGenfstCmdbus::run(xchg, &dbswdbe, (DpchInvWdbeGenfstCmdbus*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCTR) {
				req->dpchret = WdbeGenfstCtr::run(xchg, &dbswdbe, (DpchInvWdbeGenfstCtr*) req->dpchinv);
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU) {
				if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAdd_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuAdd_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuAximmcohostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuAximmcohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
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
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpbram_xlnx_v8_4") req->dpchret = WdbeMtpCplmstbuDpbram_xlnx_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpebram_lttc_v1_2") req->dpchret = WdbeMtpCplmstbuDpebram_lttc_v1_2::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDphy_rx_lttc_v1_4_csi") req->dpchret = WdbeMtpCplmstbuDphy_rx_lttc_v1_4_csi::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpram_efnx_v1_0") req->dpchret = WdbeMtpCplmstbuDpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDpsram_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuDpsram_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB") req->dpchret = WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aPlusDPlusC") req->dpchret = WdbeMtpCplmstbuDsp48_xlnx_v3_0_aPlusDPlusC::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
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
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuI2c_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuI2c_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuI2cmaster_v1_0") req->dpchret = WdbeMtpCplmstbuI2cmaster_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIdent_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuIdent_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx") req->dpchret = WdbeMtpCplmstbuIod_mchp_v1_0_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIrq_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuIrq_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipidec_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuMipidec_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipirx_xlnx_v5_1") req->dpchret = WdbeMtpCplmstbuMipirx_xlnx_v5_1::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMpfs_ip_AXI_v1_0") req->dpchret = WdbeMtpCplmstbuMpfs_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMult_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuMult_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuOled128x32_v1_0") req->dpchret = WdbeMtpCplmstbuOled128x32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx") req->dpchret = WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSmartreg_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuSmartreg_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSmartreg_v1_0") req->dpchret = WdbeMtpCplmstbuSmartreg_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpbram_xlnx_v8_4") req->dpchret = WdbeMtpCplmstbuSpbram_xlnx_v8_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpebram_lttc_v1_4") req->dpchret = WdbeMtpCplmstbuSpebram_lttc_v1_4::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSpram_efnx_v1_0") req->dpchret = WdbeMtpCplmstbuSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuSub_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuSub_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuToc_v1_0") req->dpchret = WdbeMtpCplmstbuToc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTop_v1_0") req->dpchret = WdbeMtpCplmstbuTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuTpsram_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuTpsram_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUart_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuUart_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUartrx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUartrx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarttx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUarttx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
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
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDpram_efnx_v1_0") req->dpchret = WdbeMtpCplmsttdDpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdGpio_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdGptrack_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdHostif_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdHostif_v1_0") req->dpchret = WdbeMtpCplmsttdHostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdI2cmaster_v1_0") req->dpchret = WdbeMtpCplmsttdI2cmaster_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdSpram_efnx_v1_0") req->dpchret = WdbeMtpCplmsttdSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_v1_0") req->dpchret = WdbeMtpCplmsttdTop_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
				if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstDdrmux_Easy_v1_0") req->dpchret = WdbeMtpGenfstDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstFsmtrack_Easy_v1_0") req->dpchret = WdbeMtpGenfstFsmtrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstGpio_Easy_v1_0") req->dpchret = WdbeMtpGenfstGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstGptrack_Easy_v1_0") req->dpchret = WdbeMtpGenfstGptrack_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstHostif_Easy_v1_0") req->dpchret = WdbeMtpGenfstHostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_Easy_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUarthostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpGenfstUarthostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
			};
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
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA) {
				if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaAximmcohostif_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaAximmcohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdinv_v2_0") req->dpchret = WdbeMtpWrfpgaCmdinv_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCmdret_v2_0") req->dpchret = WdbeMtpWrfpgaCmdret_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCohostif_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaCohostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCohostif_v1_0") req->dpchret = WdbeMtpWrfpgaCohostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_32_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v1_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v2_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaCrcspec_v3_0") req->dpchret = WdbeMtpWrfpgaCrcspec_v3_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaDdrmux_Easy_v1_0") req->dpchret = WdbeMtpWrfpgaDdrmux_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
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
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaSpram_efnx_v1_0") req->dpchret = WdbeMtpWrfpgaSpram_efnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrfpga*) req->dpchinv)->srefKCustop == "WdbeMtpWrfpgaTkclksrc_v1_0") req->dpchret = WdbeMtpWrfpgaTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
				if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUarthostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpWrmcuUarthostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUsbhostif_Easy_v2_0_Mcu") req->dpchret = WdbeMtpWrmcuUsbhostif_Easy_v2_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDINV) {
				req->dpchret = WdbePlhfpgaCmdinv::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaCmdinv*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDRET) {
				req->dpchret = WdbePlhfpgaCmdret::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaCmdret*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACTR) {
				req->dpchret = WdbePlhfpgaCtr::run(xchg, &dbswdbe, (DpchInvWdbePlhfpgaCtr*) req->dpchinv);
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
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVUNT) {
				req->dpchret = WdbeWrdevUnt::run(xchg, &dbswdbe, (DpchInvWdbeWrdevUnt*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAAUX) {
				req->dpchret = WdbeWrfpgaAux::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaAux*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGABASE) {
				req->dpchret = WdbeWrfpgaBase::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGACTR) {
				req->dpchret = WdbeWrfpgaCtr::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaCtr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGADEPLOY) {
				req->dpchret = WdbeWrfpgaDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLFINE) {
				req->dpchret = WdbeWrfpgaMdlfine::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaMdlfine*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW) {
				req->dpchret = WdbeWrfpgaMdlraw::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaMdlraw*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGATOP) {
				req->dpchret = WdbeWrfpgaTop::run(xchg, &dbswdbe, (DpchInvWdbeWrfpgaTop*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUBASE) {
				req->dpchret = WdbeWrmcuBase::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuBase*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUCTR) {
				req->dpchret = WdbeWrmcuCtr::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuCtr*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUDEPLOY) {
				req->dpchret = WdbeWrmcuDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLFINE) {
				req->dpchret = WdbeWrmcuMdlfine::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlfine*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLRAW) {
				req->dpchret = WdbeWrmcuMdlraw::run(xchg, &dbswdbe, (DpchInvWdbeWrmcuMdlraw*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRTERMDEPLOY) {
				req->dpchret = WdbeWrtermDeploy::run(xchg, &dbswdbe, (DpchInvWdbeWrtermDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRTERMMAIN) {
				req->dpchret = WdbeWrtermMain::run(xchg, &dbswdbe, (DpchInvWdbeWrtermMain*) req->dpchinv);
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

	pthread_cleanup_pop(1);

	return(NULL);
};

void WdbecmbdOpprc::cleanup(
			void* arg
		) {
	XchgWdbecmbd* xchg = (XchgWdbecmbd*) arg;

	xchg->cOpprcs.unlockMutex("WdbecmbdOpprc", "cleanup");
};
