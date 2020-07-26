// IP file --- KEEP
/**
	* \file AppWzla.h
	* app main functionality (declarations)
	* \author Alexander Wirthmueller
	* \date created: 15 Jun 2019
	* \date modified: 15 Jun 2019
	*/

#ifndef APPWZLA_H
#define APPWZLA_H

#include <sbecore/Mttypes.h>

#include "ApiWzlm.h"
#include "VecWzlaVSte.h"

#include <curl/curl.h>

// IP include.cust --- INSERT

/**
	* DOMWzla
	*/
class DOMWzla {

	/*
	- Sess
		- CrdNav
		- CrdSdb (CrdSdb_statshr)
			- PnlAuth (PnlAuth_contiac, PnlAuth_continf, PnlAuth_feedflstwsf, PnlAuth_feedfpupwct, PnlAuth_feedfpupwpr, PnlAuth_feedfpupwve, PnlAuth_feedfsge, PnlAuth_statshr)
			- PnlHeartbeat
			- PnlPrjsnc (PnlPrjsnc_contiac, PnlPrjsnc_statshr)
			- PnlVersnc (PnlVersnc_contiac, PnlVersnc_feedfpupprj, PnlVersnc_feedfpupver, PnlVersnc_statshr)
	*/

public:
	DOMWzla();
	~DOMWzla();

public:
	// IP DOM.vars.cust --- INSERT

	// Sess
	std::string scrJrefSess;

	// CrdNav
	std::string scrJrefCrdNav;

	// CrdSdb
	std::string scrJrefCrdSdb;
	CrdWzlmSdb::StatShr CrdSdb_statshr;

	// PnlAuth
	PnlWzlmSdbAuth::ContIac PnlAuth_contiac;
	PnlWzlmSdbAuth::ContInf PnlAuth_continf;
	Sbecore::Xmlio::Feed PnlAuth_feedflstwsf;
	Sbecore::Xmlio::Feed PnlAuth_feedfpupwct;
	Sbecore::Xmlio::Feed PnlAuth_feedfpupwpr;
	Sbecore::Xmlio::Feed PnlAuth_feedfpupwve;
	Sbecore::Xmlio::Feed PnlAuth_feedfsge;
	PnlWzlmSdbAuth::StatShr PnlAuth_statshr;

	// PnlPrjsnc
	PnlWzlmSdbPrjsnc::ContIac PnlPrjsnc_contiac;
	PnlWzlmSdbPrjsnc::StatShr PnlPrjsnc_statshr;

	// PnlVersnc
	PnlWzlmSdbVersnc::ContIac PnlVersnc_contiac;
	Sbecore::Xmlio::Feed PnlVersnc_feedfpupprj;
	Sbecore::Xmlio::Feed PnlVersnc_feedfpupver;
	PnlWzlmSdbVersnc::StatShr PnlVersnc_statshr;

};

/**
	* AppWzla
	*/
class AppWzla {

public:
	/**
		* VecVVerbose
		*/
	class VecVVerbose {

	public:
		static const Sbecore::uint OFF = 0;
		static const Sbecore::uint STATE = 1;
		static const Sbecore::uint DPCHMETA = 2;
		static const Sbecore::uint DPCHFULL = 3;
	};

public:
	AppWzla(const std::string engip, const Sbecore::uint engport, const std::string username, const std::string password);
	~AppWzla();

public:
	// IP vars.cust --- INSERT

	Sbecore::uint ixVVerbose;

	unsigned int nDpchApp;
	unsigned int nByteToEng;

	unsigned int nDpchEng;
	unsigned int nDpchEngNotify;
	unsigned int nByteFromEng;

	unsigned int ixVSte;

	StgWzlmapi* stgwzlmapi;

	DOMWzla* DOM;

	Sbecore::Cond cRefresh;

	unsigned int ixVSteRefresh;
	bool waitReplyRefresh;

	Sbecore::Mutex mHandleDpchEng;

	DpchAppWzlm* dpchapp;

	Sbecore::Cond cDpch;

	pthread_t dpch;

	pthread_t notify;

public:
	static void* runDpch(void* arg);
	static void cleanupDpch(void* arg);

	static void* runNotify(void* arg);
	static void cleanupNotify(void* arg);

	static Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _arg);

	static bool dpchEngConfirmAccepted(DpchEngWzlm* dpcheng, const std::string& scrJref, const std::string& sref);
	static bool dpchEngConfirmDenied(DpchEngWzlm* dpcheng);
	static bool dpchEngIsOfType(DpchEngWzlm* dpcheng, const Sbecore::uint ixWzlmVDpch, const std::string& scrJref);

	void resetStats();

	void refresh();

	void sendDpchApp(DpchAppWzlm* dpchapp);

public:
	void changeState(unsigned int _ixVSte);

	unsigned int enterSteIdle();
	void leaveSteIdle();

	unsigned int enterSteConnect_idle();
	void leaveSteConnect_idle();
	unsigned int enterSteConnect_DpchLogin();
	void leaveSteConnect_DpchLogin();
	unsigned int enterSteConnect_DpchInit_Sess();
	void leaveSteConnect_DpchInit_Sess();
	unsigned int enterSteConnect_DpchNavDo_MitCrdSdb();
	void leaveSteConnect_DpchNavDo_MitCrdSdb();
	unsigned int enterSteConnect_DpchInit_CrdSdb();
	void leaveSteConnect_DpchInit_CrdSdb();
	unsigned int enterSteConnect_DpchInit_PnlAuth();
	void leaveSteConnect_DpchInit_PnlAuth();
	unsigned int enterSteConnect_DpchInit_PnlPrjsnc();
	void leaveSteConnect_DpchInit_PnlPrjsnc();
	unsigned int enterSteConnect_DpchInit_PnlVersnc();
	void leaveSteConnect_DpchInit_PnlVersnc();
	unsigned int enterSteConnect_err();
	void leaveSteConnect_err();
	unsigned int enterSteConnect_done();
	void leaveSteConnect_done();

	unsigned int enterSteRepact_idle();
	void leaveSteRepact_idle();
	unsigned int enterSteRepact_DpchHeartbeatDo_ButRac();
	void leaveSteRepact_DpchHeartbeatDo_ButRac();
	unsigned int enterSteRepact_err();
	void leaveSteRepact_err();
	unsigned int enterSteRepact_done();
	void leaveSteRepact_done();

	unsigned int enterSteRepinact_idle();
	void leaveSteRepinact_idle();
	unsigned int enterSteRepinact_DpchHeartbeatDo_ButRin();
	void leaveSteRepinact_DpchHeartbeatDo_ButRin();
	unsigned int enterSteRepinact_err();
	void leaveSteRepinact_err();
	unsigned int enterSteRepinact_done();
	void leaveSteRepinact_done();

	unsigned int enterSteAuthimpex_idle();
	void leaveSteAuthimpex_idle();
	unsigned int enterSteAuthimpex_DpchAuthData();
	void leaveSteAuthimpex_DpchAuthData();
	unsigned int enterSteAuthimpex_DpchAuthDo_ButIau();
	void leaveSteAuthimpex_DpchAuthDo_ButIau();
	unsigned int enterSteAuthimpex_err();
	void leaveSteAuthimpex_err();
	unsigned int enterSteAuthimpex_done();
	void leaveSteAuthimpex_done();

	unsigned int enterSteAuthprjnew_idle();
	void leaveSteAuthprjnew_idle();
	unsigned int enterSteAuthprjnew_DpchAuthDo_ButCau();
	void leaveSteAuthprjnew_DpchAuthDo_ButCau();
	unsigned int enterSteAuthprjnew_err();
	void leaveSteAuthprjnew_err();
	unsigned int enterSteAuthprjnew_done();
	void leaveSteAuthprjnew_done();

	unsigned int enterSteAuthwrcode_idle();
	void leaveSteAuthwrcode_idle();
	unsigned int enterSteAuthwrcode_selPrj();
	void leaveSteAuthwrcode_selPrj();
	unsigned int enterSteAuthwrcode_selVer();
	void leaveSteAuthwrcode_selVer();
	unsigned int enterSteAuthwrcode_DpchAuthData();
	void leaveSteAuthwrcode_DpchAuthData();
	unsigned int enterSteAuthwrcode_DpchAuthDo_ButWau();
	void leaveSteAuthwrcode_DpchAuthDo_ButWau();
	unsigned int enterSteAuthwrcode_err();
	void leaveSteAuthwrcode_err();
	unsigned int enterSteAuthwrcode_done();
	void leaveSteAuthwrcode_done();

	unsigned int enterSteSyncprj_idle();
	void leaveSteSyncprj_idle();
	unsigned int enterSteSyncprj_DpchPrjsncData();
	void leaveSteSyncprj_DpchPrjsncData();
	unsigned int enterSteSyncprj_DpchPrjsncDo_ButSnc();
	void leaveSteSyncprj_DpchPrjsncDo_ButSnc();
	unsigned int enterSteSyncprj_err();
	void leaveSteSyncprj_err();
	unsigned int enterSteSyncprj_done();
	void leaveSteSyncprj_done();

	unsigned int enterSteSyncver_idle();
	void leaveSteSyncver_idle();
	unsigned int enterSteSyncver_selPrj();
	void leaveSteSyncver_selPrj();
	unsigned int enterSteSyncver_selVer();
	void leaveSteSyncver_selVer();
	unsigned int enterSteSyncver_DpchVersncData();
	void leaveSteSyncver_DpchVersncData();
	unsigned int enterSteSyncver_DpchVersncDo_ButSnc();
	void leaveSteSyncver_DpchVersncDo_ButSnc();
	unsigned int enterSteSyncver_err();
	void leaveSteSyncver_err();
	unsigned int enterSteSyncver_done();
	void leaveSteSyncver_done();

	unsigned int enterSteFinish_idle();
	void leaveSteFinish_idle();
	unsigned int enterSteFinish_DpchNavDo_MitSesTrm();
	void leaveSteFinish_DpchNavDo_MitSesTrm();
	unsigned int enterSteFinish_err();
	void leaveSteFinish_err();
	unsigned int enterSteFinish_done();
	void leaveSteFinish_done();

public:
	bool mergeDpchEngWzlmSdbData(CrdWzlmSdb::DpchEngData* dpcheng);
	bool mergeDpchEngWzlmSdbAuthData(PnlWzlmSdbAuth::DpchEngData* dpcheng);
	bool mergeDpchEngWzlmSdbPrjsncData(PnlWzlmSdbPrjsnc::DpchEngData* dpcheng);
	bool mergeDpchEngWzlmSdbVersncData(PnlWzlmSdbVersnc::DpchEngData* dpcheng);

	bool handleDpchEngIdle(DpchEngWzlm* _dpcheng);
	bool handleDpchEngConnect(DpchEngWzlm* _dpcheng);
	bool handleDpchEngRepact(DpchEngWzlm* _dpcheng);
	bool handleDpchEngRepinact(DpchEngWzlm* _dpcheng);
	bool handleDpchEngAuthimpex(DpchEngWzlm* _dpcheng);
	bool handleDpchEngAuthprjnew(DpchEngWzlm* _dpcheng);
	bool handleDpchEngAuthwrcode(DpchEngWzlm* _dpcheng);
	bool handleDpchEngSyncprj(DpchEngWzlm* _dpcheng);
	bool handleDpchEngSyncver(DpchEngWzlm* _dpcheng);
	bool handleDpchEngFinish(DpchEngWzlm* _dpcheng);

	void handleDpchEng(DpchEngWzlm* _dpcheng, const bool error);

	void changeWaitSte(const unsigned int ixVSteChange, const unsigned int ixVSteWait);
	void changeWaitStePre(const unsigned int ixVSteChange, const unsigned int ixVSteWait);
	void waitStePost(const unsigned int ixVSteWait, const bool waitReply);

public:
	// IP cust --- INSERT
};

/**
	* AppWzla_curlarg
	*/
struct AppWzla_curlarg {
	char* buf;
	size_t buflen;
};

#endif

