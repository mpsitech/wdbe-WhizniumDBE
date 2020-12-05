/**
	* \file VecWdbeVBasereptype.h
	* vector VecWdbeVBasereptype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
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
};

#endif

