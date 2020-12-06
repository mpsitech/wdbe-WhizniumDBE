/**
	* \file WdbeWrdevCtr.cpp
	* Wdbe operation processor - write C++ code for controller (implementation)
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

#include "WdbeWrdevCtr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrdev;

/******************************************************************************
 namespace WdbeWrdevCtr
 ******************************************************************************/

DpchRetWdbe* WdbeWrdevCtr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevCtr* dpchinv
		) {
	ubigint refWdbeMController = dpchinv->refWdbeMController;
	string folder = dpchinv->folder;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMController* ctr = NULL;

	ListWdbeMVector vecs;
	ListWdbeMCommand cmds;
	ListWdbeMError errs;

	string srefCtr;
	unsigned int num = 0;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(refWdbeMController, &ctr)) {
		dbswdbe->tblwdbemvector->loadRstByHktHku(VecWdbeVMVectorHkTbl::CTR, ctr->ref, false, vecs);
		dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);
		dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, errs);

		dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(ctr->refWdbeMModule), srefCtr);

		dbswdbe->loadUintBySQL("SELECT TblWdbeMVectoritem.vecNum FROM TblWdbeMModule, TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMModule.ref = " + to_string(ctr->refWdbeMModule) + " AND TblWdbeMVector.hkIxVTbl = "
					+ to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = TblWdbeMModule.hkUref AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref LIKE 'VecV%Controller' AND TblWdbeMVectoritem.sref = '"
					+ srefCtr + "'", num);

		// CtrXxxxYyyyZzzzz.h
		s = xchg->tmppath + "/" + folder + "/" + ctr->Fullsref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeCtrH(dbswdbe, outfile, Easy, ctr, vecs, cmds, errs);
		outfile.close();

		// CtrXxxxYyyyZzzzz.cpp
		s = xchg->tmppath + "/" + folder + "/" + ctr->Fullsref + ".cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeCtrCpp(dbswdbe, outfile, Easy, ctr, num, srefCtr, vecs, cmds, errs);
		outfile.close();

		delete ctr;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrdevCtr::writeCtrH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMController* ctr
			, ListWdbeMVector& vecs
			, ListWdbeMCommand& cmds
			, ListWdbeMError& errs
		) {
	WdbeMVector* vec = NULL;

	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	WdbeMError* err = NULL;

	ListWdbeAMErrorPar epas;

	set<string> unqsrefsUnts;

	string supsref, subsref;

	string srefroot;

	string s;

	// --- include.vecs
	outfile << "// IP include.vecs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);

		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];

			if (ipa->refWdbeMVector != 0)
				if (dbswdbe->loadStringBySQL("SELECT TblWdbeMUnit.Fullsref FROM TblWdbeMUnit, TblWdbeMVector WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMUnit.ref = TblWdbeMVector.hkUref AND TblWdbeMVector.ref = "
							+ to_string(ipa->refWdbeMVector) , s))
					unqsrefsUnts.insert(s);
		};

		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];

			if (rpa->refWdbeMVector != 0)
				if (dbswdbe->loadStringBySQL("SELECT TblWdbeMUnit.Fullsref FROM TblWdbeMUnit, TblWdbeMVector WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMUnit.ref = TblWdbeMVector.hkUref AND TblWdbeMVector.ref = "
							+ to_string(rpa->refWdbeMVector) , s))
					unqsrefsUnts.insert(s);
		};
	};

	for (auto it = unqsrefsUnts.begin(); it != unqsrefsUnts.end(); it++) outfile << "#include \"" << (*it) << "_vecs.h\"" << endl;

	outfile << "// IP include.vecs --- IEND" << endl;

	// --- fsrs.cmds
	outfile << "// IP fsrs.cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);
		if (rpas.nodes.size() > 0) outfile << "#define " << cmd->Fullsref << " " << ctr->Fullsref << "::Cmd" << StrMod::cap(cmd->sref) << endl;
	};
	outfile << "// IP fsrs.cmds --- IEND" << endl;

	// --- fsrs.vecs
	outfile << "// IP fsrs.vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		outfile << "#define " << vec->sref << " " << ctr->Fullsref << "::Vec" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+ctr->Fullsref.length()-3) << endl;
	};
	outfile << "// IP fsrs.vecs --- IEND" << endl;

	// --- speccmds
	outfile << "// IP speccmds --- IBEGIN" << endl;
	if (!Easy) {
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];

			Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);
			if (rpas.nodes.size() > 0) writeSpeccmdH(dbswdbe, outfile, cmd, rpas, supsref, subsref);
		};
	};
	outfile << "// IP speccmds --- IEND" << endl;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecH(dbswdbe, outfile, vec, NULL, NULL, ctr, true, 1);
	};
	outfile << "// IP vecs --- IEND" << endl;

	// --- constructor.easy*
	if (Easy) outfile << "// IP constructor.easy --- AFFIRM" << endl;
	else outfile << "// IP constructor.easy --- REMOVE" << endl;

	// --- constructor.full*
	if (!Easy) outfile << "// IP constructor.full --- AFFIRM" << endl;
	else outfile << "// IP constructor.full --- REMOVE" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);
		writeCmdH(dbswdbe, outfile, Easy, cmd, ipas, rpas, supsref, subsref);
	};
	outfile << "// IP cmds --- IEND" << endl;

	// --- vecerr*
	if (errs.nodes.size() > 0) outfile << "// IP vecerr --- AFFIRM" << endl;
	else outfile << "// IP vecerr --- REMOVE" << endl;

	// --- errs
	outfile << "// IP errs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < errs.nodes.size(); i++) {
		err = errs.nodes[i];

		Wdbe::analyzeErr(dbswdbe, err, NULL, ctr, epas, supsref, subsref);
		writeErrH(dbswdbe, outfile, err);
	};
	outfile << "// IP errs --- IEND" << endl;
};

void WdbeWrdevCtr::writeCtrCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMController* ctr
			, const utinyint tixCtr
			, const string& srefCtr
			, ListWdbeMVector& vecs
			, ListWdbeMCommand& cmds
			, ListWdbeMError& errs
		) {
	WdbeMVector* vec = NULL;

	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	ListWdbeAMCommandRetpar rpas;

	WdbeMError* err = NULL;

	ListWdbeAMErrorPar epas;

	string supsref, subsref;

	// --- speccmds
	outfile << "// IP speccmds --- IBEGIN" << endl;
	if (!Easy) {
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];

			Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);
			if (rpas.nodes.size() > 0) writeSpeccmdCpp(dbswdbe, outfile, tixCtr, cmd, rpas, supsref, subsref);
		};
	};
	outfile << "// IP speccmds --- IEND" << endl;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecCpp(dbswdbe, outfile, vec, NULL, NULL, ctr, true);
	};
	outfile << "// IP vecs --- IEND" << endl;

	// --- constructor.easy*
	if (Easy) outfile << "// IP constructor.easy --- AFFIRM" << endl;
	else outfile << "// IP constructor.easy --- REMOVE" << endl;

	// --- constructor.full*
	if (!Easy) outfile << "// IP constructor.full --- AFFIRM" << endl;
	else outfile << "// IP constructor.full --- REMOVE" << endl;

	// --- getNewCmd
	outfile << "// IP getNewCmd --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (tixVCommand == VecVCommand::" << StrMod::uc(cmd->sref) << ") cmd = getNewCmd" << StrMod::cap(cmd->sref) << "();" << endl;
	};
	outfile << "// IP getNewCmd --- IEND" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, NULL, ctr, ipas, rpas, supsref, subsref);
		writeCmdCpp(dbswdbe, outfile, Easy, tixCtr, srefCtr, (errs.nodes.size() > 0), cmd, ipas, rpas, supsref, subsref);
	};
	outfile << "// IP cmds --- IEND" << endl;

	// --- vecerr*
	if (errs.nodes.size() > 0) outfile << "// IP vecerr --- AFFIRM" << endl;
	else outfile << "// IP vecerr --- REMOVE" << endl;

	// --- getNewErr
	outfile << "// IP getNewErr --- IBEGIN" << endl;
	for (unsigned int i = 0; i < errs.nodes.size(); i++) {
		err = errs.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (tixVError == VecVError::" << StrMod::uc(err->sref) << ") err = getNewErr" << StrMod::cap(err->sref) << "();" << endl;
	};
	outfile << "// IP getNewErr --- IEND" << endl;

	// --- errs
	outfile << "// IP errs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < errs.nodes.size(); i++) {
		err = errs.nodes[i];

		Wdbe::analyzeErr(dbswdbe, err, NULL, ctr, epas, supsref, subsref);
		writeErrCpp(dbswdbe, outfile, err, epas, supsref, subsref);
	};
	outfile << "// IP errs --- IEND" << endl;
};
// IP cust --- IEND
