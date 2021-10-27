/**
	* \file SqkWdbeGenfst.cpp
	* squawk generation for operation pack WdbeGenfst (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "SqkWdbeGenfst.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeGenfst
 ******************************************************************************/

string SqkWdbeGenfst::getSquawkCmdbus(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstCmdbus* dpchinv
		) {
	// example: "add command bus wiring for module 'icm2-cmdbus (cmdbus_v1_0 command bus controller)'"
	return(""); // IP getSquawkCmdbus --- LINE
};

string SqkWdbeGenfst::getSquawkCtrFwdctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstCtrFwdctr* dpchinv
		) {
	// example: "add command process and FSM debug ports for module 'icm2-acq (controller)'"
	return(""); // IP getSquawkCtrFwdctr --- LINE
};

string SqkWdbeGenfst::getSquawkEctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstEctr* dpchinv
		) {
	// example: "add vector constants and FSM debug ports for module 'icm2-acq (easy model controller)'"
	return(""); // IP getSquawkEctr --- LINE
};

string SqkWdbeGenfst::getSquawkEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstEhostif* dpchinv
		) {
	// example: "add command wiring and connect reset request for module 'icm2-hostif (easy model host interface)'"
	return(""); // IP getSquawkEhostif --- LINE
};

string SqkWdbeGenfst::getSquawkHostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstHostif* dpchinv
		) {
	// example: "connect reset request for module 'dcx3-hostif (host interface)'"
	return(""); // IP getSquawkHostif --- LINE
};

string SqkWdbeGenfst::getSquawkImbuf(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstImbuf* dpchinv
		) {
	// example: "add inter-module buffer wiring for module 'icm2-cmdinv-buf (dpbram_v1_0)'"
	return(""); // IP getSquawkImbuf --- LINE
};

string SqkWdbeGenfst::getSquawkPpl(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstPpl* dpchinv
		) {
	// example: "add FSM's and signals for pipeline 'corner'"
	return(""); // IP getSquawkPpl --- LINE
};

string SqkWdbeGenfst::getSquawkTop(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstTop* dpchinv
		) {
	// example: "add reset process for module 'icm2 (top)'"
	return(""); // IP getSquawkTop --- LINE
};
