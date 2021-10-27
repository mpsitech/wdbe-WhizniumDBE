/**
	* \file DlgWdbeVerGenfst.h
	* API code for job DlgWdbeVerGenfst (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERGENFST_H
#define DLGWDBEVERGENFST_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeVerGenfstDo DlgWdbeVerGenfst::VecVDo
#define VecVDlgWdbeVerGenfstSge DlgWdbeVerGenfst::VecVSge

#define ContInfDlgWdbeVerGenfst DlgWdbeVerGenfst::ContInf
#define StatAppDlgWdbeVerGenfst DlgWdbeVerGenfst::StatApp
#define StatShrDlgWdbeVerGenfst DlgWdbeVerGenfst::StatShr
#define TagDlgWdbeVerGenfst DlgWdbeVerGenfst::Tag

#define DpchAppDlgWdbeVerGenfstDo DlgWdbeVerGenfst::DpchAppDo
#define DpchEngDlgWdbeVerGenfstData DlgWdbeVerGenfst::DpchEngData

/**
	* DlgWdbeVerGenfst
	*/
namespace DlgWdbeVerGenfst {
	/**
		* VecVDo (full: VecVDlgWdbeVerGenfstDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint GFSBUTRUNCLICK = 1;
		static const Sbecore::uint GFSBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerGenfstSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint GENFST = 2;
		static const Sbecore::uint GENMTP = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerGenfst)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint GFSTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& GfsTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string GfsTxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeVerGenfst)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;

	public:
		StatApp(const std::string& shortMenu = "");

	public:
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWdbeVerGenfst)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint GFSBUTRUNACTIVE = 1;
		static const Sbecore::uint GFSBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool GfsButRunActive = true, const bool GfsButStoActive = true, const bool ButDneActive = true);

	public:
		bool GfsButRunActive;
		bool GfsButStoActive;
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeVerGenfst)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint GFSCPTPRG = 2;
		static const Sbecore::uint GFSBUTRUN = 3;
		static const Sbecore::uint GFSBUTSTO = 4;
		static const Sbecore::uint BUTDNE = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& GfsCptPrg = "", const std::string& GfsButRun = "", const std::string& GfsButSto = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string GfsCptPrg;
		std::string GfsButRun;
		std::string GfsButSto;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeVerGenfstDo)
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
		* DpchEngData (full: DpchEngDlgWdbeVerGenfstData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
