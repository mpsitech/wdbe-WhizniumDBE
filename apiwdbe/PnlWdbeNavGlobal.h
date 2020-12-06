/**
	* \file PnlWdbeNavGlobal.h
	* API code for job PnlWdbeNavGlobal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVGLOBAL_H
#define PNLWDBENAVGLOBAL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeNavGlobalDo PnlWdbeNavGlobal::VecVDo

#define ContIacWdbeNavGlobal PnlWdbeNavGlobal::ContIac
#define StatAppWdbeNavGlobal PnlWdbeNavGlobal::StatApp
#define StatShrWdbeNavGlobal PnlWdbeNavGlobal::StatShr
#define TagWdbeNavGlobal PnlWdbeNavGlobal::Tag

#define DpchAppWdbeNavGlobalData PnlWdbeNavGlobal::DpchAppData
#define DpchAppWdbeNavGlobalDo PnlWdbeNavGlobal::DpchAppDo
#define DpchEngWdbeNavGlobalData PnlWdbeNavGlobal::DpchEngData

/**
	* PnlWdbeNavGlobal
	*/
namespace PnlWdbeNavGlobal {
	/**
		* VecVDo (full: VecVWdbeNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMCHVIEWCLICK = 1;
		static const Sbecore::uint BUTMCHNEWCRDCLICK = 2;
		static const Sbecore::uint BUTLIBVIEWCLICK = 3;
		static const Sbecore::uint BUTLIBNEWCRDCLICK = 4;
		static const Sbecore::uint BUTFAMVIEWCLICK = 5;
		static const Sbecore::uint BUTFAMNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSILVIEWCLICK = 7;
		static const Sbecore::uint BUTSILNEWCRDCLICK = 8;
		static const Sbecore::uint BUTMTPVIEWCLICK = 9;
		static const Sbecore::uint BUTMTPNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavGlobal)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTMCH = 1;
		static const Sbecore::uint NUMFLSTLIB = 2;
		static const Sbecore::uint NUMFLSTFAM = 3;
		static const Sbecore::uint NUMFLSTSIL = 4;
		static const Sbecore::uint NUMFLSTMTP = 5;

	public:
		ContIac(const Sbecore::uint numFLstMch = 1, const Sbecore::uint numFLstLib = 1, const Sbecore::uint numFLstFam = 1, const Sbecore::uint numFLstSil = 1, const Sbecore::uint numFLstMtp = 1);

	public:
		Sbecore::uint numFLstMch;
		Sbecore::uint numFLstLib;
		Sbecore::uint numFLstFam;
		Sbecore::uint numFLstSil;
		Sbecore::uint numFLstMtp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeNavGlobal)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint LSTMCHALT = 2;
		static const Sbecore::uint LSTLIBALT = 3;
		static const Sbecore::uint LSTFAMALT = 4;
		static const Sbecore::uint LSTSILALT = 5;
		static const Sbecore::uint LSTMTPALT = 6;
		static const Sbecore::uint LSTMCHNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTLIBNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTFAMNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTSILNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTMTPNUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstMchAlt = true, const bool LstLibAlt = true, const bool LstFamAlt = true, const bool LstSilAlt = true, const bool LstMtpAlt = true, const Sbecore::uint LstMchNumFirstdisp = 1, const Sbecore::uint LstLibNumFirstdisp = 1, const Sbecore::uint LstFamNumFirstdisp = 1, const Sbecore::uint LstSilNumFirstdisp = 1, const Sbecore::uint LstMtpNumFirstdisp = 1);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool LstMchAlt;
		bool LstLibAlt;
		bool LstFamAlt;
		bool LstSilAlt;
		bool LstMtpAlt;
		Sbecore::uint LstMchNumFirstdisp;
		Sbecore::uint LstLibNumFirstdisp;
		Sbecore::uint LstFamNumFirstdisp;
		Sbecore::uint LstSilNumFirstdisp;
		Sbecore::uint LstMtpNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWdbeNavGlobal)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTMCHAVAIL = 1;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 2;
		static const Sbecore::uint LSTLIBAVAIL = 3;
		static const Sbecore::uint BUTLIBVIEWACTIVE = 4;
		static const Sbecore::uint LSTFAMAVAIL = 5;
		static const Sbecore::uint BUTFAMVIEWACTIVE = 6;
		static const Sbecore::uint LSTSILAVAIL = 7;
		static const Sbecore::uint BUTSILVIEWACTIVE = 8;
		static const Sbecore::uint LSTMTPAVAIL = 9;
		static const Sbecore::uint BUTMTPVIEWACTIVE = 10;

	public:
		StatShr(const bool LstMchAvail = true, const bool ButMchViewActive = true, const bool LstLibAvail = true, const bool ButLibViewActive = true, const bool LstFamAvail = true, const bool ButFamViewActive = true, const bool LstSilAvail = true, const bool ButSilViewActive = true, const bool LstMtpAvail = true, const bool ButMtpViewActive = true);

	public:
		bool LstMchAvail;
		bool ButMchViewActive;
		bool LstLibAvail;
		bool ButLibViewActive;
		bool LstFamAvail;
		bool ButFamViewActive;
		bool LstSilAvail;
		bool ButSilViewActive;
		bool LstMtpAvail;
		bool ButMtpViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeNavGlobal)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTMCH = 2;
		static const Sbecore::uint CPTLIB = 3;
		static const Sbecore::uint CPTFAM = 4;
		static const Sbecore::uint CPTSIL = 5;
		static const Sbecore::uint CPTMTP = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptMch = "", const std::string& CptLib = "", const std::string& CptFam = "", const std::string& CptSil = "", const std::string& CptMtp = "");

	public:
		std::string Cpt;
		std::string CptMch;
		std::string CptLib;
		std::string CptFam;
		std::string CptSil;
		std::string CptMtp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavGlobalData)
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
		* DpchAppDo (full: DpchAppWdbeNavGlobalDo)
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
		* DpchEngData (full: DpchEngWdbeNavGlobalData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFAM = 3;
		static const Sbecore::uint FEEDFLSTLIB = 4;
		static const Sbecore::uint FEEDFLSTMCH = 5;
		static const Sbecore::uint FEEDFLSTMTP = 6;
		static const Sbecore::uint FEEDFLSTSIL = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFam;
		Sbecore::Xmlio::Feed feedFLstLib;
		Sbecore::Xmlio::Feed feedFLstMch;
		Sbecore::Xmlio::Feed feedFLstMtp;
		Sbecore::Xmlio::Feed feedFLstSil;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
