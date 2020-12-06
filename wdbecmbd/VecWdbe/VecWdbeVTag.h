/**
	* \file VecWdbeVTag.h
	* vector VecWdbeVTag (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVTAG_H
#define VECWDBEVTAG_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVTag
	*/
namespace VecWdbeVTag {
	const Sbecore::uint ABOUT = 1;
	const Sbecore::uint ALWAYS = 2;
	const Sbecore::uint CANCEL = 3;
	const Sbecore::uint CLOSE = 4;
	const Sbecore::uint CLSESS = 5;
	const Sbecore::uint CLUST = 6;
	const Sbecore::uint CREATE = 7;
	const Sbecore::uint DETAIL = 8;
	const Sbecore::uint DONE = 9;
	const Sbecore::uint DOWNLOAD = 10;
	const Sbecore::uint EMPLONG = 11;
	const Sbecore::uint EMPSHORT = 12;
	const Sbecore::uint ERROR = 13;
	const Sbecore::uint FILENAME = 14;
	const Sbecore::uint FLS = 15;
	const Sbecore::uint FOR = 16;
	const Sbecore::uint GENERAL = 17;
	const Sbecore::uint GOTO = 18;
	const Sbecore::uint GRP = 19;
	const Sbecore::uint HELP = 20;
	const Sbecore::uint IMPERR = 21;
	const Sbecore::uint IMPORT = 22;
	const Sbecore::uint LOAINI = 23;
	const Sbecore::uint NAV = 24;
	const Sbecore::uint NEW = 25;
	const Sbecore::uint NO = 26;
	const Sbecore::uint OK = 27;
	const Sbecore::uint OPSCPLLAST = 28;
	const Sbecore::uint OPSPREP = 29;
	const Sbecore::uint OWN = 30;
	const Sbecore::uint PROGRESS = 31;
	const Sbecore::uint PRSERR = 32;
	const Sbecore::uint QUEST = 33;
	const Sbecore::uint REC = 34;
	const Sbecore::uint REVERSE = 35;
	const Sbecore::uint RUN = 36;
	const Sbecore::uint SESS = 37;
	const Sbecore::uint SHOWLONG = 38;
	const Sbecore::uint SHOWSHORT = 39;
	const Sbecore::uint STOP = 40;
	const Sbecore::uint SUSPSESS = 41;
	const Sbecore::uint TRU = 42;
	const Sbecore::uint UPLOAD = 43;
	const Sbecore::uint WARNING = 44;
	const Sbecore::uint YES = 45;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
