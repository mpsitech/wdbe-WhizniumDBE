/**
	* \file PnlWdbeUsgMNUser.h
	* API code for job PnlWdbeUsgMNUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEUSGMNUSER_H
#define PNLWDBEUSGMNUSER_H

#include "ApiWdbe_blks.h"

#include "WdbeQUsgMNUser.h"

#include "QryWdbeUsgMNUser.h"

#define VecVWdbeUsgMNUserDo PnlWdbeUsgMNUser::VecVDo

#define ContInfWdbeUsgMNUser PnlWdbeUsgMNUser::ContInf
#define StatAppWdbeUsgMNUser PnlWdbeUsgMNUser::StatApp
#define StatShrWdbeUsgMNUser PnlWdbeUsgMNUser::StatShr
#define StgIacWdbeUsgMNUser PnlWdbeUsgMNUser::StgIac
#define TagWdbeUsgMNUser PnlWdbeUsgMNUser::Tag

#define DpchAppWdbeUsgMNUserData PnlWdbeUsgMNUser::DpchAppData
#define DpchAppWdbeUsgMNUserDo PnlWdbeUsgMNUser::DpchAppDo
#define DpchEngWdbeUsgMNUserData PnlWdbeUsgMNUser::DpchEngData

/**
	* PnlWdbeUsgMNUser
	*/
namespace PnlWdbeUsgMNUser {
	/**
		* VecVDo (full: VecVWdbeUsgMNUserDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVIEWCLICK = 1;
		static const Sbecore::uint BUTADDCLICK = 2;
		static const Sbecore::uint BUTSUBCLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeUsgMNUser)
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
	  * StatApp (full: StatAppWdbeUsgMNUser)
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
	  * StatShr (full: StatShrWdbeUsgMNUser)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTVIEWAVAIL = 1;
		static const Sbecore::uint BUTVIEWACTIVE = 2;
		static const Sbecore::uint BUTADDAVAIL = 3;
		static const Sbecore::uint BUTSUBAVAIL = 4;
		static const Sbecore::uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWdbeUsgMNUser)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;
		static const Sbecore::uint TCOULVWIDTH = 2;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 250, const Sbecore::uint TcoUlvWidth = 100);

	public:
		Sbecore::uint TcoMrefWidth;
		Sbecore::uint TcoUlvWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWdbeUsgMNUser)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOMREF = 7;
		static const Sbecore::uint TCOULV = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoMref = "", const std::string& TcoUlv = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoMref;
		std::string TcoUlv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeUsgMNUserData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWdbeUsgMNUser::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWdbeUsgMNUser::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeUsgMNUserDo)
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
		* DpchEngData (full: DpchEngWdbeUsgMNUserData)
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
		ListWdbeQUsgMNUser rst;
		QryWdbeUsgMNUser::StatApp statappqry;
		QryWdbeUsgMNUser::StatShr statshrqry;
		QryWdbeUsgMNUser::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
