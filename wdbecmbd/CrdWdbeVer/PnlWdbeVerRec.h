/**
	* \file PnlWdbeVerRec.h
	* job handler for job PnlWdbeVerRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEVERREC_H
#define PNLWDBEVERREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeVerMNLibrary.h"
#include "PnlWdbeVerRef1NFile.h"
#include "PnlWdbeVer1NUnit.h"
#include "PnlWdbeVerBvr1NVersion.h"
#include "PnlWdbeVer1NSystem.h"
#include "PnlWdbeVer1NRelease.h"
#include "PnlWdbeVerDetail.h"

#define VecVWdbeVerRecDo PnlWdbeVerRec::VecVDo

#define ContInfWdbeVerRec PnlWdbeVerRec::ContInf
#define StatAppWdbeVerRec PnlWdbeVerRec::StatApp
#define StatShrWdbeVerRec PnlWdbeVerRec::StatShr
#define TagWdbeVerRec PnlWdbeVerRec::Tag

#define DpchAppWdbeVerRecDo PnlWdbeVerRec::DpchAppDo
#define DpchEngWdbeVerRecData PnlWdbeVerRec::DpchEngData

/**
	* PnlWdbeVerRec
	*/
class PnlWdbeVerRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeVerRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeVerRec)
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
		* StatApp (full: StatAppWdbeVerRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdone1NRelease = false, const bool initdone1NSystem = false, const bool initdoneBvr1NVersion = false, const bool initdone1NUnit = false, const bool initdoneRef1NFile = false, const bool initdoneMNLibrary = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NRelease = false, const bool initdone1NSystem = false, const bool initdoneBvr1NVersion = false, const bool initdone1NUnit = false, const bool initdoneRef1NFile = false, const bool initdoneMNLibrary = false);
	};

	/**
		* StatShr (full: StatShrWdbeVerRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NRELEASE = 3;
		static const Sbecore::uint JREF1NSYSTEM = 4;
		static const Sbecore::uint JREFBVR1NVERSION = 5;
		static const Sbecore::uint JREF1NUNIT = 6;
		static const Sbecore::uint JREFREF1NFILE = 7;
		static const Sbecore::uint JREFMNLIBRARY = 8;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NRelease = 0, const Sbecore::ubigint jref1NSystem = 0, const Sbecore::ubigint jrefBvr1NVersion = 0, const Sbecore::ubigint jref1NUnit = 0, const Sbecore::ubigint jrefRef1NFile = 0, const Sbecore::ubigint jrefMNLibrary = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NRelease;
		Sbecore::ubigint jref1NSystem;
		Sbecore::ubigint jrefBvr1NVersion;
		Sbecore::ubigint jref1NUnit;
		Sbecore::ubigint jrefRef1NFile;
		Sbecore::ubigint jrefMNLibrary;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeVerRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeVerRecDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeVerRecData)
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

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeVerRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeVerRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeVerMNLibrary* pnlmnlibrary;
	PnlWdbeVerRef1NFile* pnlref1nfile;
	PnlWdbeVer1NUnit* pnl1nunit;
	PnlWdbeVerBvr1NVersion* pnlbvr1nversion;
	PnlWdbeVer1NSystem* pnl1nsystem;
	PnlWdbeVer1NRelease* pnl1nrelease;
	PnlWdbeVerDetail* pnldetail;

	WdbeMVersion recVer;

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
	bool handleCallWdbeVerUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeVer_steEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeVer_prjEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeVer_bvrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
