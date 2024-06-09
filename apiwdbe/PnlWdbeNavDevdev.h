/**
	* \file PnlWdbeNavDevdev.h
	* API code for job PnlWdbeNavDevdev (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVDEVDEV_H
#define PNLWDBENAVDEVDEV_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavDevdevDo PnlWdbeNavDevdev::VecVDo

#define ContIacWdbeNavDevdev PnlWdbeNavDevdev::ContIac
#define StatAppWdbeNavDevdev PnlWdbeNavDevdev::StatApp
#define StatShrWdbeNavDevdev PnlWdbeNavDevdev::StatShr
#define TagWdbeNavDevdev PnlWdbeNavDevdev::Tag

#define DpchAppWdbeNavDevdevData PnlWdbeNavDevdev::DpchAppData
#define DpchAppWdbeNavDevdevDo PnlWdbeNavDevdev::DpchAppDo
#define DpchEngWdbeNavDevdevData PnlWdbeNavDevdev::DpchEngData

/**
	* PnlWdbeNavDevdev
	*/
namespace PnlWdbeNavDevdev {
	/**
		* VecVDo (full: VecVWdbeNavDevdevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRJVIEWCLICK = 1;
		static const Sbecore::uint BUTPRJNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTVERNEWCRDCLICK = 4;
		static const Sbecore::uint BUTUNTVIEWCLICK = 5;
		static const Sbecore::uint BUTUNTNEWCRDCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTUNT = 3;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstUnt = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstUnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavDevdev)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTPRJALT = 2;
		static const Sbecore::uint LSTVERALT = 3;
		static const Sbecore::uint LSTUNTALT = 4;
		static const Sbecore::uint LSTPRJNUMFIRSTDISP = 5;
		static const Sbecore::uint LSTVERNUMFIRSTDISP = 6;
		static const Sbecore::uint LSTUNTNUMFIRSTDISP = 7;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstUntAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstUntNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstPrjAlt;
		bool LstVerAlt;
		bool LstUntAlt;
		Sbecore::uint LstPrjNumFirstdisp;
		Sbecore::uint LstVerNumFirstdisp;
		Sbecore::uint LstUntNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavDevdev)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTUNTAVAIL = 5;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 6;
		static const Sbecore::uint BUTUNTNEWCRDACTIVE = 7;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstUntAvail = true, const bool ButUntViewActive = true, const bool ButUntNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstUntAvail;
		bool ButUntViewActive;
		bool ButUntNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavDevdev)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRJ = 2;
		static const Sbecore::uint CPTVER = 3;
		static const Sbecore::uint CPTUNT = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrj = "", const std::string& CptVer = "", const std::string& CptUnt = "");

	public:
		std::string Cpt;
		std::string CptPrj;
		std::string CptVer;
		std::string CptUnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDevdevData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDevdevDo)
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
		* DpchEngData (full: DpchEngWdbeNavDevdevData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTPRJ = 3;
		static const Sbecore::uint FEEDFLSTUNT = 4;
		static const Sbecore::uint FEEDFLSTVER = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstPrj;
		Sbecore::Feed feedFLstUnt;
		Sbecore::Feed feedFLstVer;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
