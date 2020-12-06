/**
	* \file VecWdbeVMimetype.cpp
	* vector VecWdbeVMimetype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVMimetype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVMimetype
 ******************************************************************************/

uint VecWdbeVMimetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bmp") return BMP;
	if (s == "cpp") return CPP;
	if (s == "css") return CSS;
	if (s == "csv") return CSV;
	if (s == "doc") return DOC;
	if (s == "docx") return DOCX;
	if (s == "eps") return EPS;
	if (s == "gif") return GIF;
	if (s == "h") return H;
	if (s == "hdf") return HDF;
	if (s == "html") return HTML;
	if (s == "jpg") return JPG;
	if (s == "js") return JS;
	if (s == "make") return MAKE;
	if (s == "nc") return NC;
	if (s == "pdf") return PDF;
	if (s == "png") return PNG;
	if (s == "ppt") return PPT;
	if (s == "pptx") return PPTX;
	if (s == "sh") return SH;
	if (s == "sql") return SQL;
	if (s == "svg") return SVG;
	if (s == "tex") return TEX;
	if (s == "tgz") return TGZ;
	if (s == "tif") return TIF;
	if (s == "txt") return TXT;
	if (s == "xls") return XLS;
	if (s == "xlsx") return XLSX;
	if (s == "xml") return XML;
	if (s == "zip") return ZIP;

	return(0);
};

string VecWdbeVMimetype::getSref(
			const uint ix
		) {
	if (ix == BMP) return("bmp");
	if (ix == CPP) return("cpp");
	if (ix == CSS) return("css");
	if (ix == CSV) return("csv");
	if (ix == DOC) return("doc");
	if (ix == DOCX) return("docx");
	if (ix == EPS) return("eps");
	if (ix == GIF) return("gif");
	if (ix == H) return("h");
	if (ix == HDF) return("hdf");
	if (ix == HTML) return("html");
	if (ix == JPG) return("jpg");
	if (ix == JS) return("js");
	if (ix == MAKE) return("make");
	if (ix == NC) return("nc");
	if (ix == PDF) return("pdf");
	if (ix == PNG) return("png");
	if (ix == PPT) return("ppt");
	if (ix == PPTX) return("pptx");
	if (ix == SH) return("sh");
	if (ix == SQL) return("sql");
	if (ix == SVG) return("svg");
	if (ix == TEX) return("tex");
	if (ix == TGZ) return("tgz");
	if (ix == TIF) return("tif");
	if (ix == TXT) return("txt");
	if (ix == XLS) return("xls");
	if (ix == XLSX) return("xlsx");
	if (ix == XML) return("xml");
	if (ix == ZIP) return("zip");

	return("");
};

string VecWdbeVMimetype::getTitle(
			const uint ix
		) {
	if (ix == BMP) return("image/bmp");
	if (ix == CPP) return("text/x-c");
	if (ix == CSS) return("text/css");
	if (ix == CSV) return("text/comma-separated-values");
	if (ix == DOC) return("application/msword");
	if (ix == DOCX) return("application/vnd.openxmlformats-officedocument.wordprocessingml.document");
	if (ix == EPS) return("application/postscript");
	if (ix == GIF) return("image/gif");
	if (ix == H) return("text/x-h");
	if (ix == HDF) return("application/x-hdf");
	if (ix == HTML) return("text/html");
	if (ix == JPG) return("image/jpeg");
	if (ix == JS) return("text/javascript");
	if (ix == MAKE) return("text/x-makefile");
	if (ix == NC) return("application/x-netcdf");
	if (ix == PDF) return("application/pdf");
	if (ix == PNG) return("image/png");
	if (ix == PPT) return("application/mspowerpoint");
	if (ix == PPTX) return("application/vnd.openxmlformats-officedocument.presentationml.presentation");
	if (ix == SH) return("application/x-sh");
	if (ix == SQL) return("text/x-sql");
	if (ix == SVG) return("image/svg+xml");
	if (ix == TEX) return("application/x-tex");
	if (ix == TGZ) return("application/x-gzip");
	if (ix == TIF) return("image/tiff");
	if (ix == TXT) return("text/plain");
	if (ix == XLS) return("application/msexcel");
	if (ix == XLSX) return("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
	if (ix == XML) return("text/xml");
	if (ix == ZIP) return("application/zip");
	return(getSref(ix));

	return("");
};
