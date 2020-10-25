/**
	* \file SqkWdbeWrmcu.cpp
	* squawk generation for operation pack WdbeWrmcu (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "SqkWdbeWrmcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeWrmcu
 ******************************************************************************/

string SqkWdbeWrmcu::getSquawkBase(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuBase* dpchinv
		) {
	// example: "write C code basics for unit 'icacam2'"
	return(""); // IP getSquawkBase --- LINE
};

string SqkWdbeWrmcu::getSquawkCtrFwdctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuCtrFwdctr* dpchinv
		) {
	// example: "write type-specific C code for module 'icm2-acq (controller)'"
	return(""); // IP getSquawkCtrFwdctr --- LINE
};

string SqkWdbeWrmcu::getSquawkDeploy(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuDeploy* dpchinv
		) {
	// example: "write MCU code deployment scripts for release 'Idhw_genio'"
	return(""); // IP getSquawkDeploy --- LINE
};

string SqkWdbeWrmcu::getSquawkEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuEhostif* dpchinv
		) {
	// example: "write template-specific C code for module 'zedb-ehostif (easy host interface)'"
	return(""); // IP getSquawkEhostif --- LINE
};

string SqkWdbeWrmcu::getSquawkMdlfine(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuMdlfine* dpchinv
		) {
	// example: "write in-detail C code for module 'icm2 (top_v1_0 top)'"
	return(""); // IP getSquawkMdlfine --- LINE
};

string SqkWdbeWrmcu::getSquawkMdlraw(
			DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuMdlraw* dpchinv
		) {
	// example: "write raw C code for module 'icm2 (top_v1_0 top)'"
	return(""); // IP getSquawkMdlraw --- LINE
};

