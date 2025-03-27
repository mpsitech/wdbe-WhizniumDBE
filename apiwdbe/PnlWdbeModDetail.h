/**
	* \file PnlWdbeModDetail.h
	* API code for job PnlWdbeModDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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
		static const Sbecore::uint BUTVNDEDITCLICK = 2;
		static const Sbecore::uint BUTHKUVIEWCLICK = 3;
		static const Sbecore::uint BUTSUPVIEWCLICK = 4;
		static const Sbecore::uint BUTTPLVIEWCLICK = 5;
		static const Sbecore::uint BUTIMBNEWCLICK = 6;
		static const Sbecore::uint BUTIMBDELETECLICK = 7;
		static const Sbecore::uint BUTCTRNEWCLICK = 8;
		static const Sbecore::uint BUTCTRDELETECLICK = 9;
		static const Sbecore::uint BUTCTRCLRVIEWCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPVND = 1;
		static const Sbecore::uint TXFVND = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint NUMFPUPHKT = 4;
		static const Sbecore::uint TXFSRR = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint TXFIMBFSR = 7;
		static const Sbecore::uint NUMFPUPIMBRTY = 8;
		static const Sbecore::uint TXFIMBWID = 9;
		static const Sbecore::uint TXFIMBMMX = 10;
		static const Sbecore::uint TXFIMBPRI = 11;
		static const Sbecore::uint TXFCTRFSR = 12;

	public:
		ContIac(const Sbecore::uint numFPupVnd = 1, const std::string& TxfVnd = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const std::string& TxfSrr = "", const std::string& TxfCmt = "", const std::string& TxfImbFsr = "", const Sbecore::uint numFPupImbRty = 1, const std::string& TxfImbWid = "", const std::string& TxfImbMmx = "", const std::string& TxfImbPri = "", const std::string& TxfCtrFsr = "");

	public:
		Sbecore::uint numFPupVnd;
		std::string TxfVnd;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		std::string TxfSrr;
		std::string TxfCmt;
		std::string TxfImbFsr;
		Sbecore::uint numFPupImbRty;
		std::string TxfImbWid;
		std::string TxfImbMmx;
		std::string TxfImbPri;
		std::string TxfCtrFsr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeModDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHKU = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTPL = 4;
		static const Sbecore::uint TXTCTRCLR = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHku = "", const std::string& TxtSup = "", const std::string& TxtTpl = "", const std::string& TxtCtrClr = "");

	public:
		std::string TxtSrf;
		std::string TxtHku;
		std::string TxtSup;
		std::string TxtTpl;
		std::string TxtCtrClr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeModDetail)
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
	  * StatShr (full: StatShrWdbeModDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPVNDACTIVE = 4;
		static const Sbecore::uint TXFVNDVALID = 5;
		static const Sbecore::uint BUTVNDEDITAVAIL = 6;
		static const Sbecore::uint PUPTYPACTIVE = 7;
		static const Sbecore::uint TXTHKUACTIVE = 8;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 9;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 10;
		static const Sbecore::uint TXTSUPACTIVE = 11;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 12;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 13;
		static const Sbecore::uint TXTTPLACTIVE = 14;
		static const Sbecore::uint BUTTPLVIEWAVAIL = 15;
		static const Sbecore::uint BUTTPLVIEWACTIVE = 16;
		static const Sbecore::uint TXFSRRACTIVE = 17;
		static const Sbecore::uint TXFCMTACTIVE = 18;
		static const Sbecore::uint SEPIMBAVAIL = 19;
		static const Sbecore::uint HDGIMBAVAIL = 20;
		static const Sbecore::uint BUTIMBNEWAVAIL = 21;
		static const Sbecore::uint BUTIMBDELETEAVAIL = 22;
		static const Sbecore::uint TXFIMBFSRAVAIL = 23;
		static const Sbecore::uint TXFIMBFSRACTIVE = 24;
		static const Sbecore::uint PUPIMBRTYAVAIL = 25;
		static const Sbecore::uint PUPIMBRTYACTIVE = 26;
		static const Sbecore::uint TXFIMBWIDAVAIL = 27;
		static const Sbecore::uint TXFIMBWIDACTIVE = 28;
		static const Sbecore::uint TXFIMBMMXAVAIL = 29;
		static const Sbecore::uint TXFIMBMMXACTIVE = 30;
		static const Sbecore::uint TXFIMBPRIAVAIL = 31;
		static const Sbecore::uint TXFIMBPRIACTIVE = 32;
		static const Sbecore::uint SEPCTRAVAIL = 33;
		static const Sbecore::uint HDGCTRAVAIL = 34;
		static const Sbecore::uint BUTCTRNEWAVAIL = 35;
		static const Sbecore::uint BUTCTRDELETEAVAIL = 36;
		static const Sbecore::uint TXFCTRFSRAVAIL = 37;
		static const Sbecore::uint TXFCTRFSRACTIVE = 38;
		static const Sbecore::uint TXTCTRCLRAVAIL = 39;
		static const Sbecore::uint TXTCTRCLRACTIVE = 40;
		static const Sbecore::uint BUTCTRCLRVIEWAVAIL = 41;
		static const Sbecore::uint BUTCTRCLRVIEWACTIVE = 42;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupVndActive = true, const bool TxfVndValid = false, const bool ButVndEditAvail = true, const bool PupTypActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTplActive = true, const bool ButTplViewAvail = true, const bool ButTplViewActive = true, const bool TxfSrrActive = true, const bool TxfCmtActive = true, const bool SepImbAvail = true, const bool HdgImbAvail = true, const bool ButImbNewAvail = true, const bool ButImbDeleteAvail = true, const bool TxfImbFsrAvail = true, const bool TxfImbFsrActive = true, const bool PupImbRtyAvail = true, const bool PupImbRtyActive = true, const bool TxfImbWidAvail = true, const bool TxfImbWidActive = true, const bool TxfImbMmxAvail = true, const bool TxfImbMmxActive = true, const bool TxfImbPriAvail = true, const bool TxfImbPriActive = true, const bool SepCtrAvail = true, const bool HdgCtrAvail = true, const bool ButCtrNewAvail = true, const bool ButCtrDeleteAvail = true, const bool TxfCtrFsrAvail = true, const bool TxfCtrFsrActive = true, const bool TxtCtrClrAvail = true, const bool TxtCtrClrActive = true, const bool ButCtrClrViewAvail = true, const bool ButCtrClrViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupVndActive;
		bool TxfVndValid;
		bool ButVndEditAvail;
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
		bool SepImbAvail;
		bool HdgImbAvail;
		bool ButImbNewAvail;
		bool ButImbDeleteAvail;
		bool TxfImbFsrAvail;
		bool TxfImbFsrActive;
		bool PupImbRtyAvail;
		bool PupImbRtyActive;
		bool TxfImbWidAvail;
		bool TxfImbWidActive;
		bool TxfImbMmxAvail;
		bool TxfImbMmxActive;
		bool TxfImbPriAvail;
		bool TxfImbPriActive;
		bool SepCtrAvail;
		bool HdgCtrAvail;
		bool ButCtrNewAvail;
		bool ButCtrDeleteAvail;
		bool TxfCtrFsrAvail;
		bool TxfCtrFsrActive;
		bool TxtCtrClrAvail;
		bool TxtCtrClrActive;
		bool ButCtrClrViewAvail;
		bool ButCtrClrViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeModDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTVND = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTHKU = 5;
		static const Sbecore::uint CPTSUP = 6;
		static const Sbecore::uint CPTTPL = 7;
		static const Sbecore::uint CPTSRR = 8;
		static const Sbecore::uint CPTCMT = 9;
		static const Sbecore::uint HDGIMB = 10;
		static const Sbecore::uint CPTIMBFSR = 11;
		static const Sbecore::uint CPTIMBRTY = 12;
		static const Sbecore::uint CPTIMBWID = 13;
		static const Sbecore::uint CPTIMBMMX = 14;
		static const Sbecore::uint CPTIMBPRI = 15;
		static const Sbecore::uint HDGCTR = 16;
		static const Sbecore::uint CPTCTRFSR = 17;
		static const Sbecore::uint CPTCTRCLR = 18;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptVnd = "", const std::string& CptTyp = "", const std::string& CptHku = "", const std::string& CptSup = "", const std::string& CptTpl = "", const std::string& CptSrr = "", const std::string& CptCmt = "", const std::string& HdgImb = "", const std::string& CptImbFsr = "", const std::string& CptImbRty = "", const std::string& CptImbWid = "", const std::string& CptImbMmx = "", const std::string& CptImbPri = "", const std::string& HdgCtr = "", const std::string& CptCtrFsr = "", const std::string& CptCtrClr = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptVnd;
		std::string CptTyp;
		std::string CptHku;
		std::string CptSup;
		std::string CptTpl;
		std::string CptSrr;
		std::string CptCmt;
		std::string HdgImb;
		std::string CptImbFsr;
		std::string CptImbRty;
		std::string CptImbWid;
		std::string CptImbMmx;
		std::string CptImbPri;
		std::string HdgCtr;
		std::string CptCtrFsr;
		std::string CptCtrClr;

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
		static const Sbecore::uint FEEDFPUPIMBRTY = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint FEEDFPUPVND = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupHkt;
		Sbecore::Feed feedFPupImbRty;
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
