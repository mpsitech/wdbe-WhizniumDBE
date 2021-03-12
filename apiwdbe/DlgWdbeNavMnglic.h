/**
	* \file DlgWdbeNavMnglic.h
	* API code for job DlgWdbeNavMnglic (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBENAVMNGLIC_H
#define DLGWDBENAVMNGLIC_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeNavMnglicDo DlgWdbeNavMnglic::VecVDo
#define VecVDlgWdbeNavMnglicSge DlgWdbeNavMnglic::VecVSge

#define ContIacDlgWdbeNavMnglic DlgWdbeNavMnglic::ContIac
#define ContInfDlgWdbeNavMnglic DlgWdbeNavMnglic::ContInf
#define StatAppDlgWdbeNavMnglic DlgWdbeNavMnglic::StatApp
#define StatShrDlgWdbeNavMnglic DlgWdbeNavMnglic::StatShr
#define TagDlgWdbeNavMnglic DlgWdbeNavMnglic::Tag

#define DpchAppDlgWdbeNavMnglicData DlgWdbeNavMnglic::DpchAppData
#define DpchAppDlgWdbeNavMnglicDo DlgWdbeNavMnglic::DpchAppDo
#define DpchEngDlgWdbeNavMnglicData DlgWdbeNavMnglic::DpchEngData

/**
	* DlgWdbeNavMnglic
	*/
namespace DlgWdbeNavMnglic {
	/**
		* VecVDo (full: VecVDlgWdbeNavMnglicDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTSCNCLICK = 1;
		static const Sbecore::uint DETBUTSDCCLICK = 2;
		static const Sbecore::uint DETBUTACTCLICK = 3;
		static const Sbecore::uint BUTDNECLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeNavMnglicSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeNavMnglic)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDETPUPFIS = 1;
		static const Sbecore::uint DETCHKFIS = 2;
		static const Sbecore::uint NUMFDETLSTLCS = 3;

	public:
		ContIac(const Sbecore::uint numFDetPupFis = 1, const bool DetChkFis = false, const Sbecore::uint numFDetLstLcs = 1);

	public:
		Sbecore::uint numFDetPupFis;
		bool DetChkFis;
		Sbecore::uint numFDetLstLcs;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeNavMnglic)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSIP = 2;
		static const Sbecore::uint DETTXTSCP = 3;
		static const Sbecore::uint DETTXTLSR = 4;
		static const Sbecore::uint DETTXTLAR = 5;
		static const Sbecore::uint DETTXTLST = 6;
		static const Sbecore::uint DETTXTLEX = 7;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSip = "", const std::string& DetTxtScp = "", const std::string& DetTxtLsr = "", const std::string& DetTxtLar = "", const std::string& DetTxtLst = "", const std::string& DetTxtLex = "");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSip;
		std::string DetTxtScp;
		std::string DetTxtLsr;
		std::string DetTxtLar;
		std::string DetTxtLst;
		std::string DetTxtLex;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeNavMnglic)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;
		static const Sbecore::uint DETLSTLCSNUMFIRSTDISP = 2;

	public:
		StatApp(const std::string& shortMenu = "", const Sbecore::uint DetLstLcsNumFirstdisp = 1);

	public:
		std::string shortMenu;
		Sbecore::uint DetLstLcsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWdbeNavMnglic)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint DETBUTACTACTIVE = 1;

	public:
		StatShr(const bool DetButActActive = true);

	public:
		bool DetButActActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeNavMnglic)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETHDGSRV = 2;
		static const Sbecore::uint DETCPTSIP = 3;
		static const Sbecore::uint DETCPTSCP = 4;
		static const Sbecore::uint DETBUTSCN = 5;
		static const Sbecore::uint DETBUTSDC = 6;
		static const Sbecore::uint DETCPTFIS = 7;
		static const Sbecore::uint DETCPTLCS = 8;
		static const Sbecore::uint DETBUTACT = 9;
		static const Sbecore::uint DETHDGLIC = 10;
		static const Sbecore::uint DETCPTLSR = 11;
		static const Sbecore::uint DETCPTLAR = 12;
		static const Sbecore::uint DETCPTLST = 13;
		static const Sbecore::uint DETCPTLEX = 14;
		static const Sbecore::uint BUTDNE = 15;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetHdgSrv = "", const std::string& DetCptSip = "", const std::string& DetCptScp = "", const std::string& DetButScn = "", const std::string& DetButSdc = "", const std::string& DetCptFis = "", const std::string& DetCptLcs = "", const std::string& DetButAct = "", const std::string& DetHdgLic = "", const std::string& DetCptLsr = "", const std::string& DetCptLar = "", const std::string& DetCptLst = "", const std::string& DetCptLex = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string DetHdgSrv;
		std::string DetCptSip;
		std::string DetCptScp;
		std::string DetButScn;
		std::string DetButSdc;
		std::string DetCptFis;
		std::string DetCptLcs;
		std::string DetButAct;
		std::string DetHdgLic;
		std::string DetCptLsr;
		std::string DetCptLar;
		std::string DetCptLst;
		std::string DetCptLex;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeNavMnglicData)
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
		* DpchAppDo (full: DpchAppDlgWdbeNavMnglicDo)
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
		* DpchEngData (full: DpchEngDlgWdbeNavMnglicData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTLCS = 4;
		static const Sbecore::uint FEEDFDETPUPFIS = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFDetLstLcs;
		Sbecore::Feed feedFDetPupFis;
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
