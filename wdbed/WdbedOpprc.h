/**
	* \file WdbedOpprc.h
	* operation processor for Wdbe daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEDOPPRC_H
#define WDBEDOPPRC_H

/**
	* WdbedOpprc
	*/
namespace WdbedOpprc {
	void* run(void* arg);
	void cleanup(void* _arg);

	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _ret);

	void writeDpchInv(CURL* curl, XchgWdbed* xchg, ReqWdbe* req);
	Sbecore::uint readDpchRet(XchgWdbed* xchg, ReqWdbe* req);
};

/**
	* WdbedOpprc_arg
	*/
struct WdbedOpprc_arg {
	XchgWdbed* xchg;
	NodeWdbe* node;
};

/**
	* WdbedOpprc_cuarg
	*/
struct WdbedOpprc_cuarg {
	XchgWdbed* xchg;
	ReqWdbe** req;
	Sbecore::ubigint* oref;
	Sbecore::ubigint* jref;
};

#endif

