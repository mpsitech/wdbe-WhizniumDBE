/**
	* \file PnlWdbeVarDetail.h
	* API code for job PnlWdbeVarDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEVARDETAIL_H
#define PNLWDBEVARDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeVarDetailDo PnlWdbeVarDetail::VecVDo

#define ContIacWdbeVarDetail PnlWdbeVarDetail::ContIac
#define ContInfWdbeVarDetail PnlWdbeVarDetail::ContInf
#define StatAppWdbeVarDetail PnlWdbeVarDetail::StatApp
#define StatShrWdbeVarDetail PnlWdbeVarDetail::StatShr
#define TagWdbeVarDetail PnlWdbeVarDetail::Tag

#define DpchAppWdbeVarDetailData PnlWdbeVarDetail::DpchAppData
#define DpchAppWdbeVarDetailDo PnlWdbeVarDetail::DpchAppDo
#define DpchEngWdbeVarDetailData PnlWdbeVarDetail::DpchEngData

/**
	* PnlWdbeVarDetail
	*/
namespace PnlWdbeVarDetail {
	/**
		* VecVDo (full: VecVWdbeVarDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTREUVIEWCLICK = 5;
		static const Sbecore::uint BUTHTYEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeVarDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint CHKCON = 3;
		static const Sbecore::uint CHKFAL = 4;
		static const Sbecore::uint NUMFPUPHTY = 5;
		static const Sbecore::uint TXFHTY = 6;
		static const Sbecore::uint TXFWID = 7;
		static const Sbecore::uint TXFMMX = 8;
		static const Sbecore::uint TXFONV = 9;
		static const Sbecore::uint TXFOFV = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupRet = 1, const bool ChkCon = false, const bool ChkFal = false, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfOnv = "", const std::string& TxfOfv = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupRet;
		bool ChkCon;
		bool ChkFal;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfOnv;
		std::string TxfOfv;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeVarDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTREU = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtReu = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeVarDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint PUPHTYALT = 3;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 4;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCluAlt;
		bool PupHtyAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeVarDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint LSTCLUACTIVE = 4;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 5;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 6;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 7;
		static const Sbecore::uint TXTREUACTIVE = 8;
		static const Sbecore::uint BUTREUVIEWAVAIL = 9;
		static const Sbecore::uint BUTREUVIEWACTIVE = 10;
		static const Sbecore::uint CHKCONACTIVE = 11;
		static const Sbecore::uint CHKFALACTIVE = 12;
		static const Sbecore::uint PUPHTYACTIVE = 13;
		static const Sbecore::uint TXFHTYVALID = 14;
		static const Sbecore::uint BUTHTYEDITAVAIL = 15;
		static const Sbecore::uint TXFWIDACTIVE = 16;
		static const Sbecore::uint TXFMMXACTIVE = 17;
		static const Sbecore::uint TXFONVACTIVE = 18;
		static const Sbecore::uint TXFOFVACTIVE = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool ChkConActive = true, const bool ChkFalActive = true, const bool PupHtyActive = true, const bool TxfHtyValid = false, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfOnvActive = true, const bool TxfOfvActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool ChkConActive;
		bool ChkFalActive;
		bool PupHtyActive;
		bool TxfHtyValid;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfOnvActive;
		bool TxfOfvActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeVarDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTREU = 4;
		static const Sbecore::uint CPTCON = 5;
		static const Sbecore::uint CPTFAL = 6;
		static const Sbecore::uint CPTHTY = 7;
		static const Sbecore::uint CPTWID = 8;
		static const Sbecore::uint CPTMMX = 9;
		static const Sbecore::uint CPTONV = 10;
		static const Sbecore::uint CPTOFV = 11;
		static const Sbecore::uint CPTCMT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptClu = "", const std::string& CptReu = "", const std::string& CptCon = "", const std::string& CptFal = "", const std::string& CptHty = "", const std::string& CptWid = "", const std::string& CptMmx = "", const std::string& CptOnv = "", const std::string& CptOfv = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptClu;
		std::string CptReu;
		std::string CptCon;
		std::string CptFal;
		std::string CptHty;
		std::string CptWid;
		std::string CptMmx;
		std::string CptOnv;
		std::string CptOfv;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeVarDetailData)
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
		* DpchAppDo (full: DpchAppWdbeVarDetailDo)
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
		* DpchEngData (full: DpchEngWdbeVarDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPHTY = 5;
		static const Sbecore::uint FEEDFPUPRET = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupHty;
		Sbecore::Feed feedFPupRet;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
