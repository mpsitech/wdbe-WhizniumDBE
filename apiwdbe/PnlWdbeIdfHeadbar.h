/**
	* \file PnlWdbeIdfHeadbar.h
	* API code for job PnlWdbeIdfHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Aug 2025
	*/
// IP header --- ABOVE

#ifndef PNLWDBEIDFHEADBAR_H
#define PNLWDBEIDFHEADBAR_H

#include "ApiWdbe_blks.h"

#define StgInfWdbeIdfHeadbar PnlWdbeIdfHeadbar::StgInf
#define TagWdbeIdfHeadbar PnlWdbeIdfHeadbar::Tag

#define DpchEngWdbeIdfHeadbarData PnlWdbeIdfHeadbar::DpchEngData

/**
	* PnlWdbeIdfHeadbar
	*/
namespace PnlWdbeIdfHeadbar {
	/**
	  * StgInf (full: StgInfWdbeIdfHeadbar)
	  */
	class StgInf : public Sbecore::Block {

	public:
		static const Sbecore::uint MENAPPCPTWIDTH = 1;
		static const Sbecore::uint MENAPPWIDTH = 2;

	public:
		StgInf(const Sbecore::uint MenAppCptwidth = 100, const Sbecore::uint MenAppWidth = 100);

	public:
		Sbecore::uint MenAppCptwidth;
		Sbecore::uint MenAppWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StgInf* comp);
		std::set<Sbecore::uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagWdbeIdfHeadbar)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MENAPP = 1;

	public:
		Tag(const std::string& MenApp = "");

	public:
		std::string MenApp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeIdfHeadbarData)
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
