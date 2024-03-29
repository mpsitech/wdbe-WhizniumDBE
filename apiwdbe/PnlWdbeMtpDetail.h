/**
	* \file PnlWdbeMtpDetail.h
	* API code for job PnlWdbeMtpDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMTPDETAIL_H
#define PNLWDBEMTPDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeMtpDetailDo PnlWdbeMtpDetail::VecVDo

#define ContIacWdbeMtpDetail PnlWdbeMtpDetail::ContIac
#define ContInfWdbeMtpDetail PnlWdbeMtpDetail::ContInf
#define StatAppWdbeMtpDetail PnlWdbeMtpDetail::StatApp
#define StatShrWdbeMtpDetail PnlWdbeMtpDetail::StatShr
#define TagWdbeMtpDetail PnlWdbeMtpDetail::Tag

#define DpchAppWdbeMtpDetailData PnlWdbeMtpDetail::DpchAppData
#define DpchAppWdbeMtpDetailDo PnlWdbeMtpDetail::DpchAppDo
#define DpchEngWdbeMtpDetailData PnlWdbeMtpDetail::DpchEngData

/**
	* PnlWdbeMtpDetail
	*/
namespace PnlWdbeMtpDetail {
	/**
		* VecVDo (full: VecVWdbeMtpDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVNDEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeMtpDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPVND = 1;
		static const Sbecore::uint TXFVND = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint TXFSRR = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupVnd = 1, const std::string& TxfVnd = "", const Sbecore::uint numFPupTyp = 1, const std::string& TxfSrr = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupVnd;
		std::string TxfVnd;
		Sbecore::uint numFPupTyp;
		std::string TxfSrr;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeMtpDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;

	public:
		ContInf(const std::string& TxtSrf = "");

	public:
		std::string TxtSrf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeMtpDetail)
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
	  * StatShr (full: StatShrWdbeMtpDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFVNDVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPVNDACTIVE = 5;
		static const Sbecore::uint BUTVNDEDITAVAIL = 6;
		static const Sbecore::uint PUPTYPACTIVE = 7;
		static const Sbecore::uint TXFSRRACTIVE = 8;
		static const Sbecore::uint TXFCMTACTIVE = 9;

	public:
		StatShr(const bool TxfVndValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupVndActive = true, const bool ButVndEditAvail = true, const bool PupTypActive = true, const bool TxfSrrActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfVndValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupVndActive;
		bool ButVndEditAvail;
		bool PupTypActive;
		bool TxfSrrActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeMtpDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTVND = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTSRR = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptVnd = "", const std::string& CptTyp = "", const std::string& CptSrr = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptVnd;
		std::string CptTyp;
		std::string CptSrr;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeMtpDetailData)
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
		* DpchAppDo (full: DpchAppWdbeMtpDetailDo)
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
		* DpchEngData (full: DpchEngWdbeMtpDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPTYP = 4;
		static const Sbecore::uint FEEDFPUPVND = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupTyp;
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
