/**
	* \file PnlWdbeMtpRec.h
	* job handler for job PnlWdbeMtpRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMTPREC_H
#define PNLWDBEMTPREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeMtpMge1NSignal.h"
#include "PnlWdbeMtpRef1NFile.h"
#include "PnlWdbeMtpSup1NModule.h"
#include "PnlWdbeMtpMdl1NGeneric.h"
#include "PnlWdbeMtpTpl1NModule.h"
#include "PnlWdbeMtpMdl1NPort.h"
#include "PnlWdbeMtpAPar.h"
#include "PnlWdbeMtpKHdltype.h"
#include "PnlWdbeMtpKParKey.h"
#include "PnlWdbeMtpDetail.h"

#define VecVWdbeMtpRecDo PnlWdbeMtpRec::VecVDo

#define ContInfWdbeMtpRec PnlWdbeMtpRec::ContInf
#define StatAppWdbeMtpRec PnlWdbeMtpRec::StatApp
#define StatShrWdbeMtpRec PnlWdbeMtpRec::StatShr
#define TagWdbeMtpRec PnlWdbeMtpRec::Tag

#define DpchAppWdbeMtpRecDo PnlWdbeMtpRec::DpchAppDo
#define DpchEngWdbeMtpRecData PnlWdbeMtpRec::DpchEngData

/**
	* PnlWdbeMtpRec
	*/
class PnlWdbeMtpRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeMtpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeMtpRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeMtpRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneMdl1NPort = false, const bool initdoneTpl1NModule = false, const bool initdoneMdl1NGeneric = false, const bool initdoneSup1NModule = false, const bool initdoneRef1NFile = false, const bool initdoneMge1NSignal = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneMdl1NPort = false, const bool initdoneTpl1NModule = false, const bool initdoneMdl1NGeneric = false, const bool initdoneSup1NModule = false, const bool initdoneRef1NFile = false, const bool initdoneMge1NSignal = false);
	};

	/**
		* StatShr (full: StatShrWdbeMtpRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFKPARKEY = 3;
		static const Sbecore::uint JREFKHDLTYPE = 4;
		static const Sbecore::uint JREFAPAR = 5;
		static const Sbecore::uint JREFMDL1NPORT = 6;
		static const Sbecore::uint JREFTPL1NMODULE = 7;
		static const Sbecore::uint JREFMDL1NGENERIC = 8;
		static const Sbecore::uint JREFSUP1NMODULE = 9;
		static const Sbecore::uint JREFREF1NFILE = 10;
		static const Sbecore::uint JREFMGE1NSIGNAL = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefKParKey = 0, const Sbecore::ubigint jrefKHdltype = 0, const Sbecore::ubigint jrefAPar = 0, const Sbecore::ubigint jrefMdl1NPort = 0, const Sbecore::ubigint jrefTpl1NModule = 0, const Sbecore::ubigint jrefMdl1NGeneric = 0, const Sbecore::ubigint jrefSup1NModule = 0, const Sbecore::ubigint jrefRef1NFile = 0, const Sbecore::ubigint jrefMge1NSignal = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefKParKey;
		Sbecore::ubigint jrefKHdltype;
		Sbecore::ubigint jrefAPar;
		Sbecore::ubigint jrefMdl1NPort;
		Sbecore::ubigint jrefTpl1NModule;
		Sbecore::ubigint jrefMdl1NGeneric;
		Sbecore::ubigint jrefSup1NModule;
		Sbecore::ubigint jrefRef1NFile;
		Sbecore::ubigint jrefMge1NSignal;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeMtpRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeMtpRecDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeMtpRecData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeMtpRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeMtpRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeMtpMge1NSignal* pnlmge1nsignal;
	PnlWdbeMtpRef1NFile* pnlref1nfile;
	PnlWdbeMtpSup1NModule* pnlsup1nmodule;
	PnlWdbeMtpMdl1NGeneric* pnlmdl1ngeneric;
	PnlWdbeMtpTpl1NModule* pnltpl1nmodule;
	PnlWdbeMtpMdl1NPort* pnlmdl1nport;
	PnlWdbeMtpAPar* pnlapar;
	PnlWdbeMtpKHdltype* pnlkhdltype;
	PnlWdbeMtpKParKey* pnlkparkey;
	PnlWdbeMtpDetail* pnldetail;

	WdbeMModule recMdl;
	Sbecore::uint ixWSubsetMdl;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWdbe* dbswdbe, const bool notif = false, DpchEngWdbe** dpcheng = NULL);
	void regularize(DbsWdbe* dbswdbe, const bool notif = false, DpchEngWdbe** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeMdlUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeMdl_typEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_tplEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_supEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_sup_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_imbEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hkuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hku_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hktEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_ctrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
