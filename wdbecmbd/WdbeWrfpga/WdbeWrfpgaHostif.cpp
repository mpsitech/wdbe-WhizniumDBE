/**
	* \file WdbeWrfpgaHostif.cpp
	* Wdbe operation processor - write template-specific VHDL code (implementation)
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

#include "WdbeWrfpgaHostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaHostif
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaHostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaHostif* dpchinv
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

		// xxxx/Hostif.vhd
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
void WdbeWrfpgaHostif::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	WdbeMUnit* unt = NULL;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;

	string sref, srefrootMgmt, srefrootCor;

	vector<string> srefsImb, srefsImbRd, srefsImbWr;
	vector<string> srefrootsImb, srefrootsImbRd, srefrootsImbWr;
	vector<int> PriosImb, PriosImbRd, PriosImbWr;
	vector<int> wAvllensImb;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	int Prio;

	unsigned int ix;

	bool first, found;

	// --- analyze buffer transfers
	if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
		dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT TblWdbeMImbuf.* FROM TblWdbeMImbuf, TblWdbeRMModuleMModule WHERE TblWdbeMImbuf.refWdbeMModule = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeRMModuleMModule.corRefWdbeMModule = "
					+ to_string(mdl->ref) + " ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMModule.sref ASC", false, imbs);

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (!Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, sref, srefrootMgmt, srefrootCor)) {
				srefsImbRd.push_back(sref);
				srefrootsImbRd.push_back(srefrootCor);
				PriosImbRd.push_back(imb->Prio);

			} else {
				srefsImbWr.push_back(sref);
				srefrootsImbWr.push_back(srefrootCor);
				PriosImbWr.push_back(imb->Prio);
			};

			srefsImb.push_back(sref);
			srefrootsImb.push_back(srefrootCor);
			PriosImb.push_back(imb->Prio);
			wAvllensImb.push_back(getImbwavllen(dbswdbe, mdl, srefrootCor));
		};

		dbswdbe->tblwdbemvectoritem->loadRstBySQL("SELECT TblWdbeMVectoritem.* FROM TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = "
					+ to_string(mdl->hkUref) + " AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref = 'VecW" + unt->Fullsref.substr(3) + "Buffer' ORDER BY TblWdbeMVectoritem.vecNum ASC", false, vits);

		delete unt;
	};

	if (!srefrootsImb.empty()) {
		// --- sigs.tkns
		outfile << "-- IP sigs.tkns --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefrootsImb.size(); i++)
					outfile << "\tsignal tkn" << srefrootsImb[i] << ": std_logic_vector(7 downto 0) := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ";" << endl;
		outfile << "-- IP sigs.tkns --- IEND" << endl;

		// --- impl.op.tknste
		outfile << "-- IP impl.op.tknste --- IBEGIN" << endl;
		ix = 1;
		for (unsigned int i = 0; i < 8; i++, ix *= 2) {
			outfile << "\ttknste(" << i << ") <= '0'";

			found = false;
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];

				if (vit->vecNum == ix) {
					for (unsigned int k = 0; k < srefsImb.size(); k++) {
						if (srefsImb[k] == vit->sref) {
							outfile << " when tkn" << srefrootsImb[k] << "=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[k]) << " else '1'";

							found = true;
							break;
						};
					};
				};

				if (found) break;
			};

			outfile << ";" << endl;
		};
		outfile << "-- IP impl.op.tknste --- IEND" << endl;

		// --- impl.op.avlbx
		outfile << "-- IP impl.op.avlbx --- IBEGIN" << endl;
		ix = 1;
		for (unsigned int i = 0; i < 8; i++, ix *= 2) {
			outfile << "\tavlbx(" << i << ") <=";

			found = false;
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];

				if (vit->vecNum == ix) {
					for (unsigned int k = 0; k < srefsImb.size(); k++) {
						if (srefsImb[k] == vit->sref) {
							if (wAvllensImb[k] > 0) outfile << " '1' when avllen" << srefrootsImb[k] << "/=" << valToSlv("0", wAvllensImb[k]) << " else";

							found = true;
							break;
						};
					};
				};

				if (found) break;
			};

			outfile << " '0';" << endl;
		};
		outfile << "-- IP impl.op.avlbx --- IEND" << endl;

		// --- impl.op.avllen
		outfile << "-- IP impl.op.avllen --- IBEGIN" << endl;
		outfile << "\tavllen <=";
		
		for (unsigned int i = 0; i < srefrootsImb.size(); i++) {
			if (i > 0) outfile << "\t\t\t\telse";
			
			if (wAvllensImb[i] < 32) outfile << " " << valToSlv("0", 32 - wAvllensImb[i]) << " &";
			
			outfile << " avllen" << srefrootsImb[i] << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << "))" << endl;
		};

		outfile << "\t\t\t\telse (others => '0');" << endl;
		outfile << "-- IP impl.op.avllen --- IEND" << endl;

		// --- impl.op.ackTxbuf
		outfile << "-- IP impl.op.ackTxbuf --- IBEGIN" << endl;
		outfile << "\tackTxbuf <=";
		
		for (unsigned int i = 0; i < srefrootsImbRd.size(); i++) {
			if (i > 0) outfile << "\t\t\t\telse";
				
			outfile << " ack" << srefrootsImbRd[i] << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbRd[i]) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbRd[i]) << "))" << endl;
		};

		outfile << "\t\t\t\telse '0';" << endl;
		outfile << "-- IP impl.op.ackTxbuf --- IEND" << endl;

		// --- impl.op.dTxbuf
		outfile << "-- IP impl.op.dTxbuf --- IBEGIN" << endl;
		outfile << "\tdTxbuf <=";
		
		for (unsigned int i = 0; i < srefrootsImbRd.size(); i++) {
			if (i > 0) outfile << "\t\t\t\telse";
				
			outfile << " d" << srefrootsImbRd[i] << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbRd[i]) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbRd[i]) << "))" << endl;
		};

		outfile << "\t\t\t\telse (others => '0');" << endl;
		outfile << "-- IP impl.op.dTxbuf --- IEND" << endl;

		// --- impl.op.ackRxbuf
		outfile << "-- IP impl.op.ackRxbuf --- IBEGIN" << endl;
		outfile << "\tackRxbuf <=";
		
		for (unsigned int i = 0; i < srefrootsImbWr.size(); i++) {
			if (i > 0) outfile << "\t\t\t\telse";
				
			outfile << " ack" << srefrootsImbWr[i] << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbWr[i]) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbWr[i]) << "))" << endl;
		};

		outfile << "\t\t\t\telse '0';" << endl;
		outfile << "-- IP impl.op.ackRxbuf --- IEND" << endl;

		// --- impl.op.bufs
		outfile << "-- IP impl.op.bufs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefrootsImbRd.size(); i++) {
			outfile << "\t-- " << srefsImbRd[i] << endl;
			outfile << "\treq" << srefrootsImbRd[i] << " <= reqTxbuf when tkn=tkn" << srefrootsImbRd[i] << " else '0';" << endl;
			outfile << "\tdne" << srefrootsImbRd[i] << " <= dneTxbuf when tkn=tkn" << srefrootsImbRd[i] << " else '0';" << endl;
			outfile << endl;

			outfile << "\tstrbD" << srefrootsImbRd[i] << " <= strbDTxbuf;" << endl;
			outfile << endl;
		};

		for (unsigned int i = 0; i < srefrootsImbWr.size(); i++) {
			outfile << "\t-- " << srefsImbWr[i] << endl;
			outfile << "\treq" << srefrootsImbWr[i] << " <= reqRxbuf when tkn=tkn" << srefrootsImbWr[i] << " else '0';" << endl;
			outfile << "\tdne" << srefrootsImbWr[i] << " <= dneRxbuf when tkn=tkn" << srefrootsImbWr[i] << " else '0';" << endl;
			outfile << endl;

			outfile << "\td" << srefrootsImbWr[i] << " <= dRxbuf;" << endl;
			outfile << "\tstrbD" << srefrootsImbWr[i] << " <= strbDRxbuf;" << endl;
			outfile << endl;
		};
		outfile << "-- IP impl.op.bufs --- IEND" << endl;

		// --- impl.op.vars
		outfile << "-- IP impl.op.vars --- IBEGIN" << endl;
		first = true;
		Prio = 0;

		for (unsigned int i = 0; i < srefrootsImb.size(); i++) {
			if (first || (PriosImb[i] != Prio)) {
				first = false;
				Prio = PriosImb[i];
				
				outfile << "\t\tvariable lastBxPr" << Prio << ": std_logic_vector(7 downto 0) := (others => '0');" << endl;
			};
		};
		outfile << "-- IP impl.op.vars --- IEND" << endl;

		// --- impl.op.asyncrst
		outfile << "-- IP impl.op.asyncrst --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefrootsImb.size(); i++)
					outfile << "\t\t\ttkn" << srefrootsImb[i] << " <= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ";" << endl;
		outfile << "-- IP impl.op.asyncrst --- IEND" << endl;

		// --- impl.op.xferTkn
		outfile << "-- IP impl.op.xferTkn --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		for (unsigned int i = 0; i < srefrootsImb.size(); i++) {
			if (i != 0) outfile << " or ";
			outfile << "auxbuf(ixAuxbufTkn)=tkn" << srefrootsImb[i];
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferTkn --- IEND" << endl;

		// --- impl.op.xferReqbx
		outfile << "-- IP impl.op.xferReqbx --- IBEGIN" << endl;
		for (unsigned int i = 0; i < srefrootsImb.size(); i++) {
			outfile << "\t\t\t\t\t\t";
			if (i != 0) outfile << "els";

			outfile << "if ";
			
			found = false;
			if ((i == 0) && ((i + 1) != srefrootsImb.size())) if (PriosImb[i + 1] == PriosImb[i]) found = true;
			if (i != 0) if (PriosImb[i - 1] == PriosImb[i]) found = true;

			if (found) outfile << "( ";

			outfile << "((y and tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ") /= (others => '0'))";

			if (found) {
				outfile << " and ( (lastBxPr" << PriosImb[i] << " /= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ") or ((y and (";

				for (unsigned int j = 0; j < srefsImb.size(); j++) {
					if (PriosImb[j] == PriosImb[i]) {
						if (j != 0) outfile << " or ";

						outfile << "tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[j]);
					};
				};

				outfile << ")) = tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ") ) )";
			};
			outfile << " then" << endl;

			outfile << "\t\t\t\t\t\t\tarbbx <= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImb[i]) << ";" << endl;
		};
		outfile << "-- IP impl.op.xferReqbx --- IEND" << endl;

		// --- impl.op.xferArblenTx
		outfile << "-- IP impl.op.xferArblenTx --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		for (unsigned int i = 0; i < srefrootsImbRd.size(); i++) {
			if (i != 0) outfile << " or ";
			outfile << "auxbuf(ixAuxbufTkn)=tkn" << srefrootsImbRd[i];
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferArblenTx --- IEND" << endl;

		// --- impl.op.xferArblenRx
		outfile << "-- IP impl.op.xferArblenRx --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		for (unsigned int i = 0; i < srefrootsImbWr.size(); i++) {
			if (i != 0) outfile << " or ";
			outfile << "auxbuf(ixAuxbufTkn)=tkn" << srefrootsImbWr[i];
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferArblenRx --- IEND" << endl;

		// --- impl.op.cnfRd
		outfile << "-- IP impl.op.cnfRd --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefrootsImbRd.size(); i++) {
			outfile << "\t\t\t\t\t";
			if (i != 0) outfile << "els";
			outfile << "if tkn=tkn" << srefrootsImbRd[i] << " then" << endl;

			outfile << "\t\t\t\t\t\tlastBxPr" << PriosImbRd[i] << " := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbRd[i]) << ";" << endl;
			outfile << "\t\t\t\t\t\ttkn" << srefrootsImbRd[i] << " <= not tkn" << srefrootsImbRd[i] << ";" << endl;
		};

		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl.op.cnfRd --- IEND" << endl;

		// --- impl.op.cnfWr
		outfile << "-- IP impl.op.cnfWr --- IBEGIN" << endl;

		for (unsigned int i = 0; i < srefrootsImbWr.size(); i++) {
			outfile << "\t\t\t\t\t";
			if (i != 0) outfile << "els";
			outfile << "if tkn=tkn" << srefrootsImbWr[i] << " then" << endl;

			outfile << "\t\t\t\t\t\tlastBxPr" << PriosImbWr[i] << " := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(srefsImbWr[i]) << ";" << endl;
			outfile << "\t\t\t\t\t\ttkn" << srefrootsImbWr[i] << " <= not tkn" << srefrootsImbWr[i] << ";" << endl;
		};

		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl.op.cnfWr --- IEND" << endl;
	};
};

usmallint WdbeWrfpgaHostif::getImbwavllen(
			DbsWdbe* dbswdbe
			, WdbeMModule* hostif
			, const string& Imbsigsref
		) {
	usmallint w = 0;

	WdbeMPort* prt = NULL;

	if (dbswdbe->tblwdbemport->loadRecBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(hostif->ref) + " AND sref = 'avllen" + Imbsigsref + "'", &prt)) {
		w = prt->Width;
		delete prt;
	};

	return w;
};
// IP cust --- IEND
