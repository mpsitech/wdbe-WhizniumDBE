/**
	* \file PnlWdbeNavHigh.h
	* API code for job PnlWdbeNavHigh (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVHIGH_H
#define PNLWDBENAVHIGH_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavHighDo PnlWdbeNavHigh::VecVDo

#define ContIacWdbeNavHigh PnlWdbeNavHigh::ContIac
#define StatAppWdbeNavHigh PnlWdbeNavHigh::StatApp
#define StatShrWdbeNavHigh PnlWdbeNavHigh::StatShr
#define TagWdbeNavHigh PnlWdbeNavHigh::Tag

#define DpchAppWdbeNavHighData PnlWdbeNavHigh::DpchAppData
#define DpchAppWdbeNavHighDo PnlWdbeNavHigh::DpchAppDo
#define DpchEngWdbeNavHighData PnlWdbeNavHigh::DpchEngData

/**
	* PnlWdbeNavHigh
	*/
namespace PnlWdbeNavHigh {
	/**
		* VecVDo (full: VecVWdbeNavHighDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPPHVIEWCLICK = 1;
		static const Sbecore::uint BUTPPHNEWCRDCLICK = 2;
		static const Sbecore::uint BUTMODVIEWCLICK = 3;
		static const Sbecore::uint BUTMODNEWCRDCLICK = 4;
		static const Sbecore::uint BUTVECVIEWCLICK = 5;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 6;
		static const Sbecore::uint BUTVITVIEWCLICK = 7;
		static const Sbecore::uint BUTCMDVIEWCLICK = 8;
		static const Sbecore::uint BUTCMDNEWCRDCLICK = 9;
		static const Sbecore::uint BUTERRVIEWCLICK = 10;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 11;
		static const Sbecore::uint BUTPPLVIEWCLICK = 12;
		static const Sbecore::uint BUTPPLNEWCRDCLICK = 13;
		static const Sbecore::uint BUTSEGVIEWCLICK = 14;
		static const Sbecore::uint BUTSEGNEWCRDCLICK = 15;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavHigh)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPPH = 1;
		static const Sbecore::uint NUMFLSTMOD = 2;
		static const Sbecore::uint NUMFLSTVEC = 3;
		static const Sbecore::uint NUMFLSTVIT = 4;
		static const Sbecore::uint NUMFLSTCMD = 5;
		static const Sbecore::uint NUMFLSTERR = 6;
		static const Sbecore::uint NUMFLSTPPL = 7;
		static const Sbecore::uint NUMFLSTSEG = 8;

	public:
		ContIac(const Sbecore::uint numFLstPph = 1, const Sbecore::uint numFLstMod = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstCmd = 1, const Sbecore::uint numFLstErr = 1, const Sbecore::uint numFLstPpl = 1, const Sbecore::uint numFLstSeg = 1);

	public:
		Sbecore::uint numFLstPph;
		Sbecore::uint numFLstMod;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstCmd;
		Sbecore::uint numFLstErr;
		Sbecore::uint numFLstPpl;
		Sbecore::uint numFLstSeg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavHigh)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTPPHALT = 2;
		static const Sbecore::uint LSTMODALT = 3;
		static const Sbecore::uint LSTVECALT = 4;
		static const Sbecore::uint LSTVITALT = 5;
		static const Sbecore::uint LSTCMDALT = 6;
		static const Sbecore::uint LSTERRALT = 7;
		static const Sbecore::uint LSTPPLALT = 8;
		static const Sbecore::uint LSTSEGALT = 9;
		static const Sbecore::uint LSTPPHNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTMODNUMFIRSTDISP = 11;
		static const Sbecore::uint LSTVECNUMFIRSTDISP = 12;
		static const Sbecore::uint LSTVITNUMFIRSTDISP = 13;
		static const Sbecore::uint LSTCMDNUMFIRSTDISP = 14;
		static const Sbecore::uint LSTERRNUMFIRSTDISP = 15;
		static const Sbecore::uint LSTPPLNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTSEGNUMFIRSTDISP = 17;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPphAlt = true, const bool LstModAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstCmdAlt = true, const bool LstErrAlt = true, const bool LstPplAlt = true, const bool LstSegAlt = true, const Sbecore::uint LstPphNumFirstdisp = 1, const Sbecore::uint LstModNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstCmdNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1, const Sbecore::uint LstPplNumFirstdisp = 1, const Sbecore::uint LstSegNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstPphAlt;
		bool LstModAlt;
		bool LstVecAlt;
		bool LstVitAlt;
		bool LstCmdAlt;
		bool LstErrAlt;
		bool LstPplAlt;
		bool LstSegAlt;
		Sbecore::uint LstPphNumFirstdisp;
		Sbecore::uint LstModNumFirstdisp;
		Sbecore::uint LstVecNumFirstdisp;
		Sbecore::uint LstVitNumFirstdisp;
		Sbecore::uint LstCmdNumFirstdisp;
		Sbecore::uint LstErrNumFirstdisp;
		Sbecore::uint LstPplNumFirstdisp;
		Sbecore::uint LstSegNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavHigh)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPPHAVAIL = 1;
		static const Sbecore::uint BUTPPHVIEWACTIVE = 2;
		static const Sbecore::uint BUTPPHNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTMODAVAIL = 4;
		static const Sbecore::uint BUTMODVIEWACTIVE = 5;
		static const Sbecore::uint BUTMODNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTVECAVAIL = 7;
		static const Sbecore::uint BUTVECVIEWACTIVE = 8;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTVITAVAIL = 10;
		static const Sbecore::uint BUTVITVIEWACTIVE = 11;
		static const Sbecore::uint LSTCMDAVAIL = 12;
		static const Sbecore::uint BUTCMDVIEWACTIVE = 13;
		static const Sbecore::uint BUTCMDNEWCRDACTIVE = 14;
		static const Sbecore::uint LSTERRAVAIL = 15;
		static const Sbecore::uint BUTERRVIEWACTIVE = 16;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 17;
		static const Sbecore::uint LSTPPLAVAIL = 18;
		static const Sbecore::uint BUTPPLVIEWACTIVE = 19;
		static const Sbecore::uint BUTPPLNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTSEGAVAIL = 21;
		static const Sbecore::uint BUTSEGVIEWACTIVE = 22;
		static const Sbecore::uint BUTSEGNEWCRDACTIVE = 23;

	public:
		StatShr(const bool LstPphAvail = true, const bool ButPphViewActive = true, const bool ButPphNewcrdActive = true, const bool LstModAvail = true, const bool ButModViewActive = true, const bool ButModNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool LstCmdAvail = true, const bool ButCmdViewActive = true, const bool ButCmdNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true, const bool LstPplAvail = true, const bool ButPplViewActive = true, const bool ButPplNewcrdActive = true, const bool LstSegAvail = true, const bool ButSegViewActive = true, const bool ButSegNewcrdActive = true);

	public:
		bool LstPphAvail;
		bool ButPphViewActive;
		bool ButPphNewcrdActive;
		bool LstModAvail;
		bool ButModViewActive;
		bool ButModNewcrdActive;
		bool LstVecAvail;
		bool ButVecViewActive;
		bool ButVecNewcrdActive;
		bool LstVitAvail;
		bool ButVitViewActive;
		bool LstCmdAvail;
		bool ButCmdViewActive;
		bool ButCmdNewcrdActive;
		bool LstErrAvail;
		bool ButErrViewActive;
		bool ButErrNewcrdActive;
		bool LstPplAvail;
		bool ButPplViewActive;
		bool ButPplNewcrdActive;
		bool LstSegAvail;
		bool ButSegViewActive;
		bool ButSegNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavHigh)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPPH = 2;
		static const Sbecore::uint CPTMOD = 3;
		static const Sbecore::uint CPTVEC = 4;
		static const Sbecore::uint CPTVIT = 5;
		static const Sbecore::uint CPTCMD = 6;
		static const Sbecore::uint CPTERR = 7;
		static const Sbecore::uint CPTPPL = 8;
		static const Sbecore::uint CPTSEG = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPph = "", const std::string& CptMod = "", const std::string& CptVec = "", const std::string& CptVit = "", const std::string& CptCmd = "", const std::string& CptErr = "", const std::string& CptPpl = "", const std::string& CptSeg = "");

	public:
		std::string Cpt;
		std::string CptPph;
		std::string CptMod;
		std::string CptVec;
		std::string CptVit;
		std::string CptCmd;
		std::string CptErr;
		std::string CptPpl;
		std::string CptSeg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavHighData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavHighDo)
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
		* DpchEngData (full: DpchEngWdbeNavHighData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMD = 3;
		static const Sbecore::uint FEEDFLSTERR = 4;
		static const Sbecore::uint FEEDFLSTMOD = 5;
		static const Sbecore::uint FEEDFLSTPPH = 6;
		static const Sbecore::uint FEEDFLSTPPL = 7;
		static const Sbecore::uint FEEDFLSTSEG = 8;
		static const Sbecore::uint FEEDFLSTVEC = 9;
		static const Sbecore::uint FEEDFLSTVIT = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCmd;
		Sbecore::Feed feedFLstErr;
		Sbecore::Feed feedFLstMod;
		Sbecore::Feed feedFLstPph;
		Sbecore::Feed feedFLstPpl;
		Sbecore::Feed feedFLstSeg;
		Sbecore::Feed feedFLstVec;
		Sbecore::Feed feedFLstVit;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
