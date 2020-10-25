/**
	* \file WdbeQErrAPar.h
	* API code for table TblWdbeQErrAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQERRAPAR_H
#define WDBEQERRAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQErrAPar
	*/
class WdbeQErrAPar {

public:
	WdbeQErrAPar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");

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
	* ListWdbeQErrAPar
	*/
class ListWdbeQErrAPar {

public:
	ListWdbeQErrAPar();
	ListWdbeQErrAPar(const ListWdbeQErrAPar& src);
	ListWdbeQErrAPar& operator=(const ListWdbeQErrAPar& src);
	~ListWdbeQErrAPar();

	void clear();

public:
	std::vector<WdbeQErrAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

