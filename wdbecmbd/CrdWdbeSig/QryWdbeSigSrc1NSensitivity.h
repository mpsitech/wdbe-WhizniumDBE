/**
	* \file QryWdbeSigSrc1NSensitivity.h
	* job handler for job QryWdbeSigSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef QRYWDBESIGSRC1NSENSITIVITY_H
#define QRYWDBESIGSRC1NSENSITIVITY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatAppQryWdbeSigSrc1NSensitivity QryWdbeSigSrc1NSensitivity::StatApp
#define StatShrQryWdbeSigSrc1NSensitivity QryWdbeSigSrc1NSensitivity::StatShr
#define StgIacQryWdbeSigSrc1NSensitivity QryWdbeSigSrc1NSensitivity::StgIac

/**
	* QryWdbeSigSrc1NSensitivity
	*/
class QryWdbeSigSrc1NSensitivity : public JobWdbe {

public:
	/**
		* StatApp (full: StatAppQryWdbeSigSrc1NSensitivity)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryWdbeSigSrc1NSensitivity)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWdbeSigSrc1NSensitivity)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWdbeSigSrc1NSensitivity(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~QryWdbeSigSrc1NSensitivity();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWdbeQSigSrc1NSensitivity rst;

	Sbecore::uint ixWdbeVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWdbe* dbswdbe, const bool call = false);

	void fetch(DbsWdbe* dbswdbe);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WdbeQSigSrc1NSensitivity* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:
	bool handleRerun(DbsWdbe* dbswdbe);
	bool handleShow(DbsWdbe* dbswdbe);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeStubChgFromSelf(DbsWdbe* dbswdbe);
	bool handleCallWdbeSnsMod_srtSruEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif