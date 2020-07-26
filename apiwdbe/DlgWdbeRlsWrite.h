/**
	* \file DlgWdbeRlsWrite.h
	* API code for job DlgWdbeRlsWrite (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWDBERLSWRITE_H
#define DLGWDBERLSWRITE_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeRlsWriteDit DlgWdbeRlsWrite::VecVDit
#define VecVDlgWdbeRlsWriteDo DlgWdbeRlsWrite::VecVDo
#define VecVDlgWdbeRlsWriteDoWrc DlgWdbeRlsWrite::VecVDoWrc
#define VecVDlgWdbeRlsWriteSge DlgWdbeRlsWrite::VecVSge

#define ContIacDlgWdbeRlsWrite DlgWdbeRlsWrite::ContIac
#define ContIacDlgWdbeRlsWriteDet DlgWdbeRlsWrite::ContIacDet
#define ContInfDlgWdbeRlsWrite DlgWdbeRlsWrite::ContInf
#define ContInfDlgWdbeRlsWriteFia DlgWdbeRlsWrite::ContInfFia
#define ContInfDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::ContInfLfi
#define ContInfDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::ContInfWrc
#define StatAppDlgWdbeRlsWrite DlgWdbeRlsWrite::StatApp
#define StatShrDlgWdbeRlsWrite DlgWdbeRlsWrite::StatShr
#define StatShrDlgWdbeRlsWriteCuc DlgWdbeRlsWrite::StatShrCuc
#define StatShrDlgWdbeRlsWriteFia DlgWdbeRlsWrite::StatShrFia
#define StatShrDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::StatShrLfi
#define StatShrDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::StatShrWrc
#define TagDlgWdbeRlsWrite DlgWdbeRlsWrite::Tag
#define TagDlgWdbeRlsWriteCuc DlgWdbeRlsWrite::TagCuc
#define TagDlgWdbeRlsWriteDet DlgWdbeRlsWrite::TagDet
#define TagDlgWdbeRlsWriteFia DlgWdbeRlsWrite::TagFia
#define TagDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::TagLfi
#define TagDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::TagWrc

#define DpchAppDlgWdbeRlsWriteData DlgWdbeRlsWrite::DpchAppData
#define DpchAppDlgWdbeRlsWriteDo DlgWdbeRlsWrite::DpchAppDo
#define DpchEngDlgWdbeRlsWriteData DlgWdbeRlsWrite::DpchEngData

/**
	* DlgWdbeRlsWrite
	*/
namespace DlgWdbeRlsWrite {
	/**
		* VecVDit (full: VecVDlgWdbeRlsWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint CUC = 2;
		static const Sbecore::uint WRC = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint FIA = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWdbeRlsWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint ALRMER = 3;
		static const Sbecore::uint UPKIDLE = 4;
		static const Sbecore::uint UNPACK = 5;
		static const Sbecore::uint UPKDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint FILLPLH = 9;
		static const Sbecore::uint CREATE = 10;
		static const Sbecore::uint WRITE = 11;
		static const Sbecore::uint MRG = 12;
		static const Sbecore::uint MRGFINE = 13;
		static const Sbecore::uint MRGTYPSPEC = 14;
		static const Sbecore::uint MRGTPLSPEC = 15;
		static const Sbecore::uint CLRSPEC = 16;
		static const Sbecore::uint MRGCUST = 17;
		static const Sbecore::uint PACK = 18;
		static const Sbecore::uint FAIL = 19;
		static const Sbecore::uint DONE = 20;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsWrite)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

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
	  * ContIacDet (full: ContIacDlgWdbeRlsWriteDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CHKBSO = 1;

	public:
		ContIacDet(const bool ChkBso = false);

	public:
		bool ChkBso;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsWrite)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * ContInfFia (full: ContInfDlgWdbeRlsWriteFia)
	  */
	class ContInfFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeRlsWriteLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

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
	  * ContInfWrc (full: ContInfDlgWdbeRlsWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWrc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfWrc* comp);
		std::set<Sbecore::uint> diff(const ContInfWrc* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeRlsWrite)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrDlgWdbeRlsWrite)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
	  * StatShrCuc (full: StatShrDlgWdbeRlsWriteCuc)
	  */
	class StatShrCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;

	public:
		StatShrCuc(const bool UldAvail = true, const bool UldActive = true);

	public:
		bool UldAvail;
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
	  * StatShrFia (full: StatShrDlgWdbeRlsWriteFia)
	  */
	class StatShrFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;

	public:
		StatShrFia(const bool DldAvail = true, const bool DldActive = true);

	public:
		bool DldAvail;
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWdbeRlsWriteLfi)
	  */
	class StatShrLfi : public Sbecore::Xmlio::Block {

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
	  * StatShrWrc (full: StatShrDlgWdbeRlsWriteWrc)
	  */
	class StatShrWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrWrc(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeRlsWrite)
	  */
	class Tag : public Sbecore::Xmlio::Block {

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
	  * TagCuc (full: TagDlgWdbeRlsWriteCuc)
	  */
	class TagCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagCuc(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgWdbeRlsWriteDet)
	  */
	class TagDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTBSO = 1;

	public:
		TagDet(const std::string& CptBso = "");

	public:
		std::string CptBso;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagFia (full: TagDlgWdbeRlsWriteFia)
	  */
	class TagFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagFia(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWdbeRlsWriteLfi)
	  */
	class TagLfi : public Sbecore::Xmlio::Block {

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
	  * TagWrc (full: TagDlgWdbeRlsWriteWrc)
	  */
	class TagWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTAUT = 2;
		static const Sbecore::uint BUTRUN = 3;
		static const Sbecore::uint BUTSTO = 4;

	public:
		TagWrc(const std::string& CptPrg = "", const std::string& ButAut = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButAut;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsWriteData)
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
		* DpchAppDo (full: DpchAppDlgWdbeRlsWriteDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRC = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoWrc = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWrc;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsWriteData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFFIA = 5;
		static const Sbecore::uint CONTINFLFI = 6;
		static const Sbecore::uint CONTINFWRC = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRCUC = 12;
		static const Sbecore::uint STATSHRFIA = 13;
		static const Sbecore::uint STATSHRLFI = 14;
		static const Sbecore::uint STATSHRWRC = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGCUC = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGFIA = 19;
		static const Sbecore::uint TAGLFI = 20;
		static const Sbecore::uint TAGWRC = 21;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfFia continffia;
		ContInfLfi continflfi;
		ContInfWrc continfwrc;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrLfi statshrlfi;
		StatShrWrc statshrwrc;
		Tag tag;
		TagCuc tagcuc;
		TagDet tagdet;
		TagFia tagfia;
		TagLfi taglfi;
		TagWrc tagwrc;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

