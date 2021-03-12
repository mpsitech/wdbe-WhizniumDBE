/**
	* \file DlgWdbeCvrWrite.h
	* API code for job DlgWdbeCvrWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBECVRWRITE_H
#define DLGWDBECVRWRITE_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeCvrWriteDit DlgWdbeCvrWrite::VecVDit
#define VecVDlgWdbeCvrWriteDo DlgWdbeCvrWrite::VecVDo
#define VecVDlgWdbeCvrWriteDoWrc DlgWdbeCvrWrite::VecVDoWrc
#define VecVDlgWdbeCvrWriteSge DlgWdbeCvrWrite::VecVSge

#define ContIacDlgWdbeCvrWrite DlgWdbeCvrWrite::ContIac
#define ContInfDlgWdbeCvrWrite DlgWdbeCvrWrite::ContInf
#define ContInfDlgWdbeCvrWriteFia DlgWdbeCvrWrite::ContInfFia
#define ContInfDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::ContInfWrc
#define StatAppDlgWdbeCvrWrite DlgWdbeCvrWrite::StatApp
#define StatShrDlgWdbeCvrWrite DlgWdbeCvrWrite::StatShr
#define StatShrDlgWdbeCvrWriteCuc DlgWdbeCvrWrite::StatShrCuc
#define StatShrDlgWdbeCvrWriteFia DlgWdbeCvrWrite::StatShrFia
#define StatShrDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::StatShrWrc
#define TagDlgWdbeCvrWrite DlgWdbeCvrWrite::Tag
#define TagDlgWdbeCvrWriteCuc DlgWdbeCvrWrite::TagCuc
#define TagDlgWdbeCvrWriteFia DlgWdbeCvrWrite::TagFia
#define TagDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::TagWrc

#define DpchAppDlgWdbeCvrWriteData DlgWdbeCvrWrite::DpchAppData
#define DpchAppDlgWdbeCvrWriteDo DlgWdbeCvrWrite::DpchAppDo
#define DpchEngDlgWdbeCvrWriteData DlgWdbeCvrWrite::DpchEngData

/**
	* DlgWdbeCvrWrite
	*/
namespace DlgWdbeCvrWrite {
	/**
		* VecVDit (full: VecVDlgWdbeCvrWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint CUC = 1;
		static const Sbecore::uint WRC = 2;
		static const Sbecore::uint FIA = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeCvrWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWdbeCvrWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeCvrWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint UPKIDLE = 2;
		static const Sbecore::uint UNPACK = 3;
		static const Sbecore::uint UPKDONE = 4;
		static const Sbecore::uint CREIDLE = 5;
		static const Sbecore::uint CREATE = 6;
		static const Sbecore::uint WRITE = 7;
		static const Sbecore::uint MRG = 8;
		static const Sbecore::uint MRGCUST = 9;
		static const Sbecore::uint PACK = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeCvrWrite)
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
	  * ContInf (full: ContInfDlgWdbeCvrWrite)
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
	  * ContInfFia (full: ContInfDlgWdbeCvrWriteFia)
	  */
	class ContInfFia : public Sbecore::Block {

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
	  * ContInfWrc (full: ContInfDlgWdbeCvrWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Block {

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
	  * StatApp (full: StatAppDlgWdbeCvrWrite)
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
	  * StatShr (full: StatShrDlgWdbeCvrWrite)
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
	  * StatShrCuc (full: StatShrDlgWdbeCvrWriteCuc)
	  */
	class StatShrCuc : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrCuc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
	  * StatShrFia (full: StatShrDlgWdbeCvrWriteFia)
	  */
	class StatShrFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrWrc (full: StatShrDlgWdbeCvrWriteWrc)
	  */
	class StatShrWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWrc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeCvrWrite)
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
	  * TagCuc (full: TagDlgWdbeCvrWriteCuc)
	  */
	class TagCuc : public Sbecore::Block {

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
	  * TagFia (full: TagDlgWdbeCvrWriteFia)
	  */
	class TagFia : public Sbecore::Block {

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
	  * TagWrc (full: TagDlgWdbeCvrWriteWrc)
	  */
	class TagWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagWrc(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeCvrWriteData)
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
		* DpchAppDo (full: DpchAppDlgWdbeCvrWriteDo)
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
		* DpchEngData (full: DpchEngDlgWdbeCvrWriteData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIA = 4;
		static const Sbecore::uint CONTINFWRC = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRCUC = 10;
		static const Sbecore::uint STATSHRFIA = 11;
		static const Sbecore::uint STATSHRWRC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGCUC = 14;
		static const Sbecore::uint TAGFIA = 15;
		static const Sbecore::uint TAGWRC = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFia continffia;
		ContInfWrc continfwrc;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrWrc statshrwrc;
		Tag tag;
		TagCuc tagcuc;
		TagFia tagfia;
		TagWrc tagwrc;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
