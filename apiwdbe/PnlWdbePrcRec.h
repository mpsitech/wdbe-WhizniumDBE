/**
	* \file PnlWdbePrcRec.h
	* API code for job PnlWdbePrcRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRCREC_H
#define PNLWDBEPRCREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbePrcRecDo PnlWdbePrcRec::VecVDo

#define ContInfWdbePrcRec PnlWdbePrcRec::ContInf
#define StatAppWdbePrcRec PnlWdbePrcRec::StatApp
#define StatShrWdbePrcRec PnlWdbePrcRec::StatShr
#define TagWdbePrcRec PnlWdbePrcRec::Tag

#define DpchAppWdbePrcRecDo PnlWdbePrcRec::DpchAppDo
#define DpchEngWdbePrcRecData PnlWdbePrcRec::DpchEngData

/**
	* PnlWdbePrcRec
	*/
namespace PnlWdbePrcRec {
	/**
		* VecVDo (full: VecVWdbePrcRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbePrcRec)
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
	  * StatApp (full: StatAppWdbePrcRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEKHDLTYPE = 2;
		static const Sbecore::uint INITDONEPRC1NVARIABLE = 3;
		static const Sbecore::uint INITDONEMGE1NSIGNAL = 4;
		static const Sbecore::uint INITDONEFSMFSM1NFSMSTATE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdonePrc1NVariable = false, const bool initdoneMge1NSignal = false, const bool initdoneFsmFsm1NFsmstate = false);

	public:
		bool initdoneDetail;
		bool initdoneKHdltype;
		bool initdonePrc1NVariable;
		bool initdoneMge1NSignal;
		bool initdoneFsmFsm1NFsmstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePrcRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFKHDLTYPE = 3;
		static const Sbecore::uint SCRJREFPRC1NVARIABLE = 4;
		static const Sbecore::uint SCRJREFMGE1NSIGNAL = 5;
		static const Sbecore::uint SCRJREFFSMFSM1NFSMSTATE = 6;
		static const Sbecore::uint PNLFSMFSM1NFSMSTATEAVAIL = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefKHdltype = "", const std::string& scrJrefPrc1NVariable = "", const std::string& scrJrefMge1NSignal = "", const std::string& scrJrefFsmFsm1NFsmstate = "", const bool pnlfsmfsm1nfsmstateAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefKHdltype;
		std::string scrJrefPrc1NVariable;
		std::string scrJrefMge1NSignal;
		std::string scrJrefFsmFsm1NFsmstate;
		bool pnlfsmfsm1nfsmstateAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePrcRec)
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
		* DpchAppDo (full: DpchAppWdbePrcRecDo)
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
		* DpchEngData (full: DpchEngWdbePrcRecData)
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
