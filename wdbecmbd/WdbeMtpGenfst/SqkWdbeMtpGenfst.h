/**
	* \file SqkWdbeMtpGenfst.h
	* squawk generation for operation pack WdbeMtpGenfst (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef SQKWDBEMTPGENFST_H
#define SQKWDBEMTPGENFST_H

#include "WdbeMtpGenfst_blks.h"

/**
	* SqkWdbeMtpGenfst
	*/
namespace SqkWdbeMtpGenfst {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
};

#endif
