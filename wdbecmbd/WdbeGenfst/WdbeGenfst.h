/**
	* \file WdbeGenfst.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFST_H
#define WDBEGENFST_H

#include "WdbeGenfst_blks.h"

// IP include.cust --- INSERT

namespace WdbeGenfst {

	// IP cust --- IBEGIN
  void addCtrVits(DbsWdbe* dbswdbe, WdbeMController* ctr, ListWdbeMCommand& cmds, Sbecore::uint& mdlNum, const std::string& Prjshort, const std::string& Untsref);

	void getMaxlenRecvSend(DbsWdbe* dbswdbe, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, unsigned int& maxlenRecv, unsigned int& maxlenSend);
	// IP cust --- IEND
};

#endif
