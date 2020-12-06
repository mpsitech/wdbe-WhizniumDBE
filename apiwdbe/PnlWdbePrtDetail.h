/**
	* \file PnlWdbePrtDetail.h
	* API code for job PnlWdbePrtDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRTDETAIL_H
#define PNLWDBEPRTDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbePrtDetailDo PnlWdbePrtDetail::VecVDo

#define ContIacWdbePrtDetail PnlWdbePrtDetail::ContIac
#define ContInfWdbePrtDetail PnlWdbePrtDetail::ContInf
#define StatAppWdbePrtDetail PnlWdbePrtDetail::StatApp
#define StatShrWdbePrtDetail PnlWdbePrtDetail::StatShr
#define TagWdbePrtDetail PnlWdbePrtDetail::Tag

#define DpchAppWdbePrtDetailData PnlWdbePrtDetail::DpchAppData
#define DpchAppWdbePrtDetailDo PnlWdbePrtDetail::DpchAppDo
#define DpchEngWdbePrtDetailData PnlWdbePrtDetail::DpchEngData

/**
	* PnlWdbePrtDetail
	*/
namespace PnlWdbePrtDetail {
	/**
		* VecVDo (full: VecVWdbePrtDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTMDLVIEWCLICK = 5;
		static const Sbecore::uint BUTHTYEDITCLICK = 6;
		static const Sbecore::uint BUTCPIVIEWCLICK = 7;
		static const Sbecore::uint BUTCPRVIEWCLICK = 8;
		static const Sbecore::uint BUTCSIVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrtDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint NUMFPUPDIR = 2;
		static const Sbecore::uint NUMFPUPHTY = 3;
		static const Sbecore::uint TXFHTY = 4;
		static const Sbecore::uint TXFWID = 5;
		static const Sbecore::uint TXFMMX = 6;
		static const Sbecore::uint TXFDFV = 7;
		static const Sbecore::uint TXFCPI = 8;
		static const Sbecore::uint TXFCPR = 9;
		static const Sbecore::uint TXFCSI = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupDir = 1, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfDfv = "", const std::string& TxfCpi = "", const std::string& TxfCpr = "", const std::string& TxfCsi = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupDir;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfDfv;
		std::string TxfCpi;
		std::string TxfCpr;
		std::string TxfCsi;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePrtDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTCPI = 4;
		static const Sbecore::uint TXTCPR = 5;
		static const Sbecore::uint TXTCSI = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtMdl = "", const std::string& TxtCpi = "", const std::string& TxtCpr = "", const std::string& TxtCsi = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtMdl;
		std::string TxtCpi;
		std::string TxtCpr;
		std::string TxtCsi;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbePrtDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint PUPHTYALT = 3;
		static const Sbecore::uint TXTCPIALT = 4;
		static const Sbecore::uint TXTCPRALT = 5;
		static const Sbecore::uint TXTCSIALT = 6;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 7;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const bool TxtCpiAlt = false, const bool TxtCprAlt = false, const bool TxtCsiAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCluAlt;
		bool PupHtyAlt;
		bool TxtCpiAlt;
		bool TxtCprAlt;
		bool TxtCsiAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePrtDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint TXFCPIVALID = 2;
		static const Sbecore::uint TXFCPRVALID = 3;
		static const Sbecore::uint TXFCSIVALID = 4;
		static const Sbecore::uint BUTSAVEAVAIL = 5;
		static const Sbecore::uint BUTSAVEACTIVE = 6;
		static const Sbecore::uint TXTSRFACTIVE = 7;
		static const Sbecore::uint LSTCLUACTIVE = 8;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 9;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 10;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 11;
		static const Sbecore::uint TXTMDLACTIVE = 12;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 13;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 14;
		static const Sbecore::uint PUPDIRACTIVE = 15;
		static const Sbecore::uint PUPHTYACTIVE = 16;
		static const Sbecore::uint BUTHTYEDITAVAIL = 17;
		static const Sbecore::uint TXFWIDACTIVE = 18;
		static const Sbecore::uint TXFMMXACTIVE = 19;
		static const Sbecore::uint TXFDFVACTIVE = 20;
		static const Sbecore::uint TXTCPIACTIVE = 21;
		static const Sbecore::uint BUTCPIVIEWAVAIL = 22;
		static const Sbecore::uint TXTCPRACTIVE = 23;
		static const Sbecore::uint BUTCPRVIEWAVAIL = 24;
		static const Sbecore::uint TXTCSIACTIVE = 25;
		static const Sbecore::uint BUTCSIVIEWAVAIL = 26;
		static const Sbecore::uint TXFCMTACTIVE = 27;

	public:
		StatShr(const bool TxfHtyValid = false, const bool TxfCpiValid = false, const bool TxfCprValid = false, const bool TxfCsiValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool PupDirActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfDfvActive = true, const bool TxtCpiActive = true, const bool ButCpiViewAvail = true, const bool TxtCprActive = true, const bool ButCprViewAvail = true, const bool TxtCsiActive = true, const bool ButCsiViewAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool TxfCpiValid;
		bool TxfCprValid;
		bool TxfCsiValid;
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
		bool PupDirActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfDfvActive;
		bool TxtCpiActive;
		bool ButCpiViewAvail;
		bool TxtCprActive;
		bool ButCprViewAvail;
		bool TxtCsiActive;
		bool ButCsiViewAvail;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePrtDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTMDL = 4;
		static const Sbecore::uint CPTDIR = 5;
		static const Sbecore::uint CPTHTY = 6;
		static const Sbecore::uint CPTWID = 7;
		static const Sbecore::uint CPTMMX = 8;
		static const Sbecore::uint CPTDFV = 9;
		static const Sbecore::uint CPTCPI = 10;
		static const Sbecore::uint CPTCPR = 11;
		static const Sbecore::uint CPTCSI = 12;
		static const Sbecore::uint CPTCMT = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptClu = "", const std::string& CptMdl = "", const std::string& CptDir = "", const std::string& CptHty = "", const std::string& CptWid = "", const std::string& CptMmx = "", const std::string& CptDfv = "", const std::string& CptCpi = "", const std::string& CptCpr = "", const std::string& CptCsi = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptClu;
		std::string CptMdl;
		std::string CptDir;
		std::string CptHty;
		std::string CptWid;
		std::string CptMmx;
		std::string CptDfv;
		std::string CptCpi;
		std::string CptCpr;
		std::string CptCsi;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrtDetailData)
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
		* DpchAppDo (full: DpchAppWdbePrtDetailDo)
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
		* DpchEngData (full: DpchEngWdbePrtDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPDIR = 5;
		static const Sbecore::uint FEEDFPUPHTY = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupDir;
		Sbecore::Xmlio::Feed feedFPupHty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
