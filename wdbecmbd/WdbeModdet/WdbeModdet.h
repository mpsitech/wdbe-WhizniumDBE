/**
	* \file WdbeModdet.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDET_H
#define WDBEMODDET_H

#include "WdbeModdet_blks.h"

// IP include.cust --- IBEGIN
#include <utility>
// IP include.cust --- IEND

namespace WdbeModdet {

	// IP cust --- IBEGIN
  void addCtrVits(DbsWdbe* dbswdbe, WdbeMController* ctr, ListWdbeMCommand& cmds, Sbecore::uint& mdlNum, const std::string& Prjshort, const std::string& Untsref);

	void getMaxlenRecvSend(DbsWdbe* dbswdbe, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, unsigned int& maxlenRecv, unsigned int& maxlenSend);
	// IP cust --- IEND
};

#endif
