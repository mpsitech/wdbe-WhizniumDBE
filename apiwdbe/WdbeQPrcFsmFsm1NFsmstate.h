/**
	* \file WdbeQPrcFsmFsm1NFsmstate.h
	* API code for table TblWdbeQPrcFsmFsm1NFsmstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCFSMFSM1NFSMSTATE_H
#define WDBEQPRCFSMFSM1NFSMSTATE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcFsmFsm1NFsmstate
	*/
class WdbeQPrcFsmFsm1NFsmstate {

public:
	WdbeQPrcFsmFsm1NFsmstate(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcFsmFsm1NFsmstate
	*/
class ListWdbeQPrcFsmFsm1NFsmstate {

public:
	ListWdbeQPrcFsmFsm1NFsmstate();
	ListWdbeQPrcFsmFsm1NFsmstate(const ListWdbeQPrcFsmFsm1NFsmstate& src);
	ListWdbeQPrcFsmFsm1NFsmstate& operator=(const ListWdbeQPrcFsmFsm1NFsmstate& src);
	~ListWdbeQPrcFsmFsm1NFsmstate();

	void clear();

public:
	std::vector<WdbeQPrcFsmFsm1NFsmstate*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

