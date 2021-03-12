/**
	* \file PnlWdbeSysRec.h
	* API code for job PnlWdbeSysRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESYSREC_H
#define PNLWDBESYSREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSysRecDo PnlWdbeSysRec::VecVDo

#define ContInfWdbeSysRec PnlWdbeSysRec::ContInf
#define StatAppWdbeSysRec PnlWdbeSysRec::StatApp
#define StatShrWdbeSysRec PnlWdbeSysRec::StatShr
#define TagWdbeSysRec PnlWdbeSysRec::Tag

#define DpchAppWdbeSysRecDo PnlWdbeSysRec::DpchAppDo
#define DpchEngWdbeSysRecData PnlWdbeSysRec::DpchEngData

/**
	* PnlWdbeSysRec
	*/
namespace PnlWdbeSysRec {
	/**
		* VecVDo (full: VecVWdbeSysRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeSysRec)
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
	  * StatApp (full: StatAppWdbeSysRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONESYS1NTARGET = 2;
		static const Sbecore::uint INITDONEHK1NVECTOR = 3;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneSys1NTarget = false, const bool initdoneHk1NVector = false);

	public:
		bool initdoneDetail;
		bool initdoneSys1NTarget;
		bool initdoneHk1NVector;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeSysRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFSYS1NTARGET = 3;
		static const Sbecore::uint SCRJREFHK1NVECTOR = 4;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefSys1NTarget = "", const std::string& scrJrefHk1NVector = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefSys1NTarget;
		std::string scrJrefHk1NVector;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSysRec)
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
		* DpchAppDo (full: DpchAppWdbeSysRecDo)
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
		* DpchEngData (full: DpchEngWdbeSysRecData)
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
