/**
	* \file WdbeQCmdList.h
	* API code for table TblWdbeQCmdList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQCMDLIST_H
#define WDBEQCMDLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmdList
	*/
class WdbeQCmdList {

public:
	WdbeQCmdList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Fullsref = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string srefIxVRettype = "", const std::string titIxVRettype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Fullsref;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string srefIxVRettype;
	std::string titIxVRettype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmdList
	*/
class ListWdbeQCmdList {

public:
	ListWdbeQCmdList();
	ListWdbeQCmdList(const ListWdbeQCmdList& src);
	ListWdbeQCmdList& operator=(const ListWdbeQCmdList& src);
	~ListWdbeQCmdList();

	void clear();

public:
	std::vector<WdbeQCmdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

