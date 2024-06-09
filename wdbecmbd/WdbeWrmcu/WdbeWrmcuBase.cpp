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

// IP ns.cust --- INSERT

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

	unsigned int snsbyte, evtbyte;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		dbswdbe->tblwdbemmodule->loadRstByHktHku(VecWdbeVMModuleHkTbl::UNT, unt->ref, false, mdls);

		// xxxx/Xxxx.h
		s = xchg->tmppath + "/" + folder + "/" + Untsref + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntH(dbswdbe, outfile, unt, Untsref, mdls, snsbyte, evtbyte);
		outfile.close();

		// xxxx/Xxxx_exe.c
		s = xchg->tmppath + "/" + folder + "/" + Untsref + "_exe.c.ip";
		outfile.open(s.c_str(), ios::out);
		writeUntExeC(dbswdbe, outfile, unt, mdls, snsbyte, evtbyte);
		outfile.close();

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
/******************************************************************************
 class WdbeWrmcuBase::Event
 ******************************************************************************/

WdbeWrmcuBase::Event::Event(
			const unsigned int ixVSection
			, const string& sref
			, const bool cluster
			, const unsigned int evtbyte
			, const unsigned char value
		) {
	this->ixVSection = ixVSection;
	this->sref = sref;
	this->cluster = cluster;
	this->evtbyte = evtbyte;
	this->value = value;

	mdlSet = NULL;
};

/******************************************************************************
 class WdbeWrmcuBase::Module
 ******************************************************************************/

WdbeWrmcuBase::Module::Module(
			const string& sref
			, const unsigned int snsbyte
			, const unsigned char value
		) {
	this->sref = sref;
	this->snsbyte = snsbyte;
	this->value = value;
};

/******************************************************************************
 namespace WdbeWrmcuBase
 ******************************************************************************/

void WdbeWrmcuBase::writeUntH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, const string& Untsref
			, ListWdbeMModule& mdls
			, unsigned int& snsbyte
			, unsigned int& evtbyte
		) {
	vector<ubigint> refs;

	map<ubigint,string> srefsMdls;
	WdbeMModule* mdl = NULL;

	ListWdbeMPeripheral pphs;
	WdbeMPeripheral* pph = NULL;

	ListWdbeMBank bnks;
	WdbeMBank* bnk = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	ListWdbeMInterrupt isrs;
	WdbeMInterrupt* isr = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	ListWdbeMSensitivity snss;
	WdbeMSensitivity* sns = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	ListWdbeMVariable vars;
	WdbeMVariable* var = NULL;

	vector<Module*> mods;
	map<ubigint,Module*> refsMods;
	Module* mod = NULL;
	Module* mod2 = NULL;

	unsigned char value;

	vector<Event*> evts;
	Event* evt = NULL;

	unsigned int ixVSection;
	string sref;
	string srefroot, srefroot_last;

	unsigned int evtbyte_test, snsbyte_test;

	vector<string> ss;
	string s;

	bool first, first2;

	ubigint refC;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) srefsMdls[mdls.nodes[i]->ref] = mdls.nodes[i]->sref;

	// --- summary
	outfile << "// IP summary --- IBEGIN" << endl;
	// ex.
	/*
		peripherals:
			uartrx, uarttx: uart0 (rxd@8, txd@9)
			laser, disp: spi0 (cs@21, sclk@22, mosi@23)
		input pins:
			vmon: magswpn@7
		output pins:
			state: ledr@12, ledg@13, ledb@14
	*/

	outfile << "/*" << endl;

	outfile << "\tperipherals:" << endl;

	dbswdbe->tblwdbemperipheral->loadRstByUnt(unt->ref, false, pphs);

	for (unsigned int i = 0; i < pphs.nodes.size(); i++) {
		pph = pphs.nodes[i];

		outfile << "\t\t";

		dbswdbe->tblwdbermmodulemperipheral->loadMdlsByPph(pph->ref, false, refs);

		first = true;
		for (unsigned int j = 0; j < refs.size(); j++) {
			auto it = srefsMdls.find(refs[j]);

			if (it != srefsMdls.end()) {
				if (first) first = false;
				else outfile << ", ";
				outfile << it->second;
			};
		};
		if (!first) outfile << ": ";

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

		outfile << endl;
	};

	if (pphs.nodes.size() == 0) outfile << "\t\t(none)" << endl;

	outfile << "\tinput pins:" << endl;

	first = true;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND mdlIxVCat = " + to_string(VecWdbeVMPortMdlCat::RTEPIN)
					+ " AND ixVDir = " + to_string(VecWdbeVMPortDir::IN) + " ORDER BY mdlNum ASC", false, prts);

		if (prts.nodes.size() > 0) {
			first = false;

			outfile << "\t\t" << mdl->sref << ":";

			for (unsigned int j = 0; j < prts.nodes.size(); j++) {
				prt = prts.nodes[j];

				if (j != 0) outfile << ",";

				if (dbswdbe->tblwdbempin->loadRecBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMBank, TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeJMPinSref.sref = '" + prt->cpiSrefWdbeMPin
							+ "' AND TblWdbeMPin.ref = TblWdbeJMPinSref.refWdbeMPin AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref), &pin)) {

					outfile << " " << pin->sref << "@" << pin->Location;
					delete pin;

				} else outfile << " " << prt->sref;
			};

			outfile << endl;
		};
	};
	if (first) outfile << "\t\t(none)" << endl;

	outfile << "\toutput pins:" << endl;

	first = true;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND mdlIxVCat = " + to_string(VecWdbeVMPortMdlCat::RTEPIN)
					+ " AND ixVDir = " + to_string(VecWdbeVMPortDir::OUT) + " ORDER BY mdlNum ASC", false, prts);

		if (prts.nodes.size() > 0) {
			first = false;

			outfile << "\t\t" << mdl->sref << ":";

			for (unsigned int j = 0; j < prts.nodes.size(); j++) {
				prt = prts.nodes[j];

				if (j != 0) outfile << ",";

				if (dbswdbe->tblwdbempin->loadRecBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMBank, TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeJMPinSref.sref = '" + prt->cpiSrefWdbeMPin
							+ "' AND TblWdbeMPin.ref = TblWdbeJMPinSref.refWdbeMPin AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref), &pin)) {

					outfile << " " << pin->sref << "@" << pin->Location;
					delete pin;

				} else outfile << " " << prt->sref;
			};

			outfile << endl;
		};
	};
	if (first) outfile << "\t\t(none)" << endl;

	outfile << "*/" << endl;
	outfile << "// IP summary --- IEND" << endl;

	// --- define.easy*
	if (unt->Easy) outfile << "// IP define.easy --- AFFIRM" << endl;
	else outfile << "// IP define.easy --- REMOVE" << endl;

	// --- define.full*
	if (!unt->Easy) outfile << "// IP define.full --- AFFIRM" << endl;
	else outfile << "// IP define.full --- REMOVE" << endl;

	// --- define.unts
	outfile << "// IP define.unts --- IBEGIN" << endl;

	// vectors associated with unit or controllers
	dbswdbe->tblwdbemvector->loadRstBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " ORDER BY sref ASC", false, vecs);
	dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMModule, TblWdbeMVector WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = "
				+ to_string(unt->ref) + " AND (TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " OR TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EDBGCTR)
				+ ") AND TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND TblWdbeMVector.hkUref = TblWdbeMModule.refWdbeMController ORDER BY TblWdbeMVector.sref ASC", true, vecs);

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		if (i != 0) outfile << endl;

		dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

		if (vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) {
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];
				outfile << "#define VEC" << StrMod::uc(Wdbe::getVecSubsref(Untsref, vec->sref)) << "_" << vit->sref << " " << vit->vecNum << endl;
			};
		} else {
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];
				outfile << "#define VEC" << StrMod::uc(Wdbe::getVecSubsref(Untsref, vec->sref)) << "_" << vit->sref << " 0x" << Wdbe::binToHex(vit->vecNum) << endl;
			};
		};
	};

	outfile << "// IP define.unts --- IEND" << endl;

	// --- pins
	if (unt->srefKToolch == "splcty") {
		outfile << "// IP pins --- IBEGIN" << endl;
		outfile << "// IP pins --- BEGIN" << endl;

		// use C51 compiler sbit aliasses
		// ex. 'sbit TN = SFR_P0^0;'

		dbswdbe->tblwdbembank->loadRstByUnt(unt->ref, false, bnks);

		for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
			bnk = bnks.nodes[i];

			dbswdbe->tblwdbempin->loadRstByBnk(bnk->ref, false, pins);

			for (unsigned int j = 0; j < pins.nodes.size(); j++) {
				pin = pins.nodes[j];

				if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeJMPinSref WHERE refWdbeMPin = " + to_string(pin->ref) + " AND sref <> '" + pin->sref + "'", s)) 
							outfile << "sbit " << StrMod::uc(pin->sref) << " = SFR_" << StrMod::uc(StrMod::replaceChar(s, '.', '^')) << ";" << endl;
			};
		};

		outfile << "// IP pins --- END" << endl;
		outfile << "// IP pins --- IEND" << endl;
	};

	// --- evts
	outfile << "// IP evts --- IBEGIN" << endl;

	// prepare module vector
	snsbyte = 0;
	value = 0x01;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		mod = new Module(mdl->sref, snsbyte, value);
		mods.push_back(mod);

		refsMods[mdl->ref] = mod;

		if (value == 0x80) {
			value = 0x01;
			snsbyte++;
		} else (value <<= 1);
	};

	if (value == 0x01) snsbyte--;

	// prepare event vector
	evtbyte = 0;
	value = 0x01;

	dbswdbe->tblwdbeminterrupt->loadRstByUnt(unt->ref, false, isrs);
	for (unsigned int i = 0; i < isrs.nodes.size(); i++) {
		isr = isrs.nodes[i];

		evt = new Event(Event::VecVSection::ISR, isr->sref, false, evtbyte, value);
		evts.push_back(evt);

		if (value == 0x80) {
			value = 0x01;
			evtbyte++;
		} else (value <<= 1);

		dbswdbe->tblwdbemsensitivity->loadRstBySQL("SELECT * FROM TblWdbeMSensitivity WHERE srcIxVTbl = " + to_string(VecWdbeVMSensitivitySrcTbl::INT) + " AND srcUref = " + to_string(isr->ref), false, snss);

		for (unsigned int j = 0; j < snss.nodes.size(); j++) {
			sns = snss.nodes[j];

			if (sns->refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) {
				if (refsMods.find(sns->refUref) == refsMods.end()) cout << "module reference " << sns->refUref << " not found!" << endl;
				evt->mdlsGet.push_back(refsMods[sns->refUref]);
			};
		};
	};

	dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::HSHK) + " ORDER BY refNum ASC", false, sigs);
	dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::STRB) + " ORDER BY refNum ASC", true, sigs); // includes strobes for statsng shared data updates

	refC = 0;

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) {
			evt = new Event((sig->ixVBasetype == VecWdbeVMSignalBasetype::HSHK) ? Event::VecVSection::HSHK : Event::VecVSection::STRB, sig->sref, (sig->refWdbeCSignal == refC), evtbyte, value);
			evts.push_back(evt);

			if (value == 0x80) {
				value = 0x01;
				evtbyte++;
			} else (value <<= 1);

			refC = sig->refWdbeCSignal;

			evt->mdlSet = refsMods[sig->mgeUref];

			dbswdbe->tblwdbemsensitivity->loadRstBySQL("SELECT * FROM TblWdbeMSensitivity WHERE srcIxVTbl = " + to_string(VecWdbeVMSensitivitySrcTbl::SIG) + " AND srcUref = " + to_string(sig->ref), false, snss);

			for (unsigned int j = 0; j < snss.nodes.size(); j++) {
				sns = snss.nodes[j];

				if (sns->refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) {
					if (refsMods.find(sns->refUref) == refsMods.end()) cout << "module reference " << sns->refUref << " not found!" << endl;
					evt->mdlsGet.push_back(refsMods[sns->refUref]);
				};
			};
		};
	};

	if (value == 0x01) evtbyte--;

	// reverse association of events to modules
	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		for (unsigned int j = 0; j < evts.size(); j++) {
			evt = evts[j];

			for (unsigned int k = 0; k < evt->mdlsGet.size(); k++) if (evt->mdlsGet[k] == mod) mod->evtsGet.push_back(evt);
			if (evt->mdlSet == mod) mod->evtsSet.push_back(evt);
		};
	};

	// output
	outfile << "// - flags" << endl;

	outfile << "extern";
	if (unt->srefKToolch == "splcty") outfile << " bdata";
	outfile << " struct Flags {" << endl;

	outfile << "\t// handshake" << endl;

	first = true;

	for (unsigned int i = 0; i < evts.size(); i++) {
		evt = evts[i];

		if (evt->ixVSection == Event::VecVSection::HSHK) {
			if (first) first = false;
			else if (!evt->cluster) outfile << endl;

			outfile << "\tunsigned char " << evt->sref << ":1;" << endl;
		};
	};

	outfile << "} flags;" << endl;
	outfile << endl;

	outfile << "// - events" << endl;
	outfile << "extern unsigned char";
	for (unsigned i = 0; i <= evtbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " evts" << i;
	};
	outfile << ";" << endl;
	outfile << endl;

	ixVSection = 0;
	for (unsigned int i = 0; i < evts.size(); i++) {
		evt = evts[i];
		mod = evt->mdlSet;

		if (evt->ixVSection != ixVSection) {
			outfile << endl;

			if (evt->ixVSection == Event::VecVSection::ISR) outfile << "// interrupts" << endl;
			else if (evt->ixVSection == Event::VecVSection::HSHK) outfile << "// handshake" << endl;
			else if (evt->ixVSection == Event::VecVSection::STRB) outfile << "// strobes including statsng command shared data updates" << endl;

			ixVSection = evt->ixVSection;
		};

		if (!evt->cluster) outfile << endl;
		outfile << "#define EVTS" << evt->evtbyte << "_" << evt->sref << " 0x" << Wdbe::binToHex(evt->value) << endl;

		outfile << "#define SET_EVT_" << evt->sref << "() \\" << endl;
		outfile << "\t{evts" << evt->evtbyte << " |= EVTS" << evt->evtbyte << "_" << evt->sref << ";";
		if (mod) outfile << " \\" << endl << "\tacts" << mod->snsbyte << " |= ACTS" << mod->snsbyte << "_" << mod->sref << ";";
		for (unsigned int j = 0; j < evt->mdlsGet.size(); j++) {
			mod2 = evt->mdlsGet[j];
			outfile << " \\" << endl << "\tsnss" << mod2->snsbyte << " |= SNSS" << mod2->snsbyte << "_" << mod2->sref << ";";
		};
		outfile << "}" << endl;

		outfile << "#define IS_SET_EVT_" << evt->sref << "() ((evts" << evt->evtbyte << " & EVTS" << evt->evtbyte << "_" << evt->sref << ") != 0)" << endl;
	};

	outfile << endl;
	outfile << "#define HAVE_NO_EVTS() ((";
	for (unsigned i = 0; i <= evtbyte; i++) {
		if (i != 0) outfile << " | ";
		outfile << "evts" << i;
	};
	outfile << ") == 0)" << endl;

	outfile << endl;
	outfile << "#define CLEAR_EVTS_ISR()";

	evtbyte_test = -1;
	first = true;

	for (unsigned int i = 0; i < evts.size(); i++) {
		evt = evts[i];

		if (evt->ixVSection == Event::VecVSection::ISR) {
			if (evt->evtbyte != evtbyte_test) {
				if (!first) outfile << ");";
				outfile << " \\" << endl;
				outfile << "\tevts" << evt->evtbyte << " &= ~(";
				evtbyte_test = evt->evtbyte;

				first = false;
				first2 = true;
			};

			if (first2) first2 = false;
			else outfile << " | ";

			outfile << "EVTS" << evt->evtbyte << "_" << evt->sref;
		};
	};

	if (first) outfile << endl;
	else outfile << ");" << endl;

	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		outfile << endl;
		outfile << "#define CLEAR_EVTS_FROM_" << StrMod::uc(mod->sref) << "()";

		evtbyte_test = -1;
		first = true;

		for (unsigned int j = 0; j < mod->evtsSet.size(); j++) {
			evt = mod->evtsSet[j];

			if (evt->evtbyte != evtbyte_test) {
				if (!first) outfile << ");";
				outfile << " \\" << endl;
				outfile << "\tevts" << evt->evtbyte << " &= ~(";
				evtbyte_test = evt->evtbyte;

				first = false;
				first2 = true;
			};

			if (first2) first2 = false;
			else outfile << " | ";

			outfile << "EVTS" << evt->evtbyte << "_" << evt->sref;
		};

		if (!first) outfile << ");";
		outfile << " \\" << endl << "\tacts" << mod->snsbyte << " &= ~ACTS" << mod->snsbyte << "_" << mod->sref << ";" << endl;

		outfile << endl;
		outfile << "#define HAVE_EVTS_FOR_" << StrMod::uc(mod->sref) << "() ((";

		evtbyte_test = -1;
		first = true;

		for (unsigned int j = 0; j < mod->evtsGet.size(); j++) {
			evt = mod->evtsGet[j];

			if (evt->evtbyte != evtbyte_test) {
				if (!first) outfile << "))";
				outfile << " \\" << endl;
				outfile << "\t\t";
				if (!first) outfile << "| ";
				outfile << "(evts" << evt->evtbyte << " & (";
				evtbyte_test = evt->evtbyte;

				first = false;
				first2 = true;
			};

			if (first2) first2 = false;
			else outfile << " | ";

			outfile << "EVTS" << evt->evtbyte << "_" << evt->sref;
		};

		if (first) outfile << "false))" << endl;
		else outfile << ")) \\" << endl << "\t!= 0))" << endl;
	};

	outfile << endl;
	outfile << "// - activities" << endl;
	outfile << "extern unsigned char";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " acts" << i;
	};
	outfile << ";" << endl;

	snsbyte_test = -1;
	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		if (mod->snsbyte != snsbyte_test) {
			outfile << endl;
			snsbyte_test = mod->snsbyte;
		};

		outfile << "#define ACTS" << mod->snsbyte << "_" << mod->sref << " 0x" << Wdbe::binToHex(mod->value) << endl;
	};

	outfile << endl;
	outfile << "#define HAVE_NO_ACTS() ((";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << " | ";
		outfile << "acts" << i;
	};
	outfile << ") == 0)" << endl;

	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		outfile << endl;
		outfile << "#define SET_ACTIVE_" << StrMod::uc(mod->sref) << "() acts" << mod->snsbyte << " |= ACTS" << mod->snsbyte << "_" << mod->sref << ";" << endl;
		outfile << "#define UNSET_ACTIVE_" << StrMod::uc(mod->sref) << "() acts" << mod->snsbyte << " &= ~ACTS" << mod->snsbyte << "_" << mod->sref << ";" << endl;
		outfile << "#define IS_ACTIVE_" << StrMod::uc(mod->sref) << "() ((acts" << mod->snsbyte << " & ACTS" << mod->snsbyte << "_" << mod->sref << ") != 0)" << endl;
	};

	outfile << endl;
	outfile << "// - sensitivities" << endl;
	outfile << "extern unsigned char";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " snss" << i;
	};
	outfile << ";" << endl;

	snsbyte_test = -1;
	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		if (mod->snsbyte != snsbyte_test) {
			outfile << endl;
			snsbyte_test = mod->snsbyte;
		};

		outfile << "#define SNSS" << mod->snsbyte << "_" << mod->sref << " 0x" << Wdbe::binToHex(mod->value) << endl;
	};

	outfile << endl;
	outfile << "#define HAVE_NO_SNSS() ((";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << " | ";
		outfile << "snss" << i;
	};
	outfile << ") == 0)" << endl;

	for (unsigned int i = 0; i < mods.size(); i++) {
		mod = mods[i];

		outfile << endl;
		outfile << "#define SET_SENSITIVE_" << StrMod::uc(mod->sref) << "() snss" << mod->snsbyte << " |= SNSS" << mod->snsbyte << "_" << mod->sref << "; sns = true;" << endl;
		outfile << "#define UNSET_SENSITIVE_" << StrMod::uc(mod->sref) << "() snss" << mod->snsbyte << " &= ~SNSS" << mod->snsbyte << "_" << mod->sref << "; sns = false;" << endl;
		outfile << "#define IS_SENSITIVE_" << StrMod::uc(mod->sref) << "() ((snss" << mod->snsbyte << " & SNSS" << mod->snsbyte << "_" << mod->sref << ") != 0)" << endl;
	};

	outfile << "// IP evts --- IEND" << endl;

	// --- mdls
	outfile << "// IP mdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		dbswdbe->tblwdbemvariable->loadRstBySQL("SELECT * FROM TblWdbeMVariable WHERE refIxVTbl = " + to_string(VecWdbeVMVariableRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " ORDER BY refNum ASC", false, vars);

		outfile << "/**" << endl;
		outfile << "\t* " << mdl->sref << " ";
		if (mdl->refWdbeMController != 0) outfile << "controller" << endl;
		else outfile << "module" << endl;
		outfile << "\t*/" << endl;
		outfile << endl;

		outfile << "// IP " << mdl->sref << ".cust --- INSERT" << endl;
		outfile << endl;

		outfile << "extern struct Shrdat" << StrMod::cap(mdl->sref) << " { // IP Shrdat" << StrMod::cap(mdl->sref) << " --- LINE" << endl;

		refC = 0;

		for (unsigned int i = 0; i < vars.nodes.size(); i++) {
			var = vars.nodes[i];

			if ((i != 0) && (var->refWdbeCVariable != refC)) outfile << endl;

			outfile << "\t" << getVarStr(var) << ";";
			if (var->Comment != "") outfile << " // " << var->Comment;
			outfile << endl;

			refC = sig->refWdbeCSignal;
		};
		if (vars.nodes.size() > 0) outfile << endl;

		if (vars.nodes.size() == 0) outfile << "\tuint8_t dummy; // IP Shrdat" << StrMod::cap(mdl->sref) << ".cust --- LINE" << endl;
		else outfile << "\t// IP Shrdat" << StrMod::cap(mdl->sref) << ".cust --- INSERT" << endl;

		outfile << "} shrdat" << StrMod::cap(mdl->sref) << ";" << endl;
		outfile << endl;
	};

	outfile << "// IP mdls --- IEND" << endl;
};

void WdbeWrmcuBase::writeUntExeC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMUnit* unt
			, ListWdbeMModule& mdls
			, const unsigned int snsbyte
			, const unsigned int evtbyte
		) {
	WdbeMModule* mdl = NULL;

	// --- include
	outfile << "// IP include --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		outfile << "#include \"" << StrMod::cap(mdl->sref) << ".h\"" << endl;
	};
	outfile << "// IP include --- IEND" << endl;

	// --- vars
	outfile << "// IP vars --- IBEGIN" << endl;

	if (unt->srefKToolch == "splcty") outfile << "bdata ";
	outfile << "volatile struct Flags flags = {0};" << endl;
	outfile << endl;

	outfile << "volatile unsigned char";
	for (unsigned i = 0; i <= evtbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " evts" << i << " = 0";
	};
	outfile << ";" << endl;
	outfile << endl;

	outfile << "volatile unsigned char";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " acts" << i << " = 0";
	};
	outfile << ";" << endl;
	outfile << "volatile unsigned char";
	for (unsigned i = 0; i <= snsbyte; i++) {
		if (i != 0) outfile << ",";
		outfile << " snss" << i << " = 0";
	};
	outfile << ";" << endl;
	outfile << endl;

	outfile << "// IP vars --- IEND" << endl;

	// --- init.mdls
	outfile << "// IP init.mdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		outfile << "\t" << mdl->sref << "Init();" << endl;
	};
	outfile << "// IP init.mdls --- IEND" << endl;

	// --- run
	outfile << "// IP run --- IBEGIN" << endl;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		outfile << endl;
		outfile << "\t\tif (IS_ACTIVE_" << StrMod::uc(mdl->sref) << "()) CLEAR_EVTS_FROM_" << StrMod::uc(mdl->sref) << "();" << endl;
		outfile << "\t\tif (IS_SENSITIVE_" << StrMod::uc(mdl->sref) << "()) if (!" << StrMod::lc(mdl->sref) << "Run()) if (HAVE_NO_SNSS()) if (HAVE_NO_ACTS()) break;" << endl;
	};
	outfile << "// IP run --- IEND" << endl;
};

// IP cust --- IEND
