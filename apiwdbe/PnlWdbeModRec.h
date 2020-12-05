/**
	* \file PnlWdbeModRec.h
	* API code for job PnlWdbeModRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMODREC_H
#define PNLWDBEMODREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeModRecDo PnlWdbeModRec::VecVDo

#define ContInfWdbeModRec PnlWdbeModRec::ContInf
#define StatAppWdbeModRec PnlWdbeModRec::StatApp
#define StatShrWdbeModRec PnlWdbeModRec::StatShr
#define TagWdbeModRec PnlWdbeModRec::Tag

#define DpchAppWdbeModRecDo PnlWdbeModRec::DpchAppDo
#define DpchEngWdbeModRecData PnlWdbeModRec::DpchEngData

/**
	* PnlWdbeModRec
	*/
namespace PnlWdbeModRec {
	/**
		* VecVDo (full: VecVWdbeModRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeModRec)
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
	  * StatApp (full: StatAppWdbeModRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEKHDLTYPE = 2;
		static const Sbecore::uint INITDONEAPAR = 3;
		static const Sbecore::uint INITDONEMDL1NGENERIC = 4;
		static const Sbecore::uint INITDONECOR1NIMBUF = 5;
		static const Sbecore::uint INITDONEMDL1NPORT = 6;
		static const Sbecore::uint INITDONE1NPROCESS = 7;
		static const Sbecore::uint INITDONEMDL1NSIGNAL = 8;
		static const Sbecore::uint INITDONE1NPERIPHERAL = 9;
		static const Sbecore::uint INITDONESUP1NMODULE = 10;
		static const Sbecore::uint INITDONEMGE1NSIGNAL = 11;
		static const Sbecore::uint INITDONECTRREF1NCOMMAND = 12;
		static const Sbecore::uint INITDONECTRHK1NVECTOR = 13;
		static const Sbecore::uint INITDONECTRREF1NERROR = 14;
		static const Sbecore::uint INITDONECTRMNCOMMAND = 15;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneMdl1NGeneric = false, const bool initdoneCor1NImbuf = false, const bool initdoneMdl1NPort = false, const bool initdone1NProcess = false, const bool initdoneMdl1NSignal = false, const bool initdone1NPeripheral = false, const bool initdoneSup1NModule = false, const bool initdoneMge1NSignal = false, const bool initdoneCtrRef1NCommand = false, const bool initdoneCtrHk1NVector = false, const bool initdoneCtrRef1NError = false, const bool initdoneCtrMNCommand = false);

	public:
		bool initdoneDetail;
		bool initdoneKHdltype;
		bool initdoneAPar;
		bool initdoneMdl1NGeneric;
		bool initdoneCor1NImbuf;
		bool initdoneMdl1NPort;
		bool initdone1NProcess;
		bool initdoneMdl1NSignal;
		bool initdone1NPeripheral;
		bool initdoneSup1NModule;
		bool initdoneMge1NSignal;
		bool initdoneCtrRef1NCommand;
		bool initdoneCtrHk1NVector;
		bool initdoneCtrRef1NError;
		bool initdoneCtrMNCommand;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeModRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFKHDLTYPE = 3;
		static const Sbecore::uint SCRJREFAPAR = 4;
		static const Sbecore::uint SCRJREFMDL1NGENERIC = 5;
		static const Sbecore::uint SCRJREFCOR1NIMBUF = 6;
		static const Sbecore::uint SCRJREFMDL1NPORT = 7;
		static const Sbecore::uint SCRJREF1NPROCESS = 8;
		static const Sbecore::uint SCRJREFMDL1NSIGNAL = 9;
		static const Sbecore::uint SCRJREF1NPERIPHERAL = 10;
		static const Sbecore::uint SCRJREFSUP1NMODULE = 11;
		static const Sbecore::uint SCRJREFMGE1NSIGNAL = 12;
		static const Sbecore::uint SCRJREFCTRREF1NCOMMAND = 13;
		static const Sbecore::uint PNLCTRREF1NCOMMANDAVAIL = 14;
		static const Sbecore::uint SCRJREFCTRHK1NVECTOR = 15;
		static const Sbecore::uint PNLCTRHK1NVECTORAVAIL = 16;
		static const Sbecore::uint SCRJREFCTRREF1NERROR = 17;
		static const Sbecore::uint PNLCTRREF1NERRORAVAIL = 18;
		static const Sbecore::uint SCRJREFCTRMNCOMMAND = 19;
		static const Sbecore::uint PNLCTRMNCOMMANDAVAIL = 20;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 21;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefKHdltype = "", const std::string& scrJrefAPar = "", const std::string& scrJrefMdl1NGeneric = "", const std::string& scrJrefCor1NImbuf = "", const std::string& scrJrefMdl1NPort = "", const std::string& scrJref1NProcess = "", const std::string& scrJrefMdl1NSignal = "", const std::string& scrJref1NPeripheral = "", const std::string& scrJrefSup1NModule = "", const std::string& scrJrefMge1NSignal = "", const std::string& scrJrefCtrRef1NCommand = "", const bool pnlctrref1ncommandAvail = false, const std::string& scrJrefCtrHk1NVector = "", const bool pnlctrhk1nvectorAvail = false, const std::string& scrJrefCtrRef1NError = "", const bool pnlctrref1nerrorAvail = false, const std::string& scrJrefCtrMNCommand = "", const bool pnlctrmncommandAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefKHdltype;
		std::string scrJrefAPar;
		std::string scrJrefMdl1NGeneric;
		std::string scrJrefCor1NImbuf;
		std::string scrJrefMdl1NPort;
		std::string scrJref1NProcess;
		std::string scrJrefMdl1NSignal;
		std::string scrJref1NPeripheral;
		std::string scrJrefSup1NModule;
		std::string scrJrefMge1NSignal;
		std::string scrJrefCtrRef1NCommand;
		bool pnlctrref1ncommandAvail;
		std::string scrJrefCtrHk1NVector;
		bool pnlctrhk1nvectorAvail;
		std::string scrJrefCtrRef1NError;
		bool pnlctrref1nerrorAvail;
		std::string scrJrefCtrMNCommand;
		bool pnlctrmncommandAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeModRec)
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
		* DpchAppDo (full: DpchAppWdbeModRecDo)
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
		* DpchEngData (full: DpchEngWdbeModRecData)
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

