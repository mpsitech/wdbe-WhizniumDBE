/**
	* \file PnlWdbeModDetail.h
	* API code for job PnlWdbeModDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEMODDETAIL_H
#define PNLWDBEMODDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeModDetailDo PnlWdbeModDetail::VecVDo

#define ContIacWdbeModDetail PnlWdbeModDetail::ContIac
#define ContInfWdbeModDetail PnlWdbeModDetail::ContInf
#define StatAppWdbeModDetail PnlWdbeModDetail::StatApp
#define StatShrWdbeModDetail PnlWdbeModDetail::StatShr
#define TagWdbeModDetail PnlWdbeModDetail::Tag

#define DpchAppWdbeModDetailData PnlWdbeModDetail::DpchAppData
#define DpchAppWdbeModDetailDo PnlWdbeModDetail::DpchAppDo
#define DpchEngWdbeModDetailData PnlWdbeModDetail::DpchEngData

/**
	* PnlWdbeModDetail
	*/
namespace PnlWdbeModDetail {
	/**
		* VecVDo (full: VecVWdbeModDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTHKUVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTTPLVIEWCLICK = 4;
		static const Sbecore::uint BUTCTRNEWCLICK = 5;
		static const Sbecore::uint BUTCTRDELETECLICK = 6;
		static const Sbecore::uint BUTCTRFWDVIEWCLICK = 7;
		static const Sbecore::uint BUTCTRCLRVIEWCLICK = 8;
		static const Sbecore::uint BUTIMBNEWCLICK = 9;
		static const Sbecore::uint BUTIMBDELETECLICK = 10;
		static const Sbecore::uint BUTIMBCORVIEWCLICK = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPHKT = 2;
		static const Sbecore::uint TXFSRR = 3;
		static const Sbecore::uint TXFCMT = 4;
		static const Sbecore::uint TXFCTRFSR = 5;
		static const Sbecore::uint NUMFPUPIMBDIR = 6;
		static const Sbecore::uint TXFIMBPRI = 7;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const std::string& TxfSrr = "", const std::string& TxfCmt = "", const std::string& TxfCtrFsr = "", const Sbecore::uint numFPupImbDir = 1, const std::string& TxfImbPri = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		std::string TxfSrr;
		std::string TxfCmt;
		std::string TxfCtrFsr;
		Sbecore::uint numFPupImbDir;
		std::string TxfImbPri;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeModDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHKU = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTPL = 4;
		static const Sbecore::uint TXTCTRFWD = 5;
		static const Sbecore::uint TXTCTRCLR = 6;
		static const Sbecore::uint TXTIMBSRF = 7;
		static const Sbecore::uint TXTIMBCOR = 8;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHku = "", const std::string& TxtSup = "", const std::string& TxtTpl = "", const std::string& TxtCtrFwd = "", const std::string& TxtCtrClr = "", const std::string& TxtImbSrf = "", const std::string& TxtImbCor = "");

	public:
		std::string TxtSrf;
		std::string TxtHku;
		std::string TxtSup;
		std::string TxtTpl;
		std::string TxtCtrFwd;
		std::string TxtCtrClr;
		std::string TxtImbSrf;
		std::string TxtImbCor;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeModDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);

	public:
		Sbecore::uint ixWdbeVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeModDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTHKUACTIVE = 5;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 6;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 7;
		static const Sbecore::uint TXTSUPACTIVE = 8;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 9;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 10;
		static const Sbecore::uint TXTTPLACTIVE = 11;
		static const Sbecore::uint BUTTPLVIEWAVAIL = 12;
		static const Sbecore::uint BUTTPLVIEWACTIVE = 13;
		static const Sbecore::uint TXFSRRACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;
		static const Sbecore::uint SEPCTRAVAIL = 16;
		static const Sbecore::uint HDGCTRAVAIL = 17;
		static const Sbecore::uint BUTCTRNEWAVAIL = 18;
		static const Sbecore::uint BUTCTRDELETEAVAIL = 19;
		static const Sbecore::uint TXFCTRFSRAVAIL = 20;
		static const Sbecore::uint TXFCTRFSRACTIVE = 21;
		static const Sbecore::uint TXTCTRFWDAVAIL = 22;
		static const Sbecore::uint TXTCTRFWDACTIVE = 23;
		static const Sbecore::uint BUTCTRFWDVIEWAVAIL = 24;
		static const Sbecore::uint BUTCTRFWDVIEWACTIVE = 25;
		static const Sbecore::uint TXTCTRCLRAVAIL = 26;
		static const Sbecore::uint TXTCTRCLRACTIVE = 27;
		static const Sbecore::uint BUTCTRCLRVIEWAVAIL = 28;
		static const Sbecore::uint BUTCTRCLRVIEWACTIVE = 29;
		static const Sbecore::uint SEPIMBAVAIL = 30;
		static const Sbecore::uint HDGIMBAVAIL = 31;
		static const Sbecore::uint BUTIMBNEWAVAIL = 32;
		static const Sbecore::uint BUTIMBDELETEAVAIL = 33;
		static const Sbecore::uint TXTIMBSRFAVAIL = 34;
		static const Sbecore::uint TXTIMBSRFACTIVE = 35;
		static const Sbecore::uint TXTIMBCORAVAIL = 36;
		static const Sbecore::uint TXTIMBCORACTIVE = 37;
		static const Sbecore::uint BUTIMBCORVIEWAVAIL = 38;
		static const Sbecore::uint BUTIMBCORVIEWACTIVE = 39;
		static const Sbecore::uint PUPIMBDIRAVAIL = 40;
		static const Sbecore::uint PUPIMBDIRACTIVE = 41;
		static const Sbecore::uint TXFIMBPRIAVAIL = 42;
		static const Sbecore::uint TXFIMBPRIACTIVE = 43;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTplActive = true, const bool ButTplViewAvail = true, const bool ButTplViewActive = true, const bool TxfSrrActive = true, const bool TxfCmtActive = true, const bool SepCtrAvail = true, const bool HdgCtrAvail = true, const bool ButCtrNewAvail = true, const bool ButCtrDeleteAvail = true, const bool TxfCtrFsrAvail = true, const bool TxfCtrFsrActive = true, const bool TxtCtrFwdAvail = true, const bool TxtCtrFwdActive = true, const bool ButCtrFwdViewAvail = true, const bool ButCtrFwdViewActive = true, const bool TxtCtrClrAvail = true, const bool TxtCtrClrActive = true, const bool ButCtrClrViewAvail = true, const bool ButCtrClrViewActive = true, const bool SepImbAvail = true, const bool HdgImbAvail = true, const bool ButImbNewAvail = true, const bool ButImbDeleteAvail = true, const bool TxtImbSrfAvail = true, const bool TxtImbSrfActive = true, const bool TxtImbCorAvail = true, const bool TxtImbCorActive = true, const bool ButImbCorViewAvail = true, const bool ButImbCorViewActive = true, const bool PupImbDirAvail = true, const bool PupImbDirActive = true, const bool TxfImbPriAvail = true, const bool TxfImbPriActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTplActive;
		bool ButTplViewAvail;
		bool ButTplViewActive;
		bool TxfSrrActive;
		bool TxfCmtActive;
		bool SepCtrAvail;
		bool HdgCtrAvail;
		bool ButCtrNewAvail;
		bool ButCtrDeleteAvail;
		bool TxfCtrFsrAvail;
		bool TxfCtrFsrActive;
		bool TxtCtrFwdAvail;
		bool TxtCtrFwdActive;
		bool ButCtrFwdViewAvail;
		bool ButCtrFwdViewActive;
		bool TxtCtrClrAvail;
		bool TxtCtrClrActive;
		bool ButCtrClrViewAvail;
		bool ButCtrClrViewActive;
		bool SepImbAvail;
		bool HdgImbAvail;
		bool ButImbNewAvail;
		bool ButImbDeleteAvail;
		bool TxtImbSrfAvail;
		bool TxtImbSrfActive;
		bool TxtImbCorAvail;
		bool TxtImbCorActive;
		bool ButImbCorViewAvail;
		bool ButImbCorViewActive;
		bool PupImbDirAvail;
		bool PupImbDirActive;
		bool TxfImbPriAvail;
		bool TxfImbPriActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeModDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTHKU = 4;
		static const Sbecore::uint CPTSUP = 5;
		static const Sbecore::uint CPTTPL = 6;
		static const Sbecore::uint CPTSRR = 7;
		static const Sbecore::uint CPTCMT = 8;
		static const Sbecore::uint HDGCTR = 9;
		static const Sbecore::uint CPTCTRFSR = 10;
		static const Sbecore::uint CPTCTRFWD = 11;
		static const Sbecore::uint CPTCTRCLR = 12;
		static const Sbecore::uint HDGIMB = 13;
		static const Sbecore::uint CPTIMBSRF = 14;
		static const Sbecore::uint CPTIMBCOR = 15;
		static const Sbecore::uint CPTIMBDIR = 16;
		static const Sbecore::uint CPTIMBPRI = 17;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptHku = "", const std::string& CptSup = "", const std::string& CptTpl = "", const std::string& CptSrr = "", const std::string& CptCmt = "", const std::string& HdgCtr = "", const std::string& CptCtrFsr = "", const std::string& CptCtrFwd = "", const std::string& CptCtrClr = "", const std::string& HdgImb = "", const std::string& CptImbSrf = "", const std::string& CptImbCor = "", const std::string& CptImbDir = "", const std::string& CptImbPri = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptHku;
		std::string CptSup;
		std::string CptTpl;
		std::string CptSrr;
		std::string CptCmt;
		std::string HdgCtr;
		std::string CptCtrFsr;
		std::string CptCtrFwd;
		std::string CptCtrClr;
		std::string HdgImb;
		std::string CptImbSrf;
		std::string CptImbCor;
		std::string CptImbDir;
		std::string CptImbPri;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeModDetailData)
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
		* DpchAppDo (full: DpchAppWdbeModDetailDo)
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
		* DpchEngData (full: DpchEngWdbeModDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPHKT = 4;
		static const Sbecore::uint FEEDFPUPIMBDIR = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupHkt;
		Sbecore::Xmlio::Feed feedFPupImbDir;
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

