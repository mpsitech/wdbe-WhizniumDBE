/**
	* \file CrdWdbeCpr.h
	* API code for job CrdWdbeCpr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBECPR_H
#define CRDWDBECPR_H

#include "ApiWdbe_blks.h"

#define VecVWdbeCprDo CrdWdbeCpr::VecVDo
#define VecVWdbeCprSge CrdWdbeCpr::VecVSge

#define ContInfWdbeCpr CrdWdbeCpr::ContInf
#define StatAppWdbeCpr CrdWdbeCpr::StatApp
#define StatShrWdbeCpr CrdWdbeCpr::StatShr
#define TagWdbeCpr CrdWdbeCpr::Tag

#define DpchAppWdbeCprDo CrdWdbeCpr::DpchAppDo
#define DpchEngWdbeCprData CrdWdbeCpr::DpchEngData

/**
	* CrdWdbeCpr
	*/
namespace CrdWdbeCpr {
	/**
		* VecVDo (full: VecVWdbeCprDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeCprSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeCpr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDCPR = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdCpr = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdCpr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeCpr)
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
	  * StatShr (full: StatShrWdbeCpr)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGNEW = 1;
		static const Sbecore::uint SCRJREFHEADBAR = 2;
		static const Sbecore::uint SCRJREFLIST = 3;
		static const Sbecore::uint SCRJREFREC = 4;
		static const Sbecore::uint MSPCRD1AVAIL = 5;
		static const Sbecore::uint MITCRDNEWAVAIL = 6;

	public:
		StatShr(const std::string& scrJrefDlgnew = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true);

	public:
		std::string scrJrefDlgnew;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeCpr)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeCprDo)
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
		* DpchEngData (full: DpchEngWdbeCprData)
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
