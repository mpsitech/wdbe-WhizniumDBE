/**
	* \file WdbeModdet.h
	* Wdbe operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


