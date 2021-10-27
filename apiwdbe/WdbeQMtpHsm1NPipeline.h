/**
	* \file WdbeQMtpHsm1NPipeline.h
	* API code for table TblWdbeQMtpHsm1NPipeline (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPHSM1NPIPELINE_H
#define WDBEQMTPHSM1NPIPELINE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpHsm1NPipeline
	*/
class WdbeQMtpHsm1NPipeline {

public:
	WdbeQMtpHsm1NPipeline(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpHsm1NPipeline
	*/
class ListWdbeQMtpHsm1NPipeline {

public:
	ListWdbeQMtpHsm1NPipeline();
	ListWdbeQMtpHsm1NPipeline(const ListWdbeQMtpHsm1NPipeline& src);
	ListWdbeQMtpHsm1NPipeline& operator=(const ListWdbeQMtpHsm1NPipeline& src);
	~ListWdbeQMtpHsm1NPipeline();

	void clear();

public:
	std::vector<WdbeQMtpHsm1NPipeline*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
