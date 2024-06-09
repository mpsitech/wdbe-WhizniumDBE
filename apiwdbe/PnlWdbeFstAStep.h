/**
	* \file PnlWdbeFstAStep.h
	* API code for job PnlWdbeFstAStep (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEFSTASTEP_H
#define PNLWDBEFSTASTEP_H

#include "ApiWdbe_blks.h"

#include "WdbeQFstAStep.h"

#include "QryWdbeFstAStep.h"

#define VecVWdbeFstAStepDo PnlWdbeFstAStep::VecVDo

#define ContInfWdbeFstAStep PnlWdbeFstAStep::ContInf
#define StatAppWdbeFstAStep PnlWdbeFstAStep::StatApp
#define StatShrWdbeFstAStep PnlWdbeFstAStep::StatShr
#define StgIacWdbeFstAStep PnlWdbeFstAStep::StgIac
#define TagWdbeFstAStep PnlWdbeFstAStep::Tag

#define DpchAppWdbeFstAStepData PnlWdbeFstAStep::DpchAppData
#define DpchAppWdbeFstAStepDo PnlWdbeFstAStep::DpchAppDo
#define DpchEngWdbeFstAStepData PnlWdbeFstAStep::DpchEngData

/**
	* PnlWdbeFstAStep
	*/
namespace PnlWdbeFstAStep {
	/**
		* VecVDo (full: VecVWdbeFstAStepDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDUPLICATECLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeFstAStep)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeFstAStep)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);

	public:
		Sbecore::uint ixWdbeVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeFstAStep)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTNEWAVAIL = 5;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 6;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWdbeFstAStep)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOFNXWIDTH = 1;
		static const Sbecore::uint TCOCN1WIDTH = 2;
		static const Sbecore::uint TCOIP1WIDTH = 3;
		static const Sbecore::uint TCOCN2WIDTH = 4;
		static const Sbecore::uint TCOIP2WIDTH = 5;
		static const Sbecore::uint TCOCN3WIDTH = 6;
		static const Sbecore::uint TCOIP3WIDTH = 7;
		static const Sbecore::uint TCOCN4WIDTH = 8;
		static const Sbecore::uint TCOIP4WIDTH = 9;
		static const Sbecore::uint TCOCN5WIDTH = 10;
		static const Sbecore::uint TCOIP5WIDTH = 11;
		static const Sbecore::uint TCOCN6WIDTH = 12;
		static const Sbecore::uint TCOIP6WIDTH = 13;

	public:
		StgIac(const Sbecore::uint TcoFnxWidth = 100, const Sbecore::uint TcoCn1Width = 100, const Sbecore::uint TcoIp1Width = 100, const Sbecore::uint TcoCn2Width = 100, const Sbecore::uint TcoIp2Width = 100, const Sbecore::uint TcoCn3Width = 100, const Sbecore::uint TcoIp3Width = 100, const Sbecore::uint TcoCn4Width = 100, const Sbecore::uint TcoIp4Width = 100, const Sbecore::uint TcoCn5Width = 100, const Sbecore::uint TcoIp5Width = 100, const Sbecore::uint TcoCn6Width = 100, const Sbecore::uint TcoIp6Width = 100);

	public:
		Sbecore::uint TcoFnxWidth;
		Sbecore::uint TcoCn1Width;
		Sbecore::uint TcoIp1Width;
		Sbecore::uint TcoCn2Width;
		Sbecore::uint TcoIp2Width;
		Sbecore::uint TcoCn3Width;
		Sbecore::uint TcoIp3Width;
		Sbecore::uint TcoCn4Width;
		Sbecore::uint TcoIp4Width;
		Sbecore::uint TcoCn5Width;
		Sbecore::uint TcoIp5Width;
		Sbecore::uint TcoCn6Width;
		Sbecore::uint TcoIp6Width;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeFstAStep)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOFNX = 7;
		static const Sbecore::uint TCOCN1 = 8;
		static const Sbecore::uint TCOIP1 = 9;
		static const Sbecore::uint TCOCN2 = 10;
		static const Sbecore::uint TCOIP2 = 11;
		static const Sbecore::uint TCOCN3 = 12;
		static const Sbecore::uint TCOIP3 = 13;
		static const Sbecore::uint TCOCN4 = 14;
		static const Sbecore::uint TCOIP4 = 15;
		static const Sbecore::uint TCOCN5 = 16;
		static const Sbecore::uint TCOIP5 = 17;
		static const Sbecore::uint TCOCN6 = 18;
		static const Sbecore::uint TCOIP6 = 19;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoFnx = "", const std::string& TcoCn1 = "", const std::string& TcoIp1 = "", const std::string& TcoCn2 = "", const std::string& TcoIp2 = "", const std::string& TcoCn3 = "", const std::string& TcoIp3 = "", const std::string& TcoCn4 = "", const std::string& TcoIp4 = "", const std::string& TcoCn5 = "", const std::string& TcoIp5 = "", const std::string& TcoCn6 = "", const std::string& TcoIp6 = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoFnx;
		std::string TcoCn1;
		std::string TcoIp1;
		std::string TcoCn2;
		std::string TcoIp2;
		std::string TcoCn3;
		std::string TcoIp3;
		std::string TcoCn4;
		std::string TcoIp4;
		std::string TcoCn5;
		std::string TcoIp5;
		std::string TcoCn6;
		std::string TcoIp6;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeFstAStepData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWdbeFstAStep::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWdbeFstAStep::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeFstAStepDo)
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
		* DpchEngData (full: DpchEngWdbeFstAStepData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWdbeQFstAStep rst;
		QryWdbeFstAStep::StatApp statappqry;
		QryWdbeFstAStep::StatShr statshrqry;
		QryWdbeFstAStep::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
