/**
	* \file PnlWdbeCvrRec.h
	* API code for job PnlWdbeCvrRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBECVRREC_H
#define PNLWDBECVRREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeCvrRecDo PnlWdbeCvrRec::VecVDo

#define ContInfWdbeCvrRec PnlWdbeCvrRec::ContInf
#define StatAppWdbeCvrRec PnlWdbeCvrRec::StatApp
#define StatShrWdbeCvrRec PnlWdbeCvrRec::StatShr
#define TagWdbeCvrRec PnlWdbeCvrRec::Tag

#define DpchAppWdbeCvrRecDo PnlWdbeCvrRec::DpchAppDo
#define DpchEngWdbeCvrRecData PnlWdbeCvrRec::DpchEngData

/**
	* PnlWdbeCvrRec
	*/
namespace PnlWdbeCvrRec {
	/**
		* VecVDo (full: VecVWdbeCvrRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeCvrRec)
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
	  * StatApp (full: StatAppWdbeCvrRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAPLH = 2;
		static const Sbecore::uint INITDONEAIP = 3;
		static const Sbecore::uint INITDONEBCV1NCOREVERSION = 4;
		static const Sbecore::uint INITDONEHK1NMODULE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPlh = false, const bool initdoneAIp = false, const bool initdoneBcv1NCoreversion = false, const bool initdoneHk1NModule = false);

	public:
		bool initdoneDetail;
		bool initdoneAPlh;
		bool initdoneAIp;
		bool initdoneBcv1NCoreversion;
		bool initdoneHk1NModule;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeCvrRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAPLH = 3;
		static const Sbecore::uint SCRJREFAIP = 4;
		static const Sbecore::uint SCRJREFBCV1NCOREVERSION = 5;
		static const Sbecore::uint SCRJREFHK1NMODULE = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAPlh = "", const std::string& scrJrefAIp = "", const std::string& scrJrefBcv1NCoreversion = "", const std::string& scrJrefHk1NModule = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAPlh;
		std::string scrJrefAIp;
		std::string scrJrefBcv1NCoreversion;
		std::string scrJrefHk1NModule;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeCvrRec)
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
		* DpchAppDo (full: DpchAppWdbeCvrRecDo)
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
		* DpchEngData (full: DpchEngWdbeCvrRecData)
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
