/**
	* \file WdbeQFstAStep.h
	* API code for table TblWdbeQFstAStep (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQFSTASTEP_H
#define WDBEQFSTASTEP_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQFstAStep
	*/
class WdbeQFstAStep {

public:
	WdbeQFstAStep(const Sbecore::uint jnum = 0, const std::string stubFnxRefWdbeMFsmstate = "", const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");

public:
	Sbecore::uint jnum;
	std::string stubFnxRefWdbeMFsmstate;
	std::string Cond1;
	std::string Ip1;
	std::string Cond2;
	std::string Ip2;
	std::string Cond3;
	std::string Ip3;
	std::string Cond4;
	std::string Ip4;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQFstAStep
	*/
class ListWdbeQFstAStep {

public:
	ListWdbeQFstAStep();
	ListWdbeQFstAStep(const ListWdbeQFstAStep& src);
	ListWdbeQFstAStep& operator=(const ListWdbeQFstAStep& src);
	~ListWdbeQFstAStep();

	void clear();

public:
	std::vector<WdbeQFstAStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

