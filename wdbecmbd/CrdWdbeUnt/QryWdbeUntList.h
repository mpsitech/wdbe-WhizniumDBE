/**
	* \file QryWdbeUntList.h
	* job handler for job QryWdbeUntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef QRYWDBEUNTLIST_H
#define QRYWDBEUNTLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWdbeUntListOrd QryWdbeUntList::VecVOrd

#define StatAppQryWdbeUntList QryWdbeUntList::StatApp
#define StatShrQryWdbeUntList QryWdbeUntList::StatShr
#define StgIacQryWdbeUntList QryWdbeUntList::StgIac

/**
	* QryWdbeUntList
	*/
class QryWdbeUntList : public JobWdbe {

public:
	/**
		* VecVOrd (full: VecVQryWdbeUntListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint MDL = 1;
		static const Sbecore::uint SYS = 2;
		static const Sbecore::uint REU = 3;
		static const Sbecore::uint RET = 4;
		static const Sbecore::uint TYP = 5;
		static const Sbecore::uint TIT = 6;
		static const Sbecore::uint SRF = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWdbeUntList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 15, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWdbeUntList)
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
		* StgIac (full: StgIacQryWdbeUntList)
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
	QryWdbeUntList(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~QryWdbeUntList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWdbeQUntList rst;

	Sbecore::uint ixWdbeVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWdbe* dbswdbe, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const std::string& preTit, const Sbecore::uint preTyp, const Sbecore::uint preRet, const Sbecore::ubigint preReu, const Sbecore::ubigint preSys, const Sbecore::ubigint preMdl, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWdbe* dbswdbe);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WdbeQUntList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:
	bool handleRerun(DbsWdbe* dbswdbe);
	bool handleShow(DbsWdbe* dbswdbe);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeUntUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeUntMod(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeStubChgFromSelf(DbsWdbe* dbswdbe);

};

#endif



