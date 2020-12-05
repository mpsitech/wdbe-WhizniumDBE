/**
	* \file Wdbecmbd_exe.h
	* Wdbe combined daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBECMBD_EXE_H
#define WDBECMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "WdbecmbdAppsrv.h"
#include "WdbecmbdJobprc.h"
#include "WdbecmbdOpprc.h"

/**
	* Wdbecmbd
	*/
class Wdbecmbd {

public:
	Wdbecmbd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wdbecmbd();

public:
	std::string exedir;

	DbsWdbe dbswdbe;

	XchgWdbecmbd* xchg;
	
	RootWdbe* root;

	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	std::vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif



