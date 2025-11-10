/**
	* \file WdbeMtpCplmstbuCohostif_Easy_v1_0.cpp
	* Wdbe operation processor - connect PHY, CRC and timeout (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuCohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuCohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuCohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// exact copy from WdbeMtpCplmstbuHostif_Easy_v1_0.cpp

	ubigint ref, refC;

	uint mdlNum;

	ubigint refPrcOp;

	string s;
	int wA, wD;

	wA = 32;
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", s)) wA = atoi(s.c_str());
	wD = 8;
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s)) wD = atoi(s.c_str());

	mdlNum = 1;

	refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refWdbeMModule, 0, "op", "mclk", "reset", true, "", false, "main operation");

	// - AXI
	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'axi'", ref)) {
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_araddr", wA);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_rdata", wD);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_awaddr", wA);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_wdata", wD);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_wstrb", wD/8);

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqAxi", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackAxi", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneAxi", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axisendNotRecv", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axilen", false, "slvdn", 32, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axirecvAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "axirecvAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "axirecvAXIS_tdata", false, "slvdn", wD, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "axirecvAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "axisendAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axisendAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axisendAXIS_tdata", false, "slvdn", wD, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "axisendAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");

		Wdbe::setGenDfv(dbswdbe, ref, "wA", to_string(wA));
		Wdbe::setGenDfv(dbswdbe, ref, "wD", to_string(wD));

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqAxi");
		Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackAxi");
		Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneAxi");

		Wdbe::setPrtCsi(dbswdbe, ref, "sendNotRecv", "axisendNotRecv");
		Wdbe::setPrtCsi(dbswdbe, ref, "len", "axilen");

		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tready", "axirecvAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tvalid", "axirecvAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tdata", "axirecvAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tlast", "axirecvAXIS_tlast");

		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tready", "axisendAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tvalid", "axisendAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tdata", "axisendAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tlast", "axisendAXIS_tlast");

		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_araddr", "AXIL_araddr");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_arprot", "AXIL_arprot");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_arready", "AXIL_arready");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_arvalid", "AXIL_arvalid");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_rdata", "AXIL_rdata");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_rready", "AXIL_rready");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_rresp", "AXIL_rresp");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_rvalid", "AXIL_rvalid");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_rlast", "AXIL_rlast");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_awaddr", "AXIL_awaddr");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_awprot", "AXIL_awprot");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_awready", "AXIL_awready");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_awvalid", "AXIL_awvalid");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_wdata", "AXIL_wdata");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_wready", "AXIL_wready");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_wstrb", "AXIL_wstrb");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_wvalid", "AXIL_wvalid");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_bready", "AXIL_bready");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_bresp", "AXIL_bresp");
		Wdbe::setPrtCpr(dbswdbe, ref, "AXIL_bvalid", "AXIL_bvalid");
	};

	// - SPI
	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'spi'", ref)) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqSpi", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackSpi", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneSpi", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spilen", false, "slvdn", 32, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spirecvAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spirecvAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spirecvAXIS_tdata", false, "slvdn", 8, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spirecvAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spisendAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisendAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisendAXIS_tdata", false, "slvdn", 8, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisendAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");
		Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqSpi");
		Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackSpi");
		Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneSpi");

		Wdbe::setPrtCsi(dbswdbe, ref, "len", "spilen");

		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tready", "spirecvAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tvalid", "spirecvAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tdata", "spirecvAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "recvAXIS_tlast", "spirecvAXIS_tlast");

		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tready", "spisendAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tvalid", "spisendAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tdata", "spisendAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "sendAXIS_tlast", "spisendAXIS_tlast");

		Wdbe::setPrtCpr(dbswdbe, ref, "nss", "nss");
		Wdbe::setPrtCpr(dbswdbe, ref, "sclk", "sclk");
		Wdbe::setPrtCpr(dbswdbe, ref, "mosi", "mosi");
		Wdbe::setPrtCpr(dbswdbe, ref, "miso", "miso");
	};

	// - UART
	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'rx'", ref)) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqUrx", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackUrx", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneUrx", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "urxlen", false, "slvdn", 32, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "urxAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "urxAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "urxAXIS_tdata", false, "slvdn", 8, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "urxAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "urxburst", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");
		Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqUrx");
		Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackUrx");
		Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneUrx");

		Wdbe::setPrtCsi(dbswdbe, ref, "len", "urxlen");

		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tready", "urxAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tvalid", "urxAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tdata", "urxAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tlast", "urxAXIS_tlast");

		Wdbe::setPrtCsi(dbswdbe, ref, "burst", "urxburst");

		Wdbe::setPrtCpr(dbswdbe, ref, "rxd", "rxd");
	};

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'tx'", ref)) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqUtx", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackUtx", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneUtx", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "utxlen", false, "slvdn", 32, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "utxAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "utxAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "utxAXIS_tdata", false, "slvdn", 8, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "utxAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");
		Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqUtx");
		Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackUtx");
		Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneUtx");

		Wdbe::setPrtCsi(dbswdbe, ref, "len", "utxlen");

		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tready", "utxAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tvalid", "utxAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tdata", "utxAXIS_tdata");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tlast", "utxAXIS_tlast");

		Wdbe::setPrtCpr(dbswdbe, ref, "txd", "txd");
	};

	// - independent of PHY
	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'crc'", ref)) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "crcAXIS_tready", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcAXIS_tvalid", false, "sl", 1, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcAXIS_tdata", false, "slvdn", wD, "", "", "", "0", 0, "");
		if (wD > 8) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcAXIS_tkeep", false, "slvdn", wD/8, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcAXIS_tlast", false, "sl", 1, "", "", "", "0", 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "crc", false, "slvdn", 16, "", "", "", "0", 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "validCrc", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tready", "crcAXIS_tready");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tvalid", "crcAXIS_tvalid");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tdata", "crcAXIS_tdata");
		if (wD > 8) Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tkeep", "crcAXIS_tkeep");
		Wdbe::setPrtCsi(dbswdbe, ref, "AXIS_tlast", "crcAXIS_tlast");

		Wdbe::setPrtCsi(dbswdbe, ref, "crc", "crc");
		Wdbe::setPrtCsi(dbswdbe, ref, "validCrc", "validCrc");
	};

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'timeout'", ref)) {
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "torestart", false, "sl", 1, "", "", "", "0", 0, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "timeout", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenDfv(dbswdbe, ref, "twait", "100");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");
		Wdbe::setPrtCpr(dbswdbe, ref, "tkclk", "tkclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "restart", "torestart");
		Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "timeout");
	};

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'timeout2'", ref)) {
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "timeout2", false, "sl", 1, "", "", "", "0", 0, "");

		Wdbe::setGenDfv(dbswdbe, ref, "twait", "1000");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");
		Wdbe::setPrtCpr(dbswdbe, ref, "tkclk", "tkclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "restart", "torestart");
		Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "timeout2");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
