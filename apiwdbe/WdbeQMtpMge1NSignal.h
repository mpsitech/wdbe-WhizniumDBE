/**
	* \file WdbeQMtpMge1NSignal.h
	* API code for table TblWdbeQMtpMge1NSignal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPMGE1NSIGNAL_H
#define WDBEQMTPMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpMge1NSignal
	*/
class WdbeQMtpMge1NSignal {

public:
	WdbeQMtpMge1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpMge1NSignal
	*/
class ListWdbeQMtpMge1NSignal {

public:
	ListWdbeQMtpMge1NSignal();
	ListWdbeQMtpMge1NSignal(const ListWdbeQMtpMge1NSignal& src);
	ListWdbeQMtpMge1NSignal& operator=(const ListWdbeQMtpMge1NSignal& src);
	~ListWdbeQMtpMge1NSignal();

	void clear();

public:
	std::vector<WdbeQMtpMge1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

