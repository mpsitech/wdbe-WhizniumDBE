/**
	* \file PnlWdbeFstHeadbar.h
	* API code for job PnlWdbeFstHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEFSTHEADBAR_H
#define PNLWDBEFSTHEADBAR_H

#include "ApiWdbe_blks.h"

#define StgInfWdbeFstHeadbar PnlWdbeFstHeadbar::StgInf
#define TagWdbeFstHeadbar PnlWdbeFstHeadbar::Tag

#define DpchEngWdbeFstHeadbarData PnlWdbeFstHeadbar::DpchEngData

/**
	* PnlWdbeFstHeadbar
	*/
namespace PnlWdbeFstHeadbar {
	/**
	  * StgInf (full: StgInfWdbeFstHeadbar)
	  */
	class StgInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPPCPTWIDTH = 1;
		static const Sbecore::uint MENAPPWIDTH = 2;
		static const Sbecore::uint MENCRDCPTWIDTH = 3;
		static const Sbecore::uint MENCRDWIDTH = 4;

	public:
		StgInf(const Sbecore::uint MenAppCptwidth = 100, const Sbecore::uint MenAppWidth = 100, const Sbecore::uint MenCrdCptwidth = 100, const Sbecore::uint MenCrdWidth = 100);

	public:
		Sbecore::uint MenAppCptwidth;
		Sbecore::uint MenAppWidth;
		Sbecore::uint MenCrdCptwidth;
		Sbecore::uint MenCrdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StgInf* comp);
		std::set<Sbecore::uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagWdbeFstHeadbar)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPP = 1;
		static const Sbecore::uint MENCRD = 2;

	public:
		Tag(const std::string& MenApp = "", const std::string& MenCrd = "");

	public:
		std::string MenApp;
		std::string MenCrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeFstHeadbarData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;

	public:
		DpchEngData();

	public:
		StgInf stginf;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

