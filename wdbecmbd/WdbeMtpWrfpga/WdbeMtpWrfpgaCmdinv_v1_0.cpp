/**
	* \file WdbeMtpWrfpgaCmdinv_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaCmdinv_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaCmdinv_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCmdinv_v1_0::run(
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

		// xxxx/Cmdinv.vhd
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
void WdbeMtpWrfpgaCmdinv_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	WdbeMModule* top = NULL;

	WdbeMModule* cmdbus = NULL;
	string Cmdbussref;

	WdbeMModule* cmdinv = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	set<string> srefsCtrs;

	bool first;

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::TOP), &top)) {
		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDBUS), &cmdbus)) {
			Cmdbussref = StrMod::cap(cmdbus->sref);

			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDINV), &cmdinv)) {

				dbswdbe->tblwdbemvectoritem->loadRstBySQL("SELECT TblWdbeMVectoritem.* FROM TblWdbeMSignal, TblWdbeMVectoritem WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(top->ref) + " AND TblWdbeMSignal.sref = 'req"
							+ Cmdbussref + "' AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMSignal.refWdbeMVector AND TblWdbeMVectoritem.sref LIKE '" + cmdinv->sref + "To%' ORDER BY TblWdbeMVectoritem.vecNum ASC", false, vits);

				for (unsigned int i = 0; i < vits.nodes.size(); i++) {
					vit = vits.nodes[i];
					srefsCtrs.insert(StrMod::uncap(vit->sref.substr(cmdinv->sref.length()+2)));
				};

				delete cmdinv;
			};
			delete cmdbus;
		};
		delete top;
	};

	// --- sigs.reqsIcsTocA0s
	outfile << "-- IP sigs.reqsIcsTocA0s --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\tsignal req" << Cmdbussref << "To" << StrMod::cap(*it) << "_sig: std_logic := '0';" << endl;
		outfile << "\tsignal ixTocBuf" << StrMod::cap(*it) << ": natural range 0 to sizeTocBuf-1 := 0;" << endl;
		outfile << "\tsignal a0Buf" << StrMod::cap(*it) << ": natural range 0 to sizeBuf-1 := 0;" << endl;
		outfile << endl;
	};
	outfile << "-- IP sigs.reqsIcsTocA0s --- IEND" << endl;

	// --- impl.buf.a0Buf
	outfile << "-- IP impl.buf.a0Buf --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		if (it == srefsCtrs.begin()) outfile << "\ta0Buf <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "a0Buf" << StrMod::cap(*it) << " when ixTocBuf=ixTocBuf" << StrMod::cap(*it) << endl;
	};
	if (!srefsCtrs.empty()) outfile << "\t\t\t\telse 0;" << endl;
	outfile << "-- IP impl.buf.a0Buf --- IEND" << endl;

	// --- impl.buf.wrToAny
	outfile << "-- IP impl.buf.wrToAny --- IBEGIN" << endl;
	outfile << "\twr" << Cmdbussref << "ToAny <= ";
	if (!srefsCtrs.empty()) {
		outfile << "'1' when (";

		first = true;
		for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
			if (first) first = false;
			else outfile << " or ";
			
			outfile << "wr" << Cmdbussref << "To" << StrMod::cap(*it) << "='1'";
		};

		outfile << ") else";
	};
	outfile << "'0';" << endl;
	outfile << "-- IP impl.buf.wrToAny --- IEND" << endl;

	// --- impl.buf.reqs
	outfile << "-- IP impl.buf.reqs --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\treq" << Cmdbussref << "To" << StrMod::cap(*it) << " <= req" << Cmdbussref << "To" << StrMod::cap(*it) << "_sig when req" << Cmdbussref << "='1' else '0';" << endl;
	};
	outfile << "-- IP impl.buf.reqs --- IEND" << endl;

	// --- impl.buf.idle
	outfile << "-- IP impl.buf.idle --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\t\t\t\t\t";
		if (it != srefsCtrs.begin()) outfile << "els";
		outfile << "if wr" << Cmdbussref << "To" << StrMod::cap(*it) << "='1' then" << endl;
		outfile << "\t\t\t\t\t\tixTocBuf <= ixTocBuf" << StrMod::cap(*it) << ";" << endl;
	};
	if (!srefsCtrs.empty()) outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.buf.idle --- IEND" << endl;

	// --- impl.buf.updReqA
	outfile << "-- IP impl.buf.updReqA --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\t\t\t\treq" << Cmdbussref << "To" << StrMod::cap(*it) << "_sig <= '0';" << endl;
	};
	outfile << "-- IP impl.buf.updReqA --- IEND" << endl;

	// --- impl.buf.updReqE
	outfile << "-- IP impl.buf.updReqE --- IBEGIN" << endl;
	for (auto it = srefsCtrs.begin(); it != srefsCtrs.end(); it++) {
		outfile << "\t\t\t\t";
		if (it != srefsCtrs.begin()) outfile << "els";
		outfile << "if (drdBuf=tixV" << Prjshort << Untsref << "Controller" << StrMod::cap(*it) << " and req" << Cmdbussref << "To" << StrMod::cap(*it) << "_sig='0') then" << endl;
		outfile << "\t\t\t\t\treq" << Cmdbussref << "To" << StrMod::cap(*it) << "_sig <= '1';" << endl;
		outfile << "\t\t\t\t\tixTocBuf" << StrMod::cap(*it) << " <= j;" << endl;
		outfile << "\t\t\t\t\ta0Buf" << StrMod::cap(*it) << " <= k;" << endl;
	};
	if (!srefsCtrs.empty()) outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.buf.updReqE --- IEND" << endl;
};
// IP cust --- IEND



