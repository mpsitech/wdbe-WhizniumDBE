/**
	* \file WdbeMtpCplmstbuPmmu_v1_0.cpp
	* Wdbe operation processor - connect buffers, fill slot vector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuPmmu_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuPmmu_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuPmmu_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	string sref, srefrootMgmt, srefrootCor;

	ubigint refPrcMem, refPrcOp;
	ubigint refPrcInbuf0B, refPrcOutbuf0B;

	string pgsizeMem, sizePg, sizeTocbuf;
	usmallint wA, wAvllen, wPg;

	unsigned int slot;

	string s;
	size_t ptr;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcMem = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "mem", "fastclk", "reset", true, "", false, "memory read/write operation");
		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		wA = 11;
		wAvllen = 11;
		wPg = 11;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "pgsizeMem", pgsizeMem)) if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizePg", sizePg)) {
			wA = Wdbe::valToWidth(atoi(pgsizeMem.c_str()) * 1024*atoi(sizePg.c_str()) - 1);
			wAvllen = Wdbe::valToWidth(atoi(pgsizeMem.c_str()) * 1024*atoi(sizePg.c_str()));
			wPg = Wdbe::valToWidth(1024*atoi(sizePg.c_str())-1);
		};

		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + to_string(wA) + " WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'a'");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'inbuf0'", ref)) {
			// ex. inbuf0LwiracqToPmmu => srefrootMgmt = Inbuf0ToPmmu, srefrootCor = Inbuf0FromLwiracq
			Wdbe::getImbsrefs(dbswdbe, ref, sref, srefrootMgmt, srefrootCor);

			// re-configure ports ; user is responsible for connecting clk
			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'clk" + srefrootCor + "' WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'clkInbuf0FromCormdl'");
			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'avllen" + srefrootCor + "', Width = " + to_string(wAvllen) + " WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'avllenInbuf0FromCormdl'");

			// signals
			ptr = srefrootCor.find("From");
			if (ptr != string::npos) s = StrMod::uncap(srefrootCor.substr(ptr + 4));
			else s = "";
			refPrcInbuf0B = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "inbuf0B", "clk" + srefrootCor, "reset", true, "", false, "inbuf0 B outward/" + s + "-facing operation");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMem, 0, "enInbuf0", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMem, 0, "aInbuf0_vec", false, "slvdn", wPg+1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dInbuf0", false, "slvdn", 8, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0B, 0, "enInbuf0B", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0B, 0, "aInbuf0B_vec", false, "slvdn", wPg+1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "clkA", "fastclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enInbuf0");

			Wdbe::setPrtCsi(dbswdbe, ref, "aA", "aInbuf0_vec");
			Wdbe::setPrtCsi(dbswdbe, ref, "drdA", "dInbuf0");

			Wdbe::setPrtCpr(dbswdbe, ref, "clkB", "clk" + srefrootCor);

			Wdbe::setPrtCsi(dbswdbe, ref, "enB", "enInbuf0B");

			Wdbe::setPrtCsi(dbswdbe, ref, "aB", "aInbuf0B_vec");
			Wdbe::setPrtCpr(dbswdbe, ref, "dwrB", "d" + srefrootCor);
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'outbuf0'", ref)) {
			// ex. outbuf0PmmuHostif => srefrootMgmt = Outbuf0ToHostif, srefrootCor = Onbuf0FromPmmu
			Wdbe::getImbsrefs(dbswdbe, ref, sref, srefrootMgmt, srefrootCor);

			// re-configure ports
			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'clk" + srefrootMgmt + "' WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'clkOutbuf0ToCormdl'");
			dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'avllen" + srefrootMgmt + "', Width = " + to_string(wAvllen) + " WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'avllenOutbuf0ToCormdl'");

			// signals
			ptr = srefrootMgmt.find("To");
			if (ptr != string::npos) s = StrMod::uncap(srefrootMgmt.substr(ptr + 2));
			else s = "";

			refPrcOutbuf0B = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "outbuf0B", "clk" + srefrootMgmt, "reset", true, "", false, "outbuf0 B outward/" + s + "-facing operation");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMem, 0, "enOutbuf0", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMem, 0, "aOutbuf0_vec", false, "slvdn", wPg+1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMem, 0, "dOutbuf0", false, "slvdn", 8, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0B, 0, "enOutbuf0B", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0B, 0, "aOutbuf0B_vec", false, "slvdn", wPg+1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "clkA", "fastclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enOutbuf0");

			Wdbe::setPrtCsi(dbswdbe, ref, "aA", "aOutbuf0_vec");
			Wdbe::setPrtCsi(dbswdbe, ref, "dwrA", "dOutbuf0");

			Wdbe::setPrtCpr(dbswdbe, ref, "clkB", "clk" + srefrootMgmt);

			Wdbe::setPrtCsi(dbswdbe, ref, "enB", "enOutbuf0B");

			Wdbe::setPrtCsi(dbswdbe, ref, "aB", "aOutbuf0B_vec");
			Wdbe::setPrtCpr(dbswdbe, ref, "drdB", "d" + srefrootMgmt);
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'tocbuf'", ref)) {
			wA = 10;
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeTocbuf", sizeTocbuf)) wA = Wdbe::valToWidth(1024*atoi(sizeTocbuf.c_str())-1);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "enTocbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "weTocbuf", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "aTocbuf_vec", false, "slvdn", wA, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "drdTocbuf", false, "slvdn", 9, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dwrTocbuf", false, "slvdn", 9, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "clk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "en", "enTocbuf");
			Wdbe::setPrtCsi(dbswdbe, ref, "we", "weTocbuf");

			Wdbe::setPrtCsi(dbswdbe, ref, "a", "aTocbuf_vec");
			Wdbe::setPrtCsi(dbswdbe, ref, "drd", "drdTocbuf");
			Wdbe::setPrtCsi(dbswdbe, ref, "dwr", "dwrTocbuf");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(mdl->refWdbeMController) + " AND sref LIKE 'VecV%Slot'", ref)) {
			slot = 14;
			if (Wdbe::getMpa(dbswdbe, mdl->ref, "slot", s)) slot = atoi(s.c_str());

			for (unsigned int i = 0; i < slot;i++) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, (i+1), "s" + to_string(i), "", "");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
