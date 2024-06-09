/**
	* \file WdbeGenfstCtr.h
	* Wdbe operation processor - add command process and FSM debug ports (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTCTR_H
#define WDBEGENFSTCTR_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstCtr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstCtr* dpchinv);
	// IP cust --- IBEGIN

	void addCmdErrSigs(DbsWdbe* dbswdbe, WdbeMModule* mdl, Sbecore::uint& mdlNum, WdbeMProcess* prc, WdbeMCommand* cmd, const std::string& UntsrefExtcmd, const std::string& MdlsrefExtcmd, const std::string& Cmdsref, WdbeMError* err);
	Sbecore::ubigint mergeCreateFsts(DbsWdbe* dbswdbe, const Sbecore::ubigint refFsm, const Sbecore::ubigint refC, const std::string& sref, ListWdbeMFsmstate& oldfsts, ListWdbeMFsmstate& fsts, Sbecore::uint& fsmNum, const bool createNotSkip, bool& maxOneOldFstNoFass);
	// IP cust --- IEND
};

#endif
