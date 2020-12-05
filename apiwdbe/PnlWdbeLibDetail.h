/**
	* \file PnlWdbeLibDetail.h
	* API code for job PnlWdbeLibDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBELIBDETAIL_H
#define PNLWDBELIBDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeLibDetailDo PnlWdbeLibDetail::VecVDo

#define ContIacWdbeLibDetail PnlWdbeLibDetail::ContIac
#define ContInfWdbeLibDetail PnlWdbeLibDetail::ContInf
#define StatAppWdbeLibDetail PnlWdbeLibDetail::StatApp
#define StatShrWdbeLibDetail PnlWdbeLibDetail::StatShr
#define TagWdbeLibDetail PnlWdbeLibDetail::Tag

#define DpchAppWdbeLibDetailData PnlWdbeLibDetail::DpchAppData
#define DpchAppWdbeLibDetailDo PnlWdbeLibDetail::DpchAppDo
#define DpchEngWdbeLibDetailData PnlWdbeLibDetail::DpchEngData

/**
	* PnlWdbeLibDetail
	*/
namespace PnlWdbeLibDetail {
	/**
		* VecVDo (full: VecVWdbeLibDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTDEPVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeLibDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFVER = 2;
		static const Sbecore::uint NUMFLSTDEP = 3;
		static const Sbecore::uint TXFDEP = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfVer = "", const Sbecore::uint numFLstDep = 1, const std::string& TxfDep = "", const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		std::string TxfVer;
		Sbecore::uint numFLstDep;
		std::string TxfDep;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeLibDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;

	public:
		ContInf(const std::string& TxtSrf = "");

	public:
		std::string TxtSrf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeLibDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTDEPALT = 2;
		static const Sbecore::uint LSTDEPNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstDepAlt = true, const Sbecore::uint LstDepNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstDepAlt;
		Sbecore::uint LstDepNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeLibDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFDEPVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXFTITACTIVE = 5;
		static const Sbecore::uint TXFVERACTIVE = 6;
		static const Sbecore::uint LSTDEPACTIVE = 7;
		static const Sbecore::uint BUTDEPVIEWAVAIL = 8;
		static const Sbecore::uint BUTDEPVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool TxfDepValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxfVerActive = true, const bool LstDepActive = true, const bool ButDepViewAvail = true, const bool ButDepViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfDepValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxfVerActive;
		bool LstDepActive;
		bool ButDepViewAvail;
		bool ButDepViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeLibDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTDEP = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptVer = "", const std::string& CptDep = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptVer;
		std::string CptDep;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeLibDetailData)
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
		* DpchAppDo (full: DpchAppWdbeLibDetailDo)
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
		* DpchEngData (full: DpchEngWdbeLibDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDEP = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDep;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

