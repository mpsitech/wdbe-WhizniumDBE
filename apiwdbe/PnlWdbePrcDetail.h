/**
	* \file PnlWdbePrcDetail.h
	* API code for job PnlWdbePrcDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRCDETAIL_H
#define PNLWDBEPRCDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbePrcDetailDo PnlWdbePrcDetail::VecVDo

#define ContIacWdbePrcDetail PnlWdbePrcDetail::ContIac
#define ContInfWdbePrcDetail PnlWdbePrcDetail::ContInf
#define StatAppWdbePrcDetail PnlWdbePrcDetail::StatApp
#define StatShrWdbePrcDetail PnlWdbePrcDetail::StatShr
#define TagWdbePrcDetail PnlWdbePrcDetail::Tag

#define DpchAppWdbePrcDetailData PnlWdbePrcDetail::DpchAppData
#define DpchAppWdbePrcDetailDo PnlWdbePrcDetail::DpchAppDo
#define DpchEngWdbePrcDetailData PnlWdbePrcDetail::DpchEngData

/**
	* PnlWdbePrcDetail
	*/
namespace PnlWdbePrcDetail {
	/**
		* VecVDo (full: VecVWdbePrcDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTMDLVIEWCLICK = 2;
		static const Sbecore::uint BUTCLKVIEWCLICK = 3;
		static const Sbecore::uint BUTASRVIEWCLICK = 4;
		static const Sbecore::uint BUTFSMNEWCLICK = 5;
		static const Sbecore::uint BUTFSMDELETECLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrcDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLK = 1;
		static const Sbecore::uint TXFASR = 2;
		static const Sbecore::uint CHKFAL = 3;
		static const Sbecore::uint TXFSNR = 4;
		static const Sbecore::uint CHKEIP = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint NUMFPUPFSMDTT = 7;

	public:
		ContIac(const std::string& TxfClk = "", const std::string& TxfAsr = "", const bool ChkFal = false, const std::string& TxfSnr = "", const bool ChkEip = false, const std::string& TxfCmt = "", const Sbecore::uint numFPupFsmDtt = 1);

	public:
		std::string TxfClk;
		std::string TxfAsr;
		bool ChkFal;
		std::string TxfSnr;
		bool ChkEip;
		std::string TxfCmt;
		Sbecore::uint numFPupFsmDtt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePrcDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTMDL = 2;
		static const Sbecore::uint TXTCLK = 3;
		static const Sbecore::uint TXTASR = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtMdl = "", const std::string& TxtClk = "", const std::string& TxtAsr = "");

	public:
		std::string TxtSrf;
		std::string TxtMdl;
		std::string TxtClk;
		std::string TxtAsr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbePrcDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint TXTCLKALT = 2;
		static const Sbecore::uint TXTASRALT = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtAsrAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool TxtClkAlt;
		bool TxtAsrAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePrcDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLKVALID = 1;
		static const Sbecore::uint TXFASRVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint TXTMDLACTIVE = 6;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 7;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 8;
		static const Sbecore::uint TXTCLKACTIVE = 9;
		static const Sbecore::uint BUTCLKVIEWAVAIL = 10;
		static const Sbecore::uint TXTASRACTIVE = 11;
		static const Sbecore::uint BUTASRVIEWAVAIL = 12;
		static const Sbecore::uint CHKFALACTIVE = 13;
		static const Sbecore::uint TXFSNRACTIVE = 14;
		static const Sbecore::uint CHKEIPACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;
		static const Sbecore::uint BUTFSMNEWAVAIL = 17;
		static const Sbecore::uint BUTFSMDELETEAVAIL = 18;
		static const Sbecore::uint PUPFSMDTTAVAIL = 19;
		static const Sbecore::uint PUPFSMDTTACTIVE = 20;

	public:
		StatShr(const bool TxfClkValid = false, const bool TxfAsrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtClkActive = true, const bool ButClkViewAvail = true, const bool TxtAsrActive = true, const bool ButAsrViewAvail = true, const bool ChkFalActive = true, const bool TxfSnrActive = true, const bool ChkEipActive = true, const bool TxfCmtActive = true, const bool ButFsmNewAvail = true, const bool ButFsmDeleteAvail = true, const bool PupFsmDttAvail = true, const bool PupFsmDttActive = true);

	public:
		bool TxfClkValid;
		bool TxfAsrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtClkActive;
		bool ButClkViewAvail;
		bool TxtAsrActive;
		bool ButAsrViewAvail;
		bool ChkFalActive;
		bool TxfSnrActive;
		bool ChkEipActive;
		bool TxfCmtActive;
		bool ButFsmNewAvail;
		bool ButFsmDeleteAvail;
		bool PupFsmDttAvail;
		bool PupFsmDttActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePrcDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTMDL = 3;
		static const Sbecore::uint CPTCLK = 4;
		static const Sbecore::uint CPTASR = 5;
		static const Sbecore::uint CPTFAL = 6;
		static const Sbecore::uint CPTSNR = 7;
		static const Sbecore::uint CPTEIP = 8;
		static const Sbecore::uint CPTCMT = 9;
		static const Sbecore::uint HDGFSM = 10;
		static const Sbecore::uint CPTFSMDTT = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptMdl = "", const std::string& CptClk = "", const std::string& CptAsr = "", const std::string& CptFal = "", const std::string& CptSnr = "", const std::string& CptEip = "", const std::string& CptCmt = "", const std::string& HdgFsm = "", const std::string& CptFsmDtt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptMdl;
		std::string CptClk;
		std::string CptAsr;
		std::string CptFal;
		std::string CptSnr;
		std::string CptEip;
		std::string CptCmt;
		std::string HdgFsm;
		std::string CptFsmDtt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrcDetailData)
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
		* DpchAppDo (full: DpchAppWdbePrcDetailDo)
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
		* DpchEngData (full: DpchEngWdbePrcDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPFSMDTT = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupFsmDtt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
