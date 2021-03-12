/**
	* \file Wdbe.h
	* Wdbe global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBE_H
#define WDBE_H

#define WDBE_VERSION "1.1.5"
#define WDBE_VERSION_MAJOR 1
#define WDBE_VERSION_MINOR 1
#define WDBE_VERSION_SUB 5

#include <sys/wait.h> // IP include.cust --- ILINE

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "VecWdbeVBasereptype.h"
#include "VecWdbeVCall.h"
#include "VecWdbeVDpch.h"
#include "VecWdbeVError.h"
#include "VecWdbeVExpstate.h"
#include "VecWdbeVIop.h"
#include "VecWdbeVJob.h"
#include "VecWdbeVMimetype.h"
#include "VecWdbeVOpengtype.h"
#include "VecWdbeVOppack.h"
#include "VecWdbeVQrystate.h"
#include "VecWdbeVReqitmode.h"
#include "VecWdbeVStub.h"
#include "VecWdbeVTag.h"

#include <DbsWdbe.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
	* Acv
	*/
namespace Acv {
	Sbecore::ubigint addfile(DbsWdbe* dbswdbe, const std::string& acvpath, const std::string& path, const Sbecore::ubigint grp, const Sbecore::ubigint own, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, const std::string& osrefKContent, const std::string& Filename, const std::string& srefKMimetype, const std::string& Comment);
	void alterfile(DbsWdbe* dbswdbe, const std::string& acvpath, const std::string& path, const Sbecore::ubigint ref);
	std::string getfile(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMFile);
};

/**
	* Lop
	*/
namespace Lop {
	void apply(const Sbecore::uint ixWdbeVLop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);

	void insert(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
};

/**
	* Oolop
	*/
namespace Oolop {
	void apply(const Sbecore::uint ixWdbeVOolop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);

	void insertBefore(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void insertAfter(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void toBefore(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void toAfter(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void swap(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
};

/**
	* Tmp
	*/
namespace Tmp {
	std::string newfile(const std::string& tmppath, const std::string& ext);
	std::string newfolder(const std::string& tmppath);
	std::string random();
};

// IP cust --- INSERT

/**
	* Wdbe
	*/
namespace Wdbe {
	// IP gbl --- IBEGIN
	Sbecore::ubigint getRefMtp(DbsWdbe* dbswdbe, const std::string& sref);
	void getSrefsMtpCustops(DbsWdbe* dbswdbe, std::map<Sbecore::ubigint,std::string>& srefsMtpCustops, const Sbecore::uint ixWdbeVKeylist);

	std::string getPrjshort(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMVersion);
	void updateVerste(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMVersion, const Sbecore::uint ixVState);

	bool getLibmkf(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMLibrary, const Sbecore::ubigint x1RefWdbeMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x2SrefKTag, std::string& Val);

	bool getMchmkf(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x1SrefKTag, std::string& Val);
	bool getMchpar(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x1SrefKKey, std::string& Val);

	void analyzeUnt(DbsWdbe* dbswdbe, WdbeMUnit* unt, std::string& srefroot, ListWdbeMVector& vecs, ListWdbeMController& ctrs, ListWdbeMImbuf& imbs, ListWdbeMCommand& cmds, ListWdbeMError& errs, Sbecore::ubigint& refHostif, Sbecore::uint& ixImbCmdinv, Sbecore::uint& ixImbCmdret, bool& hasvecbuf, bool& hasvecctr, bool& hasveccmd, bool& hasvecerr, bool& hasspeccmd);

	void getPairsCmdbus(DbsWdbe* dbswdbe, ListWdbeMModule& mdls, std::set<std::pair<std::string,std::string> >& pairsCmdbus);

	std::string getImbshort(WdbeMImbuf* imb);

	void analyzeCmd(DbsWdbe* dbswdbe, WdbeMCommand* cmd, WdbeMUnit* unt, WdbeMController* ctr, ListWdbeAMCommandInvpar& ipas, ListWdbeAMCommandRetpar& rpas, std::string& supsref, std::string& subsref);
	void getCmdSupsubsref(WdbeMCommand* cmd, WdbeMUnit* unt, WdbeMController* ctr, std::string& supsref, std::string& subsref);

	void analyzeErr(DbsWdbe* dbswdbe, WdbeMError* err, WdbeMUnit* unt, WdbeMController* ctr, ListWdbeAMErrorPar& epas, std::string& supsref, std::string& subsref);
	void getErrSupsubsref(WdbeMError* err, WdbeMUnit* unt, WdbeMController* ctr, std::string& supsref, std::string& subsref);

	unsigned int getLenInv(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMCommand);
	unsigned int getLenRet(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMCommand);
	unsigned int getLenErr(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMError);

	std::string getCompsref(DbsWdbe* dbswdbe, WdbeMModule* mdl);

	bool getMpa(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& x1SrefKKey, std::string& Val);
	void setMpa(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& x1SrefKKey, const std::string& Val);

	bool getGenDfv(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, std::string& Defval);
	void setGenDfv(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const std::string& Defval);
	void setGenSrc(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const std::string& srcSrefWdbeMGeneric);

	void setPrtWdt(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const Sbecore::usmallint Width);
	void setPrtDfv(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const std::string& Defval);
	void setPrtCpr(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const std::string& cprSrefWdbeMPort);
	void setPrtCsi(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMModule, const std::string& sref, const std::string& csiSrefWdbeMSignal);

	unsigned int getParlen(const Sbecore::uint ixWdbeVPartype, const Sbecore::utinyint Length);
	void getRange(const std::string& s, std::string& sref, bool& hasrng, Sbecore::utinyint& from, Sbecore::utinyint& to, std::string& ix);

	void levelUnts(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMVersion, ListWdbeMUnit& unts, std::vector<unsigned int>& lvlsUnts);
	void sortUnts(ListWdbeMUnit& unts, std::vector<unsigned int>& lvlsUnts, bool buNotTd = false);
	void levelUntmdls(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMUnit, ListWdbeMModule& mdls, std::vector<unsigned int>& lvlsMdls);
	void sortMdls(ListWdbeMModule& mdls, std::vector<unsigned int>& lvlsMdls, bool buNotTd = false);
	void levelMdls(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMVersion, ListWdbeMModule& mdls, std::vector<unsigned int>& lvlsMdls, bool buNotTd = false, bool lvlunts = false, bool lvluntsBuNotTd = false);
	void showLvlsMdls(DbsWdbe* dbswdbe, ListWdbeMModule& mdls, std::vector<unsigned int>& lvlsMdls);

	unsigned int valToWidth(unsigned long long val);

	std::string binToHex(unsigned char bin);
	unsigned char hexToBin(std::string hex);

	int run(const std::string& cmd);
	bool tgz(const std::string& infolder, const std::string& tgzfile, const bool verbose = false);
	bool untgz(const std::string& tgzfile, const std::string& outfolder, const bool verbose = false);
	// IP gbl --- IEND
};

/**
	* OpengWdbe
	*/
namespace OpengWdbe {
	void getIcsWdbeVOppackByIxWdbeVOpengtype(const Sbecore::uint ixWdbeVOpengtype, std::vector<Sbecore::uint>& icsWdbeVOppack);
	void getIcsWdbeVDpchByIxWdbeVOppack(const Sbecore::uint ixWdbeVOppack, std::set<Sbecore::uint>& icsWdbeVDpch);
};

/**
	* StubWdbe
	*/
namespace StubWdbe {
	std::string getStub(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVStub, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);

	std::string getStubBnkSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubBnkStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCmdStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCprStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCtrLong(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCtrSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCtrStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCvrNo(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCvrStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubErrStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFamStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFilStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFsmStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFstStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGenStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGroup(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubImbStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLibSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLibStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMchSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMchStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMdlHsref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMdlSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMdlStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubModStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMtpStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOwner(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPinStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPphStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrcStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrjShort(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrjStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrsStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrtSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrtStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRlsLong(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRlsStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesMenu(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSigSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSigStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSilStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSysStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTrgSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTrgStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUniStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUntSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUntStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsgStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrPrs(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVarStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVecStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerNo(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerShort(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVitStd(DbsWdbe* dbswdbe, const Sbecore::ubigint ref, const Sbecore::uint ixWdbeVLocale = VecWdbeVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
	* WdbeException
	*/
class WdbeException : public Sbecore::SbeException {

public:
	static const Sbecore::uint LIC_AUTH = 1001;
	static const Sbecore::uint LIC_CTWARN = 1002;
	static const Sbecore::uint LIC_CTLOST = 1003;

public:
	WdbeException(const Sbecore::uint ix, const std::map<std::string,std::string>& vals);

public:
	std::string getSref();
};

/**
	* ContInfWdbeAlert
	*/
class ContInfWdbeAlert : public Sbecore::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfWdbeAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const ContInfWdbeAlert* comp);
};

/**
	* DpchWdbe
	*/
class DpchWdbe : public Sbecore::Block {

public:
	DpchWdbe(const Sbecore::uint ixWdbeVDpch = 0);
	virtual ~DpchWdbe();

public:
	Sbecore::uint ixWdbeVDpch;
};

/**
	* DpchInvWdbe
	*/
class DpchInvWdbe : public DpchWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchInvWdbe(const Sbecore::uint ixWdbeVDpch = VecWdbeVDpch::DPCHINVWDBE, const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchInvWdbe();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbe
	*/
class DpchRetWdbe : public DpchWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;

public:
	DpchRetWdbe(const Sbecore::uint ixWdbeVDpch = VecWdbeVDpch::DPCHRETWDBE, const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::utinyint ixOpVOpres = Sbecore::VecOpVOpres::PROGRESS, const Sbecore::utinyint pdone = 0);
	virtual ~DpchRetWdbe();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;
	Sbecore::utinyint ixOpVOpres;
	Sbecore::utinyint pdone;

public:
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif
