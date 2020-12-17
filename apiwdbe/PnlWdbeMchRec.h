/**
	* \file PnlWdbeMchRec.h
	* API code for job PnlWdbeMchRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMCHREC_H
#define PNLWDBEMCHREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeMchRecDo PnlWdbeMchRec::VecVDo

#define ContInfWdbeMchRec PnlWdbeMchRec::ContInf
#define StatAppWdbeMchRec PnlWdbeMchRec::StatApp
#define StatShrWdbeMchRec PnlWdbeMchRec::StatShr
#define TagWdbeMchRec PnlWdbeMchRec::Tag

#define DpchAppWdbeMchRecDo PnlWdbeMchRec::DpchAppDo
#define DpchEngWdbeMchRecData PnlWdbeMchRec::DpchEngData

/**
	* PnlWdbeMchRec
	*/
namespace PnlWdbeMchRec {
	/**
		* VecVDo (full: VecVWdbeMchRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeMchRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeMchRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAMAKEFILE = 2;
		static const Sbecore::uint INITDONEAPAR = 3;
		static const Sbecore::uint INITDONE1NRELEASE = 4;
		static const Sbecore::uint INITDONESUP1NMACHINE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAMakefile = false, const bool initdoneAPar = false, const bool initdone1NRelease = false, const bool initdoneSup1NMachine = false);

	public:
		bool initdoneDetail;
		bool initdoneAMakefile;
		bool initdoneAPar;
		bool initdone1NRelease;
		bool initdoneSup1NMachine;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeMchRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAMAKEFILE = 3;
		static const Sbecore::uint SCRJREFAPAR = 4;
		static const Sbecore::uint SCRJREF1NRELEASE = 5;
		static const Sbecore::uint SCRJREFSUP1NMACHINE = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAMakefile = "", const std::string& scrJrefAPar = "", const std::string& scrJref1NRelease = "", const std::string& scrJrefSup1NMachine = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAMakefile;
		std::string scrJrefAPar;
		std::string scrJref1NRelease;
		std::string scrJrefSup1NMachine;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeMchRec)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;

	public:
		Tag(const std::string& Cpt = "");

	public:
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeMchRecDo)
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
		* DpchEngData (full: DpchEngWdbeMchRecData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
