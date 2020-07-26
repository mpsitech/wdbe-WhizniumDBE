/**
	* \file PnlWdbeNavCoredev.h
	* API code for job PnlWdbeNavCoredev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWDBENAVCOREDEV_H
#define PNLWDBENAVCOREDEV_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavCoredevDo PnlWdbeNavCoredev::VecVDo

#define ContIacWdbeNavCoredev PnlWdbeNavCoredev::ContIac
#define StatAppWdbeNavCoredev PnlWdbeNavCoredev::StatApp
#define StatShrWdbeNavCoredev PnlWdbeNavCoredev::StatShr
#define TagWdbeNavCoredev PnlWdbeNavCoredev::Tag

#define DpchAppWdbeNavCoredevData PnlWdbeNavCoredev::DpchAppData
#define DpchAppWdbeNavCoredevDo PnlWdbeNavCoredev::DpchAppDo
#define DpchEngWdbeNavCoredevData PnlWdbeNavCoredev::DpchEngData

/**
	* PnlWdbeNavCoredev
	*/
namespace PnlWdbeNavCoredev {
	/**
		* VecVDo (full: VecVWdbeNavCoredevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCPRVIEWCLICK = 1;
		static const Sbecore::uint BUTCPRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTCVRVIEWCLICK = 3;
		static const Sbecore::uint BUTCVRNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavCoredev)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCPR = 1;
		static const Sbecore::uint NUMFLSTCVR = 2;

	public:
		ContIac(const Sbecore::uint numFLstCpr = 1, const Sbecore::uint numFLstCvr = 1);

	public:
		Sbecore::uint numFLstCpr;
		Sbecore::uint numFLstCvr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavCoredev)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTCPRALT = 2;
		static const Sbecore::uint LSTCVRALT = 3;
		static const Sbecore::uint LSTCPRNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTCVRNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCprAlt = true, const bool LstCvrAlt = true, const Sbecore::uint LstCprNumFirstdisp = 1, const Sbecore::uint LstCvrNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstCprAlt;
		bool LstCvrAlt;
		Sbecore::uint LstCprNumFirstdisp;
		Sbecore::uint LstCvrNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavCoredev)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTCPRAVAIL = 1;
		static const Sbecore::uint BUTCPRVIEWACTIVE = 2;
		static const Sbecore::uint LSTCVRAVAIL = 3;
		static const Sbecore::uint BUTCVRVIEWACTIVE = 4;

	public:
		StatShr(const bool LstCprAvail = true, const bool ButCprViewActive = true, const bool LstCvrAvail = true, const bool ButCvrViewActive = true);

	public:
		bool LstCprAvail;
		bool ButCprViewActive;
		bool LstCvrAvail;
		bool ButCvrViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavCoredev)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCPR = 2;
		static const Sbecore::uint CPTCVR = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCpr = "", const std::string& CptCvr = "");

	public:
		std::string Cpt;
		std::string CptCpr;
		std::string CptCvr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavCoredevData)
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
		* DpchAppDo (full: DpchAppWdbeNavCoredevDo)
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
		* DpchEngData (full: DpchEngWdbeNavCoredevData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCPR = 3;
		static const Sbecore::uint FEEDFLSTCVR = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCpr;
		Sbecore::Xmlio::Feed feedFLstCvr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

