// IP file --- KEEP
/**
	* \file VecWzlaVSte.cpp
	* state vector (implementation)
	* \author Alexander Wirthmueller
	* \date created: 15 Jun 2019
	* \date modified: 15 Jun 2019
	*/

#include "VecWzlaVSte.h"

using namespace std;

string VecWzlaVSte::getSref(
			const unsigned int ix
		) {
	if (ix == IDLE) return("idle");

	if (ix == CONNECT_IDLE) return("connect.idle");
	if (ix == CONNECT_DPCHLOGIN) return("connect.DpchLogin");
	if (ix == CONNECT_DPCHINIT_SESS) return("connect.DpchInit.Sess");
	if (ix == CONNECT_DPCHNAVDO_MITCRDSDB) return("connect.DpchNavDo.MitCrdSdb");
	if (ix == CONNECT_DPCHINIT_CRDSDB) return("connect.DpchInit.CrdSdb");
	if (ix == CONNECT_DPCHINIT_PNLAUTH) return("connect.DpchInit.PnlAuth");
	if (ix == CONNECT_DPCHINIT_PNLPRJSNC) return("connect.DpchInit.PnlPrjsnc");
	if (ix == CONNECT_DPCHINIT_PNLVERSNC) return("connect.DpchInit.PnlVersnc");
	if (ix == CONNECT_ERR) return("connect.err");
	if (ix == CONNECT_DONE) return("connect.done");

	if (ix == REPACT_IDLE) return("repact.idle");
	if (ix == REPACT_DPCHHEARTBEATDO_BUTRAC) return("repact.DpchHeartbeatDo.ButRac");
	if (ix == REPACT_ERR) return("repact.err");
	if (ix == REPACT_DONE) return("repact.done");

	if (ix == REPINACT_IDLE) return("repinact.idle");
	if (ix == REPINACT_DPCHHEARTBEATDO_BUTRIN) return("repinact.DpchHeartbeatDo.ButRin");
	if (ix == REPINACT_ERR) return("repinact.err");
	if (ix == REPINACT_DONE) return("repinact.done");

	if (ix == AUTHIMPEX_IDLE) return("authimpex.idle");
	if (ix == AUTHIMPEX_DPCHAUTHDATA) return("authimpex.DpchAuthData");
	if (ix == AUTHIMPEX_DPCHAUTHDO_BUTIAU) return("authimpex.DpchAuthDo.ButIau");
	if (ix == AUTHIMPEX_ERR) return("authimpex.err");
	if (ix == AUTHIMPEX_DONE) return("authimpex.done");

	if (ix == AUTHPRJNEW_IDLE) return("authprjnew.idle");
	if (ix == AUTHPRJNEW_DPCHAUTHDO_BUTCAU) return("authprjnew.DpchAuthDo.ButCau");
	if (ix == AUTHPRJNEW_ERR) return("authprjnew.err");
	if (ix == AUTHPRJNEW_DONE) return("authprjnew.done");

	if (ix == AUTHWRCODE_IDLE) return("authwrcode.idle");
	if (ix == AUTHWRCODE_SELPRJ) return("authwrcode.selPrj");
	if (ix == AUTHWRCODE_SELVER) return("authwrcode.selVer");
	if (ix == AUTHWRCODE_DPCHAUTHDATA) return("authwrcode.DpchAuthData");
	if (ix == AUTHWRCODE_DPCHAUTHDO_BUTWAU) return("authwrcode.DpchAuthDo.ButWau");
	if (ix == AUTHWRCODE_ERR) return("authwrcode.err");
	if (ix == AUTHWRCODE_DONE) return("authwrcode.done");

	if (ix == SYNCPRJ_IDLE) return("syncprj.idle");
	if (ix == SYNCPRJ_DPCHPRJSNCDATA) return("syncprj.DpchPrjsncData");
	if (ix == SYNCPRJ_DPCHPRJSNCDO_BUTSNC) return("syncprj.DpchPrjsncDo.ButSnc");
	if (ix == SYNCPRJ_ERR) return("syncprj.err");
	if (ix == SYNCPRJ_DONE) return("syncprj.done");

	if (ix == SYNCVER_IDLE) return("syncver.idle");
	if (ix == SYNCVER_SELPRJ) return("syncver.selPrj");
	if (ix == SYNCVER_SELVER) return("syncver.selVer");
	if (ix == SYNCVER_DPCHVERSNCDATA) return("syncver.DpchVersncData");
	if (ix == SYNCVER_DPCHVERSNCDO_BUTSNC) return("syncver.DpchVersncDo.ButSnc");
	if (ix == SYNCVER_ERR) return("syncver.err");
	if (ix == SYNCVER_DONE) return("syncver.done");

	if (ix == FINISH_IDLE) return("finish.idle");
	if (ix == FINISH_DPCHNAVDO_MITSESTRM) return("finish.DpchNavDo.MitSesTrm");
	if (ix == FINISH_ERR) return("finish.err");
	if (ix == FINISH_DONE) return("finish.done");

	return("");
};

