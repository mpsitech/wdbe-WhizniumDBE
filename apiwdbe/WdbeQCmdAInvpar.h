/**
	* \file WdbeQCmdAInvpar.h
	* API code for table TblWdbeQCmdAInvpar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQCMDAINVPAR_H
#define WDBEQCMDAINVPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmdAInvpar
	*/
class WdbeQCmdAInvpar {

public:
	WdbeQCmdAInvpar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Defval = "", const std::string stubRefWdbeMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWdbeVPartype;
	std::string titIxWdbeVPartype;
	std::string stubRefWdbeMVector;
	Sbecore::utinyint Length;
	std::string Defval;
	std::string stubRefWdbeMVectoritem;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmdAInvpar
	*/
class ListWdbeQCmdAInvpar {

public:
	ListWdbeQCmdAInvpar();
	ListWdbeQCmdAInvpar(const ListWdbeQCmdAInvpar& src);
	ListWdbeQCmdAInvpar& operator=(const ListWdbeQCmdAInvpar& src);
	~ListWdbeQCmdAInvpar();

	void clear();

public:
	std::vector<WdbeQCmdAInvpar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

