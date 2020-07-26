/**
	* \file WdbeWrmcuMdlraw.cpp
	* Wdbe operation processor - write raw C code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrmcuMdlraw.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

/******************************************************************************
 namespace WdbeWrmcuMdlraw
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuMdlraw::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuMdlraw* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	ListWdbeMProcess prcs;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl)); // TBD ... mdl->sref vs. compsref ...

		dbswdbe->tblwdbemprocess->loadRstByMdl(mdl->ref, false, prcs);

		// xxxx/Xxxxx.h
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlH(dbswdbe, outfile, Prjshort, Untsref, mdl, prcs);
		outfile.close();

		// xxxx/Xxxxx.c
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".c.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlC(dbswdbe, outfile, Prjshort, Untsref, Compsref, mdl, prcs);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrmcuMdlraw::writeMdlH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
			, ListWdbeMProcess& prcs
		) {
	ListWdbeMPeripheral pphs;
	WdbeMPeripheral* pph = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	WdbeMProcess* prc = NULL;

	bool first;

	// --- summary
	outfile << "// IP summary --- IBEGIN" << endl;

	dbswdbe->tblwdbemperipheral->loadRstBySQL("SELECT * FROM TblWdbeMPeripheral WHERE refWdbeMModule = " + to_string(mdl->ref) + " ORDER BY sref ASC", false, pphs);
	dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND mdlIxVCat = " + to_string(VecWdbeVMPortMdlCat::RTEPIN)
				+ " ORDER BY mdlNum ASC", false, prts);

	if ((pphs.nodes.size() > 0) || (prts.nodes.size() > 0)) {
		outfile << "/*" << endl;

		first = true;
		for (unsigned int i = 0; i < pphs.nodes.size(); i++) {
			pph = pphs.nodes[i];

			if (first) {
				outfile << "\tperipherals: ";
				first = false;
			} else outfile << ", ";

			outfile << pph->sref;

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
		};
		if (!first) outfile << endl;

		first = true;
		for (unsigned int i = 0; i < prts.nodes.size(); i++) {
			prt = prts.nodes[i];

			if (prt->ixVDir == VecWdbeVMPortDir::IN) {
				if (first) {
					outfile << "\tinput pins: ";
					first = false;
				} else outfile << ", ";

				if (dbswdbe->tblwdbempin->loadRecBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMBank, TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeJMPinSref.sref = '" + prt->cpiSrefWdbeMPin
							+ "' AND TblWdbeMPin.ref = TblWdbeJMPinSref.refWdbeMPin AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref), &pin)) {

					outfile << pin->sref << "@" << pin->Location;
					delete pin;

				} else outfile << prt->sref;
			};
		};
		if (!first) outfile << endl;

		first = true;
		for (unsigned int i = 0; i < prts.nodes.size(); i++) {
			prt = prts.nodes[i];

			if (prt->ixVDir == VecWdbeVMPortDir::OUT) {
				if (first) {
					outfile << "\toutput pins: ";
					first = false;
				} else outfile << ", ";

				if (dbswdbe->tblwdbempin->loadRecBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMBank, TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeJMPinSref.sref = '" + prt->cpiSrefWdbeMPin
							+ "' AND TblWdbeMPin.ref = TblWdbeJMPinSref.refWdbeMPin AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref), &pin)) {

					outfile << pin->sref << "@" << pin->Location;
					delete pin;

				} else outfile << prt->sref;
			};
		};
		if (!first) outfile << endl;

		outfile << "*/" << endl;
	};

	outfile << "// IP summary --- IEND" << endl;

	// --- init.prcs
	outfile << "// IP init.prcs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		outfile << "void " << mdl->sref << StrMod::cap(prc->sref) << "Init(void);" << endl;
	};
	outfile << "// IP init.prcs --- IEND" << endl;

	// --- run.prcs
	outfile << "// IP run.prcs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		outfile << "bool " << mdl->sref << StrMod::cap(prc->sref) << "Run(void);" << endl;
	};
	outfile << "// IP run.prcs --- IEND" << endl;
};

void WdbeWrmcuMdlraw::writeMdlC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, const string& Compsref
			, WdbeMModule* mdl
			, ListWdbeMProcess& prcs
		) {
	WdbeMProcess* prc = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	bool first;

	// --- shrdat
	dbswdbe->tblwdbemsignal->loadRstByMdl(mdl->ref, false, sigs);

	outfile << "// IP shrdat --- IBEGIN" << endl;

	outfile << "struct Shrdat" << Compsref << " shrdat"  << Compsref;

	first = true;

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::VOID) && sig->Const) {
			if (first) {
				outfile << " = {" << endl << "\t";
				first = false;
			} else {
				outfile << "," << endl << "\t";
			};

			outfile << "." << sig->sref << " = " << getValStr(sig);
		};
	};
	if (!first) outfile << endl << "}";
	outfile << ";" << endl;

	outfile << "// IP shrdat --- IEND" << endl;

	// --- vars
	outfile << "// IP vars --- IBEGIN" << endl;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "// --- " << prc->Comment << " (" << prc->sref << ")" << endl;

		if (prc->refWdbeMFsm != 0) {
			outfile << "// IP vars." << prc->sref << ".fsm --- INSERT" << endl;
			outfile << endl;
		};

		outfile << "// IP vars." << prc->sref << ".cust --- INSERT" << endl;
	};
	outfile << "// IP vars --- IEND" << endl;

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		outfile << "\t" << mdl->sref << StrMod::cap(prc->sref) << "Init();" << endl;
	};
	outfile << "// IP init --- IEND" << endl;

	// --- init.prcs
	outfile << "// IP init.prcs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "void " << mdl->sref << StrMod::cap(prc->sref) << "Init() {" << endl;
		outfile << "\t// IP " << mdl->sref << StrMod::cap(prc->sref) << "Init --- INSERT" << endl;
		outfile << "\t// IP " << mdl->sref << StrMod::cap(prc->sref) << "Init.cust --- INSERT" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "// IP init.prcs --- IEND" << endl;

	// --- run
	outfile << "// IP run --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		outfile << "\tif (" << mdl->sref << StrMod::cap(prc->sref) << "Run()) mod = true;" << endl;
	};
	outfile << "// IP run --- IEND" << endl;

	// --- run.prcs
	outfile << "// IP run.prcs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "bool " << mdl->sref << StrMod::cap(prc->sref) << "Run() {" << endl;
		outfile << "\tbool mod = false;" << endl;
		outfile << endl;

		outfile << "\t// IP " << mdl->sref << StrMod::cap(prc->sref) << "Run.pre --- INSERT" << endl;
		outfile << endl;

		outfile << "\t// IP " << mdl->sref << StrMod::cap(prc->sref) << "Run --- INSERT" << endl;

		outfile << "\treturn mod;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "// IP run.prcs --- IEND" << endl;
};
// IP cust --- IEND


