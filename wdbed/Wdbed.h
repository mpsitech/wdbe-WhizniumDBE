/**
	* \file Wdbecmbd.h
	* inter-thread exchange object for Wdbe combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBED_H
#define WDBED_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>
#if MHD_VERSION < 0x0097002
	#define MHD_Result int
#endif

#include <curl/curl.h>

#include <sbecore/Txtrd.h>
#include <sbecore/DbsMon.h>

#include "Wdbe.h"

#include "SqkWdbeCplmst.h"
#include "SqkWdbeGen.h"
#include "SqkWdbeGenfst.h"
#include "SqkWdbeMtpCplmstbu.h"
#include "SqkWdbeMtpCplmsttd.h"
#include "SqkWdbeMtpGenfst.h"
#include "SqkWdbeMtpPlhfpga.h"
#include "SqkWdbeMtpPlhmcu.h"
#include "SqkWdbeMtpWrfpga.h"
#include "SqkWdbeMtpWrmcu.h"
#include "SqkWdbePlhfpga.h"
#include "SqkWdbePlhmcu.h"
#include "SqkWdbePrcfile.h"
#include "SqkWdbePrctree.h"
#include "SqkWdbeWrdev.h"
#include "SqkWdbeWrfpga.h"
#include "SqkWdbeWrmcu.h"

// IP include.cust --- INSERT

class XchgWdbed;
typedef XchgWdbed XchgWdbe;

/**
	* DpchWdbedAck (written by dOpengsrv, identified by opd_exe)
	*/
namespace DpchWdbedAck {
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchWdbedQuit (written by d_exe, identified by opdEngsrv)
	*/
namespace DpchWdbedQuit {
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchWdbedReg (written by dOpengsrv, read by opd_exe)
	*/
namespace DpchWdbedReg {
	void writeXML(xmlTextWriter* wr, const Sbecore::ubigint nref = 0);
};

/**
	* DpchWdbeopdReg (written by opd_exe, read by dOpengsrv)
	*/
class DpchWdbeopdReg : public DpchWdbe {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint IXWDBEVOPENGTYPE = 2;
	static const Sbecore::uint OPPRCN = 3;

public:
	DpchWdbeopdReg();

public:
	Sbecore::usmallint port;
	Sbecore::uint ixWdbeVOpengtype;
	Sbecore::usmallint opprcn;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchWdbeopdUnreg (written by opd_exe, read by dOpengsrv)
	*/
class DpchWdbeopdUnreg : public DpchWdbe {

public:
	static const Sbecore::uint NREF = 1;

public:
	DpchWdbeopdUnreg();

public:
	Sbecore::ubigint nref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWdbe
	*/
class DpchAppWdbe : public DpchWdbe {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchAppWdbe(const Sbecore::uint ixWdbeVDpch = 0);
	virtual ~DpchAppWdbe();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readJSON(const Json::Value& sup, bool addbasetag = false);
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWdbeAlert
	*/
class DpchAppWdbeAlert : public DpchAppWdbe {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint NUMFMCB = 2;

public:
	DpchAppWdbeAlert();

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readJSON(const Json::Value& sup, bool addbasetag = false);
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWdbeInit
	*/
class DpchAppWdbeInit : public DpchAppWdbe {

public:
	DpchAppWdbeInit();
};

/**
	* DpchAppWdbeResume
	*/
class DpchAppWdbeResume : public DpchAppWdbe {

public:
	DpchAppWdbeResume();
};

/**
	* DpchEngWdbe
	*/
class DpchEngWdbe : public DpchWdbe {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchEngWdbe(const Sbecore::uint ixWdbeVDpch = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchEngWdbe();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();
	virtual void merge(DpchEngWdbe* dpcheng);

	virtual void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
	virtual void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWdbeAck
	*/
class DpchEngWdbeAck : public DpchEngWdbe {

public:
	DpchEngWdbeAck(const Sbecore::ubigint jref = 0);
};

/**
	* DpchEngWdbeAlert
	*/
class DpchEngWdbeAlert : public DpchEngWdbe {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWdbeAlert(const Sbecore::ubigint jref = 0, ContInfWdbeAlert* continf = NULL, Sbecore::Feed* feedFMcb = NULL, const std::set<Sbecore::uint>& mask = {NONE});

public:
	ContInfWdbeAlert continf;
	Sbecore::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWdbe* dpcheng);

	void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWdbeConfirm
	*/
class DpchEngWdbeConfirm : public DpchEngWdbe {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREF = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWdbeConfirm(const bool accepted = false, const Sbecore::ubigint jref = 0, const std::string& sref = "", const std::set<Sbecore::uint>& mask = {ALL});

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWdbe* dpcheng);

	void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWdbeSuspend
	*/
class DpchEngWdbeSuspend : public DpchEngWdbe {

public:
	DpchEngWdbeSuspend(const Sbecore::ubigint jref = 0);
};

/**
	* StgWdbeAppearance
	*/
class StgWdbeAppearance : public Sbecore::Block {

public:
	static const Sbecore::uint HISTLENGTH = 1;
	static const Sbecore::uint SUSPSESS = 2;
	static const Sbecore::uint SESSTTERM = 3;
	static const Sbecore::uint SESSTWARN = 4;
	static const Sbecore::uint ROOTTTERM = 5;

public:
	StgWdbeAppearance(const Sbecore::usmallint histlength = 20, const bool suspsess = true, const Sbecore::uint sesstterm = 0, const Sbecore::uint sesstwarn = 0, const Sbecore::uint roottterm = 0);

public:
	Sbecore::usmallint histlength;
	bool suspsess;
	Sbecore::uint sesstterm;
	Sbecore::uint sesstwarn;
	Sbecore::uint roottterm;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbeAppearance* comp);
	std::set<Sbecore::uint> diff(const StgWdbeAppearance* comp);
};

/**
	* StgWdbeAppsrv
	*/
class StgWdbeAppsrv : public Sbecore::Block {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint HTTPS = 2;
	static const Sbecore::uint CORS = 3;

public:
	StgWdbeAppsrv(const Sbecore::usmallint port = 13100, const bool https = false, const std::string& cors = "");

public:
	Sbecore::usmallint port;
	bool https;
	std::string cors;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbeAppsrv* comp);
	std::set<Sbecore::uint> diff(const StgWdbeAppsrv* comp);
};

/**
	* StgWdbed
	*/
class StgWdbed : public Sbecore::Block {

public:
	static const Sbecore::uint JOBPRCN = 1;
	static const Sbecore::uint OPENGSRVPORT = 2;
	static const Sbecore::uint APPSRV = 3;

public:
	StgWdbed(const Sbecore::usmallint jobprcn = 4, const Sbecore::usmallint opengsrvport = 13120, const bool appsrv = true);

public:
	Sbecore::usmallint jobprcn;
	Sbecore::usmallint opengsrvport;
	bool appsrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbed* comp);
	std::set<Sbecore::uint> diff(const StgWdbed* comp);
};

/**
	* StgWdbeDatabase
	*/
class StgWdbeDatabase : public Sbecore::Block {

public:
	static const Sbecore::uint IXDBSVDBSTYPE = 1;
	static const Sbecore::uint DBSPATH = 2;
	static const Sbecore::uint DBSNAME = 3;
	static const Sbecore::uint USERNAME = 4;
	static const Sbecore::uint PASSWORD = 5;
	static const Sbecore::uint IP = 6;
	static const Sbecore::uint PORT = 7;

public:
	StgWdbeDatabase(const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsWdbe.sql", const std::string& dbsname = "DbsWdbe", const std::string& username = "default", const std::string& password = "asdf1234", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 3306);

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbeDatabase* comp);
	std::set<Sbecore::uint> diff(const StgWdbeDatabase* comp);
};

/**
	* StgWdbeMonitor
	*/
class StgWdbeMonitor : public Sbecore::Block {

public:
	static const Sbecore::uint USERNAME = 1;
	static const Sbecore::uint PASSWORD = 2;
	static const Sbecore::uint IP = 3;
	static const Sbecore::uint PORT = 4;
	static const Sbecore::uint IXDBSVDBSTYPE = 5;
	static const Sbecore::uint DBSPATH = 6;
	static const Sbecore::uint DBSNAME = 7;
	static const Sbecore::uint DBSUSERNAME = 8;
	static const Sbecore::uint DBSPASSWORD = 9;

public:
	StgWdbeMonitor(const std::string& username = "wzemuser", const std::string& password = "asdf1234", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 14100, const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsWzem.sql", const std::string& dbsname = "DbsWzem", const std::string& dbsusername = "", const std::string& dbspassword = "");

public:
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string dbsusername;
	std::string dbspassword;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbeMonitor* comp);
	std::set<Sbecore::uint> diff(const StgWdbeMonitor* comp);
};

/**
	* StgWdbePath
	*/
class StgWdbePath : public Sbecore::Block {

public:
	static const Sbecore::uint ACVPATH = 1;
	static const Sbecore::uint KEYPATH = 2;
	static const Sbecore::uint MONPATH = 3;
	static const Sbecore::uint TMPPATH = 4;
	static const Sbecore::uint WEBPATH = 5;
	static const Sbecore::uint HELPURL = 6;

public:
	StgWdbePath(const std::string& acvpath = "${WHIZROOT}/acv/wdbe", const std::string& keypath = "", const std::string& monpath = "${WHIZROOT}/mon/wdbe", const std::string& tmppath = "${WHIZROOT}/tmp/wdbe", const std::string& webpath = "${WHIZROOT}/web/appwdbe", const std::string& helpurl = "/wdbe");

public:
	std::string acvpath;
	std::string keypath;
	std::string monpath;
	std::string tmppath;
	std::string webpath;
	std::string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbePath* comp);
	std::set<Sbecore::uint> diff(const StgWdbePath* comp);
};

/**
	* StgWdbeTenant
	*/
class StgWdbeTenant : public Sbecore::Block {

public:
	static const Sbecore::uint ORGNAME = 1;
	static const Sbecore::uint ORGWEB = 2;

public:
	StgWdbeTenant(const std::string& orgname = "", const std::string& orgweb = "");

public:
	std::string orgname;
	std::string orgweb;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWdbeTenant* comp);
	std::set<Sbecore::uint> diff(const StgWdbeTenant* comp);
};

/**
	* AlrWdbe
	*/
namespace AlrWdbe {
	DpchEngWdbeAlert* prepareAlrAbt(const Sbecore::ubigint jref, const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngWdbeAlert* prepareAlrIer(const Sbecore::ubigint jref, const Sbecore::uint ixWdbeVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngWdbeAlert* prepareAlrPer(const Sbecore::ubigint jref, const Sbecore::uint ixWdbeVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngWdbeAlert* prepareAlrSav(const Sbecore::ubigint jref, const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngWdbeAlert* prepareAlrTrm(const Sbecore::ubigint jref, const Sbecore::uint ixWdbeVLocale, const Sbecore::uint sesstterm, const Sbecore::uint sesstwarn, Sbecore::Feed& feedFMcbAlert);
	std::string prepareAlrTrm_dtToString(const uint ixWdbeVLocale, const time_t dt);
};

/**
	* ReqWdbe
	*/
class ReqWdbe {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint REDIRECT = 1; // web client triggered root request (GET)
		static const Sbecore::uint PREFLIGHT = 2; // web client triggered Dpch pre-flight request (OPTIONS)
		static const Sbecore::uint WEB = 3; // web client triggered ui file request (GET)
		static const Sbecore::uint CMD = 4; // command line request
		static const Sbecore::uint DPCHAPP = 5; // web client triggered Dpch request (POST+DpchApp)
		static const Sbecore::uint NOTIFY = 6; // web client triggered notify-on-Dpch request (GET)
		static const Sbecore::uint POLL = 7; // web client triggered Dpch poll request (GET)
		static const Sbecore::uint UPLOAD = 8; // web client triggered file upload request (POST)
		static const Sbecore::uint DOWNLOAD = 9; // web client triggered file download request (GET)
		static const Sbecore::uint DPCHRET = 10; // op engine or opprc triggered op return (DpchRet)
		static const Sbecore::uint METHOD = 11; // M2M interface triggered method request
		static const Sbecore::uint TIMER = 12; // timer triggered request
		static const Sbecore::uint EXTCALL = 13; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint RECEIVE = 1; // during data reception - appsrv internal
		static const Sbecore::uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const Sbecore::uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const Sbecore::uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqWdbe(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqWdbe();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	// specific data for base type CMD
	std::string cmd;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD
	std::string ip;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, DPCHAPP, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Sbecore::Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	std::string filename; // full path
	std::fstream* file;
	size_t filelen;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* request;
	size_t requestlen;

	// specifc data for base types DPCHAPP, NOTIFY, POLL
	bool jsonNotXml;

	// specific data for base types CMD, DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	Sbecore::ubigint jref;

	// specific data for base type TIMER
	Sbecore::ubigint wref;
	std::string sref;

	// specific data for base type EXTCALL
	Sbecore::Call* call;

	// specific data for base types CMD, DPCHAPP, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	bool weak;

	// specific data for base type DPCHAPP
	DpchAppWdbe* dpchapp;

	// specific data for base types DPCHAPP, NOTIFY, POLL
	DpchEngWdbe* dpcheng;
	Sbecore::uint ixWdbeVLocale;

	// specific data for base type DPCHRET
	DpchInvWdbe* dpchinv;
	DpchRetWdbe* dpchret;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Sbecore::Method* method;

public:
	void setStateReply();
};

/**
	* ReqopengconWdbe
	*/
class ReqopengconWdbe {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint RECEIVE = 0; // during data reception - opengsrv internal
		static const Sbecore::uint REPLY = 1; // while reply being transmitted by opengconsrv - opengsrv internal
	};

public:
	ReqopengconWdbe(const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqopengconWdbe();

public:
	Sbecore::uint ixVState;
	std::string ip;

	MHD_PostProcessor* pp;

	char* request;
	size_t requestlen;

	DpchWdbe* dpchopd;

	char* reply;
	size_t replylen;
};

/**
	* DcolWdbe
	*/
class DcolWdbe {

public:
	DcolWdbe(const Sbecore::ubigint jref = 0, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS);
	~DcolWdbe();

public:
	Sbecore::ubigint jref;

	Sbecore::uint ixWdbeVLocale;

	Sbecore::Mutex mAccess;

	bool hot;

	std::list<DpchEngWdbe*> dpchs;

	ReqWdbe* req;

public:
	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* JobWdbe
	*/
class JobWdbe {

public:
	JobWdbe(XchgWdbe* xchg, const Sbecore::uint ixWdbeVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS);
	virtual ~JobWdbe();

public:
	XchgWdbe* xchg;

	Sbecore::ubigint jref;

	Sbecore::uint ixWdbeVJob;

	Sbecore::uint ixWdbeVLocale;

	Sbecore::Mutex mAccess;

	bool muteRefresh;

	Sbecore::uint ixVSge;
	Sbecore::uint nextIxVSgeSuccess;
	Sbecore::uint nextIxVSgeFailure;

	std::string lasterror;

	Sbecore::uint opN;
	Sbecore::uint opNSuccess;
	Sbecore::uint opNFailure;

	std::vector<DpchInvWdbe*> invs;

	Sbecore::Mutex mOps;
	std::list<Sbecore::Op*> ops;
	std::string opsqkLast;

	Sbecore::ubigint wrefLast;
	Sbecore::ubigint wrefMin;

	ReqWdbe* reqCmd;

public:
	Sbecore::ubigint insertSubjob(std::map<Sbecore::ubigint, JobWdbe*>& subjobs, JobWdbe* subjob);
	bool eraseSubjobByJref(std::map<Sbecore::ubigint, JobWdbe*>& subjobs, const Sbecore::ubigint _jref);

	virtual DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	virtual void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void refreshWithDpchEng(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng = NULL, const bool unmute = false);

	virtual std::string getSquawk(DbsWdbe* dbswdbe);

	virtual void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);
	virtual void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

	void lockAccess(const std::string& srefObject, const std::string& srefMember);
	bool trylockAccess(const std::string& srefObject, const std::string& srefMember);
	void unlockAccess(const std::string& srefObject, const std::string& srefMember);

	void lockAccess(const std::string& srefMember);
	bool trylockAccess(const std::string& srefMember);
	void unlockAccess(const std::string& srefMember);

	void setStage(DbsWdbe* dbswdbe, const Sbecore::uint _ixVSge);

	void clearInvs();
	Sbecore::ubigint addInv(DpchInvWdbe* inv);
	void addInvs(std::vector<DpchInvWdbe*>& _invs);
	void submitInvs(DbsWdbe* dbswdbe, const Sbecore::uint nextIxVSgeEmpty, Sbecore::uint& _ixVSge);

	void clearOps();
	void addOp(DbsWdbe* dbswdbe, DpchInvWdbe* inv);
	void removeOp(const Sbecore::ubigint oref);
	std::string getOpsqkLast();

	void callback(const Sbecore::uint nextIxVSge);
	void invalidateWakeups();
};

/**
	* CsjobWdbe
	*/
class CsjobWdbe : public JobWdbe {

public:
	CsjobWdbe(XchgWdbe* xchg, const Sbecore::uint ixWdbeVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS);

public:
	bool srvNotCli;
	CsjobWdbe* srv; // client

public:
	virtual bool handleClaim(DbsWdbe* dbswdbe, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest); // server
};

/**
	* ShrdatWdbe
	*/
class ShrdatWdbe {

public:
	ShrdatWdbe(const std::string& srefSupclass, const std::string& srefObject);
	~ShrdatWdbe();

public:
	std::string srefSupclass;
	std::string srefObject;

	Sbecore::Rwmutex rwmAccess;

public:
	virtual void init(XchgWdbe* xchg, DbsWdbe* dbswdbe);
	virtual void term(XchgWdbe* xchg);

	void rlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void runlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void rlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void runlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void wunlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
};

/**
	* StmgrWdbe
	*/
class StmgrWdbe {

public:
	StmgrWdbe(XchgWdbe* xchg, const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	~StmgrWdbe();

public:
	XchgWdbe* xchg;

	Sbecore::ubigint jref;
	Sbecore::uint ixVNonetype;

	Sbecore::Stcch* stcch;

	Sbecore::Mutex mAccess;

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);
	bool refresh(DbsWdbe* dbswdbe, Sbecore::Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* WakeupWdbe
	*/
class WakeupWdbe {

public:
	WakeupWdbe(XchgWdbe* xchg, const Sbecore::ubigint wref, const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);

public:
	XchgWdbe* xchg;

	Sbecore::ubigint wref;

	Sbecore::ubigint jref;
	std::string sref;
	uint64_t deltat;
	bool weak;
};

/**
	* ExtcallWdbe
	*/
class ExtcallWdbe {

public:
	ExtcallWdbe(XchgWdbe* xchg, Sbecore::Call* call);

public:
	XchgWdbe* xchg;
	Sbecore::Call* call;
};

/**
	* NodeWdbe
	*/
class NodeWdbe {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint IDLE = 0; // not connected
		static const Sbecore::uint READY = 1; // connected
		static const Sbecore::uint ERROR = 2; // error
		static const Sbecore::uint TERM = 3; // terminate requested
		static const Sbecore::uint DONE = 4; // connection closed or lost
	};

public:
	NodeWdbe(const Sbecore::ubigint nref, const std::string& ip, const Sbecore::uint port, const Sbecore::uint opprcn, const Sbecore::uint ixWdbeVOpengtype);
	~NodeWdbe();

public:
	Sbecore::ubigint nref;

	std::string ip;
	Sbecore::uint port;
	Sbecore::uint opprcn;
	Sbecore::uint ixWdbeVOpengtype;

	std::set<Sbecore::uint> icsWdbeVDpch;

	Sbecore::uint ixVState;
};

/**
	* XchgWdbed
	*/
class XchgWdbed {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatWdbe {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- INSERT

	public:
		void init(XchgWdbe* xchg, DbsWdbe* dbswdbe);
		void term(XchgWdbe* xchg);
	};

public:
	XchgWdbed();
	~XchgWdbed();

public:
	StgWdbeAppearance stgwdbeappearance;
	StgWdbeAppsrv stgwdbeappsrv;
	StgWdbed stgwdbed;
	StgWdbeDatabase stgwdbedatabase;
	StgWdbeMonitor stgwdbemonitor;
	StgWdbePath stgwdbepath;
	StgWdbeTenant stgwdbetenant;

	ShrdatJobprc shrdatJobprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	std::string key;
	std::string cert;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// root job
	Sbecore::ubigint jrefRoot;

	// job receiving commands
	Sbecore::ubigint jrefCmd;

	// monitor object
	Sbecore::DbsMon mon;

	// log file
	Sbecore::Mutex mLogfile;

	// condition for op engine client
	Sbecore::Cond cOpengcli;

	bool termOpengcli;

	// condition for job processors
	Sbecore::Cond cJobprcs;

	// condition for operation processors (sub-threads of WdbedOpengcli)
	Sbecore::Cond cOpprcs;

	// request list
	Sbecore::Mutex mReqs;
	std::list<ReqWdbe*> reqs;

	// operation invocation list
	Sbecore::Refseq orefseq;
	Sbecore::Mutex mInvs;
	std::list<DpchInvWdbe*> invs;

	// presetting list
	Sbecore::Rwmutex rwmPresets;
	std::multimap<Sbecore::presetref_t,Sbecore::Preset*> presets;

	// stub manager list
	Sbecore::Rwmutex rwmStmgrs;
	std::map<Sbecore::ubigint,StmgrWdbe*> stmgrs;

	// call listener list
	Sbecore::Rwmutex rwmClstns;
	std::multimap<Sbecore::clstnref_t,Sbecore::Clstn*> clstns;
	std::multimap<Sbecore::clstnref2_t,Sbecore::clstnref_t> cref2sClstns;

	// dispatch collector list
	Sbecore::Rwmutex rwmDcols;
	std::map<Sbecore::ubigint,DcolWdbe*> dcols;

	// job list
	Sbecore::Refseq jrefseq;
	Sbecore::Rwmutex rwmJobs;
	std::map<Sbecore::ubigint,JobWdbe*> jobs;
	std::map<Sbecore::ubigint,Sbecore::uint> ixWdbeVJobs;
	std::map<Sbecore::ubigint,Sbecore::Jobinfo*> jobinfos;

	// client/server job information
	Sbecore::Rwmutex rwmCsjobinfos;
	std::map<Sbecore::uint,Sbecore::Csjobinfo*> csjobinfos;

	// sequence for wakeup references
	Sbecore::Refseq wrefseq;

	// node list
	Sbecore::Refseq nrefseq;
	Sbecore::Rwmutex rwmNodes;
	std::map<Sbecore::ubigint,NodeWdbe*> nodes;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqWdbe* req);
	ReqWdbe* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsWdbe* dbswdbe, JobWdbe* job, std::vector<DpchInvWdbe*>& dpchinvs);
	DpchInvWdbe* pullFirstInv(NodeWdbe* node);
	void returnInv(DpchInvWdbe* dpchinv);

	// presetting methods
	Sbecore::Preset* addPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const Sbecore::Arg& arg);

	Sbecore::Preset* addIxPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const Sbecore::uint ix);
	Sbecore::Preset* addRefPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const Sbecore::ubigint ref);
	Sbecore::Preset* addRefsPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const std::vector<Sbecore::ubigint>& refs);
	Sbecore::Preset* addSrefPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const std::string& sref);
	Sbecore::Preset* addIntvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const int intval);
	Sbecore::Preset* addDblvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const double dblval);
	Sbecore::Preset* addBoolvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const bool boolval);
	Sbecore::Preset* addTxtvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref, const std::string& txtval);

	Sbecore::Preset* getPresetByPref(const Sbecore::presetref_t& pref);

	Sbecore::Arg getPreset(const Sbecore::uint ixWdbeVPreset, Sbecore::ubigint jref);

	Sbecore::uint getIxPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	Sbecore::ubigint getRefPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	std::vector<Sbecore::ubigint> getRefsPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	std::string getSrefPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	int getIntvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	double getDblvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	bool getBoolvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	std::string getTxtvalPreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);

	void getPresetsByJref(const Sbecore::ubigint jref, std::vector<Sbecore::uint>& icsWdbeVPreset, std::vector<Sbecore::Arg>& args);

	void removePreset(const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jref);
	void removePresetsByJref(const Sbecore::ubigint jref);

	// stub manager methods
	StmgrWdbe* addStmgr(const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	StmgrWdbe* getStmgrByJref(const Sbecore::ubigint jref);
	void removeStmgrByJref(const Sbecore::ubigint jref);

	// call listener list methods
	Sbecore::Clstn* addClstn(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig = 0, const bool chgarg = false, const Sbecore::Arg& arg = Sbecore::Arg(), const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addIxClstn(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addRefClstn(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefClstn(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefSrefClstn(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const std::string& sref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addClstnStmgr(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref);

	Sbecore::Clstn* getClstnByCref(const Sbecore::clstnref_t& cref);
	void getClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget, std::vector<Sbecore::uint>& icsWdbeVCall, std::vector<Sbecore::uint>& icsVJobmask);

	void removeClstns(const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Sbecore::Call* call, std::vector<Sbecore::ubigint>& jrefTrigs, std::vector<Sbecore::ubigint>& jrefs, std::vector<Sbecore::uint>& icsVTarget, std::vector<Sbecore::uint>& icsVJactype);

	void triggerCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

	bool triggerArgToArgCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::Arg& argInv, Sbecore::Arg& argRet);
	bool triggerCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref);
	bool triggerIxCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv);
	bool triggerRefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv);
	bool triggerIntvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool triggerIxSrefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv);
	bool triggerIxSrefToIxCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);
	bool triggerIxIntvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool triggerSrefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const std::string& srefInv);
	bool triggerToBoolvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, std::string& srefRet);
	bool triggerRefToBoolvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerIxRefToRefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::ubigint& refRet);
	bool triggerIxRefSrefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool triggerRefToIxCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerSrefToRefCall(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCall, const Sbecore::ubigint jref, const std::string& srefInv, Sbecore::ubigint& refRet);

	// dispatch collector list methods
	DcolWdbe* addDcol(const Sbecore::ubigint jref);
	DcolWdbe* getDcolByJref(Sbecore::ubigint jref, const bool tree = true);
	void removeDcolByJref(const Sbecore::ubigint jref);
	void removeDcolsByJref(const Sbecore::ubigint jref);

	void submitDpch(DpchEngWdbe* dpcheng);
	DpchEngWdbe* pullFirstDpch(DcolWdbe* dcol);

	// job list methods
	Sbecore::ubigint addJob(DbsWdbe* dbswdbe, JobWdbe* job, const Sbecore::ubigint jrefSup);
	JobWdbe* getJobByJref(const Sbecore::ubigint jref);
	Sbecore::Jobinfo* getJobinfoByJref(const Sbecore::ubigint jref);
	void removeJobByJref(const Sbecore::ubigint jref);

	bool getJobSup(const Sbecore::ubigint jrefSup, Sbecore::ubigint jref);
	void setJobStage(DbsWdbe* dbswdbe, JobWdbe* job, const Sbecore::uint ixVSge);

	// client/server job methods
	void addCsjobClaim(DbsWdbe* dbswdbe, CsjobWdbe* csjob, Sbecore::Claim* claim);

	bool getCsjobClaim(CsjobWdbe* csjob, bool& takenNotAvailable, bool& fulfilled, bool& run);
	bool getCsjobClaim(CsjobWdbe* csjob, bool& takenNotAvailable, bool& fulfilled);

	void clearCsjobRun(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVJob);

	void removeCsjobClaim(DbsWdbe* dbswdbe, CsjobWdbe* csjob);

	bool getCsjobNotJob(const Sbecore::uint ixWdbeVJob);
	std::set<Sbecore::ubigint> getCsjobClisByJref(const Sbecore::ubigint jref);

	// timer methods
	Sbecore::ubigint addWakeup(const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);

	// node methods
	NodeWdbe* addNode(const std::string& ip, const Sbecore::uint port, const Sbecore::uint opprcn, const Sbecore::uint ixWdbeVOpengtype);
	NodeWdbe* getNodeByNref(const Sbecore::ubigint nref);

	void terminateNodes();
	void terminateNodeByNref(const Sbecore::ubigint nref);

	void setNodeState(NodeWdbe* node, const Sbecore::uint ixVState);
};
#endif
