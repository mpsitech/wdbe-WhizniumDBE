/**
	* \file PnlWdbeBnkDetail.h
	* API code for job PnlWdbeBnkDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEBNKDETAIL_H
#define PNLWDBEBNKDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeBnkDetailDo PnlWdbeBnkDetail::VecVDo

#define ContIacWdbeBnkDetail PnlWdbeBnkDetail::ContIac
#define ContInfWdbeBnkDetail PnlWdbeBnkDetail::ContInf
#define StatAppWdbeBnkDetail PnlWdbeBnkDetail::StatApp
#define StatShrWdbeBnkDetail PnlWdbeBnkDetail::StatShr
#define TagWdbeBnkDetail PnlWdbeBnkDetail::Tag

#define DpchAppWdbeBnkDetailData PnlWdbeBnkDetail::DpchAppData
#define DpchAppWdbeBnkDetailDo PnlWdbeBnkDetail::DpchAppDo
#define DpchEngWdbeBnkDetailData PnlWdbeBnkDetail::DpchEngData

/**
	* PnlWdbeBnkDetail
	*/
namespace PnlWdbeBnkDetail {
	/**
		* VecVDo (full: VecVWdbeBnkDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTUNTVIEWCLICK = 2;
		static const Sbecore::uint BUTVSTEDITCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeBnkDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPVST = 1;
		static const Sbecore::uint TXFVST = 2;

	public:
		ContIac(const Sbecore::uint numFPupVst = 1, const std::string& TxfVst = "");

	public:
		Sbecore::uint numFPupVst;
		std::string TxfVst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeBnkDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTUNT = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtUnt = "");

	public:
		std::string TxtSrf;
		std::string TxtUnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeBnkDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint PUPVSTALT = 2;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupVstAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool PupVstAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeBnkDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFVSTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTUNTACTIVE = 5;
		static const Sbecore::uint BUTUNTVIEWAVAIL = 6;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 7;
		static const Sbecore::uint PUPVSTACTIVE = 8;
		static const Sbecore::uint BUTVSTEDITAVAIL = 9;

	public:
		StatShr(const bool TxfVstValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtUntActive = true, const bool ButUntViewAvail = true, const bool ButUntViewActive = true, const bool PupVstActive = true, const bool ButVstEditAvail = true);

	public:
		bool TxfVstValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtUntActive;
		bool ButUntViewAvail;
		bool ButUntViewActive;
		bool PupVstActive;
		bool ButVstEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeBnkDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTUNT = 3;
		static const Sbecore::uint CPTVST = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptUnt = "", const std::string& CptVst = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptUnt;
		std::string CptVst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeBnkDetailData)
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
		* DpchAppDo (full: DpchAppWdbeBnkDetailDo)
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
		* DpchEngData (full: DpchEngWdbeBnkDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPVST = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupVst;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

