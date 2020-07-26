/**
	* \file SqkWdbeMtpModdet.h
	* squawk generation for operation pack WdbeMtpModdet (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

