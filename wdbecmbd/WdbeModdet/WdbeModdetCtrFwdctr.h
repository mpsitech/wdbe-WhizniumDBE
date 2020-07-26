/**
	* \file WdbeModdetCtrFwdctr.h
	* Wdbe operation processor - add command process and FSM debug ports (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMODDETCTRFWDCTR_H
#define WDBEMODDETCTRFWDCTR_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetCtrFwdctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetCtrFwdctr* dpchinv);
	// IP cust --- IBEGIN

	void addCmdErrSigs(DbsWdbe* dbswdbe, WdbeMModule* mdl, Sbecore::uint& mdlNum, WdbeMProcess* prc, WdbeMCommand* cmd, const std::string& UntsrefExtcmd, const std::string& MdlsrefExtcmd, const std::string& Cmdsref, WdbeMError* err);
	Sbecore::ubigint mergeCreateFsts(DbsWdbe* dbswdbe, const Sbecore::ubigint refFsm, const Sbecore::ubigint refC, const std::string& sref, ListWdbeMFsmstate& oldfsts, ListWdbeMFsmstate& fsts, Sbecore::uint& fsmNum, const bool createNotSkip, bool& maxOneOldFstNoFass);
	// IP cust --- IEND
};

#endif


