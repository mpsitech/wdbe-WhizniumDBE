/**
	* \file VecWdbeVExpstate.h
	* vector VecWdbeVExpstate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

