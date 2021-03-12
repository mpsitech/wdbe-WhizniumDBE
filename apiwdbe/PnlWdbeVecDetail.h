/**
	* \file PnlWdbeVecDetail.h
	* API code for job PnlWdbeVecDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEVECDETAIL_H
#define PNLWDBEVECDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeVecDetailDo PnlWdbeVecDetail::VecVDo

#define ContIacWdbeVecDetail PnlWdbeVecDetail::ContIac
#define ContInfWdbeVecDetail PnlWdbeVecDetail::ContInf
#define StatAppWdbeVecDetail PnlWdbeVecDetail::StatApp
#define StatShrWdbeVecDetail PnlWdbeVecDetail::StatShr
#define TagWdbeVecDetail PnlWdbeVecDetail::Tag

#define DpchAppWdbeVecDetailData PnlWdbeVecDetail::DpchAppData
#define DpchAppWdbeVecDetailDo PnlWdbeVecDetail::DpchAppDo
#define DpchEngWdbeVecDetailData PnlWdbeVecDetail::DpchEngData

/**
	* PnlWdbeVecDetail
	*/
namespace PnlWdbeVecDetail {
	/**
		* VecVDo (full: VecVWdbeVecDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTHKUVIEWCLICK = 2;
		static const Sbecore::uint BUTOPTEDITCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeVecDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPHKT = 2;
		static const Sbecore::uint NUMSFLSTOPT = 3;
		static const Sbecore::uint TXFOPT = 4;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeVecDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHKU = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHku = "");

	public:
		std::string TxtSrf;
		std::string TxtHku;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeVecDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTOPTALT = 2;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstOptAlt;
		Sbecore::uint LstOptNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeVecDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFOPTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTHKUACTIVE = 6;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 7;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 8;
		static const Sbecore::uint LSTOPTACTIVE = 9;
		static const Sbecore::uint BUTOPTEDITAVAIL = 10;

	public:
		StatShr(const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true);

	public:
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool LstOptActive;
		bool ButOptEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeVecDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTHKU = 4;
		static const Sbecore::uint CPTOPT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptHku = "", const std::string& CptOpt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptHku;
		std::string CptOpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeVecDetailData)
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
		* DpchAppDo (full: DpchAppWdbeVecDetailDo)
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
		* DpchEngData (full: DpchEngWdbeVecDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint FEEDFPUPHKT = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOpt;
		Sbecore::Feed feedFPupHkt;
		Sbecore::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
