/**
	* \file VecWdbeVBasereptype.h
	* vector VecWdbeVBasereptype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVBASEREPTYPE_H
#define VECWDBEVBASEREPTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVBasereptype
	*/
namespace VecWdbeVBasereptype {
	const Sbecore::uint VOID = 1;
	const Sbecore::uint PRJGIT = 2;
	const Sbecore::uint CUSTGIT = 3;
	const Sbecore::uint ULD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
};

#endif
