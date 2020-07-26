// IP file --- KEEP
/**
	* \file AppWzla.cpp
	* app main functionality (implementation)
	* \author Alexander Wirthmueller
	* \date created: 15 Jun 2019
	* \date modified: 15 Jun 2019
	*/

#include "AppWzla.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DOMWzla
 ******************************************************************************/

DOMWzla::DOMWzla() {
	// IP DOM.constructor --- INSERT
};

DOMWzla::~DOMWzla() {
	// IP DOM.destructor --- INSERT
};

/******************************************************************************
 class AppWzla
 ******************************************************************************/

AppWzla::AppWzla(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			cRefresh("cRefresh", "AppWzla", "AppWzla")
			, mHandleDpchEng("mHandleDpchEng", "AppWzla", "AppWzla")
			, cDpch("cDpch", "AppWzla", "AppWzla")
		{
	pthread_attr_t attr;

	ixVVerbose = VecVVerbose::DPCHMETA;

	resetStats();

	ixVSte = VecWzlaVSte::IDLE;

	stgwzlmapi = new StgWzlmapi();

	stgwzlmapi->engip = engip;
	stgwzlmapi->engport = engport;
	stgwzlmapi->username = username;
	stgwzlmapi->password = password;

	DOM = new DOMWzla();

	ixVSteRefresh = 0;
	waitReplyRefresh = false;

	dpchapp = NULL;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	// IP constructor.cust --- INSERT

	pthread_create(&dpch, &attr, &runDpch, (void*) this);

	pthread_attr_destroy(&attr);

	notify = 0;
};

AppWzla::~AppWzla() {
	if (notify != 0) {
		pthread_cancel(notify);
		pthread_join(notify, NULL);
	};

	pthread_cancel(dpch);
	pthread_join(dpch, NULL);

	// IP destructor.cust --- INSERT

	delete stgwzlmapi;

	delete DOM;

	if (dpchapp) delete dpchapp;
};

void* AppWzla::runDpch(
			void* arg
		) {
	AppWzla* inst = (AppWzla*) arg;

	CURL* curl = NULL;
	CURLcode curlres;
	curl_slist* chunk = NULL;

	AppWzla_curlarg curlarg = {.buf = NULL, .buflen = 0};

	string url = "https://" + inst->stgwzlmapi->engip + ":" + to_string(inst->stgwzlmapi->engport) + "/dpch";

	char* buf;
	char* buf_old;
	size_t buflen;

	DpchEngWzlm* dpcheng = NULL;
	uint ixWzlmVDpch = 0;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupDpch, arg);

	curl = curl_easy_init();

	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

	curl_easy_setopt(curl, CURLOPT_POST, 1);

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlarg);

	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

	curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);

	while (true) {
		inst->cDpch.lockMutex("AppWzla", "runDpch");
		if (!(inst->dpchapp)) inst->cDpch.wait("AppWzla", "runDpch");

		ApiWzlm::writeDpchApp(inst->dpchapp, &buf, buflen, 4);

		if (inst->ixVVerbose >= VecVVerbose::DPCHMETA) cout << "\tsubmitting " << VecWzlmVDpch::getSref(inst->dpchapp->ixWzlmVDpch) << "{" << inst->dpchapp->getSrefsMask() << "} (" << buflen << " bytes)" << endl;

		delete inst->dpchapp;
		inst->dpchapp = NULL;

		inst->cDpch.unlockMutex("AppWzla", "runDpch");

		dpcheng = NULL;
		ixWzlmVDpch = 0;

		if (buf) {
			if (inst->ixVVerbose >= VecVVerbose::DPCHFULL) cout << "\t" << string(&(buf[4]), buflen-4) << endl;

			// string to be sent is "xml=<xbuf>"
			buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '-';

			buf_old = buf;
			buf = curl_easy_escape(curl, buf, buflen);
			delete[] buf_old;

			buf[3] = '=';

			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);

			curlres = curl_easy_perform(curl);

			delete[] buf;

			if ((curlres == CURLE_OK) && curlarg.buf) {
				inst->nDpchApp++;
				inst->nByteToEng += buflen;

				ixWzlmVDpch = ApiWzlm::readDpchEng(curlarg.buf, curlarg.buflen, &dpcheng);

				if (dpcheng) {
					inst->nDpchEng++;
					inst->nByteFromEng += curlarg.buflen;

					if (inst->ixVVerbose >= VecVVerbose::DPCHMETA) cout << "\treceived " << VecWzlmVDpch::getSref(ixWzlmVDpch) << "{" << dpcheng->getSrefsMask() << "} (" << curlarg.buflen << " bytes)" << endl;
					if (inst->ixVVerbose >= VecVVerbose::DPCHFULL) cout << "\t" << string(curlarg.buf, curlarg.buflen) << endl;

					inst->handleDpchEng(dpcheng, false);
				};
			};
			
			if (curlarg.buf) {
				delete[] curlarg.buf;
				curlarg.buf = NULL;

				curlarg.buflen = 0;
			};
		};
	};

	curl_slist_free_all(chunk);

	curl_easy_cleanup(curl);

	pthread_cleanup_pop(0);

	return NULL;
};

void AppWzla::cleanupDpch(
			void* arg
		) {
	AppWzla* inst = (AppWzla*) arg;

	inst->cDpch.unlockMutex("AppWzla", "cleanupDpch");
};

void* AppWzla::runNotify(
			void* arg
		) {
	AppWzla* inst = (AppWzla*) arg;

	CURL* curl = NULL;
	CURLcode curlres;

	AppWzla_curlarg curlarg = {.buf = NULL, .buflen = 0};

	string url = "https://" + inst->stgwzlmapi->engip + ":" + to_string(inst->stgwzlmapi->engport) + "/notify/" + inst->DOM->scrJrefSess;

	DpchEngWzlm* dpcheng = NULL;
	uint ixWzlmVDpch = 0;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupNotify, arg);

	curl = curl_easy_init();

	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlarg);

	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);

	curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);

	while (true) {
		curlres = curl_easy_perform(curl);

		if ((curlres == CURLE_OK) && curlarg.buf) {
			ixWzlmVDpch = ApiWzlm::readDpchEng(curlarg.buf, curlarg.buflen, &dpcheng);
			if (!dpcheng) break;

			if (!dpchEngIsOfType(dpcheng, VecWzlmVDpch::DPCHENGWZLMACK, inst->DOM->scrJrefSess)) {
				inst->nDpchEngNotify++;
				inst->nByteFromEng += curlarg.buflen;

				if (inst->ixVVerbose >= VecVVerbose::DPCHMETA) cout << "\treceived/notify " << VecWzlmVDpch::getSref(ixWzlmVDpch) << "{" << dpcheng->getSrefsMask() << "} (" << curlarg.buflen << " bytes)" << endl;
				if (inst->ixVVerbose >= VecVVerbose::DPCHFULL) cout << "\t" << string(curlarg.buf, curlarg.buflen) << endl;
			};

			if (dpchEngIsOfType(dpcheng, VecWzlmVDpch::DPCHENGWZLMACK, inst->DOM->scrJrefSess)) {
				delete dpcheng;

			} else if (dpchEngIsOfType(dpcheng, VecWzlmVDpch::DPCHENGWZLMSUSPEND, inst->DOM->scrJrefSess)) {
				delete dpcheng;
				break;

			} else {
				inst->handleDpchEng(dpcheng, false);
				if (inst->DOM->scrJrefSess == "") break;
			};

			dpcheng = NULL;
		};

		if (curlarg.buf) {
			delete[] curlarg.buf;
			curlarg.buf = NULL;

			curlarg.buflen = 0;
		};
	};

	curl_easy_cleanup(curl);

	pthread_cleanup_pop(0);

	return NULL;
};

void AppWzla::cleanupNotify(
			void* arg
		) {
	// nothing to be done for now
};

uint AppWzla::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _arg
		) {
	AppWzla_curlarg* arg = (AppWzla_curlarg*) _arg;

	char* olddata;

	if (size > 0) {
		if (!arg->buf) {
			arg->buf = new char[size*blocksize];
			memcpy(arg->buf, data, size*blocksize);
			arg->buflen = size*blocksize;

		} else {
			olddata = arg->buf;

			arg->buf = new char[arg->buflen + size*blocksize];
			memcpy(arg->buf, olddata, arg->buflen);
			memcpy(&(arg->buf[arg->buflen]), data, size*blocksize);
			arg->buflen = arg->buflen + size*blocksize;

			delete[] olddata;
		};
	};

	return(size*blocksize);
};

bool AppWzla::dpchEngConfirmAccepted(
			DpchEngWzlm* dpcheng
			, const string& scrJref
			, const string& sref
		) {
	if (dpcheng->ixWzlmVDpch != VecWzlmVDpch::DPCHENGWZLMCONFIRM) return false;
	if (scrJref != "") if (dpcheng->scrJref != scrJref) return false;
	if (sref != "") if (((DpchEngWzlmConfirm*)dpcheng)->sref != sref) return false;

	return(((DpchEngWzlmConfirm*)dpcheng)->accepted);
};

bool AppWzla::dpchEngConfirmDenied(
			DpchEngWzlm* dpcheng
		) {
	if (dpcheng->ixWzlmVDpch != VecWzlmVDpch::DPCHENGWZLMCONFIRM) return false;

	return(!((DpchEngWzlmConfirm*)dpcheng)->accepted);
};

bool AppWzla::dpchEngIsOfType(
			DpchEngWzlm* dpcheng
			, const uint ixWzlmVDpch
			, const string& scrJref
		) {
	if (dpcheng->ixWzlmVDpch != ixWzlmVDpch) return false;
	if (scrJref != "") if (dpcheng->scrJref != scrJref) return false;

	return true;
};

void AppWzla::resetStats() {
	nDpchApp = 0;
	nByteToEng = 0;

	nDpchEng = 0;
	nDpchEngNotify = 0;
	nByteFromEng = 0;
};

void AppWzla::refresh() {
	if (ixVVerbose > VecVVerbose::OFF) cout << "\tcurrent state is: " << VecWzlaVSte::getSref(ixVSte) << " (" << ixVSte << ")" << endl;

	if (ixVSte == ixVSteRefresh) {
		ixVSteRefresh = 0;

		if (waitReplyRefresh) {
			waitReplyRefresh = false;

			cRefresh.signal("AppWzla", "refresh[1]");

			cRefresh.lockMutex("AppWzla", "refresh");
			cRefresh.wait("AppWzla", "refresh");
			cRefresh.unlockMutex("AppWzla", "refresh");

		} else {
			waitReplyRefresh = false;
			cRefresh.signal("AppWzla", "refresh[2]");
		};
	};
};

void AppWzla::sendDpchApp(
			DpchAppWzlm* dpchapp
		) {
	cDpch.lockMutex("AppWzla", "sendDpchApp");

	if (this->dpchapp) {
		delete dpchapp;
		return;
	};

	this->dpchapp = dpchapp;

	cDpch.unlockMutex("AppWzla", "sendDpchApp");

	cDpch.signal("AppWzla", "sendDpchApp");
};

void AppWzla::changeState(
			unsigned int _ixVSte
		) {
	while (ixVSte != _ixVSte) {
		switch (ixVSte) {
			case VecWzlaVSte::IDLE: leaveSteIdle(); break;
			case VecWzlaVSte::CONNECT_IDLE: leaveSteConnect_idle(); break;
			case VecWzlaVSte::CONNECT_DPCHLOGIN: leaveSteConnect_DpchLogin(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_SESS: leaveSteConnect_DpchInit_Sess(); break;
			case VecWzlaVSte::CONNECT_DPCHNAVDO_MITCRDSDB: leaveSteConnect_DpchNavDo_MitCrdSdb(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_CRDSDB: leaveSteConnect_DpchInit_CrdSdb(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLAUTH: leaveSteConnect_DpchInit_PnlAuth(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLPRJSNC: leaveSteConnect_DpchInit_PnlPrjsnc(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLVERSNC: leaveSteConnect_DpchInit_PnlVersnc(); break;
			case VecWzlaVSte::CONNECT_ERR: leaveSteConnect_err(); break;
			case VecWzlaVSte::CONNECT_DONE: leaveSteConnect_done(); break;
			case VecWzlaVSte::REPACT_IDLE: leaveSteRepact_idle(); break;
			case VecWzlaVSte::REPACT_DPCHHEARTBEATDO_BUTRAC: leaveSteRepact_DpchHeartbeatDo_ButRac(); break;
			case VecWzlaVSte::REPACT_ERR: leaveSteRepact_err(); break;
			case VecWzlaVSte::REPACT_DONE: leaveSteRepact_done(); break;
			case VecWzlaVSte::REPINACT_IDLE: leaveSteRepinact_idle(); break;
			case VecWzlaVSte::REPINACT_DPCHHEARTBEATDO_BUTRIN: leaveSteRepinact_DpchHeartbeatDo_ButRin(); break;
			case VecWzlaVSte::REPINACT_ERR: leaveSteRepinact_err(); break;
			case VecWzlaVSte::REPINACT_DONE: leaveSteRepinact_done(); break;
			case VecWzlaVSte::AUTHIMPEX_IDLE: leaveSteAuthimpex_idle(); break;
			case VecWzlaVSte::AUTHIMPEX_DPCHAUTHDATA: leaveSteAuthimpex_DpchAuthData(); break;
			case VecWzlaVSte::AUTHIMPEX_DPCHAUTHDO_BUTIAU: leaveSteAuthimpex_DpchAuthDo_ButIau(); break;
			case VecWzlaVSte::AUTHIMPEX_ERR: leaveSteAuthimpex_err(); break;
			case VecWzlaVSte::AUTHIMPEX_DONE: leaveSteAuthimpex_done(); break;
			case VecWzlaVSte::AUTHPRJNEW_IDLE: leaveSteAuthprjnew_idle(); break;
			case VecWzlaVSte::AUTHPRJNEW_DPCHAUTHDO_BUTCAU: leaveSteAuthprjnew_DpchAuthDo_ButCau(); break;
			case VecWzlaVSte::AUTHPRJNEW_ERR: leaveSteAuthprjnew_err(); break;
			case VecWzlaVSte::AUTHPRJNEW_DONE: leaveSteAuthprjnew_done(); break;
			case VecWzlaVSte::AUTHWRCODE_IDLE: leaveSteAuthwrcode_idle(); break;
			case VecWzlaVSte::AUTHWRCODE_SELPRJ: leaveSteAuthwrcode_selPrj(); break;
			case VecWzlaVSte::AUTHWRCODE_SELVER: leaveSteAuthwrcode_selVer(); break;
			case VecWzlaVSte::AUTHWRCODE_DPCHAUTHDATA: leaveSteAuthwrcode_DpchAuthData(); break;
			case VecWzlaVSte::AUTHWRCODE_DPCHAUTHDO_BUTWAU: leaveSteAuthwrcode_DpchAuthDo_ButWau(); break;
			case VecWzlaVSte::AUTHWRCODE_ERR: leaveSteAuthwrcode_err(); break;
			case VecWzlaVSte::AUTHWRCODE_DONE: leaveSteAuthwrcode_done(); break;
			case VecWzlaVSte::SYNCPRJ_IDLE: leaveSteSyncprj_idle(); break;
			case VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDATA: leaveSteSyncprj_DpchPrjsncData(); break;
			case VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDO_BUTSNC: leaveSteSyncprj_DpchPrjsncDo_ButSnc(); break;
			case VecWzlaVSte::SYNCPRJ_ERR: leaveSteSyncprj_err(); break;
			case VecWzlaVSte::SYNCPRJ_DONE: leaveSteSyncprj_done(); break;
			case VecWzlaVSte::SYNCVER_IDLE: leaveSteSyncver_idle(); break;
			case VecWzlaVSte::SYNCVER_SELPRJ: leaveSteSyncver_selPrj(); break;
			case VecWzlaVSte::SYNCVER_SELVER: leaveSteSyncver_selVer(); break;
			case VecWzlaVSte::SYNCVER_DPCHVERSNCDATA: leaveSteSyncver_DpchVersncData(); break;
			case VecWzlaVSte::SYNCVER_DPCHVERSNCDO_BUTSNC: leaveSteSyncver_DpchVersncDo_ButSnc(); break;
			case VecWzlaVSte::SYNCVER_ERR: leaveSteSyncver_err(); break;
			case VecWzlaVSte::SYNCVER_DONE: leaveSteSyncver_done(); break;
			case VecWzlaVSte::FINISH_IDLE: leaveSteFinish_idle(); break;
			case VecWzlaVSte::FINISH_DPCHNAVDO_MITSESTRM: leaveSteFinish_DpchNavDo_MitSesTrm(); break;
			case VecWzlaVSte::FINISH_ERR: leaveSteFinish_err(); break;
			case VecWzlaVSte::FINISH_DONE: leaveSteFinish_done(); break;
		};

		ixVSte = _ixVSte;
		refresh();

		switch (_ixVSte) {
			case VecWzlaVSte::IDLE: _ixVSte = enterSteIdle(); break;
			case VecWzlaVSte::CONNECT_IDLE: _ixVSte = enterSteConnect_idle(); break;
			case VecWzlaVSte::CONNECT_DPCHLOGIN: _ixVSte = enterSteConnect_DpchLogin(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_SESS: _ixVSte = enterSteConnect_DpchInit_Sess(); break;
			case VecWzlaVSte::CONNECT_DPCHNAVDO_MITCRDSDB: _ixVSte = enterSteConnect_DpchNavDo_MitCrdSdb(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_CRDSDB: _ixVSte = enterSteConnect_DpchInit_CrdSdb(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLAUTH: _ixVSte = enterSteConnect_DpchInit_PnlAuth(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLPRJSNC: _ixVSte = enterSteConnect_DpchInit_PnlPrjsnc(); break;
			case VecWzlaVSte::CONNECT_DPCHINIT_PNLVERSNC: _ixVSte = enterSteConnect_DpchInit_PnlVersnc(); break;
			case VecWzlaVSte::CONNECT_ERR: _ixVSte = enterSteConnect_err(); break;
			case VecWzlaVSte::CONNECT_DONE: _ixVSte = enterSteConnect_done(); break;
			case VecWzlaVSte::REPACT_IDLE: _ixVSte = enterSteRepact_idle(); break;
			case VecWzlaVSte::REPACT_DPCHHEARTBEATDO_BUTRAC: _ixVSte = enterSteRepact_DpchHeartbeatDo_ButRac(); break;
			case VecWzlaVSte::REPACT_ERR: _ixVSte = enterSteRepact_err(); break;
			case VecWzlaVSte::REPACT_DONE: _ixVSte = enterSteRepact_done(); break;
			case VecWzlaVSte::REPINACT_IDLE: _ixVSte = enterSteRepinact_idle(); break;
			case VecWzlaVSte::REPINACT_DPCHHEARTBEATDO_BUTRIN: _ixVSte = enterSteRepinact_DpchHeartbeatDo_ButRin(); break;
			case VecWzlaVSte::REPINACT_ERR: _ixVSte = enterSteRepinact_err(); break;
			case VecWzlaVSte::REPINACT_DONE: _ixVSte = enterSteRepinact_done(); break;
			case VecWzlaVSte::AUTHIMPEX_IDLE: _ixVSte = enterSteAuthimpex_idle(); break;
			case VecWzlaVSte::AUTHIMPEX_DPCHAUTHDATA: _ixVSte = enterSteAuthimpex_DpchAuthData(); break;
			case VecWzlaVSte::AUTHIMPEX_DPCHAUTHDO_BUTIAU: _ixVSte = enterSteAuthimpex_DpchAuthDo_ButIau(); break;
			case VecWzlaVSte::AUTHIMPEX_ERR: _ixVSte = enterSteAuthimpex_err(); break;
			case VecWzlaVSte::AUTHIMPEX_DONE: _ixVSte = enterSteAuthimpex_done(); break;
			case VecWzlaVSte::AUTHPRJNEW_IDLE: _ixVSte = enterSteAuthprjnew_idle(); break;
			case VecWzlaVSte::AUTHPRJNEW_DPCHAUTHDO_BUTCAU: _ixVSte = enterSteAuthprjnew_DpchAuthDo_ButCau(); break;
			case VecWzlaVSte::AUTHPRJNEW_ERR: _ixVSte = enterSteAuthprjnew_err(); break;
			case VecWzlaVSte::AUTHPRJNEW_DONE: _ixVSte = enterSteAuthprjnew_done(); break;
			case VecWzlaVSte::AUTHWRCODE_IDLE: _ixVSte = enterSteAuthwrcode_idle(); break;
			case VecWzlaVSte::AUTHWRCODE_SELPRJ: _ixVSte = enterSteAuthwrcode_selPrj(); break;
			case VecWzlaVSte::AUTHWRCODE_SELVER: _ixVSte = enterSteAuthwrcode_selVer(); break;
			case VecWzlaVSte::AUTHWRCODE_DPCHAUTHDATA: _ixVSte = enterSteAuthwrcode_DpchAuthData(); break;
			case VecWzlaVSte::AUTHWRCODE_DPCHAUTHDO_BUTWAU: _ixVSte = enterSteAuthwrcode_DpchAuthDo_ButWau(); break;
			case VecWzlaVSte::AUTHWRCODE_ERR: _ixVSte = enterSteAuthwrcode_err(); break;
			case VecWzlaVSte::AUTHWRCODE_DONE: _ixVSte = enterSteAuthwrcode_done(); break;
			case VecWzlaVSte::SYNCPRJ_IDLE: _ixVSte = enterSteSyncprj_idle(); break;
			case VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDATA: _ixVSte = enterSteSyncprj_DpchPrjsncData(); break;
			case VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDO_BUTSNC: _ixVSte = enterSteSyncprj_DpchPrjsncDo_ButSnc(); break;
			case VecWzlaVSte::SYNCPRJ_ERR: _ixVSte = enterSteSyncprj_err(); break;
			case VecWzlaVSte::SYNCPRJ_DONE: _ixVSte = enterSteSyncprj_done(); break;
			case VecWzlaVSte::SYNCVER_IDLE: _ixVSte = enterSteSyncver_idle(); break;
			case VecWzlaVSte::SYNCVER_SELPRJ: _ixVSte = enterSteSyncver_selPrj(); break;
			case VecWzlaVSte::SYNCVER_SELVER: _ixVSte = enterSteSyncver_selVer(); break;
			case VecWzlaVSte::SYNCVER_DPCHVERSNCDATA: _ixVSte = enterSteSyncver_DpchVersncData(); break;
			case VecWzlaVSte::SYNCVER_DPCHVERSNCDO_BUTSNC: _ixVSte = enterSteSyncver_DpchVersncDo_ButSnc(); break;
			case VecWzlaVSte::SYNCVER_ERR: _ixVSte = enterSteSyncver_err(); break;
			case VecWzlaVSte::SYNCVER_DONE: _ixVSte = enterSteSyncver_done(); break;
			case VecWzlaVSte::FINISH_IDLE: _ixVSte = enterSteFinish_idle(); break;
			case VecWzlaVSte::FINISH_DPCHNAVDO_MITSESTRM: _ixVSte = enterSteFinish_DpchNavDo_MitSesTrm(); break;
			case VecWzlaVSte::FINISH_ERR: _ixVSte = enterSteFinish_err(); break;
			case VecWzlaVSte::FINISH_DONE: _ixVSte = enterSteFinish_done(); break;
		};

		if (_ixVSte == 0) break;
	};
};

unsigned int AppWzla::enterSteIdle() {
	unsigned int retval = 0;
	// IP enterSteIdle --- INSERT
	return retval;
};

void AppWzla::leaveSteIdle() {
	// IP leaveSteIdle --- INSERT
};

unsigned int AppWzla::enterSteConnect_idle() {
	unsigned int retval = 0;
	// IP enterSteConnect_idle --- INSERT
	return retval;
};

void AppWzla::leaveSteConnect_idle() {
	// IP leaveSteConnect_idle --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchLogin() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchLogin --- BEGIN
	sendDpchApp(new RootWzlm::DpchAppLogin("", stgwzlmapi->username, stgwzlmapi->password, false, false, {RootWzlm::DpchAppLogin::ALL}));
	// IP enterSteConnect_DpchLogin --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchLogin() {
	// IP leaveSteConnect_DpchLogin --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchInit_Sess() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchInit_Sess --- BEGIN
	sendDpchApp(new DpchAppWzlmInit(DOM->scrJrefSess));
	// IP enterSteConnect_DpchInit_Sess --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchInit_Sess() {
	// IP leaveSteConnect_DpchInit_Sess --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchNavDo_MitCrdSdb() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchNavDo_MitCrdSdb --- BEGIN
	sendDpchApp(new CrdWzlmNav::DpchAppDo(DOM->scrJrefCrdNav, CrdWzlmNav::VecVDo::MITCRDSDBCLICK, {CrdWzlmNav::DpchAppDo::ALL}));
	// IP enterSteConnect_DpchNavDo_MitCrdSdb --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchNavDo_MitCrdSdb() {
	// IP leaveSteConnect_DpchNavDo_MitCrdSdb --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchInit_CrdSdb() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchInit_CrdSdb --- BEGIN
	sendDpchApp(new DpchAppWzlmInit(DOM->scrJrefCrdSdb));
	// IP enterSteConnect_DpchInit_CrdSdb --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchInit_CrdSdb() {
	// IP leaveSteConnect_DpchInit_CrdSdb --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchInit_PnlAuth() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchInit_PnlAuth --- BEGIN
	sendDpchApp(new DpchAppWzlmInit(DOM->CrdSdb_statshr.scrJrefAuth));
	// IP enterSteConnect_DpchInit_PnlAuth --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchInit_PnlAuth() {
	// IP leaveSteConnect_DpchInit_PnlAuth --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchInit_PnlPrjsnc() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchInit_PnlPrjsnc --- BEGIN
	sendDpchApp(new DpchAppWzlmInit(DOM->CrdSdb_statshr.scrJrefPrjsnc));
	// IP enterSteConnect_DpchInit_PnlPrjsnc --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchInit_PnlPrjsnc() {
	// IP leaveSteConnect_DpchInit_PnlPrjsnc --- INSERT
};

unsigned int AppWzla::enterSteConnect_DpchInit_PnlVersnc() {
	unsigned int retval = 0;
	// IP enterSteConnect_DpchInit_PnlVersnc --- BEGIN
	sendDpchApp(new DpchAppWzlmInit(DOM->CrdSdb_statshr.scrJrefVersnc));
	// IP enterSteConnect_DpchInit_PnlVersnc --- END
	return retval;
};

void AppWzla::leaveSteConnect_DpchInit_PnlVersnc() {
	// IP leaveSteConnect_DpchInit_PnlVersnc --- INSERT
};

unsigned int AppWzla::enterSteConnect_err() {
	unsigned int retval = 0;
	// IP enterSteConnect_err --- INSERT
	return retval;
};

void AppWzla::leaveSteConnect_err() {
	// IP leaveSteConnect_err --- INSERT
};

unsigned int AppWzla::enterSteConnect_done() {
	unsigned int retval = 0;
	// IP enterSteConnect_done --- INSERT
	return retval;
};

void AppWzla::leaveSteConnect_done() {
	// IP leaveSteConnect_done --- INSERT
};

unsigned int AppWzla::enterSteRepact_idle() {
	unsigned int retval = 0;
	// IP enterSteRepact_idle --- BEGIN
	retval = VecWzlaVSte::REPACT_DPCHHEARTBEATDO_BUTRAC;
	// IP enterSteRepact_idle --- END
	return retval;
};

void AppWzla::leaveSteRepact_idle() {
	// IP leaveSteRepact_idle --- INSERT
};

unsigned int AppWzla::enterSteRepact_DpchHeartbeatDo_ButRac() {
	unsigned int retval = 0;
	// IP enterSteRepact_DpchHeartbeatDo_ButRac --- BEGIN
	sendDpchApp(new PnlWzlmSdbHeartbeat::DpchAppDo(DOM->CrdSdb_statshr.scrJrefHeartbeat, PnlWzlmSdbHeartbeat::VecVDo::BUTRACCLICK, {PnlWzlmSdbHeartbeat::DpchAppDo::ALL}));
	// IP enterSteRepact_DpchHeartbeatDo_ButRac --- END
	return retval;
};

void AppWzla::leaveSteRepact_DpchHeartbeatDo_ButRac() {
	// IP leaveSteRepact_DpchHeartbeatDo_ButRac --- INSERT
};

unsigned int AppWzla::enterSteRepact_err() {
	unsigned int retval = 0;
	// IP enterSteRepact_err --- INSERT
	return retval;
};

void AppWzla::leaveSteRepact_err() {
	// IP leaveSteRepact_err --- INSERT
};

unsigned int AppWzla::enterSteRepact_done() {
	unsigned int retval = 0;
	// IP enterSteRepact_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteRepact_done --- END
	return retval;
};

void AppWzla::leaveSteRepact_done() {
	// IP leaveSteRepact_done --- INSERT
};

unsigned int AppWzla::enterSteRepinact_idle() {
	unsigned int retval = 0;
	// IP enterSteRepinact_idle --- BEGIN
	retval = VecWzlaVSte::REPINACT_DPCHHEARTBEATDO_BUTRIN;
	// IP enterSteRepinact_idle --- END
	return retval;
};

void AppWzla::leaveSteRepinact_idle() {
	// IP leaveSteRepinact_idle --- INSERT
};

unsigned int AppWzla::enterSteRepinact_DpchHeartbeatDo_ButRin() {
	unsigned int retval = 0;
	// IP enterSteRepinact_DpchHeartbeatDo_ButRin --- BEGIN
	sendDpchApp(new PnlWzlmSdbHeartbeat::DpchAppDo(DOM->CrdSdb_statshr.scrJrefHeartbeat, PnlWzlmSdbHeartbeat::VecVDo::BUTRINCLICK, {PnlWzlmSdbHeartbeat::DpchAppDo::ALL}));
	// IP enterSteRepinact_DpchHeartbeatDo_ButRin --- END
	return retval;
};

void AppWzla::leaveSteRepinact_DpchHeartbeatDo_ButRin() {
	// IP leaveSteRepinact_DpchHeartbeatDo_ButRin --- INSERT
};

unsigned int AppWzla::enterSteRepinact_err() {
	unsigned int retval = 0;
	// IP enterSteRepinact_err --- INSERT
	return retval;
};

void AppWzla::leaveSteRepinact_err() {
	// IP leaveSteRepinact_err --- INSERT
};

unsigned int AppWzla::enterSteRepinact_done() {
	unsigned int retval = 0;
	// IP enterSteRepinact_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteRepinact_done --- END
	return retval;
};

void AppWzla::leaveSteRepinact_done() {
	// IP leaveSteRepinact_done --- INSERT
};

unsigned int AppWzla::enterSteAuthimpex_idle() {
	unsigned int retval = 0;
	// IP enterSteAuthimpex_idle --- BEGIN
	retval = VecWzlaVSte::AUTHIMPEX_DPCHAUTHDATA;
	// IP enterSteAuthimpex_idle --- END
	return retval;
};

void AppWzla::leaveSteAuthimpex_idle() {
	// IP leaveSteAuthimpex_idle --- INSERT
};

unsigned int AppWzla::enterSteAuthimpex_DpchAuthData() {
	unsigned int retval = 0;
	// IP enterSteAuthimpex_DpchAuthData --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthimpex_DpchAuthData() {
	// IP leaveSteAuthimpex_DpchAuthData --- INSERT
};

unsigned int AppWzla::enterSteAuthimpex_DpchAuthDo_ButIau() {
	unsigned int retval = 0;
	// IP enterSteAuthimpex_DpchAuthDo_ButIau --- BEGIN
	sendDpchApp(new PnlWzlmSdbAuth::DpchAppDo(DOM->CrdSdb_statshr.scrJrefAuth, PnlWzlmSdbAuth::VecVDo::BUTIAUCLICK, {PnlWzlmSdbAuth::DpchAppDo::ALL}));
	// IP enterSteAuthimpex_DpchAuthDo_ButIau --- END
	return retval;
};

void AppWzla::leaveSteAuthimpex_DpchAuthDo_ButIau() {
	// IP leaveSteAuthimpex_DpchAuthDo_ButIau --- INSERT
};

unsigned int AppWzla::enterSteAuthimpex_err() {
	unsigned int retval = 0;
	// IP enterSteAuthimpex_err --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthimpex_err() {
	// IP leaveSteAuthimpex_err --- INSERT
};

unsigned int AppWzla::enterSteAuthimpex_done() {
	unsigned int retval = 0;
	// IP enterSteAuthimpex_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteAuthimpex_done --- END
	return retval;
};

void AppWzla::leaveSteAuthimpex_done() {
	// IP leaveSteAuthimpex_done --- INSERT
};

unsigned int AppWzla::enterSteAuthprjnew_idle() {
	unsigned int retval = 0;
	// IP enterSteAuthprjnew_idle --- BEGIN
	retval = VecWzlaVSte::AUTHPRJNEW_DPCHAUTHDO_BUTCAU;
	// IP enterSteAuthprjnew_idle --- END
	return retval;
};

void AppWzla::leaveSteAuthprjnew_idle() {
	// IP leaveSteAuthprjnew_idle --- INSERT
};

unsigned int AppWzla::enterSteAuthprjnew_DpchAuthDo_ButCau() {
	unsigned int retval = 0;
	// IP enterSteAuthprjnew_DpchAuthDo_ButCau --- BEGIN
	sendDpchApp(new PnlWzlmSdbAuth::DpchAppDo(DOM->CrdSdb_statshr.scrJrefAuth, PnlWzlmSdbAuth::VecVDo::BUTCAUCLICK, {PnlWzlmSdbAuth::DpchAppDo::ALL}));
	// IP enterSteAuthprjnew_DpchAuthDo_ButCau --- END
	return retval;
};

void AppWzla::leaveSteAuthprjnew_DpchAuthDo_ButCau() {
	// IP leaveSteAuthprjnew_DpchAuthDo_ButCau --- INSERT
};

unsigned int AppWzla::enterSteAuthprjnew_err() {
	unsigned int retval = 0;
	// IP enterSteAuthprjnew_err --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthprjnew_err() {
	// IP leaveSteAuthprjnew_err --- INSERT
};

unsigned int AppWzla::enterSteAuthprjnew_done() {
	unsigned int retval = 0;
	// IP enterSteAuthprjnew_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteAuthprjnew_done --- END
	return retval;
};

void AppWzla::leaveSteAuthprjnew_done() {
	// IP leaveSteAuthprjnew_done --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_idle() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_idle --- BEGIN
	retval = VecWzlaVSte::AUTHWRCODE_SELPRJ;
	// IP enterSteAuthwrcode_idle --- END
	return retval;
};

void AppWzla::leaveSteAuthwrcode_idle() {
	// IP leaveSteAuthwrcode_idle --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_selPrj() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_selPrj --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthwrcode_selPrj() {
	// IP leaveSteAuthwrcode_selPrj --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_selVer() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_selVer --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthwrcode_selVer() {
	// IP leaveSteAuthwrcode_selVer --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_DpchAuthData() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_DpchAuthData --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthwrcode_DpchAuthData() {
	// IP leaveSteAuthwrcode_DpchAuthData --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_DpchAuthDo_ButWau() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_DpchAuthDo_ButWau --- BEGIN
	sendDpchApp(new PnlWzlmSdbAuth::DpchAppDo(DOM->CrdSdb_statshr.scrJrefAuth, PnlWzlmSdbAuth::VecVDo::BUTWAUCLICK, {PnlWzlmSdbAuth::DpchAppDo::ALL}));
	// IP enterSteAuthwrcode_DpchAuthDo_ButWau --- END
	return retval;
};

void AppWzla::leaveSteAuthwrcode_DpchAuthDo_ButWau() {
	// IP leaveSteAuthwrcode_DpchAuthDo_ButWau --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_err() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_err --- INSERT
	return retval;
};

void AppWzla::leaveSteAuthwrcode_err() {
	// IP leaveSteAuthwrcode_err --- INSERT
};

unsigned int AppWzla::enterSteAuthwrcode_done() {
	unsigned int retval = 0;
	// IP enterSteAuthwrcode_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteAuthwrcode_done --- END
	return retval;
};

void AppWzla::leaveSteAuthwrcode_done() {
	// IP leaveSteAuthwrcode_done --- INSERT
};

unsigned int AppWzla::enterSteSyncprj_idle() {
	unsigned int retval = 0;
	// IP enterSteSyncprj_idle --- BEGIN
	retval = VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDATA;
	// IP enterSteSyncprj_idle --- END
	return retval;
};

void AppWzla::leaveSteSyncprj_idle() {
	// IP leaveSteSyncprj_idle --- INSERT
};

unsigned int AppWzla::enterSteSyncprj_DpchPrjsncData() {
	unsigned int retval = 0;
	// IP enterSteSyncprj_DpchPrjsncData --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncprj_DpchPrjsncData() {
	// IP leaveSteSyncprj_DpchPrjsncData --- INSERT
};

unsigned int AppWzla::enterSteSyncprj_DpchPrjsncDo_ButSnc() {
	unsigned int retval = 0;
	// IP enterSteSyncprj_DpchPrjsncDo_ButSnc --- BEGIN
	sendDpchApp(new PnlWzlmSdbPrjsnc::DpchAppDo(DOM->CrdSdb_statshr.scrJrefPrjsnc, PnlWzlmSdbPrjsnc::VecVDo::BUTSNCCLICK, {PnlWzlmSdbPrjsnc::DpchAppDo::ALL}));
	// IP enterSteSyncprj_DpchPrjsncDo_ButSnc --- END
	return retval;
};

void AppWzla::leaveSteSyncprj_DpchPrjsncDo_ButSnc() {
	// IP leaveSteSyncprj_DpchPrjsncDo_ButSnc --- INSERT
};

unsigned int AppWzla::enterSteSyncprj_err() {
	unsigned int retval = 0;
	// IP enterSteSyncprj_err --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncprj_err() {
	// IP leaveSteSyncprj_err --- INSERT
};

unsigned int AppWzla::enterSteSyncprj_done() {
	unsigned int retval = 0;
	// IP enterSteSyncprj_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteSyncprj_done --- END
	return retval;
};

void AppWzla::leaveSteSyncprj_done() {
	// IP leaveSteSyncprj_done --- INSERT
};

unsigned int AppWzla::enterSteSyncver_idle() {
	unsigned int retval = 0;
	// IP enterSteSyncver_idle --- BEGIN
	retval = VecWzlaVSte::SYNCVER_SELPRJ;
	// IP enterSteSyncver_idle --- END
	return retval;
};

void AppWzla::leaveSteSyncver_idle() {
	// IP leaveSteSyncver_idle --- INSERT
};

unsigned int AppWzla::enterSteSyncver_selPrj() {
	unsigned int retval = 0;
	// IP enterSteSyncver_selPrj --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncver_selPrj() {
	// IP leaveSteSyncver_selPrj --- INSERT
};

unsigned int AppWzla::enterSteSyncver_selVer() {
	unsigned int retval = 0;
	// IP enterSteSyncver_selVer --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncver_selVer() {
	// IP leaveSteSyncver_selVer --- INSERT
};

unsigned int AppWzla::enterSteSyncver_DpchVersncData() {
	unsigned int retval = 0;
	// IP enterSteSyncver_DpchVersncData --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncver_DpchVersncData() {
	// IP leaveSteSyncver_DpchVersncData --- INSERT
};

unsigned int AppWzla::enterSteSyncver_DpchVersncDo_ButSnc() {
	unsigned int retval = 0;
	// IP enterSteSyncver_DpchVersncDo_ButSnc --- BEGIN
	sendDpchApp(new PnlWzlmSdbVersnc::DpchAppDo(DOM->CrdSdb_statshr.scrJrefVersnc, PnlWzlmSdbVersnc::VecVDo::BUTSNCCLICK, {PnlWzlmSdbVersnc::DpchAppDo::ALL}));
	// IP enterSteSyncver_DpchVersncDo_ButSnc --- END
	return retval;
};

void AppWzla::leaveSteSyncver_DpchVersncDo_ButSnc() {
	// IP leaveSteSyncver_DpchVersncDo_ButSnc --- INSERT
};

unsigned int AppWzla::enterSteSyncver_err() {
	unsigned int retval = 0;
	// IP enterSteSyncver_err --- INSERT
	return retval;
};

void AppWzla::leaveSteSyncver_err() {
	// IP leaveSteSyncver_err --- INSERT
};

unsigned int AppWzla::enterSteSyncver_done() {
	unsigned int retval = 0;
	// IP enterSteSyncver_done --- BEGIN
	retval = VecWzlaVSte::CONNECT_DONE;
	// IP enterSteSyncver_done --- END
	return retval;
};

void AppWzla::leaveSteSyncver_done() {
	// IP leaveSteSyncver_done --- INSERT
};

unsigned int AppWzla::enterSteFinish_idle() {
	unsigned int retval = 0;
	// IP enterSteFinish_idle --- BEGIN
	retval = VecWzlaVSte::FINISH_DPCHNAVDO_MITSESTRM;
	// IP enterSteFinish_idle --- END
	return retval;
};

void AppWzla::leaveSteFinish_idle() {
	// IP leaveSteFinish_idle --- INSERT
};

unsigned int AppWzla::enterSteFinish_DpchNavDo_MitSesTrm() {
	unsigned int retval = 0;
	// IP enterSteFinish_DpchNavDo_MitSesTrm --- BEGIN
	sendDpchApp(new CrdWzlmNav::DpchAppDo(DOM->scrJrefCrdNav, CrdWzlmNav::VecVDo::MITSESTRMCLICK, {CrdWzlmNav::DpchAppDo::ALL}));
	// IP enterSteFinish_DpchNavDo_MitSesTrm --- END
	return retval;
};

void AppWzla::leaveSteFinish_DpchNavDo_MitSesTrm() {
	// IP leaveSteFinish_DpchNavDo_MitSesTrm --- INSERT
};

unsigned int AppWzla::enterSteFinish_err() {
	unsigned int retval = 0;
	// IP enterSteFinish_err --- INSERT
	return retval;
};

void AppWzla::leaveSteFinish_err() {
	// IP leaveSteFinish_err --- INSERT
};

unsigned int AppWzla::enterSteFinish_done() {
	unsigned int retval = 0;
	// IP enterSteFinish_done --- BEGIN
	retval = VecWzlaVSte::IDLE;
	// IP enterSteFinish_done --- END
	return retval;
};

void AppWzla::leaveSteFinish_done() {
	// IP leaveSteFinish_done --- INSERT
};

bool AppWzla::mergeDpchEngWzlmSdbData(
			CrdWzlmSdb::DpchEngData* dpcheng
		) {
	if (dpcheng->has(CrdWzlmSdb::DpchEngData::STATSHR)) DOM->CrdSdb_statshr = dpcheng->statshr;

	return(dpcheng->hasAny({CrdWzlmSdb::DpchEngData::STATSHR}));
};

bool AppWzla::mergeDpchEngWzlmSdbAuthData(
			PnlWzlmSdbAuth::DpchEngData* dpcheng
		) {
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::CONTIAC)) DOM->PnlAuth_contiac = dpcheng->contiac;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::CONTINF)) DOM->PnlAuth_continf = dpcheng->continf;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::FEEDFLSTWSF)) DOM->PnlAuth_feedflstwsf = dpcheng->feedFLstWsf;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWCT)) DOM->PnlAuth_feedfpupwct = dpcheng->feedFPupWct;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWPR)) DOM->PnlAuth_feedfpupwpr = dpcheng->feedFPupWpr;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWVE)) DOM->PnlAuth_feedfpupwve = dpcheng->feedFPupWve;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::FEEDFSGE)) DOM->PnlAuth_feedfsge = dpcheng->feedFSge;
	if (dpcheng->has(PnlWzlmSdbAuth::DpchEngData::STATSHR)) DOM->PnlAuth_statshr = dpcheng->statshr;

	return(dpcheng->hasAny({PnlWzlmSdbAuth::DpchEngData::CONTIAC,PnlWzlmSdbAuth::DpchEngData::CONTINF,PnlWzlmSdbAuth::DpchEngData::FEEDFLSTWSF,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWCT,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWPR,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWVE,PnlWzlmSdbAuth::DpchEngData::FEEDFSGE,PnlWzlmSdbAuth::DpchEngData::STATSHR}));
};

bool AppWzla::mergeDpchEngWzlmSdbPrjsncData(
			PnlWzlmSdbPrjsnc::DpchEngData* dpcheng
		) {
	if (dpcheng->has(PnlWzlmSdbPrjsnc::DpchEngData::CONTIAC)) DOM->PnlPrjsnc_contiac = dpcheng->contiac;
	if (dpcheng->has(PnlWzlmSdbPrjsnc::DpchEngData::STATSHR)) DOM->PnlPrjsnc_statshr = dpcheng->statshr;

	return(dpcheng->hasAny({PnlWzlmSdbPrjsnc::DpchEngData::CONTIAC,PnlWzlmSdbPrjsnc::DpchEngData::STATSHR}));
};

bool AppWzla::mergeDpchEngWzlmSdbVersncData(
			PnlWzlmSdbVersnc::DpchEngData* dpcheng
		) {
	if (dpcheng->has(PnlWzlmSdbVersnc::DpchEngData::CONTIAC)) DOM->PnlVersnc_contiac = dpcheng->contiac;
	if (dpcheng->has(PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPPRJ)) DOM->PnlVersnc_feedfpupprj = dpcheng->feedFPupPrj;
	if (dpcheng->has(PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPVER)) DOM->PnlVersnc_feedfpupver = dpcheng->feedFPupVer;
	if (dpcheng->has(PnlWzlmSdbVersnc::DpchEngData::STATSHR)) DOM->PnlVersnc_statshr = dpcheng->statshr;

	return(dpcheng->hasAny({PnlWzlmSdbVersnc::DpchEngData::CONTIAC,PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPPRJ,PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPVER,PnlWzlmSdbVersnc::DpchEngData::STATSHR}));
};

bool AppWzla::handleDpchEngIdle(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngConnect(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::CONNECT_DPCHLOGIN) {
		if (dpchEngConfirmAccepted(_dpcheng, "", "")) {
			DOM->scrJrefSess = _dpcheng->scrJref;
			// IP handleDpchEngConnect.connect.DpchLogin1 --- INSERT
			changeState(VecWzlaVSte::CONNECT_DPCHINIT_SESS);
		} else if (dpchEngConfirmDenied(_dpcheng)) {
			// IP handleDpchEngConnect.connect.DpchLogin2 --- INSERT
			changeState(VecWzlaVSte::CONNECT_ERR);
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHINIT_SESS) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGSESSWZLMDATA, DOM->scrJrefSess)) {
			if (_dpcheng->hasAll({SessWzlm::DpchEngData::STATSHR})) {
			// IP handleDpchEngConnect.connect.DpchInit.Sess1 --- INSERT
				changeState(VecWzlaVSte::CONNECT_DONE);
			};
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHNAVDO_MITCRDSDB) {
		if (dpchEngConfirmAccepted(_dpcheng, "", "CrdWzlmSdb")) {
			DOM->scrJrefCrdSdb = _dpcheng->scrJref;
			changeState(VecWzlaVSte::CONNECT_DPCHINIT_CRDSDB);
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHINIT_CRDSDB) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBDATA, DOM->scrJrefCrdSdb)) {
			if (_dpcheng->hasAll({CrdWzlmSdb::DpchEngData::STATSHR}))
					changeState(VecWzlaVSte::CONNECT_DPCHINIT_PNLAUTH);
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHINIT_PNLAUTH) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC,PnlWzlmSdbAuth::DpchEngData::CONTINF,PnlWzlmSdbAuth::DpchEngData::STATSHR,PnlWzlmSdbAuth::DpchEngData::FEEDFLSTWSF,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWCT,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWPR,PnlWzlmSdbAuth::DpchEngData::FEEDFPUPWVE,PnlWzlmSdbAuth::DpchEngData::FEEDFSGE}))
					changeState(VecWzlaVSte::CONNECT_DPCHINIT_PNLPRJSNC);
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHINIT_PNLPRJSNC) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBPRJSNCDATA, DOM->CrdSdb_statshr.scrJrefPrjsnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbPrjsnc::DpchEngData::CONTIAC,PnlWzlmSdbPrjsnc::DpchEngData::STATSHR}))
					changeState(VecWzlaVSte::CONNECT_DPCHINIT_PNLVERSNC);
		};

	} else if (ixVSte == VecWzlaVSte::CONNECT_DPCHINIT_PNLVERSNC) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbVersnc::DpchEngData::CONTIAC,PnlWzlmSdbVersnc::DpchEngData::STATSHR,PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPPRJ,PnlWzlmSdbVersnc::DpchEngData::FEEDFPUPVER}))
					changeState(VecWzlaVSte::CONNECT_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngRepact(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::REPACT_DPCHHEARTBEATDO_BUTRAC) {
		if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefHeartbeat, "")) {
			changeState(VecWzlaVSte::REPACT_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngRepinact(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::REPINACT_DPCHHEARTBEATDO_BUTRIN) {
		if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefHeartbeat, "")) {
			changeState(VecWzlaVSte::REPINACT_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngAuthimpex(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::AUTHIMPEX_DPCHAUTHDATA) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHIMPEX_DPCHAUTHDO_BUTIAU);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefAuth, "")) {
			changeState(VecWzlaVSte::AUTHIMPEX_DPCHAUTHDO_BUTIAU);
		};

	} else if (ixVSte == VecWzlaVSte::AUTHIMPEX_DPCHAUTHDO_BUTIAU) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHIMPEX_DONE);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefAuth, "")) {
			changeState(VecWzlaVSte::AUTHIMPEX_DONE);
		} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMALERT, DOM->CrdSdb_statshr.scrJrefAuth)) {
			// IP handleDpchEngAuthimpex.authimpex.DpchAuthDo.ButIau3 --- INSERT
			changeState(VecWzlaVSte::AUTHIMPEX_ERR);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngAuthprjnew(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::AUTHPRJNEW_DPCHAUTHDO_BUTCAU) {
		if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefAuth, "")) {
			changeState(VecWzlaVSte::AUTHPRJNEW_DONE);
		} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMALERT, DOM->CrdSdb_statshr.scrJrefAuth)) {
			// IP handleDpchEngAuthprjnew.authprjnew.DpchAuthDo.ButCau2 --- INSERT
			changeState(VecWzlaVSte::AUTHPRJNEW_ERR);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngAuthwrcode(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::AUTHWRCODE_SELPRJ) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHWRCODE_SELVER);
		};

	} else if (ixVSte == VecWzlaVSte::AUTHWRCODE_SELVER) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHWRCODE_DPCHAUTHDATA);
		};

	} else if (ixVSte == VecWzlaVSte::AUTHWRCODE_DPCHAUTHDATA) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHWRCODE_DPCHAUTHDO_BUTWAU);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefAuth, "")) {
			changeState(VecWzlaVSte::AUTHWRCODE_DPCHAUTHDO_BUTWAU);
		};

	} else if (ixVSte == VecWzlaVSte::AUTHWRCODE_DPCHAUTHDO_BUTWAU) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
			if (_dpcheng->hasAll({PnlWzlmSdbAuth::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::AUTHWRCODE_DONE);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefAuth, "")) {
			changeState(VecWzlaVSte::AUTHWRCODE_DONE);
		} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMALERT, DOM->CrdSdb_statshr.scrJrefAuth)) {
			// IP handleDpchEngAuthwrcode.authwrcode.DpchAuthDo.ButWau3 --- INSERT
			changeState(VecWzlaVSte::AUTHWRCODE_ERR);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngSyncprj(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDATA) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBPRJSNCDATA, DOM->CrdSdb_statshr.scrJrefPrjsnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbPrjsnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDO_BUTSNC);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefPrjsnc, "")) {
			changeState(VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDO_BUTSNC);
		};

	} else if (ixVSte == VecWzlaVSte::SYNCPRJ_DPCHPRJSNCDO_BUTSNC) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBPRJSNCDATA, DOM->CrdSdb_statshr.scrJrefPrjsnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbPrjsnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCPRJ_DONE);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefPrjsnc, "")) {
			changeState(VecWzlaVSte::SYNCPRJ_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngSyncver(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::SYNCVER_SELPRJ) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbVersnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCVER_SELVER);
		};

	} else if (ixVSte == VecWzlaVSte::SYNCVER_SELVER) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbVersnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCVER_DPCHVERSNCDATA);
		};

	} else if (ixVSte == VecWzlaVSte::SYNCVER_DPCHVERSNCDATA) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbVersnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCVER_DPCHVERSNCDO_BUTSNC);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefVersnc, "")) {
			changeState(VecWzlaVSte::SYNCVER_DPCHVERSNCDO_BUTSNC);
		};

	} else if (ixVSte == VecWzlaVSte::SYNCVER_DPCHVERSNCDO_BUTSNC) {
		if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
			if (_dpcheng->hasAll({PnlWzlmSdbVersnc::DpchEngData::CONTIAC}))
					changeState(VecWzlaVSte::SYNCVER_DONE);
		} else if (dpchEngConfirmAccepted(_dpcheng, DOM->CrdSdb_statshr.scrJrefVersnc, "")) {
			changeState(VecWzlaVSte::SYNCVER_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

bool AppWzla::handleDpchEngFinish(
			DpchEngWzlm* _dpcheng
		) {
	bool skipRefresh = false;
	uint oldIxVSte = ixVSte;

	if (ixVSte == VecWzlaVSte::FINISH_DPCHNAVDO_MITSESTRM) {
		if (dpchEngConfirmAccepted(_dpcheng, DOM->scrJrefCrdNav, "")) {
			changeState(VecWzlaVSte::FINISH_DONE);
		};
	};

	if (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;
	return skipRefresh;
};

void AppWzla::handleDpchEng(
			DpchEngWzlm* _dpcheng
			, const bool err
		) {
	mHandleDpchEng.lock("AppWzla", "handleDpchEng");

	bool _refresh = false;

	// --- error handling
	// ...

	// --- merge data blocks
	if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBDATA, DOM->scrJrefCrdSdb)) {
		mergeDpchEngWzlmSdbData((CrdWzlmSdb::DpchEngData*) _dpcheng);
	} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBAUTHDATA, DOM->CrdSdb_statshr.scrJrefAuth)) {
		mergeDpchEngWzlmSdbAuthData((PnlWzlmSdbAuth::DpchEngData*) _dpcheng);
	} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBPRJSNCDATA, DOM->CrdSdb_statshr.scrJrefPrjsnc)) {
		mergeDpchEngWzlmSdbPrjsncData((PnlWzlmSdbPrjsnc::DpchEngData*) _dpcheng);
	} else if (dpchEngIsOfType(_dpcheng, VecWzlmVDpch::DPCHENGWZLMSDBVERSNCDATA, DOM->CrdSdb_statshr.scrJrefVersnc)) {
		mergeDpchEngWzlmSdbVersncData((PnlWzlmSdbVersnc::DpchEngData*) _dpcheng);
	};

	// --- process state-related dispatches
	if ((ixVSte >= VecWzlaVSte::CONNECT_IDLE) && (ixVSte <= VecWzlaVSte::CONNECT_DONE)) {
		if (handleDpchEngConnect(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::REPACT_IDLE) && (ixVSte <= VecWzlaVSte::REPACT_DONE)) {
		if (handleDpchEngRepact(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::REPINACT_IDLE) && (ixVSte <= VecWzlaVSte::REPINACT_DONE)) {
		if (handleDpchEngRepinact(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::AUTHIMPEX_IDLE) && (ixVSte <= VecWzlaVSte::AUTHIMPEX_DONE)) {
		if (handleDpchEngAuthimpex(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::AUTHPRJNEW_IDLE) && (ixVSte <= VecWzlaVSte::AUTHPRJNEW_DONE)) {
		if (handleDpchEngAuthprjnew(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::AUTHWRCODE_IDLE) && (ixVSte <= VecWzlaVSte::AUTHWRCODE_DONE)) {
		if (handleDpchEngAuthwrcode(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::SYNCPRJ_IDLE) && (ixVSte <= VecWzlaVSte::SYNCPRJ_DONE)) {
		if (handleDpchEngSyncprj(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::SYNCVER_IDLE) && (ixVSte <= VecWzlaVSte::SYNCVER_DONE)) {
		if (handleDpchEngSyncver(_dpcheng)) _refresh = false;
	} else if ((ixVSte >= VecWzlaVSte::FINISH_IDLE) && (ixVSte <= VecWzlaVSte::FINISH_DONE)) {
		if (handleDpchEngFinish(_dpcheng)) _refresh = false;
	};

	if (_refresh) refresh();

	// --- process other dispatches
	// ...
	
	if (_dpcheng) delete _dpcheng;

	mHandleDpchEng.unlock("AppWzla", "handleDpchEng");
};

void AppWzla::changeWaitSte(
			const unsigned int ixVSteChange
			, const unsigned int ixVSteWait
		) {
	// enter unlocked, leave unlocked
	cRefresh.lockMutex("AppWzla", "changeWaitSte");

	ixVSteRefresh = ixVSteWait;

	changeState(ixVSteChange);
	cRefresh.wait("AppWzla", "changeWaitSte");

	cRefresh.unlockMutex("AppWzla", "changeWaitSte");
};

void AppWzla::changeWaitStePre(
			const unsigned int ixVSteChange
			, const unsigned int ixVSteWait
		) {
	// enter unlocked, leave locked
	cRefresh.lockMutex("AppWzla", "changeWaitStePre");

	ixVSteRefresh = ixVSteWait;
	waitReplyRefresh = true;

	changeState(ixVSteChange);

	cRefresh.wait("AppWzla", "changeWaitStePre");
};

void AppWzla::waitStePost(
			const unsigned int ixVSteWait
			, const bool waitReply
		) {
	// enter locked, leave locked if waitReply true
	ixVSteRefresh = ixVSteWait;
	waitReplyRefresh = waitReply;

	cRefresh.unlockMutex("AppWzla", "waitStePost[1]");

	cRefresh.signal("AppWzla", "waitStePost");

	cRefresh.lockMutex("AppWzla", "waitStePost");
	cRefresh.wait("AppWzla", "waitStePost");

	if (!waitReply) cRefresh.unlockMutex("AppWzla", "waitStePost[2]");
};

// IP cust --- INSERT

