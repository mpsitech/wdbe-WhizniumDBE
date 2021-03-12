/**
	* \file CrdWdbeVer.h
	* API code for job CrdWdbeVer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBEVER_H
#define CRDWDBEVER_H

#include "ApiWdbe_blks.h"

#define VecVWdbeVerDo CrdWdbeVer::VecVDo
#define VecVWdbeVerSge CrdWdbeVer::VecVSge

#define ContInfWdbeVer CrdWdbeVer::ContInf
#define StatAppWdbeVer CrdWdbeVer::StatApp
#define StatShrWdbeVer CrdWdbeVer::StatShr
#define TagWdbeVer CrdWdbeVer::Tag

#define DpchAppWdbeVerDo CrdWdbeVer::DpchAppDo
#define DpchEngWdbeVerData CrdWdbeVer::DpchEngData

/**
	* CrdWdbeVer
	*/
namespace CrdWdbeVer {
	/**
		* VecVDo (full: VecVWdbeVerDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDPCVCLICK = 4;
		static const Sbecore::uint MITCRDIBSCLICK = 5;
		static const Sbecore::uint MITCRDIDSCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeVerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;
		static const Sbecore::uint ALRCVW = 3;
		static const Sbecore::uint SETPRJCVR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeVer)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVER = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVer = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeVer)
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
	  * StatShr (full: StatShrWdbeVer)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGBSCDD = 1;
		static const Sbecore::uint SCRJREFDLGDETDD = 2;
		static const Sbecore::uint SCRJREFDLGNEW = 3;
		static const Sbecore::uint SCRJREFHEADBAR = 4;
		static const Sbecore::uint SCRJREFLIST = 5;
		static const Sbecore::uint SCRJREFREC = 6;
		static const Sbecore::uint MSPCRD1AVAIL = 7;
		static const Sbecore::uint MITCRDNEWAVAIL = 8;
		static const Sbecore::uint MITCRDPCVAVAIL = 9;
		static const Sbecore::uint MITCRDPCVACTIVE = 10;
		static const Sbecore::uint MSPCRD3AVAIL = 11;
		static const Sbecore::uint MSPCRD3ACTIVE = 12;
		static const Sbecore::uint MITCRDIBSAVAIL = 13;
		static const Sbecore::uint MITCRDIBSACTIVE = 14;
		static const Sbecore::uint MITCRDIDSAVAIL = 15;
		static const Sbecore::uint MITCRDIDSACTIVE = 16;

	public:
		StatShr(const std::string& scrJrefDlgbscdd = "", const std::string& scrJrefDlgdetdd = "", const std::string& scrJrefDlgnew = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdPcvAvail = true, const bool MitCrdPcvActive = true, const bool MspCrd3Avail = true, const bool MspCrd3Active = true, const bool MitCrdIbsAvail = true, const bool MitCrdIbsActive = true, const bool MitCrdIdsAvail = true, const bool MitCrdIdsActive = true);

	public:
		std::string scrJrefDlgbscdd;
		std::string scrJrefDlgdetdd;
		std::string scrJrefDlgnew;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdPcvAvail;
		bool MitCrdPcvActive;
		bool MspCrd3Avail;
		bool MspCrd3Active;
		bool MitCrdIbsAvail;
		bool MitCrdIbsActive;
		bool MitCrdIdsAvail;
		bool MitCrdIdsActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeVer)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;
		static const Sbecore::uint MITCRDPCV = 4;
		static const Sbecore::uint MITCRDIBS = 5;
		static const Sbecore::uint MITCRDIDS = 6;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "", const std::string& MitCrdPcv = "", const std::string& MitCrdIbs = "", const std::string& MitCrdIds = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;
		std::string MitCrdPcv;
		std::string MitCrdIbs;
		std::string MitCrdIds;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeVerDo)
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
		* DpchEngData (full: DpchEngWdbeVerData)
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
