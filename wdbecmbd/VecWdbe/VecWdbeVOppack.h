/**
	* \file VecWdbeVOppack.h
	* vector VecWdbeVOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVOPPACK_H
#define VECWDBEVOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVOppack
	*/
namespace VecWdbeVOppack {
	const Sbecore::uint WDBECPLMST = 1;
	const Sbecore::uint WDBEGEN = 2;
	const Sbecore::uint WDBEGENFST = 3;
	const Sbecore::uint WDBEMTPCPLMSTBU = 4;
	const Sbecore::uint WDBEMTPCPLMSTTD = 5;
	const Sbecore::uint WDBEMTPGENFST = 6;
	const Sbecore::uint WDBEMTPPLHFPGA = 7;
	const Sbecore::uint WDBEMTPPLHMCU = 8;
	const Sbecore::uint WDBEMTPWRFPGA = 9;
	const Sbecore::uint WDBEMTPWRMCU = 10;
	const Sbecore::uint WDBEPLHFPGA = 11;
	const Sbecore::uint WDBEPLHMCU = 12;
	const Sbecore::uint WDBEPRCFILE = 13;
	const Sbecore::uint WDBEPRCTREE = 14;
	const Sbecore::uint WDBEWRDEV = 15;
	const Sbecore::uint WDBEWRFPGA = 16;
	const Sbecore::uint WDBEWRMCU = 17;
	const Sbecore::uint WDBEWRTERM = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Feed& feed);
	void fillFeed(Sbecore::Feed& feed);
};

#endif
