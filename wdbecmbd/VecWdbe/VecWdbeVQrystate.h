/**
	* \file VecWdbeVQrystate.h
	* vector VecWdbeVQrystate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef VECWDBEVQRYSTATE_H
#define VECWDBEVQRYSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVQrystate
	*/
namespace VecWdbeVQrystate {
	const Sbecore::uint MNR = 1;
	const Sbecore::uint OOD = 2;
	const Sbecore::uint SLM = 3;
	const Sbecore::uint UTD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

