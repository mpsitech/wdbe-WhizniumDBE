/**
	* \file CrdWdbeCvr.h
	* API code for job CrdWdbeCvr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBECVR_H
#define CRDWDBECVR_H

#include "ApiWdbe_blks.h"

#define VecVWdbeCvrDo CrdWdbeCvr::VecVDo
#define VecVWdbeCvrSge CrdWdbeCvr::VecVSge

#define ContInfWdbeCvr CrdWdbeCvr::ContInf
#define StatAppWdbeCvr CrdWdbeCvr::StatApp
#define StatShrWdbeCvr CrdWdbeCvr::StatShr
#define TagWdbeCvr CrdWdbeCvr::Tag

#define DpchAppWdbeCvrDo CrdWdbeCvr::DpchAppDo
#define DpchEngWdbeCvrData CrdWdbeCvr::DpchEngData

/**
	* CrdWdbeCvr
	*/
namespace CrdWdbeCvr {
	/**
		* VecVDo (full: VecVWdbeCvrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDIBSCLICK = 4;
		static const Sbecore::uint MITCRDIDSCLICK = 5;
		static const Sbecore::uint MITCRDWCOCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeCvrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeCvr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDCVR = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdCvr = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdCvr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeCvr)
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
	  * StatShr (full: StatShrWdbeCvr)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGBSCCD = 1;
		static const Sbecore::uint SCRJREFDLGDETCD = 2;
		static const Sbecore::uint SCRJREFDLGNEW = 3;
		static const Sbecore::uint SCRJREFDLGWRITE = 4;
		static const Sbecore::uint SCRJREFHEADBAR = 5;
		static const Sbecore::uint SCRJREFLIST = 6;
		static const Sbecore::uint SCRJREFREC = 7;
		static const Sbecore::uint MSPCRD1AVAIL = 8;
		static const Sbecore::uint MITCRDNEWAVAIL = 9;
		static const Sbecore::uint MITCRDIBSAVAIL = 10;
		static const Sbecore::uint MITCRDIBSACTIVE = 11;
		static const Sbecore::uint MITCRDIDSAVAIL = 12;
		static const Sbecore::uint MITCRDIDSACTIVE = 13;
		static const Sbecore::uint MSPCRD2AVAIL = 14;
		static const Sbecore::uint MITCRDWCOAVAIL = 15;
		static const Sbecore::uint MITCRDWCOACTIVE = 16;

	public:
		StatShr(const std::string& scrJrefDlgbsccd = "", const std::string& scrJrefDlgdetcd = "", const std::string& scrJrefDlgnew = "", const std::string& scrJrefDlgwrite = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdIbsAvail = true, const bool MitCrdIbsActive = true, const bool MitCrdIdsAvail = true, const bool MitCrdIdsActive = true, const bool MspCrd2Avail = true, const bool MitCrdWcoAvail = true, const bool MitCrdWcoActive = true);

	public:
		std::string scrJrefDlgbsccd;
		std::string scrJrefDlgdetcd;
		std::string scrJrefDlgnew;
		std::string scrJrefDlgwrite;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdIbsAvail;
		bool MitCrdIbsActive;
		bool MitCrdIdsAvail;
		bool MitCrdIdsActive;
		bool MspCrd2Avail;
		bool MitCrdWcoAvail;
		bool MitCrdWcoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeCvr)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;
		static const Sbecore::uint MITCRDIBS = 4;
		static const Sbecore::uint MITCRDIDS = 5;
		static const Sbecore::uint MITCRDWCO = 6;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "", const std::string& MitCrdIbs = "", const std::string& MitCrdIds = "", const std::string& MitCrdWco = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;
		std::string MitCrdIbs;
		std::string MitCrdIds;
		std::string MitCrdWco;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeCvrDo)
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
		* DpchEngData (full: DpchEngWdbeCvrData)
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
