/**
	* \file PnlWdbeNavDevdev.h
	* API code for job PnlWdbeNavDevdev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
		static const Sbecore::uint BUTSYSVIEWCLICK = 5;
		static const Sbecore::uint BUTSYSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTTRGVIEWCLICK = 7;
		static const Sbecore::uint BUTTRGNEWCRDCLICK = 8;
		static const Sbecore::uint BUTUNTVIEWCLICK = 9;
		static const Sbecore::uint BUTUNTNEWCRDCLICK = 10;
		static const Sbecore::uint BUTRLSVIEWCLICK = 11;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTSYS = 3;
		static const Sbecore::uint NUMFLSTTRG = 4;
		static const Sbecore::uint NUMFLSTUNT = 5;
		static const Sbecore::uint NUMFLSTRLS = 6;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstSys = 1, const Sbecore::uint numFLstTrg = 1, const Sbecore::uint numFLstUnt = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstSys;
		Sbecore::uint numFLstTrg;
		Sbecore::uint numFLstUnt;
		Sbecore::uint numFLstRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavDevdev)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTPRJALT = 2;
		static const Sbecore::uint LSTVERALT = 3;
		static const Sbecore::uint LSTSYSALT = 4;
		static const Sbecore::uint LSTTRGALT = 5;
		static const Sbecore::uint LSTUNTALT = 6;
		static const Sbecore::uint LSTRLSALT = 7;
		static const Sbecore::uint LSTPRJNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTVERNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTSYSNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTTRGNUMFIRSTDISP = 11;
		static const Sbecore::uint LSTUNTNUMFIRSTDISP = 12;
		static const Sbecore::uint LSTRLSNUMFIRSTDISP = 13;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstSysAlt = true, const bool LstTrgAlt = true, const bool LstUntAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstSysNumFirstdisp = 1, const Sbecore::uint LstTrgNumFirstdisp = 1, const Sbecore::uint LstUntNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstPrjAlt;
		bool LstVerAlt;
		bool LstSysAlt;
		bool LstTrgAlt;
		bool LstUntAlt;
		bool LstRlsAlt;
		Sbecore::uint LstPrjNumFirstdisp;
		Sbecore::uint LstVerNumFirstdisp;
		Sbecore::uint LstSysNumFirstdisp;
		Sbecore::uint LstTrgNumFirstdisp;
		Sbecore::uint LstUntNumFirstdisp;
		Sbecore::uint LstRlsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavDevdev)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTSYSAVAIL = 5;
		static const Sbecore::uint BUTSYSVIEWACTIVE = 6;
		static const Sbecore::uint BUTSYSNEWCRDACTIVE = 7;
		static const Sbecore::uint LSTTRGAVAIL = 8;
		static const Sbecore::uint BUTTRGVIEWACTIVE = 9;
		static const Sbecore::uint BUTTRGNEWCRDACTIVE = 10;
		static const Sbecore::uint LSTUNTAVAIL = 11;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 12;
		static const Sbecore::uint BUTUNTNEWCRDACTIVE = 13;
		static const Sbecore::uint LSTRLSAVAIL = 14;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 15;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 16;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstSysAvail = true, const bool ButSysViewActive = true, const bool ButSysNewcrdActive = true, const bool LstTrgAvail = true, const bool ButTrgViewActive = true, const bool ButTrgNewcrdActive = true, const bool LstUntAvail = true, const bool ButUntViewActive = true, const bool ButUntNewcrdActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstSysAvail;
		bool ButSysViewActive;
		bool ButSysNewcrdActive;
		bool LstTrgAvail;
		bool ButTrgViewActive;
		bool ButTrgNewcrdActive;
		bool LstUntAvail;
		bool ButUntViewActive;
		bool ButUntNewcrdActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavDevdev)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRJ = 2;
		static const Sbecore::uint CPTVER = 3;
		static const Sbecore::uint CPTSYS = 4;
		static const Sbecore::uint CPTTRG = 5;
		static const Sbecore::uint CPTUNT = 6;
		static const Sbecore::uint CPTRLS = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrj = "", const std::string& CptVer = "", const std::string& CptSys = "", const std::string& CptTrg = "", const std::string& CptUnt = "", const std::string& CptRls = "");

	public:
		std::string Cpt;
		std::string CptPrj;
		std::string CptVer;
		std::string CptSys;
		std::string CptTrg;
		std::string CptUnt;
		std::string CptRls;

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
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint FEEDFLSTSYS = 5;
		static const Sbecore::uint FEEDFLSTTRG = 6;
		static const Sbecore::uint FEEDFLSTUNT = 7;
		static const Sbecore::uint FEEDFLSTVER = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstPrj;
		Sbecore::Xmlio::Feed feedFLstRls;
		Sbecore::Xmlio::Feed feedFLstSys;
		Sbecore::Xmlio::Feed feedFLstTrg;
		Sbecore::Xmlio::Feed feedFLstUnt;
		Sbecore::Xmlio::Feed feedFLstVer;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

