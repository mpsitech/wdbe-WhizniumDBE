/**
	* \file SqkWdbeModbsc.cpp
	* squawk generation for operation pack WdbeModbsc (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeModbsc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeModbsc
 ******************************************************************************/

string SqkWdbeModbsc::getSquawkCtrtd(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscCtrtd* dpchinv
		) {
	// example: "add controller for module 'dcx3-pmmu (controller)'"
	return("add controller for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkCtrtd --- RLINE
};

string SqkWdbeModbsc::getSquawkFwdctrtd(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscFwdctrtd* dpchinv
		) {
	// example: "add read and write buffers and commands for module 'dcx3-qcdif (spifwd_v1_0 forwarding controller)'"
	return("add read and write buffers for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkFwdctrtd --- RLINE
};

string SqkWdbeModbsc::getSquawkImbuftd(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscImbuftd* dpchinv
		) {
	// example: "add parameters for module 'icm2-acq-buf (dpbram_v1_0)'"
	return("add parameters for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkImbuftd --- RLINE
};

string SqkWdbeModbsc::getSquawkSys(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscSys* dpchinv
		) {
	// example: "add standard vectors for version 'ICARUSDetectorHardwareControl 0.1.0'"
	return("add standard vectors for version '" + StubWdbe::getStubVerStd(dbswdbe, dpchinv->refWdbeMVersion) + "'"); // IP getSquawkSys --- RLINE
};

string SqkWdbeModbsc::getSquawkTplcpy(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscTplcpy* dpchinv
		) {
	// example: "copy parameters, subs, generics and ports from template for module 'icm2-acq-buf (bpbram_v1_0)'"
	return("copy parameters, subs, generics and ports from template for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawkTplcpy --- RLINE
};

string SqkWdbeModbsc::getSquawkUnt(
			DbsWdbe* dbswdbe
			, DpchInvWdbeModbscUnt* dpchinv
		) {
	// example: "add standard vectors for unit 'icacam2'"
	return("add standard vectors for unit '" + StubWdbe::getStubUntStd(dbswdbe, dpchinv->refWdbeMUnit) + "'"); // IP getSquawkUnt --- RLINE
};



