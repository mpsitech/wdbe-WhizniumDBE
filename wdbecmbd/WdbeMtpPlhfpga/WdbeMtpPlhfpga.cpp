/**
	* \file WdbeMtpPlhfpga.cpp
	* Wdbe operation pack global code (implementation)
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

#include "WdbeMtpPlhfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpga
 ******************************************************************************/

// IP cust --- IBEGIN
unsigned int WdbeMtpPlhfpga::extendToWD(
			const unsigned int size
			, const unsigned int wD
			, unsigned int& resid
		) {
	resid = size % (wD/8);

	if (resid == 0) return size;
	else return(size-resid + wD/8);
};
// IP cust --- IEND
