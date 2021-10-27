/**
	* \file WdbeWrdevSys.cpp
	* Wdbe operation processor - write C++ code for system (implementation)
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

#include "WdbeWrdevSys.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrdev;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrdevSys
 ******************************************************************************/

DpchRetWdbe* WdbeWrdevSys::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevSys* dpchinv
		) {
	ubigint refWdbeMSystem = dpchinv->refWdbeMSystem;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMSystem* sys = NULL;

	ListWdbeMTarget trgs;
	WdbeMTarget* trg = NULL;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	map<ubigint,unsigned int> icsTrgunts; // by trg->ref

	vector<bool> hasvecbufs;
	vector<bool> hasvecctrs;
	vector<bool> hasveccmds;
	vector<bool> hasvecerrs;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemsystem->loadRecByRef(refWdbeMSystem, &sys)) {
		dbswdbe->tblwdbemtarget->loadRstBySys(sys->ref, false, trgs);
		dbswdbe->tblwdbemunit->loadRstByRetReu(VecWdbeVMUnitRefTbl::VER, sys->refWdbeMVersion, false, unts);

		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			for (unsigned int j = 0; j < unts.nodes.size(); j++) {
				unt = unts.nodes[j];

				if (unt->ref == trg->refWdbeMUnit) {
					icsTrgunts[trg->ref] = j;
					break;
				};
			};
		};

		hasvecbufs.resize(unts.nodes.size(), false);
		hasvecctrs.resize(unts.nodes.size(), false);
		hasveccmds.resize(unts.nodes.size(), false);
		hasvecerrs.resize(unts.nodes.size(), false);

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			dbswdbe->tblwdbemvector->loadRstByHktHku(VecWdbeVMVectorHkTbl::UNT, unt->ref, false, vecs);
			for (unsigned int j = 0; j < vecs.nodes.size(); j++) {
				vec = vecs.nodes[j];

				if (vec->sref == ("VecW" + unt->Fullsref.substr(3) + "Buffer")) hasvecbufs[i] = true;
				else if (vec->sref == ("VecV" + unt->Fullsref.substr(3) + "Controller")) hasvecctrs[i] = true;
				else if (vec->sref == ("VecV" + unt->Fullsref.substr(3) + "Command")) hasveccmds[i] = true;
				else if (vec->sref == ("VecV" + unt->Fullsref.substr(3) + "Error")) hasveccmds[i] = true;
			};
		};

		dbswdbe->tblwdbemvector->loadRstByHktHku(VecWdbeVMVectorHkTbl::SYS, sys->ref, false, vecs);

		// SysXxxxYyyyy.h
		s = xchg->tmppath + "/" + folder + "/" + sys->sref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeSysH(dbswdbe, outfile, sys, unts, vecs);
		outfile.close();

		// SysXxxxYyyyy_vecs.cpp
		s = xchg->tmppath + "/" + folder + "/" + sys->sref + "_vecs.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeSysvecsCpp(dbswdbe, outfile, sys, vecs);
		outfile.close();

		// SysXxxxYyyyy.cpp
		s = xchg->tmppath + "/" + folder + "/" + sys->sref + ".cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeSysCpp(dbswdbe, outfile, sys, trgs, unts, icsTrgunts, hasvecbufs, hasvecctrs, hasveccmds, hasvecerrs, vecs);
		outfile.close();

		delete sys;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrdevSys::writeSysH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMSystem* sys
			, ListWdbeMUnit& unts
			, ListWdbeMVector& vecs
		) {
	WdbeMUnit* unt = NULL;

	WdbeMVector* vec = NULL;

	// --- include.unts
	outfile << "// IP include.unts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];
		outfile << "#include \"" << unt->Fullsref << ".h\"" << endl;
	};
	outfile << "// IP include.unts --- IEND" << endl;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecH(dbswdbe, outfile, vec, sys, NULL, NULL, true, 1);
	};
	outfile << "// IP vecs --- IEND" << endl;
};

void WdbeWrdevSys::writeSysvecsCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMSystem* sys
			, ListWdbeMVector& vecs
		) {
	WdbeMVector* vec = NULL;

	// --- vecs
	outfile << "// IP vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		writeVecCpp(dbswdbe, outfile, vec, sys, NULL, NULL, true);
	};
	outfile << "// IP vecs --- IEND" << endl;
};

void WdbeWrdevSys::writeSysCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMSystem* sys
			, ListWdbeMTarget& trgs
			, ListWdbeMUnit& unts
			, map<ubigint,unsigned int>& icsTrgunts
			, vector<bool>& hasvecbufs
			, vector<bool>& hasvecctrs
			, vector<bool>& hasveccmds
			, vector<bool>& hasvecerrs
			, ListWdbeMVector& vecs
		) {
	WdbeMUnit* sysunt = NULL;

	WdbeMTarget* trg = NULL;

	WdbeMUnit* unt = NULL;

	vector<string> srefsTrgs;
	vector<string> srefsFwdctrs;
	vector<string> fullsrefsFwdctrs;
	vector<string> srefsRdbufs;
	vector<string> srefsWrbufs;

	set<unsigned int> icsSubtrgs;

	string srefroot;

	ListWdbeMVector untvecs;
	ListWdbeMController ctrs;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;

	ListWdbeMCommand cmds;
	ListWdbeMError errs;

	ubigint refHostif;
	uint ixImbCmdinv, ixImbCmdret;
	bool hasvecbuf, hasvecctr, hasveccmd, hasvecerr, hasspeccmd;

	string sref, srefrootMgmt, srefrootCor;

	vector<string> srefsImbRd, srefsImbWr;
	vector<string> srefrootsImbRd, srefrootsImbWr;

	unsigned int ixSrefrootsImbWrCmdinv = 0;
	unsigned int ixSrefrootsImbRdCmdret = 0;

	string s;

	unsigned int ix;

	bool first;

	if (dbswdbe->tblwdbemunit->loadRecByRef(sys->refWdbeMUnit, &sysunt)) {
		Wdbe::analyzeUnt(dbswdbe, sysunt, srefroot, untvecs, ctrs, imbs, cmds, errs, refHostif, ixImbCmdinv, ixImbCmdret, hasvecbuf, hasvecctr, hasveccmd, hasvecerr, hasspeccmd);

		ixSrefrootsImbRdCmdret = imbs.nodes.size();
		ixSrefrootsImbRdCmdret = imbs.nodes.size();

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (!Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, sref, srefrootMgmt, srefrootCor)) {
				srefsImbRd.push_back(sref);
				srefrootsImbRd.push_back(srefrootCor);
				if (i == ixImbCmdret) ixSrefrootsImbRdCmdret = srefrootsImbRd.size() - 1;

			} else {
				srefsImbWr.push_back(sref);
				srefrootsImbWr.push_back(srefrootCor);
				if (i == ixImbCmdinv) ixSrefrootsImbWrCmdinv = srefrootsImbWr.size() - 1;
			};
		};

		// --- runPrepprc.rst
		outfile << "// IP runPrepprc.rst --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			expandTrgRte(dbswdbe, trgs, i, unts, srefsTrgs, srefsFwdctrs, fullsrefsFwdctrs, srefsRdbufs, srefsWrbufs);
			getTrgSubtrgs(trgs, i, icsSubtrgs);

			outfile << "\t\t\t";
			if (first) first = false;
			else outfile << "} else ";

			outfile << "if (rst->ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") {" << endl;

			if (srefsTrgs.size() == 0) {
				outfile << "\t\t\t\trst->root = true;" << endl;

			} else {
				// reset command in last controller of route
				ix = srefsTrgs.size()-1;
				outfile << "\t\t\t\trst->cmd = inst->getNewCmd(VecVTarget::" << StrMod::uc(StrMod::dotToUsc(srefsTrgs[ix])) << ", VecV" << fullsrefsFwdctrs[ix].substr(3, 4+4) << "Controller::" << StrMod::uc(srefsFwdctrs[ix]) << ", VecV" << fullsrefsFwdctrs[ix].substr(3) << "Command::RESET);" << endl;
			};
			outfile << endl;

			for (auto it = icsSubtrgs.begin(); it != icsSubtrgs.end(); it++) outfile << "\t\t\t\tinsert(rst->subIcsVTarget, VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trgs.nodes[*it]->sref)) << ");" << endl;
			outfile << endl;
		};
		if (!first) outfile << "\t};" << endl;
		outfile << "// IP runPrepprc.rst --- IEND" << endl;

		// --- runPrepprc.bufxf
		outfile << "// IP runPrepprc.bufxf --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			expandTrgRte(dbswdbe, trgs, i, unts, srefsTrgs, srefsFwdctrs, fullsrefsFwdctrs, srefsRdbufs, srefsWrbufs);

			outfile << "\t\t\t";
			if (first) first = false;
			else outfile << "} else ";

			outfile << "if (bufxf->ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") {" << endl;

			if (srefsTrgs.size() > 0) {
				ix = srefsTrgs.size()-1;

				if (srefsWrbufs[ix] != "") {
					// write
					outfile << "\t\t\t\tif (bufxf->writeNotRead) {" << endl;

					outfile << "\t\t\t\t\tbufxf->rootTixWBuffer = VecW" << fullsrefsFwdctrs[0].substr(3, 4+4) << "Buffer::" << StrMod::uc(srefsWrbufs[0]) << ";" << endl;
					outfile << endl;

					for (unsigned int j = 0; j < srefsTrgs.size();j++) outfile << "\t\t\t\t\tbufxf->icsReqcmd.insert(cmdix_t(VecVTarget::" << StrMod::uc(StrMod::dotToUsc(srefsTrgs[j])) << ", VecV" << fullsrefsFwdctrs[j].substr(3, 4+4)
								<< "Controller::" << StrMod::uc(srefsFwdctrs[j]) << ", VecV" << fullsrefsFwdctrs[j].substr(3) << "Command::WRITE));" << endl;

					for (unsigned int j = 0; j < srefsTrgs.size();j++) {
						outfile << endl;

						outfile << "\t\t\t\t\tcmd = " << fullsrefsFwdctrs[j] << "::getNewCmdWrite(";
						if (j == (srefsWrbufs.size()-1)) outfile << "bufxf->tixWBuffer";
						else outfile << "VecW" << fullsrefsFwdctrs[j+1].substr(3, 4+4) << "Buffer::" << StrMod::uc(srefsWrbufs[j+1]);
						outfile << ", bufxf->reqlen);" << endl;

						outfile << "\t\t\t\t\tcmd->setProgressCallback(bufxfCmdProgressCallback, (void*) bufxf);" << endl;
						outfile << "\t\t\t\t\tbufxf->cmds.push_back(cmd);" << endl;
					};
				};
				
				if (srefsRdbufs[ix] != "") {
					// read
					if (srefsWrbufs[ix] != "") {
						outfile << endl;
						outfile << "\t\t\t\t} else {" << endl;
					} else outfile << "\t\t\t\tif (!bufxf->writeNotRead) {" << endl;
					
					for (unsigned int j=srefsTrgs.size();j>0;j--) outfile << "\t\t\t\t\tbufxf->icsReqcmd.insert(cmdix_t(VecVTarget::" << StrMod::uc(StrMod::dotToUsc(srefsTrgs[j-1])) << ", VecV" << fullsrefsFwdctrs[j-1].substr(3, 4+4)
								<< "Controller::" << StrMod::uc(srefsFwdctrs[j-1]) << ", VecV" << fullsrefsFwdctrs[j-1].substr(3) << "Command::READ));" << endl;

					outfile << endl;
					outfile << "\t\t\t\t\tbufxf->rootTixWBuffer = VecW" << fullsrefsFwdctrs[0].substr(3, 4+4) << "Buffer::" << StrMod::uc(srefsRdbufs[0]) << ";" << endl;

					for (unsigned int j=srefsTrgs.size();j>0;j--) {
						outfile << endl;

						outfile << "\t\t\t\t\tcmd = " << fullsrefsFwdctrs[j-1] << "::getNewCmdRead(";
						if (j == srefsWrbufs.size()) outfile << "bufxf->tixWBuffer";
						else outfile << "VecW" << fullsrefsFwdctrs[j].substr(3, 4+4) << "Buffer::" << StrMod::uc(srefsRdbufs[j]);
						outfile << ", bufxf->reqlen);" << endl;

						outfile << "\t\t\t\t\tcmd->setProgressCallback(bufxfCmdProgressCallback, (void*) bufxf);" << endl;
						outfile << "\t\t\t\t\tbufxf->cmds.push_back(cmd);" << endl;
					};
				};

				if ((srefsRdbufs[ix] != "") || (srefsWrbufs[ix] != "")) outfile << "\t\t\t\t};" << endl;
			};
		};
		if (!first) outfile << "\t};" << endl;
		outfile << "// IP runPrepprc.bufxf --- IEND" << endl;

		// --- runReqprc.tkns
		outfile << "// IP runReqprc.tkns --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) outfile << "\tutinyint tkn" << srefrootsImbRd[i] << " = VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ";" << endl;
		for (unsigned int i = 0; i < srefsImbWr.size(); i++) outfile << "\tutinyint tkn" << srefrootsImbWr[i] << " = VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ";" << endl;
		outfile << "// IP runReqprc.tkns --- IEND" << endl;

		// --- runReqprc.reqbx
		outfile << "// IP runReqprc.reqbx --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != ixSrefrootsImbRdCmdret) {
				outfile << "\t\t\trngBufxfs = xchg->bufxfs.equal_range(bufxfref_t(Bufxf::VecVState::WAITXFER, VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ", 0));" << endl;
				outfile << "\t\t\tif (rngBufxfs.first != rngBufxfs.second) reqbx |= VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ";" << endl;
				outfile << endl;
			};
		};

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != ixSrefrootsImbWrCmdinv) {
				outfile << "\t\t\trngBufxfs = xchg->bufxfs.equal_range(bufxfref_t(Bufxf::VecVState::WAITXFER, VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ", 0));" << endl;
				outfile << "\t\t\tif (rngBufxfs.first != rngBufxfs.second) reqbx |= VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ";" << endl;
				outfile << endl;
			};
		};
		outfile << "// IP runReqprc.reqbx --- IEND" << endl;

		// --- runReqprc.xferTknste
		outfile << "// IP runReqprc.xferTknste --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != ixSrefrootsImbRdCmdret) {
				outfile << "\t\t\t\t\tif ( ! (((_rxbuf[2] & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") ^ tkn" << srefrootsImbRd[i] << ") & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") ) {" << endl;
				outfile << "\t\t\t\t\t\tif (_rxbuf[2] & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") tkn" << srefrootsImbRd[i] << " = ~VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << "; else tkn" << srefrootsImbRd[i] << " = VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ";" << endl;
				outfile << "\t\t\t\t\t\tif (!first) {" << endl;
				outfile << "\t\t\t\t\t\t\t//cout << \"tkn" << srefrootsImbRd[i] << " corrected\" << endl;" << endl;
				outfile << "\t\t\t\t\t\t\tif (arbbxRd_last == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") skiprd = true;" << endl;
				outfile << "\t\t\t\t\t\t};" << endl;
				outfile << "\t\t\t\t\t};" << endl;
			};
		};

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != ixSrefrootsImbWrCmdinv) {
				outfile << "\t\t\t\t\tif ( ! (((_rxbuf[2] & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") ^ tkn" << srefrootsImbWr[i] << ") & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") ) {" << endl;
				outfile << "\t\t\t\t\t\tif (_rxbuf[2] & VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") tkn" << srefrootsImbWr[i] << " = ~VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << "; else tkn" << srefrootsImbWr[i] << " = VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ";" << endl;
				outfile << "\t\t\t\t\t\tif (!first) {" << endl;
				outfile << "\t\t\t\t\t\t\t//cout << \"tkn" << srefrootsImbWr[i] << " corrected\" << endl;" << endl;
				outfile << "\t\t\t\t\t\t\tif (arbbxRd_last == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") skiprd = true;" << endl;
				outfile << "\t\t\t\t\t\t};" << endl;
				outfile << "\t\t\t\t\t};" << endl;
			};
		};
		outfile << "// IP runReqprc.xferTknste --- IEND" << endl;

		// --- runReqprc.xferArbbx
		outfile << "// IP runReqprc.xferArbbx --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tif (";
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != 0) outfile << " || ";
			outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ")";
		};
		outfile << ") arbbxRd_last = arbbx;" << endl;

		outfile << "\t\t\t\t\tif (";
		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != 0) outfile << " || ";
			outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ")";
		};
		outfile << ") arbbxWr_last = arbbx;" << endl;
		outfile << "// IP runReqprc.xferArbbx --- IEND" << endl;

		// --- runReqprc.lockWrite
		outfile << "// IP runReqprc.lockWrite --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\tif (";
		first = true;
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != ixSrefrootsImbRdCmdret) {
				if (first) first = false;
				else outfile << " || ";

				outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ")";
			};
		};
		outfile << ") {" << endl;
		outfile << "// IP runReqprc.lockWrite --- IEND" << endl;

		// --- runReqprc.rw
		outfile << "// IP runReqprc.rw --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tif (!(skipwr && (";
		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != 0) outfile << " || ";
			outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ")";
		};
		outfile << "))) {" << endl;
		outfile << "// IP runReqprc.rw --- IEND" << endl;

		// --- runReqprc.setTkn
		outfile << "// IP runReqprc.setTkn --- IBEGIN" << endl;
		first = true;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") tkn = tkn" << srefrootsImbRd[i] << ";" << endl;
		};

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			outfile << "\t\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") tkn = tkn" << srefrootsImbWr[i] << ";" << endl;
		};
		outfile << "// IP runReqprc.setTkn --- IEND" << endl;

		// --- runReqprc.read
		outfile << "// IP runReqprc.read --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\t\tif (";
		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != 0) outfile << " || ";
			outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ")";
		};
		outfile << ") {" << endl;
		outfile << "// IP runReqprc.read --- IEND" << endl;

		// --- runReqprc.write
		outfile << "// IP runReqprc.write --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\t\t} else if (";
		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != 0) outfile << " || ";
			outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ")";
		};
		outfile << ") {" << endl;
		outfile << "// IP runReqprc.write --- IEND" << endl;

		// --- runReqprc.invtkn
		outfile << "// IP runReqprc.invtkn --- IBEGIN" << endl;
		first = true;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			outfile << "\t\t\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ") tkn" << srefrootsImbRd[i] << " = invtkn;" << endl;
		};

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			outfile << "\t\t\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ") tkn" << srefrootsImbWr[i] << " = invtkn;" << endl;
		};
		outfile << "// IP runReqprc.invtkn --- IEND" << endl;

		// --- runReqprc.updRead
		outfile << "// IP runReqprc.updRead --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tif (";
		first = true;

		for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
			if (i != ixSrefrootsImbRdCmdret) {
				if (first) first = false;
				else outfile << " || ";

				outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbRd[i]) << ")";
			};
		};

		if (first) outfile << "false";
		outfile << ") {" << endl;
		outfile << "// IP runReqprc.updRead --- IEND" << endl;

		// --- runReqprc.updWrite
		outfile << "// IP runReqprc.updWrite --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t} else if (";
		first = true;

		for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
			if (i != ixSrefrootsImbWrCmdinv) {
				if (first) first = false;
				else outfile << " || ";

				outfile << "(arbbx == VecW" << srefroot << "Buffer::" << StrMod::uc(srefsImbWr[i]) << ")";
			};
		};

		if (first) outfile << "false";
		outfile << ") {" << endl;
		outfile << "// IP runReqprc.updWrite --- IEND" << endl;

		// --- runReqprc_setRoute
		outfile << "// IP runReqprc_setRoute --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			expandTrgRte(dbswdbe, trgs, i, unts, srefsTrgs, srefsFwdctrs, fullsrefsFwdctrs, srefsRdbufs, srefsWrbufs);

			outfile << "\t";
			if (first) first = false;
			else outfile << "} else ";

			outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") {" << endl;

			for (unsigned int j = 0; j < fullsrefsFwdctrs.size();j++) {
				outfile << "\t\ttxbuf[ofs";
				if (j > 0) outfile << "+" << j;
				outfile << "] = VecV" << fullsrefsFwdctrs[j].substr(3, 4+4) << "Controller::" << StrMod::uc(srefsFwdctrs[j]) << ";" << endl;
			};

			outfile << "\t\ttxbuf[ofs";
			if (fullsrefsFwdctrs.size() > 0) outfile << "+" << fullsrefsFwdctrs.size();
			outfile << "] = tixVController;" << endl;
		};
		if (!first) outfile << "\t};" << endl;
		outfile << "// IP runReqprc_setRoute --- IEND" << endl;

		// --- connectToTarget
		outfile << "// IP connectToTarget --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";
				
				outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") unt = new " << unt->Fullsref << "(xchg, ixVTarget);" << endl;
			};
		};
		outfile << "// IP connectToTarget --- IEND" << endl;

		// --- getTixVControllerBySref
		outfile << "// IP getTixVControllerBySref --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecctrs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";
					
					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") tixVController = " << unt->Fullsref << "::getTixVControllerBySref(sref);" << endl;
				};
			};
		};
		outfile << "// IP getTixVControllerBySref --- IEND" << endl;

		// --- getSrefByTixVController
		outfile << "// IP getSrefByTixVController --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecctrs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";
					
					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") sref = " << unt->Fullsref << "::getSrefByTixVController(tixVController);" << endl;
				};
			};
		};
		outfile << "// IP getSrefByTixVController --- IEND" << endl;

		// --- fillFeedFController
		outfile << "// IP fillFeedFController --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecctrs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";
					
					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") " << unt->Fullsref << "::fillFeedFController(feed);" << endl;
				};
			};
		};
		outfile << "// IP fillFeedFController --- IEND" << endl;

		// --- getTixWBufferBySref
		outfile << "// IP getTixWBufferBySref --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecbufs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") tixWBuffer = " << unt->Fullsref << "::getTixWBufferBySref(sref);" << endl;
				};
			};
		};
		outfile << "// IP getTixWBufferBySref --- IEND" << endl;

		// --- getSrefByTixWBuffer
		outfile << "// IP getSrefByTixWBuffer --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecbufs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") sref = " << unt->Fullsref << "::getSrefByTixWBuffer(tixWBuffer);" << endl;
				};
			};
		};
		outfile << "// IP getSrefByTixWBuffer --- IEND" << endl;

		// --- fillFeedFBuffer
		outfile << "// IP fillFeedFBuffer --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecbufs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") " << unt->Fullsref << "::fillFeedFBuffer(feed);" << endl;
				};
			};
		};
		outfile << "// IP fillFeedFBuffer --- IEND" << endl;

		// --- getTixVCommandBySref
		outfile << "// IP getTixVCommandBySref --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";

				outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") tixVCommand = " << unt->Fullsref << "::getTixVCommandBySref(";
				if (hasvecctrs[it->second]) outfile << "tixVController, ";
				outfile << "sref);" << endl;
			};
		};
		outfile << "// IP getTixVCommandBySref --- IEND" << endl;

		// --- getSrefByTixVCommand
		outfile << "// IP getSrefByTixVCommand --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";

				outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") sref = " << unt->Fullsref << "::getSrefByTixVCommand(";
				if (hasvecctrs[it->second]) outfile << "tixVController, ";
				outfile << "tixVCommand);" << endl;
			};
		};
		outfile << "// IP getSrefByTixVCommand --- IEND" << endl;

		// --- fillFeedFCommand
		outfile << "// IP fillFeedFCommand --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";

				outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") " << unt->Fullsref << "::fillFeedFCommand(";
				if (hasvecctrs[it->second]) outfile << "tixVController, ";
				outfile << "feed);" << endl;
			};
		};
		outfile << "// IP fillFeedFCommand --- IEND" << endl;

		// --- getSrefByTixVError
		outfile << "// IP getSrefByTixVError --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				if (hasvecerrs[it->second]) {
					unt = unts.nodes[it->second];

					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") sref = " << unt->Fullsref << "::getSrefByTixVError(";
					if (hasvecctrs[it->second]) outfile << "tixVController, ";
					outfile << "tixVError);" << endl;
				};
			};
		};
		outfile << "// IP getSrefByTixVError --- IEND" << endl;

		// --- getTitleByTixVError
		outfile << "// IP getTitleByTixVError --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				if (hasvecerrs[it->second]) {
					unt = unts.nodes[it->second];

					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") Title = " << unt->Fullsref << "::getTitleByTixVError(";
					if (hasvecctrs[it->second]) outfile << "tixVController, ";
					outfile << "tixVError);" << endl;
				};
			};
		};
		outfile << "// IP getTitleByTixVError --- IEND" << endl;

		// --- getNewBufxf
		outfile << "// IP getNewBufxf --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				if (hasvecbufs[it->second]) {
					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") bufxf = " << unt->Fullsref << "::getNewBufxf(tixWBuffer, reqlen);" << endl;
				};
			};
		};
		outfile << "// IP getNewBufxf --- IEND" << endl;

		// --- getNewCmd
		outfile << "// IP getNewCmd --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				unt = unts.nodes[it->second];

				outfile << "\t";
				if (first) first = false;
				else outfile << "else ";

				outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") cmd = " << unt->Fullsref << "::getNewCmd(";
				if (hasvecctrs[it->second]) outfile << "tixVController, ";
				outfile << "tixVCommand);" << endl;
			};
		};
		outfile << "// IP getNewCmd --- IEND" << endl;

		// --- getNewErr
		outfile << "// IP getNewErr --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
			trg = trgs.nodes[i];

			auto it = icsTrgunts.find(trg->ref);
			if (it != icsTrgunts.end()) {
				if (hasvecerrs[it->second]) {
					unt = unts.nodes[it->second];

					outfile << "\t";
					if (first) first = false;
					else outfile << "else ";

					outfile << "if (ixVTarget == VecVTarget::" << StrMod::uc(StrMod::dotToUsc(trg->sref)) << ") err = " << unt->Fullsref << "::getNewErr(";
					if (hasvecctrs[it->second]) outfile << "tixVController, ";
					outfile << "tixVError);" << endl;
				};
			};
		};
		outfile << "// IP getNewErr --- IEND" << endl;

		delete sysunt;
	};
};

void WdbeWrdevSys::expandTrgRte(
			DbsWdbe* dbswdbe
			, ListWdbeMTarget& trgs
			, const unsigned int ixTrg
			, ListWdbeMUnit& unts
			, vector<string>& srefsTrgs
			, vector<string>& srefsFwdctrs
			, vector<string>& fullsrefsFwdctrs
			, vector<string>& srefsRdbufs
			, vector<string>& srefsWrbufs
		) {
	// ex. 1: dcx3, rte is 'bss3.dcxif'
	// {BSS3, dcxif, CtrIdhwBss3Dcxif, rdbufDcxifToHostif, wrbufHostifToDcxif}

	// ex. 2: dcx3_icm2, rte is 'bss3.dcxif;dcx3.qcdif'
	// {BSS3, dcxif, CtrIdhwBss3Dcxif, rdbufDcxifToHostif, wrbufHostifToDcxif}
	// {DCX3, qcdif, CrrIdhwDcx3Qcdif, rdbufQcdifToHostif, wrbufHostifToQcdif}

	ubigint ref;

	WdbeMTarget* trg = NULL;
	WdbeMUnit* unt = NULL;

	WdbeMController* ctr = NULL;

	string sref, srefrootMgmt, srefrootCor;

	string srefUnt;
	string srefMdl;

	string rte;

	vector<string> ss;
	string s;

	size_t ptr;

	bool found;

	StrMod::srefsToVector(trgs.nodes[ixTrg]->rteSrefsWdbeMModule, ss);

	srefsTrgs.clear();
	srefsFwdctrs.clear();
	fullsrefsFwdctrs.clear();
	srefsRdbufs.clear();
	srefsWrbufs.clear();

	for (unsigned int i = 0; i < ss.size();i++) {
		ptr = ss[i].find('.');

		if (ptr != string::npos) {
			srefUnt = ss[i].substr(0, ptr);
			srefMdl = ss[i].substr(ptr+1);

			// find unit hosting the forwarding controller
			found = false;
			for (unsigned int j = 0; j < unts.nodes.size(); j++) {
				unt = unts.nodes[j];
				
				if (unt->sref == srefUnt) {
					found = true;
					break;
				};
			};

			if (found) {
				if (dbswdbe->tblwdbemcontroller->loadRecBySQL("SELECT TblWdbeMController.* FROM TblWdbeMModule, TblWdbeMController WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
							+ " AND TblWdbeMModule.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule.sref = '" + srefMdl + "' AND TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref", &ctr)) {

					// find target corresponding to the unit
					s = "";
					for (unsigned int j = 0; j < trgs.nodes.size(); j++) {
						trg = trgs.nodes[j];

						if ((trg->refWdbeMUnit == unt->ref) && (trg->rteSrefsWdbeMModule == rte)) {
							s = trg->sref;
							break;
						};
					};
					srefsTrgs.push_back(s);

					srefsFwdctrs.push_back(srefMdl);
					fullsrefsFwdctrs.push_back(ctr->Fullsref);

					sref = "";
					if (dbswdbe->loadRefBySQL("SELECT TblWdbeRMModuleMModule.ctdRefWdbeMModule FROM TblWdbeRMModuleMModule, TblWdbeMModule WHERE TblWdbeRMModuleMModule.srefKFunction = 'snk' AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeMModule.supRefWdbeMModule = "
								+ to_string(ctr->refWdbeMModule), ref)) Wdbe::getImbsrefs(dbswdbe, ref, sref, srefrootMgmt, srefrootCor);
					srefsRdbufs.push_back(sref);

					sref = "";
					if (dbswdbe->loadRefBySQL("SELECT TblWdbeRMModuleMModule.ctdRefWdbeMModule FROM TblWdbeRMModuleMModule, TblWdbeMModule WHERE TblWdbeRMModuleMModule.srefKFunction = 'src' AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeMModule.supRefWdbeMModule = "
								+ to_string(ctr->refWdbeMModule), ref)) Wdbe::getImbsrefs(dbswdbe, ref, sref, srefrootMgmt, srefrootCor);
					srefsWrbufs.push_back(sref);

					delete ctr;
				};
			};

			// update route up to here
			if (rte != "") rte += ";";
			rte += ss[i];
		};
	};
};

void WdbeWrdevSys::getTrgSubtrgs(
			ListWdbeMTarget& trgs
			, const unsigned int ixTrg
			, set<unsigned int>& icsSubtrgs
		) {
	WdbeMTarget* trg = NULL;

	vector<string> ss;
	vector<string> ss2;

	bool found;

	StrMod::srefsToVector(trgs.nodes[ixTrg]->rteSrefsWdbeMModule, ss);

	icsSubtrgs.clear();

	for (unsigned int i = 0; i < trgs.nodes.size(); i++) {
		if (i != ixTrg) {
			trg = trgs.nodes[i];

			StrMod::srefsToVector(trg->rteSrefsWdbeMModule, ss2);

			if (ss2.size() > ss.size()) {
				found = true;
				
				for (unsigned int j = 0; j < ss.size();j++) {
					if (ss[j] != ss2[j]) {
						found = false;
						break;
					};
				};

				if (found) icsSubtrgs.insert(i);
			};
		};
	};
};
// IP cust --- IEND
