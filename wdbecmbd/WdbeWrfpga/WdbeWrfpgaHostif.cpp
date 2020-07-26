/**
	* \file WdbeWrfpgaHostif.cpp
	* Wdbe operation processor - write template-specific VHDL code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	// ex.: imb->sref = "qcdifToHostif", mdl->sref = "rdbuf", Imbshort = "FromQcdif", Imbsigsref = "RdbufFromQcdif"

	WdbeMUnit* unt = NULL;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;
	WdbeMImbuf* imb2 = NULL;

	set<ubigint> refsImbsRd, refsImbsWr;

	string Imbshort, Imbsigsref;

	usmallint wAvllen;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	utinyint Prio;

	unsigned int ix;

	bool first, found;

	if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
		dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT * FROM TblWdbeMImbuf WHERE corRefWdbeMModule = " + to_string(mdl->ref) + " ORDER BY Prio ASC, sref ASC", false, imbs);

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (imb->ixVDir == VecWdbeVMImbufDir::IN) refsImbsWr.insert(imb->ref);
			else if (imb->ixVDir == VecWdbeVMImbufDir::OUT) refsImbsRd.insert(imb->ref);
		};

		dbswdbe->tblwdbemvectoritem->loadRstBySQL("SELECT TblWdbeMVectoritem.* FROM TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = "
					+ to_string(mdl->hkUref) + " AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref = 'VecW" + unt->Fullsref.substr(3) + "Buffer' ORDER BY TblWdbeMVectoritem.vecNum ASC", false, vits);

		delete unt;
	};

	if (!refsImbsRd.empty() && !refsImbsWr.empty()) {
		// --- sigs.tkns
		outfile << "-- IP sigs.tkns --- IBEGIN" << endl;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) )
						outfile << "\tsignal tkn" << Imbshort << ": std_logic_vector(7 downto 0) := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
		};
		outfile << "-- IP sigs.tkns --- IEND" << endl;

		// --- impl.op.tknste
		outfile << "-- IP impl.op.tknste --- IBEGIN" << endl;
		ix = 1;
		for (unsigned int i = 0; i < 8;i++,ix*=2) {
			outfile << "\ttknste(" << i << ") <= '0'";

			found = false;
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];

				if (vit->vecNum == ix) {
					for (unsigned int k = 0; k < imbs.nodes.size(); k++) {
						imb = imbs.nodes[k];

						if (imb->sref == vit->sref) {
							Imbshort = Wdbe::getImbshort(imb);

							outfile << " when tkn" << Imbshort << "=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(vit->sref) << " else '1'";
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
		for (unsigned int i = 0; i < 8;i++,ix*=2) {
			outfile << "\tavlbx(" << i << ") <=";

			found = false;
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];

				if (vit->vecNum == ix) {
					for (unsigned int k = 0; k < imbs.nodes.size(); k++) {
						imb = imbs.nodes[k];

						if (imb->sref == vit->sref) {
							Imbsigsref = getImbsigsref(dbswdbe, imb);
							wAvllen = getImbwavllen(dbswdbe, mdl, Imbsigsref);

							if (wAvllen > 0) outfile << " '1' when avllen" << Imbsigsref << "/=" << valToSlv("0", wAvllen) << " else";

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
		
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbsigsref = getImbsigsref(dbswdbe, imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				if (first) first = false;
				else outfile << "\t\t\t\telse";
				
				wAvllen = getImbwavllen(dbswdbe, mdl, Imbsigsref);
				if (wAvllen < 32) outfile << " " << valToSlv("0", 32-wAvllen) << " &";
				
				outfile << " avllen" << Imbsigsref << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << "))" << endl;
			};
		};

		outfile << "\t\t\t\telse (others => '0');" << endl;
		outfile << "-- IP impl.op.avllen --- IEND" << endl;

		// --- impl.op.ackTxbuf
		outfile << "-- IP impl.op.ackTxbuf --- IBEGIN" << endl;
		outfile << "\tackTxbuf <=";
		
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbsigsref = getImbsigsref(dbswdbe, imb);

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				if (first) first = false;
				else outfile << "\t\t\t\telse";
				
				outfile << " ack" << Imbsigsref << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << "))" << endl;
			};
		};

		outfile << "\t\t\t\telse '0';" << endl;
		outfile << "-- IP impl.op.ackTxbuf --- IEND" << endl;

		// --- impl.op.dTxbuf
		outfile << "-- IP impl.op.dTxbuf --- IBEGIN" << endl;
		outfile << "\tdTxbuf <=";
		
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbsigsref = getImbsigsref(dbswdbe, imb);

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				if (first) first = false;
				else outfile << "\t\t\t\telse";
				
				outfile << " d" << Imbsigsref << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << "))" << endl;
			};
		};

		outfile << "\t\t\t\telse (others => '0');" << endl;
		outfile << "-- IP impl.op.dTxbuf --- IEND" << endl;

		// --- impl.op.ackRxbuf
		outfile << "-- IP impl.op.ackRxbuf --- IBEGIN" << endl;
		outfile << "\tackRxbuf <=";
		
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbsigsref = getImbsigsref(dbswdbe, imb);

			if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				if (first) first = false;
				else outfile << "\t\t\t\telse";
				
				outfile << " ack" << Imbsigsref << " when (tkn=tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << " or tkn=(not tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << "))" << endl;
			};
		};

		outfile << "\t\t\t\telse '0';" << endl;
		outfile << "-- IP impl.op.ackRxbuf --- IEND" << endl;

		// --- impl.op.bufs
		outfile << "-- IP impl.op.bufs --- IBEGIN" << endl;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);
			Imbsigsref = getImbsigsref(dbswdbe, imb);

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				outfile << "\t-- " << StrMod::uncap(Imbshort) << endl;
				outfile << "\treq" << Imbsigsref << " <= reqTxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
				outfile << "\tdne" << Imbsigsref << " <= dneTxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
				outfile << endl;

				outfile << "\tstrbD" << Imbsigsref << " <= strbDTxbuf;" << endl;
				outfile << endl;

			} else if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				outfile << "\t-- " << StrMod::uncap(Imbshort) << endl;
				outfile << "\treq" << Imbsigsref << " <= reqRxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
				outfile << "\tdne" << Imbsigsref << " <= dneRxbuf when tkn=tkn" << Imbshort << " else '0';" << endl;
				outfile << endl;

				outfile << "\td" << Imbsigsref << " <= dRxbuf;" << endl;
				outfile << "\tstrbD" << Imbsigsref << " <= strbDRxbuf;" << endl;
				outfile << endl;
			};
		};
		outfile << "-- IP impl.op.bufs --- IEND" << endl;

		// --- impl.op.vars
		outfile << "-- IP impl.op.vars --- IBEGIN" << endl;

		first = true;
		Prio = 0;

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				if (first || (imb->Prio != Prio)) {
					first = false;
					Prio = imb->Prio;
					
					outfile << "\t\tvariable lastBxPr" << ((int) Prio) << ": std_logic_vector(7 downto 0) := (others => '0');" << endl;
				};
			};
		};
		outfile << "-- IP impl.op.vars --- IEND" << endl;

		// --- impl.op.asyncrst
		outfile << "-- IP impl.op.asyncrst --- IBEGIN" << endl;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			Imbshort = Wdbe::getImbshort(imb);

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) )
						outfile << "\t\t\ttkn" << Imbshort << " <= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
		};
		outfile << "-- IP impl.op.asyncrst --- IEND" << endl;


		// --- impl.op.xferTkn
		outfile << "-- IP impl.op.xferTkn --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";

				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferTkn --- IEND" << endl;

		// --- impl.op.xferReqbx
		outfile << "-- IP impl.op.xferReqbx --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ( (refsImbsRd.find(imb->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb->ref) != refsImbsWr.end()) ) {
				outfile << "\t\t\t\t\t\t";
				if (!first) outfile << "els";

				outfile << "if ";
				
				found = false;
				if ((i == 0) && ((i+1) != imbs.nodes.size())) if (imbs.nodes[i+1]->Prio == imb->Prio) found = true;
				if (i != 0) if (imbs.nodes[i-1]->Prio == imb->Prio) found = true;

				if (found) outfile << "( ";

				outfile << "((y and tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ") /= (others => '0'))";

				if (found) {
					outfile << " and ( (lastBxPr" << ((int) imb->Prio) << " /= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ") or ((y and (";

					first = true;
					for (unsigned int j = 0; j < imbs.nodes.size(); j++) {
						imb2 = imbs.nodes[j];

						if ( ((refsImbsRd.find(imb2->ref) != refsImbsRd.end()) || (refsImbsWr.find(imb2->ref) != refsImbsWr.end())) && (imb2->Prio == imb->Prio) ) {
							if (first) first = false;
							else outfile << " or ";
							
							outfile << "tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb2->sref);
						};
					};

					outfile << ")) = tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ") ) )";
				};
				outfile << " then" << endl;

				outfile << "\t\t\t\t\t\t\tarbbx <= tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;

				first = false;
			};
		};
		outfile << "-- IP impl.op.xferReqbx --- IEND" << endl;

		// --- impl.op.xferArblenTx
		outfile << "-- IP impl.op.xferArblenTx --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";

				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferArblenTx --- IEND" << endl;

		// --- impl.op.xferArblenRx
		outfile << "-- IP impl.op.xferArblenRx --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\telsif (";

		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				if (first) first = false;
				else outfile << " or ";

				outfile << "auxbuf(ixAuxbufTkn)=tkn" << Imbshort;
			};
		};

		outfile << ") then" << endl;
		outfile << "-- IP impl.op.xferArblenRx --- IEND" << endl;

		// --- impl.op.cnfRd
		outfile << "-- IP impl.op.cnfRd --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsRd.find(imb->ref) != refsImbsRd.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				outfile << "\t\t\t\t\t";
				if (first) first = false;
				else outfile << "els";
				outfile << "if tkn=tkn" << Imbshort << " then" << endl;

				outfile << "\t\t\t\t\t\tlastBxPr" << ((int) imb->Prio) << " := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
				outfile << "\t\t\t\t\t\ttkn" << Imbshort << " <= not tkn" << Imbshort << ";" << endl;
			};
		};
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl.op.cnfRd --- IEND" << endl;

		// --- impl.op.cnfWr
		outfile << "-- IP impl.op.cnfWr --- IBEGIN" << endl;
		first = true;
		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if (refsImbsWr.find(imb->ref) != refsImbsWr.end()) {
				Imbshort = Wdbe::getImbshort(imb);

				outfile << "\t\t\t\t\t";
				if (first) first = false;
				else outfile << "els";
				outfile << "if tkn=tkn" << Imbshort << " then" << endl;

				outfile << "\t\t\t\t\t\tlastBxPr" << ((int) imb->Prio) << " := tixW" << Prjshort << Untsref << "Buffer" << StrMod::cap(imb->sref) << ";" << endl;
				outfile << "\t\t\t\t\t\ttkn" << Imbshort << " <= not tkn" << Imbshort << ";" << endl;
			};
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


