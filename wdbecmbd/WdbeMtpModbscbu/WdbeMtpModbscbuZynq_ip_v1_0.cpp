/**
	* \file WdbeMtpModbscbuZynq_ip_v1_0.cpp
	* Wdbe operation processor - connect AXI bus functionality (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuZynq_ip_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuZynq_ip_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuZynq_ip_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* axi = NULL;

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::WRP), &axi)) {
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ACLK", "s00_axi_aclk");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ARESETN", "s00_axi_aresetn");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_AWADDR", "s00_axi_awaddr");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_AWPROT", "s00_axi_awprot");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_AWVALID", "s00_axi_awvalid");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_AWREADY", "s00_axi_awready");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_WDATA", "s00_axi_wdata");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_WSTRB", "s00_axi_wstrb");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_WVALID", "s00_axi_wvalid");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_WREADY", "s00_axi_wready");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_BRESP", "s00_axi_bresp");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_BVALID", "s00_axi_bvalid");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_BREADY", "s00_axi_bready");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ARADDR", "s00_axi_araddr");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ARPROT", "s00_axi_arprot");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ARVALID", "s00_axi_arvalid");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_ARREADY", "s00_axi_arready");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_RDATA", "s00_axi_rdata");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_RRESP", "s00_axi_rresp");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_RVALID", "s00_axi_rvalid");
		Wdbe::setPrtCpr(dbswdbe, axi->ref, "S_AXI_RREADY", "s00_axi_rready");

		delete axi;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


