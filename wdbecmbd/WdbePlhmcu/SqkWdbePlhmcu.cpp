/**
	* \file SqkWdbePlhmcu.cpp
	* squawk generation for operation pack WdbePlhmcu (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "SqkWdbePlhmcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbePlhmcu
 ******************************************************************************/

string SqkWdbePlhmcu::getSquawkEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbePlhmcuEhostif* dpchinv
		) {
	// example: "fill type-specific placeholders for module 'icm2-hostif (uarthostif_Easy_v1_0_Mcu easy model host interface)'"
	return(""); // IP getSquawkEhostif --- LINE
};

