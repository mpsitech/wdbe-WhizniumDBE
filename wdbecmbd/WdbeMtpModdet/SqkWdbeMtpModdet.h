/**
	* \file SqkWdbeMtpModdet.h
	* squawk generation for operation pack WdbeMtpModdet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEMTPMODDET_H
#define SQKWDBEMTPMODDET_H

#include "WdbeMtpModdet_blks.h"

/**
	* SqkWdbeMtpModdet
	*/
namespace SqkWdbeMtpModdet {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpModdet* dpchinv);
};

#endif
