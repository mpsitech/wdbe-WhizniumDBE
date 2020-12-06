/**
	* \file WdbedJobprc.h
	* job processor for Wdbe daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEDJOBPRC_H
#define WDBEDJOBPRC_H

/**
	* WdbedJobprc
	*/
namespace WdbedJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWdbed* xchg, DbsWdbe* dbswdbe, ReqWdbe* req);
};

#endif
