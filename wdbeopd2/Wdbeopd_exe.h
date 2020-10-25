/**
	* \file Wdbeopd_exe.h
	* Wdbe operation daemon wdbeopd2 main (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEOPD_EXE_H
#define WDBEOPD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "WdbeopdEngsrv.h"
#include "WdbeopdOpprc.h"

/**
	* Wdbeopd
	*/
class Wdbeopd {

public:
	Wdbeopd(const std::string& exedir, const Sbecore::usmallint engsrvportofs);
	~Wdbeopd();

public:
	std::string exedir;

	DbsWdbe dbswdbe;

	XchgWdbeopd* xchg;

	MHD_Daemon* engsrv;

	std::vector<pthread_t> opprcs;

public:
	char* curlbuf;
	size_t curlbuflen;

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	static Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _inst);

public:
	void loadPref();
	void storePref();
};

#endif

