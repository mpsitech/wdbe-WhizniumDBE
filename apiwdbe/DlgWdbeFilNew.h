/**
	* \file DlgWdbeFilNew.h
	* API code for job DlgWdbeFilNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWDBEFILNEW_H
#define DLGWDBEFILNEW_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeFilNewDit DlgWdbeFilNew::VecVDit
#define VecVDlgWdbeFilNewDo DlgWdbeFilNew::VecVDo
#define VecVDlgWdbeFilNewDoDet DlgWdbeFilNew::VecVDoDet
#define VecVDlgWdbeFilNewSge DlgWdbeFilNew::VecVSge

#define ContIacDlgWdbeFilNew DlgWdbeFilNew::ContIac
#define ContIacDlgWdbeFilNewDet DlgWdbeFilNew::ContIacDet
#define ContInfDlgWdbeFilNew DlgWdbeFilNew::ContInf
#define StatAppDlgWdbeFilNew DlgWdbeFilNew::StatApp
#define StatShrDlgWdbeFilNew DlgWdbeFilNew::StatShr
#define StatShrDlgWdbeFilNewDet DlgWdbeFilNew::StatShrDet
#define StatShrDlgWdbeFilNewFil DlgWdbeFilNew::StatShrFil
#define TagDlgWdbeFilNew DlgWdbeFilNew::Tag
#define TagDlgWdbeFilNewDet DlgWdbeFilNew::TagDet
#define TagDlgWdbeFilNewFil DlgWdbeFilNew::TagFil

#define DpchAppDlgWdbeFilNewData DlgWdbeFilNew::DpchAppData
#define DpchAppDlgWdbeFilNewDo DlgWdbeFilNew::DpchAppDo
#define DpchEngDlgWdbeFilNewData DlgWdbeFilNew::DpchEngData

/**
	* DlgWdbeFilNew
	*/
namespace DlgWdbeFilNew {
	/**
		* VecVDit (full: VecVDlgWdbeFilNewDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint FIL = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWdbeFilNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWdbeFilNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTCRECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeFilNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint CREDONE = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeFilNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgWdbeFilNewDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFREU = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint NUMFPUPMIM = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIacDet(const std::string& TxfFnm = "", const Sbecore::uint numFPupRet = 1, const std::string& TxfReu = "", const Sbecore::uint numFPupCnt = 1, const Sbecore::uint numFPupMim = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFPupRet;
		std::string TxfReu;
		Sbecore::uint numFPupCnt;
		Sbecore::uint numFPupMim;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeFilNew)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeFilNew)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONE = 1;
		static const Sbecore::uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const std::string& shortMenu = "");

	public:
		bool initdone;
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWdbeFilNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrDet (full: StatShrDlgWdbeFilNewDet)
	  */
	class StatShrDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
	  * StatShrFil (full: StatShrDlgWdbeFilNewFil)
	  */
	class StatShrFil : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrFil(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFil* comp);
		std::set<Sbecore::uint> diff(const StatShrFil* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeFilNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint BUTDNE = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgWdbeFilNewDet)
	  */
	class TagDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTFNM = 1;
		static const Sbecore::uint CPTRET = 2;
		static const Sbecore::uint CPTREU = 3;
		static const Sbecore::uint CPTCNT = 4;
		static const Sbecore::uint CPTMIM = 5;
		static const Sbecore::uint CPTCMT = 6;
		static const Sbecore::uint BUTCRE = 7;

	public:
		TagDet(const std::string& CptFnm = "", const std::string& CptRet = "", const std::string& CptReu = "", const std::string& CptCnt = "", const std::string& CptMim = "", const std::string& CptCmt = "", const std::string& ButCre = "");

	public:
		std::string CptFnm;
		std::string CptRet;
		std::string CptReu;
		std::string CptCnt;
		std::string CptMim;
		std::string CptCmt;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagFil (full: TagDlgWdbeFilNewFil)
	  */
	class TagFil : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagFil(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeFilNewData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeFilNewDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoDet = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeFilNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint FEEDFDETPUPCNT = 5;
		static const Sbecore::uint FEEDFDETPUPMIM = 6;
		static const Sbecore::uint FEEDFDETPUPRET = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRDET = 12;
		static const Sbecore::uint STATSHRFIL = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGDET = 15;
		static const Sbecore::uint TAGFIL = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupCnt;
		Sbecore::Xmlio::Feed feedFDetPupMim;
		Sbecore::Xmlio::Feed feedFDetPupRet;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrFil statshrfil;
		Tag tag;
		TagDet tagdet;
		TagFil tagfil;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

