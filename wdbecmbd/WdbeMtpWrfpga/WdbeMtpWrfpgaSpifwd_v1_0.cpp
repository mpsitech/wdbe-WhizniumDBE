/**
	* \file WdbeMtpWrfpgaSpifwd_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaSpifwd_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaSpifwd_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaSpifwd_v1_0::run(
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

		// xxxx/Xxxif.vhd
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
void WdbeMtpWrfpgaSpifwd_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	// ex.: imb->sref = "qcdifToHostif", mdl->sref = "rdbuf", Imbshort = "FromQcdif"

	ubigint ref;

	WdbeMUnit* unt = NULL;
	string Trguntsref;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;

	set<ubigint> refsImbsRd, refsImbsWr;

	ubigint refMdlCmdinvbuf = 0;
	ubigint refMdlCmdretbuf = 0;

	WdbeMImbuf* cmdretbuf = NULL;
	WdbeMImbuf* cmdinvbuf = NULL;

	string tixCmdretbuf;
	string tixCmdinvbuf;

	string Imbshort;

	bool hasrdbuf, haswrbuf;

	usmallint wReqlenRdbuf = 0;
	usmallint wReqlenWrbuf = 0;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	unsigned int ix;

	string s;

	bool first, found;

	if (dbswdbe->tblwdbemunit->loadRecBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMController, TblWdbeMUnit WHERE TblWdbeMController.refWdbeMModule = " + to_string(mdl->ref) + " AND TblWdbeMUnit.ref = TblWdbeMController.fwdRefWdbeMUnit", &unt)) {
		Trguntsref = StrMod::cap(unt->sref);

		dbswdbe->loadRefBySQL("SELECT TblWdbeMModule2.ref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMModule AS TblWdbeMModule2 WHERE TblWdbeMModule1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDINV) + " AND TblWdbeMModule1.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule1.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule2.supRefWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule2.sref = 'buf'", refMdlCmdinvbuf);
		dbswdbe->loadRefBySQL("SELECT TblWdbeMModule2.ref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMModule AS TblWdbeMModule2 WHERE TblWdbeMModule1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDRET) + " AND TblWdbeMModule1.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule1.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule2.supRefWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule2.sref = 'buf'", refMdlCmdretbuf);

		dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT TblWdbeMImbuf.* FROM TblWdbeMModule, TblWdbeMImbuf WHERE TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF) + " AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
					+ " AND TblWdbeMModule.hkUref = " + to_string(unt->ref) + " AND TblWdbeMImbuf.corRefWdbeMModule = TblWdbeMModule.ref ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMImbuf.sref ASC", false, imbs);

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (imb->ixVDir == VecWdbeVMImbufDir::IN) refsImbsWr.insert(imb->ref);
			else if (imb->ixVDir == VecWdbeVMImbufDir::OUT) refsImbsRd.insert(imb->ref);

			if (imb->refWdbeMModule == refMdlCmdinvbuf) {
				cmdinvbuf = imb;
				tixCmdinvbuf = "tixW" + Prjshort + Trguntsref + "Buffer" + StrMod::cap(imb->sref);
			};
			if (imb->refWdbeMModule == refMdlCmdretbuf) {
				cmdretbuf = imb;
				tixCmdretbuf = "tixW" + Prjshort + Trguntsref + "Buffer" + StrMod::cap(imb->sref);
			};
		};

		dbswdbe->tblwdbemvectoritem->loadRstBySQL("SELECT TblWdbeMVectoritem.* FROM TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = "
					+ to_string(unt->ref) + " AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref = 'VecW" + unt->Fullsref.substr(3) + "Buffer' ORDER BY TblWdbeMVectoritem.vecNum ASC", false, vits);

		delete unt;
	};

	// non-FPGA targets: dummy cmdretbuf and cmdinvbuf
	if (!cmdretbuf) tixCmdretbuf = "x\"01\"";
	if (!cmdinvbuf) tixCmdinvbuf = "x\"02\"";

	hasrdbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rdbuf'", ref);
	if (hasrdbuf) if (Wdbe::getMpa(dbswdbe, ref, "size", s)) wReqlenRdbuf = Wdbe::valToWidth(1024*atoi(s.c_str()));

	haswrbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'wrbuf'", ref);
	if (haswrbuf) if (Wdbe::getMpa(dbswdbe, ref, "size", s)) wReqlenWrbuf = Wdbe::valToWidth(1024*atoi(s.c_str()));

	// --- sigs.tkns
	outfile << "-- IP sigs.tkns --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
		imb = imbs.nodes[i];

		Imbshort = Wdbe::getImbshort(imb);

		if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) )
					outfile << "\tsignal tkn" << Imbshort << ": std_logic_vector(7 downto 0) := tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
	};
	
	if (!cmdretbuf) outfile << "\tsignal tknFromCmdret: std_logic_vector(7 downto 0) := " << tixCmdretbuf << ";" << endl;
	if (!cmdinvbuf) outfile << "\tsignal tknToCmdinv: std_logic_vector(7 downto 0) := " << tixCmdinvbuf << ";" << endl;
	outfile << "-- IP sigs.tkns --- IEND" << endl;

	// --- sigs.ixReqbxs
	outfile << "-- IP sigs.ixReqbxs --- IBEGIN" << endl;
	ix = 1;
	for (unsigned int i = 0; i < 8;i++,ix*=2) {
		found = false;
		for (unsigned int j = 0; j < vits.nodes.size(); j++) {
			vit = vits.nodes[j];

			if (vit->vecNum == ix) {
				for (unsigned int k = 0; k < imbs.nodes.size(); k++) {
					imb = imbs.nodes[k];

					if (imb->sref == vit->sref) {
						Imbshort = Wdbe::getImbshort(imb);

						outfile << "\tconstant ixReqbx" << Imbshort << ": natural := " << i << ";" << endl;

						found = true;
						break;
					};
				};
			};

			if (found) break;
		};
	};

	if (!cmdretbuf) outfile << "\tconstant ixReqbxFromCmdret: natural := 0;" << endl;
	if (!cmdinvbuf) outfile << "\tconstant ixReqbxToCmdinv: natural := 1;" << endl;
	outfile << "-- IP sigs.ixReqbxs --- IEND" << endl;

	// --- sigs.rdbufBRead*
	if (hasrdbuf) outfile << "-- IP sigs.rdbufBRead --- AFFIRM" << endl;
	else outfile << "-- IP sigs.rdbufBRead --- REMOVE" << endl;

	// --- sigs.wrbufBWrite*
	if (haswrbuf) outfile << "-- IP sigs.wrbufBWrite --- AFFIRM" << endl;
	else outfile << "-- IP sigs.wrbufBWrite --- REMOVE" << endl;

	// --- sigs.dRdbuf*
	if (hasrdbuf) outfile << "-- IP sigs.dRdbuf --- AFFIRM" << endl;
	else outfile << "-- IP sigs.dRdbuf --- REMOVE" << endl;

	// --- sigs.dWrbuf*
	if (haswrbuf) outfile << "-- IP sigs.dWrbuf --- AFFIRM" << endl;
	else outfile << "-- IP sigs.dWrbuf --- REMOVE" << endl;

	// --- impl.cmd.lock.toCmdbuf
	outfile << "-- IP impl.cmd.lock.toCmdbuf --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tlenCmdbuf <= 0;" << endl;
	outfile << "-- IP impl.cmd.lock.toCmdbuf --- IEND" << endl;

	// --- impl.cmd.lock.fromCmdbuf
	outfile << "-- IP impl.cmd.lock.fromCmdbuf --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tbytecnt := 0;" << endl;
	outfile << endl;
				
	outfile << "\t\t\t\t\tdFromCmdbuf <= cmdbuf(0);" << endl;
	outfile << "-- IP impl.cmd.lock.fromCmdbuf --- IEND" << endl;

	// --- impl.cmd.lock.fwderr
	outfile << "-- IP impl.cmd.lock.fwderr --- IBEGIN" << endl;
	outfile << "\t\t\t\t\ti := ixCmdbufFwderrRoute+1;" << endl;
	outfile << "\t\t\t\t\tj := ixCmdbufRoute;" << endl;
	outfile << "-- IP impl.cmd.lock.fwderr --- IEND" << endl;

	// --- impl.cmd.prepFwderrA.last
	outfile << "-- IP impl.cmd.prepFwderrA.last --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVActionFwderr;" << endl;
	outfile << "\t\t\t\t\tcmdbuf(ixCmdbufFwderrRoute) <= tixV" << Prjshort << Untsref << "Controller" << StrMod::cap(mdl->sref) << ";" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\tlenCmdbuf <= lenCmdbufFwderr;" << endl;
	outfile << "-- IP impl.cmd.prepFwderrA.last --- IEND" << endl;

	// --- impl.cmd.prepFwderrA.load
	outfile << "-- IP impl.cmd.prepFwderrA.load --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tx := cmdbuf(j);" << endl;
	outfile << "-- IP impl.cmd.prepFwderrA.load --- IEND" << endl;

	// --- impl.cmd.prepFwderrB.store
	outfile << "-- IP impl.cmd.prepFwderrB.store --- IBEGIN" << endl;
	outfile << "\t\t\t\tcmdbuf(i) <= x;" << endl;
	outfile << endl;

	outfile << "\t\t\t\ti := i + 1;" << endl;
	outfile << "\t\t\t\tj := j + 1;" << endl;
	outfile << "-- IP impl.cmd.prepFwderrB.store --- IEND" << endl;

	// --- impl.cmd.prepErrBufxferRead --- mb not, is only cref!
	outfile << "-- IP impl.cmd.prepErrBufxferRead --- IBEGIN" << endl;
// ...
	outfile << "-- IP impl.cmd.prepErrBufxferRead --- IEND" << endl;

	// --- impl.cmd.prepErrBufxferWrite
	outfile << "-- IP impl.cmd.prepErrBufxferWrite --- IBEGIN" << endl;
// ...
	outfile << "-- IP impl.cmd.prepErrBufxferWrite --- IEND" << endl;

	// --- impl.cmd.toCmdbufA.reset
	outfile << "-- IP impl.cmd.toCmdbufA.reset --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tlenCmdbuf <= 0;" << endl;
	outfile << "-- IP impl.cmd.toCmdbufA.reset --- IEND" << endl;

	// --- impl.cmd.toCmdbufB
	outfile << "-- IP impl.cmd.toCmdbufB --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tcmdbuf(lenCmdbuf) <= dToCmdbuf;" << endl;
	outfile << "\t\t\t\t\tlenCmdbuf <= lenCmdbuf + 1;" << endl;
	outfile << "-- IP impl.cmd.toCmdbufB --- IEND" << endl;

	// --- impl.cmd.fromCmdbufA.out
	outfile << "-- IP impl.cmd.fromCmdbufA.out --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tdFromCmdbuf <= cmdbuf(bytecnt);" << endl;
	outfile << "-- IP impl.cmd.fromCmdbufA.out --- IEND" << endl;

	// --- impl.cmd.fromCmdbufB
	outfile << "-- IP impl.cmd.fromCmdbufB --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tbytecnt := bytecnt + 1;" << endl;
	outfile << "-- IP impl.cmd.fromCmdbufB --- IEND" << endl;

	// --- impl.op.reqbx
	outfile << "-- IP impl.op.reqbx --- IBEGIN" << endl;
	ix = 1;
	for (unsigned int i = 0; i < 8;i++,ix*=2) {
		found = false;

		for (unsigned int j = 0; j < vits.nodes.size(); j++) {
			vit = vits.nodes[j];

			if (vit->vecNum == ix) {
				for (unsigned int k = 0; k < imbs.nodes.size(); k++) {
					imb = imbs.nodes[k];

					if (imb->sref == vit->sref) {
						Imbshort = Wdbe::getImbshort(imb);

						outfile << "\treqbx(ixReqbx" << Imbshort << ") <= '1' when (";
						if (imb->ref == cmdinvbuf->ref) outfile << "ackOpToCmdLock='1' and lenCmdbuf/=0";
						else if (imb->ref == cmdretbuf->ref) outfile << "ackOpToCmdLock='1' and lenCmdbuf=0";
						else if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) outfile << "tixW" << Trguntsref << "BufferRead=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " and reqlenRdbuf/=0 and reqlenRdbuf_zero='0'";
						else if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) outfile << "tixW" << Trguntsref << "BufferWrite=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " and reqlenWrbuf/=0 and reqlenWrbuf_zero='0'";

						outfile << ") else '0';" << endl;

						found = true;
						break;
					};
				};
			};

			if (found) break;
		};
		
		if ((i == 0) && !cmdretbuf) {
			outfile << "\treqbx(ixReqbxFromCmdret) <= '1' when (ackOpToCmdLock='1' and lenCmdbuf=0) else '0';" << endl;
			found = true;
		};
		if ((i == 0) && !cmdinvbuf) {
			outfile << "\treqbx(ixReqbxToCmdinv) <= '1' when (ackOpToCmdLock='1' and lenCmdbuf/=0) else '0';" << endl;
			found = true;
		};
		
		if (!found) outfile << "\treqbx(" << i << ") <= '0';" << endl;
	};

	outfile << "-- IP impl.op.reqbx --- IEND" << endl;

	// --- impl.op.reqlen
	outfile << "-- IP impl.op.reqlen --- IBEGIN" << endl;
	outfile << "\treqlen <= std_logic_vector(to_unsigned(sizeCmdbuf, 32)) when (tkn=" << tixCmdretbuf << " or tkn=(not " << tixCmdretbuf << "))" << endl;
	outfile << "\t\t\t\telse std_logic_vector(to_unsigned(lenCmdbuf, 32)) when (tkn=" << tixCmdinvbuf << " or tkn=(not " << tixCmdinvbuf << "))" << endl;
	if (hasrdbuf) {
		outfile << "\t\t\t\telse " << valToSlv("0", 32-wReqlenRdbuf) << " & std_logic_vector(to_unsigned(reqlenRdbuf, " << wReqlenRdbuf << ")) when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ")";
			};
		};
		outfile << ")" << endl;
	};
	if (haswrbuf) {
		outfile << "\t\t\t\telse " << valToSlv("0", 32-wReqlenWrbuf) << " & std_logic_vector(to_unsigned(reqlenWrbuf, " << wReqlenWrbuf << ")) when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ")";
			};
		};
		outfile << ")" << endl;
	};
	outfile << "\t\t\t\telse (others => '0');" << endl;
	outfile << "-- IP impl.op.reqlen --- IEND" << endl;

	// --- impl.op.ackRxbuf
	outfile << "-- IP impl.op.ackRxbuf --- IBEGIN" << endl;
	outfile << "\tackRxbuf <= ackOpToCmdToCmdbuf when (tkn=" << tixCmdretbuf << " or tkn=(not " << tixCmdretbuf << "))" << endl;
	if (hasrdbuf) {
		outfile << "\t\t\t\telse ackRdbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ")";
			};
		};
		outfile << ")" << endl;
	};
	outfile << "\t\t\t\telse '0';" << endl;
	outfile << "-- IP impl.op.ackRxbuf --- IEND" << endl;

	// --- impl.op.ackTxbuf
	outfile << "-- IP impl.op.ackTxbuf --- IBEGIN" << endl;
	outfile << "\tackTxbuf <= ackOpToCmdFromCmdbuf when (tkn=" << tixCmdinvbuf << " or tkn=(not " << tixCmdinvbuf << "))" << endl;
	if (haswrbuf) {
		outfile << "\t\t\t\telse ackWrbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ")";
			};
		};
		outfile << ")" << endl;
	};
	outfile << "\t\t\t\telse '0';" << endl;
	outfile << "-- IP impl.op.ackTxbuf --- IEND" << endl;

	// --- impl.op.dTxbuf
	outfile << "-- IP impl.op.dTxbuf --- IBEGIN" << endl;
	outfile << "\tdTxbuf <= dFromCmdbuf when (tkn=" << tixCmdinvbuf << " or tkn=(not " << tixCmdinvbuf << "))" << endl;
	if (haswrbuf) {
		outfile << "\t\t\t\telse dWrbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ")";
			};
		};
		outfile << ")" << endl;
	};
	outfile << "\t\t\t\telse (others => '0');" << endl;
	outfile << "-- IP impl.op.dTxbuf --- IEND" << endl;

	// --- impl.op.bufs
	outfile << "-- IP impl.op.bufs --- IBEGIN" << endl;

	outfile << "\t-- to cmdbuf" << endl;
	if (cmdretbuf) {
		Imbshort = Wdbe::getImbshort(cmdretbuf);
		outfile << "\treqOpToCmdToCmdbuf <= reqRxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
		outfile << "\tdneOpToCmdToCmdbuf <= dneRxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
	} else {
		outfile << "\treqOpToCmdToCmdbuf <= reqRxbuf when tkn=tknFromCmdret else '0';" << endl;
		outfile << "\tdneOpToCmdToCmdbuf <= dneRxbuf when tkn=tknFromCmdret else '0';" << endl;
	};
	outfile << endl;

	outfile << "\tdToCmdbuf <= dRxbuf;" << endl;
	outfile << "\tstrbDToCmdbuf <= strbDRxbuf;" << endl;
	outfile << endl;

	outfile << "\t-- from cmdbuf" << endl;
	if (cmdinvbuf) {
		Imbshort = Wdbe::getImbshort(cmdinvbuf);
		outfile << "\treqOpToCmdFromCmdbuf <= reqTxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
		outfile << "\tdneOpToCmdFromCmdbuf <= dneTxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
	} else {
		outfile << "\treqOpToCmdFromCmdbuf <= reqTxbuf when tkn=tknToCmdinv else '0';" << endl;
		outfile << "\tdneOpToCmdFromCmdbuf <= dneTxbuf when tkn=tknToCmdinv else '0';" << endl;
	};
	outfile << endl;

	outfile << "\tstrbDFromCmdbuf <= strbDTxbuf;" << endl;
	outfile << endl;

	if (hasrdbuf) {
		outfile << "\t-- to rdbuf / from ";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << ", ";
				outfile << StrMod::uncap(Imbshort);
			};
		};
		outfile << endl;

		outfile << "\treqRdbuf <= reqRxbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tkn" << Imbshort;
			};
		};
		outfile << ") else '0';" << endl;

		outfile << "\tdneRdbuf <= dneRxbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tkn" << Imbshort;
			};
		};
		outfile << ") else '0';" << endl;

		outfile << endl;

		outfile << "\tdRdbuf <= dRxbuf;" << endl;
		outfile << "\tstrbDRdbuf <= strbDRxbuf;" << endl;
	};

	if (hasrdbuf && haswrbuf) outfile << endl;

	if (haswrbuf) {
		outfile << "\t-- from wrbuf / to ";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << ", ";
				outfile << StrMod::uncap(Imbshort);
			};
		};
		outfile << endl;

		outfile << "\treqWrbuf <= reqTxbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tkn" << Imbshort;
			};
		};
		outfile << ") else '0';" << endl;

		outfile << "\tdneWrbuf <= dneTxbuf when (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "tkn=tkn" << Imbshort;
			};
		};
		outfile << ") else '0';" << endl;

		outfile << endl;

		outfile << "\tstrbDWrbuf <= strbDTxbuf;" << endl;
	};
	outfile << "-- IP impl.op.bufs --- IEND" << endl;

	// --- impl.op.reqOpToReadErr*
	if (hasrdbuf) outfile << "-- IP impl.op.reqOpToReadErr --- AFFIRM" << endl;
	else outfile << "-- IP impl.op.reqOpToReadErr --- REMOVE" << endl;

	// --- impl.op.reqOpToWriteErr*
	if (haswrbuf) outfile << "-- IP impl.op.reqOpToWriteErr --- AFFIRM" << endl;
	else outfile << "-- IP impl.op.reqOpToWriteErr --- REMOVE" << endl;

	// --- impl.op.init
	outfile << "-- IP impl.op.init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
		imb = imbs.nodes[i];

		Imbshort = Wdbe::getImbshort(imb);

		if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) )
					outfile << "\t\t\t\ttkn" << Imbshort << " <= tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
	};

	if (!cmdretbuf) outfile << "\t\t\t\ttknFromCmdret <= " << tixCmdretbuf << ";" << endl;
	if (!cmdinvbuf) outfile << "\t\t\t\ttknToCmdinv <= " << tixCmdinvbuf << ";" << endl;
	outfile << "-- IP impl.op.init --- IEND" << endl;

	// --- impl.op.idle
	outfile << "-- IP impl.op.idle --- IBEGIN" << endl;
	outfile << "\t\t\t\telsif (arbbx/=x\"00\"";
	for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
		imb = imbs.nodes[i];

		if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
			Imbshort = Wdbe::getImbshort(imb);

			outfile << " or ";
			if (imb->ref == cmdretbuf->ref) outfile << "avlbx";
			else outfile << "reqbx";
			outfile << "(ixReqbx" << Imbshort << ")='1'";
		};
	};

	if (!cmdretbuf) outfile << " or avlbx(ixReqbxFromCmdret)='1'";
	if (!cmdinvbuf) outfile << " or reqbx(ixReqbxToCmdinv)='1'";

	outfile << " or wakeup='1') then" << endl;
	outfile << "-- IP impl.op.idle --- IEND" << endl;

	// --- impl.op.stepRetry.err
	outfile << "-- IP impl.op.stepRetry.err --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tif arbbx=" << tixCmdretbuf << " then" << endl;
	outfile << "\t\t\t\t\t\t-- no error handling for now" << endl;

	outfile << "\t\t\t\t\telsif arbbx=" << tixCmdinvbuf << " then" << endl;
	outfile << "\t\t\t\t\t\tstateOp <= stateOpFwderr;" << endl;

	if (hasrdbuf) {
		outfile << "\t\t\t\t\telsif (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) && (imb->ref != cmdretbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "arbbx=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref);
			};
		};
		outfile << ") then" << endl;
		outfile << "\t\t\t\t\t\tstateOp <= stateOpReadErr;" << endl;
	};

	if (haswrbuf) {
		outfile << "\t\t\t\t\telsif (";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsWr.find(imb->ref) != refsImbsWr.end()) && (imb->ref != cmdinvbuf->ref) ) {
				if (first) first = false;
				else outfile << " or ";
				outfile << "arbbx=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref);
			};
		};
		outfile << ") then" << endl;
		outfile << "\t\t\t\t\t\tstateOp <= stateOpWriteErr;" << endl;
	};

	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.stepRetry.err --- IEND" << endl;

	// --- impl.op.stepRetry
	outfile << "-- IP impl.op.stepRetry --- IBEGIN" << endl;
	if (cmdretbuf && cmdinvbuf) {
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				Imbshort = Wdbe::getImbshort(imb);

				if (!first) outfile << endl;

				outfile << "\t\t\t\t\t";
				if (first) first = false;
				else outfile << "els";
				outfile << "if arbbx=tixW" << Prjshort << Trguntsref << "Buffer" << StrMod::cap(imb->sref) << " then" << endl;

				outfile << "\t\t\t\t\t\tauxbuf(ixAuxbufTkn) <= tkn" << Imbshort << ";" << endl;
				outfile << "\t\t\t\t\t\ttkn <= tkn" << Imbshort << ";" << endl;
				outfile << endl;
				
				if (imb->ref != cmdretbuf->ref) {
					outfile << "\t\t\t\t\t\treqOpToCmdLock <= '0';" << endl;
					outfile << endl;
				};

				outfile << "\t\t\t\t\t\tstateOp <= stateOpTxA;" << endl;
			};
		};

	} else {
		outfile << "\t\t\t\t\tif arbbx=" << tixCmdretbuf << " then" << endl;
		outfile << "\t\t\t\t\t\tauxbuf(ixAuxbufTkn) <= tknFromCmdret;" << endl;
		outfile << "\t\t\t\t\t\ttkn <= tknFromCmdret;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tstateOp <= stateOpTxA;" << endl;

		outfile << "\t\t\t\t\telsif arbbx=" << tixCmdinvbuf << " then" << endl;
		outfile << "\t\t\t\t\t\tauxbuf(ixAuxbufTkn) <= tknToCmdinv;" << endl;
		outfile << "\t\t\t\t\t\ttkn <= tknToCmdinv;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\treqOpToCmdLock <= '0';" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tstateOp <= stateOpTxA;" << endl;
	};
	outfile << "-- IP impl.op.stepRetry --- IEND" << endl;

	// --- impl.op.xferTkn
	outfile << "-- IP impl.op.xferTkn --- IBEGIN" << endl;
	outfile << "\t\t\t\t\t\telsif (";

	if (cmdretbuf && cmdinvbuf) {
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";
				
				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};
	} else {
		outfile << "auxbuf(ixAuxbufTkn)=tknFromCmdret or auxbuf(ixAuxbufTkn)=tknToCmdinv";
	};

	outfile << ") then" << endl;
	outfile << "-- IP impl.op.xferTkn --- IEND" << endl;

	// --- impl.op.xferArblen.rd
	outfile << "-- IP impl.op.xferArblen.rd --- IBEGIN" << endl;
	outfile << "\t\t\t\t\t\tif ";
	if (cmdretbuf) {
		outfile << "(";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";
				
				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};
		outfile << ")";
	} else {
		outfile << "auxbuf(ixAuxbufTkn)=tknFromCmdret";
	};
	outfile << " then" << endl;
	outfile << "-- IP impl.op.xferArblen.rd --- IEND" << endl;

	// --- impl.op.xferArblen.wr
	outfile << "-- IP impl.op.xferArblen.wr --- IBEGIN" << endl;
	outfile << "\t\t\t\t\t\telsif ";
	if (cmdinvbuf) {
		outfile << "(";
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";
				
				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};
		outfile << ")";
	} else {
		outfile << "auxbuf(ixAuxbufTkn)=tknToCmdinv";
	};
	outfile << " then" << endl;
	outfile << "-- IP impl.op.xferArblen.wr --- IEND" << endl;

	// --- impl.op.cnfRd
	outfile << "-- IP impl.op.cnfRd --- IBEGIN" << endl;
	if (cmdretbuf) {
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				outfile << "\t\t\t\t\t";
				if (first) first = false;
				else outfile << "els";
				outfile << "if tkn=tkn" << Imbshort << " then" << endl;

				outfile << "\t\t\t\t\t\ttkn" << Imbshort << " <= not tkn" << Imbshort << ";" << endl;
			};
		};
	} else {
		outfile << "\t\t\t\t\tif tkn=tknFromCmdret then" << endl;
		outfile << "\t\t\t\t\t\ttknFromCmdret <= not tknFromCmdret;" << endl;
	};
	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.ring.cnfRd --- IEND" << endl;

	// --- impl.op.cnfWr
	outfile << "-- IP impl.op.cnfWr --- IBEGIN" << endl;
	if (cmdinvbuf) {
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				outfile << "\t\t\t\t\t";
				if (first) first = false;
				else outfile << "els";
				outfile << "if tkn=tkn" << Imbshort << " then" << endl;

				outfile << "\t\t\t\t\t\ttkn" << Imbshort << " <= not tkn" << Imbshort << ";" << endl;
			};
		};

	} else {
		outfile << "\t\t\t\t\tif tkn=tknToCmdinv then" << endl;
		outfile << "\t\t\t\t\t\ttknToCmdinv <= not tknToCmdinv;" << endl;
	};
	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.cnfWr --- IEND" << endl;

	// --- impl.op.readErr*
	if (hasrdbuf) outfile << "-- IP impl.op.readErr --- AFFIRM" << endl;
	else outfile << "-- IP impl.op.readErr --- REMOVE" << endl;

	// --- impl.op.writeErr*
	if (haswrbuf) outfile << "-- IP impl.op.writeErr --- AFFIRM" << endl;
	else outfile << "-- IP impl.op.writeErr --- REMOVE" << endl;

	// --- impl.rdbufBRead*
	if (hasrdbuf) outfile << "-- IP impl.rdbufBRead --- AFFIRM" << endl;
	else outfile << "-- IP impl.rdbufBRead --- REMOVE" << endl;

	// --- impl.wrbufBWrite*
	if (haswrbuf) outfile << "-- IP impl.wrbufBWrite --- AFFIRM" << endl;
	else outfile << "-- IP impl.wrbufBWrite --- REMOVE" << endl;
};
// IP cust --- IEND


