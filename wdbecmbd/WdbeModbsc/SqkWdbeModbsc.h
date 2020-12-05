/**
	* \file SqkWdbeModbsc.h
	* squawk generation for operation pack WdbeModbsc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEMODBSC_H
#define SQKWDBEMODBSC_H

#include "WdbeModbsc_blks.h"

/**
	* SqkWdbeModbsc
	*/
namespace SqkWdbeModbsc {
	std::string getSquawkCtrtd(DbsWdbe* dbswdbe, DpchInvWdbeModbscCtrtd* dpchinv);
	std::string getSquawkFwdctrtd(DbsWdbe* dbswdbe, DpchInvWdbeModbscFwdctrtd* dpchinv);
	std::string getSquawkImbuftd(DbsWdbe* dbswdbe, DpchInvWdbeModbscImbuftd* dpchinv);
	std::string getSquawkSys(DbsWdbe* dbswdbe, DpchInvWdbeModbscSys* dpchinv);
	std::string getSquawkTplcpy(DbsWdbe* dbswdbe, DpchInvWdbeModbscTplcpy* dpchinv);
	std::string getSquawkUnt(DbsWdbe* dbswdbe, DpchInvWdbeModbscUnt* dpchinv);
};

#endif



