/**
	* \file PnlWdbePrcKHdltype.h
	* API code for job PnlWdbePrcKHdltype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRCKHDLTYPE_H
#define PNLWDBEPRCKHDLTYPE_H

#include "ApiWdbe_blks.h"

#include "WdbeQPrcKHdltype.h"

#include "QryWdbePrcKHdltype.h"

#define VecVWdbePrcKHdltypeDo PnlWdbePrcKHdltype::VecVDo

#define ContInfWdbePrcKHdltype PnlWdbePrcKHdltype::ContInf
#define StatAppWdbePrcKHdltype PnlWdbePrcKHdltype::StatApp
#define StatShrWdbePrcKHdltype PnlWdbePrcKHdltype::StatShr
#define StgIacWdbePrcKHdltype PnlWdbePrcKHdltype::StgIac
#define TagWdbePrcKHdltype PnlWdbePrcKHdltype::Tag

#define DpchAppWdbePrcKHdltypeData PnlWdbePrcKHdltype::DpchAppData
#define DpchAppWdbePrcKHdltypeDo PnlWdbePrcKHdltype::DpchAppDo
#define DpchEngWdbePrcKHdltypeData PnlWdbePrcKHdltype::DpchEngData

/**
	* PnlWdbePrcKHdltype
	*/
namespace PnlWdbePrcKHdltype {
	/**
		* VecVDo (full: VecVWdbePrcKHdltypeDo)
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
	  * ContInf (full: ContInfWdbePrcKHdltype)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppWdbePrcKHdltype)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWdbePrcKHdltype)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUPACTIVE = 1;
		static const Sbecore::uint BUTDOWNACTIVE = 2;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 3;
		static const Sbecore::uint BUTDELETEACTIVE = 4;

	public:
		StatShr(const bool ButUpActive = true, const bool ButDownActive = true, const bool ButDuplicateActive = true, const bool ButDeleteActive = true);

	public:
		bool ButUpActive;
		bool ButDownActive;
		bool ButDuplicateActive;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWdbePrcKHdltype)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOFIXWIDTH = 1;
		static const Sbecore::uint TCOSRFWIDTH = 2;
		static const Sbecore::uint TCOAVLWIDTH = 3;
		static const Sbecore::uint TCOIMPWIDTH = 4;
		static const Sbecore::uint TCOTITWIDTH = 5;
		static const Sbecore::uint TCOCMTWIDTH = 6;

	public:
		StgIac(const Sbecore::uint TcoFixWidth = 100, const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoAvlWidth = 100, const Sbecore::uint TcoImpWidth = 100, const Sbecore::uint TcoTitWidth = 100, const Sbecore::uint TcoCmtWidth = 100);

	public:
		Sbecore::uint TcoFixWidth;
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoAvlWidth;
		Sbecore::uint TcoImpWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoCmtWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbePrcKHdltype)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOFIX = 7;
		static const Sbecore::uint TCOSRF = 8;
		static const Sbecore::uint TCOAVL = 9;
		static const Sbecore::uint TCOIMP = 10;
		static const Sbecore::uint TCOTIT = 11;
		static const Sbecore::uint TCOCMT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoFix = "", const std::string& TcoSrf = "", const std::string& TcoAvl = "", const std::string& TcoImp = "", const std::string& TcoTit = "", const std::string& TcoCmt = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoFix;
		std::string TcoSrf;
		std::string TcoAvl;
		std::string TcoImp;
		std::string TcoTit;
		std::string TcoCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrcKHdltypeData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWdbePrcKHdltype::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWdbePrcKHdltype::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePrcKHdltypeDo)
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
		* DpchEngData (full: DpchEngWdbePrcKHdltypeData)
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
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWdbeQPrcKHdltype rst;
		QryWdbePrcKHdltype::StatApp statappqry;
		QryWdbePrcKHdltype::StatShr statshrqry;
		QryWdbePrcKHdltype::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

