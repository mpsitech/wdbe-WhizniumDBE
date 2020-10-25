/**
	* \file DlgWdbeUtlIexconv.h
	* API code for job DlgWdbeUtlIexconv (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef DLGWDBEUTLIEXCONV_H
#define DLGWDBEUTLIEXCONV_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeUtlIexconvDit DlgWdbeUtlIexconv::VecVDit
#define VecVDlgWdbeUtlIexconvDo DlgWdbeUtlIexconv::VecVDo
#define VecVDlgWdbeUtlIexconvDoCnv DlgWdbeUtlIexconv::VecVDoCnv
#define VecVDlgWdbeUtlIexconvSge DlgWdbeUtlIexconv::VecVSge

#define ContIacDlgWdbeUtlIexconv DlgWdbeUtlIexconv::ContIac
#define ContInfDlgWdbeUtlIexconv DlgWdbeUtlIexconv::ContInf
#define ContInfDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::ContInfCnv
#define ContInfDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::ContInfRes
#define StatAppDlgWdbeUtlIexconv DlgWdbeUtlIexconv::StatApp
#define StatShrDlgWdbeUtlIexconv DlgWdbeUtlIexconv::StatShr
#define StatShrDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::StatShrCnv
#define StatShrDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::StatShrRes
#define StatShrDlgWdbeUtlIexconvSrc DlgWdbeUtlIexconv::StatShrSrc
#define TagDlgWdbeUtlIexconv DlgWdbeUtlIexconv::Tag
#define TagDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::TagCnv
#define TagDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::TagRes
#define TagDlgWdbeUtlIexconvSrc DlgWdbeUtlIexconv::TagSrc

#define DpchAppDlgWdbeUtlIexconvData DlgWdbeUtlIexconv::DpchAppData
#define DpchAppDlgWdbeUtlIexconvDo DlgWdbeUtlIexconv::DpchAppDo
#define DpchEngDlgWdbeUtlIexconvData DlgWdbeUtlIexconv::DpchEngData

/**
	* DlgWdbeUtlIexconv
	*/
namespace DlgWdbeUtlIexconv {
	/**
		* VecVDit (full: VecVDlgWdbeUtlIexconvDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint CNV = 2;
		static const Sbecore::uint RES = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeUtlIexconvDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoCnv (full: VecVDlgWdbeUtlIexconvDoCnv)
		*/
	class VecVDoCnv {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeUtlIexconvSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint UPKIDLE = 2;
		static const Sbecore::uint UNPACK = 3;
		static const Sbecore::uint UPKDONE = 4;
		static const Sbecore::uint ULDDONE = 5;
		static const Sbecore::uint CONV = 6;
		static const Sbecore::uint PACK = 7;
		static const Sbecore::uint DONE = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeUtlIexconv)
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
	  * ContInf (full: ContInfDlgWdbeUtlIexconv)
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
	  * ContInfCnv (full: ContInfDlgWdbeUtlIexconvCnv)
	  */
	class ContInfCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfCnv(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfCnv* comp);
		std::set<Sbecore::uint> diff(const ContInfCnv* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeUtlIexconvRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfRes(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeUtlIexconv)
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
	  * StatShr (full: StatShrDlgWdbeUtlIexconv)
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
	  * StatShrCnv (full: StatShrDlgWdbeUtlIexconvCnv)
	  */
	class StatShrCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrCnv(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrCnv* comp);
		std::set<Sbecore::uint> diff(const StatShrCnv* comp);
	};

	/**
	  * StatShrRes (full: StatShrDlgWdbeUtlIexconvRes)
	  */
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrRes(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
	  * StatShrSrc (full: StatShrDlgWdbeUtlIexconvSrc)
	  */
	class StatShrSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrSrc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrSrc* comp);
		std::set<Sbecore::uint> diff(const StatShrSrc* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeUtlIexconv)
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
	  * TagCnv (full: TagDlgWdbeUtlIexconvCnv)
	  */
	class TagCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagCnv(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagRes (full: TagDlgWdbeUtlIexconvRes)
	  */
	class TagRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagRes(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagSrc (full: TagDlgWdbeUtlIexconvSrc)
	  */
	class TagSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagSrc(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeUtlIexconvData)
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
		* DpchAppDo (full: DpchAppDlgWdbeUtlIexconvDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOCNV = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoCnv = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoCnv;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUtlIexconvData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFCNV = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRCNV = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint STATSHRSRC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGCNV = 14;
		static const Sbecore::uint TAGRES = 15;
		static const Sbecore::uint TAGSRC = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfCnv continfcnv;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCnv statshrcnv;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;
		Tag tag;
		TagCnv tagcnv;
		TagRes tagres;
		TagSrc tagsrc;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

