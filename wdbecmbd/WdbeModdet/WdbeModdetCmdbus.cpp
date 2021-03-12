/**
	* \file WdbeModdetCmdbus.cpp
	* Wdbe operation processor - add command bus wiring (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModdetCmdbus.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModdet;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeModdetCmdbus
 ******************************************************************************/

DpchRetWdbe* WdbeModdetCmdbus::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModdetCmdbus* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	bool mcuNotFpga = dpchinv->mcuNotFpga;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ubigint refC;

	string srefbase;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;
	uint mdlNum;

	ubigint refTop = 0;
	ubigint refCmdbus = 0;
	ubigint refCmdinv = 0;
	ubigint refCmdret = 0;

	string Cmdbussref;

	set<pair<string,string> > pairsCmdbus;

	WdbeMSignal* sig = NULL;

	unsigned int maxlenRecv, maxlenSend;

	WdbeMUnit* unt = NULL;

	uint vecNum;

	uint ixVDir;

	ubigint refPrcClk, refPrcArb;
	ubigint refPrtClk, refPrtAck;

	string s;

	bool found;


	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (mdl->hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
			srefbase = unt->Fullsref.substr(3);
			dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, mdls);

			delete unt;
		};

		delete mdl;
	};

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) refTop = mdl->ref;
		else if (mdl->ref == refWdbeMModule) {
			refCmdbus = mdl->ref;
			Cmdbussref = StrMod::cap(mdl->sref);
		} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) refCmdinv = mdl->ref;
		else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) refCmdret = mdl->ref;

		if ((refTop || mcuNotFpga) && refCmdbus && refCmdinv && refCmdret) break;
	};

	if ((refTop || mcuNotFpga) && refCmdbus && refCmdinv && refCmdret) {
		// - determine cmdinv/cmdret buf maxlen parameter
		maxlenRecv = 10;
		maxlenSend = 9;

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR))
						getMaxlenRecvSend(dbswdbe, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, maxlenRecv, maxlenSend);
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refCmdinv) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), ref))
					Wdbe::setMpa(dbswdbe, ref, "maxlen", to_string(maxlenRecv));

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refCmdret) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), ref))
					Wdbe::setMpa(dbswdbe, ref, "maxlen", to_string(maxlenSend));

		Wdbe::getPairsCmdbus(dbswdbe, mdls, pairsCmdbus);

		if (pairsCmdbus.size() > 0) {
			// - top module signals
			if (!mcuNotFpga) {
				mdlNum = 1;

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::CLK, refC, refTop, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refCmdbus, 0, "clk" + Cmdbussref, false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, refTop, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "d" + Cmdbussref, false, "slvdn", 8, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(&sig, VecWdbeVMSignalBasetype::OTH, refC, refTop, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdy" + Cmdbussref, false, "slvdn", pairsCmdbus.size(), "", "", "", "0", false, 0, "");
				sig->refWdbeMVector = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::SIG, sig->ref, "VecVSig" + srefbase + "Rdy" + Cmdbussref, "notit");
				dbswdbe->tblwdbemsignal->updateRec(sig);

				vecNum = 0;
				for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, sig->refWdbeMVector, vecNum++, it->first + "To" + StrMod::cap(it->second), "", "");

				delete sig;

				dbswdbe->tblwdbemsignal->insertNewRec(&sig, VecWdbeVMSignalBasetype::OTH, refC, refTop, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "req" + Cmdbussref, false, "slvdn", pairsCmdbus.size(), "", "", "", "0", false, 0, "");
				sig->refWdbeMVector = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::SIG, sig->ref, "VecVSig" + srefbase + "Req" + Cmdbussref, "notit");
				dbswdbe->tblwdbemsignal->updateRec(sig);

				vecNum = 0;
				for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, sig->refWdbeMVector, vecNum++, it->first + "To" + StrMod::cap(it->second), "", "");

				delete sig;

				dbswdbe->tblwdbemsignal->insertNewRec(&sig, VecWdbeVMSignalBasetype::OTH, refC, refTop, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refCmdbus, 0, "ack" + Cmdbussref, false, "slvdn", pairsCmdbus.size(), "", "", "", "0", false, 0, "");
				sig->refWdbeMVector = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::SIG, sig->ref, "VecVSig" + srefbase + "Ack" + Cmdbussref, "notit");
				dbswdbe->tblwdbemsignal->updateRec(sig);

				vecNum = 0;
				for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, sig->refWdbeMVector, vecNum++, it->first + "To" + StrMod::cap(it->second), "", "");

				delete sig;
			};

			// - command bus ports, signals and processes
			mdlNum = 1;

			refPrcClk = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refCmdbus, 0, "clk", "mclk", "", true, "", false, "clock");
			refPrcArb = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refCmdbus, 0, "arb", "clk", "", true, "", false, "arbiter operation");

			refPrtClk = dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refCmdbus, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "clk", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "clk" + Cmdbussref, "");

			refC = dbswdbe->tblwdbecport->getNewRef();
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCmdbus, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "rdy", VecWdbeVMPortDir::IN, "slvdn", pairsCmdbus.size(), "", "", "", "", "rdy" + Cmdbussref, "");

			refC = dbswdbe->tblwdbecport->getNewRef();
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCmdbus, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "req", VecWdbeVMPortDir::IN, "slvdn", pairsCmdbus.size(), "", "", "", "", "req" + Cmdbussref, "");
			refPrtAck = dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refCmdbus, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "ack", VecWdbeVMPortDir::OUT, "slvdn", pairsCmdbus.size(), "", "", "", "", "ack" + Cmdbussref, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, refCmdbus, 1, VecWdbeVMSignalMgeTbl::PRC, refPrcClk, 0, "clk", false, "sl", 1, "", "", "", "0", false, refPrtClk, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, refCmdbus, 2, VecWdbeVMSignalMgeTbl::PRC, refPrcArb, 0, "ack", false, "slvdn", pairsCmdbus.size(), "", "", "", "0", false, refPrtAck, "");

			// - cmdinv/cmdret/ctr/fwdctr ports
			for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
				mdl = mdls.nodes[i];

				if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR)) {
					found = false;
					ixVDir = VecWdbeVMPortDir::IN;

					for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) {
						if ((it->first == mdl->sref) || (it->second == mdl->sref)) {
							found = true;
							if (it->first == mdl->sref) ixVDir = VecWdbeVMPortDir::INOUT;
						};
						
						if (found && (ixVDir == VecWdbeVMPortDir::INOUT)) break;
					};

					if (found) {
						mdlNum = 1;

						// clk/d
						refC = dbswdbe->tblwdbecport->getNewRef();
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "clk" + Cmdbussref, VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "clk" + Cmdbussref, "");
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "d" + Cmdbussref, ixVDir, "slvdn", 8, "", "", "", "", "d" + Cmdbussref, "");

						for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) {
							if ((it->first == mdl->sref) || (it->second == mdl->sref)) {
								refC = dbswdbe->tblwdbecport->getNewRef();

								// ports per pairing
								if (it->first == mdl->sref) {
									dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "req" + Cmdbussref + "To" + StrMod::cap(it->second), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "req" + Cmdbussref + "[" + it->first + "To" + StrMod::cap(it->second) + "]", "");
									dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "wr" + Cmdbussref + "To" + StrMod::cap(it->second), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ack" + Cmdbussref + "[" + it->first + "To" + StrMod::cap(it->second) + "]", "");
								} else if (it->second == mdl->sref) {
									dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "rdy" + Cmdbussref + "From" + StrMod::cap(it->first), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "rdy" + Cmdbussref + "[" + it->first + "To" + StrMod::cap(it->second) + "]", "");
									dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, "rd" + Cmdbussref + "From" + StrMod::cap(it->first), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ack" + Cmdbussref + "[" + it->first + "To" + StrMod::cap(it->second) + "]", "");
								};
							};
						};
					};
				};
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
