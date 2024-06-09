/**
	* \file WdbeQSigMNCdc.h
	* API code for table TblWdbeQSigMNCdc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQSIGMNCDC_H
#define WDBEQSIGMNCDC_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSigMNCdc
	*/
class WdbeQSigMNCdc {

public:
	WdbeQSigMNCdc(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxVDir = "", const std::string titIxVDir = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxVDir;
	std::string titIxVDir;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSigMNCdc
	*/
class ListWdbeQSigMNCdc {

public:
	ListWdbeQSigMNCdc();
	ListWdbeQSigMNCdc(const ListWdbeQSigMNCdc& src);
	ListWdbeQSigMNCdc& operator=(const ListWdbeQSigMNCdc& src);
	~ListWdbeQSigMNCdc();

	void clear();

public:
	std::vector<WdbeQSigMNCdc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
