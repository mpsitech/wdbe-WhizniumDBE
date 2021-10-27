/**
	* \file PnlWdbePplDetail.h
	* API code for job PnlWdbePplDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPPLDETAIL_H
#define PNLWDBEPPLDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbePplDetailDo PnlWdbePplDetail::VecVDo

#define ContIacWdbePplDetail PnlWdbePplDetail::ContIac
#define ContInfWdbePplDetail PnlWdbePplDetail::ContInf
#define StatAppWdbePplDetail PnlWdbePplDetail::StatApp
#define StatShrWdbePplDetail PnlWdbePplDetail::StatShr
#define TagWdbePplDetail PnlWdbePplDetail::Tag

#define DpchAppWdbePplDetailData PnlWdbePplDetail::DpchAppData
#define DpchAppWdbePplDetailDo PnlWdbePplDetail::DpchAppDo
#define DpchEngWdbePplDetailData PnlWdbePplDetail::DpchEngData

/**
	* PnlWdbePplDetail
	*/
namespace PnlWdbePplDetail {
	/**
		* VecVDo (full: VecVWdbePplDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTHSMVIEWCLICK = 2;
		static const Sbecore::uint BUTCLKVIEWCLICK = 3;
		static const Sbecore::uint BUTCLGVIEWCLICK = 4;
		static const Sbecore::uint BUTASRVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePplDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLK = 1;
		static const Sbecore::uint TXFCLG = 2;
		static const Sbecore::uint TXFASR = 3;
		static const Sbecore::uint TXFDPT = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const std::string& TxfClk = "", const std::string& TxfClg = "", const std::string& TxfAsr = "", const std::string& TxfDpt = "", const std::string& TxfCmt = "");

	public:
		std::string TxfClk;
		std::string TxfClg;
		std::string TxfAsr;
		std::string TxfDpt;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePplDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHSM = 2;
		static const Sbecore::uint TXTCLK = 3;
		static const Sbecore::uint TXTCLG = 4;
		static const Sbecore::uint TXTASR = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHsm = "", const std::string& TxtClk = "", const std::string& TxtClg = "", const std::string& TxtAsr = "");

	public:
		std::string TxtSrf;
		std::string TxtHsm;
		std::string TxtClk;
		std::string TxtClg;
		std::string TxtAsr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbePplDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint TXTCLKALT = 2;
		static const Sbecore::uint TXTCLGALT = 3;
		static const Sbecore::uint TXTASRALT = 4;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtClgAlt = false, const bool TxtAsrAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool TxtClkAlt;
		bool TxtClgAlt;
		bool TxtAsrAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePplDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLKVALID = 1;
		static const Sbecore::uint TXFCLGVALID = 2;
		static const Sbecore::uint TXFASRVALID = 3;
		static const Sbecore::uint BUTSAVEAVAIL = 4;
		static const Sbecore::uint BUTSAVEACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTHSMACTIVE = 7;
		static const Sbecore::uint BUTHSMVIEWAVAIL = 8;
		static const Sbecore::uint BUTHSMVIEWACTIVE = 9;
		static const Sbecore::uint TXTCLKACTIVE = 10;
		static const Sbecore::uint BUTCLKVIEWAVAIL = 11;
		static const Sbecore::uint TXTCLGACTIVE = 12;
		static const Sbecore::uint BUTCLGVIEWAVAIL = 13;
		static const Sbecore::uint TXTASRACTIVE = 14;
		static const Sbecore::uint BUTASRVIEWAVAIL = 15;
		static const Sbecore::uint TXFDPTACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool TxfClkValid = false, const bool TxfClgValid = false, const bool TxfAsrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtHsmActive = true, const bool ButHsmViewAvail = true, const bool ButHsmViewActive = true, const bool TxtClkActive = true, const bool ButClkViewAvail = true, const bool TxtClgActive = true, const bool ButClgViewAvail = true, const bool TxtAsrActive = true, const bool ButAsrViewAvail = true, const bool TxfDptActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfClkValid;
		bool TxfClgValid;
		bool TxfAsrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtHsmActive;
		bool ButHsmViewAvail;
		bool ButHsmViewActive;
		bool TxtClkActive;
		bool ButClkViewAvail;
		bool TxtClgActive;
		bool ButClgViewAvail;
		bool TxtAsrActive;
		bool ButAsrViewAvail;
		bool TxfDptActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePplDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTHSM = 3;
		static const Sbecore::uint CPTCLK = 4;
		static const Sbecore::uint CPTCLG = 5;
		static const Sbecore::uint CPTASR = 6;
		static const Sbecore::uint CPTDPT = 7;
		static const Sbecore::uint CPTCMT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptHsm = "", const std::string& CptClk = "", const std::string& CptClg = "", const std::string& CptAsr = "", const std::string& CptDpt = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptHsm;
		std::string CptClk;
		std::string CptClg;
		std::string CptAsr;
		std::string CptDpt;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePplDetailData)
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
		* DpchAppDo (full: DpchAppWdbePplDetailDo)
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
		* DpchEngData (full: DpchEngWdbePplDetailData)
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
