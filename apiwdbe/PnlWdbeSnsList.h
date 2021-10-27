/**
	* \file PnlWdbeSnsList.h
	* API code for job PnlWdbeSnsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESNSLIST_H
#define PNLWDBESNSLIST_H

#include "ApiWdbe_blks.h"

#include "WdbeQSnsList.h"

#include "QryWdbeSnsList.h"

#define VecVWdbeSnsListDo PnlWdbeSnsList::VecVDo

#define ContIacWdbeSnsList PnlWdbeSnsList::ContIac
#define ContInfWdbeSnsList PnlWdbeSnsList::ContInf
#define StatShrWdbeSnsList PnlWdbeSnsList::StatShr
#define StgIacWdbeSnsList PnlWdbeSnsList::StgIac
#define TagWdbeSnsList PnlWdbeSnsList::Tag

#define DpchAppWdbeSnsListData PnlWdbeSnsList::DpchAppData
#define DpchAppWdbeSnsListDo PnlWdbeSnsList::DpchAppDo
#define DpchEngWdbeSnsListData PnlWdbeSnsList::DpchEngData

/**
	* PnlWdbeSnsList
	*/
namespace PnlWdbeSnsList {
	/**
		* VecVDo (full: VecVWdbeSnsListDo)
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
	  * ContIac (full: ContIacWdbeSnsList)
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
	  * ContInf (full: ContInfWdbeSnsList)
	  */
	class ContInf : public Sbecore::Block {

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
	  * StatShr (full: StatShrWdbeSnsList)
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
	  * StgIac (full: StgIacWdbeSnsList)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCORETWIDTH = 1;
		static const Sbecore::uint TCOREUWIDTH = 2;
		static const Sbecore::uint TCOSRTWIDTH = 3;
		static const Sbecore::uint TCOSRUWIDTH = 4;

	public:
		StgIac(const Sbecore::uint TcoRetWidth = 100, const Sbecore::uint TcoReuWidth = 100, const Sbecore::uint TcoSrtWidth = 100, const Sbecore::uint TcoSruWidth = 100);

	public:
		Sbecore::uint TcoRetWidth;
		Sbecore::uint TcoReuWidth;
		Sbecore::uint TcoSrtWidth;
		Sbecore::uint TcoSruWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeSnsList)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTFOR = 2;
		static const Sbecore::uint TXTRECORD1 = 3;
		static const Sbecore::uint TXTRECORD2 = 4;
		static const Sbecore::uint TRS = 5;
		static const Sbecore::uint TXTSHOWING1 = 6;
		static const Sbecore::uint TXTSHOWING2 = 7;
		static const Sbecore::uint TCORET = 8;
		static const Sbecore::uint TCOREU = 9;
		static const Sbecore::uint TCOSRT = 10;
		static const Sbecore::uint TCOSRU = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoRet = "", const std::string& TcoReu = "", const std::string& TcoSrt = "", const std::string& TcoSru = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoRet;
		std::string TcoReu;
		std::string TcoSrt;
		std::string TcoSru;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSnsListData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWdbeSnsList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWdbeSnsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeSnsListDo)
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
		* DpchEngData (full: DpchEngWdbeSnsListData)
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
		ListWdbeQSnsList rst;
		QryWdbeSnsList::StatApp statappqry;
		QryWdbeSnsList::StatShr statshrqry;
		QryWdbeSnsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
