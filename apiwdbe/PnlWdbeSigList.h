/**
	* \file PnlWdbeSigList.h
	* API code for job PnlWdbeSigList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESIGLIST_H
#define PNLWDBESIGLIST_H

#include "ApiWdbe_blks.h"

#include "WdbeQSigList.h"

#include "QryWdbeSigList.h"

#define VecVWdbeSigListDo PnlWdbeSigList::VecVDo

#define ContIacWdbeSigList PnlWdbeSigList::ContIac
#define ContInfWdbeSigList PnlWdbeSigList::ContInf
#define StatShrWdbeSigList PnlWdbeSigList::StatShr
#define StgIacWdbeSigList PnlWdbeSigList::StgIac
#define TagWdbeSigList PnlWdbeSigList::Tag

#define DpchAppWdbeSigListData PnlWdbeSigList::DpchAppData
#define DpchAppWdbeSigListDo PnlWdbeSigList::DpchAppDo
#define DpchEngWdbeSigListData PnlWdbeSigList::DpchEngData

/**
	* PnlWdbeSigList
	*/
namespace PnlWdbeSigList {
	/**
		* VecVDo (full: VecVWdbeSigListDo)
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
	  * ContIac (full: ContIacWdbeSigList)
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
	  * ContInf (full: ContInfWdbeSigList)
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
	  * StatShr (full: StatShrWdbeSigList)
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
	  * StgIac (full: StgIacWdbeSigList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOTYPWIDTH = 2;
		static const Sbecore::uint TCOMDLWIDTH = 3;
		static const Sbecore::uint TCOMGTWIDTH = 4;
		static const Sbecore::uint TCOMGUWIDTH = 5;
		static const Sbecore::uint TCOVECWIDTH = 6;
		static const Sbecore::uint TCOCONWIDTH = 7;
		static const Sbecore::uint TCOHTYWIDTH = 8;
		static const Sbecore::uint TCOWIDWIDTH = 9;
		static const Sbecore::uint TCOMMXWIDTH = 10;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoMdlWidth = 100, const Sbecore::uint TcoMgtWidth = 100, const Sbecore::uint TcoMguWidth = 100, const Sbecore::uint TcoVecWidth = 100, const Sbecore::uint TcoConWidth = 100, const Sbecore::uint TcoHtyWidth = 100, const Sbecore::uint TcoWidWidth = 100, const Sbecore::uint TcoMmxWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoMdlWidth;
		Sbecore::uint TcoMgtWidth;
		Sbecore::uint TcoMguWidth;
		Sbecore::uint TcoVecWidth;
		Sbecore::uint TcoConWidth;
		Sbecore::uint TcoHtyWidth;
		Sbecore::uint TcoWidWidth;
		Sbecore::uint TcoMmxWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeSigList)
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
		static const Sbecore::uint TCOTYP = 9;
		static const Sbecore::uint TCOMDL = 10;
		static const Sbecore::uint TCOMGT = 11;
		static const Sbecore::uint TCOMGU = 12;
		static const Sbecore::uint TCOVEC = 13;
		static const Sbecore::uint TCOCON = 14;
		static const Sbecore::uint TCOHTY = 15;
		static const Sbecore::uint TCOWID = 16;
		static const Sbecore::uint TCOMMX = 17;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSrf = "", const std::string& TcoTyp = "", const std::string& TcoMdl = "", const std::string& TcoMgt = "", const std::string& TcoMgu = "", const std::string& TcoVec = "", const std::string& TcoCon = "", const std::string& TcoHty = "", const std::string& TcoWid = "", const std::string& TcoMmx = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSrf;
		std::string TcoTyp;
		std::string TcoMdl;
		std::string TcoMgt;
		std::string TcoMgu;
		std::string TcoVec;
		std::string TcoCon;
		std::string TcoHty;
		std::string TcoWid;
		std::string TcoMmx;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSigListData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWdbeSigList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWdbeSigList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeSigListDo)
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
		* DpchEngData (full: DpchEngWdbeSigListData)
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
		ListWdbeQSigList rst;
		QryWdbeSigList::StatApp statappqry;
		QryWdbeSigList::StatShr statshrqry;
		QryWdbeSigList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
