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

#include "PnlWdbeModCtrMNCommand.h"
#include "PnlWdbeModCtrRef1NError.h"
#include "PnlWdbeModCtrHk1NVector.h"
#include "PnlWdbeModCtrRef1NCommand.h"
#include "PnlWdbeModMge1NSignal.h"
#include "PnlWdbeModSup1NModule.h"
#include "PnlWdbeMod1NPeripheral.h"
#include "PnlWdbeModMdl1NSignal.h"
#include "PnlWdbeMod1NProcess.h"
#include "PnlWdbeModMdl1NPort.h"
#include "PnlWdbeModCor1NImbuf.h"
#include "PnlWdbeModMdl1NGeneric.h"
#include "PnlWdbeModAPar.h"
#include "PnlWdbeModKHdltype.h"
#include "PnlWdbeModDetail.h"

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
		* StatApp (full: StatAppWdbeModRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneMdl1NGeneric = false, const bool initdoneCor1NImbuf = false, const bool initdoneMdl1NPort = false, const bool initdone1NProcess = false, const bool initdoneMdl1NSignal = false, const bool initdone1NPeripheral = false, const bool initdoneSup1NModule = false, const bool initdoneMge1NSignal = false, const bool initdoneCtrRef1NCommand = false, const bool initdoneCtrHk1NVector = false, const bool initdoneCtrRef1NError = false, const bool initdoneCtrMNCommand = false);
	};

	/**
		* StatShr (full: StatShrWdbeModRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFKHDLTYPE = 3;
		static const Sbecore::uint JREFAPAR = 4;
		static const Sbecore::uint JREFMDL1NGENERIC = 5;
		static const Sbecore::uint JREFCOR1NIMBUF = 6;
		static const Sbecore::uint JREFMDL1NPORT = 7;
		static const Sbecore::uint JREF1NPROCESS = 8;
		static const Sbecore::uint JREFMDL1NSIGNAL = 9;
		static const Sbecore::uint JREF1NPERIPHERAL = 10;
		static const Sbecore::uint JREFSUP1NMODULE = 11;
		static const Sbecore::uint JREFMGE1NSIGNAL = 12;
		static const Sbecore::uint JREFCTRREF1NCOMMAND = 13;
		static const Sbecore::uint PNLCTRREF1NCOMMANDAVAIL = 14;
		static const Sbecore::uint JREFCTRHK1NVECTOR = 15;
		static const Sbecore::uint PNLCTRHK1NVECTORAVAIL = 16;
		static const Sbecore::uint JREFCTRREF1NERROR = 17;
		static const Sbecore::uint PNLCTRREF1NERRORAVAIL = 18;
		static const Sbecore::uint JREFCTRMNCOMMAND = 19;
		static const Sbecore::uint PNLCTRMNCOMMANDAVAIL = 20;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 21;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefKHdltype = 0, const Sbecore::ubigint jrefAPar = 0, const Sbecore::ubigint jrefMdl1NGeneric = 0, const Sbecore::ubigint jrefCor1NImbuf = 0, const Sbecore::ubigint jrefMdl1NPort = 0, const Sbecore::ubigint jref1NProcess = 0, const Sbecore::ubigint jrefMdl1NSignal = 0, const Sbecore::ubigint jref1NPeripheral = 0, const Sbecore::ubigint jrefSup1NModule = 0, const Sbecore::ubigint jrefMge1NSignal = 0, const Sbecore::ubigint jrefCtrRef1NCommand = 0, const bool pnlctrref1ncommandAvail = false, const Sbecore::ubigint jrefCtrHk1NVector = 0, const bool pnlctrhk1nvectorAvail = false, const Sbecore::ubigint jrefCtrRef1NError = 0, const bool pnlctrref1nerrorAvail = false, const Sbecore::ubigint jrefCtrMNCommand = 0, const bool pnlctrmncommandAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefKHdltype;
		Sbecore::ubigint jrefAPar;
		Sbecore::ubigint jrefMdl1NGeneric;
		Sbecore::ubigint jrefCor1NImbuf;
		Sbecore::ubigint jrefMdl1NPort;
		Sbecore::ubigint jref1NProcess;
		Sbecore::ubigint jrefMdl1NSignal;
		Sbecore::ubigint jref1NPeripheral;
		Sbecore::ubigint jrefSup1NModule;
		Sbecore::ubigint jrefMge1NSignal;
		Sbecore::ubigint jrefCtrRef1NCommand;
		bool pnlctrref1ncommandAvail;
		Sbecore::ubigint jrefCtrHk1NVector;
		bool pnlctrhk1nvectorAvail;
		Sbecore::ubigint jrefCtrRef1NError;
		bool pnlctrref1nerrorAvail;
		Sbecore::ubigint jrefCtrMNCommand;
		bool pnlctrmncommandAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeModRec)
		*/
	class Tag {

	public:
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

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalPnlctrref1ncommandAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrhk1nvectorAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrref1nerrorAvail(DbsWdbe* dbswdbe);
	bool evalPnlctrmncommandAvail(DbsWdbe* dbswdbe);
	bool evalButRegularizeActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeModRec(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeModRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWdbeModCtrMNCommand* pnlctrmncommand;
	PnlWdbeModCtrRef1NError* pnlctrref1nerror;
	PnlWdbeModCtrHk1NVector* pnlctrhk1nvector;
	PnlWdbeModCtrRef1NCommand* pnlctrref1ncommand;
	PnlWdbeModMge1NSignal* pnlmge1nsignal;
	PnlWdbeModSup1NModule* pnlsup1nmodule;
	PnlWdbeMod1NPeripheral* pnl1nperipheral;
	PnlWdbeModMdl1NSignal* pnlmdl1nsignal;
	PnlWdbeMod1NProcess* pnl1nprocess;
	PnlWdbeModMdl1NPort* pnlmdl1nport;
	PnlWdbeModCor1NImbuf* pnlcor1nimbuf;
	PnlWdbeModMdl1NGeneric* pnlmdl1ngeneric;
	PnlWdbeModAPar* pnlapar;
	PnlWdbeModKHdltype* pnlkhdltype;
	PnlWdbeModDetail* pnldetail;

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
	bool handleCallWdbeMdlUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeImbUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeCtrUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
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
	bool handleCallWdbeImb_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeImb_corEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwdEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwd_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_clrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif



