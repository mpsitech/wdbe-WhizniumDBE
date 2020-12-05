/**
	* \file VecWdbeVMimetype.h
	* vector VecWdbeVMimetype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVMIMETYPE_H
#define VECWDBEVMIMETYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVMimetype
	*/
namespace VecWdbeVMimetype {
	const Sbecore::uint BMP = 1;
	const Sbecore::uint CPP = 2;
	const Sbecore::uint CSS = 3;
	const Sbecore::uint CSV = 4;
	const Sbecore::uint DOC = 5;
	const Sbecore::uint DOCX = 6;
	const Sbecore::uint EPS = 7;
	const Sbecore::uint GIF = 8;
	const Sbecore::uint H = 9;
	const Sbecore::uint HDF = 10;
	const Sbecore::uint HTML = 11;
	const Sbecore::uint JPG = 12;
	const Sbecore::uint JS = 13;
	const Sbecore::uint MAKE = 14;
	const Sbecore::uint NC = 15;
	const Sbecore::uint PDF = 16;
	const Sbecore::uint PNG = 17;
	const Sbecore::uint PPT = 18;
	const Sbecore::uint PPTX = 19;
	const Sbecore::uint SH = 20;
	const Sbecore::uint SQL = 21;
	const Sbecore::uint SVG = 22;
	const Sbecore::uint TEX = 23;
	const Sbecore::uint TGZ = 24;
	const Sbecore::uint TIF = 25;
	const Sbecore::uint TXT = 26;
	const Sbecore::uint XLS = 27;
	const Sbecore::uint XLSX = 28;
	const Sbecore::uint XML = 29;
	const Sbecore::uint ZIP = 30;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
};

#endif



