/**
	* \file PnlWdbePinDetail.h
	* API code for job PnlWdbePinDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPINDETAIL_H
#define PNLWDBEPINDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbePinDetailDo PnlWdbePinDetail::VecVDo

#define ContIacWdbePinDetail PnlWdbePinDetail::ContIac
#define ContInfWdbePinDetail PnlWdbePinDetail::ContInf
#define StatAppWdbePinDetail PnlWdbePinDetail::StatApp
#define StatShrWdbePinDetail PnlWdbePinDetail::StatShr
#define TagWdbePinDetail PnlWdbePinDetail::Tag

#define DpchAppWdbePinDetailData PnlWdbePinDetail::DpchAppData
#define DpchAppWdbePinDetailDo PnlWdbePinDetail::DpchAppDo
#define DpchEngWdbePinDetailData PnlWdbePinDetail::DpchEngData

/**
	* PnlWdbePinDetail
	*/
namespace PnlWdbePinDetail {
	/**
		* VecVDo (full: VecVWdbePinDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJSREDITCLICK = 2;
		static const Sbecore::uint BUTCLUVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 4;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 5;
		static const Sbecore::uint BUTBNKVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePinDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJSR = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint TXFLOC = 3;

	public:
		ContIac(const Sbecore::uint numFPupJsr = 1, const Sbecore::uint numFLstClu = 1, const std::string& TxfLoc = "");

	public:
		Sbecore::uint numFPupJsr;
		Sbecore::uint numFLstClu;
		std::string TxfLoc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePinDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTBNK = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtBnk = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtBnk;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbePinDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWdbePinDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPJSRACTIVE = 3;
		static const Sbecore::uint BUTJSREDITAVAIL = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTBNKACTIVE = 10;
		static const Sbecore::uint BUTBNKVIEWAVAIL = 11;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 12;
		static const Sbecore::uint TXFLOCACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupJsrActive = true, const bool ButJsrEditAvail = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtBnkActive = true, const bool ButBnkViewAvail = true, const bool ButBnkViewActive = true, const bool TxfLocActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupJsrActive;
		bool ButJsrEditAvail;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtBnkActive;
		bool ButBnkViewAvail;
		bool ButBnkViewActive;
		bool TxfLocActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePinDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTBNK = 4;
		static const Sbecore::uint CPTLOC = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptClu = "", const std::string& CptBnk = "", const std::string& CptLoc = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptClu;
		std::string CptBnk;
		std::string CptLoc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePinDetailData)
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
		* DpchAppDo (full: DpchAppWdbePinDetailDo)
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
		* DpchEngData (full: DpchEngWdbePinDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPJSR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupJsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

