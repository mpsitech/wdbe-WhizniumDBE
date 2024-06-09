/**
	* \file PnlWdbeNavLow.h
	* API code for job PnlWdbeNavLow (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVLOW_H
#define PNLWDBENAVLOW_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavLowDo PnlWdbeNavLow::VecVDo

#define ContIacWdbeNavLow PnlWdbeNavLow::ContIac
#define StatAppWdbeNavLow PnlWdbeNavLow::StatApp
#define StatShrWdbeNavLow PnlWdbeNavLow::StatShr
#define TagWdbeNavLow PnlWdbeNavLow::Tag

#define DpchAppWdbeNavLowData PnlWdbeNavLow::DpchAppData
#define DpchAppWdbeNavLowDo PnlWdbeNavLow::DpchAppDo
#define DpchEngWdbeNavLowData PnlWdbeNavLow::DpchEngData

/**
	* PnlWdbeNavLow
	*/
namespace PnlWdbeNavLow {
	/**
		* VecVDo (full: VecVWdbeNavLowDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTBNKVIEWCLICK = 1;
		static const Sbecore::uint BUTBNKNEWCRDCLICK = 2;
		static const Sbecore::uint BUTPINVIEWCLICK = 3;
		static const Sbecore::uint BUTPINNEWCRDCLICK = 4;
		static const Sbecore::uint BUTINTVIEWCLICK = 5;
		static const Sbecore::uint BUTINTNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSNSVIEWCLICK = 7;
		static const Sbecore::uint BUTVARVIEWCLICK = 8;
		static const Sbecore::uint BUTGENVIEWCLICK = 9;
		static const Sbecore::uint BUTPRTVIEWCLICK = 10;
		static const Sbecore::uint BUTSIGVIEWCLICK = 11;
		static const Sbecore::uint BUTSIGNEWCRDCLICK = 12;
		static const Sbecore::uint BUTCDCVIEWCLICK = 13;
		static const Sbecore::uint BUTPRCVIEWCLICK = 14;
		static const Sbecore::uint BUTFSTVIEWCLICK = 15;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavLow)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTBNK = 1;
		static const Sbecore::uint NUMFLSTPIN = 2;
		static const Sbecore::uint NUMFLSTINT = 3;
		static const Sbecore::uint NUMFLSTSNS = 4;
		static const Sbecore::uint NUMFLSTVAR = 5;
		static const Sbecore::uint NUMFLSTGEN = 6;
		static const Sbecore::uint NUMFLSTPRT = 7;
		static const Sbecore::uint NUMFLSTSIG = 8;
		static const Sbecore::uint NUMFLSTCDC = 9;
		static const Sbecore::uint NUMFLSTPRC = 10;
		static const Sbecore::uint NUMFLSTFST = 11;

	public:
		ContIac(const Sbecore::uint numFLstBnk = 1, const Sbecore::uint numFLstPin = 1, const Sbecore::uint numFLstInt = 1, const Sbecore::uint numFLstSns = 1, const Sbecore::uint numFLstVar = 1, const Sbecore::uint numFLstGen = 1, const Sbecore::uint numFLstPrt = 1, const Sbecore::uint numFLstSig = 1, const Sbecore::uint numFLstCdc = 1, const Sbecore::uint numFLstPrc = 1, const Sbecore::uint numFLstFst = 1);

	public:
		Sbecore::uint numFLstBnk;
		Sbecore::uint numFLstPin;
		Sbecore::uint numFLstInt;
		Sbecore::uint numFLstSns;
		Sbecore::uint numFLstVar;
		Sbecore::uint numFLstGen;
		Sbecore::uint numFLstPrt;
		Sbecore::uint numFLstSig;
		Sbecore::uint numFLstCdc;
		Sbecore::uint numFLstPrc;
		Sbecore::uint numFLstFst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavLow)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTBNKALT = 2;
		static const Sbecore::uint LSTPINALT = 3;
		static const Sbecore::uint LSTINTALT = 4;
		static const Sbecore::uint LSTSNSALT = 5;
		static const Sbecore::uint LSTVARALT = 6;
		static const Sbecore::uint LSTGENALT = 7;
		static const Sbecore::uint LSTPRTALT = 8;
		static const Sbecore::uint LSTSIGALT = 9;
		static const Sbecore::uint LSTCDCALT = 10;
		static const Sbecore::uint LSTPRCALT = 11;
		static const Sbecore::uint LSTFSTALT = 12;
		static const Sbecore::uint LSTBNKNUMFIRSTDISP = 13;
		static const Sbecore::uint LSTPINNUMFIRSTDISP = 14;
		static const Sbecore::uint LSTINTNUMFIRSTDISP = 15;
		static const Sbecore::uint LSTSNSNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTVARNUMFIRSTDISP = 17;
		static const Sbecore::uint LSTGENNUMFIRSTDISP = 18;
		static const Sbecore::uint LSTPRTNUMFIRSTDISP = 19;
		static const Sbecore::uint LSTSIGNUMFIRSTDISP = 20;
		static const Sbecore::uint LSTCDCNUMFIRSTDISP = 21;
		static const Sbecore::uint LSTPRCNUMFIRSTDISP = 22;
		static const Sbecore::uint LSTFSTNUMFIRSTDISP = 23;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstBnkAlt = true, const bool LstPinAlt = true, const bool LstIntAlt = true, const bool LstSnsAlt = true, const bool LstVarAlt = true, const bool LstGenAlt = true, const bool LstPrtAlt = true, const bool LstSigAlt = true, const bool LstCdcAlt = true, const bool LstPrcAlt = true, const bool LstFstAlt = true, const Sbecore::uint LstBnkNumFirstdisp = 1, const Sbecore::uint LstPinNumFirstdisp = 1, const Sbecore::uint LstIntNumFirstdisp = 1, const Sbecore::uint LstSnsNumFirstdisp = 1, const Sbecore::uint LstVarNumFirstdisp = 1, const Sbecore::uint LstGenNumFirstdisp = 1, const Sbecore::uint LstPrtNumFirstdisp = 1, const Sbecore::uint LstSigNumFirstdisp = 1, const Sbecore::uint LstCdcNumFirstdisp = 1, const Sbecore::uint LstPrcNumFirstdisp = 1, const Sbecore::uint LstFstNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstBnkAlt;
		bool LstPinAlt;
		bool LstIntAlt;
		bool LstSnsAlt;
		bool LstVarAlt;
		bool LstGenAlt;
		bool LstPrtAlt;
		bool LstSigAlt;
		bool LstCdcAlt;
		bool LstPrcAlt;
		bool LstFstAlt;
		Sbecore::uint LstBnkNumFirstdisp;
		Sbecore::uint LstPinNumFirstdisp;
		Sbecore::uint LstIntNumFirstdisp;
		Sbecore::uint LstSnsNumFirstdisp;
		Sbecore::uint LstVarNumFirstdisp;
		Sbecore::uint LstGenNumFirstdisp;
		Sbecore::uint LstPrtNumFirstdisp;
		Sbecore::uint LstSigNumFirstdisp;
		Sbecore::uint LstCdcNumFirstdisp;
		Sbecore::uint LstPrcNumFirstdisp;
		Sbecore::uint LstFstNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavLow)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTBNKAVAIL = 1;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 2;
		static const Sbecore::uint BUTBNKNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTPINAVAIL = 4;
		static const Sbecore::uint BUTPINVIEWACTIVE = 5;
		static const Sbecore::uint BUTPINNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTINTAVAIL = 7;
		static const Sbecore::uint BUTINTVIEWACTIVE = 8;
		static const Sbecore::uint BUTINTNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTSNSAVAIL = 10;
		static const Sbecore::uint BUTSNSVIEWACTIVE = 11;
		static const Sbecore::uint LSTVARAVAIL = 12;
		static const Sbecore::uint BUTVARVIEWACTIVE = 13;
		static const Sbecore::uint LSTGENAVAIL = 14;
		static const Sbecore::uint BUTGENVIEWACTIVE = 15;
		static const Sbecore::uint LSTPRTAVAIL = 16;
		static const Sbecore::uint BUTPRTVIEWACTIVE = 17;
		static const Sbecore::uint LSTSIGAVAIL = 18;
		static const Sbecore::uint BUTSIGVIEWACTIVE = 19;
		static const Sbecore::uint BUTSIGNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTCDCAVAIL = 21;
		static const Sbecore::uint BUTCDCVIEWACTIVE = 22;
		static const Sbecore::uint LSTPRCAVAIL = 23;
		static const Sbecore::uint BUTPRCVIEWACTIVE = 24;
		static const Sbecore::uint LSTFSTAVAIL = 25;
		static const Sbecore::uint BUTFSTVIEWACTIVE = 26;

	public:
		StatShr(const bool LstBnkAvail = true, const bool ButBnkViewActive = true, const bool ButBnkNewcrdActive = true, const bool LstPinAvail = true, const bool ButPinViewActive = true, const bool ButPinNewcrdActive = true, const bool LstIntAvail = true, const bool ButIntViewActive = true, const bool ButIntNewcrdActive = true, const bool LstSnsAvail = true, const bool ButSnsViewActive = true, const bool LstVarAvail = true, const bool ButVarViewActive = true, const bool LstGenAvail = true, const bool ButGenViewActive = true, const bool LstPrtAvail = true, const bool ButPrtViewActive = true, const bool LstSigAvail = true, const bool ButSigViewActive = true, const bool ButSigNewcrdActive = true, const bool LstCdcAvail = true, const bool ButCdcViewActive = true, const bool LstPrcAvail = true, const bool ButPrcViewActive = true, const bool LstFstAvail = true, const bool ButFstViewActive = true);

	public:
		bool LstBnkAvail;
		bool ButBnkViewActive;
		bool ButBnkNewcrdActive;
		bool LstPinAvail;
		bool ButPinViewActive;
		bool ButPinNewcrdActive;
		bool LstIntAvail;
		bool ButIntViewActive;
		bool ButIntNewcrdActive;
		bool LstSnsAvail;
		bool ButSnsViewActive;
		bool LstVarAvail;
		bool ButVarViewActive;
		bool LstGenAvail;
		bool ButGenViewActive;
		bool LstPrtAvail;
		bool ButPrtViewActive;
		bool LstSigAvail;
		bool ButSigViewActive;
		bool ButSigNewcrdActive;
		bool LstCdcAvail;
		bool ButCdcViewActive;
		bool LstPrcAvail;
		bool ButPrcViewActive;
		bool LstFstAvail;
		bool ButFstViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavLow)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTBNK = 2;
		static const Sbecore::uint CPTPIN = 3;
		static const Sbecore::uint CPTINT = 4;
		static const Sbecore::uint CPTSNS = 5;
		static const Sbecore::uint CPTVAR = 6;
		static const Sbecore::uint CPTGEN = 7;
		static const Sbecore::uint CPTPRT = 8;
		static const Sbecore::uint CPTSIG = 9;
		static const Sbecore::uint CPTCDC = 10;
		static const Sbecore::uint CPTPRC = 11;
		static const Sbecore::uint CPTFST = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptBnk = "", const std::string& CptPin = "", const std::string& CptInt = "", const std::string& CptSns = "", const std::string& CptVar = "", const std::string& CptGen = "", const std::string& CptPrt = "", const std::string& CptSig = "", const std::string& CptCdc = "", const std::string& CptPrc = "", const std::string& CptFst = "");

	public:
		std::string Cpt;
		std::string CptBnk;
		std::string CptPin;
		std::string CptInt;
		std::string CptSns;
		std::string CptVar;
		std::string CptGen;
		std::string CptPrt;
		std::string CptSig;
		std::string CptCdc;
		std::string CptPrc;
		std::string CptFst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavLowData)
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
		* DpchAppDo (full: DpchAppWdbeNavLowDo)
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
		* DpchEngData (full: DpchEngWdbeNavLowData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBNK = 3;
		static const Sbecore::uint FEEDFLSTCDC = 4;
		static const Sbecore::uint FEEDFLSTFST = 5;
		static const Sbecore::uint FEEDFLSTGEN = 6;
		static const Sbecore::uint FEEDFLSTINT = 7;
		static const Sbecore::uint FEEDFLSTPIN = 8;
		static const Sbecore::uint FEEDFLSTPRC = 9;
		static const Sbecore::uint FEEDFLSTPRT = 10;
		static const Sbecore::uint FEEDFLSTSIG = 11;
		static const Sbecore::uint FEEDFLSTSNS = 12;
		static const Sbecore::uint FEEDFLSTVAR = 13;
		static const Sbecore::uint STATAPP = 14;
		static const Sbecore::uint STATSHR = 15;
		static const Sbecore::uint TAG = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstBnk;
		Sbecore::Feed feedFLstCdc;
		Sbecore::Feed feedFLstFst;
		Sbecore::Feed feedFLstGen;
		Sbecore::Feed feedFLstInt;
		Sbecore::Feed feedFLstPin;
		Sbecore::Feed feedFLstPrc;
		Sbecore::Feed feedFLstPrt;
		Sbecore::Feed feedFLstSig;
		Sbecore::Feed feedFLstSns;
		Sbecore::Feed feedFLstVar;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
