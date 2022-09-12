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
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuGpio_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx") req->dpchret = WdbeMtpCplmstbuIod_mchp_v1_0_mipirx::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMipidec_mchp_v1_0") req->dpchret = WdbeMtpCplmstbuMipidec_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMpfs_ip_AXI_v1_0") req->dpchret = WdbeMtpCplmstbuMpfs_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuMult_xlnx_v12_0") req->dpchret = WdbeMtpCplmstbuMult_xlnx_v12_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuOled128x32_v1_0") req->dpchret = WdbeMtpCplmstbuOled128x32_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuPmmu_v1_0") req->dpchret = WdbeMtpCplmstbuPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
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
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUart_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuUart_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarthostif_Easy_v1_0") req->dpchret = WdbeMtpCplmstbuUarthostif_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarthostif_v1_0") req->dpchret = WdbeMtpCplmstbuUarthostif_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUartrx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUartrx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUarttx_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUarttx_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu") req->dpchret = WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuXadc_xlnx_v3_3") req->dpchret = WdbeMtpCplmstbuXadc_xlnx_v3_3::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuZynq_ip_AXI_v1_0") req->dpchret = WdbeMtpCplmstbuZynq_ip_AXI_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmstbu*) req->dpchinv)->srefKCustop == "WdbeMtpCplmstbuZynq_ip_AXI_v2_0") req->dpchret = WdbeMtpCplmstbuZynq_ip_AXI_v2_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmstbu*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD) {
				if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdinv_v1_0") req->dpchret = WdbeMtpCplmsttdCmdinv_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdCmdret_v1_0") req->dpchret = WdbeMtpCplmsttdCmdret_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdDpbram_v1_0") req->dpchret = WdbeMtpCplmsttdDpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdGpio_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdGpio_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdI2c_Easy_v1_0") req->dpchret = WdbeMtpCplmsttdI2c_Easy_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdPmmu_v1_0") req->dpchret = WdbeMtpCplmsttdPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdSpbram_v1_0") req->dpchret = WdbeMtpCplmsttdSpbram_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_lttc_v1_0") req->dpchret = WdbeMtpCplmsttdTop_lttc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_mchp_v1_0") req->dpchret = WdbeMtpCplmsttdTop_mchp_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
				else if (((DpchInvWdbeMtpCplmsttd*) req->dpchinv)->srefKCustop == "WdbeMtpCplmsttdTop_xlnx_v1_0") req->dpchret = WdbeMtpCplmsttdTop_xlnx_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpCplmsttd*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
				if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstPmmu_v1_0") req->dpchret = WdbeMtpGenfstPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstSpifwd_v1_0") req->dpchret = WdbeMtpGenfstSpifwd_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstTkclksrc_v1_0") req->dpchret = WdbeMtpGenfstTkclksrc_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu") req->dpchret = WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
				else if (((DpchInvWdbeMtpGenfst*) req->dpchinv)->srefKCustop == "WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpGenfst*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
				if (((DpchInvWdbeMtpPlhfpga*) req->dpchinv)->srefKCustop == "WdbeMtpPlhfpgaPmmu_v1_0") req->dpchret = WdbeMtpPlhfpgaPmmu_v1_0::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhfpga*) req->dpchinv);
			};
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
				if (((DpchInvWdbeMtpPlhmcu*) req->dpchinv)->srefKCustop == "WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpPlhmcu*) req->dpchinv);
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
			if (req->dpchinv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
				if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu") req->dpchret = WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
				else if (((DpchInvWdbeMtpWrmcu*) req->dpchinv)->srefKCustop == "WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu") req->dpchret = WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu::run(xchg, &dbswdbe, (DpchInvWdbeMtpWrmcu*) req->dpchinv);
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
