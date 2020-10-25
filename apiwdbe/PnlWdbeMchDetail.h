/**
	* \file PnlWdbeMchDetail.h
	* API code for job PnlWdbeMchDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEMCHDETAIL_H
#define PNLWDBEMCHDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeMchDetailDo PnlWdbeMchDetail::VecVDo

#define ContIacWdbeMchDetail PnlWdbeMchDetail::ContIac
#define ContInfWdbeMchDetail PnlWdbeMchDetail::ContInf
#define StatAppWdbeMchDetail PnlWdbeMchDetail::StatApp
#define StatShrWdbeMchDetail PnlWdbeMchDetail::StatShr
#define TagWdbeMchDetail PnlWdbeMchDetail::Tag

#define DpchAppWdbeMchDetailData PnlWdbeMchDetail::DpchAppData
#define DpchAppWdbeMchDetailDo PnlWdbeMchDetail::DpchAppDo
#define DpchEngWdbeMchDetailData PnlWdbeMchDetail::DpchEngData

/**
	* PnlWdbeMchDetail
	*/
namespace PnlWdbeMchDetail {
	/**
		* VecVDo (full: VecVWdbeMchDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPLAEDITCLICK = 2;
		static const Sbecore::uint BUTCCHVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeMchDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPPLA = 1;
		static const Sbecore::uint TXFPLA = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const Sbecore::uint numFPupPla = 1, const std::string& TxfPla = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupPla;
		std::string TxfPla;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeMchDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCCH = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCch = "");

	public:
		std::string TxtSrf;
		std::string TxtCch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeMchDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint PUPPLAALT = 2;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupPlaAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool PupPlaAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeMchDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFPLAVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPPLAACTIVE = 5;
		static const Sbecore::uint BUTPLAEDITAVAIL = 6;
		static const Sbecore::uint TXTCCHACTIVE = 7;
		static const Sbecore::uint BUTCCHVIEWAVAIL = 8;
		static const Sbecore::uint BUTCCHVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool TxfPlaValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupPlaActive = true, const bool ButPlaEditAvail = true, const bool TxtCchActive = true, const bool ButCchViewAvail = true, const bool ButCchViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfPlaValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupPlaActive;
		bool ButPlaEditAvail;
		bool TxtCchActive;
		bool ButCchViewAvail;
		bool ButCchViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeMchDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTPLA = 3;
		static const Sbecore::uint CPTCCH = 4;
		static const Sbecore::uint CPTCMT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptPla = "", const std::string& CptCch = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptPla;
		std::string CptCch;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeMchDetailData)
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
		* DpchAppDo (full: DpchAppWdbeMchDetailDo)
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
		* DpchEngData (full: DpchEngWdbeMchDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPLA = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupPla;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

