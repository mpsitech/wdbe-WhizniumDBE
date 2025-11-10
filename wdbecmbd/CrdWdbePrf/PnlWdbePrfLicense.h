/**
	* \file PnlWdbePrfLicense.h
	* job handler for job PnlWdbePrfLicense (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRFLICENSE_H
#define PNLWDBEPRFLICENSE_H

// IP include.spec --- INSERT

#include "JobWdbeLicense.h" // IP include.cust --- LINE

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
class PnlWdbePrfLicense : public JobWdbe {

public:
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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePrfLicense)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrfLicenseData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePrfLicenseDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbePrfLicenseData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	PnlWdbePrfLicense(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePrfLicense();

public:
	ContIac contiac;
	StatShr statshr;

	// IP vars.cust --- BEGIN
	JobWdbeLicense::Stg stgjobwdbelicense;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
	void getPref(JobWdbeLicense::Stg*& _stgjobwdbelicense);
	void setPref(DbsWdbe* dbswdbe, const bool _refresh = false);
	// IP cust --- END

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

};

#endif
