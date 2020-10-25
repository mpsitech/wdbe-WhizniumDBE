/**
	* \file SessWdbe.h
	* job handler for job SessWdbe (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SESSWDBE_H
#define SESSWDBE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdWdbeNav.h"
#include "CrdWdbeUsg.h"
#include "CrdWdbeUsr.h"
#include "CrdWdbePrs.h"
#include "CrdWdbeFil.h"
#include "CrdWdbeMch.h"
#include "CrdWdbeLib.h"
#include "CrdWdbeFam.h"
#include "CrdWdbeSil.h"
#include "CrdWdbeMtp.h"
#include "CrdWdbePrj.h"
#include "CrdWdbeVer.h"
#include "CrdWdbeSys.h"
#include "CrdWdbeTrg.h"
#include "CrdWdbeUnt.h"
#include "CrdWdbeRls.h"
#include "CrdWdbeCpr.h"
#include "CrdWdbeCvr.h"
#include "CrdWdbeMod.h"
#include "CrdWdbeVec.h"
#include "CrdWdbeVit.h"
#include "CrdWdbeCmd.h"
#include "CrdWdbeErr.h"
#include "CrdWdbePph.h"
#include "CrdWdbeBnk.h"
#include "CrdWdbePin.h"
#include "CrdWdbeGen.h"
#include "CrdWdbePrt.h"
#include "CrdWdbeSig.h"
#include "CrdWdbePrc.h"
#include "CrdWdbeFst.h"
#include "CrdWdbeVar.h"
#include "CrdWdbeUtl.h"

#define StatShrSessWdbe SessWdbe::StatShr

#define DpchEngSessWdbeData SessWdbe::DpchEngData

/**
	* SessWdbe
	*/
class SessWdbe : public JobWdbe {

public:
	/**
		* StatShr (full: StatShrSessWdbe)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWdbeData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Xmlio::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Xmlio::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	SessWdbe(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWdbeMUser, const std::string& ip);
	~SessWdbe();

public:
	StatShr statshr;

	CrdWdbeNav* crdnav;
	std::list<CrdWdbeUsg*> crdusgs;
	std::list<CrdWdbeUsr*> crdusrs;
	std::list<CrdWdbePrs*> crdprss;
	std::list<CrdWdbeFil*> crdfils;
	std::list<CrdWdbeMch*> crdmchs;
	std::list<CrdWdbeLib*> crdlibs;
	std::list<CrdWdbeFam*> crdfams;
	std::list<CrdWdbeSil*> crdsils;
	std::list<CrdWdbeMtp*> crdmtps;
	std::list<CrdWdbePrj*> crdprjs;
	std::list<CrdWdbeVer*> crdvers;
	std::list<CrdWdbeSys*> crdsyss;
	std::list<CrdWdbeTrg*> crdtrgs;
	std::list<CrdWdbeUnt*> crdunts;
	std::list<CrdWdbeRls*> crdrlss;
	std::list<CrdWdbeCpr*> crdcprs;
	std::list<CrdWdbeCvr*> crdcvrs;
	std::list<CrdWdbeMod*> crdmods;
	std::list<CrdWdbeVec*> crdvecs;
	std::list<CrdWdbeVit*> crdvits;
	std::list<CrdWdbeCmd*> crdcmds;
	std::list<CrdWdbeErr*> crderrs;
	std::list<CrdWdbePph*> crdpphs;
	std::list<CrdWdbeBnk*> crdbnks;
	std::list<CrdWdbePin*> crdpins;
	std::list<CrdWdbeGen*> crdgens;
	std::list<CrdWdbePrt*> crdprts;
	std::list<CrdWdbeSig*> crdsigs;
	std::list<CrdWdbePrc*> crdprcs;
	std::list<CrdWdbeFst*> crdfsts;
	std::list<CrdWdbeVar*> crdvars;
	std::list<CrdWdbeUtl*> crdutls;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void term(DbsWdbe* dbswdbe);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixWdbeVCard);
	Sbecore::uint evalCrdverActive();
	Sbecore::uint evalCrdsysActive();
	Sbecore::uint evalCrdtrgActive();
	Sbecore::uint evalCrduntActive();
	Sbecore::uint evalCrdrlsActive();
	Sbecore::uint evalCrdcvrActive();
	Sbecore::uint evalCrdmodActive();
	Sbecore::uint evalCrdvecActive();
	Sbecore::uint evalCrdvitActive();
	Sbecore::uint evalCrdcmdActive();
	Sbecore::uint evalCrderrActive();
	Sbecore::uint evalCrdpphActive();
	Sbecore::uint evalCrdbnkActive();
	Sbecore::uint evalCrdpinActive();
	Sbecore::uint evalCrdgenActive();
	Sbecore::uint evalCrdprtActive();
	Sbecore::uint evalCrdsigActive();
	Sbecore::uint evalCrdprcActive();
	Sbecore::uint evalCrdfstActive();
	Sbecore::uint evalCrdvarActive();

	Sbecore::uint checkCrdaccess(const Sbecore::uint ixWdbeVCard);
	void getIxCrdacc(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCard, const bool adm, ListWdbeRMUserMUsergroup& urus, const Sbecore::ubigint refWdbeMUser, Sbecore::uint& ixWdbeWAccess);

	Sbecore::uint checkRecaccess(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVCard, const Sbecore::ubigint ref);
	void logRecaccess(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint preUref, const Sbecore::uint ixWdbeVCard, const Sbecore::ubigint unvUref);

	Sbecore::uint crdToMtb(const Sbecore::uint ixWdbeVCard);
	Sbecore::uint preToMtb(const Sbecore::uint ixWdbeVPreset);
	bool hasActive(const Sbecore::uint ixWdbeVCard);
	bool hasGrpown(const Sbecore::uint ixWdbeVMaintable);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:
	bool handleCreateCrdbnk(DbsWdbe* dbswdbe);
	bool handleCreateCrdcmd(DbsWdbe* dbswdbe);
	bool handleCreateCrdcpr(DbsWdbe* dbswdbe);
	bool handleCreateCrdcvr(DbsWdbe* dbswdbe);
	bool handleCreateCrderr(DbsWdbe* dbswdbe);
	bool handleCreateCrdfam(DbsWdbe* dbswdbe);
	bool handleCreateCrdfil(DbsWdbe* dbswdbe);
	bool handleCreateCrdfst(DbsWdbe* dbswdbe);
	bool handleCreateCrdgen(DbsWdbe* dbswdbe);
	bool handleCreateCrdlib(DbsWdbe* dbswdbe);
	bool handleCreateCrdmch(DbsWdbe* dbswdbe);
	bool handleCreateCrdmod(DbsWdbe* dbswdbe);
	bool handleCreateCrdmtp(DbsWdbe* dbswdbe);
	bool handleCreateCrdpin(DbsWdbe* dbswdbe);
	bool handleCreateCrdpph(DbsWdbe* dbswdbe);
	bool handleCreateCrdprc(DbsWdbe* dbswdbe);
	bool handleCreateCrdprj(DbsWdbe* dbswdbe);
	bool handleCreateCrdprs(DbsWdbe* dbswdbe);
	bool handleCreateCrdprt(DbsWdbe* dbswdbe);
	bool handleCreateCrdrls(DbsWdbe* dbswdbe);
	bool handleCreateCrdsig(DbsWdbe* dbswdbe);
	bool handleCreateCrdsil(DbsWdbe* dbswdbe);
	bool handleCreateCrdsys(DbsWdbe* dbswdbe);
	bool handleCreateCrdtrg(DbsWdbe* dbswdbe);
	bool handleCreateCrdunt(DbsWdbe* dbswdbe);
	bool handleCreateCrdusg(DbsWdbe* dbswdbe);
	bool handleCreateCrdusr(DbsWdbe* dbswdbe);
	bool handleCreateCrdutl(DbsWdbe* dbswdbe);
	bool handleCreateCrdvar(DbsWdbe* dbswdbe);
	bool handleCreateCrdvec(DbsWdbe* dbswdbe);
	bool handleCreateCrdver(DbsWdbe* dbswdbe);
	bool handleCreateCrdvit(DbsWdbe* dbswdbe);
	bool handleEraseCrdbnk(DbsWdbe* dbswdbe);
	bool handleEraseCrdcmd(DbsWdbe* dbswdbe);
	bool handleEraseCrdcpr(DbsWdbe* dbswdbe);
	bool handleEraseCrdcvr(DbsWdbe* dbswdbe);
	bool handleEraseCrderr(DbsWdbe* dbswdbe);
	bool handleEraseCrdfam(DbsWdbe* dbswdbe);
	bool handleEraseCrdfil(DbsWdbe* dbswdbe);
	bool handleEraseCrdfst(DbsWdbe* dbswdbe);
	bool handleEraseCrdgen(DbsWdbe* dbswdbe);
	bool handleEraseCrdlib(DbsWdbe* dbswdbe);
	bool handleEraseCrdmch(DbsWdbe* dbswdbe);
	bool handleEraseCrdmod(DbsWdbe* dbswdbe);
	bool handleEraseCrdmtp(DbsWdbe* dbswdbe);
	bool handleEraseCrdpin(DbsWdbe* dbswdbe);
	bool handleEraseCrdpph(DbsWdbe* dbswdbe);
	bool handleEraseCrdprc(DbsWdbe* dbswdbe);
	bool handleEraseCrdprj(DbsWdbe* dbswdbe);
	bool handleEraseCrdprs(DbsWdbe* dbswdbe);
	bool handleEraseCrdprt(DbsWdbe* dbswdbe);
	bool handleEraseCrdrls(DbsWdbe* dbswdbe);
	bool handleEraseCrdsig(DbsWdbe* dbswdbe);
	bool handleEraseCrdsil(DbsWdbe* dbswdbe);
	bool handleEraseCrdsys(DbsWdbe* dbswdbe);
	bool handleEraseCrdtrg(DbsWdbe* dbswdbe);
	bool handleEraseCrdunt(DbsWdbe* dbswdbe);
	bool handleEraseCrdusg(DbsWdbe* dbswdbe);
	bool handleEraseCrdusr(DbsWdbe* dbswdbe);
	bool handleEraseCrdutl(DbsWdbe* dbswdbe);
	bool handleEraseCrdvar(DbsWdbe* dbswdbe);
	bool handleEraseCrdvec(DbsWdbe* dbswdbe);
	bool handleEraseCrdver(DbsWdbe* dbswdbe);
	bool handleEraseCrdvit(DbsWdbe* dbswdbe);

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeCrdActive(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, Sbecore::uint& ixRet);
	bool handleCallWdbeCrdClose(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWdbeCrdOpen(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool handleCallWdbeLog(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool handleCallWdbeRecaccess(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool handleCallWdbeRefPreSet(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

