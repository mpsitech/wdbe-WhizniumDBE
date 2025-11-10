/**
	* \file PnlWdbeMtpRec.h
	* API code for job PnlWdbeMtpRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMTPREC_H
#define PNLWDBEMTPREC_H

#include "ApiWdbe_blks.h"

#define VecVWdbeMtpRecDo PnlWdbeMtpRec::VecVDo

#define ContInfWdbeMtpRec PnlWdbeMtpRec::ContInf
#define StatAppWdbeMtpRec PnlWdbeMtpRec::StatApp
#define StatShrWdbeMtpRec PnlWdbeMtpRec::StatShr
#define TagWdbeMtpRec PnlWdbeMtpRec::Tag

#define DpchAppWdbeMtpRecDo PnlWdbeMtpRec::DpchAppDo
#define DpchEngWdbeMtpRecData PnlWdbeMtpRec::DpchEngData

/**
	* PnlWdbeMtpRec
	*/
namespace PnlWdbeMtpRec {
	/**
		* VecVDo (full: VecVWdbeMtpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeMtpRec)
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
	  * StatApp (full: StatAppWdbeMtpRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEKPARKEY = 2;
		static const Sbecore::uint INITDONEKHDLTYPE = 3;
		static const Sbecore::uint INITDONEAPAR = 4;
		static const Sbecore::uint INITDONEMDL1NGENERIC = 5;
		static const Sbecore::uint INITDONETPL1NMODULE = 6;
		static const Sbecore::uint INITDONEMDL1NPORT = 7;
		static const Sbecore::uint INITDONEHSM1NPIPELINE = 8;
		static const Sbecore::uint INITDONESUP1NMODULE = 9;
		static const Sbecore::uint INITDONEREF1NFILE = 10;
		static const Sbecore::uint INITDONEMGE1NSIGNAL = 11;
		static const Sbecore::uint INITDONEREF1NVARIABLE = 12;
		static const Sbecore::uint INITDONEREF1NSENSITIVITY = 13;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKHdltype = false, const bool initdoneAPar = false, const bool initdoneMdl1NGeneric = false, const bool initdoneTpl1NModule = false, const bool initdoneMdl1NPort = false, const bool initdoneHsm1NPipeline = false, const bool initdoneSup1NModule = false, const bool initdoneRef1NFile = false, const bool initdoneMge1NSignal = false, const bool initdoneRef1NVariable = false, const bool initdoneRef1NSensitivity = false);

	public:
		bool initdoneDetail;
		bool initdoneKParKey;
		bool initdoneKHdltype;
		bool initdoneAPar;
		bool initdoneMdl1NGeneric;
		bool initdoneTpl1NModule;
		bool initdoneMdl1NPort;
		bool initdoneHsm1NPipeline;
		bool initdoneSup1NModule;
		bool initdoneRef1NFile;
		bool initdoneMge1NSignal;
		bool initdoneRef1NVariable;
		bool initdoneRef1NSensitivity;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeMtpRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFKPARKEY = 3;
		static const Sbecore::uint SCRJREFKHDLTYPE = 4;
		static const Sbecore::uint SCRJREFAPAR = 5;
		static const Sbecore::uint SCRJREFMDL1NGENERIC = 6;
		static const Sbecore::uint SCRJREFTPL1NMODULE = 7;
		static const Sbecore::uint SCRJREFMDL1NPORT = 8;
		static const Sbecore::uint SCRJREFHSM1NPIPELINE = 9;
		static const Sbecore::uint SCRJREFSUP1NMODULE = 10;
		static const Sbecore::uint SCRJREFREF1NFILE = 11;
		static const Sbecore::uint SCRJREFMGE1NSIGNAL = 12;
		static const Sbecore::uint SCRJREFREF1NVARIABLE = 13;
		static const Sbecore::uint SCRJREFREF1NSENSITIVITY = 14;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefKParKey = "", const std::string& scrJrefKHdltype = "", const std::string& scrJrefAPar = "", const std::string& scrJrefMdl1NGeneric = "", const std::string& scrJrefTpl1NModule = "", const std::string& scrJrefMdl1NPort = "", const std::string& scrJrefHsm1NPipeline = "", const std::string& scrJrefSup1NModule = "", const std::string& scrJrefRef1NFile = "", const std::string& scrJrefMge1NSignal = "", const std::string& scrJrefRef1NVariable = "", const std::string& scrJrefRef1NSensitivity = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefKParKey;
		std::string scrJrefKHdltype;
		std::string scrJrefAPar;
		std::string scrJrefMdl1NGeneric;
		std::string scrJrefTpl1NModule;
		std::string scrJrefMdl1NPort;
		std::string scrJrefHsm1NPipeline;
		std::string scrJrefSup1NModule;
		std::string scrJrefRef1NFile;
		std::string scrJrefMge1NSignal;
		std::string scrJrefRef1NVariable;
		std::string scrJrefRef1NSensitivity;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeMtpRec)
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
		* DpchAppDo (full: DpchAppWdbeMtpRecDo)
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
		* DpchEngData (full: DpchEngWdbeMtpRecData)
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
