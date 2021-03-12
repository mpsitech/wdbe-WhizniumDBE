/**
	* \file DlgWdbeCprNew.h
	* API code for job DlgWdbeCprNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBECPRNEW_H
#define DLGWDBECPRNEW_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeCprNewDo DlgWdbeCprNew::VecVDo
#define VecVDlgWdbeCprNewSge DlgWdbeCprNew::VecVSge

#define ContIacDlgWdbeCprNew DlgWdbeCprNew::ContIac
#define ContInfDlgWdbeCprNew DlgWdbeCprNew::ContInf
#define StatAppDlgWdbeCprNew DlgWdbeCprNew::StatApp
#define StatShrDlgWdbeCprNew DlgWdbeCprNew::StatShr
#define TagDlgWdbeCprNew DlgWdbeCprNew::Tag

#define DpchAppDlgWdbeCprNewData DlgWdbeCprNew::DpchAppData
#define DpchAppDlgWdbeCprNewDo DlgWdbeCprNew::DpchAppDo
#define DpchEngDlgWdbeCprNewData DlgWdbeCprNew::DpchEngData

/**
	* DlgWdbeCprNew
	*/
namespace DlgWdbeCprNew {
	/**
		* VecVDo (full: VecVDlgWdbeCprNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeCprNewSge)
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
	  * ContIac (full: ContIacDlgWdbeCprNew)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDETPUPTYP = 1;
		static const Sbecore::uint DETTXFSRF = 2;
		static const Sbecore::uint DETTXFTIT = 3;

	public:
		ContIac(const Sbecore::uint numFDetPupTyp = 1, const std::string& DetTxfSrf = "", const std::string& DetTxfTit = "");

	public:
		Sbecore::uint numFDetPupTyp;
		std::string DetTxfSrf;
		std::string DetTxfTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeCprNew)
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
	  * StatApp (full: StatAppDlgWdbeCprNew)
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
	  * StatShr (full: StatShrDlgWdbeCprNew)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeCprNew)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTTYP = 2;
		static const Sbecore::uint DETCPTSRF = 3;
		static const Sbecore::uint DETCPTTIT = 4;
		static const Sbecore::uint BUTCNC = 5;
		static const Sbecore::uint BUTCRE = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptTyp = "", const std::string& DetCptSrf = "", const std::string& DetCptTit = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptTyp;
		std::string DetCptSrf;
		std::string DetCptTit;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeCprNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbeCprNewDo)
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
		* DpchEngData (full: DpchEngDlgWdbeCprNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPTYP = 4;
		static const Sbecore::uint FEEDFSGE = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFDetPupTyp;
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
