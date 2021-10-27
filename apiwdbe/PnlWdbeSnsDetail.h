/**
	* \file PnlWdbeSnsDetail.h
	* API code for job PnlWdbeSnsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESNSDETAIL_H
#define PNLWDBESNSDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSnsDetailDo PnlWdbeSnsDetail::VecVDo

#define ContIacWdbeSnsDetail PnlWdbeSnsDetail::ContIac
#define ContInfWdbeSnsDetail PnlWdbeSnsDetail::ContInf
#define StatAppWdbeSnsDetail PnlWdbeSnsDetail::StatApp
#define StatShrWdbeSnsDetail PnlWdbeSnsDetail::StatShr
#define TagWdbeSnsDetail PnlWdbeSnsDetail::Tag

#define DpchAppWdbeSnsDetailData PnlWdbeSnsDetail::DpchAppData
#define DpchAppWdbeSnsDetailDo PnlWdbeSnsDetail::DpchAppDo
#define DpchEngWdbeSnsDetailData PnlWdbeSnsDetail::DpchEngData

/**
	* PnlWdbeSnsDetail
	*/
namespace PnlWdbeSnsDetail {
	/**
		* VecVDo (full: VecVWdbeSnsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;
		static const Sbecore::uint BUTSRUVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSnsDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPRET = 1;
		static const Sbecore::uint NUMFPUPSRT = 2;

	public:
		ContIac(const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupSrt = 1);

	public:
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupSrt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeSnsDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREU = 1;
		static const Sbecore::uint TXTSRU = 2;

	public:
		ContInf(const std::string& TxtReu = "", const std::string& TxtSru = "");

	public:
		std::string TxtReu;
		std::string TxtSru;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeSnsDetail)
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
	  * StatShr (full: StatShrWdbeSnsDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTREUACTIVE = 3;
		static const Sbecore::uint BUTREUVIEWAVAIL = 4;
		static const Sbecore::uint BUTREUVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRUACTIVE = 6;
		static const Sbecore::uint BUTSRUVIEWAVAIL = 7;
		static const Sbecore::uint BUTSRUVIEWACTIVE = 8;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtSruActive = true, const bool ButSruViewAvail = true, const bool ButSruViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtSruActive;
		bool ButSruViewAvail;
		bool ButSruViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSnsDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTREU = 2;
		static const Sbecore::uint CPTSRU = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptReu = "", const std::string& CptSru = "");

	public:
		std::string Cpt;
		std::string CptReu;
		std::string CptSru;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSnsDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSnsDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSnsDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPSRT = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupRet;
		Sbecore::Feed feedFPupSrt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
