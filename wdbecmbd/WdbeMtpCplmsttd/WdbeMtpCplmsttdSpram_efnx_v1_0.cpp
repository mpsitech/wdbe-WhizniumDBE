/**
	* \file WdbeMtpCplmsttdSpram_efnx_v1_0.cpp
	* Wdbe operation processor - infer EFX_RAM10 primitives and add mux logic (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdSpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdSpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdSpram_efnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// stripped down copy from WdbeMtpCplmsttdDpram_efnx_v1_0

	ubigint refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	WdbeMModule* submdl = NULL;

	ubigint refPrcMux;

	unsigned int size;
	unsigned int NRam;
	unsigned int w;

	unsigned int wA, wA_int;

	unsigned int i, j;

	string Onval, Sig;

	string s;

	size = 0;
	w = 0;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", s)) size = atoi(s.c_str());
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());

		if ((size > 0) && ((w == 8) || (w == 16) || (w == 32) || (w == 64))) {
			// align number of primitives to size increment
			if ((size % (w/8)) != 0) NRam = ((size / (w/8)) + 1) * (w/8);
			else NRam = size;

			// address port widths in line with specified size
			wA_int = ceil(log2(1024 * NRam / (w/8)));
			wA = ceil(log2(1024 * size / (w/8)));

			// adapt port widths
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", wA);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drd", w);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwr", w);

			// - multiplexer process and signals
			mdlNum = 1;

			refPrcMux = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "mux", "clk", "reset", false, "", false, "multiplexing");

			if (wA_int > wA) {
				Onval = "\"";
				for (int i = wA; i < wA_int; i++) Onval += "0";
				Onval += "\" & a";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "a_sig", false, "slvdn", wA_int, "", "*", Onval, "", 0, "");
			};
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enm1", false, "sl", 1, "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "am1", false, "slvdn", wA_int, "", "", "", "0", 0, "");

			// {en/RE/WE}_i*[m1]
			for (i = 0; i < NRam/(w/8); i++) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();

				Sig = ""; if (wA_int > wA) Sig = "_sig";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "en_i" + to_string(i), false, "sl", 1, "", getComb(NRam, w, i, "", Sig), "1", "0", 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "RE_i" + to_string(i), false, "sl", 1, "", "en_i" + to_string(i) + " and !we", "1", "0", 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "WE_i" + to_string(i), false, "slvdn", 2, "", "en_i" + to_string(i) + " and we", "11", "00", 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "en_i" + to_string(i) + "m1", false, "sl", 1, "", getComb(NRam, w, i, "m1", ""), "1", "0", 0, "");
			};
			// -

			// drd_i*
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (i = 0; i < NRam/(w/8); i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drd_i" + to_string(i), false, "slvdn", w, "", "", "", "", 0, "");

			// primitives and drd_i*j*
			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ram_i0j0'", &submdl)) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + " + to_string(NRam - 1) + " WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(submdl->hkNum));

				for (unsigned int n = 0; n < NRam; n++) {
					i = n / (w/8);
					j = n % (w/8);

					if (n != 0) {
						submdl->ref = 0;
						submdl->hkNum = mdl->hkNum + n + 1;
						submdl->sref = "ram_i" + to_string(i) + "j" + to_string(j);

						dbswdbe->tblwdbemmodule->insertRec(submdl);
					};

					refC = dbswdbe->tblwdbecsignal->getNewRef();
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, submdl->ref, 0, "drd_i" + to_string(i) + "j" + to_string(j), false, "slvdn", 8, "", "", "", "", 0, "");
				};

				delete submdl;
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
string WdbeMtpCplmsttdSpram_efnx_v1_0::getComb(
			const unsigned int NRam
			, const unsigned int w
			, const unsigned int i
			, const string& Postfix
			, const string& Sig
		) {
	// stripped down copy from WdbeMtpCplmsttdDpram_efnx_v1_0

	string Comb;

	unsigned int log2w, nmax;

	log2w = log2(w/8);

	nmax = ceil(log2(NRam));
	if (lround(pow(2, NRam)) == nmax) nmax--;
	nmax -= log2w;

	Comb = "en" + Postfix + "='1'";

	if (nmax > 0) {
		Comb = "(" + Comb + " and a" + Postfix + Sig + "(" + to_string(10 + nmax-1) + " downto 10)=\""; // 10 for 2^10 = 1024 bytes per RAM

		for (unsigned int n = nmax; n > 0; n--) {
			if (i & (0x00000001 << (n-1)) ) Comb += "1";
			else Comb += "0";
		};

		Comb += "\")";
	};

	return Comb;
};
// IP cust --- IEND
