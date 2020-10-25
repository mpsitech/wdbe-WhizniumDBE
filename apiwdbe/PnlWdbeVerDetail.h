/**
	* \file PnlWdbeVerDetail.h
	* API code for job PnlWdbeVerDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEVERDETAIL_H
#define PNLWDBEVERDETAIL_H

#include "ApiWdbe_blks.h"

#define VecVWdbeVerDetailDo PnlWdbeVerDetail::VecVDo

#define ContIacWdbeVerDetail PnlWdbeVerDetail::ContIac
#define ContInfWdbeVerDetail PnlWdbeVerDetail::ContInf
#define StatAppWdbeVerDetail PnlWdbeVerDetail::StatApp
#define StatShrWdbeVerDetail PnlWdbeVerDetail::StatShr
#define TagWdbeVerDetail PnlWdbeVerDetail::Tag

#define DpchAppWdbeVerDetailData PnlWdbeVerDetail::DpchAppData
#define DpchAppWdbeVerDetailDo PnlWdbeVerDetail::DpchAppDo
#define DpchEngWdbeVerDetailData PnlWdbeVerDetail::DpchEngData

/**
	* PnlWdbeVerDetail
	*/
namespace PnlWdbeVerDetail {
	/**
		* VecVDo (full: VecVWdbeVerDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRJVIEWCLICK = 2;
		static const Sbecore::uint BUTBVRVIEWCLICK = 3;
		static const Sbecore::uint BUTJSTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeVerDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFMAJ = 1;
		static const Sbecore::uint TXFMIN = 2;
		static const Sbecore::uint TXFSUB = 3;
		static const Sbecore::uint NUMFPUPJST = 4;
		static const Sbecore::uint NUMFPUPSTE = 5;
		static const Sbecore::uint TXFABT = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const std::string& TxfMaj = "", const std::string& TxfMin = "", const std::string& TxfSub = "", const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const std::string& TxfAbt = "", const std::string& TxfCmt = "");

	public:
		std::string TxfMaj;
		std::string TxfMin;
		std::string TxfSub;
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		std::string TxfAbt;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeVerDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRJ = 1;
		static const Sbecore::uint TXTBVR = 2;

	public:
		ContInf(const std::string& TxtPrj = "", const std::string& TxtBvr = "");

	public:
		std::string TxtPrj;
		std::string TxtBvr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWdbeVerDetail)
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
	  * StatShr (full: StatShrWdbeVerDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRJACTIVE = 3;
		static const Sbecore::uint BUTPRJVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 5;
		static const Sbecore::uint TXFMAJACTIVE = 6;
		static const Sbecore::uint TXFMINACTIVE = 7;
		static const Sbecore::uint TXFSUBACTIVE = 8;
		static const Sbecore::uint TXTBVRACTIVE = 9;
		static const Sbecore::uint BUTBVRVIEWAVAIL = 10;
		static const Sbecore::uint BUTBVRVIEWACTIVE = 11;
		static const Sbecore::uint PUPJSTACTIVE = 12;
		static const Sbecore::uint BUTJSTEDITAVAIL = 13;
		static const Sbecore::uint PUPSTEACTIVE = 14;
		static const Sbecore::uint TXFABTACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrjActive = true, const bool ButPrjViewAvail = true, const bool ButPrjViewActive = true, const bool TxfMajActive = true, const bool TxfMinActive = true, const bool TxfSubActive = true, const bool TxtBvrActive = true, const bool ButBvrViewAvail = true, const bool ButBvrViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool TxfAbtActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrjActive;
		bool ButPrjViewAvail;
		bool ButPrjViewActive;
		bool TxfMajActive;
		bool TxfMinActive;
		bool TxfSubActive;
		bool TxtBvrActive;
		bool ButBvrViewAvail;
		bool ButBvrViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool TxfAbtActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbeVerDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRJ = 2;
		static const Sbecore::uint CPTMAJ = 3;
		static const Sbecore::uint CPTMIN = 4;
		static const Sbecore::uint CPTSUB = 5;
		static const Sbecore::uint CPTBVR = 6;
		static const Sbecore::uint CPTSTE = 7;
		static const Sbecore::uint CPTABT = 8;
		static const Sbecore::uint CPTCMT = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrj = "", const std::string& CptMaj = "", const std::string& CptMin = "", const std::string& CptSub = "", const std::string& CptBvr = "", const std::string& CptSte = "", const std::string& CptAbt = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptPrj;
		std::string CptMaj;
		std::string CptMin;
		std::string CptSub;
		std::string CptBvr;
		std::string CptSte;
		std::string CptAbt;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbeVerDetailData)
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
		* DpchAppDo (full: DpchAppWdbeVerDetailDo)
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
		* DpchEngData (full: DpchEngWdbeVerDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJST = 4;
		static const Sbecore::uint FEEDFPUPSTE = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJst;
		Sbecore::Xmlio::Feed feedFPupSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

