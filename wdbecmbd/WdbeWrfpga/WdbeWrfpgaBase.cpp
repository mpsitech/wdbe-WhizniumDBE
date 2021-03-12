/**
	* \file WdbeWrfpgaBase.cpp
	* Wdbe operation processor - write VHDL/UCF/XDC code basics (implementation)
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

#include "WdbeWrfpgaBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaBase
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaBase::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaBase* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMUnit* unt = NULL;

	ListWdbeMPort topprts;
	set<string> srefsTopprts;

	ListWdbeMBank bnks;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		if ((unt->srefKToolch == "ise") || (unt->srefKToolch == "vivado") || (unt->srefKToolch == "vivzynq")) {
			// find ports in use
			dbswdbe->tblwdbemport->loadRstBySQL("SELECT TblWdbeMPort.* FROM TblWdbeMModule, TblWdbeMPort WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(refWdbeMUnit)
						+ " AND TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::TOP) + " AND TblWdbeMPort.mdlRefWdbeMModule = TblWdbeMModule.ref", false, topprts);
			for (unsigned int i = 0; i < topprts.nodes.size(); i++) srefsTopprts.insert(topprts.nodes[i]->sref);

			dbswdbe->tblwdbembank->loadRstByUnt(refWdbeMUnit, false, bnks);

			if (s == "ise") {
				// xxxx/Xxxx.ucf
				s = xchg->tmppath + "/" + folder + "/" + Untsref + ".ucf.ip";
				outfile.open(s.c_str(), ios::out);
				writeUntUcf(dbswdbe, outfile, srefsTopprts, bnks);
				outfile.close();
			} else {
				// xxxx/Xxxx.xdc
				s = xchg->tmppath + "/" + folder + "/" + Untsref+ ".xdc.ip";
				outfile.open(s.c_str(), ios::out);
				writeUntXdc(dbswdbe, outfile, refWdbeMUnit, srefsTopprts, bnks, (unt->srefKToolch == "vivzynq"));
				outfile.close();
			};

			// xxxx/Xxxx.vhd
			s = xchg->tmppath + "/" + folder + "/" + Untsref + ".vhd.ip";
			outfile.open(s.c_str(), ios::out);
			writeUntVhd(dbswdbe, outfile, Prjshort, Untsref, unt);
			outfile.close();
		};

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaBase::writeUntUcf(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, set<string>& srefsTopprts
			, ListWdbeMBank& bnks
		) {
	WdbeMBank* bnk = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeAMPinPar ppas;
	map<string,WdbeAMPinPar*> srefsPpas;

	string iostd;
	int period;

	string s;

	size_t ptr;

	bool first;

	// --- pins
	outfile << "# IP pins --- IBEGIN" << endl;

	// list pins by I/O bank
	for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
		bnk = bnks.nodes[i];

		iostd = "LVCMOS33";
		if (bnk->srefKVoltstd == "_1v2") iostd = "LVCMOS12";
		else if (bnk->srefKVoltstd == "_1v8") iostd = "LVCMOS18";
		else if (bnk->srefKVoltstd == "_2v5") iostd = "LVCMOS25";

		dbswdbe->tblwdbempin->loadRstByBnk(bnk->ref, false, pins);
		first = true;

		for (unsigned int j = 0; j < pins.nodes.size(); j++) {
			pin = pins.nodes[j];

			s = pin->sref;
			ptr = s.find('[');
			if (ptr != string::npos) s = s.substr(0, ptr);

			if (srefsTopprts.find(s) != srefsTopprts.end()) {
				dbswdbe->tblwdbeampinpar->loadRstByPin(pin->ref, false, ppas);
				srefsPpas.clear();
				for (unsigned int k = 0; k < ppas.nodes.size(); k++) srefsPpas[ppas.nodes[k]->x1SrefKKey] = ppas.nodes[k];

				if (first) {
					outfile << endl;
					outfile << "# " << StubWdbe::getStubBnkStd(dbswdbe, bnk->ref) << endl;
					first = false;
				};

				outfile << "NET \"" << pin->sref << "\" LOC=" << StrMod::uc(pin->Location);
				if (srefsPpas.find("lvds") == srefsPpas.end()) outfile << " | IOSTANDARD=" << iostd;

				auto it = srefsPpas.find("fclk");
				if (it != srefsPpas.end()) {
					period = 1000000 / atoi(it->second->Val.c_str());
					outfile << " | PERIOD=" << period << "ns";
				};

				if (srefsPpas.find("noclkdr") != srefsPpas.end()) outfile << " | CLOCK_DEDICATED_ROUTE=FALSE";

				outfile << ";" << endl;
			};
		};
	};

	outfile << "# IP pins --- IEND" << endl;
};

void WdbeWrfpgaBase::writeUntXdc(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const ubigint refWdbeMUnit
			, set<string>& srefsTopprts
			, ListWdbeMBank& bnks
			, const bool zynqNotFpga
		) {
	vector<ubigint> refs;

	vector<bool> occsBnks;
	WdbeMBank* bnk = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeAMPinPar ppas;
	map<string,WdbeAMPinPar*> srefsPpas;

	ubigint refMtp;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string iostd;
	bool bus;
	int period;

	string s;

	size_t ptr;

	bool first;

	// --- pins
	outfile << "# IP pins --- IBEGIN" << endl;

	occsBnks.resize(bnks.nodes.size());

	// list pins by I/O bank
	for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
		bnk = bnks.nodes[i];

		dbswdbe->tblwdbempin->loadRstByBnk(bnk->ref, false, pins);

		occsBnks[i] = (pins.nodes.size() > 0);

		first = true;
		for (unsigned int j = 0; j < pins.nodes.size(); j++) {
			pin = pins.nodes[j];

			s = pin->sref;
			ptr = s.find('[');
			if (ptr != string::npos) s = s.substr(0, ptr);
			bus = (ptr != string::npos);

			if (srefsTopprts.find(s) != srefsTopprts.end()) {
				dbswdbe->tblwdbeampinpar->loadRstByPin(pin->ref, false, ppas);
				srefsPpas.clear();
				for (unsigned int k = 0; k < ppas.nodes.size(); k++) srefsPpas[ppas.nodes[k]->x1SrefKKey] = ppas.nodes[k];

				if (first) {
					outfile << endl;
					outfile << "# " << StubWdbe::getStubBnkStd(dbswdbe, bnk->ref) << endl;
					first = false;
				};

				outfile << "set_property PACKAGE_PIN " << StrMod::uc(pin->Location) << " [get_ports ";
				if (bus) outfile << "{" << pin->sref << "}";
				else outfile << pin->sref;
				outfile << "];" << endl;

				if (srefsPpas.find("noclkdr") != srefsPpas.end()) {
					outfile << "\tset_property CLOCK_DEDICATED_ROUTE FALSE [get_ports ";
					if (bus) outfile << "{" << pin->sref << "}";
					else outfile << pin->sref;
					outfile << "];" << endl;
				};
			};
		};
	};

	outfile << "# IP pins --- IEND" << endl;

	// --- bnks
	outfile << "# IP bnks --- IBEGIN" << endl;
	outfile << "# banks" << endl;

	for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
		bnk = bnks.nodes[i];

		if (occsBnks[i]) {
			ptr = bnk->sref.find("bank");
			if (ptr == 0) bnk->sref = bnk->sref.substr(4);

			iostd = "LVCMOS33";
			if (bnk->srefKVoltstd == "_1v2") iostd = "LVCMOS12";
			else if (bnk->srefKVoltstd == "_1v8") iostd = "LVCMOS18";
			else if (bnk->srefKVoltstd == "_2v5") iostd = "LVCMOS25";

			outfile << "set_property IOSTANDARD " << iostd << " [get_ports -of_objects [get_iobanks " << bnk->sref << "]];" << endl;
		};
	};
	outfile << "# IP bnks --- IEND" << endl;

	// --- clks
	outfile << "# IP clks --- IBEGIN" << endl;
	outfile << "# IP clks --- BEGIN" << endl;
	outfile << "# clocks" << endl;
	if (zynqNotFpga) outfile << "# a clock by the name of clk_fpga_0 is generated automatically with the correct timing" << endl;

	for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
		bnk = bnks.nodes[i];

		dbswdbe->tblwdbempin->loadRstByBnk(bnk->ref, false, pins);

		for (unsigned int j = 0; j < pins.nodes.size(); j++) {
			pin = pins.nodes[j];

			s = pin->sref;
			ptr = s.find('[');
			if (ptr != string::npos) s = s.substr(0, ptr);
			bus = (ptr != string::npos);

			if (srefsTopprts.find(s) != srefsTopprts.end()) {
				dbswdbe->tblwdbeampinpar->loadRstByPin(pin->ref, false, ppas);
				srefsPpas.clear();
				for (unsigned int k = 0; k < ppas.nodes.size(); k++) srefsPpas[ppas.nodes[k]->x1SrefKKey] = ppas.nodes[k];

				auto it = srefsPpas.find("fclk");
				if (it != srefsPpas.end()) {
					period = 1000000 / atoi(it->second->Val.c_str());
					outfile << "create_clock -name " << pin->sref << " -period " << period << " -waveform {0 " << (period/2) << "} [get_ports ";
					if (bus) outfile << "{" << pin->sref << "}";
					else outfile << pin->sref;
					outfile << "];" << endl;
				};
			};
		};
	};

	// derived clocks
	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + " AND supRefWdbeMModule = 0 AND tplRefWdbeMModule = 0 AND sref = 'BUFG'", refMtp)) {
		dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND tplRefWdbeMModule = "
					+ to_string(refMtp) + " ORDER BY hkNum ASC", false, refs);

		for (unsigned int i = 0; i < refs.size();i++) {
			dbswdbe->tblwdbemmodule->loadHrstup(refs[i], mdls);
			
			if (mdls.nodes.size() > 0) {
				if (dbswdbe->loadStringBySQL("SELECT csiSrefWdbeMSignal FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdls.nodes[0]->ref) + " AND sref = 'O'", s)) {
					outfile << "#create_generated_clock -name " << s << " -source [get_ports/get_pins xxxxx] -edges {a b c} [get_pins root/";
					for (unsigned int j=mdls.nodes.size();j>0;j--) {
						mdl = mdls.nodes[j-1];
						outfile << "my" << StrMod::cap(mdl->sref) << "/";
					};
					outfile << "O];" << endl;
				};
			};
		};
	};
	outfile << "# IP clks --- END" << endl;
	outfile << "# IP clks --- IEND" << endl;
};

void WdbeWrfpgaBase::writeUntVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMUnit* unt
		) {
	ubigint ref;

	ListWdbeMUnit sysunts;
	WdbeMUnit* sysunt = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	ListWdbeAVKeylistKey klsAkeys;
	WdbeAVKeylistKey* klsAkey = NULL;

	bool first;

	if (!unt->Easy) {
		// --- prjpkg
		outfile << "-- IP prjpkg --- IBEGIN" << endl;

		// buffer vectors: include all system units in reach from unit via forwarding controller
		sysunts.nodes.push_back(new WdbeMUnit(*unt));

		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMModule, TblWdbeMController, TblWdbeMUnit WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
					+ " AND TblWdbeMModule.hkUref = " + to_string(unt->ref) + " AND TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMUnit.ref = TblWdbeMController.fwdRefWdbeMUnit ORDER BY TblWdbeMUnit.sref ASC",
					true, sysunts);

		first = true;
		for (unsigned int i = 0; i < sysunts.nodes.size(); i++) {
			sysunt = sysunts.nodes[i];

			if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(sysunt->ref)
						+ " AND sref = 'VecW" + Prjshort + StrMod::cap(sysunt->sref) + "Buffer'", &vec)) {

				if (first) first = false;
				else outfile << endl;

				dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << "\tconstant tix" << vec->sref.substr(3) << StrMod::cap(vit->sref) << ": std_logic_vector(7 downto 0) := x\"" << Wdbe::binToHex(vit->vecNum) << "\";" << endl;
				};

				delete vec;
			};
		};

		outfile << "-- IP prjpkg --- IEND" << endl;
	};

	// --- untpkgs
	outfile << "-- IP untpkgs --- IBEGIN" << endl;
	outfile << "library ieee;" << endl;
	outfile << "use ieee.std_logic_1164.all;" << endl;
	outfile << "use ieee.numeric_std.all;" << endl;
	outfile << endl;

	outfile << "package " << Untsref << " is" << endl;

	if (unt->Easy) {
		// vectors associated with unit or controller command sets
		dbswdbe->tblwdbemvector->loadRstBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " ORDER BY sref ASC", false, vecs);

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			if (i != 0) outfile << endl;

			dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

			if (vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << "\tconstant ix" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4) << StrMod::cap(vit->sref) << ": natural := " << vit->vecNum << ";" << endl;
				};
			} else {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];

					// ex. VecWSimdArtyBuffer -> tixWArtyBuffer...
					outfile << "\tconstant tix" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4) << StrMod::cap(vit->sref) << ": std_logic_vector(7 downto 0) := x\"" << Wdbe::binToHex(vit->vecNum) << "\";" << endl;
				};
			};
		};

		dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMModule, TblWdbeMVector WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = "
					+ to_string(unt->ref) + " AND TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " AND TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR)
					+ " AND TblWdbeMVector.hkUref = TblWdbeMModule.refWdbeMController AND TblWdbeMVector.sref LIKE 'VecV%Command' ORDER BY TblWdbeMVector.sref ASC", false, vecs);

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			if (i != 0) outfile << endl;

			dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

			if (vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << "\tconstant ix" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4+4) << StrMod::cap(vit->sref) << ": natural := " << vit->vecNum << ";" << endl;
				};
			} else {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];

					// ex. VecVSimdArtyCoulcntCommand -> tixVCoulcntCommand...
					outfile << "\tconstant tix" << vec->sref.substr(3, 1) << vec->sref.substr(3+1+4+4) << StrMod::cap(vit->sref) << ": std_logic_vector(7 downto 0) := x\"" << Wdbe::binToHex(vit->vecNum) << "\";" << endl;
				};
			};
		};

	} else {
		// vectors associated with unit or top module signals
		dbswdbe->tblwdbemvector->loadRstBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref)
					+ " AND sref <> 'VecW" + Prjshort + Untsref + "Buffer' ORDER BY sref ASC", false, vecs);
		dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMSignal, TblWdbeMVector WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(unt->refWdbeMModule)
					+ " AND TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::SIG) + " AND TblWdbeMVector.hkUref = TblWdbeMSignal.ref ORDER BY TblWdbeMVector.sref ASC", true, vecs);

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			if (i != 0) outfile << endl;

			dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

			if (vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << "\tconstant ix" << vec->sref.substr(3) << StrMod::cap(vit->sref) << ": natural := " << vit->vecNum << ";" << endl;
				};
			} else {
				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << "\tconstant tix" << vec->sref.substr(3) << StrMod::cap(vit->sref) << ": std_logic_vector(7 downto 0) := x\"" << Wdbe::binToHex(vit->vecNum) << "\";" << endl;
				};
			};
		};
	};
	outfile << "end " << Untsref << ";" << endl;

	// types associated with module templates and modules
	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT TblWdbeMModule2.* FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMModule AS TblWdbeMModule2 WHERE TblWdbeMModule1.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
				+ " AND TblWdbeMModule1.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule2.ref = TblWdbeMModule1.tplRefWdbeMModule ORDER BY TblWdbeMModule2.sref ASC", false, mdls);
	dbswdbe->tblwdbemmodule->loadRstByHktHku(VecWdbeVMModuleHkTbl::UNT, unt->ref, true, mdls);

	ref = 0;
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->ref != ref) { // DISTINCT clause doesn't allow for tpl sref ordering
			dbswdbe->tblwdbeavkeylistkey->loadRstByKlsMtbUrf(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, VecWdbeVMaintable::TBLWDBEMMODULE, mdl->ref, false, klsAkeys);
			if (klsAkeys.nodes.size() > 0) {
				outfile << endl;

				outfile << "library ieee;" << endl;
				outfile << "use ieee.std_logic_1164.all;" << endl;
				outfile << "use ieee.numeric_std.all;" << endl;
				outfile << endl;

				outfile << "package " << StrMod::cap(mdl->sref) << "_lib is" << endl;
				for (unsigned int j = 0; j < klsAkeys.nodes.size(); j++) {
					klsAkey = klsAkeys.nodes[j];

					outfile << "\ttype " << klsAkey->sref << " is " << klsAkey->Title << ";" << endl;
				};
				outfile << "end " << StrMod::cap(mdl->sref) << "_lib;" << endl;
			};

			ref = mdl->ref;
		};
	};

	outfile << "-- IP untpkgs --- IEND" << endl;
};
// IP cust --- IEND
