/**
	* \file SqkWdbeMtpWrmcu.h
	* squawk generation for operation pack WdbeMtpWrmcu (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEMTPWRMCU_H
#define SQKWDBEMTPWRMCU_H

#include "WdbeMtpWrmcu_blks.h"

/**
	* SqkWdbeMtpWrmcu
	*/
namespace SqkWdbeMtpWrmcu {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpWrmcu* dpchinv);
};

#endif
