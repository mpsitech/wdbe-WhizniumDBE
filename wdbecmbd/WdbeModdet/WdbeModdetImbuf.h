/**
	* \file WdbeModdetImbuf.h
	* Wdbe operation processor - add inter-module buffer wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETIMBUF_H
#define WDBEMODDETIMBUF_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetImbuf {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetImbuf* dpchinv);
	// IP cust --- IBEGIN

	void mergeCreateOprt(DbsWdbe* dbswdbe, const Sbecore::ubigint refC, const Sbecore::ubigint refMdl, Sbecore::uint& mdlNum, const std::string& sref, const std::string& srefHty, const Sbecore::usmallint Width, const std::string& srefCsi, std::map<std::string,WdbeMPort*>& srefsOldprts);
	// IP cust --- IEND
};

#endif
