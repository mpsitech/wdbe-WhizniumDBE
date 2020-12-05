/**
	* \file PnlWdbeTrgDetail.h
	* API code for job PnlWdbeTrgDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBETRGDETAIL_H
#define PNLWDBETRGDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeTrgDetailDo PnlWdbeTrgDetail::VecVDo

#define ContIacWdbeTrgDetail PnlWdbeTrgDetail::ContIac
#define ContInfWdbeTrgDetail PnlWdbeTrgDetail::ContInf
#define StatAppWdbeTrgDetail PnlWdbeTrgDetail::StatApp
#define StatShrWdbeTrgDetail PnlWdbeTrgDetail::StatShr
#define TagWdbeTrgDetail PnlWdbeTrgDetail::Tag

#define DpchAppWdbeTrgDetailData PnlWdbeTrgDetail::DpchAppData
#define DpchAppWdbeTrgDetailDo PnlWdbeTrgDetail::DpchAppDo
#define DpchEngWdbeTrgDetailData PnlWdbeTrgDetail::DpchEngData

/**
	* PnlWdbeTrgDetail
	*/
namespace PnlWdbeTrgDetail {
	/**
		* VecVDo (full: VecVWdbeTrgDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSYSVIEWCLICK = 2;
		static const Sbecore::uint BUTUNTVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeTrgDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTRTE = 1;
		static const Sbecore::uint TXFRTE = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const Sbecore::uint numFLstRte = 1, const std::string& TxfRte = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstRte;
		std::string TxfRte;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeTrgDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTSYS = 2;
		static const Sbecore::uint TXTUNT = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtSys = "", const std::string& TxtUnt = "");

	public:
		std::string TxtSrf;
		std::string TxtSys;
		std::string TxtUnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeTrgDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTRTEALT = 2;
		static const Sbecore::uint LSTRTENUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstRteAlt = true, const Sbecore::uint LstRteNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstRteAlt;
		Sbecore::uint LstRteNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeTrgDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFRTEVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTSYSACTIVE = 5;
		static const Sbecore::uint BUTSYSVIEWAVAIL = 6;
		static const Sbecore::uint BUTSYSVIEWACTIVE = 7;
		static const Sbecore::uint TXTUNTACTIVE = 8;
		static const Sbecore::uint BUTUNTVIEWAVAIL = 9;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 10;
		static const Sbecore::uint LSTRTEACTIVE = 11;
		static const Sbecore::uint TXFCMTACTIVE = 12;

	public:
		StatShr(const bool TxfRteValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtSysActive = true, const bool ButSysViewAvail = true, const bool ButSysViewActive = true, const bool TxtUntActive = true, const bool ButUntViewAvail = true, const bool ButUntViewActive = true, const bool LstRteActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfRteValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtSysActive;
		bool ButSysViewAvail;
		bool ButSysViewActive;
		bool TxtUntActive;
		bool ButUntViewAvail;
		bool ButUntViewActive;
		bool LstRteActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeTrgDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSYS = 3;
		static const Sbecore::uint CPTUNT = 4;
		static const Sbecore::uint CPTRTE = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSys = "", const std::string& CptUnt = "", const std::string& CptRte = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSys;
		std::string CptUnt;
		std::string CptRte;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeTrgDetailData)
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
		* DpchAppDo (full: DpchAppWdbeTrgDetailDo)
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
		* DpchEngData (full: DpchEngWdbeTrgDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTRTE = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstRte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

