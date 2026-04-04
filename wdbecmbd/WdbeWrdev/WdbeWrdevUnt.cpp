/**
	* \file WdbeWrdevUnt.cpp
	* Wdbe operation processor - write C++ code for unit (implementation)
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

#include "WdbeWrdevUnt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrdev;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrdevUnt
 ******************************************************************************/

DpchRetWdbe* WdbeWrdevUnt::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevUnt* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;
	string folder = dpchinv->folder;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMUnit* unt = NULL;

	string srefroot;

	ListWdbeMVector vecs;
	ListWdbeMController ctrs;
	ListWdbeMImbuf imbs;
	ListWdbeMCommand cmds;
	ListWdbeMError errs;

	ubigint refHostif;
	uint ixImbCmdinv, ixImbCmdret;
	bool hasvecbuf, hasvecctr, hasvecfsm, hasveccmd, hasvecerr, hasspeccmd;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		Wdbe::analyzeUnt(dbswdbe, unt, srefroot, vecs, ctrs, imbs, cmds, errs, refHostif, ixImbCmdinv, ixImbCmdret, hasvecbuf, hasvecctr, hasvecfsm, hasveccmd, hasvecerr, hasspeccmd);

		// UntXxxxYyyy.h
		s = xchg->tmppath + "/" + folder + "/" + unt->Fullsref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntH(dbswdbe, outfile, Easy, unt, srefroot, ctrs, imbs, cmds, errs, refHostif, ixImbCmdinv, ixImbCmdret, hasvecbuf, hasvecctr, hasvecfsm, hasveccmd, hasvecerr, hasspeccmd);
		outfile.close();

		// UntXxxxYyyy.cpp
		s = xchg->tmppath + "/" + folder + "/" + unt->Fullsref + ".cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntCpp(dbswdbe, outfile, Easy, unt, srefroot, vecs, ctrs, imbs, cmds, errs, refHostif, ixImbCmdinv, ixImbCmdret, hasvecbuf, hasvecctr, hasvecfsm, hasveccmd, hasvecerr);
		outfile.close();

		// UntXxxxYyyy_vecs.h
		s = xchg->tmppath + "/" + folder + "/" + unt->Fullsref + "_vecs.h.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntvecsH(dbswdbe, outfile, unt, vecs);
		outfile.close();

		// UntXxxxYyyy_vecs.cpp
		s = xchg->tmppath + "/" + folder + "/" + unt->Fullsref + "_vecs.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntvecsCpp(dbswdbe, outfile, unt, vecs);
		outfile.close();

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrdevUnt::writeUntH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMUnit* unt
			, const string& srefroot
			, ListWdbeMController& ctrs
			, ListWdbeMImbuf& imbs
			, ListWdbeMCommand& cmds
			, ListWdbeMError& errs
			, const ubigint refHostif
			, const uint ixImbCmdinv
			, const uint ixImbCmdret
			, const bool hasvecbuf
			, const bool hasvecctr
			, const bool hasvecfsm
			, const bool hasveccmd
			, const bool hasvecerr
			, const bool hasspeccmd
		) {
	WdbeMController* ctr = NULL;

	WdbeMImbuf* imb = NULL;

	WdbeMCommand* cmd = NULL;

	WdbeMError* err = NULL;

	ListWdbeAMCommandInvpar ipas;
	ListWdbeAMCommandRetpar rpas;

	ListWdbeAMErrorPar epas;

	string supsref, subsref;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	// --- include.ctrs
	outfile << "// IP include.ctrs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
		ctr = ctrs.nodes[i];
		outfile << "#include \"" << ctr->Fullsref << ".h\"" << endl;
	};
	outfile << "// IP include.ctrs --- IEND" << endl;

	// --- ufpspeccmds*
	if (!Easy && hasspeccmd) outfile << "// IP ufpspeccmds --- AFFIRM" << endl;
	else outfile << "// IP ufpspeccmds --- REMOVE" << endl;

	// --- speccmds
	outfile << "// IP speccmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, unt, NULL, ipas, rpas, supsref, subsref);
		writeSpeccmdH(dbswdbe, outfile, Easy, cmd, ipas, rpas, supsref, subsref);
	};
	outfile << "// IP speccmds --- IEND" << endl;

	// --- ufpctrs*
	if (hasvecctr) outfile << "// IP ufpctrs --- AFFIRM" << endl;
	else outfile << "// IP ufpctrs --- REMOVE" << endl;

	if (Easy) {
		// --- umccmds*
		if (hasvecctr) outfile << "// IP umccmds --- REMOVE" << endl;
		else outfile << "// IP umccmds --- AFFIRM" << endl;

		// --- cmdvars
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];
			outfile << "\tCmd" << StrMod::cap(cmd->sref) << " cmd" << StrMod::cap(cmd->sref) << ";" << endl;
		};
	};

	// --- ctrs
	outfile << "// IP ctrs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
		ctr = ctrs.nodes[i];
		outfile << "\t" << ctr->Fullsref << "* " << StrMod::lc(ctr->Fullsref.substr(3+srefroot.length())) << ";" << endl;
	};
	outfile << "// IP ctrs --- IEND" << endl;

	// --- vecctr*
	if (hasvecctr) outfile << "// IP vecctr --- AFFIRM" << endl;
	else outfile << "// IP vecctr --- REMOVE" << endl;

	// --- vecbuf*
	if (hasvecbuf) outfile << "// IP vecbuf --- AFFIRM" << endl;
	else outfile << "// IP vecbuf --- REMOVE" << endl;

	// --- veccmd*
	if (hasveccmd) outfile << "// IP veccmd --- AFFIRM" << endl;
	else outfile << "// IP veccmd --- REMOVE" << endl;

	// --- ufpveccmd*
	if (hasvecctr) outfile << "// IP ufpveccmd --- AFFIRM" << endl;
	else outfile << "// IP ufpveccmd --- REMOVE" << endl;

	if (!Easy) {
		// --- vecerr*
		if (hasvecerr) outfile << "// IP vecerr --- AFFIRM" << endl;
		else outfile << "// IP vecerr --- REMOVE" << endl;

		// --- ufpvecerr*
		if (hasvecctr) outfile << "// IP ufpvecerr --- AFFIRM" << endl;
		else outfile << "// IP ufpvecerr --- REMOVE" << endl;
	};

	// --- getNewBufxf*
	if (hasvecbuf) outfile << "// IP getNewBufxf --- AFFIRM" << endl;
	else outfile << "// IP getNewBufxf --- REMOVE" << endl;

	// --- getNewCmd*
	if (hasveccmd) outfile << "// IP getNewCmd --- AFFIRM" << endl;
	else outfile << "// IP getNewCmd --- REMOVE" << endl;

	// --- ufpgetNewCmd*
	if (hasvecctr) outfile << "// IP ufpgetNewCmd --- AFFIRM" << endl;
	else outfile << "// IP ufpgetNewCmd --- REMOVE" << endl;

	if (!Easy) {
		// --- getNewErr*
		if (hasvecerr) outfile << "// IP getNewErr --- AFFIRM" << endl;
		else outfile << "// IP getNewErr --- REMOVE" << endl;

		// --- ufpgetNewErr*
		if (hasvecctr) outfile << "// IP ufpgetNewErr --- AFFIRM" << endl;
		else outfile << "// IP ufpgetNewErr --- REMOVE" << endl;
	};

	// --- vecfsm*
	if (hasvecfsm) outfile << "// IP vecfsm --- AFFIRM" << endl;
	else outfile << "// IP vecfsm --- REMOVE" << endl;

	// --- bufxfs
	outfile << "// IP bufxfs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
		imb = imbs.nodes[i];

		if ((i != ixImbCmdinv) && (i != ixImbCmdret)) {
			mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, sref, srefrootMgmt, srefrootCor);

			outfile << "\t";
			if (!Easy) outfile << "static ";
			outfile << "Dbecore::Bufxf* getNewBufxf" << srefrootCor << "(const size_t reqlen";
			if (Easy) outfile << ", unsigned char* buf";
			outfile << ");" << endl;

			if (mgmtToNotFrom) {
				outfile << "\tint write" << srefrootCor << "(const unsigned char* data, const size_t datalen";
				if (Easy) outfile << ", const bool copy";
				outfile << ", Dbecore::Reseval* reseval = NULL);" << endl;
			} else {
				outfile << "\tint read" << srefrootCor << "(const size_t reqlen, unsigned char*& data, size_t& datalen, Dbecore::Reseval* reseval = NULL);" << endl;
			};
			outfile << endl;
		};
	};
	outfile << "// IP bufxfs --- IEND" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, unt, NULL, ipas, rpas, supsref, subsref);
		writeCmdH(dbswdbe, outfile, Easy, cmd, ipas, rpas, supsref, subsref);
	};
	outfile << "// IP cmds --- IEND" << endl;

	if (!Easy) {
		// --- errs
		outfile << "// IP errs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < errs.nodes.size(); i++) {
			err = errs.nodes[i];

			Wdbe::analyzeErr(dbswdbe, err, unt, NULL, epas, supsref, subsref);
			writeErrH(dbswdbe, outfile, err);
		};
		outfile << "// IP errs --- IEND" << endl;
	};
};

void WdbeWrdevUnt::writeUntCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMUnit* unt
			, const string& srefroot
			, ListWdbeMVector& vecs
			, ListWdbeMController& ctrs
			, ListWdbeMImbuf& imbs
			, ListWdbeMCommand& cmds
			, ListWdbeMError& errs
			, const ubigint refHostif
			, const uint ixImbCmdinv
			, const uint ixImbCmdret
			, const bool hasvecbuf
			, const bool hasvecctr
			, const bool hasvecfsm
			, const bool hasveccmd
			, const bool hasvecerr
		) {
	WdbeMVector* vec = NULL;

	WdbeMController* ctr = NULL;

	WdbeMImbuf* imb = NULL;

	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	ListWdbeAMCommandRetpar rpas;

	WdbeMError* err = NULL;

	ListWdbeAMErrorPar epas;

	string supsref, subsref;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	string s, s2;

	bool first;

	if (Easy) {
		// --- init
		outfile << "// IP init --- IBEGIN" << endl;
		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];
			outfile << "\t" << StrMod::lc(ctr->Fullsref.substr(3+srefroot.length())) << " = new " << ctr->Fullsref << "(this);" << endl;
		};
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];
			outfile << "\tcmd" << StrMod::cap(cmd->sref) << " = getNewCmd" << StrMod::cap(cmd->sref) << "();" << endl;
		};
		outfile << "// IP init --- IEND" << endl;

		// --- term
		outfile << "// IP term --- IBEGIN" << endl;
		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];
			outfile << "\tdelete " << StrMod::lc(ctr->Fullsref.substr(3+srefroot.length())) << ";" << endl;
		};
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];
			outfile << "\tdelete cmd" << StrMod::cap(cmd->sref) << ";" << endl;
		};
		outfile << "// IP term --- IEND" << endl;

	} else {
		// --- speccmds
		outfile << "// IP speccmds --- IBEGIN" << endl;
		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];

			Wdbe::analyzeCmd(dbswdbe, cmd, unt, NULL, ipas, rpas, supsref, subsref);
			writeSpeccmdCpp(dbswdbe, outfile, Easy, 0, cmd, ipas, rpas, supsref, subsref);
		};
		outfile << "// IP speccmds --- IEND" << endl;

		// --- constructor
		outfile << "// IP constructor --- IBEGIN" << endl;
		if (ctrs.nodes.size() > 0) {
			outfile << endl;

			for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
				ctr = ctrs.nodes[i];
				outfile << "\t" << StrMod::lc(ctr->Fullsref.substr(3+srefroot.length())) << " = new " << ctr->Fullsref << "(xchg, ixVTarget, uref);" << endl;
			};
		};
		outfile << "// IP constructor --- IEND" << endl;

		// --- destructor
		outfile << "// IP destructor --- IBEGIN" << endl;
		if (ctrs.nodes.size() > 0) {
			for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
				ctr = ctrs.nodes[i];
				outfile << "\tdelete " << StrMod::lc(ctr->Fullsref.substr(3+srefroot.length())) << ";" << endl;
			};

			outfile << endl;
		};
		outfile << "// IP destructor --- IEND" << endl;
	};

	// --- vecctr*
	if (hasvecctr) outfile << "// IP vecctr --- AFFIRM" << endl;
	else outfile << "// IP vecctr --- REMOVE" << endl;

	// --- vecbuf*
	if (hasvecbuf) outfile << "// IP vecbuf --- AFFIRM" << endl;
	else outfile << "// IP vecbuf --- REMOVE" << endl;

	// --- veccmd*
	if (hasveccmd) outfile << "// IP veccmd --- AFFIRM" << endl;
	else outfile << "// IP veccmd --- REMOVE" << endl;

	// --- ufpveccmd*
	if (hasvecctr) outfile << "// IP ufpveccmd --- AFFIRM" << endl;
	else outfile << "// IP ufpveccmd --- REMOVE" << endl;

	if (hasvecctr) {
		// --- getTixVCommandBySref
		outfile << "// IP getTixVCommandBySref --- IBEGIN" << endl;
		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") tixVCommand = VecV" << ctr->Fullsref.substr(3) << "Command::getTix(sref);" << endl;
		};
		outfile << "// IP getTixVCommandBySref --- IEND" << endl;

		// --- getSrefByTixVCommand
		outfile << "// IP getSrefByTixVCommand --- IBEGIN" << endl;
		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") sref = VecV" << ctr->Fullsref.substr(3) << "Command::getSref(tixVCommand);" << endl;
		};
		outfile << "// IP getSrefByTixVCommand --- IEND" << endl;

		// --- fillFeedFCommand
		outfile << "// IP fillFeedFCommand --- IBEGIN" << endl;
		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") VecV" << ctr->Fullsref.substr(3) << "Command::fillFeed(feed);" << endl;
		};
		outfile << "// IP fillFeedFCommand --- IEND" << endl;
	};

	if (!Easy) {
		// --- vecerr*
		if (hasvecerr) outfile << "// IP vecerr --- AFFIRM" << endl;
		else outfile << "// IP vecerr --- REMOVE" << endl;

		// --- ufpvecerr*
		if (hasvecerr) outfile << "// IP ufpvecerr --- AFFIRM" << endl;
		else outfile << "// IP ufpvecerr --- REMOVE" << endl;

		if (hasvecerr) {
			// --- getTixVErrorBySref
			outfile << "// IP getTixVErrorBySref --- IBEGIN" << endl;
			for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
				ctr = ctrs.nodes[i];

				outfile << "\t";
				if (i != 0) outfile << "else ";
				outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") tixVError = VecV" << ctr->Fullsref.substr(3) << "Error::getTix(sref);" << endl;
			};
			outfile << "// IP getTixVErrorBySref --- IEND" << endl;

			// --- getSrefByTixVError
			outfile << "// IP getSrefByTixVError --- IBEGIN" << endl;
			for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
				ctr = ctrs.nodes[i];

				outfile << "\t";
				if (i != 0) outfile << "else ";
				outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") sref = VecV" << ctr->Fullsref.substr(3) << "Error::getSref(tixVError);" << endl;
			};
			outfile << "// IP getSrefByTixVError --- IEND" << endl;
		};
	};

	// --- getNewBufxf*
	if (hasvecbuf) outfile << "// IP getNewBufxf --- AFFIRM" << endl;
	else outfile << "// IP getNewBufxf --- REMOVE" << endl;

	if (hasvecbuf) {
		// --- getNewBufxf.get
		outfile << "// IP getNewBufxf.get --- IBEGIN" << endl;

		if (Easy) s2 = ", buf";
		else s2 = "";

		first = true;

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ((i != ixImbCmdinv) && (i != ixImbCmdret)) {
				Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, sref, srefrootMgmt, srefrootCor);

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";
				outfile << "if (tixVBuffer == VecV" << srefroot << "Buffer::" << StrMod::uc(sref) << ") bufxf = getNewBufxf" << srefrootCor << "(reqlen" << s2 << ");" << endl;
			};
		};
		outfile << "// IP getNewBufxf.get --- IEND" << endl;
	};

	// --- getNewCmd*
	if (hasveccmd) outfile << "// IP getNewCmd --- AFFIRM" << endl;
	else outfile << "// IP getNewCmd --- REMOVE" << endl;

	if (hasveccmd) {
		// --- getNewCmd.get
		outfile << "// IP getNewCmd.get --- IBEGIN" << endl;

		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (tixVCommand == VecV" << srefroot << "Command::" << StrMod::uc(cmd->sref) << ") cmd = getNewCmd" << StrMod::cap(cmd->sref) << "();" << endl;
		};

		outfile << "// IP getNewCmd.get --- IEND" << endl;
	};

	// --- ufpgetNewCmd*
	if (hasvecctr) outfile << "// IP ufpgetNewCmd --- AFFIRM" << endl;
	else outfile << "// IP ufpgetNewCmd --- REMOVE" << endl;

	if (hasvecctr) {
		// --- ufpgetNewCmd.get
		outfile << "// IP ufpgetNewCmd.get --- IBEGIN" << endl;

		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") cmd = " << ctr->Fullsref << "::getNewCmd(tixVCommand);" << endl;
		};

		outfile << "// IP ufpgetNewCmd.get --- IEND" << endl;
	};

	if (!Easy) {
		// --- getNewErr*
		if (hasvecerr) outfile << "// IP getNewErr --- AFFIRM" << endl;
		else outfile << "// IP getNewErr --- REMOVE" << endl;

		if (hasvecerr) {
			// --- getNewErr.get
			outfile << "// IP getNewErr.get --- IBEGIN" << endl;

			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];

				outfile << "\t";
				if (i != 0) outfile << "else ";
				outfile << "if (tixVError == VecV" << srefroot << "Error::" << StrMod::uc(err->sref) << ") err = getNewErr" << StrMod::cap(err->sref) << "();" << endl;
			};

			outfile << "// IP getNewErr.get --- IEND" << endl;
		};

		// --- ufpgetNewErr*
		if (hasvecerr) outfile << "// IP ufpgetNewErr --- AFFIRM" << endl;
		else outfile << "// IP ufpgetNewErr --- REMOVE" << endl;

		if (hasvecerr) {
			// --- ufpgetNewErr.get
			outfile << "// IP ufpgetNewErr.get --- IBEGIN" << endl;

			for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
				ctr = ctrs.nodes[i];

				outfile << "\t";
				if (i != 0) outfile << "else ";
				outfile << "if (tixVController == VecV" << srefroot << "Controller::" << StrMod::uc(ctr->Fullsref.substr(3+srefroot.length())) << ") err = " << ctr->Fullsref << "::getNewErr(tixVError);" << endl;
			};

			outfile << "// IP ufpgetNewErr.get --- IEND" << endl;
		};
	};

	// --- vecfsm*
	if (hasvecfsm) outfile << "// IP vecfsm --- AFFIRM" << endl;
	else outfile << "// IP vecfsm --- REMOVE" << endl;

	if (hasvecfsm) {
		// --- getGetSrefFsmstate
		outfile << "// IP getGetSrefFsmstate --- IBEGIN" << endl;
		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::FSM) outfile << "\tif (s == \"" << StrMod::lc(vec->sref.substr(3+1+srefroot.length())) << "\") return " << vec->sref << "::getSref;" << endl;
		};
		outfile << "// IP getGetSrefFsmstate --- IEND" << endl;

		// --- fillFeedFFsmstate
		outfile << "// IP fillFeedFFsmstate --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::FSM) {
				outfile << "\t";

				if (first) first = false;
				else outfile << "else ";

				outfile << "if (s == \"" << StrMod::lc(vec->sref.substr(3+1+srefroot.length())) << "\") " << vec->sref << "::fillFeed(feed);" << endl;
			};
		};
		outfile << "// IP fillFeedFFsmstate --- IEND" << endl;
	};
	// IP getGetSrefFsmstate --- INSERT

	// --- bufxfs
	outfile << "// IP bufxfs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
		imb = imbs.nodes[i];

		if ((i != ixImbCmdinv) && (i != ixImbCmdret)) {
			mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, sref, srefrootMgmt, srefrootCor);

			// -- getNewBufxf
			outfile << "Bufxf* " << unt->Fullsref << "::getNewBufxf" << srefrootCor << "(" << endl;
			outfile << "\t\t\tconst size_t reqlen" << endl;
			if (Easy) outfile << "\t\t\t, unsigned char* buf" << endl;
			outfile << "\t\t) {" << endl;

			outfile << "\treturn(new Bufxf(VecV" << srefroot << "Buffer::" << StrMod::uc(sref);
			if (mgmtToNotFrom) outfile << ", true";
			else outfile << ", false";
			outfile << ", reqlen";
			if (Easy) {
				if (mgmtToNotFrom) outfile << ", 0, 2";
				else outfile << ", 0, 2";
				outfile << ", buf";
			};
			outfile << "));" << endl;

			outfile << "};" << endl;
			outfile << endl;

			if (mgmtToNotFrom) {
				// -- writeTo...
				outfile << "int " << unt->Fullsref << "::write" << srefrootCor << "(" << endl;
				outfile << "\t\t\tconst unsigned char* data" << endl;
				outfile << "\t\t\t, const size_t datalen" << endl;
				if (Easy) outfile << "\t\t\t, const bool copy" << endl;
				outfile << "\t\t\t, Reseval* reseval" << endl;
				outfile << "\t\t) {" << endl;

				if (Easy) {
					outfile << "\tint res;" << endl;
					outfile << endl;

					outfile << "\tBufxf* bufxf;" << endl;
					outfile << endl;

					outfile << "\tif (copy) {" << endl;
					outfile << "\t\tbufxf = getNewBufxf" << srefrootCor << "(datalen, (unsigned char*) data);" << endl;
					outfile << "\t\tbufxf->setWriteData(data, datalen);" << endl;
					outfile << "\t} else bufxf = getNewBufxf" << srefrootCor << "(datalen, (unsigned char*) data);" << endl;
					outfile << endl;

					outfile << "\ttry {" << endl;
					outfile << "\t\tres = runBufxf(bufxf, reseval);" << endl;
					outfile << "\t} catch (const DbeException& e) {" << endl;
					outfile << "\t\tdelete bufxf;" << endl;
					outfile << "\t\tthrow;" << endl;
					outfile << "\t};" << endl;
					outfile << endl;

					outfile << "\tdelete bufxf;" << endl;
					outfile << endl;

					outfile << "\treturn res;" << endl;

				} else {
					outfile << "\tint res;" << endl;
					outfile << endl;

					outfile << "\tBufxf* bufxf = getNewBufxf" << srefrootCor << "(datalen);" << endl;
					outfile << endl;

					outfile << "\tbufxf->ixVTarget = ixVTarget;" << endl;
					outfile << "\tbufxf->uref = uref;" << endl;
					outfile << endl;

					outfile << "\tbufxf->setWriteData(data, datalen);" << endl;
					outfile << endl;

					outfile << "\ttry {" << endl;
					outfile << "\t\tres = runBufxf(bufxf, reseval);" << endl;
					outfile << "\t} catch (const DbeException& e) {" << endl;
					outfile << "\t\tdelete bufxf;" << endl;
					outfile << "\t\tthrow;" << endl;
					outfile << "\t};" << endl;
					outfile << endl;

					outfile << "\tdelete bufxf;" << endl;
					outfile << endl;

					outfile << "\treturn res;" << endl;
				};

				outfile << "};" << endl;
				outfile << endl;

			} else {
				// -- readFrom...
				outfile << "int " << unt->Fullsref << "::read" << srefrootCor << "(" << endl;
				outfile << "\t\t\tconst size_t reqlen" << endl;
				outfile << "\t\t\t, unsigned char*& data" << endl;
				outfile << "\t\t\t, size_t& datalen" << endl;
				outfile << "\t\t\t, Reseval* reseval" << endl;
				outfile << "\t\t) {" << endl;

				if (Easy) {
					outfile << "\tint res;" << endl;
					outfile << endl;

					outfile << "\tBufxf* bufxf = getNewBufxf" << srefrootCor << "(reqlen, data);" << endl;
					outfile << endl;

					outfile << "\ttry {" << endl;
					outfile << "\t\tres = runBufxf(bufxf, reseval);" << endl;
					outfile << endl;

					outfile << "\t\tif (res == 0) {" << endl;
					outfile << "\t\t\tif (!data) data = bufxf->getReadData();" << endl;
					outfile << "\t\t\tdatalen = bufxf->getReadDatalen();" << endl;
					outfile << "\t\t} else {" << endl;
					outfile << "\t\t\tdatalen = 0;" << endl;
					outfile << "\t\t};" << endl;
					outfile << endl;

					outfile << "\t} catch (const DbeException& e) {" << endl;
					outfile << "\t\tdelete bufxf;" << endl;
					outfile << "\t\tthrow;" << endl;
					outfile << "\t};" << endl;
					outfile << endl;

					outfile << "\tdelete bufxf;" << endl;
					outfile << endl;

					outfile << "\treturn res;" << endl;

				} else {
					outfile << "\tint res;" << endl;
					outfile << endl;

					outfile << "\tBufxf* bufxf = getNewBufxf" << srefrootCor << "(reqlen);" << endl;
					outfile << endl;

					outfile << "\tbufxf->ixVTarget = ixVTarget;" << endl;
					outfile << "\tbufxf->uref = uref;" << endl;
					outfile << endl;

					outfile << "\ttry {" << endl;
					outfile << "\t\tres = runBufxf(bufxf, reseval);" << endl;
					outfile << endl;

					outfile << "\t\tif (res == 0) {" << endl;
					outfile << "\t\t\tif (!data) data = bufxf->getReadData();" << endl;
					outfile << "\t\t\tdatalen = bufxf->getReadDatalen();" << endl;
					outfile << "\t\t} else {" << endl;
					outfile << "\t\t\tdatalen = 0;" << endl;
					outfile << "\t\t};" << endl;
					outfile << endl;

					outfile << "\t} catch (const DbeException& e) {" << endl;
					outfile << "\t\tdelete bufxf;" << endl;
					outfile << "\t\tthrow;" << endl;
					outfile << "\t};" << endl;
					outfile << endl;

					outfile << "\tdelete bufxf;" << endl;
					outfile << endl;

					outfile << "\treturn res;" << endl;
				};

				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "// IP bufxfs --- IEND" << endl;

	// --- cmds
	outfile << "// IP cmds --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		Wdbe::analyzeCmd(dbswdbe, cmd, unt, NULL, ipas, rpas, supsref, subsref);
		writeCmdCpp(dbswdbe, outfile, Easy, 0, "", hasvecerr, cmd, ipas, rpas, supsref, subsref);
	};
	outfile << "// IP cmds --- IEND" << endl;

	if (!Easy) {
		// --- errs
		outfile << "// IP errs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < errs.nodes.size(); i++) {
			err = errs.nodes[i];

			Wdbe::analyzeErr(dbswdbe, err, unt, NULL, epas, supsref, subsref);
			writeErrCpp(dbswdbe, outfile, err, epas, supsref, subsref);
		};
		outfile << "// IP errs --- IEND" << endl;
	};
};

void WdbeWrdevUnt::writeUntvecsH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, ListWdbeMVector& vecs
		) {
	WdbeMVector* vec = NULL;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecH(dbswdbe, outfile, vec, unt, NULL, NULL, false);
	};
	outfile << "// IP vecs --- IEND" << endl;
};

void WdbeWrdevUnt::writeUntvecsCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, ListWdbeMVector& vecs
		) {
	WdbeMVector* vec = NULL;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecCpp(dbswdbe, outfile, vec, unt, NULL, NULL, false);
	};
	outfile << "// IP vecs --- IEND" << endl;
};
// IP cust --- IEND
