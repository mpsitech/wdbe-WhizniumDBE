/**
	* \file PnlWdbeVerRec.h
	* API code for job PnlWdbeVerRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEVERREC_H
#define PNLWDBEVERREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeVerRecDo PnlWdbeVerRec::VecVDo

#define ContInfWdbeVerRec PnlWdbeVerRec::ContInf
#define StatAppWdbeVerRec PnlWdbeVerRec::StatApp
#define StatShrWdbeVerRec PnlWdbeVerRec::StatShr
#define TagWdbeVerRec PnlWdbeVerRec::Tag

#define DpchAppWdbeVerRecDo PnlWdbeVerRec::DpchAppDo
#define DpchEngWdbeVerRecData PnlWdbeVerRec::DpchEngData

/**
	* PnlWdbeVerRec
	*/
namespace PnlWdbeVerRec {
	/**
		* VecVDo (full: VecVWdbeVerRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeVerRec)
	  */
	class ContInf : public Sbecore::Block {

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
	  * StatApp (full: StatAppWdbeVerRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NCOMPONENT = 2;
		static const Sbecore::uint INITDONEBVR1NVERSION = 3;
		static const Sbecore::uint INITDONEREF1NFILE = 4;
		static const Sbecore::uint INITDONE1NUNIT = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NComponent = false, const bool initdoneBvr1NVersion = false, const bool initdoneRef1NFile = false, const bool initdone1NUnit = false);

	public:
		bool initdoneDetail;
		bool initdone1NComponent;
		bool initdoneBvr1NVersion;
		bool initdoneRef1NFile;
		bool initdone1NUnit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeVerRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NCOMPONENT = 3;
		static const Sbecore::uint SCRJREFBVR1NVERSION = 4;
		static const Sbecore::uint SCRJREFREF1NFILE = 5;
		static const Sbecore::uint SCRJREF1NUNIT = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NComponent = "", const std::string& scrJrefBvr1NVersion = "", const std::string& scrJrefRef1NFile = "", const std::string& scrJref1NUnit = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NComponent;
		std::string scrJrefBvr1NVersion;
		std::string scrJrefRef1NFile;
		std::string scrJref1NUnit;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeVerRec)
	  */
	class Tag : public Sbecore::Block {

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
		* DpchAppDo (full: DpchAppWdbeVerRecDo)
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
		* DpchEngData (full: DpchEngWdbeVerRecData)
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
