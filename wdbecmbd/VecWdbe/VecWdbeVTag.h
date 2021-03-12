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
	const Sbecore::uint ANNOUNCE = 3;
	const Sbecore::uint CANCEL = 4;
	const Sbecore::uint CLOSE = 5;
	const Sbecore::uint CLSESS = 6;
	const Sbecore::uint CLUST = 7;
	const Sbecore::uint CREATE = 8;
	const Sbecore::uint DETAIL = 9;
	const Sbecore::uint DONE = 10;
	const Sbecore::uint DOWNLOAD = 11;
	const Sbecore::uint EMPLONG = 12;
	const Sbecore::uint EMPSHORT = 13;
	const Sbecore::uint ERROR = 14;
	const Sbecore::uint FILENAME = 15;
	const Sbecore::uint FLS = 16;
	const Sbecore::uint FOR = 17;
	const Sbecore::uint GENERAL = 18;
	const Sbecore::uint GOTO = 19;
	const Sbecore::uint GRP = 20;
	const Sbecore::uint HELP = 21;
	const Sbecore::uint HOUR = 22;
	const Sbecore::uint HOURS = 23;
	const Sbecore::uint IMPERR = 24;
	const Sbecore::uint IMPORT = 25;
	const Sbecore::uint LOAINI = 26;
	const Sbecore::uint MINUTE = 27;
	const Sbecore::uint MINUTES = 28;
	const Sbecore::uint NAV = 29;
	const Sbecore::uint NEW = 30;
	const Sbecore::uint NO = 31;
	const Sbecore::uint OK = 32;
	const Sbecore::uint OPSCPLLAST = 33;
	const Sbecore::uint OPSPREP = 34;
	const Sbecore::uint OWN = 35;
	const Sbecore::uint PROGRESS = 36;
	const Sbecore::uint PRSERR = 37;
	const Sbecore::uint QUEST = 38;
	const Sbecore::uint REC = 39;
	const Sbecore::uint REVERSE = 40;
	const Sbecore::uint RUN = 41;
	const Sbecore::uint SECOND = 42;
	const Sbecore::uint SECONDS = 43;
	const Sbecore::uint SESS = 44;
	const Sbecore::uint SHOWLONG = 45;
	const Sbecore::uint SHOWSHORT = 46;
	const Sbecore::uint STOP = 47;
	const Sbecore::uint SUSPSESS = 48;
	const Sbecore::uint TRU = 49;
	const Sbecore::uint UPLOAD = 50;
	const Sbecore::uint WARNING = 51;
	const Sbecore::uint YES = 52;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
};

#endif
