/**
	* \file PnlWdbeGenDetail.h
	* API code for job PnlWdbeGenDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEGENDETAIL_H
#define PNLWDBEGENDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeGenDetailDo PnlWdbeGenDetail::VecVDo

#define ContIacWdbeGenDetail PnlWdbeGenDetail::ContIac
#define ContInfWdbeGenDetail PnlWdbeGenDetail::ContInf
#define StatAppWdbeGenDetail PnlWdbeGenDetail::StatApp
#define StatShrWdbeGenDetail PnlWdbeGenDetail::StatShr
#define TagWdbeGenDetail PnlWdbeGenDetail::Tag

#define DpchAppWdbeGenDetailData PnlWdbeGenDetail::DpchAppData
#define DpchAppWdbeGenDetailDo PnlWdbeGenDetail::DpchAppDo
#define DpchEngWdbeGenDetailData PnlWdbeGenDetail::DpchEngData

/**
	* PnlWdbeGenDetail
	*/
namespace PnlWdbeGenDetail {
	/**
		* VecVDo (full: VecVWdbeGenDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTMDLVIEWCLICK = 5;
		static const Sbecore::uint BUTHTYEDITCLICK = 6;
		static const Sbecore::uint BUTSRCVIEWCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeGenDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint NUMFPUPHTY = 2;
		static const Sbecore::uint TXFHTY = 3;
		static const Sbecore::uint TXFWID = 4;
		static const Sbecore::uint TXFMMX = 5;
		static const Sbecore::uint TXFDFV = 6;
		static const Sbecore::uint TXFSRC = 7;
		static const Sbecore::uint TXFCMT = 8;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfDfv = "", const std::string& TxfSrc = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfDfv;
		std::string TxfSrc;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeGenDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTSRC = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtMdl = "", const std::string& TxtSrc = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtMdl;
		std::string TxtSrc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeGenDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint PUPHTYALT = 3;
		static const Sbecore::uint TXTSRCALT = 4;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const bool TxtSrcAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCluAlt;
		bool PupHtyAlt;
		bool TxtSrcAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeGenDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint TXFSRCVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTMDLACTIVE = 10;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 11;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 12;
		static const Sbecore::uint PUPHTYACTIVE = 13;
		static const Sbecore::uint BUTHTYEDITAVAIL = 14;
		static const Sbecore::uint TXFWIDACTIVE = 15;
		static const Sbecore::uint TXFMMXACTIVE = 16;
		static const Sbecore::uint TXFDFVACTIVE = 17;
		static const Sbecore::uint TXTSRCACTIVE = 18;
		static const Sbecore::uint BUTSRCVIEWAVAIL = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfHtyValid = false, const bool TxfSrcValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfDfvActive = true, const bool TxtSrcActive = true, const bool ButSrcViewAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool TxfSrcValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfDfvActive;
		bool TxtSrcActive;
		bool ButSrcViewAvail;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeGenDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTMDL = 4;
		static const Sbecore::uint CPTHTY = 5;
		static const Sbecore::uint CPTWID = 6;
		static const Sbecore::uint CPTMMX = 7;
		static const Sbecore::uint CPTDFV = 8;
		static const Sbecore::uint CPTSRC = 9;
		static const Sbecore::uint CPTCMT = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptClu = "", const std::string& CptMdl = "", const std::string& CptHty = "", const std::string& CptWid = "", const std::string& CptMmx = "", const std::string& CptDfv = "", const std::string& CptSrc = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptClu;
		std::string CptMdl;
		std::string CptHty;
		std::string CptWid;
		std::string CptMmx;
		std::string CptDfv;
		std::string CptSrc;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeGenDetailData)
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
		* DpchAppDo (full: DpchAppWdbeGenDetailDo)
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
		* DpchEngData (full: DpchEngWdbeGenDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPHTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupHty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
