/**
	* \file PnlWdbeCmdDetail.h
	* API code for job PnlWdbeCmdDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBECMDDETAIL_H
#define PNLWDBECMDDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeCmdDetailDo PnlWdbeCmdDetail::VecVDo

#define ContIacWdbeCmdDetail PnlWdbeCmdDetail::ContIac
#define ContInfWdbeCmdDetail PnlWdbeCmdDetail::ContInf
#define StatAppWdbeCmdDetail PnlWdbeCmdDetail::StatApp
#define StatShrWdbeCmdDetail PnlWdbeCmdDetail::StatShr
#define TagWdbeCmdDetail PnlWdbeCmdDetail::Tag

#define DpchAppWdbeCmdDetailData PnlWdbeCmdDetail::DpchAppData
#define DpchAppWdbeCmdDetailDo PnlWdbeCmdDetail::DpchAppDo
#define DpchEngWdbeCmdDetailData PnlWdbeCmdDetail::DpchEngData

/**
	* PnlWdbeCmdDetail
	*/
namespace PnlWdbeCmdDetail {
	/**
		* VecVDo (full: VecVWdbeCmdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCmdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFSR = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint NUMFPUPRTY = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfFsr = "", const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupRty = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfFsr;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupRty;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCmdDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTREU = 2;
		static const Sbecore::uint TXTIVR = 3;
		static const Sbecore::uint TXTRVR = 4;
		static const Sbecore::uint TXTRER = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtReu = "", const std::string& TxtIvr = "", const std::string& TxtRvr = "", const std::string& TxtRer = "");

	public:
		std::string TxtSrf;
		std::string TxtReu;
		std::string TxtIvr;
		std::string TxtRvr;
		std::string TxtRer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeCmdDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWdbeCmdDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFFSRACTIVE = 4;
		static const Sbecore::uint TXTREUACTIVE = 5;
		static const Sbecore::uint BUTREUVIEWAVAIL = 6;
		static const Sbecore::uint BUTREUVIEWACTIVE = 7;
		static const Sbecore::uint PUPRTYACTIVE = 8;
		static const Sbecore::uint TXTIVRACTIVE = 9;
		static const Sbecore::uint TXTRVRACTIVE = 10;
		static const Sbecore::uint TXTRERACTIVE = 11;
		static const Sbecore::uint TXFCMTACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfFsrActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupRtyActive = true, const bool TxtIvrActive = true, const bool TxtRvrActive = true, const bool TxtRerActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfFsrActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupRtyActive;
		bool TxtIvrActive;
		bool TxtRvrActive;
		bool TxtRerActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeCmdDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTFSR = 3;
		static const Sbecore::uint CPTREU = 4;
		static const Sbecore::uint CPTRTY = 5;
		static const Sbecore::uint CPTIVR = 6;
		static const Sbecore::uint CPTRVR = 7;
		static const Sbecore::uint CPTRER = 8;
		static const Sbecore::uint CPTCMT = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptFsr = "", const std::string& CptReu = "", const std::string& CptRty = "", const std::string& CptIvr = "", const std::string& CptRvr = "", const std::string& CptRer = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptFsr;
		std::string CptReu;
		std::string CptRty;
		std::string CptIvr;
		std::string CptRvr;
		std::string CptRer;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCmdDetailData)
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
		* DpchAppDo (full: DpchAppWdbeCmdDetailDo)
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
		* DpchEngData (full: DpchEngWdbeCmdDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPRTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupRty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
