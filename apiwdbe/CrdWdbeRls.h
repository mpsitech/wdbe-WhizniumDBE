/**
	* \file CrdWdbeRls.h
	* API code for job CrdWdbeRls (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBERLS_H
#define CRDWDBERLS_H

#include "ApiWdbe_blks.h"

#define VecVWdbeRlsDo CrdWdbeRls::VecVDo
#define VecVWdbeRlsSge CrdWdbeRls::VecVSge

#define ContInfWdbeRls CrdWdbeRls::ContInf
#define StatAppWdbeRls CrdWdbeRls::StatApp
#define StatShrWdbeRls CrdWdbeRls::StatShr
#define TagWdbeRls CrdWdbeRls::Tag

#define DpchAppWdbeRlsDo CrdWdbeRls::DpchAppDo
#define DpchEngWdbeRlsData CrdWdbeRls::DpchEngData

/**
	* CrdWdbeRls
	*/
namespace CrdWdbeRls {
	/**
		* VecVDo (full: VecVWdbeRlsDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDSRTCLICK = 3;
		static const Sbecore::uint MITCRDCRTCLICK = 4;
		static const Sbecore::uint MITCRDFRTCLICK = 5;
		static const Sbecore::uint MITCRDWCOCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeRlsSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeRls)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDRLS = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdRls = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeRls)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONELIST = 6;
		static const Sbecore::uint INITDONEREC = 7;

	public:
		StatApp(const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);

	public:
		Sbecore::uint ixWdbeVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneList;
		bool initdoneRec;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeRls)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGFINREPTR = 1;
		static const Sbecore::uint SCRJREFDLGSTAREPTR = 2;
		static const Sbecore::uint SCRJREFDLGWRITE = 3;
		static const Sbecore::uint SCRJREFHEADBAR = 4;
		static const Sbecore::uint SCRJREFLIST = 5;
		static const Sbecore::uint SCRJREFREC = 6;
		static const Sbecore::uint MSPCRD1AVAIL = 7;
		static const Sbecore::uint MITCRDSRTAVAIL = 8;
		static const Sbecore::uint MITCRDSRTACTIVE = 9;
		static const Sbecore::uint MITCRDCRTAVAIL = 10;
		static const Sbecore::uint MITCRDCRTACTIVE = 11;
		static const Sbecore::uint MITCRDFRTAVAIL = 12;
		static const Sbecore::uint MITCRDFRTACTIVE = 13;
		static const Sbecore::uint MITCRDWCOAVAIL = 14;
		static const Sbecore::uint MITCRDWCOACTIVE = 15;

	public:
		StatShr(const std::string& scrJrefDlgfinreptr = "", const std::string& scrJrefDlgstareptr = "", const std::string& scrJrefDlgwrite = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdSrtAvail = true, const bool MitCrdSrtActive = true, const bool MitCrdCrtAvail = true, const bool MitCrdCrtActive = true, const bool MitCrdFrtAvail = true, const bool MitCrdFrtActive = true, const bool MitCrdWcoAvail = true, const bool MitCrdWcoActive = true);

	public:
		std::string scrJrefDlgfinreptr;
		std::string scrJrefDlgstareptr;
		std::string scrJrefDlgwrite;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdSrtAvail;
		bool MitCrdSrtActive;
		bool MitCrdCrtAvail;
		bool MitCrdCrtActive;
		bool MitCrdFrtAvail;
		bool MitCrdFrtActive;
		bool MitCrdWcoAvail;
		bool MitCrdWcoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeRls)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDSRT = 3;
		static const Sbecore::uint MITCRDCRT = 4;
		static const Sbecore::uint MITCRDFRT = 5;
		static const Sbecore::uint MITCRDWCO = 6;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdSrt = "", const std::string& MitCrdCrt = "", const std::string& MitCrdFrt = "", const std::string& MitCrdWco = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdSrt;
		std::string MitCrdCrt;
		std::string MitCrdFrt;
		std::string MitCrdWco;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeRlsDo)
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
		* DpchEngData (full: DpchEngWdbeRlsData)
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
