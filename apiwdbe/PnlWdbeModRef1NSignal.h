/**
	* \file PnlWdbeModRef1NSignal.h
	* API code for job PnlWdbeModRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMODREF1NSIGNAL_H
#define PNLWDBEMODREF1NSIGNAL_H

#include "ApiWdbe_blks.h"

#include "WdbeQModRef1NSignal.h"

#include "QryWdbeModRef1NSignal.h"

#define VecVWdbeModRef1NSignalDo PnlWdbeModRef1NSignal::VecVDo

#define ContInfWdbeModRef1NSignal PnlWdbeModRef1NSignal::ContInf
#define StatAppWdbeModRef1NSignal PnlWdbeModRef1NSignal::StatApp
#define StatShrWdbeModRef1NSignal PnlWdbeModRef1NSignal::StatShr
#define StgIacWdbeModRef1NSignal PnlWdbeModRef1NSignal::StgIac
#define TagWdbeModRef1NSignal PnlWdbeModRef1NSignal::Tag

#define DpchAppWdbeModRef1NSignalData PnlWdbeModRef1NSignal::DpchAppData
#define DpchAppWdbeModRef1NSignalDo PnlWdbeModRef1NSignal::DpchAppDo
#define DpchEngWdbeModRef1NSignalData PnlWdbeModRef1NSignal::DpchEngData

/**
	* PnlWdbeModRef1NSignal
	*/
namespace PnlWdbeModRef1NSignal {
	/**
		* VecVDo (full: VecVWdbeModRef1NSignalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTVIEWCLICK = 3;
		static const Sbecore::uint BUTNEWCLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeModRef1NSignal)
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
	  * StatApp (full: StatAppWdbeModRef1NSignal)
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
	  * StatShr (full: StatShrWdbeModRef1NSignal)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTVIEWAVAIL = 5;
		static const Sbecore::uint BUTVIEWACTIVE = 6;
		static const Sbecore::uint BUTNEWAVAIL = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButNewAvail = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButViewAvail;
		bool ButViewActive;
		bool ButNewAvail;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWdbeModRef1NSignal)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeModRef1NSignal)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOREF = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoRef = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeModRef1NSignalData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWdbeModRef1NSignal::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWdbeModRef1NSignal::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeModRef1NSignalDo)
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
		* DpchEngData (full: DpchEngWdbeModRef1NSignalData)
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
		ListWdbeQModRef1NSignal rst;
		QryWdbeModRef1NSignal::StatApp statappqry;
		QryWdbeModRef1NSignal::StatShr statshrqry;
		QryWdbeModRef1NSignal::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
