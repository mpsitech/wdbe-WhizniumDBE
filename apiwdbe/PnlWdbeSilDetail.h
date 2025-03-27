/**
	* \file PnlWdbeSilDetail.h
	* API code for job PnlWdbeSilDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESILDETAIL_H
#define PNLWDBESILDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSilDetailDo PnlWdbeSilDetail::VecVDo

#define ContIacWdbeSilDetail PnlWdbeSilDetail::ContIac
#define ContInfWdbeSilDetail PnlWdbeSilDetail::ContInf
#define StatAppWdbeSilDetail PnlWdbeSilDetail::StatApp
#define StatShrWdbeSilDetail PnlWdbeSilDetail::StatShr
#define TagWdbeSilDetail PnlWdbeSilDetail::Tag

#define DpchAppWdbeSilDetailData PnlWdbeSilDetail::DpchAppData
#define DpchAppWdbeSilDetailDo PnlWdbeSilDetail::DpchAppDo
#define DpchEngWdbeSilDetailData PnlWdbeSilDetail::DpchEngData

/**
	* PnlWdbeSilDetail
	*/
namespace PnlWdbeSilDetail {
	/**
		* VecVDo (full: VecVWdbeSilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;
		static const Sbecore::uint BUTPKGEDITCLICK = 4;
		static const Sbecore::uint BUTTCHEDITCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSilDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFSR = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint NUMFPUPRET = 4;
		static const Sbecore::uint NUMFPUPPKG = 5;
		static const Sbecore::uint TXFPKG = 6;
		static const Sbecore::uint CHKESY = 7;
		static const Sbecore::uint NUMFPUPTCH = 8;
		static const Sbecore::uint TXFTCH = 9;
		static const Sbecore::uint TXFCMT = 10;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFsr = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupPkg = 1, const std::string& TxfPkg = "", const bool ChkEsy = false, const Sbecore::uint numFPupTch = 1, const std::string& TxfTch = "", const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		std::string TxfFsr;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupPkg;
		std::string TxfPkg;
		bool ChkEsy;
		Sbecore::uint numFPupTch;
		std::string TxfTch;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeSilDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTREU = 2;
		static const Sbecore::uint TXTMDL = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtReu = "", const std::string& TxtMdl = "");

	public:
		std::string TxtSrf;
		std::string TxtReu;
		std::string TxtMdl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeSilDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint PUPPKGALT = 2;
		static const Sbecore::uint PUPTCHALT = 3;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupPkgAlt = false, const bool PupTchAlt = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool PupPkgAlt;
		bool PupTchAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeSilDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint TXFFSRACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTREUACTIVE = 7;
		static const Sbecore::uint BUTREUVIEWAVAIL = 8;
		static const Sbecore::uint BUTREUVIEWACTIVE = 9;
		static const Sbecore::uint TXTMDLACTIVE = 10;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 11;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 12;
		static const Sbecore::uint PUPPKGACTIVE = 13;
		static const Sbecore::uint TXFPKGVALID = 14;
		static const Sbecore::uint BUTPKGEDITAVAIL = 15;
		static const Sbecore::uint CHKESYACTIVE = 16;
		static const Sbecore::uint PUPTCHACTIVE = 17;
		static const Sbecore::uint TXFTCHVALID = 18;
		static const Sbecore::uint BUTTCHEDITAVAIL = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxfFsrActive = true, const bool PupTypActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool PupPkgActive = true, const bool TxfPkgValid = false, const bool ButPkgEditAvail = true, const bool ChkEsyActive = true, const bool PupTchActive = true, const bool TxfTchValid = false, const bool ButTchEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxfFsrActive;
		bool PupTypActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool PupPkgActive;
		bool TxfPkgValid;
		bool ButPkgEditAvail;
		bool ChkEsyActive;
		bool PupTchActive;
		bool TxfTchValid;
		bool ButTchEditAvail;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSilDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTFSR = 4;
		static const Sbecore::uint CPTTYP = 5;
		static const Sbecore::uint CPTREU = 6;
		static const Sbecore::uint CPTMDL = 7;
		static const Sbecore::uint CPTPKG = 8;
		static const Sbecore::uint CPTESY = 9;
		static const Sbecore::uint CPTTCH = 10;
		static const Sbecore::uint CPTCMT = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptFsr = "", const std::string& CptTyp = "", const std::string& CptReu = "", const std::string& CptMdl = "", const std::string& CptPkg = "", const std::string& CptEsy = "", const std::string& CptTch = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptFsr;
		std::string CptTyp;
		std::string CptReu;
		std::string CptMdl;
		std::string CptPkg;
		std::string CptEsy;
		std::string CptTch;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSilDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSilDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSilDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPKG = 4;
		static const Sbecore::uint FEEDFPUPRET = 5;
		static const Sbecore::uint FEEDFPUPTCH = 6;
		static const Sbecore::uint FEEDFPUPTYP = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupPkg;
		Sbecore::Feed feedFPupRet;
		Sbecore::Feed feedFPupTch;
		Sbecore::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
