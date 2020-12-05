/**
	* \file PnlWdbeUntList.h
	* API code for job PnlWdbeUntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEUNTLIST_H
#define PNLWDBEUNTLIST_H

#include "ApiWdbe_blks.h"

#include "WdbeQUntList.h"

#include "QryWdbeUntList.h"

#define VecVWdbeUntListDo PnlWdbeUntList::VecVDo

#define ContIacWdbeUntList PnlWdbeUntList::ContIac
#define ContInfWdbeUntList PnlWdbeUntList::ContInf
#define StatShrWdbeUntList PnlWdbeUntList::StatShr
#define StgIacWdbeUntList PnlWdbeUntList::StgIac
#define TagWdbeUntList PnlWdbeUntList::Tag

#define DpchAppWdbeUntListData PnlWdbeUntList::DpchAppData
#define DpchAppWdbeUntListDo PnlWdbeUntList::DpchAppDo
#define DpchEngWdbeUntListData PnlWdbeUntList::DpchEngData

/**
	* PnlWdbeUntList
	*/
namespace PnlWdbeUntList {
	/**
		* VecVDo (full: VecVWdbeUntListDo)
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
	  * ContIac (full: ContIacWdbeUntList)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

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
	  * ContInf (full: ContInfWdbeUntList)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTFOR = 1;
		static const Sbecore::uint TXTPRE = 2;
		static const Sbecore::uint BUTFILTERON = 3;
		static const Sbecore::uint NUMFCSIQST = 4;

	public:
		ContInf(const std::string& TxtFor = "", const std::string& TxtPre = "", const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		std::string TxtFor;
		std::string TxtPre;
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeUntList)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
	  * StgIac (full: StgIacWdbeUntList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOTITWIDTH = 2;
		static const Sbecore::uint TCOFSRWIDTH = 3;
		static const Sbecore::uint TCOTYPWIDTH = 4;
		static const Sbecore::uint TCORETWIDTH = 5;
		static const Sbecore::uint TCOREUWIDTH = 6;
		static const Sbecore::uint TCOSYSWIDTH = 7;
		static const Sbecore::uint TCOMDLWIDTH = 8;
		static const Sbecore::uint TCOPKGWIDTH = 9;
		static const Sbecore::uint TCOESYWIDTH = 10;
		static const Sbecore::uint TCOTCHWIDTH = 11;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoTitWidth = 200, const Sbecore::uint TcoFsrWidth = 150, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoRetWidth = 100, const Sbecore::uint TcoReuWidth = 250, const Sbecore::uint TcoSysWidth = 200, const Sbecore::uint TcoMdlWidth = 100, const Sbecore::uint TcoPkgWidth = 100, const Sbecore::uint TcoEsyWidth = 100, const Sbecore::uint TcoTchWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoFsrWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoRetWidth;
		Sbecore::uint TcoReuWidth;
		Sbecore::uint TcoSysWidth;
		Sbecore::uint TcoMdlWidth;
		Sbecore::uint TcoPkgWidth;
		Sbecore::uint TcoEsyWidth;
		Sbecore::uint TcoTchWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeUntList)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTFOR = 2;
		static const Sbecore::uint TXTRECORD1 = 3;
		static const Sbecore::uint TXTRECORD2 = 4;
		static const Sbecore::uint TRS = 5;
		static const Sbecore::uint TXTSHOWING1 = 6;
		static const Sbecore::uint TXTSHOWING2 = 7;
		static const Sbecore::uint TCOSRF = 8;
		static const Sbecore::uint TCOTIT = 9;
		static const Sbecore::uint TCOFSR = 10;
		static const Sbecore::uint TCOTYP = 11;
		static const Sbecore::uint TCORET = 12;
		static const Sbecore::uint TCOREU = 13;
		static const Sbecore::uint TCOSYS = 14;
		static const Sbecore::uint TCOMDL = 15;
		static const Sbecore::uint TCOPKG = 16;
		static const Sbecore::uint TCOESY = 17;
		static const Sbecore::uint TCOTCH = 18;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSrf = "", const std::string& TcoTit = "", const std::string& TcoFsr = "", const std::string& TcoTyp = "", const std::string& TcoRet = "", const std::string& TcoReu = "", const std::string& TcoSys = "", const std::string& TcoMdl = "", const std::string& TcoPkg = "", const std::string& TcoEsy = "", const std::string& TcoTch = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSrf;
		std::string TcoTit;
		std::string TcoFsr;
		std::string TcoTyp;
		std::string TcoRet;
		std::string TcoReu;
		std::string TcoSys;
		std::string TcoMdl;
		std::string TcoPkg;
		std::string TcoEsy;
		std::string TcoTch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeUntListData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWdbeUntList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWdbeUntList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeUntListDo)
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
		* DpchEngData (full: DpchEngWdbeUntListData)
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
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWdbeQUntList rst;
		QryWdbeUntList::StatApp statappqry;
		QryWdbeUntList::StatShr statshrqry;
		QryWdbeUntList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

