/**
	* \file PnlWdbeRlsDetail.h
	* API code for job PnlWdbeRlsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBERLSDETAIL_H
#define PNLWDBERLSDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeRlsDetailDo PnlWdbeRlsDetail::VecVDo

#define ContIacWdbeRlsDetail PnlWdbeRlsDetail::ContIac
#define ContInfWdbeRlsDetail PnlWdbeRlsDetail::ContInf
#define StatAppWdbeRlsDetail PnlWdbeRlsDetail::StatApp
#define StatShrWdbeRlsDetail PnlWdbeRlsDetail::StatShr
#define TagWdbeRlsDetail PnlWdbeRlsDetail::Tag

#define DpchAppWdbeRlsDetailData PnlWdbeRlsDetail::DpchAppData
#define DpchAppWdbeRlsDetailDo PnlWdbeRlsDetail::DpchAppDo
#define DpchEngWdbeRlsDetailData PnlWdbeRlsDetail::DpchEngData

/**
	* PnlWdbeRlsDetail
	*/
namespace PnlWdbeRlsDetail {
	/**
		* VecVDo (full: VecVWdbeRlsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCMPVIEWCLICK = 2;
		static const Sbecore::uint BUTMCHVIEWCLICK = 3;
		static const Sbecore::uint BUTOPTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeRlsDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMSFLSTOPT = 1;
		static const Sbecore::uint TXFOPT = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const std::string& TxfCmt = "");

	public:
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeRlsDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCMP = 2;
		static const Sbecore::uint TXTMCH = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCmp = "", const std::string& TxtMch = "");

	public:
		std::string TxtSrf;
		std::string TxtCmp;
		std::string TxtMch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeRlsDetail)
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
	  * StatShr (full: StatShrWdbeRlsDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFOPTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTCMPACTIVE = 5;
		static const Sbecore::uint BUTCMPVIEWAVAIL = 6;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 7;
		static const Sbecore::uint TXTMCHACTIVE = 8;
		static const Sbecore::uint BUTMCHVIEWAVAIL = 9;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 10;
		static const Sbecore::uint LSTOPTACTIVE = 11;
		static const Sbecore::uint BUTOPTEDITAVAIL = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtCmpActive = true, const bool ButCmpViewAvail = true, const bool ButCmpViewActive = true, const bool TxtMchActive = true, const bool ButMchViewAvail = true, const bool ButMchViewActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtCmpActive;
		bool ButCmpViewAvail;
		bool ButCmpViewActive;
		bool TxtMchActive;
		bool ButMchViewAvail;
		bool ButMchViewActive;
		bool LstOptActive;
		bool ButOptEditAvail;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeRlsDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCMP = 3;
		static const Sbecore::uint CPTMCH = 4;
		static const Sbecore::uint CPTOPT = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptCmp = "", const std::string& CptMch = "", const std::string& CptOpt = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptCmp;
		std::string CptMch;
		std::string CptOpt;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeRlsDetailData)
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
		* DpchAppDo (full: DpchAppWdbeRlsDetailDo)
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
		* DpchEngData (full: DpchEngWdbeRlsDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOpt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
