/**
	* \file VecWdbeVBasereptype.h
	* vector VecWdbeVBasereptype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

