/**
	* \file WdbeMtpWrfpgaPmmu_v1_0.cpp
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

#include "WdbeMtpWrfpgaPmmu_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaPmmu_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaPmmu_v1_0::run(
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

		// xxxx/Pmmu_v1_0_...x...kB_...sl.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeMtpWrfpgaPmmu_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	unsigned int sizePg = 0;
	unsigned int pgsizeMem = 0;
	unsigned int slot = 0;

	usmallint w, w2;

	string s;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "sizePg", s)) sizePg = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "pgsizeMem", s)) pgsizeMem = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "slot", s)) slot = atoi(s.c_str());

	// --- sigs.tocbuf
	outfile << "-- IP sigs.tocbuf --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\tconstant a0TocbufS" << i << ": natural := ";
		if (i == 0) outfile << "0";
		else if (i == 1) outfile << "slot";
		else outfile << "(" << i << "*slot)";
		outfile << ";" << endl;

		outfile << "\tsignal maxlenTocbufS" << i << ": natural range 0 to slot := 0;" << endl;
		outfile << "\tsignal lenTocbufS" << i << ": natural range 0 to slot := 0;" << endl;
		outfile << "\tsignal ix0FullTocbufS" << i << ": natural range 0 to slot-1 := 0;" << endl;
		outfile << "\tsignal lenFullTocbufS" << i << ": natural range 0 to slot := 0;" << endl;
		outfile << endl;
	};
	outfile << "-- IP sigs.tocbuf --- IEND" << endl;

	// --- impl.cmd.prepRetAlloc
	outfile << "-- IP impl.cmd.prepRetAlloc --- IBEGIN" << endl;
	outfile << "\t\t\t\tcmdbuf(ixCmdbufRetAllocTixVSlot) <= tixVSlotCmd;" << endl;
	outfile << "-- IP impl.cmd.prepRetAlloc --- IEND" << endl;

	// --- impl.inbuf0.maxlenInbuf0
	outfile << "-- IP impl.inbuf0.maxlenInbuf0 --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tmaxlenInbuf0_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "maxlenTocbufS" << i << " when tixVSlotInbuf0=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << "-- IP impl.inbuf0.maxlenInbuf0 --- IEND" << endl;

	// --- impl.op.sigsTocbuf
	outfile << "-- IP impl.op.sigsTocbuf --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\ta0Tocbuf <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "a0TocbufS" << i << " when tixVSlot=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tlenTocbuf_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "lenTocbufS" << i << " when tixVSlot=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tmaxlenTocbuf_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "maxlenTocbufS" << i << " when tixVSlot=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tix0FullTocbuf_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "ix0FullTocbufS" << i << " when tixVSlot=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tlenFullTocbuf_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "lenFullTocbufS" << i << " when tixVSlot=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << "-- IP impl.op.sigsTocbuf --- IEND" << endl;

	// --- impl.op.asyncrst
	outfile << "-- IP impl.op.asyncrst --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) outfile << "\t\t\tmaxlenTocbufS" << i << " <= 0;" << endl;
	outfile << "-- IP impl.op.asyncrst --- IEND" << endl;

	// --- impl.op.init
	outfile << "-- IP impl.op.init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) outfile << "\t\t\t\tmaxlenTocbufS" << i << " <= 0;" << endl;
	outfile << "-- IP impl.op.init --- IEND" << endl;

	// --- impl.op.allocA
	outfile << "-- IP impl.op.allocA --- IBEGIN" << endl;
	outfile << "\t\t\tif ((cmdbuf(ixCmdbufInvAllocDynNotStat)=fls8 and cmdbuf(ixCmdbufInvAllocReqPglen)=x\"00\")" << endl;
	outfile << "\t\t\t\t\t\t\tor (";
	
	for (unsigned int i = 0; i < slot;i++) {
		if ((i != 0) && ((i%5)==0)) outfile << endl << "\t\t\t\t\t\t\t";
		if (i != 0) outfile << " and ";

		outfile << "maxlenTocbufS" << i << "/=0";
	};

	outfile << ")) then" << endl;
	outfile << "\t\t\t\t\ttixVSlotCmd <= tixVSlotVoid;" << endl;
	outfile << "\t\t\t\t\tstateOp <= stateOpAllocI;" << endl;
	outfile << endl;

	outfile << "\t\t\t\telse" << endl;

	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if maxlenTocbufS" << i << "=0 then" << endl;
		outfile << "\t\t\t\t\t\ttixVSlot <= tixVSlotS" << i << ";" << endl;
	};
	
	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\tstateOp <= stateOpAllocB;" << endl;
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.allocA --- IEND" << endl;

	// --- impl.op.allocC
	outfile << "-- IP impl.op.allocC --- IBEGIN" << endl;
	w = Wdbe::valToWidth(pgsizeMem-1);

	if (w < 9) outfile << "\t\t\t\t\t\tdwrTocbuf <= " << valToSlv("0", 9-w) << " & std_logic_vector(to_unsigned(j, " << w << "));" << endl;
	else outfile << "\t\t\t\t\t\tdwrTocbuf <= std_logic_vector(to_unsigned(j, 9));" << endl;
	outfile << "-- IP impl.op.allocC --- IEND" << endl;

	// --- impl.op.allocH
	outfile << "-- IP impl.op.allocH --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if tixVSlot=tixVSlotS" << i << " then" << endl;
		outfile << "\t\t\t\t\tmaxlenTocbufS" << i << " <= maxlenTocbuf;" << endl;
		outfile << "\t\t\t\t\tlenTocbufS" << i << " <= lenTocbuf;" << endl;
		outfile << "\t\t\t\t\tix0FullTocbufS" << i << " <= 0;" << endl;
		outfile << "\t\t\t\t\tlenFullTocbufS" << i << " <= 0;" << endl;
	};
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.allocH --- IEND" << endl;

	// --- impl.op.freeE
	outfile << "-- IP impl.op.freeE --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if tixVSlot=tixVSlotS" << i << " then" << endl;
		outfile << "\t\t\t\t\tmaxlenTocbufS" << i << " <= 0;" << endl;
	};
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.freeE --- IEND" << endl;

	// --- impl.op.inconfB
	outfile << "-- IP impl.op.inconfB --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if tixVSlot=tixVSlotS" << i << " then" << endl;
		outfile << "\t\t\t\t\tlenFullTocbufS" << i << " <= lenFullTocbufS" << i << " + 1;" << endl;
	};
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.inconfB --- IEND" << endl;

	// --- impl.op.instepC
	outfile << "-- IP impl.op.instepC --- IBEGIN" << endl;
	w = Wdbe::valToWidth(pgsizeMem-1);

	if (w < 9) outfile << "\t\t\t\t\t\tdwrTocbuf <= " << valToSlv("0", 9-w) << " & std_logic_vector(to_unsigned(j, " << w << "));" << endl;
	else outfile << "\t\t\t\t\t\tdwrTocbuf <= std_logic_vector(to_unsigned(j, 9));" << endl;
	outfile << "-- IP impl.op.instepC --- IEND" << endl;

	// --- impl.op.instepD
	outfile << "-- IP impl.op.instepD --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if tixVSlot=tixVSlotS" << i << " then" << endl;
		outfile << "\t\t\t\t\tlenTocbufS" << i << " <= lenTocbuf;" << endl;
	};
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.instepD --- IEND" << endl;

	// --- impl.op.outfreeB
	outfile << "-- IP impl.op.outfreeB --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << "els";
		outfile << "if tixVSlot=tixVSlotS" << i << " then" << endl;
		outfile << "\t\t\t\t\t\tix0FullTocbufS" << i << " <= ix0FullTocbufS" << i << " + 1;" << endl;
		outfile << "\t\t\t\t\t\tlenFullTocbufS" << i << " <= lenFullTocbufS" << i << " - 1;" << endl;
	};
	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.op.outfreeB --- IEND" << endl;

	// --- impl.outbuf0.maxlenOutbuf0
	outfile << "-- IP impl.outbuf0.maxlenOutbuf0 --- IBEGIN" << endl;
	for (unsigned int i = 0; i < slot;i++) {
		if (i == 0) outfile << "\tmaxlenOutbuf0_rd <= ";
		else outfile << "\t\t\t\telse ";
		
		outfile << "maxlenTocbufS" << i << " when tixVSlotOutbuf0=tixVSlotS" << i;

		if (i == (slot-1)) outfile << ";";
		outfile << endl;
	};
	outfile << "-- IP impl.outbuf0.maxlenOutbuf0 --- IEND" << endl;

	// --- impl.inbuf0B.start
	outfile << "-- IP impl.inbuf0B.start --- IBEGIN" << endl;
	w = Wdbe::valToWidth(pgsizeMem);
	w2 = Wdbe::valToWidth(1024*sizePg-1);

	outfile << "\t\t\t\tx := std_logic_vector(to_unsigned(maxlenInbuf0_rd, " << w << ")) & " << valToSlv("0", w2) << ";" << endl;
	outfile << "-- IP impl.inbuf0B.start --- IEND" << endl;

	// --- impl.outbuf0B.start
	outfile << "-- IP impl.outbuf0B.start --- IBEGIN" << endl;
	w = Wdbe::valToWidth(pgsizeMem);
	w2 = Wdbe::valToWidth(1024*sizePg-1);

	outfile << "\t\t\t\tx := std_logic_vector(to_unsigned(maxlenOutbuf0_rd, " << w << ")) & " << valToSlv("0", w2) << ";" << endl;
	outfile << "-- IP impl.outbuf0B.start --- IEND" << endl;
};
// IP cust --- IEND
