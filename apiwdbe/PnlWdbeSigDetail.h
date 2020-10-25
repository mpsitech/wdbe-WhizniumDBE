/**
	* \file PnlWdbeSigDetail.h
	* API code for job PnlWdbeSigDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBESIGDETAIL_H
#define PNLWDBESIGDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSigDetailDo PnlWdbeSigDetail::VecVDo

#define ContIacWdbeSigDetail PnlWdbeSigDetail::ContIac
#define ContInfWdbeSigDetail PnlWdbeSigDetail::ContInf
#define StatAppWdbeSigDetail PnlWdbeSigDetail::StatApp
#define StatShrWdbeSigDetail PnlWdbeSigDetail::StatShr
#define TagWdbeSigDetail PnlWdbeSigDetail::Tag

#define DpchAppWdbeSigDetailData PnlWdbeSigDetail::DpchAppData
#define DpchAppWdbeSigDetailDo PnlWdbeSigDetail::DpchAppDo
#define DpchEngWdbeSigDetailData PnlWdbeSigDetail::DpchEngData

/**
	* PnlWdbeSigDetail
	*/
namespace PnlWdbeSigDetail {
	/**
		* VecVDo (full: VecVWdbeSigDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTMDLVIEWCLICK = 5;
		static const Sbecore::uint BUTMGUVIEWCLICK = 6;
		static const Sbecore::uint BUTVECVIEWCLICK = 7;
		static const Sbecore::uint BUTHTYEDITCLICK = 8;
		static const Sbecore::uint BUTDRVVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSigDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPMGT = 3;
		static const Sbecore::uint CHKCON = 4;
		static const Sbecore::uint NUMFPUPHTY = 5;
		static const Sbecore::uint TXFHTY = 6;
		static const Sbecore::uint TXFWID = 7;
		static const Sbecore::uint TXFMMX = 8;
		static const Sbecore::uint TXFCMB = 9;
		static const Sbecore::uint TXFONV = 10;
		static const Sbecore::uint TXFOFV = 11;
		static const Sbecore::uint CHKDFO = 12;
		static const Sbecore::uint TXFCMT = 13;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupMgt = 1, const bool ChkCon = false, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfCmb = "", const std::string& TxfOnv = "", const std::string& TxfOfv = "", const bool ChkDfo = false, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupMgt;
		bool ChkCon;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfCmb;
		std::string TxfOnv;
		std::string TxfOfv;
		bool ChkDfo;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeSigDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTMGU = 4;
		static const Sbecore::uint TXTVEC = 5;
		static const Sbecore::uint TXTDRV = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtMdl = "", const std::string& TxtMgu = "", const std::string& TxtVec = "", const std::string& TxtDrv = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtMdl;
		std::string TxtMgu;
		std::string TxtVec;
		std::string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeSigDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint PUPHTYALT = 3;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 4;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCluAlt;
		bool PupHtyAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeSigDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTMDLACTIVE = 10;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 11;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 12;
		static const Sbecore::uint TXTMGUACTIVE = 13;
		static const Sbecore::uint BUTMGUVIEWAVAIL = 14;
		static const Sbecore::uint BUTMGUVIEWACTIVE = 15;
		static const Sbecore::uint TXTVECACTIVE = 16;
		static const Sbecore::uint BUTVECVIEWAVAIL = 17;
		static const Sbecore::uint BUTVECVIEWACTIVE = 18;
		static const Sbecore::uint CHKCONACTIVE = 19;
		static const Sbecore::uint PUPHTYACTIVE = 20;
		static const Sbecore::uint BUTHTYEDITAVAIL = 21;
		static const Sbecore::uint TXFWIDACTIVE = 22;
		static const Sbecore::uint TXFMMXACTIVE = 23;
		static const Sbecore::uint TXFCMBACTIVE = 24;
		static const Sbecore::uint TXFONVACTIVE = 25;
		static const Sbecore::uint TXFOFVACTIVE = 26;
		static const Sbecore::uint CHKDFOACTIVE = 27;
		static const Sbecore::uint TXTDRVACTIVE = 28;
		static const Sbecore::uint BUTDRVVIEWAVAIL = 29;
		static const Sbecore::uint BUTDRVVIEWACTIVE = 30;
		static const Sbecore::uint TXFCMTACTIVE = 31;

	public:
		StatShr(const bool TxfHtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtMguActive = true, const bool ButMguViewAvail = true, const bool ButMguViewActive = true, const bool TxtVecActive = true, const bool ButVecViewAvail = true, const bool ButVecViewActive = true, const bool ChkConActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfCmbActive = true, const bool TxfOnvActive = true, const bool TxfOfvActive = true, const bool ChkDfoActive = true, const bool TxtDrvActive = true, const bool ButDrvViewAvail = true, const bool ButDrvViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtMguActive;
		bool ButMguViewAvail;
		bool ButMguViewActive;
		bool TxtVecActive;
		bool ButVecViewAvail;
		bool ButVecViewActive;
		bool ChkConActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfCmbActive;
		bool TxfOnvActive;
		bool TxfOfvActive;
		bool ChkDfoActive;
		bool TxtDrvActive;
		bool ButDrvViewAvail;
		bool ButDrvViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSigDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTCLU = 4;
		static const Sbecore::uint CPTMDL = 5;
		static const Sbecore::uint CPTMGU = 6;
		static const Sbecore::uint CPTVEC = 7;
		static const Sbecore::uint CPTCON = 8;
		static const Sbecore::uint CPTHTY = 9;
		static const Sbecore::uint CPTWID = 10;
		static const Sbecore::uint CPTMMX = 11;
		static const Sbecore::uint CPTCMB = 12;
		static const Sbecore::uint CPTONV = 13;
		static const Sbecore::uint CPTOFV = 14;
		static const Sbecore::uint CPTDFO = 15;
		static const Sbecore::uint CPTDRV = 16;
		static const Sbecore::uint CPTCMT = 17;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptClu = "", const std::string& CptMdl = "", const std::string& CptMgu = "", const std::string& CptVec = "", const std::string& CptCon = "", const std::string& CptHty = "", const std::string& CptWid = "", const std::string& CptMmx = "", const std::string& CptCmb = "", const std::string& CptOnv = "", const std::string& CptOfv = "", const std::string& CptDfo = "", const std::string& CptDrv = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptClu;
		std::string CptMdl;
		std::string CptMgu;
		std::string CptVec;
		std::string CptCon;
		std::string CptHty;
		std::string CptWid;
		std::string CptMmx;
		std::string CptCmb;
		std::string CptOnv;
		std::string CptOfv;
		std::string CptDfo;
		std::string CptDrv;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSigDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSigDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSigDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPHTY = 5;
		static const Sbecore::uint FEEDFPUPMGT = 6;
		static const Sbecore::uint FEEDFPUPTYP = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupHty;
		Sbecore::Xmlio::Feed feedFPupMgt;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

