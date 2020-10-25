/**
	* \file QryWdbeModList.h
	* job handler for job QryWdbeModList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef QRYWDBEMODLIST_H
#define QRYWDBEMODLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWdbeModListOrd QryWdbeModList::VecVOrd

#define StatAppQryWdbeModList QryWdbeModList::StatApp
#define StatShrQryWdbeModList QryWdbeModList::StatShr
#define StgIacQryWdbeModList QryWdbeModList::StgIac

/**
	* QryWdbeModList
	*/
class QryWdbeModList : public JobWdbe {

public:
	/**
		* VecVOrd (full: VecVQryWdbeModListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint SRF = 1;
		static const Sbecore::uint TYP = 2;
		static const Sbecore::uint HKT = 3;
		static const Sbecore::uint HKU = 4;
		static const Sbecore::uint SUP = 5;
		static const Sbecore::uint TPL = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWdbeModList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 9, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWdbeModList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWdbeModList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWdbeModList(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~QryWdbeModList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWdbeQModList rst;

	Sbecore::uint ixWdbeVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWdbe* dbswdbe, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const Sbecore::uint preTyp, const Sbecore::uint preHkt, const Sbecore::ubigint preHku, const Sbecore::ubigint preSup, const Sbecore::ubigint preTpl, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWdbe* dbswdbe);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WdbeQModList* getRecByJnum(const Sbecore::uint jnum);

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
	bool handleCallWdbeMdlMod(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeMdlUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif

