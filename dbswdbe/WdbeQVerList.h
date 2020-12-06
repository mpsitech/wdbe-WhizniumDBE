/**
	* \file WdbeQVerList.h
	* Dbs and XML wrapper for table TblWdbeQVerList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVERLIST_H
#define WDBEQVERLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVerList: record of TblWdbeQVerList
	*/
class WdbeQVerList {

public:
	WdbeQVerList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMProject = 0, const std::string stubRefWdbeMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const std::string stubBvrRefWdbeMVersion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWdbeMProject;
	std::string stubRefWdbeMProject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint bvrRefWdbeMVersion;
	std::string stubBvrRefWdbeMVersion;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVerList: recordset of TblWdbeQVerList
	*/
class ListWdbeQVerList {

public:
	ListWdbeQVerList();
	ListWdbeQVerList(const ListWdbeQVerList& src);
	~ListWdbeQVerList();

	void clear();
	unsigned int size() const;
	void append(WdbeQVerList* rec);

	ListWdbeQVerList& operator=(const ListWdbeQVerList& src);

public:
	std::vector<WdbeQVerList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVerList: C++ wrapper for table TblWdbeQVerList
	*/
class TblWdbeQVerList {

public:
	TblWdbeQVerList();
	virtual ~TblWdbeQVerList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVerList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVerList* rec);
	Sbecore::ubigint insertNewRec(WdbeQVerList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMProject = 0, const std::string stubRefWdbeMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const std::string stubBvrRefWdbeMVersion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVerList& rst, WdbeQVerList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMProject = 0, const std::string stubRefWdbeMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const std::string stubBvrRefWdbeMVersion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");
	virtual void insertRst(ListWdbeQVerList& rst);
	virtual void updateRec(WdbeQVerList* rec);
	virtual void updateRst(ListWdbeQVerList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVerList: C++ wrapper for table TblWdbeQVerList (MySQL database)
	*/
class MyTblWdbeQVerList : public TblWdbeQVerList, public Sbecore::MyTable {

public:
	MyTblWdbeQVerList();
	~MyTblWdbeQVerList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerList& rst);

	Sbecore::ubigint insertRec(WdbeQVerList* rec);
	void insertRst(ListWdbeQVerList& rst);
	void updateRec(WdbeQVerList* rec);
	void updateRst(ListWdbeQVerList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVerList: C++ wrapper for table TblWdbeQVerList (PgSQL database)
	*/
class PgTblWdbeQVerList : public TblWdbeQVerList, public Sbecore::PgTable {

public:
	PgTblWdbeQVerList();
	~PgTblWdbeQVerList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVerList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVerList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVerList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVerList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerList& rst);

	Sbecore::ubigint insertRec(WdbeQVerList* rec);
	void insertRst(ListWdbeQVerList& rst);
	void updateRec(WdbeQVerList* rec);
	void updateRst(ListWdbeQVerList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerList& rst);
};
#endif

#endif
