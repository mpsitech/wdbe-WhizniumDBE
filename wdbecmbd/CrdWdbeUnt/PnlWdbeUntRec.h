/**
	* \file PnlWdbeUntRec.h
	* job handler for job PnlWdbeUntRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEUNTREC_H
#define PNLWDBEUNTREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeUntHk1NVector.h"
#include "PnlWdbeUntHk1NModule.h"
#include "PnlWdbeUntRef1NCommand.h"
#include "PnlWdbeUntRef1NSignal.h"
#include "PnlWdbeUntRef1NError.h"
#include "PnlWdbeUntFwd1NController.h"
#include "PnlWdbeUnt1NTarget.h"
#include "PnlWdbeUnt1NBank.h"
#include "PnlWdbeUnt1NPeripheral.h"
#include "PnlWdbeUntSil1NUnit.h"
#include "PnlWdbeUnt1NInterrupt.h"
#include "PnlWdbeUntDetail.h"

#define VecVWdbeUntRecDo PnlWdbeUntRec::VecVDo

#define ContInfWdbeUntRec PnlWdbeUntRec::ContInf
#define StatAppWdbeUntRec PnlWdbeUntRec::StatApp
#define StatShrWdbeUntRec PnlWdbeUntRec::StatShr
#define TagWdbeUntRec PnlWdbeUntRec::Tag

#define DpchAppWdbeUntRecDo PnlWdbeUntRec::DpchAppDo
#define DpchEngWdbeUntRecData PnlWdbeUntRec::DpchEngData

/**
	* PnlWdbeUntRec
	*/
class PnlWdbeUntRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeUntRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeUntRec)
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
		* StatApp (full: StatAppWdbeUntRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdone1NInterrupt = false, const bool initdoneSil1NUnit = false, const bool initdone1NPeripheral = false, const bool initdone1NBank = false, const bool initdoneFwd1NController = false, const bool initdone1NTarget = false, const bool initdoneRef1NSignal = false, const bool initdoneRef1NError = false, const bool initdoneRef1NCommand = false, const bool initdoneHk1NModule = false, const bool initdoneHk1NVector = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NInterrupt = false, const bool initdoneSil1NUnit = false, const bool initdone1NPeripheral = false, const bool initdone1NBank = false, const bool initdoneFwd1NController = false, const bool initdone1NTarget = false, const bool initdoneRef1NSignal = false, const bool initdoneRef1NError = false, const bool initdoneRef1NCommand = false, const bool initdoneHk1NModule = false, const bool initdoneHk1NVector = false);
	};

	/**
		* StatShr (full: StatShrWdbeUntRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NINTERRUPT = 3;
		static const Sbecore::uint JREFSIL1NUNIT = 4;
		static const Sbecore::uint PNLSIL1NUNITAVAIL = 5;
		static const Sbecore::uint JREF1NPERIPHERAL = 6;
		static const Sbecore::uint JREF1NBANK = 7;
		static const Sbecore::uint JREFFWD1NCONTROLLER = 8;
		static const Sbecore::uint JREF1NTARGET = 9;
		static const Sbecore::uint JREFREF1NSIGNAL = 10;
		static const Sbecore::uint JREFREF1NERROR = 11;
		static const Sbecore::uint JREFREF1NCOMMAND = 12;
		static const Sbecore::uint JREFHK1NMODULE = 13;
		static const Sbecore::uint JREFHK1NVECTOR = 14;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NInterrupt = 0, const Sbecore::ubigint jrefSil1NUnit = 0, const bool pnlsil1nunitAvail = false, const Sbecore::ubigint jref1NPeripheral = 0, const Sbecore::ubigint jref1NBank = 0, const Sbecore::ubigint jrefFwd1NController = 0, const Sbecore::ubigint jref1NTarget = 0, const Sbecore::ubigint jrefRef1NSignal = 0, const Sbecore::ubigint jrefRef1NError = 0, const Sbecore::ubigint jrefRef1NCommand = 0, const Sbecore::ubigint jrefHk1NModule = 0, const Sbecore::ubigint jrefHk1NVector = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NInterrupt;
		Sbecore::ubigint jrefSil1NUnit;
		bool pnlsil1nunitAvail;
		Sbecore::ubigint jref1NPeripheral;
		Sbecore::ubigint jref1NBank;
		Sbecore::ubigint jrefFwd1NController;
		Sbecore::ubigint jref1NTarget;
		Sbecore::ubigint jrefRef1NSignal;
		Sbecore::ubigint jrefRef1NError;
		Sbecore::ubigint jrefRef1NCommand;
		Sbecore::ubigint jrefHk1NModule;
		Sbecore::ubigint jrefHk1NVector;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeUntRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeUntRecDo)
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
		* DpchEngData (full: DpchEngWdbeUntRecData)
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

	bool evalPnlsil1nunitAvail(DbsWdbe* dbswdbe);
	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeUntRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeUntRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeUntHk1NVector* pnlhk1nvector;
	PnlWdbeUntHk1NModule* pnlhk1nmodule;
	PnlWdbeUntRef1NCommand* pnlref1ncommand;
	PnlWdbeUntRef1NSignal* pnlref1nsignal;
	PnlWdbeUntRef1NError* pnlref1nerror;
	PnlWdbeUntFwd1NController* pnlfwd1ncontroller;
	PnlWdbeUnt1NTarget* pnl1ntarget;
	PnlWdbeUnt1NBank* pnl1nbank;
	PnlWdbeUnt1NPeripheral* pnl1nperipheral;
	PnlWdbeUntSil1NUnit* pnlsil1nunit;
	PnlWdbeUnt1NInterrupt* pnl1ninterrupt;
	PnlWdbeUntDetail* pnldetail;

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
	bool handleCallWdbeUnt_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeUnt_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeUnt_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_silEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_sysEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
