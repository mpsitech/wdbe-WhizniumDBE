/**
	* \file PnlWdbeSegDetail.h
	* API code for job PnlWdbeSegDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESEGDETAIL_H
#define PNLWDBESEGDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSegDetailDo PnlWdbeSegDetail::VecVDo

#define ContIacWdbeSegDetail PnlWdbeSegDetail::ContIac
#define ContInfWdbeSegDetail PnlWdbeSegDetail::ContInf
#define StatAppWdbeSegDetail PnlWdbeSegDetail::StatApp
#define StatShrWdbeSegDetail PnlWdbeSegDetail::StatShr
#define TagWdbeSegDetail PnlWdbeSegDetail::Tag

#define DpchAppWdbeSegDetailData PnlWdbeSegDetail::DpchAppData
#define DpchAppWdbeSegDetailDo PnlWdbeSegDetail::DpchAppDo
#define DpchEngWdbeSegDetailData PnlWdbeSegDetail::DpchEngData

/**
	* PnlWdbeSegDetail
	*/
namespace PnlWdbeSegDetail {
	/**
		* VecVDo (full: VecVWdbeSegDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTPPLVIEWCLICK = 5;
		static const Sbecore::uint BUTSUPVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSegDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint TXFIFM = 2;
		static const Sbecore::uint TXFOFM = 3;
		static const Sbecore::uint TXFLCY = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const std::string& TxfIfm = "", const std::string& TxfOfm = "", const std::string& TxfLcy = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		std::string TxfIfm;
		std::string TxfOfm;
		std::string TxfLcy;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeSegDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTPPL = 3;
		static const Sbecore::uint TXTSUP = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtPpl = "", const std::string& TxtSup = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtPpl;
		std::string TxtSup;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeSegDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCluAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeSegDetail)
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
		static const Sbecore::uint TXTPPLACTIVE = 8;
		static const Sbecore::uint BUTPPLVIEWAVAIL = 9;
		static const Sbecore::uint BUTPPLVIEWACTIVE = 10;
		static const Sbecore::uint TXTSUPACTIVE = 11;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 12;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 13;
		static const Sbecore::uint TXFIFMACTIVE = 14;
		static const Sbecore::uint TXFOFMACTIVE = 15;
		static const Sbecore::uint TXFLCYACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtPplActive = true, const bool ButPplViewAvail = true, const bool ButPplViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxfIfmActive = true, const bool TxfOfmActive = true, const bool TxfLcyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtPplActive;
		bool ButPplViewAvail;
		bool ButPplViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxfIfmActive;
		bool TxfOfmActive;
		bool TxfLcyActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSegDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTPPL = 4;
		static const Sbecore::uint CPTSUP = 5;
		static const Sbecore::uint CPTIFM = 6;
		static const Sbecore::uint CPTOFM = 7;
		static const Sbecore::uint CPTLCY = 8;
		static const Sbecore::uint CPTCMT = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptClu = "", const std::string& CptPpl = "", const std::string& CptSup = "", const std::string& CptIfm = "", const std::string& CptOfm = "", const std::string& CptLcy = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptClu;
		std::string CptPpl;
		std::string CptSup;
		std::string CptIfm;
		std::string CptOfm;
		std::string CptLcy;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSegDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSegDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSegDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
