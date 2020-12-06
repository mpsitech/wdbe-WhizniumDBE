/**
	* \file PnlWdbeNavAuxfct.h
	* API code for job PnlWdbeNavAuxfct (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVAUXFCT_H
#define PNLWDBENAVAUXFCT_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavAuxfctDo PnlWdbeNavAuxfct::VecVDo

#define StatAppWdbeNavAuxfct PnlWdbeNavAuxfct::StatApp
#define StatShrWdbeNavAuxfct PnlWdbeNavAuxfct::StatShr
#define TagWdbeNavAuxfct PnlWdbeNavAuxfct::Tag

#define DpchAppWdbeNavAuxfctDo PnlWdbeNavAuxfct::DpchAppDo
#define DpchEngWdbeNavAuxfctData PnlWdbeNavAuxfct::DpchEngData

/**
	* PnlWdbeNavAuxfct
	*/
namespace PnlWdbeNavAuxfct {
	/**
		* VecVDo (full: VecVWdbeNavAuxfctDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUTLNEWCRDCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatApp (full: StatAppWdbeNavAuxfct)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);

	public:
		Sbecore::uint ixWdbeVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavAuxfct)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUTLNEWCRDAVAIL = 1;

	public:
		StatShr(const bool ButUtlNewcrdAvail = true);

	public:
		bool ButUtlNewcrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavAuxfct)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTUTL = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptUtl = "");

	public:
		std::string Cpt;
		std::string CptUtl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavAuxfctDo)
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
		* DpchEngData (full: DpchEngWdbeNavAuxfctData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
