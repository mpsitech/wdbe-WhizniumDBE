/**
	* \file PnlWdbeNavPre.h
	* API code for job PnlWdbeNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVPRE_H
#define PNLWDBENAVPRE_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavPreDo PnlWdbeNavPre::VecVDo

#define ContInfWdbeNavPre PnlWdbeNavPre::ContInf
#define StatShrWdbeNavPre PnlWdbeNavPre::StatShr
#define TagWdbeNavPre PnlWdbeNavPre::Tag

#define DpchAppWdbeNavPreDo PnlWdbeNavPre::DpchAppDo
#define DpchEngWdbeNavPreData PnlWdbeNavPre::DpchEngData

/**
	* PnlWdbeNavPre
	*/
namespace PnlWdbeNavPre {
	/**
		* VecVDo (full: VecVWdbeNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCVRREMOVECLICK = 1;
		static const Sbecore::uint BUTUNTREMOVECLICK = 2;
		static const Sbecore::uint BUTVERREMOVECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeNavPre)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCVR = 1;
		static const Sbecore::uint TXTUNT = 2;
		static const Sbecore::uint TXTVER = 3;

	public:
		ContInf(const std::string& TxtCvr = "", const std::string& TxtUnt = "", const std::string& TxtVer = "");

	public:
		std::string TxtCvr;
		std::string TxtUnt;
		std::string TxtVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavPre)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCVRAVAIL = 1;
		static const Sbecore::uint TXTUNTAVAIL = 2;
		static const Sbecore::uint TXTVERAVAIL = 3;

	public:
		StatShr(const bool TxtCvrAvail = true, const bool TxtUntAvail = true, const bool TxtVerAvail = true);

	public:
		bool TxtCvrAvail;
		bool TxtUntAvail;
		bool TxtVerAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavPre)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTCVR = 1;
		static const Sbecore::uint CPTUNT = 2;
		static const Sbecore::uint CPTVER = 3;

	public:
		Tag(const std::string& CptCvr = "", const std::string& CptUnt = "", const std::string& CptVer = "");

	public:
		std::string CptCvr;
		std::string CptUnt;
		std::string CptVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavPreDo)
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
		* DpchEngData (full: DpchEngWdbeNavPreData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

