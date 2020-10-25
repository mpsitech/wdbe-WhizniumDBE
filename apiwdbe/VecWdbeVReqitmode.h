/**
	* \file VecWdbeVReqitmode.h
	* vector VecWdbeVReqitmode (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

