/**
	* \file WdbeModdetEhostif.h
	* Wdbe operation processor - add command wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETEHOSTIF_H
#define WDBEMODDETEHOSTIF_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetEhostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetEhostif* dpchinv);
	// IP cust --- IBEGIN

  void mergeCreateOprt(DbsWdbe* dbswdbe, const Sbecore::ubigint refC, const Sbecore::ubigint refMdl, Sbecore::uint& mdlNum, const std::string& sref, const Sbecore::uint ixVDir, const std::string& srefHty, const Sbecore::usmallint Width, const std::string& srefCsi, ListWdbeMPort& oldprts, const unsigned int ix0Oldprts, const unsigned int ix1Oldprts);
	// IP cust --- IEND
};

#endif
