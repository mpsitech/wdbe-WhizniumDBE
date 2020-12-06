/**
	* \file DlgWdbePrjNew.h
	* API code for job DlgWdbePrjNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEPRJNEW_H
#define DLGWDBEPRJNEW_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbePrjNewDo DlgWdbePrjNew::VecVDo
#define VecVDlgWdbePrjNewSge DlgWdbePrjNew::VecVSge

#define ContIacDlgWdbePrjNew DlgWdbePrjNew::ContIac
#define ContInfDlgWdbePrjNew DlgWdbePrjNew::ContInf
#define StatAppDlgWdbePrjNew DlgWdbePrjNew::StatApp
#define StatShrDlgWdbePrjNew DlgWdbePrjNew::StatShr
#define TagDlgWdbePrjNew DlgWdbePrjNew::Tag

#define DpchAppDlgWdbePrjNewData DlgWdbePrjNew::DpchAppData
#define DpchAppDlgWdbePrjNewDo DlgWdbePrjNew::DpchAppDo
#define DpchEngDlgWdbePrjNewData DlgWdbePrjNew::DpchEngData

/**
	* DlgWdbePrjNew
	*/
namespace DlgWdbePrjNew {
	/**
		* VecVDo (full: VecVDlgWdbePrjNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTAUTCLICK = 1;
		static const Sbecore::uint BUTCNCCLICK = 2;
		static const Sbecore::uint BUTCRECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbePrjNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint AUTH = 3;
		static const Sbecore::uint AUTDONE = 4;
		static const Sbecore::uint CREATE = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbePrjNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETTXFSHO = 1;
		static const Sbecore::uint DETTXFTIT = 2;

	public:
		ContIac(const std::string& DetTxfSho = "", const std::string& DetTxfTit = "");

	public:
		std::string DetTxfSho;
		std::string DetTxfTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbePrjNew)
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
	  * StatApp (full: StatAppDlgWdbePrjNew)
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
	  * StatShr (full: StatShrDlgWdbePrjNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTAUTACTIVE = 1;
		static const Sbecore::uint BUTCNCACTIVE = 2;
		static const Sbecore::uint BUTCREACTIVE = 3;

	public:
		StatShr(const bool DetButAutActive = true, const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool DetButAutActive;
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWdbePrjNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTSHO = 2;
		static const Sbecore::uint DETCPTTIT = 3;
		static const Sbecore::uint DETBUTAUT = 4;
		static const Sbecore::uint BUTCNC = 5;
		static const Sbecore::uint BUTCRE = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptSho = "", const std::string& DetCptTit = "", const std::string& DetButAut = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptSho;
		std::string DetCptTit;
		std::string DetButAut;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbePrjNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbePrjNewDo)
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
		* DpchEngData (full: DpchEngDlgWdbePrjNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFSGE = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
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
