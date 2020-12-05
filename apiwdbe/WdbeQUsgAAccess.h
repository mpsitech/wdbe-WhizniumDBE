/**
	* \file WdbeQUsgAAccess.h
	* API code for table TblWdbeQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSGAACCESS_H
#define WDBEQUSGAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsgAAccess
	*/
class WdbeQUsgAAccess {

public:
	WdbeQUsgAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxWdbeVFeatgroup;
	std::string titX1IxWdbeVFeatgroup;
	std::string x2FeaSrefUix;
	std::string srefsIxWdbeWAccess;
	std::string titsIxWdbeWAccess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsgAAccess
	*/
class ListWdbeQUsgAAccess {

public:
	ListWdbeQUsgAAccess();
	ListWdbeQUsgAAccess(const ListWdbeQUsgAAccess& src);
	ListWdbeQUsgAAccess& operator=(const ListWdbeQUsgAAccess& src);
	~ListWdbeQUsgAAccess();

	void clear();

public:
	std::vector<WdbeQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

