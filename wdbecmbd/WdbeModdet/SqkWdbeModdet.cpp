/**
	* \file SqkWdbeModdet.cpp
	* squawk generation for operation pack WdbeModdet (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "SqkWdbeModdet.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeModdet
 ******************************************************************************/

string SqkWdbeModdet::getSquawkCmdbus(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetCmdbus* dpchinv
		) {
	// example: "add command bus wiring for module 'icm2-cmdbus (cmdbus_v1_0 command bus controller)'"
	return("add command bus wiring for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkCmdbus --- RLINE
};

string SqkWdbeModdet::getSquawkCtrFwdctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetCtrFwdctr* dpchinv
		) {
	// example: "add command process and FSM debug ports for module 'icm2-acq (controller)'"
	return(""); // IP getSquawkCtrFwdctr --- LINE
};

string SqkWdbeModdet::getSquawkEctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetEctr* dpchinv
		) {
	// example: "add vector constants and FSM debug ports for module 'icm2-acq (easy model controller)'"
	return(""); // IP getSquawkEctr --- LINE
};

string SqkWdbeModdet::getSquawkEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetEhostif* dpchinv
		) {
	// example: "add command wiring for module 'icm2-hostif (easy model host interface)'"
	return(""); // IP getSquawkEhostif --- LINE
};

string SqkWdbeModdet::getSquawkImbuf(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetImbuf* dpchinv
		) {
	// example: "add inter-module buffer wiring for module 'icm2-cmdinv-buf (dpbram_v1_0)'"
	return("add inter-module buffer wiring for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkImbuf --- RLINE
};

string SqkWdbeModdet::getSquawkUnt(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetUnt* dpchinv
		) {
	// example: "fill standard vectors for unit 'icacam2'"
	return("fill standard vectors for unit '" + StubWdbe::getStubUntStd(dbswdbe, dpchinv->refWdbeMUnit) + "'"); // IP getSquawkUnt --- RLINE
};

string SqkWdbeModdet::getSquawkWiring(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModdetWiring* dpchinv
		) {
	// example: "add hierarchical wiring for module 'icm2 (top_v1_0 top module)'"
	return("add hierarchical wiring for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkWiring --- RLINE
};


