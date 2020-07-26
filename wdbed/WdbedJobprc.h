/**
	* \file WdbedJobprc.h
	* job processor for Wdbe daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

