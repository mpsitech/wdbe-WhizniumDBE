/**
	* \file PnlWdbePrfLicense.h
	* API code for job PnlWdbePrfLicense (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRFLICENSE_H
#define PNLWDBEPRFLICENSE_H

#include "ApiWdbe_blks.h"

#define VecVWdbePrfLicenseDo PnlWdbePrfLicense::VecVDo

#define ContIacWdbePrfLicense PnlWdbePrfLicense::ContIac
#define StatShrWdbePrfLicense PnlWdbePrfLicense::StatShr
#define TagWdbePrfLicense PnlWdbePrfLicense::Tag

#define DpchAppWdbePrfLicenseData PnlWdbePrfLicense::DpchAppData
#define DpchAppWdbePrfLicenseDo PnlWdbePrfLicense::DpchAppDo
#define DpchEngWdbePrfLicenseData PnlWdbePrfLicense::DpchEngData

/**
	* PnlWdbePrfLicense
	*/
namespace PnlWdbePrfLicense {
	/**
		* VecVDo (full: VecVWdbePrfLicenseDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrfLicense)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF1 = 1;
		static const Sbecore::uint TXF2 = 2;
		static const Sbecore::uint TXF3 = 3;
		static const Sbecore::uint TXF4 = 4;
		static const Sbecore::uint TXF5 = 5;
		static const Sbecore::uint TXF6 = 6;
		static const Sbecore::uint TXF7 = 7;
		static const Sbecore::uint TXF8 = 8;
		static const Sbecore::uint TXF9 = 9;
		static const Sbecore::uint TXF10 = 10;

	public:
		ContIac(const std::string& Txf1 = "", const std::string& Txf2 = "", const std::string& Txf3 = "", const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const std::string& Txf7 = "", const std::string& Txf8 = "", const std::string& Txf9 = "", const std::string& Txf10 = "");

	public:
		std::string Txf1;
		std::string Txf2;
		std::string Txf3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		std::string Txf7;
		std::string Txf8;
		std::string Txf9;
		std::string Txf10;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePrfLicense)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint TXF1CLEAN = 2;
		static const Sbecore::uint TXF2CLEAN = 3;
		static const Sbecore::uint TXF3CLEAN = 4;
		static const Sbecore::uint TXF4CLEAN = 5;
		static const Sbecore::uint TXF5CLEAN = 6;
		static const Sbecore::uint TXF6CLEAN = 7;
		static const Sbecore::uint TXF7CLEAN = 8;
		static const Sbecore::uint TXF8CLEAN = 9;
		static const Sbecore::uint TXF9CLEAN = 10;
		static const Sbecore::uint TXF10CLEAN = 11;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool Txf1Clean = false, const bool Txf2Clean = false, const bool Txf3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Txf7Clean = false, const bool Txf8Clean = false, const bool Txf9Clean = false, const bool Txf10Clean = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool Txf1Clean;
		bool Txf2Clean;
		bool Txf3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Txf7Clean;
		bool Txf8Clean;
		bool Txf9Clean;
		bool Txf10Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePrfLicense)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPT1 = 2;
		static const Sbecore::uint CPT2 = 3;
		static const Sbecore::uint CPT3 = 4;
		static const Sbecore::uint CPT4 = 5;
		static const Sbecore::uint CPT5 = 6;
		static const Sbecore::uint CPT6 = 7;
		static const Sbecore::uint CPT7 = 8;
		static const Sbecore::uint CPT8 = 9;
		static const Sbecore::uint CPT9 = 10;
		static const Sbecore::uint CPT10 = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& Cpt1 = "", const std::string& Cpt2 = "", const std::string& Cpt3 = "", const std::string& Cpt4 = "", const std::string& Cpt5 = "", const std::string& Cpt6 = "", const std::string& Cpt7 = "", const std::string& Cpt8 = "", const std::string& Cpt9 = "", const std::string& Cpt10 = "");

	public:
		std::string Cpt;
		std::string Cpt1;
		std::string Cpt2;
		std::string Cpt3;
		std::string Cpt4;
		std::string Cpt5;
		std::string Cpt6;
		std::string Cpt7;
		std::string Cpt8;
		std::string Cpt9;
		std::string Cpt10;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrfLicenseData)
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
		* DpchAppDo (full: DpchAppWdbePrfLicenseDo)
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
		* DpchEngData (full: DpchEngWdbePrfLicenseData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
