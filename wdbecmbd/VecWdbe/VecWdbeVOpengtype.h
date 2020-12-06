/**
	* \file VecWdbeVOpengtype.h
	* vector VecWdbeVOpengtype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
