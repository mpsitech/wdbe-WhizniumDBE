/**
	* \file VecWdbeVIop.h
	* vector VecWdbeVIop (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef VECWDBEVIOP_H
#define VECWDBEVIOP_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVIop
	*/
namespace VecWdbeVIop {
	const Sbecore::uint INS = 1;
	const Sbecore::uint RETR = 2;
	const Sbecore::uint RETRINS = 3;
	const Sbecore::uint RETRUPD = 4;
	const Sbecore::uint RETRUPDINS = 5;
	const Sbecore::uint RMV = 6;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

