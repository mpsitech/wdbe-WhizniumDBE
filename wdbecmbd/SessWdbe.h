/**
	* \file SessWdbe.h
	* job handler for job SessWdbe (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef SESSWDBE_H
#define SESSWDBE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdWdbeNav.h"
#include "CrdWdbeUsg.h"
#include "CrdWdbeUsr.h"
#include "CrdWdbePrs.h"
#include "CrdWdbeFil.h"
#include "CrdWdbePrf.h"
#include "CrdWdbeMch.h"
#include "CrdWdbeLib.h"
#include "CrdWdbeFam.h"
#include "CrdWdbeSil.h"
#include "CrdWdbeMtp.h"
#include "CrdWdbePrj.h"
#include "CrdWdbeVer.h"
#include "CrdWdbeUnt.h"
#include "CrdWdbeCpr.h"
#include "CrdWdbeCvr.h"
#include "CrdWdbePph.h"
#include "CrdWdbeMod.h"
#include "CrdWdbeVec.h"
#include "CrdWdbeVit.h"
#include "CrdWdbeCmd.h"
#include "CrdWdbeErr.h"
#include "CrdWdbePpl.h"
#include "CrdWdbeSeg.h"
#include "CrdWdbeBnk.h"
#include "CrdWdbePin.h"
#include "CrdWdbeInt.h"
#include "CrdWdbeSns.h"
#include "CrdWdbeVar.h"
#include "CrdWdbeGen.h"
#include "CrdWdbePrt.h"
#include "CrdWdbeSig.h"
#include "CrdWdbeCdc.h"
#include "CrdWdbePrc.h"
#include "CrdWdbeFst.h"
#include "CrdWdbeCmp.h"
#include "CrdWdbeRls.h"
#include "CrdWdbeIdf.h"
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
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
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
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	SessWdbe(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWdbeMUser, const std::string& ip);
	~SessWdbe();

public:
	StatShr statshr;

	CrdWdbeNav* crdnav;
	std::map<Sbecore::ubigint, JobWdbe*> crdusgs;
	std::map<Sbecore::ubigint, JobWdbe*> crdusrs;
	std::map<Sbecore::ubigint, JobWdbe*> crdprss;
	std::map<Sbecore::ubigint, JobWdbe*> crdfils;
	std::map<Sbecore::ubigint, JobWdbe*> crdprfs;
	std::map<Sbecore::ubigint, JobWdbe*> crdmchs;
	std::map<Sbecore::ubigint, JobWdbe*> crdlibs;
	std::map<Sbecore::ubigint, JobWdbe*> crdfams;
	std::map<Sbecore::ubigint, JobWdbe*> crdsils;
	std::map<Sbecore::ubigint, JobWdbe*> crdmtps;
	std::map<Sbecore::ubigint, JobWdbe*> crdprjs;
	std::map<Sbecore::ubigint, JobWdbe*> crdvers;
	std::map<Sbecore::ubigint, JobWdbe*> crdunts;
	std::map<Sbecore::ubigint, JobWdbe*> crdcprs;
	std::map<Sbecore::ubigint, JobWdbe*> crdcvrs;
	std::map<Sbecore::ubigint, JobWdbe*> crdpphs;
	std::map<Sbecore::ubigint, JobWdbe*> crdmods;
	std::map<Sbecore::ubigint, JobWdbe*> crdvecs;
	std::map<Sbecore::ubigint, JobWdbe*> crdvits;
	std::map<Sbecore::ubigint, JobWdbe*> crdcmds;
	std::map<Sbecore::ubigint, JobWdbe*> crderrs;
	std::map<Sbecore::ubigint, JobWdbe*> crdppls;
	std::map<Sbecore::ubigint, JobWdbe*> crdsegs;
	std::map<Sbecore::ubigint, JobWdbe*> crdbnks;
	std::map<Sbecore::ubigint, JobWdbe*> crdpins;
	std::map<Sbecore::ubigint, JobWdbe*> crdints;
	std::map<Sbecore::ubigint, JobWdbe*> crdsnss;
	std::map<Sbecore::ubigint, JobWdbe*> crdvars;
	std::map<Sbecore::ubigint, JobWdbe*> crdgens;
	std::map<Sbecore::ubigint, JobWdbe*> crdprts;
	std::map<Sbecore::ubigint, JobWdbe*> crdsigs;
	std::map<Sbecore::ubigint, JobWdbe*> crdcdcs;
	std::map<Sbecore::ubigint, JobWdbe*> crdprcs;
	std::map<Sbecore::ubigint, JobWdbe*> crdfsts;
	std::map<Sbecore::ubigint, JobWdbe*> crdcmps;
	std::map<Sbecore::ubigint, JobWdbe*> crdrlss;
	std::map<Sbecore::ubigint, JobWdbe*> crdidfs;
	std::map<Sbecore::ubigint, JobWdbe*> crdutls;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void warnTerm(DbsWdbe* dbswdbe);
	void term(DbsWdbe* dbswdbe);

	void eraseCrd(std::map<Sbecore::ubigint, JobWdbe*>& subjobs);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixWdbeVCard);
	Sbecore::uint evalCrdverActive();
	Sbecore::uint evalCrduntActive();
	Sbecore::uint evalCrdcvrActive();
	Sbecore::uint evalCrdpphActive();
	Sbecore::uint evalCrdmodActive();
	Sbecore::uint evalCrdvecActive();
	Sbecore::uint evalCrdvitActive();
	Sbecore::uint evalCrdcmdActive();
	Sbecore::uint evalCrderrActive();
	Sbecore::uint evalCrdpplActive();
	Sbecore::uint evalCrdsegActive();
	Sbecore::uint evalCrdbnkActive();
	Sbecore::uint evalCrdpinActive();
	Sbecore::uint evalCrdintActive();
	Sbecore::uint evalCrdsnsActive();
	Sbecore::uint evalCrdvarActive();
	Sbecore::uint evalCrdgenActive();
	Sbecore::uint evalCrdprtActive();
	Sbecore::uint evalCrdsigActive();
	Sbecore::uint evalCrdcdcActive();
	Sbecore::uint evalCrdprcActive();
	Sbecore::uint evalCrdfstActive();
	Sbecore::uint evalCrdcmpActive();
	Sbecore::uint evalCrdrlsActive();

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
	bool handleCreateCrdcdc(DbsWdbe* dbswdbe);
	bool handleCreateCrdcmd(DbsWdbe* dbswdbe);
	bool handleCreateCrdcmp(DbsWdbe* dbswdbe);
	bool handleCreateCrdcpr(DbsWdbe* dbswdbe);
	bool handleCreateCrdcvr(DbsWdbe* dbswdbe);
	bool handleCreateCrderr(DbsWdbe* dbswdbe);
	bool handleCreateCrdfam(DbsWdbe* dbswdbe);
	bool handleCreateCrdfil(DbsWdbe* dbswdbe);
	bool handleCreateCrdfst(DbsWdbe* dbswdbe);
	bool handleCreateCrdgen(DbsWdbe* dbswdbe);
	bool handleCreateCrdidf(DbsWdbe* dbswdbe);
	bool handleCreateCrdint(DbsWdbe* dbswdbe);
	bool handleCreateCrdlib(DbsWdbe* dbswdbe);
	bool handleCreateCrdmch(DbsWdbe* dbswdbe);
	bool handleCreateCrdmod(DbsWdbe* dbswdbe);
	bool handleCreateCrdmtp(DbsWdbe* dbswdbe);
	bool handleCreateCrdpin(DbsWdbe* dbswdbe);
	bool handleCreateCrdpph(DbsWdbe* dbswdbe);
	bool handleCreateCrdppl(DbsWdbe* dbswdbe);
	bool handleCreateCrdprc(DbsWdbe* dbswdbe);
	bool handleCreateCrdprf(DbsWdbe* dbswdbe);
	bool handleCreateCrdprj(DbsWdbe* dbswdbe);
	bool handleCreateCrdprs(DbsWdbe* dbswdbe);
	bool handleCreateCrdprt(DbsWdbe* dbswdbe);
	bool handleCreateCrdrls(DbsWdbe* dbswdbe);
	bool handleCreateCrdseg(DbsWdbe* dbswdbe);
	bool handleCreateCrdsig(DbsWdbe* dbswdbe);
	bool handleCreateCrdsil(DbsWdbe* dbswdbe);
	bool handleCreateCrdsns(DbsWdbe* dbswdbe);
	bool handleCreateCrdunt(DbsWdbe* dbswdbe);
	bool handleCreateCrdusg(DbsWdbe* dbswdbe);
	bool handleCreateCrdusr(DbsWdbe* dbswdbe);
	bool handleCreateCrdutl(DbsWdbe* dbswdbe);
	bool handleCreateCrdvar(DbsWdbe* dbswdbe);
	bool handleCreateCrdvec(DbsWdbe* dbswdbe);
	bool handleCreateCrdver(DbsWdbe* dbswdbe);
	bool handleCreateCrdvit(DbsWdbe* dbswdbe);
	bool handleEraseCrdbnk(DbsWdbe* dbswdbe);
	bool handleEraseCrdcdc(DbsWdbe* dbswdbe);
	bool handleEraseCrdcmd(DbsWdbe* dbswdbe);
	bool handleEraseCrdcmp(DbsWdbe* dbswdbe);
	bool handleEraseCrdcpr(DbsWdbe* dbswdbe);
	bool handleEraseCrdcvr(DbsWdbe* dbswdbe);
	bool handleEraseCrderr(DbsWdbe* dbswdbe);
	bool handleEraseCrdfam(DbsWdbe* dbswdbe);
	bool handleEraseCrdfil(DbsWdbe* dbswdbe);
	bool handleEraseCrdfst(DbsWdbe* dbswdbe);
	bool handleEraseCrdgen(DbsWdbe* dbswdbe);
	bool handleEraseCrdidf(DbsWdbe* dbswdbe);
	bool handleEraseCrdint(DbsWdbe* dbswdbe);
	bool handleEraseCrdlib(DbsWdbe* dbswdbe);
	bool handleEraseCrdmch(DbsWdbe* dbswdbe);
	bool handleEraseCrdmod(DbsWdbe* dbswdbe);
	bool handleEraseCrdmtp(DbsWdbe* dbswdbe);
	bool handleEraseCrdpin(DbsWdbe* dbswdbe);
	bool handleEraseCrdpph(DbsWdbe* dbswdbe);
	bool handleEraseCrdppl(DbsWdbe* dbswdbe);
	bool handleEraseCrdprc(DbsWdbe* dbswdbe);
	bool handleEraseCrdprf(DbsWdbe* dbswdbe);
	bool handleEraseCrdprj(DbsWdbe* dbswdbe);
	bool handleEraseCrdprs(DbsWdbe* dbswdbe);
	bool handleEraseCrdprt(DbsWdbe* dbswdbe);
	bool handleEraseCrdrls(DbsWdbe* dbswdbe);
	bool handleEraseCrdseg(DbsWdbe* dbswdbe);
	bool handleEraseCrdsig(DbsWdbe* dbswdbe);
	bool handleEraseCrdsil(DbsWdbe* dbswdbe);
	bool handleEraseCrdsns(DbsWdbe* dbswdbe);
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
