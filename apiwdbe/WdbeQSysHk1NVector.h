/**
	* \file WdbeQSysHk1NVector.h
	* API code for table TblWdbeQSysHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQSYSHK1NVECTOR_H
#define WDBEQSYSHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSysHk1NVector
	*/
class WdbeQSysHk1NVector {

public:
	WdbeQSysHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSysHk1NVector
	*/
class ListWdbeQSysHk1NVector {

public:
	ListWdbeQSysHk1NVector();
	ListWdbeQSysHk1NVector(const ListWdbeQSysHk1NVector& src);
	ListWdbeQSysHk1NVector& operator=(const ListWdbeQSysHk1NVector& src);
	~ListWdbeQSysHk1NVector();

	void clear();

public:
	std::vector<WdbeQSysHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

