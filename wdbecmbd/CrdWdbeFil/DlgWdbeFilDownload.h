/**
	* \file DlgWdbeFilDownload.h
	* job handler for job DlgWdbeFilDownload (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEFILDOWNLOAD_H
#define DLGWDBEFILDOWNLOAD_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeFilDownloadDo DlgWdbeFilDownload::VecVDo

#define ContInfDlgWdbeFilDownload DlgWdbeFilDownload::ContInf
#define StatAppDlgWdbeFilDownload DlgWdbeFilDownload::StatApp
#define TagDlgWdbeFilDownload DlgWdbeFilDownload::Tag

#define DpchAppDlgWdbeFilDownloadDo DlgWdbeFilDownload::DpchAppDo
#define DpchEngDlgWdbeFilDownloadData DlgWdbeFilDownload::DpchEngData

/**
	* DlgWdbeFilDownload
	*/
class DlgWdbeFilDownload : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeFilDownloadDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeFilDownload)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInf(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeFilDownload)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* Tag (full: TagDlgWdbeFilDownload)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeFilDownloadDo)
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
		* DpchEngData (full: DpchEngDlgWdbeFilDownloadData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	DlgWdbeFilDownload(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeFilDownload();

public:
	ContInf continf;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	std::string handleDownload(DbsWdbe* dbswdbe);

};

#endif
