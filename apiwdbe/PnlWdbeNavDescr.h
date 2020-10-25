/**
	* \file PnlWdbeNavDescr.h
	* API code for job PnlWdbeNavDescr (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBENAVDESCR_H
#define PNLWDBENAVDESCR_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavDescrDo PnlWdbeNavDescr::VecVDo

#define ContIacWdbeNavDescr PnlWdbeNavDescr::ContIac
#define StatAppWdbeNavDescr PnlWdbeNavDescr::StatApp
#define StatShrWdbeNavDescr PnlWdbeNavDescr::StatShr
#define TagWdbeNavDescr PnlWdbeNavDescr::Tag

#define DpchAppWdbeNavDescrData PnlWdbeNavDescr::DpchAppData
#define DpchAppWdbeNavDescrDo PnlWdbeNavDescr::DpchAppDo
#define DpchEngWdbeNavDescrData PnlWdbeNavDescr::DpchEngData

/**
	* PnlWdbeNavDescr
	*/
namespace PnlWdbeNavDescr {
	/**
		* VecVDo (full: VecVWdbeNavDescrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMODVIEWCLICK = 1;
		static const Sbecore::uint BUTMODNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVECVIEWCLICK = 3;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 4;
		static const Sbecore::uint BUTVITVIEWCLICK = 5;
		static const Sbecore::uint BUTCMDVIEWCLICK = 6;
		static const Sbecore::uint BUTCMDNEWCRDCLICK = 7;
		static const Sbecore::uint BUTERRVIEWCLICK = 8;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 9;
		static const Sbecore::uint BUTPPHVIEWCLICK = 10;
		static const Sbecore::uint BUTPPHNEWCRDCLICK = 11;
		static const Sbecore::uint BUTBNKVIEWCLICK = 12;
		static const Sbecore::uint BUTBNKNEWCRDCLICK = 13;
		static const Sbecore::uint BUTPINVIEWCLICK = 14;
		static const Sbecore::uint BUTPINNEWCRDCLICK = 15;
		static const Sbecore::uint BUTGENVIEWCLICK = 16;
		static const Sbecore::uint BUTPRTVIEWCLICK = 17;
		static const Sbecore::uint BUTSIGVIEWCLICK = 18;
		static const Sbecore::uint BUTPRCVIEWCLICK = 19;
		static const Sbecore::uint BUTFSTVIEWCLICK = 20;
		static const Sbecore::uint BUTVARVIEWCLICK = 21;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDescr)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTMOD = 1;
		static const Sbecore::uint NUMFLSTVEC = 2;
		static const Sbecore::uint NUMFLSTVIT = 3;
		static const Sbecore::uint NUMFLSTCMD = 4;
		static const Sbecore::uint NUMFLSTERR = 5;
		static const Sbecore::uint NUMFLSTPPH = 6;
		static const Sbecore::uint NUMFLSTBNK = 7;
		static const Sbecore::uint NUMFLSTPIN = 8;
		static const Sbecore::uint NUMFLSTGEN = 9;
		static const Sbecore::uint NUMFLSTPRT = 10;
		static const Sbecore::uint NUMFLSTSIG = 11;
		static const Sbecore::uint NUMFLSTPRC = 12;
		static const Sbecore::uint NUMFLSTFST = 13;
		static const Sbecore::uint NUMFLSTVAR = 14;

	public:
		ContIac(const Sbecore::uint numFLstMod = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstCmd = 1, const Sbecore::uint numFLstErr = 1, const Sbecore::uint numFLstPph = 1, const Sbecore::uint numFLstBnk = 1, const Sbecore::uint numFLstPin = 1, const Sbecore::uint numFLstGen = 1, const Sbecore::uint numFLstPrt = 1, const Sbecore::uint numFLstSig = 1, const Sbecore::uint numFLstPrc = 1, const Sbecore::uint numFLstFst = 1, const Sbecore::uint numFLstVar = 1);

	public:
		Sbecore::uint numFLstMod;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstCmd;
		Sbecore::uint numFLstErr;
		Sbecore::uint numFLstPph;
		Sbecore::uint numFLstBnk;
		Sbecore::uint numFLstPin;
		Sbecore::uint numFLstGen;
		Sbecore::uint numFLstPrt;
		Sbecore::uint numFLstSig;
		Sbecore::uint numFLstPrc;
		Sbecore::uint numFLstFst;
		Sbecore::uint numFLstVar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavDescr)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTMODALT = 2;
		static const Sbecore::uint LSTVECALT = 3;
		static const Sbecore::uint LSTVITALT = 4;
		static const Sbecore::uint LSTCMDALT = 5;
		static const Sbecore::uint LSTERRALT = 6;
		static const Sbecore::uint LSTPPHALT = 7;
		static const Sbecore::uint LSTBNKALT = 8;
		static const Sbecore::uint LSTPINALT = 9;
		static const Sbecore::uint LSTGENALT = 10;
		static const Sbecore::uint LSTPRTALT = 11;
		static const Sbecore::uint LSTSIGALT = 12;
		static const Sbecore::uint LSTPRCALT = 13;
		static const Sbecore::uint LSTFSTALT = 14;
		static const Sbecore::uint LSTVARALT = 15;
		static const Sbecore::uint LSTMODNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTVECNUMFIRSTDISP = 17;
		static const Sbecore::uint LSTVITNUMFIRSTDISP = 18;
		static const Sbecore::uint LSTCMDNUMFIRSTDISP = 19;
		static const Sbecore::uint LSTERRNUMFIRSTDISP = 20;
		static const Sbecore::uint LSTPPHNUMFIRSTDISP = 21;
		static const Sbecore::uint LSTBNKNUMFIRSTDISP = 22;
		static const Sbecore::uint LSTPINNUMFIRSTDISP = 23;
		static const Sbecore::uint LSTGENNUMFIRSTDISP = 24;
		static const Sbecore::uint LSTPRTNUMFIRSTDISP = 25;
		static const Sbecore::uint LSTSIGNUMFIRSTDISP = 26;
		static const Sbecore::uint LSTPRCNUMFIRSTDISP = 27;
		static const Sbecore::uint LSTFSTNUMFIRSTDISP = 28;
		static const Sbecore::uint LSTVARNUMFIRSTDISP = 29;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstModAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstCmdAlt = true, const bool LstErrAlt = true, const bool LstPphAlt = true, const bool LstBnkAlt = true, const bool LstPinAlt = true, const bool LstGenAlt = true, const bool LstPrtAlt = true, const bool LstSigAlt = true, const bool LstPrcAlt = true, const bool LstFstAlt = true, const bool LstVarAlt = true, const Sbecore::uint LstModNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstCmdNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1, const Sbecore::uint LstPphNumFirstdisp = 1, const Sbecore::uint LstBnkNumFirstdisp = 1, const Sbecore::uint LstPinNumFirstdisp = 1, const Sbecore::uint LstGenNumFirstdisp = 1, const Sbecore::uint LstPrtNumFirstdisp = 1, const Sbecore::uint LstSigNumFirstdisp = 1, const Sbecore::uint LstPrcNumFirstdisp = 1, const Sbecore::uint LstFstNumFirstdisp = 1, const Sbecore::uint LstVarNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstModAlt;
		bool LstVecAlt;
		bool LstVitAlt;
		bool LstCmdAlt;
		bool LstErrAlt;
		bool LstPphAlt;
		bool LstBnkAlt;
		bool LstPinAlt;
		bool LstGenAlt;
		bool LstPrtAlt;
		bool LstSigAlt;
		bool LstPrcAlt;
		bool LstFstAlt;
		bool LstVarAlt;
		Sbecore::uint LstModNumFirstdisp;
		Sbecore::uint LstVecNumFirstdisp;
		Sbecore::uint LstVitNumFirstdisp;
		Sbecore::uint LstCmdNumFirstdisp;
		Sbecore::uint LstErrNumFirstdisp;
		Sbecore::uint LstPphNumFirstdisp;
		Sbecore::uint LstBnkNumFirstdisp;
		Sbecore::uint LstPinNumFirstdisp;
		Sbecore::uint LstGenNumFirstdisp;
		Sbecore::uint LstPrtNumFirstdisp;
		Sbecore::uint LstSigNumFirstdisp;
		Sbecore::uint LstPrcNumFirstdisp;
		Sbecore::uint LstFstNumFirstdisp;
		Sbecore::uint LstVarNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavDescr)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTMODAVAIL = 1;
		static const Sbecore::uint BUTMODVIEWACTIVE = 2;
		static const Sbecore::uint BUTMODNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTVECAVAIL = 4;
		static const Sbecore::uint BUTVECVIEWACTIVE = 5;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTVITAVAIL = 7;
		static const Sbecore::uint BUTVITVIEWACTIVE = 8;
		static const Sbecore::uint LSTCMDAVAIL = 9;
		static const Sbecore::uint BUTCMDVIEWACTIVE = 10;
		static const Sbecore::uint BUTCMDNEWCRDACTIVE = 11;
		static const Sbecore::uint LSTERRAVAIL = 12;
		static const Sbecore::uint BUTERRVIEWACTIVE = 13;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 14;
		static const Sbecore::uint LSTPPHAVAIL = 15;
		static const Sbecore::uint BUTPPHVIEWACTIVE = 16;
		static const Sbecore::uint BUTPPHNEWCRDACTIVE = 17;
		static const Sbecore::uint LSTBNKAVAIL = 18;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 19;
		static const Sbecore::uint BUTBNKNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTPINAVAIL = 21;
		static const Sbecore::uint BUTPINVIEWACTIVE = 22;
		static const Sbecore::uint BUTPINNEWCRDACTIVE = 23;
		static const Sbecore::uint LSTGENAVAIL = 24;
		static const Sbecore::uint BUTGENVIEWACTIVE = 25;
		static const Sbecore::uint LSTPRTAVAIL = 26;
		static const Sbecore::uint BUTPRTVIEWACTIVE = 27;
		static const Sbecore::uint LSTSIGAVAIL = 28;
		static const Sbecore::uint BUTSIGVIEWACTIVE = 29;
		static const Sbecore::uint LSTPRCAVAIL = 30;
		static const Sbecore::uint BUTPRCVIEWACTIVE = 31;
		static const Sbecore::uint LSTFSTAVAIL = 32;
		static const Sbecore::uint BUTFSTVIEWACTIVE = 33;
		static const Sbecore::uint LSTVARAVAIL = 34;
		static const Sbecore::uint BUTVARVIEWACTIVE = 35;

	public:
		StatShr(const bool LstModAvail = true, const bool ButModViewActive = true, const bool ButModNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool LstCmdAvail = true, const bool ButCmdViewActive = true, const bool ButCmdNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true, const bool LstPphAvail = true, const bool ButPphViewActive = true, const bool ButPphNewcrdActive = true, const bool LstBnkAvail = true, const bool ButBnkViewActive = true, const bool ButBnkNewcrdActive = true, const bool LstPinAvail = true, const bool ButPinViewActive = true, const bool ButPinNewcrdActive = true, const bool LstGenAvail = true, const bool ButGenViewActive = true, const bool LstPrtAvail = true, const bool ButPrtViewActive = true, const bool LstSigAvail = true, const bool ButSigViewActive = true, const bool LstPrcAvail = true, const bool ButPrcViewActive = true, const bool LstFstAvail = true, const bool ButFstViewActive = true, const bool LstVarAvail = true, const bool ButVarViewActive = true);

	public:
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
		bool LstPphAvail;
		bool ButPphViewActive;
		bool ButPphNewcrdActive;
		bool LstBnkAvail;
		bool ButBnkViewActive;
		bool ButBnkNewcrdActive;
		bool LstPinAvail;
		bool ButPinViewActive;
		bool ButPinNewcrdActive;
		bool LstGenAvail;
		bool ButGenViewActive;
		bool LstPrtAvail;
		bool ButPrtViewActive;
		bool LstSigAvail;
		bool ButSigViewActive;
		bool LstPrcAvail;
		bool ButPrcViewActive;
		bool LstFstAvail;
		bool ButFstViewActive;
		bool LstVarAvail;
		bool ButVarViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavDescr)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTMOD = 2;
		static const Sbecore::uint CPTVEC = 3;
		static const Sbecore::uint CPTVIT = 4;
		static const Sbecore::uint CPTCMD = 5;
		static const Sbecore::uint CPTERR = 6;
		static const Sbecore::uint CPTPPH = 7;
		static const Sbecore::uint CPTBNK = 8;
		static const Sbecore::uint CPTPIN = 9;
		static const Sbecore::uint CPTGEN = 10;
		static const Sbecore::uint CPTPRT = 11;
		static const Sbecore::uint CPTSIG = 12;
		static const Sbecore::uint CPTPRC = 13;
		static const Sbecore::uint CPTFST = 14;
		static const Sbecore::uint CPTVAR = 15;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptMod = "", const std::string& CptVec = "", const std::string& CptVit = "", const std::string& CptCmd = "", const std::string& CptErr = "", const std::string& CptPph = "", const std::string& CptBnk = "", const std::string& CptPin = "", const std::string& CptGen = "", const std::string& CptPrt = "", const std::string& CptSig = "", const std::string& CptPrc = "", const std::string& CptFst = "", const std::string& CptVar = "");

	public:
		std::string Cpt;
		std::string CptMod;
		std::string CptVec;
		std::string CptVit;
		std::string CptCmd;
		std::string CptErr;
		std::string CptPph;
		std::string CptBnk;
		std::string CptPin;
		std::string CptGen;
		std::string CptPrt;
		std::string CptSig;
		std::string CptPrc;
		std::string CptFst;
		std::string CptVar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDescrData)
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
		* DpchAppDo (full: DpchAppWdbeNavDescrDo)
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
		* DpchEngData (full: DpchEngWdbeNavDescrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBNK = 3;
		static const Sbecore::uint FEEDFLSTCMD = 4;
		static const Sbecore::uint FEEDFLSTERR = 5;
		static const Sbecore::uint FEEDFLSTFST = 6;
		static const Sbecore::uint FEEDFLSTGEN = 7;
		static const Sbecore::uint FEEDFLSTMOD = 8;
		static const Sbecore::uint FEEDFLSTPIN = 9;
		static const Sbecore::uint FEEDFLSTPPH = 10;
		static const Sbecore::uint FEEDFLSTPRC = 11;
		static const Sbecore::uint FEEDFLSTPRT = 12;
		static const Sbecore::uint FEEDFLSTSIG = 13;
		static const Sbecore::uint FEEDFLSTVAR = 14;
		static const Sbecore::uint FEEDFLSTVEC = 15;
		static const Sbecore::uint FEEDFLSTVIT = 16;
		static const Sbecore::uint STATAPP = 17;
		static const Sbecore::uint STATSHR = 18;
		static const Sbecore::uint TAG = 19;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstBnk;
		Sbecore::Xmlio::Feed feedFLstCmd;
		Sbecore::Xmlio::Feed feedFLstErr;
		Sbecore::Xmlio::Feed feedFLstFst;
		Sbecore::Xmlio::Feed feedFLstGen;
		Sbecore::Xmlio::Feed feedFLstMod;
		Sbecore::Xmlio::Feed feedFLstPin;
		Sbecore::Xmlio::Feed feedFLstPph;
		Sbecore::Xmlio::Feed feedFLstPrc;
		Sbecore::Xmlio::Feed feedFLstPrt;
		Sbecore::Xmlio::Feed feedFLstSig;
		Sbecore::Xmlio::Feed feedFLstVar;
		Sbecore::Xmlio::Feed feedFLstVec;
		Sbecore::Xmlio::Feed feedFLstVit;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

