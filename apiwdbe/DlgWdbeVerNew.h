/**
	* \file DlgWdbeVerNew.h
	* API code for job DlgWdbeVerNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef DLGWDBEVERNEW_H
#define DLGWDBEVERNEW_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeVerNewDo DlgWdbeVerNew::VecVDo
#define VecVDlgWdbeVerNewSge DlgWdbeVerNew::VecVSge
#define VecVDlgWdbeVerNewVni DlgWdbeVerNew::VecVVni

#define ContIacDlgWdbeVerNew DlgWdbeVerNew::ContIac
#define ContInfDlgWdbeVerNew DlgWdbeVerNew::ContInf
#define StatAppDlgWdbeVerNew DlgWdbeVerNew::StatApp
#define StatShrDlgWdbeVerNew DlgWdbeVerNew::StatShr
#define TagDlgWdbeVerNew DlgWdbeVerNew::Tag

#define DpchAppDlgWdbeVerNewData DlgWdbeVerNew::DpchAppData
#define DpchAppDlgWdbeVerNewDo DlgWdbeVerNew::DpchAppDo
#define DpchEngDlgWdbeVerNewData DlgWdbeVerNew::DpchEngData

/**
	* DlgWdbeVerNew
	*/
namespace DlgWdbeVerNew {
	/**
		* VecVDo (full: VecVDlgWdbeVerNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVVni (full: VecVDlgWdbeVerNewVni)
		*/
	class VecVVni {

	public:
		static const Sbecore::uint MAJ = 1;
		static const Sbecore::uint MIN = 2;
		static const Sbecore::uint SUB = 3;
		static const Sbecore::uint VOID = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPPRJ = 1;
		static const Sbecore::uint NUMFDETPUPBVR = 2;
		static const Sbecore::uint NUMFDETRBUVNI = 3;
		static const Sbecore::uint DETTXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFDetPupPrj = 1, const Sbecore::uint numFDetPupBvr = 1, const Sbecore::uint numFDetRbuVni = 1, const std::string& DetTxfCmt = "");

	public:
		Sbecore::uint numFDetPupPrj;
		Sbecore::uint numFDetPupBvr;
		Sbecore::uint numFDetRbuVni;
		std::string DetTxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerNew)
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
	  * StatApp (full: StatAppDlgWdbeVerNew)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrDlgWdbeVerNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShr(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeVerNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTPRJ = 2;
		static const Sbecore::uint DETCPTBVR = 3;
		static const Sbecore::uint DETCPTVNI = 4;
		static const Sbecore::uint DETCPTCMT = 5;
		static const Sbecore::uint BUTCNC = 6;
		static const Sbecore::uint BUTCRE = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptPrj = "", const std::string& DetCptBvr = "", const std::string& DetCptVni = "", const std::string& DetCptCmt = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptPrj;
		std::string DetCptBvr;
		std::string DetCptVni;
		std::string DetCptCmt;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeVerNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbeVerNewDo)
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
		* DpchEngData (full: DpchEngDlgWdbeVerNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPBVR = 4;
		static const Sbecore::uint FEEDFDETPUPPRJ = 5;
		static const Sbecore::uint FEEDFDETRBUVNI = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupBvr;
		Sbecore::Xmlio::Feed feedFDetPupPrj;
		Sbecore::Xmlio::Feed feedFDetRbuVni;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

