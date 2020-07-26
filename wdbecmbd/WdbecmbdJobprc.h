/**
	* \file WdbecmbdJobprc.h
	* job processor for Wdbe combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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



