/**
	* \file PnlWdbeModRec.h
	* job handler for job PnlWdbeModRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMODREC_H
#define PNLWDBEMODREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeModDetail.h"
#include "PnlWdbeModKHdltype.h"
#include "PnlWdbeModAPar.h"
#include "PnlWdbeModHsm1NPipeline.h"
#include "PnlWdbeMod1NProcess.h"
#include "PnlWdbeModMdl1NPort.h"
#include "PnlWdbeModMdl1NGeneric.h"
#include "PnlWdbeModSup1NModule.h"
#include "PnlWdbeModRef1NSignal.h"
#include "PnlWdbeModRef1NSensitivity.h"
#include "PnlWdbeModRef1NVariable.h"
#include "PnlWdbeModMge1NSignal.h"
#include "PnlWdbeModCtrRef1NError.h"
#include "PnlWdbeModCtrHk1NVector.h"
#include "PnlWdbeModCtrRef1NCommand.h"
#include "PnlWdbeModMNPeripheral.h"
#include "PnlWdbeModCtdMNModule.h"
#include "PnlWdbeModCorMNModule.h"
#include "PnlWdbeModCtrMNCommand.h"

#define VecVWdbeModRecDo PnlWdbeModRec::VecVDo

#define ContInfWdbeModRec PnlWdbeModRec::ContInf
#define StatAppWdbeModRec PnlWdbeModRec::StatApp
#define StatShrWdbeModRec PnlWdbeModRec::StatShr
#define TagWdbeModRec PnlWdbeModRec::Tag

#define DpchAppWdbeModRecDo PnlWdbeModRec::DpchAppDo
#define DpchEngWdbeModRecData PnlWdbeModRec::DpchEngData

/**
	* PnlWdbeModRec
	*/
class PnlWdbeModRec : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeModRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeModRec)
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
		* StatApp (full: StatAppWdbeModRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneHsm1NPipeline = false, const bool initdone1NProcess = false, const bool initdoneMdl1NPort = false, const bool initdoneMdl1NGeneric = false, const bool initdoneSup1NModule = false, const bool initdoneRef1NSignal = false, const bool initdoneRef1NSensitivity = false, const bool initdoneRef1NVariable = false, const bool initdoneMge1NSignal = false, const bool initdoneCtrRef1NError = false, const bool initdoneCtrHk1NVector = false, const bool initdoneCtrRef1NCommand = false, const bool initdoneMNPeripheral = false, const bool initdoneCtdMNModule = false, const bool initdoneCorMNModule = false, const bool initdoneCtrMNCommand = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneHsm1NPipeline = false, const bool initdone1NProcess = false, const bool initdoneMdl1NPort = false, const bool initdoneMdl1NGeneric = false, const bool initdoneSup1NModule = false, const bool initdoneRef1NSignal = false, const bool initdoneRef1NSensitivity = false, const bool initdoneRef1NVariable = false, const bool initdoneMge1NSignal = false, const bool initdoneCtrRef1NError = false, const bool initdoneCtrHk1NVector = false, const bool initdoneCtrRef1NCommand = false, const bool initdoneMNPeripheral = false, const bool initdoneCtdMNModule = false, const bool initdoneCorMNModule = false, const bool initdoneCtrMNCommand = false);
	};

	/**
		* StatShr (full: StatShrWdbeModRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFKHDLTYPE = 3;
		static const Sbecore::uint JREFAPAR = 4;
		static const Sbecore::uint JREFHSM1NPIPELINE = 5;
		static const Sbecore::uint JREF1NPROCESS = 6;
		static const Sbecore::uint JREFMDL1NPORT = 7;
		static const Sbecore::uint JREFMDL1NGENERIC = 8;
		static const Sbecore::uint JREFSUP1NMODULE = 9;
		static const Sbecore::uint JREFREF1NSIGNAL = 10;
		static const Sbecore::uint JREFREF1NSENSITIVITY = 11;
		static const Sbecore::uint JREFREF1NVARIABLE = 12;
		static const Sbecore::uint JREFMGE1NSIGNAL = 13;
		static const Sbecore::uint JREFCTRREF1NERROR = 14;
		static const Sbecore::uint PNLCTRREF1NERRORAVAIL = 15;
		static const Sbecore::uint JREFCTRHK1NVECTOR = 16;
		static const Sbecore::uint PNLCTRHK1NVECTORAVAIL = 17;
		static const Sbecore::uint JREFCTRREF1NCOMMAND = 18;
		static const Sbecore::uint PNLCTRREF1NCOMMANDAVAIL = 19;
		static const Sbecore::uint JREFMNPERIPHERAL = 20;
		static const Sbecore::uint JREFCTDMNMODULE = 21;
		static const Sbecore::uint JREFCORMNMODULE = 22;
		static const Sbecore::uint JREFCTRMNCOMMAND = 23;
		static const Sbecore::uint PNLCTRMNCOMMANDAVAIL = 24;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 25;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefKHdltype = 0, const Sbecore::ubigint jrefAPar = 0, const Sbecore::ubigint jrefHsm1NPipeline = 0, const Sbecore::ubigint jref1NProcess = 0, const Sbecore::ubigint jrefMdl1NPort = 0, const Sbecore::ubigint jrefMdl1NGeneric = 0, const Sbecore::ubigint jrefSup1NModule = 0, const Sbecore::ubigint jrefRef1NSignal = 0, const Sbecore::ubigint jrefRef1NSensitivity = 0, const Sbecore::ubigint jrefRef1NVariable = 0, const Sbecore::ubigint jrefMge1NSignal = 0, const Sbecore::ubigint jrefCtrRef1NError = 0, const bool pnlctrref1nerrorAvail = false, const Sbecore::ubigint jrefCtrHk1NVector = 0, const bool pnlctrhk1nvectorAvail = false, const Sbecore::ubigint jrefCtrRef1NCommand = 0, const bool pnlctrref1ncommandAvail = false, const Sbecore::ubigint jrefMNPeripheral = 0, const Sbecore::ubigint jrefCtdMNModule = 0, const Sbecore::ubigint jrefCorMNModule = 0, const Sbecore::ubigint jrefCtrMNCommand = 0, const bool pnlctrmncommandAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefKHdltype;
		Sbecore::ubigint jrefAPar;
		Sbecore::ubigint jrefHsm1NPipeline;
		Sbecore::ubigint jref1NProcess;
		Sbecore::ubigint jrefMdl1NPort;
		Sbecore::ubigint jrefMdl1NGeneric;
		Sbecore::ubigint jrefSup1NModule;
		Sbecore::ubigint jrefRef1NSignal;
		Sbecore::ubigint jrefRef1NSensitivity;
		Sbecore::ubigint jrefRef1NVariable;
		Sbecore::ubigint jrefMge1NSignal;
		Sbecore::ubigint jrefCtrRef1NError;
		bool pnlctrref1nerrorAvail;
		Sbecore::ubigint jrefCtrHk1NVector;
		bool pnlctrhk1nvectorAvail;
		Sbecore::ubigint jrefCtrRef1NCommand;
		bool pnlctrref1ncommandAvail;
		Sbecore::ubigint jrefMNPeripheral;
		Sbecore::ubigint jrefCtdMNModule;
		Sbecore::ubigint jrefCorMNModule;
		Sbecore::ubigint jrefCtrMNCommand;
		bool pnlctrmncommandAvail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeModRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeModRecDo)
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
		* DpchEngData (full: DpchEngWdbeModRecData)
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

	bool evalPnlctrref1nerrorAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrhk1nvectorAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrref1ncommandAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrmncommandAvail(DbsWdbe* dbswdbe);
	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeModRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeModRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeModDetail* pnldetail;
	PnlWdbeModKHdltype* pnlkhdltype;
	PnlWdbeModAPar* pnlapar;
	PnlWdbeModHsm1NPipeline* pnlhsm1npipeline;
	PnlWdbeMod1NProcess* pnl1nprocess;
	PnlWdbeModMdl1NPort* pnlmdl1nport;
	PnlWdbeModMdl1NGeneric* pnlmdl1ngeneric;
	PnlWdbeModSup1NModule* pnlsup1nmodule;
	PnlWdbeModRef1NSignal* pnlref1nsignal;
	PnlWdbeModRef1NSensitivity* pnlref1nsensitivity;
	PnlWdbeModRef1NVariable* pnlref1nvariable;
	PnlWdbeModMge1NSignal* pnlmge1nsignal;
	PnlWdbeModCtrRef1NError* pnlctrref1nerror;
	PnlWdbeModCtrHk1NVector* pnlctrhk1nvector;
	PnlWdbeModCtrRef1NCommand* pnlctrref1ncommand;
	PnlWdbeModMNPeripheral* pnlmnperipheral;
	PnlWdbeModCtdMNModule* pnlctdmnmodule;
	PnlWdbeModCorMNModule* pnlcormnmodule;
	PnlWdbeModCtrMNCommand* pnlctrmncommand;

	WdbeMModule recMdl;
	Sbecore::uint ixWSubsetMdl;

	WdbeMController recCtr;

	WdbeMImbuf recImb;

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
	bool handleCallWdbeCtr_clrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwd_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwdEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_ctrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hktEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hku_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hkuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_imbEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_sup_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_supEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_tplEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_typEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtrUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeImbUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeMdlUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
