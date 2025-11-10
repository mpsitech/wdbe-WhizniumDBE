/**
	* \file PnlWdbeSilRec.h
	* API code for job PnlWdbeSilRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESILREC_H
#define PNLWDBESILREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeSilRecDo PnlWdbeSilRec::VecVDo

#define ContInfWdbeSilRec PnlWdbeSilRec::ContInf
#define StatAppWdbeSilRec PnlWdbeSilRec::StatApp
#define StatShrWdbeSilRec PnlWdbeSilRec::StatShr
#define TagWdbeSilRec PnlWdbeSilRec::Tag

#define DpchAppWdbeSilRecDo PnlWdbeSilRec::DpchAppDo
#define DpchEngWdbeSilRecData PnlWdbeSilRec::DpchEngData

/**
	* PnlWdbeSilRec
	*/
namespace PnlWdbeSilRec {
	/**
		* VecVDo (full: VecVWdbeSilRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeSilRec)
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
	  * StatApp (full: StatAppWdbeSilRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NBANK = 2;
		static const Sbecore::uint INITDONESIL1NUNIT = 3;
		static const Sbecore::uint INITDONE1NPERIPHERAL = 4;
		static const Sbecore::uint INITDONE1NINTERRUPT = 5;
		static const Sbecore::uint INITDONEREF1NCOMMAND = 6;
		static const Sbecore::uint INITDONEHK1NMODULE = 7;
		static const Sbecore::uint INITDONEHK1NVECTOR = 8;
		static const Sbecore::uint INITDONEREF1NERROR = 9;
		static const Sbecore::uint INITDONEREF1NSIGNAL = 10;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NBank = false, const bool initdoneSil1NUnit = false, const bool initdone1NPeripheral = false, const bool initdone1NInterrupt = false, const bool initdoneRef1NCommand = false, const bool initdoneHk1NModule = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NError = false, const bool initdoneRef1NSignal = false);

	public:
		bool initdoneDetail;
		bool initdone1NBank;
		bool initdoneSil1NUnit;
		bool initdone1NPeripheral;
		bool initdone1NInterrupt;
		bool initdoneRef1NCommand;
		bool initdoneHk1NModule;
		bool initdoneHk1NVector;
		bool initdoneRef1NError;
		bool initdoneRef1NSignal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeSilRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NBANK = 3;
		static const Sbecore::uint SCRJREFSIL1NUNIT = 4;
		static const Sbecore::uint SCRJREF1NPERIPHERAL = 5;
		static const Sbecore::uint SCRJREF1NINTERRUPT = 6;
		static const Sbecore::uint SCRJREFREF1NCOMMAND = 7;
		static const Sbecore::uint SCRJREFHK1NMODULE = 8;
		static const Sbecore::uint SCRJREFHK1NVECTOR = 9;
		static const Sbecore::uint SCRJREFREF1NERROR = 10;
		static const Sbecore::uint SCRJREFREF1NSIGNAL = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NBank = "", const std::string& scrJrefSil1NUnit = "", const std::string& scrJref1NPeripheral = "", const std::string& scrJref1NInterrupt = "", const std::string& scrJrefRef1NCommand = "", const std::string& scrJrefHk1NModule = "", const std::string& scrJrefHk1NVector = "", const std::string& scrJrefRef1NError = "", const std::string& scrJrefRef1NSignal = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NBank;
		std::string scrJrefSil1NUnit;
		std::string scrJref1NPeripheral;
		std::string scrJref1NInterrupt;
		std::string scrJrefRef1NCommand;
		std::string scrJrefHk1NModule;
		std::string scrJrefHk1NVector;
		std::string scrJrefRef1NError;
		std::string scrJrefRef1NSignal;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeSilRec)
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
		* DpchAppDo (full: DpchAppWdbeSilRecDo)
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
		* DpchEngData (full: DpchEngWdbeSilRecData)
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
