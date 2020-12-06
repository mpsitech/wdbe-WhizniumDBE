/**
	* \file WdbedOpprc.h
	* operation processor for Wdbe daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
