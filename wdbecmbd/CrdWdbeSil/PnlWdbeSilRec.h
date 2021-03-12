/**
	* \file PnlWdbeSilRec.h
	* job handler for job PnlWdbeSilRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESILREC_H
#define PNLWDBESILREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeSilHk1NModule.h"
#include "PnlWdbeSilHk1NVector.h"
#include "PnlWdbeSilRef1NError.h"
#include "PnlWdbeSilRef1NCommand.h"
#include "PnlWdbeSil1NTarget.h"
#include "PnlWdbeSilFwd1NController.h"
#include "PnlWdbeSil1NBank.h"
#include "PnlWdbeSilSil1NUnit.h"
#include "PnlWdbeSil1NPeripheral.h"
#include "PnlWdbeSilDetail.h"

#define VecVWdbeSilRecDo PnlWdbeSilRec::VecVDo

#define ContInfWdbeSilRec PnlWdbeSilRec::ContInf
#define StatAppWdbeSilRec PnlWdbeSilRec::StatApp
#define StatShrWdbeSilRec PnlWdbeSilRec::StatShr
#define TagWdbeSilRec PnlWdbeSilRec::Tag

#define DpchAppWdbeSilRecDo PnlWdbeSilRec::DpchAppDo
#define DpchEngWdbeSilRecData PnlWdbeSilRec::DpchEngData

/**
	* PnlWdbeSilRec
	*/
class PnlWdbeSilRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSilRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeSilRec)
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
		* StatApp (full: StatAppWdbeSilRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdone1NPeripheral = false, const bool initdoneSil1NUnit = false, const bool initdone1NBank = false, const bool initdoneFwd1NController = false, const bool initdone1NTarget = false, const bool initdoneRef1NCommand = false, const bool initdoneRef1NError = false, const bool initdoneHk1NVector = false, const bool initdoneHk1NModule = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NPeripheral = false, const bool initdoneSil1NUnit = false, const bool initdone1NBank = false, const bool initdoneFwd1NController = false, const bool initdone1NTarget = false, const bool initdoneRef1NCommand = false, const bool initdoneRef1NError = false, const bool initdoneHk1NVector = false, const bool initdoneHk1NModule = false);
	};

	/**
		* StatShr (full: StatShrWdbeSilRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NPERIPHERAL = 3;
		static const Sbecore::uint JREFSIL1NUNIT = 4;
		static const Sbecore::uint JREF1NBANK = 5;
		static const Sbecore::uint JREFFWD1NCONTROLLER = 6;
		static const Sbecore::uint JREF1NTARGET = 7;
		static const Sbecore::uint JREFREF1NCOMMAND = 8;
		static const Sbecore::uint JREFREF1NERROR = 9;
		static const Sbecore::uint JREFHK1NVECTOR = 10;
		static const Sbecore::uint JREFHK1NMODULE = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NPeripheral = 0, const Sbecore::ubigint jrefSil1NUnit = 0, const Sbecore::ubigint jref1NBank = 0, const Sbecore::ubigint jrefFwd1NController = 0, const Sbecore::ubigint jref1NTarget = 0, const Sbecore::ubigint jrefRef1NCommand = 0, const Sbecore::ubigint jrefRef1NError = 0, const Sbecore::ubigint jrefHk1NVector = 0, const Sbecore::ubigint jrefHk1NModule = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NPeripheral;
		Sbecore::ubigint jrefSil1NUnit;
		Sbecore::ubigint jref1NBank;
		Sbecore::ubigint jrefFwd1NController;
		Sbecore::ubigint jref1NTarget;
		Sbecore::ubigint jrefRef1NCommand;
		Sbecore::ubigint jrefRef1NError;
		Sbecore::ubigint jrefHk1NVector;
		Sbecore::ubigint jrefHk1NModule;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeSilRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeSilRecDo)
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
		* DpchEngData (full: DpchEngWdbeSilRecData)
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
	PnlWdbeSilRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSilRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeSilHk1NModule* pnlhk1nmodule;
	PnlWdbeSilHk1NVector* pnlhk1nvector;
	PnlWdbeSilRef1NError* pnlref1nerror;
	PnlWdbeSilRef1NCommand* pnlref1ncommand;
	PnlWdbeSil1NTarget* pnl1ntarget;
	PnlWdbeSilFwd1NController* pnlfwd1ncontroller;
	PnlWdbeSil1NBank* pnl1nbank;
	PnlWdbeSilSil1NUnit* pnlsil1nunit;
	PnlWdbeSil1NPeripheral* pnl1nperipheral;
	PnlWdbeSilDetail* pnldetail;

	WdbeMUnit recUnt;
	Sbecore::uint ixWSubsetUnt;

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
	bool handleCallWdbeUntUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeUnt_sysEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_silEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeUnt_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
