/**
	* \file PnlWdbeNavDeploy.h
	* API code for job PnlWdbeNavDeploy (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVDEPLOY_H
#define PNLWDBENAVDEPLOY_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavDeployDo PnlWdbeNavDeploy::VecVDo

#define ContIacWdbeNavDeploy PnlWdbeNavDeploy::ContIac
#define StatAppWdbeNavDeploy PnlWdbeNavDeploy::StatApp
#define StatShrWdbeNavDeploy PnlWdbeNavDeploy::StatShr
#define TagWdbeNavDeploy PnlWdbeNavDeploy::Tag

#define DpchAppWdbeNavDeployData PnlWdbeNavDeploy::DpchAppData
#define DpchAppWdbeNavDeployDo PnlWdbeNavDeploy::DpchAppDo
#define DpchEngWdbeNavDeployData PnlWdbeNavDeploy::DpchEngData

/**
	* PnlWdbeNavDeploy
	*/
namespace PnlWdbeNavDeploy {
	/**
		* VecVDo (full: VecVWdbeNavDeployDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCMPVIEWCLICK = 1;
		static const Sbecore::uint BUTCMPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRLSVIEWCLICK = 3;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDeploy)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCMP = 1;
		static const Sbecore::uint NUMFLSTRLS = 2;

	public:
		ContIac(const Sbecore::uint numFLstCmp = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstCmp;
		Sbecore::uint numFLstRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavDeploy)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCMPALT = 2;
		static const Sbecore::uint LSTRLSALT = 3;
		static const Sbecore::uint LSTCMPNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTRLSNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCmpAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstCmpNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCmpAlt;
		bool LstRlsAlt;
		Sbecore::uint LstCmpNumFirstdisp;
		Sbecore::uint LstRlsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavDeploy)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTCMPAVAIL = 1;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 2;
		static const Sbecore::uint LSTRLSAVAIL = 3;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 4;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 5;

	public:
		StatShr(const bool LstCmpAvail = true, const bool ButCmpViewActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstCmpAvail;
		bool ButCmpViewActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavDeploy)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCMP = 2;
		static const Sbecore::uint CPTRLS = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCmp = "", const std::string& CptRls = "");

	public:
		std::string Cpt;
		std::string CptCmp;
		std::string CptRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDeployData)
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
		* DpchAppDo (full: DpchAppWdbeNavDeployDo)
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
		* DpchEngData (full: DpchEngWdbeNavDeployData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMP = 3;
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCmp;
		Sbecore::Feed feedFLstRls;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
