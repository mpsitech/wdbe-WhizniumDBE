/**
	* \file DlgWdbeVerCmdset.h
	* API code for job DlgWdbeVerCmdset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERCMDSET_H
#define DLGWDBEVERCMDSET_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeVerCmdsetDit DlgWdbeVerCmdset::VecVDit
#define VecVDlgWdbeVerCmdsetDo DlgWdbeVerCmdset::VecVDo
#define VecVDlgWdbeVerCmdsetDoImp DlgWdbeVerCmdset::VecVDoImp
#define VecVDlgWdbeVerCmdsetSge DlgWdbeVerCmdset::VecVSge

#define ContIacDlgWdbeVerCmdset DlgWdbeVerCmdset::ContIac
#define ContInfDlgWdbeVerCmdset DlgWdbeVerCmdset::ContInf
#define ContInfDlgWdbeVerCmdsetImp DlgWdbeVerCmdset::ContInfImp
#define ContInfDlgWdbeVerCmdsetLfi DlgWdbeVerCmdset::ContInfLfi
#define StatAppDlgWdbeVerCmdset DlgWdbeVerCmdset::StatApp
#define StatShrDlgWdbeVerCmdset DlgWdbeVerCmdset::StatShr
#define StatShrDlgWdbeVerCmdsetIfi DlgWdbeVerCmdset::StatShrIfi
#define StatShrDlgWdbeVerCmdsetImp DlgWdbeVerCmdset::StatShrImp
#define StatShrDlgWdbeVerCmdsetLfi DlgWdbeVerCmdset::StatShrLfi
#define TagDlgWdbeVerCmdset DlgWdbeVerCmdset::Tag
#define TagDlgWdbeVerCmdsetIfi DlgWdbeVerCmdset::TagIfi
#define TagDlgWdbeVerCmdsetImp DlgWdbeVerCmdset::TagImp
#define TagDlgWdbeVerCmdsetLfi DlgWdbeVerCmdset::TagLfi

#define DpchAppDlgWdbeVerCmdsetData DlgWdbeVerCmdset::DpchAppData
#define DpchAppDlgWdbeVerCmdsetDo DlgWdbeVerCmdset::DpchAppDo
#define DpchEngDlgWdbeVerCmdsetData DlgWdbeVerCmdset::DpchEngData

/**
	* DlgWdbeVerCmdset
	*/
namespace DlgWdbeVerCmdset {
	/**
		* VecVDit (full: VecVDlgWdbeVerCmdsetDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint LFI = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeVerCmdsetDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWdbeVerCmdsetDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerCmdsetSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PRSIDLE = 2;
		static const Sbecore::uint PARSE = 3;
		static const Sbecore::uint ALRWDBEPER = 4;
		static const Sbecore::uint PRSDONE = 5;
		static const Sbecore::uint IMPIDLE = 6;
		static const Sbecore::uint IMPORT = 7;
		static const Sbecore::uint ALRWDBEIER = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerCmdset)
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
	  * ContInf (full: ContInfDlgWdbeVerCmdset)
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
	  * ContInfImp (full: ContInfDlgWdbeVerCmdsetImp)
	  */
	class ContInfImp : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeVerCmdsetLfi)
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
	  * StatApp (full: StatAppDlgWdbeVerCmdset)
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
	  * StatShr (full: StatShrDlgWdbeVerCmdset)
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
	  * StatShrIfi (full: StatShrDlgWdbeVerCmdsetIfi)
	  */
	class StatShrIfi : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
	  * StatShrImp (full: StatShrDlgWdbeVerCmdsetImp)
	  */
	class StatShrImp : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWdbeVerCmdsetLfi)
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
	  * Tag (full: TagDlgWdbeVerCmdset)
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
	  * TagIfi (full: TagDlgWdbeVerCmdsetIfi)
	  */
	class TagIfi : public Sbecore::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagIfi(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagImp (full: TagDlgWdbeVerCmdsetImp)
	  */
	class TagImp : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagImp(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWdbeVerCmdsetLfi)
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
		* DpchAppData (full: DpchAppDlgWdbeVerCmdsetData)
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
		* DpchAppDo (full: DpchAppDlgWdbeVerCmdsetDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoImp = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerCmdsetData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRIFI = 10;
		static const Sbecore::uint STATSHRIMP = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGIFI = 14;
		static const Sbecore::uint TAGIMP = 15;
		static const Sbecore::uint TAGLFI = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		Tag tag;
		TagIfi tagifi;
		TagImp tagimp;
		TagLfi taglfi;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
