/**
	* \file WdbeQCmdARetpar.h
	* API code for table TblWdbeQCmdARetpar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQCMDARETPAR_H
#define WDBEQCMDARETPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmdARetpar
	*/
class WdbeQCmdARetpar {

public:
	WdbeQCmdARetpar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWdbeVPartype;
	std::string titIxWdbeVPartype;
	std::string stubRefWdbeMVector;
	Sbecore::utinyint Length;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmdARetpar
	*/
class ListWdbeQCmdARetpar {

public:
	ListWdbeQCmdARetpar();
	ListWdbeQCmdARetpar(const ListWdbeQCmdARetpar& src);
	ListWdbeQCmdARetpar& operator=(const ListWdbeQCmdARetpar& src);
	~ListWdbeQCmdARetpar();

	void clear();

public:
	std::vector<WdbeQCmdARetpar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

