/**
	* \file PnlWdbeFamDetail.h
	* API code for job PnlWdbeFamDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEFAMDETAIL_H
#define PNLWDBEFAMDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeFamDetailDo PnlWdbeFamDetail::VecVDo

#define ContIacWdbeFamDetail PnlWdbeFamDetail::ContIac
#define StatAppWdbeFamDetail PnlWdbeFamDetail::StatApp
#define StatShrWdbeFamDetail PnlWdbeFamDetail::StatShr
#define TagWdbeFamDetail PnlWdbeFamDetail::Tag

#define DpchAppWdbeFamDetailData PnlWdbeFamDetail::DpchAppData
#define DpchAppWdbeFamDetailDo PnlWdbeFamDetail::DpchAppDo
#define DpchEngWdbeFamDetailData PnlWdbeFamDetail::DpchEngData

/**
	* PnlWdbeFamDetail
	*/
namespace PnlWdbeFamDetail {
	/**
		* VecVDo (full: VecVWdbeFamDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVNDEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeFamDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPVND = 1;
		static const Sbecore::uint TXFVND = 2;
		static const Sbecore::uint TXFTIT = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFPupVnd = 1, const std::string& TxfVnd = "", const std::string& TxfTit = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupVnd;
		std::string TxfVnd;
		std::string TxfTit;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeFamDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint PUPVNDALT = 2;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupVndAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool PupVndAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeFamDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPVNDACTIVE = 3;
		static const Sbecore::uint TXFVNDVALID = 4;
		static const Sbecore::uint BUTVNDEDITAVAIL = 5;
		static const Sbecore::uint TXFTITACTIVE = 6;
		static const Sbecore::uint TXFCMTACTIVE = 7;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupVndActive = true, const bool TxfVndValid = false, const bool ButVndEditAvail = true, const bool TxfTitActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupVndActive;
		bool TxfVndValid;
		bool ButVndEditAvail;
		bool TxfTitActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeFamDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTVND = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTCMT = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptVnd = "", const std::string& CptTit = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptVnd;
		std::string CptTit;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeFamDetailData)
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
		* DpchAppDo (full: DpchAppWdbeFamDetailDo)
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
		* DpchEngData (full: DpchEngWdbeFamDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUPVND = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFPupVnd;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
