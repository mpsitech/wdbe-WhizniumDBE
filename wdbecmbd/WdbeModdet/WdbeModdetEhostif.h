/**
	* \file WdbeModdetEhostif.h
	* Wdbe operation processor - add command wiring (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


