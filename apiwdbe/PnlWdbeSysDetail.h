/**
	* \file PnlWdbeSysDetail.h
	* API code for job PnlWdbeSysDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESYSDETAIL_H
#define PNLWDBESYSDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSysDetailDo PnlWdbeSysDetail::VecVDo

#define ContIacWdbeSysDetail PnlWdbeSysDetail::ContIac
#define ContInfWdbeSysDetail PnlWdbeSysDetail::ContInf
#define StatAppWdbeSysDetail PnlWdbeSysDetail::StatApp
#define StatShrWdbeSysDetail PnlWdbeSysDetail::StatShr
#define TagWdbeSysDetail PnlWdbeSysDetail::Tag

#define DpchAppWdbeSysDetailData PnlWdbeSysDetail::DpchAppData
#define DpchAppWdbeSysDetailDo PnlWdbeSysDetail::DpchAppDo
#define DpchEngWdbeSysDetailData PnlWdbeSysDetail::DpchEngData

/**
	* PnlWdbeSysDetail
	*/
namespace PnlWdbeSysDetail {
	/**
		* VecVDo (full: VecVWdbeSysDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTUNTVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSysDetail)
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
	  * ContInf (full: ContInfWdbeSysDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTUNT = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtUnt = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtUnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeSysDetail)
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
	  * StatShr (full: StatShrWdbeSysDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTVERACTIVE = 4;
		static const Sbecore::uint BUTVERVIEWAVAIL = 5;
		static const Sbecore::uint BUTVERVIEWACTIVE = 6;
		static const Sbecore::uint TXTUNTACTIVE = 7;
		static const Sbecore::uint BUTUNTVIEWAVAIL = 8;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtUntActive = true, const bool ButUntViewAvail = true, const bool ButUntViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtUntActive;
		bool ButUntViewAvail;
		bool ButUntViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSysDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTVER = 3;
		static const Sbecore::uint CPTUNT = 4;
		static const Sbecore::uint CPTCMT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptVer = "", const std::string& CptUnt = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptVer;
		std::string CptUnt;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSysDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSysDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSysDetailData)
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
