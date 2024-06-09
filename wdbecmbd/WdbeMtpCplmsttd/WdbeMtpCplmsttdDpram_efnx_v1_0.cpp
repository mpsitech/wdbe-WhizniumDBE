/**
	* \file WdbeMtpCplmsttdDpram_efnx_v1_0.cpp
	* Wdbe operation processor - infer EFX_DPRAM10  primitives and add mux logic (implementation)
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

#include "WdbeMtpCplmsttdDpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdDpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdDpram_efnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	WdbeMModule* submdl = NULL;

	ubigint refPrcMux;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	unsigned int size;
	unsigned int NRam;
	unsigned int wA, wB, wMax;

	unsigned int wAA, wAA_int;
	unsigned int wAB, wAB_int;

	unsigned int i, j, k, l;

	string Onval, Sig;

	string s;

	size = 0;
	wA = 0;
	wB = 0;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		// write enable default according to inter-module buffer direction
		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);
		if (!mgmtToNotFrom) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", "1");
		else Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", "1");

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", s)) size = atoi(s.c_str());
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", s)) wA = atoi(s.c_str());
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wB", s)) wB = atoi(s.c_str());

		if ((size > 0) && ((wA == 8) || (wA == 16) || (wA == 32) || (wA == 64)) && ((wB == 8) || (wB == 16) || (wB == 32) || (wB == 64))) {
			wMax = wA;
			if (wB > wA) wMax = wB;

			// align number of primitives to size increment
			if ((size % (wMax/8)) != 0) NRam = ((size / (wMax/8)) + 1) * (wMax/8);
			else NRam = size;

			// address port widths in line with specified size
			wAA_int = ceil(log2(1024 * NRam / (wA/8)));
			wAA = ceil(log2(1024 * size / (wA/8)));

			wAB_int = ceil(log2(1024 * NRam / (wB/8)));
			wAB = ceil(log2(1024 * size / (wB/8)));

			// adapt port widths
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aA", wAA);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdA", wA);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrA", wA);

			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aB", wAB);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdB", wB);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrB", wB);

			// - multiplexer processes and signals
			mdlNum = 1;

			refPrcMux = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "muxA", "clkA", "resetA", false, "", false, "A-side multiplexing");

			if (wAA_int > wAA) {
				Onval = "\"";
				for (unsigned int i = wAA; i < wAA_int; i++) Onval += "0";
				Onval += "\" & aA";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "aA_sig", false, "slvdn", wAA_int, "", "*", Onval, "", false, 0, "");
			};
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enAm1", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "aAm1", false, "slvdn", wAA_int, "", "", "", "0", false, 0, "");

			// enA_i*[m1]
			for (unsigned i = 0; i < NRam/(wA/8); i++) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();

				Sig = ""; if (wAA_int > wAA) Sig = "_sig";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enA_i" + to_string(i), false, "sl", 1, "", getComb(NRam, wA, i, "A", "", Sig), "1", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enA_i" + to_string(i) + "m1", false, "sl", 1, "", getComb(NRam, wA, i, "A", "m1", ""), "1", "0", false, 0, "");
			};

			refPrcMux = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "muxB", "clkB", "resetB", false, "", false, "B-side multiplexing");

			if (wAB_int > wAB) {
				Onval = "\"";
				for (unsigned int i = wAB; i < wAB_int; i++) Onval += "0";
				Onval += "\" & aB";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "aB_sig", false, "slvdn", wAB_int, "", "*", Onval, "", false, 0, "");
			};
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enBm1", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "aBm1", false, "slvdn", wAB_int, "", "", "", "0", false, 0, "");

			// enB_k*[m1]
			for (unsigned k = 0; k < NRam/(wB/8); k++) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();

				Sig = ""; if (wAB_int > wAB) Sig = "_sig";
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enB_k" + to_string(k), false, "sl", 1, "", getComb(NRam, wB, k, "B", "", Sig), "1", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcMux, 0, "enB_k" + to_string(k) + "m1", false, "sl", 1, "", getComb(NRam, wB, k, "B", "m1", ""), "1", "0", false, 0, "");
			};
			// -

			// drdA_i*
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned i = 0; i < NRam/(wA/8); i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drdA_i" + to_string(i), false, "slvdn", wA, "", "", "", "", false, 0, "");

			// drdB_k*
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned k = 0; k < NRam/(wB/8); k++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drdB_k" + to_string(k), false, "slvdn", wB, "", "", "", "", false, 0, "");

			// primitives and drdA_i*j* / drdB_j*l*
			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ram_i0j0k0l0'", &submdl)) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + " + to_string(NRam - 1) + " WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(submdl->hkNum));

				for (unsigned int n = 0; n < NRam; n++) {
					i = n / (wA/8);
					j = n % (wA/8);

					k = n / (wB/8);
					l = n % (wB/8);

					if (n != 0) {
						submdl->ref = 0;
						submdl->hkNum = mdl->hkNum + n + 1;
						submdl->sref = "ram_i" + to_string(i) + "j" + to_string(j) + "k" + to_string(k) + "l" + to_string(l);

						dbswdbe->tblwdbemmodule->insertRec(submdl);
					};

					refC = dbswdbe->tblwdbecsignal->getNewRef();
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, submdl->ref, 0, "drdA_i" + to_string(i) + "j" + to_string(j), false, "slvdn", 8, "", "", "", "", false, 0, "");
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, submdl->ref, 0, "drdB_k" + to_string(k) + "l" + to_string(l), false, "slvdn", 8, "", "", "", "", false, 0, "");
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
string WdbeMtpCplmsttdDpram_efnx_v1_0::getComb(
			const unsigned int NRam
			, const unsigned int w
			, const unsigned int ik
			, const string& AB
			, const string& Postfix
			, const string& Sig
		) {
	// ex. enA_i3 <= '1' when enA='1' and aA(12 downto 10)="011" else '0'; for 8192x8
	// ex. enA_i3 <= '1' when enA='1' and aA(10 downto 8)="011" else '0'; for 2048x32

	string Comb;

	unsigned int log2w, nmax;

	log2w = log2(w/8);

	nmax = ceil(log2(NRam));
	if (lround(pow(2, NRam)) == nmax) nmax--;
	nmax -= log2w;

	Comb = "we" + AB + "='1' and en" + AB + Postfix + "='1'";

	if (nmax > 0) {
		Comb += " and a" + AB + Postfix + Sig + "(" + to_string(10 + nmax-1) + " downto 10)=\""; // 10 for 2^10 = 1024 bytes per RAM

		for (unsigned int n = nmax; n > 0; n--) {
			if (ik & (0x00000001 << (n-1)) ) Comb += "1";
			else Comb += "0";
		};

		Comb += "\"";
	};

	return Comb;
};
// IP cust --- IEND
