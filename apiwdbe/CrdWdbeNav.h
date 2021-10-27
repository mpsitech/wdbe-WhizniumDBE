/**
	* \file CrdWdbeNav.h
	* API code for job CrdWdbeNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBENAV_H
#define CRDWDBENAV_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavDo CrdWdbeNav::VecVDo
#define VecVWdbeNavSge CrdWdbeNav::VecVSge

#define ContInfWdbeNav CrdWdbeNav::ContInf
#define StatAppWdbeNav CrdWdbeNav::StatApp
#define StatShrWdbeNav CrdWdbeNav::StatShr
#define TagWdbeNav CrdWdbeNav::Tag

#define DpchAppWdbeNavDo CrdWdbeNav::DpchAppDo
#define DpchEngWdbeNavData CrdWdbeNav::DpchEngData

/**
	* CrdWdbeNav
	*/
namespace CrdWdbeNav {
	/**
		* VecVDo (full: VecVWdbeNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDFILCLICK = 8;
		static const Sbecore::uint MITCRDMCHCLICK = 9;
		static const Sbecore::uint MITCRDLIBCLICK = 10;
		static const Sbecore::uint MITCRDFAMCLICK = 11;
		static const Sbecore::uint MITCRDSILCLICK = 12;
		static const Sbecore::uint MITCRDMTPCLICK = 13;
		static const Sbecore::uint MITCRDPRJCLICK = 14;
		static const Sbecore::uint MITCRDVERCLICK = 15;
		static const Sbecore::uint MITCRDSYSCLICK = 16;
		static const Sbecore::uint MITCRDTRGCLICK = 17;
		static const Sbecore::uint MITCRDUNTCLICK = 18;
		static const Sbecore::uint MITCRDRLSCLICK = 19;
		static const Sbecore::uint MITCRDCPRCLICK = 20;
		static const Sbecore::uint MITCRDCVRCLICK = 21;
		static const Sbecore::uint MITCRDPPHCLICK = 22;
		static const Sbecore::uint MITCRDMODCLICK = 23;
		static const Sbecore::uint MITCRDVECCLICK = 24;
		static const Sbecore::uint MITCRDCMDCLICK = 25;
		static const Sbecore::uint MITCRDERRCLICK = 26;
		static const Sbecore::uint MITCRDPPLCLICK = 27;
		static const Sbecore::uint MITCRDSEGCLICK = 28;
		static const Sbecore::uint MITCRDBNKCLICK = 29;
		static const Sbecore::uint MITCRDPINCLICK = 30;
		static const Sbecore::uint MITCRDINTCLICK = 31;
		static const Sbecore::uint MITCRDSIGCLICK = 32;
		static const Sbecore::uint MITCRDUTLCLICK = 33;
		static const Sbecore::uint MITAPPMLCCLICK = 34;
		static const Sbecore::uint MITAPPLOICLICK = 35;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;
		static const Sbecore::uint ALRWDBETRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeNav)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNav)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEPRE = 6;
		static const Sbecore::uint INITDONEADMIN = 7;
		static const Sbecore::uint INITDONEGLOBAL = 8;
		static const Sbecore::uint INITDONEDEVDEV = 9;
		static const Sbecore::uint INITDONECOREDEV = 10;
		static const Sbecore::uint INITDONEHIGH = 11;
		static const Sbecore::uint INITDONELOW = 12;
		static const Sbecore::uint INITDONEAUXFCT = 13;

	public:
		StatApp(const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDevdev = false, const bool initdoneCoredev = false, const bool initdoneHigh = false, const bool initdoneLow = false, const bool initdoneAuxfct = false);

	public:
		Sbecore::uint ixWdbeVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneGlobal;
		bool initdoneDevdev;
		bool initdoneCoredev;
		bool initdoneHigh;
		bool initdoneLow;
		bool initdoneAuxfct;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNav)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGLOAINI = 1;
		static const Sbecore::uint SCRJREFDLGMNGLIC = 2;
		static const Sbecore::uint SCRJREFHEADBAR = 3;
		static const Sbecore::uint SCRJREFPRE = 4;
		static const Sbecore::uint PNLPREAVAIL = 5;
		static const Sbecore::uint SCRJREFADMIN = 6;
		static const Sbecore::uint PNLADMINAVAIL = 7;
		static const Sbecore::uint SCRJREFGLOBAL = 8;
		static const Sbecore::uint PNLGLOBALAVAIL = 9;
		static const Sbecore::uint SCRJREFDEVDEV = 10;
		static const Sbecore::uint PNLDEVDEVAVAIL = 11;
		static const Sbecore::uint SCRJREFCOREDEV = 12;
		static const Sbecore::uint PNLCOREDEVAVAIL = 13;
		static const Sbecore::uint SCRJREFHIGH = 14;
		static const Sbecore::uint PNLHIGHAVAIL = 15;
		static const Sbecore::uint SCRJREFLOW = 16;
		static const Sbecore::uint PNLLOWAVAIL = 17;
		static const Sbecore::uint SCRJREFAUXFCT = 18;
		static const Sbecore::uint PNLAUXFCTAVAIL = 19;
		static const Sbecore::uint MITSESSPSAVAIL = 20;
		static const Sbecore::uint MSPCRD1AVAIL = 21;
		static const Sbecore::uint MITCRDUSGAVAIL = 22;
		static const Sbecore::uint MITCRDUSRAVAIL = 23;
		static const Sbecore::uint MITCRDPRSAVAIL = 24;
		static const Sbecore::uint MITCRDFILAVAIL = 25;
		static const Sbecore::uint MSPCRD2AVAIL = 26;
		static const Sbecore::uint MITCRDMCHAVAIL = 27;
		static const Sbecore::uint MITCRDLIBAVAIL = 28;
		static const Sbecore::uint MITCRDFAMAVAIL = 29;
		static const Sbecore::uint MITCRDSILAVAIL = 30;
		static const Sbecore::uint MITCRDMTPAVAIL = 31;
		static const Sbecore::uint MSPCRD3AVAIL = 32;
		static const Sbecore::uint MITCRDPRJAVAIL = 33;
		static const Sbecore::uint MITCRDVERAVAIL = 34;
		static const Sbecore::uint MITCRDSYSAVAIL = 35;
		static const Sbecore::uint MITCRDSYSACTIVE = 36;
		static const Sbecore::uint MITCRDTRGAVAIL = 37;
		static const Sbecore::uint MITCRDTRGACTIVE = 38;
		static const Sbecore::uint MITCRDUNTAVAIL = 39;
		static const Sbecore::uint MITCRDUNTACTIVE = 40;
		static const Sbecore::uint MITCRDRLSAVAIL = 41;
		static const Sbecore::uint MITCRDRLSACTIVE = 42;
		static const Sbecore::uint MSPCRD4AVAIL = 43;
		static const Sbecore::uint MITCRDCPRAVAIL = 44;
		static const Sbecore::uint MITCRDCVRAVAIL = 45;
		static const Sbecore::uint MSPCRD5AVAIL = 46;
		static const Sbecore::uint MITCRDPPHAVAIL = 47;
		static const Sbecore::uint MITCRDPPHACTIVE = 48;
		static const Sbecore::uint MITCRDMODAVAIL = 49;
		static const Sbecore::uint MITCRDMODACTIVE = 50;
		static const Sbecore::uint MITCRDVECAVAIL = 51;
		static const Sbecore::uint MITCRDVECACTIVE = 52;
		static const Sbecore::uint MITCRDCMDAVAIL = 53;
		static const Sbecore::uint MITCRDCMDACTIVE = 54;
		static const Sbecore::uint MITCRDERRAVAIL = 55;
		static const Sbecore::uint MITCRDERRACTIVE = 56;
		static const Sbecore::uint MITCRDPPLAVAIL = 57;
		static const Sbecore::uint MITCRDPPLACTIVE = 58;
		static const Sbecore::uint MITCRDSEGAVAIL = 59;
		static const Sbecore::uint MITCRDSEGACTIVE = 60;
		static const Sbecore::uint MSPCRD6AVAIL = 61;
		static const Sbecore::uint MITCRDBNKAVAIL = 62;
		static const Sbecore::uint MITCRDBNKACTIVE = 63;
		static const Sbecore::uint MITCRDPINAVAIL = 64;
		static const Sbecore::uint MITCRDPINACTIVE = 65;
		static const Sbecore::uint MITCRDINTAVAIL = 66;
		static const Sbecore::uint MITCRDINTACTIVE = 67;
		static const Sbecore::uint MITCRDSIGAVAIL = 68;
		static const Sbecore::uint MITCRDSIGACTIVE = 69;
		static const Sbecore::uint MSPCRD7AVAIL = 70;
		static const Sbecore::uint MITCRDUTLAVAIL = 71;
		static const Sbecore::uint MSPAPP2AVAIL = 72;
		static const Sbecore::uint MITAPPMLCAVAIL = 73;
		static const Sbecore::uint MITAPPLOIAVAIL = 74;

	public:
		StatShr(const std::string& scrJrefDlgloaini = "", const std::string& scrJrefDlgmnglic = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefPre = "", const bool pnlpreAvail = false, const std::string& scrJrefAdmin = "", const bool pnladminAvail = false, const std::string& scrJrefGlobal = "", const bool pnlglobalAvail = false, const std::string& scrJrefDevdev = "", const bool pnldevdevAvail = false, const std::string& scrJrefCoredev = "", const bool pnlcoredevAvail = false, const std::string& scrJrefHigh = "", const bool pnlhighAvail = false, const std::string& scrJrefLow = "", const bool pnllowAvail = false, const std::string& scrJrefAuxfct = "", const bool pnlauxfctAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdMchAvail = true, const bool MitCrdLibAvail = true, const bool MitCrdFamAvail = true, const bool MitCrdSilAvail = true, const bool MitCrdMtpAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdVerAvail = true, const bool MitCrdSysAvail = true, const bool MitCrdSysActive = true, const bool MitCrdTrgAvail = true, const bool MitCrdTrgActive = true, const bool MitCrdUntAvail = true, const bool MitCrdUntActive = true, const bool MitCrdRlsAvail = true, const bool MitCrdRlsActive = true, const bool MspCrd4Avail = true, const bool MitCrdCprAvail = true, const bool MitCrdCvrAvail = true, const bool MspCrd5Avail = true, const bool MitCrdPphAvail = true, const bool MitCrdPphActive = true, const bool MitCrdModAvail = true, const bool MitCrdModActive = true, const bool MitCrdVecAvail = true, const bool MitCrdVecActive = true, const bool MitCrdCmdAvail = true, const bool MitCrdCmdActive = true, const bool MitCrdErrAvail = true, const bool MitCrdErrActive = true, const bool MitCrdPplAvail = true, const bool MitCrdPplActive = true, const bool MitCrdSegAvail = true, const bool MitCrdSegActive = true, const bool MspCrd6Avail = true, const bool MitCrdBnkAvail = true, const bool MitCrdBnkActive = true, const bool MitCrdPinAvail = true, const bool MitCrdPinActive = true, const bool MitCrdIntAvail = true, const bool MitCrdIntActive = true, const bool MitCrdSigAvail = true, const bool MitCrdSigActive = true, const bool MspCrd7Avail = true, const bool MitCrdUtlAvail = true, const bool MspApp2Avail = true, const bool MitAppMlcAvail = true, const bool MitAppLoiAvail = true);

	public:
		std::string scrJrefDlgloaini;
		std::string scrJrefDlgmnglic;
		std::string scrJrefHeadbar;
		std::string scrJrefPre;
		bool pnlpreAvail;
		std::string scrJrefAdmin;
		bool pnladminAvail;
		std::string scrJrefGlobal;
		bool pnlglobalAvail;
		std::string scrJrefDevdev;
		bool pnldevdevAvail;
		std::string scrJrefCoredev;
		bool pnlcoredevAvail;
		std::string scrJrefHigh;
		bool pnlhighAvail;
		std::string scrJrefLow;
		bool pnllowAvail;
		std::string scrJrefAuxfct;
		bool pnlauxfctAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdMchAvail;
		bool MitCrdLibAvail;
		bool MitCrdFamAvail;
		bool MitCrdSilAvail;
		bool MitCrdMtpAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdVerAvail;
		bool MitCrdSysAvail;
		bool MitCrdSysActive;
		bool MitCrdTrgAvail;
		bool MitCrdTrgActive;
		bool MitCrdUntAvail;
		bool MitCrdUntActive;
		bool MitCrdRlsAvail;
		bool MitCrdRlsActive;
		bool MspCrd4Avail;
		bool MitCrdCprAvail;
		bool MitCrdCvrAvail;
		bool MspCrd5Avail;
		bool MitCrdPphAvail;
		bool MitCrdPphActive;
		bool MitCrdModAvail;
		bool MitCrdModActive;
		bool MitCrdVecAvail;
		bool MitCrdVecActive;
		bool MitCrdCmdAvail;
		bool MitCrdCmdActive;
		bool MitCrdErrAvail;
		bool MitCrdErrActive;
		bool MitCrdPplAvail;
		bool MitCrdPplActive;
		bool MitCrdSegAvail;
		bool MitCrdSegActive;
		bool MspCrd6Avail;
		bool MitCrdBnkAvail;
		bool MitCrdBnkActive;
		bool MitCrdPinAvail;
		bool MitCrdPinActive;
		bool MitCrdIntAvail;
		bool MitCrdIntActive;
		bool MitCrdSigAvail;
		bool MitCrdSigActive;
		bool MspCrd7Avail;
		bool MitCrdUtlAvail;
		bool MspApp2Avail;
		bool MitAppMlcAvail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNav)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITSESSPS = 3;
		static const Sbecore::uint MITSESTRM = 4;
		static const Sbecore::uint MITCRDUSG = 5;
		static const Sbecore::uint MITCRDUSR = 6;
		static const Sbecore::uint MITCRDPRS = 7;
		static const Sbecore::uint MITCRDFIL = 8;
		static const Sbecore::uint MITCRDMCH = 9;
		static const Sbecore::uint MITCRDLIB = 10;
		static const Sbecore::uint MITCRDFAM = 11;
		static const Sbecore::uint MITCRDSIL = 12;
		static const Sbecore::uint MITCRDMTP = 13;
		static const Sbecore::uint MITCRDPRJ = 14;
		static const Sbecore::uint MITCRDVER = 15;
		static const Sbecore::uint MITCRDSYS = 16;
		static const Sbecore::uint MITCRDTRG = 17;
		static const Sbecore::uint MITCRDUNT = 18;
		static const Sbecore::uint MITCRDRLS = 19;
		static const Sbecore::uint MITCRDCPR = 20;
		static const Sbecore::uint MITCRDCVR = 21;
		static const Sbecore::uint MITCRDPPH = 22;
		static const Sbecore::uint MITCRDMOD = 23;
		static const Sbecore::uint MITCRDVEC = 24;
		static const Sbecore::uint MITCRDCMD = 25;
		static const Sbecore::uint MITCRDERR = 26;
		static const Sbecore::uint MITCRDPPL = 27;
		static const Sbecore::uint MITCRDSEG = 28;
		static const Sbecore::uint MITCRDBNK = 29;
		static const Sbecore::uint MITCRDPIN = 30;
		static const Sbecore::uint MITCRDINT = 31;
		static const Sbecore::uint MITCRDSIG = 32;
		static const Sbecore::uint MITCRDUTL = 33;
		static const Sbecore::uint MITAPPMLC = 34;
		static const Sbecore::uint MITAPPLOI = 35;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitSesSps = "", const std::string& MitSesTrm = "", const std::string& MitCrdUsg = "", const std::string& MitCrdUsr = "", const std::string& MitCrdPrs = "", const std::string& MitCrdFil = "", const std::string& MitCrdMch = "", const std::string& MitCrdLib = "", const std::string& MitCrdFam = "", const std::string& MitCrdSil = "", const std::string& MitCrdMtp = "", const std::string& MitCrdPrj = "", const std::string& MitCrdVer = "", const std::string& MitCrdSys = "", const std::string& MitCrdTrg = "", const std::string& MitCrdUnt = "", const std::string& MitCrdRls = "", const std::string& MitCrdCpr = "", const std::string& MitCrdCvr = "", const std::string& MitCrdPph = "", const std::string& MitCrdMod = "", const std::string& MitCrdVec = "", const std::string& MitCrdCmd = "", const std::string& MitCrdErr = "", const std::string& MitCrdPpl = "", const std::string& MitCrdSeg = "", const std::string& MitCrdBnk = "", const std::string& MitCrdPin = "", const std::string& MitCrdInt = "", const std::string& MitCrdSig = "", const std::string& MitCrdUtl = "", const std::string& MitAppMlc = "", const std::string& MitAppLoi = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitSesSps;
		std::string MitSesTrm;
		std::string MitCrdUsg;
		std::string MitCrdUsr;
		std::string MitCrdPrs;
		std::string MitCrdFil;
		std::string MitCrdMch;
		std::string MitCrdLib;
		std::string MitCrdFam;
		std::string MitCrdSil;
		std::string MitCrdMtp;
		std::string MitCrdPrj;
		std::string MitCrdVer;
		std::string MitCrdSys;
		std::string MitCrdTrg;
		std::string MitCrdUnt;
		std::string MitCrdRls;
		std::string MitCrdCpr;
		std::string MitCrdCvr;
		std::string MitCrdPph;
		std::string MitCrdMod;
		std::string MitCrdVec;
		std::string MitCrdCmd;
		std::string MitCrdErr;
		std::string MitCrdPpl;
		std::string MitCrdSeg;
		std::string MitCrdBnk;
		std::string MitCrdPin;
		std::string MitCrdInt;
		std::string MitCrdSig;
		std::string MitCrdUtl;
		std::string MitAppMlc;
		std::string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWdbeNavData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
