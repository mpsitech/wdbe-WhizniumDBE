/**
	* \file PnlWdbeUntRec.h
	* API code for job PnlWdbeUntRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEUNTREC_H
#define PNLWDBEUNTREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeUntRecDo PnlWdbeUntRec::VecVDo

#define ContInfWdbeUntRec PnlWdbeUntRec::ContInf
#define StatAppWdbeUntRec PnlWdbeUntRec::StatApp
#define StatShrWdbeUntRec PnlWdbeUntRec::StatShr
#define TagWdbeUntRec PnlWdbeUntRec::Tag

#define DpchAppWdbeUntRecDo PnlWdbeUntRec::DpchAppDo
#define DpchEngWdbeUntRecData PnlWdbeUntRec::DpchEngData

/**
	* PnlWdbeUntRec
	*/
namespace PnlWdbeUntRec {
	/**
		* VecVDo (full: VecVWdbeUntRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeUntRec)
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
	  * StatApp (full: StatAppWdbeUntRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NBANK = 2;
		static const Sbecore::uint INITDONEFWD1NCONTROLLER = 3;
		static const Sbecore::uint INITDONE1NTARGET = 4;
		static const Sbecore::uint INITDONE1NPERIPHERAL = 5;
		static const Sbecore::uint INITDONESIL1NUNIT = 6;
		static const Sbecore::uint INITDONEREF1NCOMMAND = 7;
		static const Sbecore::uint INITDONEHK1NMODULE = 8;
		static const Sbecore::uint INITDONEHK1NVECTOR = 9;
		static const Sbecore::uint INITDONEREF1NERROR = 10;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NBank = false, const bool initdoneFwd1NController = false, const bool initdone1NTarget = false, const bool initdone1NPeripheral = false, const bool initdoneSil1NUnit = false, const bool initdoneRef1NCommand = false, const bool initdoneHk1NModule = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NError = false);

	public:
		bool initdoneDetail;
		bool initdone1NBank;
		bool initdoneFwd1NController;
		bool initdone1NTarget;
		bool initdone1NPeripheral;
		bool initdoneSil1NUnit;
		bool initdoneRef1NCommand;
		bool initdoneHk1NModule;
		bool initdoneHk1NVector;
		bool initdoneRef1NError;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeUntRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NBANK = 3;
		static const Sbecore::uint SCRJREFFWD1NCONTROLLER = 4;
		static const Sbecore::uint SCRJREF1NTARGET = 5;
		static const Sbecore::uint SCRJREF1NPERIPHERAL = 6;
		static const Sbecore::uint SCRJREFSIL1NUNIT = 7;
		static const Sbecore::uint PNLSIL1NUNITAVAIL = 8;
		static const Sbecore::uint SCRJREFREF1NCOMMAND = 9;
		static const Sbecore::uint SCRJREFHK1NMODULE = 10;
		static const Sbecore::uint SCRJREFHK1NVECTOR = 11;
		static const Sbecore::uint SCRJREFREF1NERROR = 12;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NBank = "", const std::string& scrJrefFwd1NController = "", const std::string& scrJref1NTarget = "", const std::string& scrJref1NPeripheral = "", const std::string& scrJrefSil1NUnit = "", const bool pnlsil1nunitAvail = false, const std::string& scrJrefRef1NCommand = "", const std::string& scrJrefHk1NModule = "", const std::string& scrJrefHk1NVector = "", const std::string& scrJrefRef1NError = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NBank;
		std::string scrJrefFwd1NController;
		std::string scrJref1NTarget;
		std::string scrJref1NPeripheral;
		std::string scrJrefSil1NUnit;
		bool pnlsil1nunitAvail;
		std::string scrJrefRef1NCommand;
		std::string scrJrefHk1NModule;
		std::string scrJrefHk1NVector;
		std::string scrJrefRef1NError;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeUntRec)
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
		* DpchAppDo (full: DpchAppWdbeUntRecDo)
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
		* DpchEngData (full: DpchEngWdbeUntRecData)
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

