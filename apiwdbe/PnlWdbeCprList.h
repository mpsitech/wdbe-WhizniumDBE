/**
	* \file PnlWdbeCprList.h
	* API code for job PnlWdbeCprList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBECPRLIST_H
#define PNLWDBECPRLIST_H

#include "ApiWdbe_blks.h"

#include "WdbeQCprList.h"

#include "QryWdbeCprList.h"

#define VecVWdbeCprListDo PnlWdbeCprList::VecVDo

#define ContIacWdbeCprList PnlWdbeCprList::ContIac
#define ContInfWdbeCprList PnlWdbeCprList::ContInf
#define StatShrWdbeCprList PnlWdbeCprList::StatShr
#define StgIacWdbeCprList PnlWdbeCprList::StgIac
#define TagWdbeCprList PnlWdbeCprList::Tag

#define DpchAppWdbeCprListData PnlWdbeCprList::DpchAppData
#define DpchAppWdbeCprListDo PnlWdbeCprList::DpchAppDo
#define DpchEngWdbeCprListData PnlWdbeCprList::DpchEngData

/**
	* PnlWdbeCprList
	*/
namespace PnlWdbeCprList {
	/**
		* VecVDo (full: VecVWdbeCprListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCprList)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCprList)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTFILTERON = 1;
		static const Sbecore::uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeCprList)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWdbeCprList)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOGRPWIDTH = 1;
		static const Sbecore::uint TCOOWNWIDTH = 2;
		static const Sbecore::uint TCOSRFWIDTH = 3;
		static const Sbecore::uint TCOTITWIDTH = 4;
		static const Sbecore::uint TCOTYPWIDTH = 5;
		static const Sbecore::uint TCOCVRWIDTH = 6;
		static const Sbecore::uint TCOGRLWIDTH = 7;

	public:
		StgIac(const Sbecore::uint TcoGrpWidth = 100, const Sbecore::uint TcoOwnWidth = 100, const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoTitWidth = 250, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoCvrWidth = 100, const Sbecore::uint TcoGrlWidth = 100);

	public:
		Sbecore::uint TcoGrpWidth;
		Sbecore::uint TcoOwnWidth;
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoCvrWidth;
		Sbecore::uint TcoGrlWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeCprList)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOGRP = 7;
		static const Sbecore::uint TCOOWN = 8;
		static const Sbecore::uint TCOSRF = 9;
		static const Sbecore::uint TCOTIT = 10;
		static const Sbecore::uint TCOTYP = 11;
		static const Sbecore::uint TCOCVR = 12;
		static const Sbecore::uint TCOGRL = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoGrp = "", const std::string& TcoOwn = "", const std::string& TcoSrf = "", const std::string& TcoTit = "", const std::string& TcoTyp = "", const std::string& TcoCvr = "", const std::string& TcoGrl = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoGrp;
		std::string TcoOwn;
		std::string TcoSrf;
		std::string TcoTit;
		std::string TcoTyp;
		std::string TcoCvr;
		std::string TcoGrl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCprListData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWdbeCprList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWdbeCprList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeCprListDo)
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
		* DpchEngData (full: DpchEngWdbeCprListData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		Sbecore::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWdbeQCprList rst;
		QryWdbeCprList::StatApp statappqry;
		QryWdbeCprList::StatShr statshrqry;
		QryWdbeCprList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
