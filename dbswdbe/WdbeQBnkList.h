/**
	* \file WdbeQBnkList.h
	* Dbs and XML wrapper for table TblWdbeQBnkList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQBNKLIST_H
#define WDBEQBNKLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQBnkList: record of TblWdbeQBnkList
	*/
class WdbeQBnkList {

public:
	WdbeQBnkList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const std::string srefKVoltstd = "", const std::string titSrefKVoltstd = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMUnit;
	std::string stubRefWdbeMUnit;
	std::string srefKVoltstd;
	std::string titSrefKVoltstd;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQBnkList: recordset of TblWdbeQBnkList
	*/
class ListWdbeQBnkList {

public:
	ListWdbeQBnkList();
	ListWdbeQBnkList(const ListWdbeQBnkList& src);
	~ListWdbeQBnkList();

	void clear();
	unsigned int size() const;
	void append(WdbeQBnkList* rec);

	ListWdbeQBnkList& operator=(const ListWdbeQBnkList& src);

public:
	std::vector<WdbeQBnkList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQBnkList: C++ wrapper for table TblWdbeQBnkList
	*/
class TblWdbeQBnkList {

public:
	TblWdbeQBnkList();
	virtual ~TblWdbeQBnkList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQBnkList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnkList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQBnkList* rec);
	Sbecore::ubigint insertNewRec(WdbeQBnkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const std::string srefKVoltstd = "", const std::string titSrefKVoltstd = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQBnkList& rst, WdbeQBnkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const std::string srefKVoltstd = "", const std::string titSrefKVoltstd = "");
	virtual void insertRst(ListWdbeQBnkList& rst);
	virtual void updateRec(WdbeQBnkList* rec);
	virtual void updateRst(ListWdbeQBnkList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnkList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnkList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQBnkList: C++ wrapper for table TblWdbeQBnkList (MySQL database)
	*/
class MyTblWdbeQBnkList : public TblWdbeQBnkList, public Sbecore::MyTable {

public:
	MyTblWdbeQBnkList();
	~MyTblWdbeQBnkList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQBnkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnkList& rst);

	Sbecore::ubigint insertRec(WdbeQBnkList* rec);
	void insertRst(ListWdbeQBnkList& rst);
	void updateRec(WdbeQBnkList* rec);
	void updateRst(ListWdbeQBnkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnkList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQBnkList: C++ wrapper for table TblWdbeQBnkList (PgSQL database)
	*/
class PgTblWdbeQBnkList : public TblWdbeQBnkList, public Sbecore::PgTable {

public:
	PgTblWdbeQBnkList();
	~PgTblWdbeQBnkList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQBnkList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQBnkList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQBnkList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQBnkList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQBnkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnkList& rst);

	Sbecore::ubigint insertRec(WdbeQBnkList* rec);
	void insertRst(ListWdbeQBnkList& rst);
	void updateRec(WdbeQBnkList* rec);
	void updateRst(ListWdbeQBnkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnkList& rst);
};
#endif

#endif

