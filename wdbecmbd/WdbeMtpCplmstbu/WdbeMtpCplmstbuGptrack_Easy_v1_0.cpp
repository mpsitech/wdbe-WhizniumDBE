/**
	* \file WdbeMtpCplmstbuGptrack_Easy_v1_0.cpp
	* Wdbe operation processor - add capture/trigger ports, fill vectors and connect buffer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 17 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuGptrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuGptrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuGptrack_Easy_v1_0::run(
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

	bool hasrng;
	utinyint from, to;
	string ix;

	set<string> unqsrefs;

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
			vecNum = 0;

			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "capts", capts)) {
				StrMod::stringToVector(capts, ss, ';');

				for (unsigned int i = 0; i < ss.size(); i++) {
					Wdbe::getRange(ss[i], sref, hasrng, from, to, ix);

					if (!hasrng) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecCapt, vecNum++, sref, "", "");
					else for (utinyint j = from; j <= to; j++) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecCapt, vecNum++, sref + to_string((int) j), "", "");

					if (unqsrefs.find(sref) == unqsrefs.end()) {
						if (!hasrng) dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, sref, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", sref, "");
						else dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, sref, VecWdbeVMPortDir::IN, "slvdn", (to-from+1), "", "", "", "", ss[i], "");

						unqsrefs.insert(sref);
					};
				};
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(mdl->refWdbeMController) + " AND sref LIKE 'VecV%Trigger'", refVecTrig)) {
			vecNum = 1;

			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "trigs", trigs)) {
				StrMod::stringToVector(trigs, ss, ';');

				for (unsigned int i = 0; i < ss.size(); i++) {
					StrMod::stringToVector(ss[i], ss2, '.');

					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecTrig, vecNum++, ss2[0], "", "");
	
					if (unqsrefs.find(ss2[0]) == unqsrefs.end()) {
						dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTETOP, ss2[0], VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", ss2[0], "");
						unqsrefs.insert(sref);
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
