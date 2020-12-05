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
	const Sbecore::uint WDBEMODBSC = 1;
	const Sbecore::uint WDBEMODDET = 2;
	const Sbecore::uint WDBEMTPMODBSCBU = 3;
	const Sbecore::uint WDBEMTPMODBSCTD = 4;
	const Sbecore::uint WDBEMTPMODDET = 5;
	const Sbecore::uint WDBEMTPPLHFPGA = 6;
	const Sbecore::uint WDBEMTPPLHMCU = 7;
	const Sbecore::uint WDBEMTPWRFPGA = 8;
	const Sbecore::uint WDBEMTPWRMCU = 9;
	const Sbecore::uint WDBEPLHFPGA = 10;
	const Sbecore::uint WDBEPLHMCU = 11;
	const Sbecore::uint WDBEPRCFILE = 12;
	const Sbecore::uint WDBEPRCTREE = 13;
	const Sbecore::uint WDBEWRDEV = 14;
	const Sbecore::uint WDBEWRFPGA = 15;
	const Sbecore::uint WDBEWRMCU = 16;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Xmlio::Feed& feed);
	void fillFeed(Sbecore::Xmlio::Feed& feed);
};

#endif



