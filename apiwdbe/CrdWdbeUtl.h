/**
	* \file CrdWdbeUtl.h
	* API code for job CrdWdbeUtl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef CRDWDBEUTL_H
#define CRDWDBEUTL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeUtlDo CrdWdbeUtl::VecVDo
#define VecVWdbeUtlSge CrdWdbeUtl::VecVSge

#define ContInfWdbeUtl CrdWdbeUtl::ContInf
#define StatAppWdbeUtl CrdWdbeUtl::StatApp
#define StatShrWdbeUtl CrdWdbeUtl::StatShr
#define TagWdbeUtl CrdWdbeUtl::Tag

#define DpchAppWdbeUtlDo CrdWdbeUtl::DpchAppDo
#define DpchEngWdbeUtlData CrdWdbeUtl::DpchEngData

/**
	* CrdWdbeUtl
	*/
namespace CrdWdbeUtl {
	/**
		* VecVDo (full: VecVWdbeUtlDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDCIFCLICK = 3;
		static const Sbecore::uint MITCRDXIPCLICK = 4;
		static const Sbecore::uint MITCRDMIPCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeUtlSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeUtl)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeUtl)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;

	public:
		StatApp(const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false);

	public:
		Sbecore::uint ixWdbeVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeUtl)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGEXTRIP = 1;
		static const Sbecore::uint SCRJREFDLGIEXCONV = 2;
		static const Sbecore::uint SCRJREFDLGMRGIP = 3;
		static const Sbecore::uint SCRJREFHEADBAR = 4;

	public:
		StatShr(const std::string& scrJrefDlgextrip = "", const std::string& scrJrefDlgiexconv = "", const std::string& scrJrefDlgmrgip = "", const std::string& scrJrefHeadbar = "");

	public:
		std::string scrJrefDlgextrip;
		std::string scrJrefDlgiexconv;
		std::string scrJrefDlgmrgip;
		std::string scrJrefHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeUtl)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDCIF = 3;
		static const Sbecore::uint MITCRDXIP = 4;
		static const Sbecore::uint MITCRDMIP = 5;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdCif = "", const std::string& MitCrdXip = "", const std::string& MitCrdMip = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdCif;
		std::string MitCrdXip;
		std::string MitCrdMip;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeUtlDo)
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
		* DpchEngData (full: DpchEngWdbeUtlData)
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

