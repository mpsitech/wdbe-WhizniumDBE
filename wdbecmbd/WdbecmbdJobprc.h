/**
	* \file WdbecmbdJobprc.h
	* job processor for Wdbe combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBECMBDJOBPRC_H
#define WDBECMBDJOBPRC_H

/**
	* WdbecmbdJobprc
	*/
namespace WdbecmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWdbecmbd* xchg, DbsWdbe* dbswdbe, ReqWdbe* req);
};

#endif
