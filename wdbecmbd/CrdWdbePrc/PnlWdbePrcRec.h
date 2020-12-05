/**
	* \file PnlWdbePrcRec.h
	* job handler for job PnlWdbePrcRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRCREC_H
#define PNLWDBEPRCREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbePrcFsmFsm1NFsmstate.h"
#include "PnlWdbePrcMge1NSignal.h"
#include "PnlWdbePrcPrc1NVariable.h"
#include "PnlWdbePrcKHdltype.h"
#include "PnlWdbePrcDetail.h"

#define VecVWdbePrcRecDo PnlWdbePrcRec::VecVDo

#define ContInfWdbePrcRec PnlWdbePrcRec::ContInf
#define StatAppWdbePrcRec PnlWdbePrcRec::StatApp
#define StatShrWdbePrcRec PnlWdbePrcRec::StatShr
#define TagWdbePrcRec PnlWdbePrcRec::Tag

#define DpchAppWdbePrcRecDo PnlWdbePrcRec::DpchAppDo
#define DpchEngWdbePrcRecData PnlWdbePrcRec::DpchEngData

/**
	* PnlWdbePrcRec
	*/
class PnlWdbePrcRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePrcRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbePrcRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbePrcRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdonePrc1NVariable = false, const bool initdoneMge1NSignal = false, const bool initdoneFsmFsm1NFsmstate = false);
	};

	/**
		* StatShr (full: StatShrWdbePrcRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFKHDLTYPE = 3;
		static const Sbecore::uint JREFPRC1NVARIABLE = 4;
		static const Sbecore::uint JREFMGE1NSIGNAL = 5;
		static const Sbecore::uint JREFFSMFSM1NFSMSTATE = 6;
		static const Sbecore::uint PNLFSMFSM1NFSMSTATEAVAIL = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefKHdltype = 0, const Sbecore::ubigint jrefPrc1NVariable = 0, const Sbecore::ubigint jrefMge1NSignal = 0, const Sbecore::ubigint jrefFsmFsm1NFsmstate = 0, const bool pnlfsmfsm1nfsmstateAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefKHdltype;
		Sbecore::ubigint jrefPrc1NVariable;
		Sbecore::ubigint jrefMge1NSignal;
		Sbecore::ubigint jrefFsmFsm1NFsmstate;
		bool pnlfsmfsm1nfsmstateAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePrcRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePrcRecDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbePrcRecData)
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

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalPnlfsmfsm1nfsmstateAvail(DbsWdbe* dbswdbe);
	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbePrcRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePrcRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbePrcFsmFsm1NFsmstate* pnlfsmfsm1nfsmstate;
	PnlWdbePrcMge1NSignal* pnlmge1nsignal;
	PnlWdbePrcPrc1NVariable* pnlprc1nvariable;
	PnlWdbePrcKHdltype* pnlkhdltype;
	PnlWdbePrcDetail* pnldetail;

	WdbeMProcess recPrc;

	WdbeMFsm recFsm;

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
	bool handleCallWdbePrcUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeFsmUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbePrc_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePrc_fsmEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif



