/**
	* \file WdbedOpengcli.h
	* operation engine client for Wdbe daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEDOPENGCLI_H
#define WDBEDOPENGCLI_H

#include "WdbedOpprc.h"

/**
	* WdbedOpengcli
	*/
namespace WdbedOpengcli {
	void* run(void* arg);
	bool run_checkNodes(XchgWdbe* xchg);

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _arg);
};

/**
	* WdbedOpengcli_curlarg
	*/
struct WdbedOpengcli_curlarg {
	char* buf;
	size_t buflen;
};

#endif

