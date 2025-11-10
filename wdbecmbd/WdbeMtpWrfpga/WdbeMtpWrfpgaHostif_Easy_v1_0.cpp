/**
	* \file WdbeMtpWrfpgaHostif_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaHostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaHostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaHostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Hostif.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, Prjshort, Untsref, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeMtpWrfpgaHostif_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	vector<ubigint> refs;

	ListWdbeMModule untmdls;
	WdbeMModule* untmdl = NULL;

	string sref, srefrootMgmt, srefrootCor;

	vector<string> srefsImbRd, srefrootsImbRd;
	vector<string> srefsImbWr, srefrootsImbWr;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ubigint refPrcOp;

	string phytype, wD;

	unsigned int ix;

	unsigned int parlen;

	string s;

	bool first, first2;

	dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, untmdls);

	dbswdbe->loadRefsBySQL("SELECT TblWdbeMImbuf.refWdbeMModule FROM TblWdbeMImbuf, TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeRMModuleMModule.corRefWdbeMModule = "
				+ to_string(mdl->ref) + " ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMModule.sref ASC", false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) {
		if (!Wdbe::getImbsrefs(dbswdbe, refs[i], sref, srefrootMgmt, srefrootCor)) {
			srefsImbRd.push_back(StrMod::cap(sref));
			srefrootsImbRd.push_back(srefrootCor);
		} else {
			srefsImbWr.push_back(StrMod::cap(sref));
			srefrootsImbWr.push_back(srefrootCor);
		};
	};

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);

	Wdbe::getMpa(dbswdbe, mdl->ref, "phytype", phytype);

	wD = "8";
	if (phytype == "axi") Wdbe::getMpa(dbswdbe, mdl->ref, "wD", wD);

	// --- sigs.rxtx*
	if (phytype != "uart") outfile << "-- IP sigs.rxtx --- AFFIRM" << endl;
	else outfile << "-- IP sigs.rxtx --- REMOVE" << endl;

	// --- crc.tkeep*
	if (wD != "8") outfile << "-- IP crc.tkeep --- AFFIRM" << endl;
	else outfile << "-- IP crc.tkeep --- REMOVE" << endl;

	// --- axirxtx*
	if (phytype == "axi") outfile << "-- IP axirxtx --- AFFIRM" << endl;
	else outfile << "-- IP axirxtx --- REMOVE" << endl;

	// --- spirxtx*
	if (phytype == "spi") outfile << "-- IP spirxtx --- AFFIRM" << endl;
	else outfile << "-- IP spirxtx --- REMOVE" << endl;

	// --- uartrx*
	if (phytype == "uart") outfile << "-- IP uartrx --- AFFIRM" << endl;
	else outfile << "-- IP uartrx --- REMOVE" << endl;

	// --- uarttx*
	if (phytype == "uart") outfile << "-- IP uarttx --- AFFIRM" << endl;
	else outfile << "-- IP uarttx --- REMOVE" << endl;

	// --- impl.op.wiring.rxtx*
	if (phytype != "uart") outfile << "-- IP impl.op.wiring.rxtx --- AFFIRM" << endl;
	else outfile << "-- IP impl.op.wiring.rxtx --- REMOVE" << endl;

	// --- impl.op.wiring.cmdvalid
	outfile << "-- IP impl.op.wiring.cmdvalid --- IBEGIN" << endl;

	outfile << "\tcmdvalid <= '1' when ( (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(mdl->sref) << " and tixVCommand=x\"00\")" << endl;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
			first2 = true;

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (first2) {
					outfile << "\t\t\t\tor (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and ";
					if (cmds.nodes.size() > 1) outfile << "(";

					first2 = false;

				} else {
					outfile << " or ";
				};

				outfile << "tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref);
			};

			if (cmds.nodes.size() > 1) outfile << ")";
			if (!first2) outfile << ")" << endl;
		};
	};

	outfile << "\t\t\t\t) else '0';" << endl;

	outfile << "-- IP impl.op.wiring.cmdvalid --- IEND" << endl;

	// --- impl.op.wiring.lenRet
	outfile << "-- IP impl.op.wiring.lenRet --- IBEGIN" << endl;

	first = true;

	outfile << "\tlenRet <= ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
					if (first) first = false;
					else outfile << "\t\t\t\telse ";

					dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

					parlen = 0;

					for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
						rpa = rpas.nodes[k];

						parlen += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);
						if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) parlen--;
					};

					outfile << "x\"" << Wdbe::binToHex((parlen & 0xFF00) >> 8) << Wdbe::binToHex(parlen & 0xFF) << "\" when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse ";
	outfile << "(others => '0');" <<  endl;

	outfile << "-- IP impl.op.wiring.lenRet --- IEND" << endl;

	// --- impl.op.wiring.lenInv
	outfile << "-- IP impl.op.wiring.lenInv --- IBEGIN" << endl;

	first = true;

	outfile << "\tlenInv <= ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

				if (ipas.nodes.size() > 0) {
					if (first) first = false;
					else outfile << "\t\t\t\telse ";

					parlen = 0;

					for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
						ipa = ipas.nodes[k];
						parlen += Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);
					};

					outfile << "x\"" << Wdbe::binToHex((parlen & 0xFF00) >> 8) << Wdbe::binToHex(parlen & 0xFF) << "\" when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
					first = false;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse ";
	outfile << "(others => '0');" <<  endl;

	outfile << "-- IP impl.op.wiring.lenInv --- IEND" << endl;

	// --- impl.op.wiring.reqInv
	outfile << "-- IP impl.op.wiring.reqInv --- IBEGIN" << endl;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::STATSNG) {
					outfile << "\treqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " <= reqInv when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") else '0';" << endl;

					dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

					ix = 0;
					for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
						ipa = ipas.nodes[k];
						
						parlen = Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

						if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							outfile << "\t" << untmdl->sref << StrMod::cap(cmd->sref) << "Len" << StrMod::cap(ipa->sref) << " <= invbuf(" << ix << ");" << endl;

							ix++;
							parlen--;
						};

						outfile << "\t" << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(ipa->sref) << " <=";

						for (unsigned int l = 0; l < parlen; l++) {
							if (l != 0) outfile << " &";

							if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << " invbuf(" << (ix+parlen-l-1) << ")";
							else outfile << " invbuf(" << (ix+l) << ")";
						};

						outfile << ";" << endl;

						ix += parlen;
					};

					outfile << endl;
				};
			};
		};
	};
	outfile << "-- IP impl.op.wiring.reqInv --- IEND" << endl;

	// --- impl.op.wiring.ackInv
	outfile << "-- IP impl.op.wiring.ackInv --- IBEGIN" << endl;

	first = true;

	outfile << "\tackInv <= ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::STATSNG) {
					if (first) first = false;
					else outfile << "\t\t\t\telse ";

					outfile << "ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
					first = false;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse ";
	outfile << "'1';" <<  endl;

	outfile << "-- IP impl.op.wiring.ackInv --- IEND" << endl;

	// --- impl.op.wiring.txbufvalid
	outfile << "-- IP impl.op.wiring.txbufvalid --- IBEGIN" << endl;

	outfile << "\ttxbufvalid <= ";
	if (!srefsImbRd.empty()) {
		outfile << "'1' when";

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != 0) outfile << " or";
			outfile << " tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i];
		};
		outfile << " else '0';" << endl;

	} else outfile << " '0';" << endl;
	
	outfile << "-- IP impl.op.wiring.txbufvalid --- IEND" << endl;

	// --- impl.op.wiring.reqTxbuf
	outfile << "-- IP impl.op.wiring.reqTxbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
		outfile << "\treq" << srefrootsImbRd[i] << " <= reqTxbuf when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;

	outfile << "-- IP impl.op.wiring.reqTxbuf --- IEND" << endl;

	// --- impl.op.wiring.ackTxbuf
	outfile << "-- IP impl.op.wiring.ackTxbuf --- IBEGIN" << endl;

	outfile << "\tackTxbuf <= ";
	
	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << "ack" << srefrootsImbRd[i] << " when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (!srefsImbRd.empty()) outfile << "\t\t\t\telse ";
	outfile << "'0';" << endl;

	outfile << "-- IP impl.op.wiring.ackTxbuf --- IEND" << endl;

	// --- impl.op.wiring.dneTxbuf
	outfile << "-- IP impl.op.wiring.dneTxbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
		outfile << "\tdne" << srefrootsImbRd[i] << " <= dneTxbuf when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;

	outfile << "-- IP impl.op.wiring.dneTxbuf --- IEND" << endl;

	// --- impl.op.wiring.avllenTxbuf
	outfile << "-- IP impl.op.wiring.avllenTxbuf --- IBEGIN" << endl;

	outfile << "\tavllenTxbuf <= ";

	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << "avllen" << srefrootsImbRd[i] << " when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (!srefsImbRd.empty()) outfile << "\t\t\t\telse ";
	outfile << "(others => '0');" << endl;

	outfile << "-- IP impl.op.wiring.avllenTxbuf --- IEND" << endl;

	// --- impl.op.wiring.txbufAXIS
	outfile << "-- IP impl.op.wiring.txbufAXIS --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
		outfile << "\t" << StrMod::uncap(srefrootsImbRd[i]) << "AXIS_tready <= txbufAXIS_tready when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;
	outfile << endl;

	//
	outfile << "\ttxbufAXIS_tvalid <= ";
	
	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << StrMod::uncap(srefrootsImbRd[i]) << "AXIS_tvalid when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (!srefsImbRd.empty()) outfile << "\t\t\t\telse ";
	outfile << "'0';" << endl;
	outfile << endl;

	//
	outfile << "\ttxbufAXIS_tdata <= ";
	
	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << StrMod::uncap(srefrootsImbRd[i]) << "AXIS_tdata when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (!srefsImbRd.empty()) outfile << "\t\t\t\telse ";
	outfile << "(others => '0');" << endl;
	outfile << endl;

	//
	outfile << "\ttxbufAXIS_tlast <= ";
	
	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << StrMod::uncap(srefrootsImbRd[i]) << "AXIS_tlast when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (!srefsImbRd.empty()) outfile << "\t\t\t\telse ";
	outfile << "'1';" << endl;

	outfile << "-- IP impl.op.wiring.txbufAXIS --- IEND" << endl;

	// --- impl.op.wiring.rxbufvalid
	outfile << "-- IP impl.op.wiring.rxbufvalid --- IBEGIN" << endl;

	outfile << "\trxbufvalid <= ";
	if (!srefsImbWr.empty()) {
		outfile << "'1' when";

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != 0) outfile << " or";
			outfile << " tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i];
		};
		outfile << " else '0';" << endl;

	} else outfile << " '0';" << endl;

	outfile << "-- IP impl.op.wiring.rxbufvalid --- IEND" << endl;

	// --- impl.op.wiring.reqRxbuf
	outfile << "-- IP impl.op.wiring.reqRxbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
		outfile << "\treq" << srefrootsImbWr[i] << " <= reqRxbuf when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;

	outfile << "-- IP impl.op.wiring.reqRxbuf --- IEND" << endl;

	// --- impl.op.wiring.ackRxbuf
	outfile << "-- IP impl.op.wiring.ackRxbuf --- IBEGIN" << endl;

	outfile << "\tackRxbuf <= ";
	
	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << "ack" << srefrootsImbWr[i] << " when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << endl;
	};

	if (!srefsImbWr.empty()) outfile << "\t\t\t\telse ";
	outfile << "'0';" << endl;

	outfile << "-- IP impl.op.wiring.ackRxbuf --- IEND" << endl;

	// --- impl.op.wiring.dneRxbuf
	outfile << "-- IP impl.op.wiring.dneRxbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
		outfile << "\tdne" << srefrootsImbWr[i] << " <= dneRxbuf when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;

	outfile << "-- IP impl.op.wiring.dneRxbuf --- IEND" << endl;

	// --- impl.op.wiring.avllenRxbuf
	outfile << "-- IP impl.op.wiring.avllenRxbuf --- IBEGIN" << endl;

	outfile << "\tavllenRxbuf <= ";

	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << "avllen" << srefrootsImbWr[i] << " when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << endl;
	};

	if (!srefsImbWr.empty()) outfile << "\t\t\t\telse ";
	outfile << "(others => '0');" << endl;

	outfile << "-- IP impl.op.wiring.avllenRxbuf --- IEND" << endl;

	// --- impl.op.wiring.rxbufAXIS
	outfile << "-- IP impl.op.wiring.rxbufAXIS --- IBEGIN" << endl;

	outfile << "\trxbufAXIS_tready <= ";
	
	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << StrMod::uncap(srefrootsImbWr[i]) << "AXIS_tready when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << endl;
	};

	if (!srefsImbWr.empty()) outfile << "\t\t\t\telse ";
	outfile << "'0';" << endl;

	//
	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
		outfile << "\t" << StrMod::uncap(srefrootsImbWr[i]) << "AXIS_tvalid <= rxbufAXIS_tvalid when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;
	outfile << endl;

	//
	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
		outfile << "\t" << StrMod::uncap(srefrootsImbWr[i]) << "AXIS_tdata <= rxbufAXIS_tdata when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << " else (others => '0');" << endl;
	outfile << endl;

	//
	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
		outfile << "\t" << StrMod::uncap(srefrootsImbWr[i]) << "AXIS_tlast <= rxbufAXIS_tlast when tixVBuffer=tixV" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;
	outfile << endl;

	outfile << "-- IP impl.op.wiring.rxbufAXIS --- IEND" << endl;

	// --- impl.op.inv.retbuf
	outfile << "-- IP impl.op.inv.retbuf --- IBEGIN" << endl;

	first = true; // controller

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
 			first2 = true; // command

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

				if (rpas.nodes.size() > 0) {
					if (first2) {
						outfile << "\t\t\t\t\t";
						if (first) first = false;
						else outfile << "els";
						
						outfile << "if tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " then" << endl;
					};

					outfile << "\t\t\t\t\t\t";
					if (first2) first2 = false;
					else outfile << "els";
					
					outfile << "if tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << " then" << endl;

					ix = 0;
					for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
						rpa = rpas.nodes[k];
						
						parlen = Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

						if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							outfile << "\t\t\t\t\t\t\tretbuf(" << ix << ") <= " << untmdl->sref << StrMod::cap(cmd->sref) << "Len" << StrMod::cap(rpa->sref) << ";" << endl;

							ix++;
							parlen--;
						};

						if (parlen == 1) {
							outfile << "\t\t\t\t\t\t\tretbuf(" << ix << ") <= " << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(rpa->sref) << ";" << endl;
							ix++;

						} else {
							outfile << "\t\t\t\t\t\t\tfor i in 0 to " << (parlen-1) << " loop" << endl;

							outfile << "\t\t\t\t\t\t\t\tretbuf(";
							if (ix > 0) outfile << ix << "+";

							if ((rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << (parlen-1) << "-i";
							else outfile << "i";

							outfile << ") <= " << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(rpa->sref) << "((" << parlen << "-i)*8-1 downto (" << (parlen-1) << "-i)*8);" << endl;

							outfile << "\t\t\t\t\t\t\tend loop;" << endl;

							ix += parlen;
						};
					};
				};
			};

			if (!first2) {
				outfile << "\t\t\t\t\t\tend if;" << endl;
				outfile << endl;
			};
		};
	};

	if (!first) {
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << endl;
	};

	outfile << "-- IP impl.op.inv.retbuf --- IEND" << endl;
};
// IP cust --- IEND
