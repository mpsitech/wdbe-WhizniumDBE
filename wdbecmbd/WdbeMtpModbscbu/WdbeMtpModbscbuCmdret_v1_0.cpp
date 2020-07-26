/**
	* \file WdbeMtpModbscbuCmdret_v1_0.cpp
	* Wdbe operation processor - connect buffer (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuCmdret_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuCmdret_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuCmdret_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refC;

	WdbeMModule* mdl = NULL;
	WdbeMModule* buf = NULL;
	WdbeMModule* hostif = NULL;

	WdbeMImbuf* imb = NULL;

	uint mdlNum;

	string Cmdbussref;

	string size;
	utinyint w;

	ubigint refPrcBuf, refPrcBufB;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcBuf = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "buf", "mclk", "reset", true, "", false, "buf command bus-facing operation");
		refPrcBufB = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "bufB", "mclk", "reset", true, "", false, "buf outward/hostif-facing operation");

		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), &buf)) {
			if (dbswdbe->tblwdbemimbuf->loadRecByRef(buf->refWdbeMImbuf, &imb)) {

				if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), &hostif)) {
					imb->corRefWdbeMModule = hostif->ref;
					imb->sref = imb->sref.substr(0, imb->sref.find("Cormdl")) + StrMod::cap(hostif->sref);

					dbswdbe->tblwdbemimbuf->updateRec(imb);
					
					delete hostif;
				};

				Cmdbussref = "cmdbus";
				dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->supRefWdbeMModule) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDBUS), Cmdbussref);
				Cmdbussref = StrMod::cap(Cmdbussref);

				w = 10;
				if (Wdbe::getMpa(dbswdbe, buf->ref, "size", size)) w = Wdbe::valToWidth(1024*atoi(size.c_str())-1);

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBuf, 0, "enBuf", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBuf, 0, "aBuf_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBufB, 0, "enBufB", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBufB, 0, "weBufB", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBufB, 0, "aBufB_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, buf->ref, 0, "drdBufB", false, "slvdn", 8, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcBufB, 0, "dwrBufB", false, "slvdn", 8, "", "", "", "0", false, 0, "");

				Wdbe::setPrtCpr(dbswdbe, buf->ref, "clkA", "mclk");

				Wdbe::setPrtCsi(dbswdbe, buf->ref, "enA", "enBuf");

				Wdbe::setPrtCsi(dbswdbe, buf->ref, "aA", "aBuf_vec");
				Wdbe::setPrtCpr(dbswdbe, buf->ref, "dwrA", "d" + Cmdbussref);

				Wdbe::setPrtCpr(dbswdbe, buf->ref, "clkB", "mclk");

				Wdbe::setPrtCsi(dbswdbe, buf->ref, "enB", "enBufB");
				Wdbe::setPrtCsi(dbswdbe, buf->ref, "weB", "weBufB");

				Wdbe::setPrtCsi(dbswdbe, buf->ref, "aB", "aBufB_vec");
				Wdbe::setPrtCsi(dbswdbe, buf->ref, "drdB", "drdBufB");
				Wdbe::setPrtCsi(dbswdbe, buf->ref, "dwrB", "dwrBufB");

				delete imb;
			};
			delete buf;
		};
		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


