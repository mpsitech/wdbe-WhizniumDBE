/**
	* \file PnlWdbePphDetail.h
	* API code for job PnlWdbePphDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPPHDETAIL_H
#define PNLWDBEPPHDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbePphDetailDo PnlWdbePphDetail::VecVDo

#define ContIacWdbePphDetail PnlWdbePphDetail::ContIac
#define ContInfWdbePphDetail PnlWdbePphDetail::ContInf
#define StatAppWdbePphDetail PnlWdbePphDetail::StatApp
#define StatShrWdbePphDetail PnlWdbePphDetail::StatShr
#define TagWdbePphDetail PnlWdbePphDetail::Tag

#define DpchAppWdbePphDetailData PnlWdbePphDetail::DpchAppData
#define DpchAppWdbePphDetailDo PnlWdbePphDetail::DpchAppDo
#define DpchEngWdbePphDetailData PnlWdbePphDetail::DpchEngData

/**
	* PnlWdbePphDetail
	*/
namespace PnlWdbePphDetail {
	/**
		* VecVDo (full: VecVWdbePphDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTUNTVIEWCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePphDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCMT = 1;

	public:
		ContIac(const std::string& TxfCmt = "");

	public:
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePphDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTUNT = 2;
		static const Sbecore::uint TXTMDL = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtUnt = "", const std::string& TxtMdl = "");

	public:
		std::string TxtSrf;
		std::string TxtUnt;
		std::string TxtMdl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbePphDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);

	public:
		Sbecore::uint ixWdbeVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePphDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTUNTACTIVE = 4;
		static const Sbecore::uint BUTUNTVIEWAVAIL = 5;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 6;
		static const Sbecore::uint TXTMDLACTIVE = 7;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 8;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtUntActive = true, const bool ButUntViewAvail = true, const bool ButUntViewActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtUntActive;
		bool ButUntViewAvail;
		bool ButUntViewActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePphDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTUNT = 3;
		static const Sbecore::uint CPTMDL = 4;
		static const Sbecore::uint CPTCMT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptUnt = "", const std::string& CptMdl = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptUnt;
		std::string CptMdl;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePphDetailData)
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
		* DpchAppDo (full: DpchAppWdbePphDetailDo)
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
		* DpchEngData (full: DpchEngWdbePphDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
