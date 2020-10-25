/**
	* \file PnlWdbeNavAdmin.h
	* API code for job PnlWdbeNavAdmin (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBENAVADMIN_H
#define PNLWDBENAVADMIN_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavAdminDo PnlWdbeNavAdmin::VecVDo

#define ContIacWdbeNavAdmin PnlWdbeNavAdmin::ContIac
#define StatAppWdbeNavAdmin PnlWdbeNavAdmin::StatApp
#define StatShrWdbeNavAdmin PnlWdbeNavAdmin::StatShr
#define TagWdbeNavAdmin PnlWdbeNavAdmin::Tag

#define DpchAppWdbeNavAdminData PnlWdbeNavAdmin::DpchAppData
#define DpchAppWdbeNavAdminDo PnlWdbeNavAdmin::DpchAppDo
#define DpchEngWdbeNavAdminData PnlWdbeNavAdmin::DpchEngData

/**
	* PnlWdbeNavAdmin
	*/
namespace PnlWdbeNavAdmin {
	/**
		* VecVDo (full: VecVWdbeNavAdminDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUSGVIEWCLICK = 1;
		static const Sbecore::uint BUTUSGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTUSRVIEWCLICK = 3;
		static const Sbecore::uint BUTUSRNEWCRDCLICK = 4;
		static const Sbecore::uint BUTPRSVIEWCLICK = 5;
		static const Sbecore::uint BUTPRSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTFILVIEWCLICK = 7;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavAdmin)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTUSG = 1;
		static const Sbecore::uint NUMFLSTUSR = 2;
		static const Sbecore::uint NUMFLSTPRS = 3;
		static const Sbecore::uint NUMFLSTFIL = 4;

	public:
		ContIac(const Sbecore::uint numFLstUsg = 1, const Sbecore::uint numFLstUsr = 1, const Sbecore::uint numFLstPrs = 1, const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstUsg;
		Sbecore::uint numFLstUsr;
		Sbecore::uint numFLstPrs;
		Sbecore::uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavAdmin)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTUSGALT = 2;
		static const Sbecore::uint LSTUSRALT = 3;
		static const Sbecore::uint LSTPRSALT = 4;
		static const Sbecore::uint LSTFILALT = 5;
		static const Sbecore::uint LSTUSGNUMFIRSTDISP = 6;
		static const Sbecore::uint LSTUSRNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTPRSNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTFILNUMFIRSTDISP = 9;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstPrsAlt;
		bool LstFilAlt;
		Sbecore::uint LstUsgNumFirstdisp;
		Sbecore::uint LstUsrNumFirstdisp;
		Sbecore::uint LstPrsNumFirstdisp;
		Sbecore::uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavAdmin)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTUSGAVAIL = 1;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 2;
		static const Sbecore::uint LSTUSRAVAIL = 3;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 4;
		static const Sbecore::uint LSTPRSAVAIL = 5;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 6;
		static const Sbecore::uint LSTFILAVAIL = 7;
		static const Sbecore::uint BUTFILVIEWACTIVE = 8;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavAdmin)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTUSG = 2;
		static const Sbecore::uint CPTUSR = 3;
		static const Sbecore::uint CPTPRS = 4;
		static const Sbecore::uint CPTFIL = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptUsg = "", const std::string& CptUsr = "", const std::string& CptPrs = "", const std::string& CptFil = "");

	public:
		std::string Cpt;
		std::string CptUsg;
		std::string CptUsr;
		std::string CptPrs;
		std::string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavAdminData)
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
		* DpchAppDo (full: DpchAppWdbeNavAdminDo)
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
		* DpchEngData (full: DpchEngWdbeNavAdminData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint FEEDFLSTPRS = 4;
		static const Sbecore::uint FEEDFLSTUSG = 5;
		static const Sbecore::uint FEEDFLSTUSR = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFil;
		Sbecore::Xmlio::Feed feedFLstPrs;
		Sbecore::Xmlio::Feed feedFLstUsg;
		Sbecore::Xmlio::Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

