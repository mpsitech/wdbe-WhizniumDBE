/**
	* \file Wdbed_exe.h
	* Wdbe daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBED_EXE_H
#define WDBED_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "WdbedAppsrv.h"
#include "WdbedJobprc.h"
#include "WdbedOpengcli.h"
#include "WdbedOpengsrv.h"

/**
	* Wdbed
	*/
class Wdbed {

public:
	Wdbed(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wdbed();

public:
	std::string exedir;

	DbsWdbe dbswdbe;

	XchgWdbed* xchg;
	
	RootWdbe* root;

	MHD_Daemon* opengsrv;
	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	pthread_t opengcli;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif




