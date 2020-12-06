/**
	* \file VecWdbeVExpstate.h
	* vector VecWdbeVExpstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVEXPSTATE_H
#define VECWDBEVEXPSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVExpstate
	*/
namespace VecWdbeVExpstate {
	const Sbecore::uint DETD = 1;
	const Sbecore::uint MAXD = 2;
	const Sbecore::uint MIND = 3;
	const Sbecore::uint REGD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
