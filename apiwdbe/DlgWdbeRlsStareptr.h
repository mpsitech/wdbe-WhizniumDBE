/**
	* \file DlgWdbeRlsStareptr.h
	* API code for job DlgWdbeRlsStareptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBERLSSTAREPTR_H
#define DLGWDBERLSSTAREPTR_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeRlsStareptrDit DlgWdbeRlsStareptr::VecVDit
#define VecVDlgWdbeRlsStareptrDo DlgWdbeRlsStareptr::VecVDo
#define VecVDlgWdbeRlsStareptrDoDet DlgWdbeRlsStareptr::VecVDoDet
#define VecVDlgWdbeRlsStareptrDoExt DlgWdbeRlsStareptr::VecVDoExt
#define VecVDlgWdbeRlsStareptrDoIni DlgWdbeRlsStareptr::VecVDoIni
#define VecVDlgWdbeRlsStareptrSge DlgWdbeRlsStareptr::VecVSge

#define ContIacDlgWdbeRlsStareptr DlgWdbeRlsStareptr::ContIac
#define ContIacDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::ContIacDet
#define ContInfDlgWdbeRlsStareptr DlgWdbeRlsStareptr::ContInf
#define ContInfDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::ContInfExt
#define ContInfDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::ContInfIni
#define ContInfDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::ContInfLfi
#define StatAppDlgWdbeRlsStareptr DlgWdbeRlsStareptr::StatApp
#define StatShrDlgWdbeRlsStareptr DlgWdbeRlsStareptr::StatShr
#define StatShrDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::StatShrDet
#define StatShrDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::StatShrExt
#define StatShrDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::StatShrIni
#define StatShrDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::StatShrLfi
#define TagDlgWdbeRlsStareptr DlgWdbeRlsStareptr::Tag
#define TagDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::TagDet
#define TagDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::TagExt
#define TagDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::TagIni
#define TagDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::TagLfi

#define DpchAppDlgWdbeRlsStareptrData DlgWdbeRlsStareptr::DpchAppData
#define DpchAppDlgWdbeRlsStareptrDo DlgWdbeRlsStareptr::DpchAppDo
#define DpchEngDlgWdbeRlsStareptrData DlgWdbeRlsStareptr::DpchEngData

/**
	* DlgWdbeRlsStareptr
	*/
namespace DlgWdbeRlsStareptr {
	/**
		* VecVDit (full: VecVDlgWdbeRlsStareptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint INI = 2;
		static const Sbecore::uint EXT = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsStareptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWdbeRlsStareptrDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTSTACLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoExt (full: VecVDlgWdbeRlsStareptrDoExt)
		*/
	class VecVDoExt {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoIni (full: VecVDlgWdbeRlsStareptrDoIni)
		*/
	class VecVDoIni {

	public:
		static const Sbecore::uint BUTCLGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsStareptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint ALRGVE = 4;
		static const Sbecore::uint ALRXER = 5;
		static const Sbecore::uint STADONE = 6;
		static const Sbecore::uint UPKIDLE = 7;
		static const Sbecore::uint UNPACK = 8;
		static const Sbecore::uint UPKDONE = 9;
		static const Sbecore::uint CLGIDLE = 10;
		static const Sbecore::uint CLONEGIT = 11;
		static const Sbecore::uint CLGDONE = 12;
		static const Sbecore::uint EXTRACT = 13;
		static const Sbecore::uint PACK = 14;
		static const Sbecore::uint FAIL = 15;
		static const Sbecore::uint DONE = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsStareptr)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgWdbeRlsStareptrDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUBRT = 1;
		static const Sbecore::uint TXFGRL = 2;

	public:
		ContIacDet(const Sbecore::uint numFRbuBrt = 1, const std::string& TxfGrl = "");

	public:
		Sbecore::uint numFRbuBrt;
		std::string TxfGrl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsStareptr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfExt (full: ContInfDlgWdbeRlsStareptrExt)
	  */
	class ContInfExt : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfExt(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfExt* comp);
		std::set<Sbecore::uint> diff(const ContInfExt* comp);
	};

	/**
	  * ContInfIni (full: ContInfDlgWdbeRlsStareptrIni)
	  */
	class ContInfIni : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfIni(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfIni* comp);
		std::set<Sbecore::uint> diff(const ContInfIni* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeRlsStareptrLfi)
	  */
	class ContInfLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeRlsStareptr)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONE = 1;
		static const Sbecore::uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const std::string& shortMenu = "");

	public:
		bool initdone;
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWdbeRlsStareptr)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrDet (full: StatShrDlgWdbeRlsStareptrDet)
	  */
	class StatShrDet : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFGRLAVAIL = 1;
		static const Sbecore::uint BUTSTAACTIVE = 2;

	public:
		StatShrDet(const bool TxfGrlAvail = true, const bool ButStaActive = true);

	public:
		bool TxfGrlAvail;
		bool ButStaActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
	  * StatShrExt (full: StatShrDlgWdbeRlsStareptrExt)
	  */
	class StatShrExt : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrExt(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrExt* comp);
		std::set<Sbecore::uint> diff(const StatShrExt* comp);
	};

	/**
	  * StatShrIni (full: StatShrDlgWdbeRlsStareptrIni)
	  */
	class StatShrIni : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTCLGAVAIL = 5;
		static const Sbecore::uint BUTCLGACTIVE = 6;

	public:
		StatShrIni(const bool UldAvail = true, const bool UldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButClgAvail = true, const bool ButClgActive = true);

	public:
		bool UldAvail;
		bool UldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButClgAvail;
		bool ButClgActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrIni* comp);
		std::set<Sbecore::uint> diff(const StatShrIni* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWdbeRlsStareptrLfi)
	  */
	class StatShrLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeRlsStareptr)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint BUTDNE = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgWdbeRlsStareptrDet)
	  */
	class TagDet : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTBRT = 1;
		static const Sbecore::uint CPTGRL = 2;
		static const Sbecore::uint BUTSTA = 3;

	public:
		TagDet(const std::string& CptBrt = "", const std::string& CptGrl = "", const std::string& ButSta = "");

	public:
		std::string CptBrt;
		std::string CptGrl;
		std::string ButSta;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagExt (full: TagDlgWdbeRlsStareptrExt)
	  */
	class TagExt : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagExt(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagIni (full: TagDlgWdbeRlsStareptrIni)
	  */
	class TagIni : public Sbecore::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;
		static const Sbecore::uint CPTPRG = 3;
		static const Sbecore::uint BUTCLG = 4;

	public:
		TagIni(const std::string& Uld = "", const std::string& Cpt = "", const std::string& CptPrg = "", const std::string& ButClg = "");

	public:
		std::string Uld;
		std::string Cpt;
		std::string CptPrg;
		std::string ButClg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWdbeRlsStareptrLfi)
	  */
	class TagLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagLfi(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsStareptrData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsStareptrDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;
		static const Sbecore::uint IXVDOEXT = 4;
		static const Sbecore::uint IXVDOINI = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoDet = 0, const Sbecore::uint ixVDoExt = 0, const Sbecore::uint ixVDoIni = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;
		Sbecore::uint ixVDoExt;
		Sbecore::uint ixVDoIni;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsStareptrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFEXT = 5;
		static const Sbecore::uint CONTINFINI = 6;
		static const Sbecore::uint CONTINFLFI = 7;
		static const Sbecore::uint FEEDFDETRBUBRT = 8;
		static const Sbecore::uint FEEDFDSE = 9;
		static const Sbecore::uint FEEDFSGE = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint STATSHRDET = 13;
		static const Sbecore::uint STATSHREXT = 14;
		static const Sbecore::uint STATSHRINI = 15;
		static const Sbecore::uint STATSHRLFI = 16;
		static const Sbecore::uint TAG = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGEXT = 19;
		static const Sbecore::uint TAGINI = 20;
		static const Sbecore::uint TAGLFI = 21;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfExt continfext;
		ContInfIni continfini;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDetRbuBrt;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrExt statshrext;
		StatShrIni statshrini;
		StatShrLfi statshrlfi;
		Tag tag;
		TagDet tagdet;
		TagExt tagext;
		TagIni tagini;
		TagLfi taglfi;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
