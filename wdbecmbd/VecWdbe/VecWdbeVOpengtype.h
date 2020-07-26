/**
	* \file VecWdbeVOpengtype.h
	* vector VecWdbeVOpengtype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWDBEVOPENGTYPE_H
#define VECWDBEVOPENGTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVOpengtype
	*/
namespace VecWdbeVOpengtype {
	const Sbecore::uint WDBEOPD1 = 1;
	const Sbecore::uint WDBEOPD2 = 2;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

