/**
	* \file WdbeQCvrList.h
	* Dbs and XML wrapper for table TblWdbeQCvrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQCVRLIST_H
#define WDBEQCVRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCvrList: record of TblWdbeQCvrList
	*/
class WdbeQCvrList {

public:
	WdbeQCvrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMCoreproject = 0, const std::string stubRefWdbeMCoreproject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const std::string stubBcvRefWdbeMCoreversion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWdbeMCoreproject;
	std::string stubRefWdbeMCoreproject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint bcvRefWdbeMCoreversion;
	std::string stubBcvRefWdbeMCoreversion;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCvrList: recordset of TblWdbeQCvrList
	*/
class ListWdbeQCvrList {

public:
	ListWdbeQCvrList();
	ListWdbeQCvrList(const ListWdbeQCvrList& src);
	~ListWdbeQCvrList();

	void clear();
	unsigned int size() const;
	void append(WdbeQCvrList* rec);

	ListWdbeQCvrList& operator=(const ListWdbeQCvrList& src);

public:
	std::vector<WdbeQCvrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCvrList: C++ wrapper for table TblWdbeQCvrList
	*/
class TblWdbeQCvrList {

public:
	TblWdbeQCvrList();
	virtual ~TblWdbeQCvrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCvrList* rec);
	Sbecore::ubigint insertNewRec(WdbeQCvrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMCoreproject = 0, const std::string stubRefWdbeMCoreproject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const std::string stubBcvRefWdbeMCoreversion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCvrList& rst, WdbeQCvrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMCoreproject = 0, const std::string stubRefWdbeMCoreproject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const std::string stubBcvRefWdbeMCoreversion = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "");
	virtual void insertRst(ListWdbeQCvrList& rst);
	virtual void updateRec(WdbeQCvrList* rec);
	virtual void updateRst(ListWdbeQCvrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCvrList: C++ wrapper for table TblWdbeQCvrList (MySQL database)
	*/
class MyTblWdbeQCvrList : public TblWdbeQCvrList, public Sbecore::MyTable {

public:
	MyTblWdbeQCvrList();
	~MyTblWdbeQCvrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrList& rst);

	Sbecore::ubigint insertRec(WdbeQCvrList* rec);
	void insertRst(ListWdbeQCvrList& rst);
	void updateRec(WdbeQCvrList* rec);
	void updateRst(ListWdbeQCvrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCvrList: C++ wrapper for table TblWdbeQCvrList (PgSQL database)
	*/
class PgTblWdbeQCvrList : public TblWdbeQCvrList, public Sbecore::PgTable {

public:
	PgTblWdbeQCvrList();
	~PgTblWdbeQCvrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCvrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCvrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCvrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCvrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrList& rst);

	Sbecore::ubigint insertRec(WdbeQCvrList* rec);
	void insertRst(ListWdbeQCvrList& rst);
	void updateRec(WdbeQCvrList* rec);
	void updateRst(ListWdbeQCvrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrList& rst);
};
#endif

#endif

