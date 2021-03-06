/**
	* \file WdbeQUsrAAccess.h
	* API code for table TblWdbeQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSRAACCESS_H
#define WDBEQUSRAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsrAAccess
	*/
class WdbeQUsrAAccess {

public:
	WdbeQUsrAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");

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
	* ListWdbeQUsrAAccess
	*/
class ListWdbeQUsrAAccess {

public:
	ListWdbeQUsrAAccess();
	ListWdbeQUsrAAccess(const ListWdbeQUsrAAccess& src);
	ListWdbeQUsrAAccess& operator=(const ListWdbeQUsrAAccess& src);
	~ListWdbeQUsrAAccess();

	void clear();

public:
	std::vector<WdbeQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
