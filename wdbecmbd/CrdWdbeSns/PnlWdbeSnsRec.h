/**
	* \file PnlWdbeSnsRec.h
	* job handler for job PnlWdbeSnsRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESNSREC_H
#define PNLWDBESNSREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeSnsDetail.h"

#define VecVWdbeSnsRecDo PnlWdbeSnsRec::VecVDo

#define ContInfWdbeSnsRec PnlWdbeSnsRec::ContInf
#define StatAppWdbeSnsRec PnlWdbeSnsRec::StatApp
#define StatShrWdbeSnsRec PnlWdbeSnsRec::StatShr
#define TagWdbeSnsRec PnlWdbeSnsRec::Tag

#define DpchAppWdbeSnsRecDo PnlWdbeSnsRec::DpchAppDo
#define DpchEngWdbeSnsRecData PnlWdbeSnsRec::DpchEngData

/**
	* PnlWdbeSnsRec
	*/
class PnlWdbeSnsRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSnsRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeSnsRec)
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
		* StatApp (full: StatAppWdbeSnsRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false);
	};

	/**
		* StatShr (full: StatShrWdbeSnsRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 3;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeSnsRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeSnsRecDo)
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
		* DpchEngData (full: DpchEngWdbeSnsRecData)
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
	PnlWdbeSnsRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSnsRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeSnsDetail* pnldetail;

	WdbeMSensitivity recSns;

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
	bool handleCallWdbeSnsUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeSns_sruEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSns_srtEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeSns_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSns_reu_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeSns_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
