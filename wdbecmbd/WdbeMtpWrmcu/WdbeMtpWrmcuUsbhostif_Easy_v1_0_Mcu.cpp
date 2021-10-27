/**
	* \file WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrmcu* dpchinv
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

		// xxxx/Hostif.c
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".c.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlC(dbswdbe, outfile, Prjshort, Untsref, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu::writeMdlC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	ListWdbeMModule untmdls;
	WdbeMModule* untmdl = NULL;

	string Rxtx;

	string srefMgmt;
	string sref, srefrootMgmt, srefrootCor;

	vector<string> srefsImbRd, srefsImbWr;
	vector<string> srefsMgmtImbRd, srefsMgmtImbWr;
	vector<string> srefrootsMgmtImbRd, srefrootsMgmtImbWr;
	vector<string> srefrootsCorImbRd, srefrootsCorImbWr;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	uint cnt;

	unsigned int ix;

	string indent;

	bool first, first2;

	dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, untmdls);

	dbswdbe->loadStringBySQL("SELECT TblWdbeMModule.sref FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
				+ to_string(mdl->ref) + " AND srefKFunction = 'rxtx'", Rxtx);
	Rxtx = StrMod::cap(Rxtx);

	// --- analyze buffer transfers

	// exact copy from WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {

			if (dbswdbe->loadStringBySQL("SELECT TblWdbeMModule.sref FROM TblWdbeMModule, TblWdbeRMModuleMModule AS mdlRmdl1, TblWdbeRMModuleMModule AS mdlRmdl2 WHERE mdlRmdl2.ctdRefWdbeMModule = "
						+ to_string(untmdl->ref) + " AND mdlRmdl2.corRefWdbeMModule = " + to_string(mdl->ref)
						+ " AND mdlRmdl1.ctdRefWdbeMModule = mdlRmdl2.ctdRefWdbeMModule AND TblWdbeMModule.ref = mdlRmdl1.corRefWdbeMModule AND mdlRmdl1.srefKFunction = 'mgmt'", srefMgmt)) {

				if (!Wdbe::getImbsrefs(dbswdbe, untmdl->ref, sref, srefrootMgmt, srefrootCor)) {
					srefsMgmtImbRd.push_back(StrMod::cap(srefMgmt));
					srefsImbRd.push_back(StrMod::cap(sref));
					srefrootsMgmtImbRd.push_back(srefrootMgmt);
					srefrootsCorImbRd.push_back(srefrootCor);

				} else {
					srefsMgmtImbWr.push_back(StrMod::cap(srefMgmt));
					srefsImbWr.push_back(StrMod::cap(sref));
					srefrootsMgmtImbWr.push_back(srefrootMgmt);
					srefrootsCorImbWr.push_back(srefrootCor);
				};
			};
		};
	};

	// --- op.rxopC.cmdret
	outfile << "// IP op.rxopC.cmdret --- IBEGIN" << endl;

	// return types immsng and statsng

	first = true; // first command (any controller)

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			// count relevant commands
			cnt = 0;
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];
				if ((cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG)) cnt++;
			};

			if (cnt > 0) {
				if (cnt == 1) {
					for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
						cmd = cmds.nodes[j];
						if ((cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG)) break;
					};

					indent = "\t\t\t\t\t";
				} else indent = "\t\t\t\t\t\t";

				outfile << "\t\t\t\t";

				if (first) first = false;
				else outfile << "} else ";

				outfile << "if ";
				if (cnt == 1) outfile << "(";
				outfile << "(opbuf[IXOPBUF_controller] == VECVCONTROLLER_" << untmdl->sref << ")";
				if (cnt == 1) outfile << " && (opbuf[IXOPBUF_command] == VECV" << StrMod::uc(untmdl->sref) << "COMMAND_" << cmd->sref << "))";
				outfile << " {" << endl;

				first2 = true; // first command (per controller)

				for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
					cmd = cmds.nodes[j];

					if ((cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG)) {
						if (cnt > 1) {
							outfile << "\t\t\t\t\t";

							if (first2) first2 = false;
							else outfile << "} else ";

							outfile << "if (opbuf[IXOPBUF_command] == VECV" << StrMod::uc(untmdl->sref) << "COMMAND_" << cmd->sref << ") {" << endl;
						};

						if (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) {
							outfile << indent << "flags.reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " = 1;" << endl;
							outfile << indent << "SET_EVT_reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << "();" << endl;
							outfile << indent << "stateOp = stateOpVoidinv;" << endl;

						} else if (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) {
							dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

							ix = 0;
							for (unsigned int k = rpas.nodes.size(); k > 0; k--) {
								rpa = rpas.nodes[k - 1];
								ix += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);
							};

							if (ix > 0) {
								outfile << indent << "memcpy(buf, (unsigned char*) &shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref;
								if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) outfile << "Len";
								outfile << StrMod::cap(rpa->sref);
								outfile << ", " << (ix + 1) << ");" << endl;
							};

							ix = 0;
							for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
								rpa = rpas.nodes[k];

								if (rpa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << indent << "if (shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << StrMod::cap(rpa->sref) << ") txbuf[" << ix << "] = TRU8; else txbuf[" << ix << "] = FLS8;" << endl;

								ix += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);
							};

							outfile << indent << "stateOp = stateOpTxA;" << endl;
						};

						if (cnt > 1) outfile << "\t\t\t\t\t};" << endl;
					};
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\t};" << endl;

	outfile << "// IP op.rxopC.cmdret --- IEND" << endl;

	// --- op.rxopC.bufxf
	outfile << "// IP op.rxopC.bufxf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		outfile << "\t\t\t} else if ((opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbRd[i]) << ") && (shrdat" << srefsMgmtImbRd[i] << ".avllen" << srefrootsMgmtImbRd[i] << " > 0)) {" << endl;
		outfile << "\t\t\t\tshrdat" << Rxtx << ".len = (opbuf[IXOPBUF_length] << 8) + opbuf[IXOPBUF_length+1];" << endl;
		outfile << endl;

		outfile << "\t\t\t\tif (shrdat" << Rxtx << ".len == shrdat" << srefsMgmtImbRd[i] << ".avllen" << srefrootsMgmtImbRd[i] << ") {" << endl;
		outfile << "\t\t\t\t\tflags.req" << srefsImbRd[i] << " = 1;" << endl;
		outfile << "\t\t\t\t\tSET_EVT_req" << srefsImbRd[i] << "();" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\tstateOp = stateOpTxbufA;" << endl;
		outfile << "\t\t\t\t};" << endl;
	};

	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		outfile << "\t\t\t} else if ((opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbWr[i]) << ") && (shrdat" << srefsMgmtImbWr[i] << ".avllen" << srefrootsMgmtImbWr[i] << " > 0)) {" << endl;
		outfile << "\t\t\t\ticrc = (opbuf[IXOPBUF_length] << 8) + opbuf[IXOPBUF_length+1];" << endl;
		outfile << "\t\t\t\tshrdat" << Rxtx << ".len = icrc + 2;" << endl;
		outfile << endl;

		outfile << "\t\t\t\tif (icrc == shrdat" << srefsMgmtImbWr[i] << ".avllen" << srefrootsMgmtImbWr[i] << ") stateOp = stateOpRxbufA;" << endl;
	};

	outfile << "// IP op.rxopC.bufxf --- IEND" << endl;

	// --- op.voidinv
	outfile << "// IP op.voidinv --- IBEGIN" << endl;

	// return type immsng

	first = true;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) {
					outfile << "\t\t\t\t";

					if (first) first = false;
					else outfile << "} else ";

					outfile << "if (flags.ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " == 1) {" << endl;

					dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

					ix = 0;
					for (unsigned int k = rpas.nodes.size(); k > 0; k--) {
						rpa = rpas.nodes[k - 1];
						ix += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);
					};

					if (ix > 0) {
						outfile << "\t\t\t\tmemcpy(buf, (unsigned char*) &shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref;
						if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) outfile << "Len";
						outfile << StrMod::cap(rpa->sref);
						outfile << ", " << (ix + 1) << ");" << endl;
					};

					outfile << "\t\t\t\tflags.reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " = 0;" << endl;
					outfile << "\t\t\t\tSET_EVT_reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << "();" << endl;
					outfile << "\t\t\t\tstateOp = stateOpTxA;" << endl;
	      };
      };

      if (!first) outfile << "};" << endl;
		};
	};
	outfile << "// IP op.voidinv --- IEND" << endl;

	// --- op.txbuf*
	if (srefsImbRd.size() > 0) {
		outfile << "// IP op.txbuf --- AFFIRM" << endl;

		// --- op.txbufA.first
		outfile << "// IP op.txbufA.first --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbRd[i]) << ") *buf = shrdat" << srefsImbRd[i] << "." << StrMod::uncap(srefrootsMgmtImbRd[i]) << "D;" << endl;
		};

		outfile << "// IP op.txbufA.first --- IEND" << endl;

		// --- op.txbufB.done
		outfile << "// IP op.txbufB.done --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbRd[i]) << ") {" << endl;

			outfile << "\t\t\t\t\tflags.dne" << srefsImbRd[i] << " = 1;" << endl;
			outfile << "\t\t\t\t\tSET_EVT_dne" << srefsImbRd[i] << "();" << endl;
		};

		outfile << "// IP op.txbufB.done --- IEND" << endl;

		// --- op.txbufB.strobe
		outfile << "// IP op.txbufB.strobe --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbRd[i]) << ") SET_EVT_strb" << srefsImbRd[i] << "D();" << endl;
		};

		outfile << "// IP op.txbufB.strobe --- IEND" << endl;

		// --- op.txbufC
		outfile << "// IP op.txbufC --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbRd[i]) << ") buf[i] = shrdat" << srefsImbRd[i] << "." << StrMod::uncap(srefrootsMgmtImbRd[i]) << "D;" << endl;
		};

		outfile << "// IP op.txbufC --- IEND" << endl;

	} else outfile << "// IP op.txbuf --- REMOVE" << endl;

	// --- op.rxD
	outfile << "// IP op.rxD --- IBEGIN" << endl;

	// at least one invocation parameter, return type void

	first = true; // first command (any controller)

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			// count relevant commands
			cnt = 0;
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];
				if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) cnt++;
			};

			if (cnt > 0) {
				if (cnt == 1) {
					for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
						cmd = cmds.nodes[j];
						if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) break;
					};

					indent = "\t\t\t\t";
				} else indent = "\t\t\t\t\t";

				outfile << "\t\t\t";

				if (first) first = false;
				else outfile << "} else ";

				outfile << "if ";
				if (cnt == 1) outfile << "(";
				outfile << "(opbuf[IXOPBUF_controller] == VECVCONTROLLER_" << untmdl->sref << ")";
				if (cnt == 1) outfile << " && (opbuf[IXOPBUF_command] == VECV" << StrMod::uc(untmdl->sref) << "COMMAND_" << cmd->sref << "))";
				outfile << " {" << endl;

				first2 = true; // first command (per controller)

				for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
					cmd = cmds.nodes[j];

					if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) {
						if (cnt > 1) {
							outfile << "\t\t\t\t";

							if (first2) first2 = false;
							else outfile << "} else ";

							outfile << "if (opbuf[IXOPBUF_command] == VECV" << StrMod::uc(untmdl->sref) << "COMMAND_" << cmd->sref << ") {" << endl;
						};

						outfile << indent << "flags.reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " = 1;" << endl;
						outfile << indent << "SET_EVT_reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << "();" << endl;
						outfile << indent << "stateOp = stateOpInv;" << endl;
					};
				};
				if (cnt > 1) outfile << "\t\t\t\t};" << endl;
			};
		};
	};

	if (!first) outfile << "\t\t\t};" << endl;

	outfile << "// IP op.rxD --- IEND" << endl;

	// --- op.inv
	outfile << "// IP op.inv --- IBEGIN" << endl;

	first = true; // first command (any controller)

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) {
					outfile << "\t\t\t";

					if (first) first = false;
					else outfile << "} else ";

					outfile << "if (flags.ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " == 1) {" << endl;

					outfile << "\t\t\t\tflags.reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " = 0;" << endl;
					outfile << "\t\t\t\tSET_EVT_reqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << "();" << endl;
					outfile << "\t\t\t\tstateOp = stateOpTxackA;" << endl;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t};" << endl;

	outfile << "// IP op.inv --- IEND" << endl;

	// --- op.rxbuf*
	if (srefsImbWr.size() > 0) {
		outfile << "// IP op.rxbuf --- AFFIRM" << endl;

		// --- op.rxbufC
		outfile << "// IP op.rxbufC --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			outfile << "\t\t\t\t\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbWr[i]) << ") {" << endl;

			outfile << "\t\t\t\t\t\tflags.req" << srefsImbWr[i] << " = 0;" << endl;
			outfile << "\t\t\t\t\t\tSET_EVT_req" << srefsImbWr[i] << "();" << endl;
		};

		outfile << "// IP op.rxbufC --- IEND" << endl;

		// --- op.rxbufE.done
		outfile << "// IP op.rxbufE.done --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			outfile << "\t\t\t\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbWr[i]) << ") {" << endl;

			outfile << "\t\t\t\t\tflags.dne" << srefsImbWr[i] << " = 1;" << endl;
			outfile << "\t\t\t\t\tSET_EVT_dne" << srefsImbWr[i] << "();" << endl;
		};

		outfile << "// IP op.rxbufE.done --- IEND" << endl;

		// --- op.rxbufE.strobe
		outfile << "// IP op.rxbufE.strobe --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			outfile << "\t\t\t\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbWr[i]) << ") {" << endl;

			outfile << "\t\t\t\t\tshrdat" << srefrootsMgmtImbWr[i] << "." << StrMod::uncap(srefrootsMgmtImbWr[i]) << "D = buf[i];" << endl;
			outfile << "\t\t\t\t\tSET_EVT_strb" << srefsImbWr[i] << "D();" << endl;
		};

		outfile << "// IP op.rxbufE.strobe --- IEND" << endl;

		// --- op.rxbufE.strobe
		outfile << "// IP op.rxbufF --- IBEGIN" << endl;

		outfile << "\t\t\tif";
		if (srefsImbWr.size() > 1) outfile << " (";

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != 0) outfile << " ||";
			outfile << " ((opbuf[IXOPBUF_buffer] == VECWBUFFER_" << StrMod::uncap(srefrootsCorImbWr[i]) << ") && (flags.ack" << srefsImbWr[i] << " == 0))";
		};

		if (srefsImbWr.size() > 1) outfile << " )";
		outfile << " {" << endl;

		outfile << "// IP op.rxbufF --- IEND" << endl;

	} else outfile << "// IP op.rxbuf --- REMOVE" << endl;
};
// IP cust --- IEND
