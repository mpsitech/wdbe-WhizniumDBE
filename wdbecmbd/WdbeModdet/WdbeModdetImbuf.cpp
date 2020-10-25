/**
	* \file WdbeModdetImbuf.cpp
	* Wdbe operation processor - add inter-module buffer wiring (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModdetImbuf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModdet;

/******************************************************************************
 namespace WdbeModdetImbuf
 ******************************************************************************/

DpchRetWdbe* WdbeModdetImbuf::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModdetImbuf* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	WdbeMModule* top = NULL;
	WdbeMModule* sup = NULL;
	WdbeMImbuf* imb = NULL;
	WdbeMModule* cor = NULL;

	string maxlen;
	unsigned int w;

	string a32Not8, b32Not8;
	unsigned int wA, wB;

	string sfxTop, sfxSup, sfxCor;

	uint mdlNum;
	ubigint refC;

	ListWdbeMPort oldprts;
	map<string,WdbeMPort*> srefsOldprts;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::TOP), &top)) {
			if (dbswdbe->tblwdbemmodule->loadRecByRef(mdl->supRefWdbeMModule, &sup)) {
				if (dbswdbe->tblwdbemimbuf->loadRecByRef(mdl->refWdbeMImbuf, &imb)) {
					if (dbswdbe->tblwdbemmodule->loadRecByRef(imb->corRefWdbeMModule, &cor)) {
						Wdbe::getMpa(dbswdbe, refWdbeMModule, "a32Not8", a32Not8);
						if (a32Not8 == "true") wA = 32;
						else wA = 8;

						Wdbe::getMpa(dbswdbe, refWdbeMModule, "b32Not8", b32Not8);
						if (b32Not8 == "true") wB = 32;
						else wB = 8;

						// assemble port/signal suffixes
						if (imb->ixVDir == VecWdbeVMImbufDir::IN) {
							sfxTop = StrMod::cap(mdl->sref) + StrMod::cap(cor->sref) + "To" + StrMod::cap(sup->sref);
							sfxSup = StrMod::cap(mdl->sref) + "From" + StrMod::cap(cor->sref);
							sfxCor = StrMod::cap(mdl->sref) + "To" + StrMod::cap(sup->sref);
						} else {
							sfxTop = StrMod::cap(mdl->sref) + StrMod::cap(sup->sref) + "To" + StrMod::cap(cor->sref);
							sfxSup = StrMod::cap(mdl->sref) + "To" + StrMod::cap(cor->sref);
							sfxCor = StrMod::cap(mdl->sref) + "From" + StrMod::cap(sup->sref);
						};

						// pre-existing super module ports
						srefsOldprts.clear();
						dbswdbe->tblwdbemport->loadRstByMdl(sup->ref, false, oldprts);
						for (unsigned int i = 0; i < oldprts.nodes.size(); i++) srefsOldprts[oldprts.nodes[i]->sref] = oldprts.nodes[i];

						// determine width of available length ports/signal ; possibly overwritten by super module port (ex. pmmu)
						Wdbe::getMpa(dbswdbe, refWdbeMModule, "maxlen", maxlen);
						w = Wdbe::valToWidth(atoi(maxlen.c_str()));

						auto it = srefsOldprts.find("avllen" + sfxSup);
						if (it != srefsOldprts.end()) w = it->second->Width;

						// - top module signals
						// NOT thread safe
						mdlNum = 1;
						if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(top->ref) + " ORDER BY mdlNum DESC LIMIT 1", mdlNum)) mdlNum++;

						refC = dbswdbe->tblwdbecsignal->getNewRef();
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, cor->ref, 0, "req" + sfxTop, false, "sl", 1, "", "", "", "0", false, 0, "");
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, sup->ref, 0, "ack" + sfxTop, false, "sl", 1, "", "", "", "0", false, 0, "");
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, cor->ref, 0, "dne" + sfxTop, false, "sl", 1, "", "", "", "0", false, 0, "");

						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, sup->ref, 0, "avllen" + sfxTop, false, "slvdn", w-8, "", "", "", "0", false, 0, "");

						refC = dbswdbe->tblwdbecsignal->getNewRef();

						if (imb->ixVDir == VecWdbeVMImbufDir::IN) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, cor->ref, 0, "d" + sfxTop, false, "slvdn", wB, "", "", "", "0", false, 0, "");
						else dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, sup->ref, 0, "d" + sfxTop, false, "slvdn", wB, "", "", "", "0", false, 0, "");

						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, top->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, cor->ref, 0, "strbD" + sfxTop, false, "sl", 1, "", "", "", "0", false, 0, "");

						// - super module ports
						// NOT thread safe
						mdlNum = oldprts.nodes.size()+1;

						refC = dbswdbe->tblwdbecport->getNewRef();
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, sup->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "req" + sfxSup, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "req" + sfxTop, "");
						mergeCreateOprt(dbswdbe, refC, sup->ref, mdlNum, "ack" + sfxSup, "sl", 1, "ack" + sfxTop, srefsOldprts);
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, sup->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "dne" + sfxSup, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "dne" + sfxTop, "");

						mergeCreateOprt(dbswdbe, 0, sup->ref, mdlNum, "avllen" + sfxSup, "slvdn", w-8, "avllen" + sfxTop, srefsOldprts);

						refC = dbswdbe->tblwdbecport->getNewRef();
						if (imb->ixVDir == VecWdbeVMImbufDir::IN) {
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, sup->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "d" + sfxSup, VecWdbeVMPortDir::IN, "slvdn", wB, "", "", "", "", "d" + sfxTop, "");
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, sup->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + sfxSup, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "strbD" + sfxTop, "");
						} else {
							mergeCreateOprt(dbswdbe, refC, sup->ref, mdlNum, "d" + sfxSup, "slvdn", wB, "d" + sfxTop, srefsOldprts);
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, sup->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "strbD" + sfxSup, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "strbD" + sfxTop, "");
						};

						// MISSING: ack, len, d/strbD signals as port drivers if n/ex

						// - corresponding module ports
						// NOT thread safe
						srefsOldprts.clear();
						dbswdbe->tblwdbemport->loadRstByMdl(cor->ref, false, oldprts);
						for (unsigned int i = 0; i < oldprts.nodes.size(); i++) srefsOldprts[oldprts.nodes[i]->sref] = oldprts.nodes[i];

						mdlNum = oldprts.nodes.size()+1;

						refC = dbswdbe->tblwdbecport->getNewRef();
						mergeCreateOprt(dbswdbe, refC, cor->ref, mdlNum, "req" + sfxCor, "sl", 1, "req" + sfxTop, srefsOldprts);
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, cor->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "ack" + sfxCor, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ack" + sfxTop, "");
						mergeCreateOprt(dbswdbe, refC, cor->ref, mdlNum, "dne" + sfxCor, "sl", 1, "dne" + sfxTop, srefsOldprts);

						dbswdbe->tblwdbemport->insertNewRec(NULL, 0, cor->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "avllen" + sfxCor, VecWdbeVMPortDir::IN, "slvdn", w-8, "", "", "", "", "avllen" + sfxTop, "");

						refC = dbswdbe->tblwdbecport->getNewRef();
						if (imb->ixVDir == VecWdbeVMImbufDir::IN) {
							mergeCreateOprt(dbswdbe, refC, cor->ref, mdlNum, "d" + sfxCor, "slvdn", wB, "d" + sfxTop, srefsOldprts);
							mergeCreateOprt(dbswdbe, refC, cor->ref, mdlNum, "strbD" + sfxCor, "sl", 1, "strbD" + sfxTop, srefsOldprts);
						} else {
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, cor->ref, mdlNum++, VecWdbeVMPortMdlCat::IMB, "d" + sfxCor, VecWdbeVMPortDir::IN, "slvdn", wB, "", "", "", "", "d" + sfxTop, "");
							mergeCreateOprt(dbswdbe, refC, cor->ref, mdlNum, "strbD" + sfxCor, "sl", 1, "strbD" + sfxTop, srefsOldprts);
						};

						// MISSING: req/ack/dne, d/strbD signals as port drivers if n/ex

						delete cor;
					};
					delete imb;
				};
				delete sup;
			};
			delete top;
		};
		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeModdetImbuf::mergeCreateOprt(
			DbsWdbe* dbswdbe
			, const ubigint refC
			, const ubigint refMdl
			, uint& mdlNum
			, const string& sref
			, const string& srefHty
			, const usmallint Width
			, const string& srefCsi
			, map<string,WdbeMPort*>& srefsOldprts
		) {
	WdbeMPort* oldprt = NULL;

	auto it = srefsOldprts.find(sref);
	if (it != srefsOldprts.end()) {
		oldprt = it->second;
		oldprt->refWdbeCPort = refC;
		oldprt->mdlNum = mdlNum++;
		oldprt->csiSrefWdbeMSignal = srefCsi;
		dbswdbe->tblwdbemport->updateRec(oldprt);

	} else dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMdl, mdlNum++, VecWdbeVMPortMdlCat::IMB, sref, VecWdbeVMPortDir::OUT, srefHty, Width, "", "", "", "", srefCsi, "");
};
// IP cust --- IEND


