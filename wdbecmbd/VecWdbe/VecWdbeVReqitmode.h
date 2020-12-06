/**
	* \file VecWdbeVReqitmode.h
	* vector VecWdbeVReqitmode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVREQITMODE_H
#define VECWDBEVREQITMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVReqitmode
	*/
namespace VecWdbeVReqitmode {
	const Sbecore::uint IDLE = 1;
	const Sbecore::uint NOTIFY = 2;
	const Sbecore::uint POLL = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
