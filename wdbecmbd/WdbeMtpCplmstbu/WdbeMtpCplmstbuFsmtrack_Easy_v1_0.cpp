/**
	* \file WdbeMtpCplmstbuFsmtrack_Easy_v1_0.cpp
	* Wdbe operation processor - add capture/trigger ports, fill vectors and connect buffers (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuFsmtrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuFsmtrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuFsmtrack_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string resetTrkclk, trkclk;

	string capts; // ex. tkclksrc.op;camif.stream
	string trigs; // ex. strbFrame.rising;ackXyz.falling

	ubigint refVecCapt, refVecTrig;
	uint vecNum;

	uint mdlNum;

	ubigint refMdl, refPrc;

	ubigint refC;

	string sref;

	string srefHostif;

	string srefKVendor;

	unsigned int wHostif;
	unsigned int sizeSeqbuf;

	map<string, string> srefsPrts;

	vector<string> ss, ss2;
	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		srefHostif = StrMod::cap(Wdbe::getHostifSref(dbswdbe, mdl->hkUref));

		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		wHostif = Wdbe::getHostifWidth(dbswdbe, mdl->hkUref);

		sizeSeqbuf = 2;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeSeqbuf", s)) sizeSeqbuf = atoi(s.c_str());

		// - ports and vectors
		mdlNum = 3;

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "trkclk", trkclk);
		if (trkclk == "mclk") {
			resetTrkclk = "reset";

			dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'resetTrkclk'");
			dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'trkclk'");
			mdlNum--;

		} else {
			resetTrkclk = "reset" + StrMod::cap(trkclk);

			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = '" + resetTrkclk + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'resetTrkclk'");
			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = '" + trkclk + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'trkclk'");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(mdl->refWdbeMController) + " AND sref LIKE 'VecV%Capture'", refVecCapt)) {
			vecNum = 1;

			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "capts", capts)) {
				StrMod::stringToVector(capts, ss, ';');

				for (unsigned int i = 0; i < ss.size(); i++) {
					StrMod::stringToVector(ss[i], ss2, '.');

					if (ss2.size() == 2) {
						dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecCapt, vecNum++, ss2[0] + StrMod::cap(ss2[1]), "", "");

						sref = ss2[0] + "State" + StrMod::cap(ss2[1]);
						dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, sref, VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", sref + "_dbg", "");
					};
				};
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(mdl->refWdbeMController) + " AND sref LIKE 'VecV%Trigger'", refVecTrig)) {
			vecNum = 2;

			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "trigs", trigs)) {
				StrMod::stringToVector(trigs, ss, ';');

				for (unsigned int i = 0; i < ss.size(); i++) {
					StrMod::stringToVector(ss[i], ss2, '.');

					if (ss2.size() >= 1) {
						dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecTrig, vecNum++, ss2[0], "", "");
						dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTETOP, ss2[0], VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", ss2[0], "");
					};
				};
			};
		};

		// - global constants
		mdlNum = 1;

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "wD", true, "nat", 0, "", "", "", to_string(wHostif), false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "logWD", true, "nat", 0, "", "", "", to_string(lround(log2(wHostif/8))), false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "sizeSeqbuf", true, "nat", 0, "", "", "", to_string(1024*sizeSeqbuf), false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "logSizeSeqbuf", true, "nat", 0, "", "", "", to_string(lround(log2(1024*sizeSeqbuf))), false, 0, "");

		// - buffer connections
		if (srefKVendor == "efnx") {
			srefsPrts["resetA"] = "resetA";
			srefsPrts["clkA"] = "clkA";
			srefsPrts["enA"] = "enA";
			srefsPrts["weA"] = "weA";
			srefsPrts["aA"] = "aA";
			srefsPrts["dwrA"] = "dwrA";
			srefsPrts["drdA"] = "drdA";

			srefsPrts["resetB"] = "resetB";
			srefsPrts["clkB"] = "clkB";
			srefsPrts["enB"] = "enB";
			srefsPrts["weB"] = "weB";
			srefsPrts["aB"] = "aB";
			srefsPrts["dwrB"] = "dwrB";
			srefsPrts["drdB"] = "drdB";

		} else if (srefKVendor == "lttc") {
			srefsPrts["resetA"] = "rst_a_i";
			srefsPrts["clkA"] = "clk_a_i";
			srefsPrts["enA"] = "clk_en_a_i";
			srefsPrts["weA"] = "wr_en_a_i";
			srefsPrts["aA"] = "addr_a_i";
			srefsPrts["dwrA"] = "wr_data_a_i";
			srefsPrts["drdA"] = "rd_data_a_o";

			srefsPrts["resetB"] = "rst_b_i";
			srefsPrts["clkB"] = "clk_b_i";
			srefsPrts["enB"] = "clk_en_b_i";
			srefsPrts["weB"] = "wr_en_b_i";
			srefsPrts["aB"] = "addr_b_i";
			srefsPrts["dwrB"] = "wr_data_b_i";
			srefsPrts["drdB"] = "rd_data_b_o";

		} else if (srefKVendor == "xlnx") {
			srefsPrts["clkA"] = "clkA";
			srefsPrts["enA"] = "enA";
			srefsPrts["weA"] = "weA";
			srefsPrts["aA"] = "addrA";
			srefsPrts["dwrA"] = "dinA";
			srefsPrts["drdA"] = "doutA";

			srefsPrts["clkB"] = "clkB";
			srefsPrts["enB"] = "enB";
			srefsPrts["weB"] = "weB";
			srefsPrts["aB"] = "addrB";
			srefsPrts["dwrB"] = "dinB";
			srefsPrts["drdB"] = "doutB";
		};

		mdlNum = 1;

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'cntbuf'", refMdl)) {
			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "count", trkclk, resetTrkclk, true, "", false, "count operation");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enCntbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aCntbuf_vec", false, "slvdn", 9, "", "", "", "", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "dwrCntbuf", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enCntbufB", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aCntbufB_vec", false, "slvdn", 9, "", "", "", "", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refMdl, 0, "drdCntbufB", false, "slvdn", 32, "", "", "", "", false, 0, "");

			if (srefsPrts.find("resetA") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetA"], resetTrkclk);
			if (srefsPrts.find("resetB") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetB"], resetTrkclk);

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkA"], trkclk);
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enA"], "enCntbuf");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weA"], "1");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aA"], "aCntbuf_vec");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["dwrA"], "dwrCntbuf");

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkB"], trkclk);
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enB"], "enCntbufB");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weB"], "0");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aB"], "aCntbufB_vec");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["dwrB"], "0");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["drdB"], "drdCntbufB");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'fstoccbuf'", refMdl)) {
			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "first", trkclk, resetTrkclk, true, "", false, "first occurrence operation");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enFstoccbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aFstoccbuf_vec", false, "slvdn", 9, "", "", "", "", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "dwrFstoccbuf", false, "slvdn", 32, "", "", "", "0", false, 0, "");

			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "fstoccbufB", "mclk", "reset", true, "", false, "first occurrence buffer B/" + StrMod::uncap(srefHostif) + "-facing operation");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enFstoccbufB", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aFstoccbufB_vec", false, "slvdn", 11 - log2(wHostif/8), "", "", "", "", false, 0, "");

			if (srefsPrts.find("resetA") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetA"], resetTrkclk);
			if (srefsPrts.find("resetB") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetB"], "reset");

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkA"], trkclk);
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enA"], "enFstoccbuf");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weA"], "1");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aA"], "aFstoccbuf_vec");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["dwrA"], "dwrFstoccbuf");

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkB"], "mclk");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enB"], "enFstoccbufB");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weB"], "0");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aB"], "aFstoccbufB_vec");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["dwrB"], "0");
			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["drdB"], "fstoccbufTo" + srefHostif + "AXIS_tdata");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'seqbuf'", refMdl)) {
			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "seq", trkclk, resetTrkclk, true, "", false, "sequence operation");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enSeqbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aSeqbuf_vec", false, "slvdn", ceil(log2(sizeSeqbuf)) + 10, "", "", "", "", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "dwrSeqbuf", false, "slvdn", 32, "", "", "", "0", false, 0, "");

			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "seqbufB", "mclk", "reset", true, "", false, "sequence buffer B/" + StrMod::uncap(srefHostif) + "-facing operation");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "enSeqbufB", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, "aSeqbufB_vec", false, "slvdn", ceil(log2(sizeSeqbuf)) + 10 - log2(wHostif/8), "", "", "", "", false, 0, "");

			if (srefsPrts.find("resetA") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetA"], resetTrkclk);
			if (srefsPrts.find("resetB") != srefsPrts.end()) Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["resetB"], "reset");

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkA"], trkclk);
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enA"], "enSeqbuf");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weA"], "1");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aA"], "aSeqbuf_vec");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["dwrA"], "dwrSeqbuf");

			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["clkB"], "mclk");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["enB"], "enSeqbufB");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["weB"], "0");
			Wdbe::setPrtCsi(dbswdbe, refMdl, srefsPrts["aB"], "aSeqbufB_vec");
			Wdbe::setPrtDfv(dbswdbe, refMdl, srefsPrts["dwrB"], "0");
			Wdbe::setPrtCpr(dbswdbe, refMdl, srefsPrts["drdB"], "seqbufTo" + srefHostif + "AXIS_tdata");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
