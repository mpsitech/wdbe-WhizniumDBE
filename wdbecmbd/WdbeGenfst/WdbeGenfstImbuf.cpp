/**
	* \file WdbeGenfstImbuf.cpp
	* Wdbe operation processor - add inter-module buffer wiring (implementation)
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

#include "WdbeGenfstImbuf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstImbuf
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstImbuf::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstImbuf* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	WdbeMImbuf* imb = NULL;

	unsigned int w;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	ubigint refMgmt, refCor;

	bool mcuNotFpga;

	uint sigsRefIxVTbl;
	ubigint sigsRefUref;
	uint refNum;

	string srefWdbeKHdltype, Defval;

	ubigint refC;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemimbuf->loadRecByRef(mdl->refWdbeMImbuf, &imb)) {
			// - analyze inter-module buffer connectivity
			mcuNotFpga = (mdl->supRefWdbeMModule == 0);

			mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);

			if (!mgmtToNotFrom) dbswdbe->loadRefBySQL("SELECT corRefWdbeMModule FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(refWdbeMModule) + " AND srefKFunction = 'snk'", refCor);
			else dbswdbe->loadRefBySQL("SELECT corRefWdbeMModule FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(refWdbeMModule) + " AND srefKFunction = 'src'", refCor);

			if (!mcuNotFpga) {
				refMgmt = mdl->supRefWdbeMModule;
				sigsRefIxVTbl = VecWdbeVMSignalRefTbl::MDL;
				sigsRefUref = 0;
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::TOP) + " AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(mdl->hkUref), sigsRefUref);
				srefWdbeKHdltype = "sl";
				Defval = "0";
			} else {
				dbswdbe->loadRefBySQL("SELECT corRefWdbeMModule FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(refWdbeMModule) + " AND srefKFunction = 'mgmt'", refMgmt);
				sigsRefIxVTbl = VecWdbeVMSignalRefTbl::UNT;
				sigsRefUref = mdl->hkUref;
				srefWdbeKHdltype = "bit";
				Defval = "";
			};

			w = Wdbe::valToWidth(Wdbe::getMinmaxMax(imb->Minmax) * imb->Width / 8); // avllen in bytes, not words
			if (!mcuNotFpga) w -= 8; // 256 byte blocks for FPGA units

			// - top module / unit signals
			// NOT thread safe
			refNum = Wdbe::getNextSigRefNum(dbswdbe, sigsRefIxVTbl, sigsRefUref);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, refCor, 0, "req" + StrMod::cap(sref), false, srefWdbeKHdltype, 1, "", "", "", Defval, false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, refMgmt, 0, "ack" + StrMod::cap(sref), false, srefWdbeKHdltype, 1, "", "", "", Defval, false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, refCor, 0, "dne" + StrMod::cap(sref), false, srefWdbeKHdltype, 1, "", "", "", Defval, false, 0, "");

			if (!mcuNotFpga) {
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, refMgmt, 0, "avllen" + StrMod::cap(sref), false, "slvdn", w, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, (mgmtToNotFrom) ? refCor : refMgmt, 0, "d" + StrMod::cap(sref), false, "slvdn", imb->Width, "", "", "", "0", false, 0, "");

			} else {
				refC = 0;
			};

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, sigsRefIxVTbl, sigsRefUref, refNum++, VecWdbeVMSignalMgeTbl::MDL, refCor, 0, "strbD" + StrMod::cap(sref), false, srefWdbeKHdltype, 1, "", "", "", Defval, false, 0, "");

			// - managing module ports / variables
			if (!mcuNotFpga) {
				// NOT thread safe
				refNum = Wdbe::getNextPrtMdlNum(dbswdbe, refMgmt);

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "req" + srefrootMgmt, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "req" + StrMod::cap(sref), "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "ack" + srefrootMgmt, VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "ack" + StrMod::cap(sref), "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "dne" + srefrootMgmt, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "dne" + StrMod::cap(sref), "");

				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "avllen" + srefrootMgmt, VecWdbeVMPortDir::OUT, "slvdn", w, "", "", "", "", "avllen" + StrMod::cap(sref), "");

				refC = dbswdbe->tblwdbecport->getNewRef();
				if (!mgmtToNotFrom) {
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "d" + srefrootMgmt, VecWdbeVMPortDir::OUT, "slvdn", imb->Width, "", "", "", "", "d" + StrMod::cap(sref), "");
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + srefrootMgmt, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "strbD" + StrMod::cap(sref), "");
				} else {
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "d" + srefrootMgmt, VecWdbeVMPortDir::IN, "slvdn", imb->Width, "", "", "", "", "d" + StrMod::cap(sref), "");
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMgmt, refNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + srefrootMgmt, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "strbD" + StrMod::cap(sref), "");
				};

				// MISSING: ack, len, d/strbD signals as port drivers if n/ex

			} else {
				// NOT thread safe
				refNum = Wdbe::getNextVarRefNum(dbswdbe, VecWdbeVMVariableRefTbl::MDL, refMgmt);

				dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::MDL, refMgmt, refNum++, "avllen" + srefrootMgmt, false, false, "usgn", 8, "", "", "", false, "");
				dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::MDL, refMgmt, refNum++, "d" + srefrootMgmt, false, false, "usgn", 8, "", "", "", false, "");
			};

			if (!mcuNotFpga) {
				// - corresponding module ports
				// NOT thread safe
				refNum = Wdbe::getNextPrtMdlNum(dbswdbe, refCor);

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "req" + srefrootCor, VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "req" + StrMod::cap(sref), "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "ack" + srefrootCor, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ack" + StrMod::cap(sref), "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "dne" + srefrootCor, VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "dne" + StrMod::cap(sref), "");

				dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "avllen" + srefrootCor, VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", "avllen" + StrMod::cap(sref), "");

				refC = dbswdbe->tblwdbecport->getNewRef();
				if (!mgmtToNotFrom) {
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "d" + srefrootCor, VecWdbeVMPortDir::IN, "slvdn", imb->Width, "", "", "", "", "d" + StrMod::cap(sref), "");
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + srefrootCor, VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "strbD" + StrMod::cap(sref), "");
				} else {
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "d" + srefrootCor, VecWdbeVMPortDir::OUT, "slvdn", imb->Width, "", "", "", "", "d" + StrMod::cap(sref), "");
					dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCor, refNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + srefrootCor, VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "strbD" + StrMod::cap(sref), "");
				};

				// MISSING: req/ack/dne, d/strbD signals as port drivers if n/ex
			};

			delete imb;
		};
		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
