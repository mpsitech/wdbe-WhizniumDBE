// IP file --- KEEP
/**
	* \file VecWzlaVSte.h
	* state vector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 15 Jun 2019
	* \date modified: 15 Jun 2019
	*/

#ifndef VECWZLAVSTE_H
#define VECWZLAVSTE_H

#include <string>

namespace VecWzlaVSte {
	// idle
	const unsigned int IDLE = 1;

	// conenct to Whiznium License Manager
	const unsigned int CONNECT_IDLE = 2;
	const unsigned int CONNECT_DPCHLOGIN = 3;
	const unsigned int CONNECT_DPCHINIT_SESS = 4;
	const unsigned int CONNECT_DPCHNAVDO_MITCRDSDB = 5;
	const unsigned int CONNECT_DPCHINIT_CRDSDB = 6;
	const unsigned int CONNECT_DPCHINIT_PNLAUTH = 7;
	const unsigned int CONNECT_DPCHINIT_PNLPRJSNC = 8;
	const unsigned int CONNECT_DPCHINIT_PNLVERSNC = 9;
	const unsigned int CONNECT_ERR = 10;
	const unsigned int CONNECT_DONE = 11;

	// report activity
	const unsigned int REPACT_IDLE = 12;
	const unsigned int REPACT_DPCHHEARTBEATDO_BUTRAC = 13;
	const unsigned int REPACT_ERR = 14;
	const unsigned int REPACT_DONE = 15;

	// report inactivity
	const unsigned int REPINACT_IDLE = 16;
	const unsigned int REPINACT_DPCHHEARTBEATDO_BUTRIN = 17;
	const unsigned int REPINACT_ERR = 18;
	const unsigned int REPINACT_DONE = 19;

	// authenticate existing project import
	const unsigned int AUTHIMPEX_IDLE = 20;
	const unsigned int AUTHIMPEX_DPCHAUTHDATA = 21;
	const unsigned int AUTHIMPEX_DPCHAUTHDO_BUTIAU = 22;
	const unsigned int AUTHIMPEX_ERR = 23;
	const unsigned int AUTHIMPEX_DONE = 24;

	// authenticate new project creation
	const unsigned int AUTHPRJNEW_IDLE = 25;
	const unsigned int AUTHPRJNEW_DPCHAUTHDO_BUTCAU = 26;
	const unsigned int AUTHPRJNEW_ERR = 27;
	const unsigned int AUTHPRJNEW_DONE = 28;

	// authenticate code writing
	const unsigned int AUTHWRCODE_IDLE = 29;
	const unsigned int AUTHWRCODE_SELPRJ = 30;
	const unsigned int AUTHWRCODE_SELVER = 31;
	const unsigned int AUTHWRCODE_DPCHAUTHDATA = 32;
	const unsigned int AUTHWRCODE_DPCHAUTHDO_BUTWAU = 33;
	const unsigned int AUTHWRCODE_ERR = 34;
	const unsigned int AUTHWRCODE_DONE = 35;

	// synchronize projects
	const unsigned int SYNCPRJ_IDLE = 36;
	const unsigned int SYNCPRJ_DPCHPRJSNCDATA = 37;
	const unsigned int SYNCPRJ_DPCHPRJSNCDO_BUTSNC = 38;
	const unsigned int SYNCPRJ_ERR = 39;
	const unsigned int SYNCPRJ_DONE = 40;

	// synchronize version
	const unsigned int SYNCVER_IDLE = 41;
	const unsigned int SYNCVER_SELPRJ = 42;
	const unsigned int SYNCVER_SELVER = 43;
	const unsigned int SYNCVER_DPCHVERSNCDATA = 44;
	const unsigned int SYNCVER_DPCHVERSNCDO_BUTSNC = 45;
	const unsigned int SYNCVER_ERR = 46;
	const unsigned int SYNCVER_DONE = 47;

	// wrap up
	const unsigned int FINISH_IDLE = 48;
	const unsigned int FINISH_DPCHNAVDO_MITSESTRM = 49;
	const unsigned int FINISH_ERR = 50;
	const unsigned int FINISH_DONE = 51;

	std::string getSref(const unsigned int ix);
};

#endif

