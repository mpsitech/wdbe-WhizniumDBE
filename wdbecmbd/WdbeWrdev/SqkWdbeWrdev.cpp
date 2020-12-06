/**
	* \file SqkWdbeWrdev.cpp
	* squawk generation for operation pack WdbeWrdev (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeWrdev.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeWrdev
 ******************************************************************************/

string SqkWdbeWrdev::getSquawkBase(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevBase* dpchinv
		) {
	// example: "write device access library C++ code basics for version 'ICARUSDetectorHardware 0.1'"
	return("write device access library C++ code basics for version '" + StubWdbe::getStubVerStd(dbswdbe, dpchinv->refWdbeMVersion) + "'"); // IP getSquawkBase --- RLINE
};

string SqkWdbeWrdev::getSquawkCtr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevCtr* dpchinv
		) {
	// example: "write C++ code for controller 'acq'"
	return("write C++ code for controller '" + StubWdbe::getStubCtrStd(dbswdbe, dpchinv->refWdbeMController) + "'"); // IP getSquawkCtr --- RLINE
};

string SqkWdbeWrdev::getSquawkDeploy(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevDeploy* dpchinv
		) {
	// example: "write device access library deployment scripts for release 'Idhw_genio'"
	return("write device access library deployment scripts for release '" + StubWdbe::getStubRlsStd(dbswdbe, dpchinv->refWdbeMRelease) + "'"); // IP getSquawkDeploy --- RLINE
};

string SqkWdbeWrdev::getSquawkSys(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevSys* dpchinv
		) {
	// example: "write C++ code for system 'Basys2fwd'"
	return("write C++ code for system '" + StubWdbe::getStubSysStd(dbswdbe, dpchinv->refWdbeMSystem) + "'"); // IP getSquawkSys --- RLINE
};

string SqkWdbeWrdev::getSquawkUnt(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevUnt* dpchinv
		) {
	// example: "write C++ code for unit 'Axis2'"
	return("write C++ code for unit '" + StubWdbe::getStubUntStd(dbswdbe, dpchinv->refWdbeMUnit) + "'"); // IP getSquawkUnt --- RLINE
};
