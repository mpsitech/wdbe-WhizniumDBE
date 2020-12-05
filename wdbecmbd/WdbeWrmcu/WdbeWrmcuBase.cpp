/**
	* \file WdbeWrmcuBase.cpp
	* Wdbe operation processor - write C code basics (implementation)
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

#include "WdbeWrmcuBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

/******************************************************************************
 namespace WdbeWrmcuBase
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuBase::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuBase* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMUnit* unt = NULL;

	ListWdbeMModule mdls;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		dbswdbe->tblwdbemmodule->loadRstByHktHku(VecWdbeVMModuleHkTbl::UNT, unt->ref, false, mdls);

		// xxxx/Xxxx.h
		s = xchg->tmppath + "/" + folder + "/" + Untsref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntH(dbswdbe, outfile, unt, mdls);
		outfile.close();

		// xxxx/Xxxx_exe.c
		s = xchg->tmppath + "/" + folder + "/" + Untsref + "_exe.c.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntExeC(dbswdbe, outfile, unt, mdls);
		outfile.close();

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrmcuBase::writeUntH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, ListWdbeMModule& mdls
		) {
	WdbeMModule* mdl = NULL;

	ListWdbeMPeripheral pphs;
	WdbeMPeripheral* pph = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	vector<uint> icsMdc;
	uint ixMdc;

	ubigint refC;

	bool first;

	// --- summary
	outfile << "// IP summary --- IBEGIN" << endl;

	dbswdbe->tblwdbemperipheral->loadRstByUnt(unt->ref, false, pphs);

	outfile << "/*" << endl;
	outfile << "\tperipherals:" << endl;

	for (unsigned int i = 0; i < pphs.nodes.size(); i++) {
		pph = pphs.nodes[i];

		outfile << "\t" << pph->sref;

		dbswdbe->tblwdbempin->loadRstBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeMPin.ref = TblWdbeJMPinSref.refWdbeMPin AND TblWdbeJMPinSref.x1RefWdbeMPeripheral = "
					+ to_string(pph->ref) + " AND TblWdbeMPin.refJSref = TblWdbeJMPinSref.ref ORDER BY TblWdbeMPin.sref ASC", false, pins);

		if (pins.nodes.size() > 0) {
			outfile << " (";

			for (unsigned int j = 0; j < pins.nodes.size(); j++) {
				pin = pins.nodes[j];

				if (j != 0) outfile << ", ";
				outfile << pin->sref << "@" << pin->Location;
			};

			outfile << ")";
		};

		if (pph->refWdbeMModule != 0) outfile << " controlled by " << StubWdbe::getStubMdlSref(dbswdbe, pph->refWdbeMModule);

		outfile << endl;
	};

	outfile << "*/" << endl;
	outfile << "// IP summary --- IEND" << endl;

	// --- csts.full*
	if (!unt->Easy) outfile << "// IP csts.full --- AFFIRM" << endl;
	else outfile << "// IP csts.full --- REMOVE" << endl;

	// --- csts.unts
	outfile << "// IP csts.unts --- IBEGIN" << endl;

	// vectors associated with unit or controller command sets (adapted from WdbeWrfpgaBase)
	dbswdbe->tblwdbemvector->loadRstBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " ORDER BY sref ASC", false, vecs);
	dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMModule, TblWdbeMVector WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = "
				+ to_string(unt->ref) + " AND TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " AND TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR)
				+ " AND TblWdbeMVector.hkUref = TblWdbeMModule.refWdbeMController AND TblWdbeMVector.sref LIKE 'VecV%Command' ORDER BY TblWdbeMVector.sref ASC", true, vecs);

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		if (i != 0) outfile << endl;

		dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

		if (vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) {
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];
				outfile << "const int " << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4+4) << StrMod::cap(vit->sref) << " = " << vit->vecNum << ";" << endl;
			};
		} else {
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];
				outfile << "const unsigned char tix" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4+4) << StrMod::cap(vit->sref) << " = 0x" << Wdbe::binToHex(vit->vecNum) << ";" << endl;
			};
		};
	};

	outfile << "// IP csts.unts --- IEND" << endl;

	// --- mdls
	fillIcsMdc(icsMdc);

	outfile << "// IP mdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, false, prts);
		dbswdbe->tblwdbemsignal->loadRstByMdl(mdl->ref, false, sigs);

		outfile << "/**" << endl;
		outfile << "\t* " << mdl->sref << " ";
		if (mdl->refWdbeMController != 0) outfile << "controller" << endl;
		else outfile << "module" << endl;
		outfile << "\t*/" << endl;
		outfile << endl;

		outfile << "// IP " << mdl->sref << ".cust --- INSERT" << endl;
		outfile << endl;

		outfile << "struct Shrdat" << StrMod::cap(mdl->sref) << " {" << endl;

		refC = 0;
		first = true;

		for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
			sig = sigs.nodes[i];

			if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::VOID) && sig->Const) {
				if (first) first = false;
				else if (sig->refWdbeCSignal != refC) outfile << endl;

				outfile << "\tconst " << getVarCtype(sig) << " " << sig->sref << ";" << endl;

				refC = sig->refWdbeCSignal;
			};
		};
		if (!first) outfile << endl;

		refC = 0;
		first = true;

		for (unsigned int i = 0; i < icsMdc.size();i++) {
			ixMdc = icsMdc[i];

			for (unsigned int j = 0; j < prts.nodes.size(); j++) {
				prt = prts.nodes[j];

				if (prt->mdlIxVCat == ixMdc) {
					if (first) first = false;
					if (prt->refWdbeCPort != refC) outfile << endl;

					outfile << "\t" << getVarCtype(prt) << " " << prt->sref << ";";
					if (prt->Comment != "") outfile << " // " << prt->Comment;
					outfile << endl;

					refC = prt->refWdbeCPort;
				};
			};
		};
		outfile << endl;

		outfile << "\t// IP Shrdat" << StrMod::cap(mdl->sref) << ".cust --- INSERT" << endl;

		outfile << "};" << endl;
		outfile << endl;

		outfile << "extern struct Shrdat" << StrMod::cap(mdl->sref) << " shrdat" << StrMod::cap(mdl->sref) << ";" << endl;
		outfile << endl;
	};

	outfile << "// IP mdls --- IEND" << endl;
};

void WdbeWrmcuBase::writeUntExeC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, ListWdbeMModule& mdls
		) {
	WdbeMModule* mdl = NULL;

	// --- include
	outfile << "// IP include --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		outfile << "#include \"" << StrMod::cap(mdl->sref) << ".h\"" << endl;
	};
	outfile << "// IP include --- IEND" << endl;

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		outfile << "\t" << mdl->sref << "Init();" << endl;
	};
	outfile << "// IP init --- IEND" << endl;

	// --- run
	outfile << "// IP run --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		outfile << "\t\tif (" << mdl->sref << "Run()) mod = true;" << endl;
	};
	outfile << "// IP run --- IEND" << endl;
};

void WdbeWrmcuBase::fillIcsMdc(
			vector<uint>& icsMdc
		) {
	// copy from WdbeWrfpgaMdlraw, to be reduced further
	icsMdc.clear();

	push_back(icsMdc, VecWdbeVMPortMdlCat::RESET);
	push_back(icsMdc, VecWdbeVMPortMdlCat::CLK);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTEWRP);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTETOP);
	push_back(icsMdc, VecWdbeVMPortMdlCat::CMDBUS);
	push_back(icsMdc, VecWdbeVMPortMdlCat::IMB);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTESUP);
	//push_back(icsMdc, VecWdbeVMPortMdlCat::RTEPIN);
	push_back(icsMdc, VecWdbeVMPortMdlCat::DBG);
};
// IP cust --- IEND



