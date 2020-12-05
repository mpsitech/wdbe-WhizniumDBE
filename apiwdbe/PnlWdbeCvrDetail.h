/**
	* \file PnlWdbeCvrDetail.h
	* API code for job PnlWdbeCvrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBECVRDETAIL_H
#define PNLWDBECVRDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeCvrDetailDo PnlWdbeCvrDetail::VecVDo

#define ContIacWdbeCvrDetail PnlWdbeCvrDetail::ContIac
#define ContInfWdbeCvrDetail PnlWdbeCvrDetail::ContInf
#define StatAppWdbeCvrDetail PnlWdbeCvrDetail::StatApp
#define StatShrWdbeCvrDetail PnlWdbeCvrDetail::StatShr
#define TagWdbeCvrDetail PnlWdbeCvrDetail::Tag

#define DpchAppWdbeCvrDetailData PnlWdbeCvrDetail::DpchAppData
#define DpchAppWdbeCvrDetailDo PnlWdbeCvrDetail::DpchAppDo
#define DpchEngWdbeCvrDetailData PnlWdbeCvrDetail::DpchEngData

/**
	* PnlWdbeCvrDetail
	*/
namespace PnlWdbeCvrDetail {
	/**
		* VecVDo (full: VecVWdbeCvrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCPRVIEWCLICK = 2;
		static const Sbecore::uint BUTBCVVIEWCLICK = 3;
		static const Sbecore::uint BUTJSTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCvrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFMAJ = 1;
		static const Sbecore::uint TXFMIN = 2;
		static const Sbecore::uint TXFSUB = 3;
		static const Sbecore::uint NUMFPUPJST = 4;
		static const Sbecore::uint NUMFPUPSTE = 5;
		static const Sbecore::uint NUMSFLSTSTY = 6;

	public:
		ContIac(const std::string& TxfMaj = "", const std::string& TxfMin = "", const std::string& TxfSub = "", const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const std::vector<Sbecore::uint>& numsFLstSty = {});

	public:
		std::string TxfMaj;
		std::string TxfMin;
		std::string TxfSub;
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		std::vector<Sbecore::uint> numsFLstSty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCvrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCPR = 1;
		static const Sbecore::uint TXTBCV = 2;
		static const Sbecore::uint TXTSTY = 3;

	public:
		ContInf(const std::string& TxtCpr = "", const std::string& TxtBcv = "", const std::string& TxtSty = "");

	public:
		std::string TxtCpr;
		std::string TxtBcv;
		std::string TxtSty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeCvrDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTSTYALT = 2;
		static const Sbecore::uint LSTSTYNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstStyAlt = true, const Sbecore::uint LstStyNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstStyAlt;
		Sbecore::uint LstStyNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeCvrDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTCPRACTIVE = 3;
		static const Sbecore::uint BUTCPRVIEWAVAIL = 4;
		static const Sbecore::uint BUTCPRVIEWACTIVE = 5;
		static const Sbecore::uint TXFMAJACTIVE = 6;
		static const Sbecore::uint TXFMINACTIVE = 7;
		static const Sbecore::uint TXFSUBACTIVE = 8;
		static const Sbecore::uint TXTBCVACTIVE = 9;
		static const Sbecore::uint BUTBCVVIEWAVAIL = 10;
		static const Sbecore::uint BUTBCVVIEWACTIVE = 11;
		static const Sbecore::uint PUPJSTACTIVE = 12;
		static const Sbecore::uint BUTJSTEDITAVAIL = 13;
		static const Sbecore::uint PUPSTEACTIVE = 14;
		static const Sbecore::uint LSTSTYACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtCprActive = true, const bool ButCprViewAvail = true, const bool ButCprViewActive = true, const bool TxfMajActive = true, const bool TxfMinActive = true, const bool TxfSubActive = true, const bool TxtBcvActive = true, const bool ButBcvViewAvail = true, const bool ButBcvViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool LstStyActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtCprActive;
		bool ButCprViewAvail;
		bool ButCprViewActive;
		bool TxfMajActive;
		bool TxfMinActive;
		bool TxfSubActive;
		bool TxtBcvActive;
		bool ButBcvViewAvail;
		bool ButBcvViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool LstStyActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeCvrDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCPR = 2;
		static const Sbecore::uint CPTMAJ = 3;
		static const Sbecore::uint CPTMIN = 4;
		static const Sbecore::uint CPTSUB = 5;
		static const Sbecore::uint CPTBCV = 6;
		static const Sbecore::uint CPTSTE = 7;
		static const Sbecore::uint CPTSTY = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCpr = "", const std::string& CptMaj = "", const std::string& CptMin = "", const std::string& CptSub = "", const std::string& CptBcv = "", const std::string& CptSte = "", const std::string& CptSty = "");

	public:
		std::string Cpt;
		std::string CptCpr;
		std::string CptMaj;
		std::string CptMin;
		std::string CptSub;
		std::string CptBcv;
		std::string CptSte;
		std::string CptSty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCvrDetailData)
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
		* DpchAppDo (full: DpchAppWdbeCvrDetailDo)
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
		* DpchEngData (full: DpchEngWdbeCvrDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTSTY = 4;
		static const Sbecore::uint FEEDFPUPJST = 5;
		static const Sbecore::uint FEEDFPUPSTE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstSty;
		Sbecore::Xmlio::Feed feedFPupJst;
		Sbecore::Xmlio::Feed feedFPupSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

