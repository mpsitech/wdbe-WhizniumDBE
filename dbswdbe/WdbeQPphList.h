/**
	* \file WdbeQPphList.h
	* Dbs and XML wrapper for table TblWdbeQPphList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPPHLIST_H
#define WDBEQPPHLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPphList: record of TblWdbeQPphList
	*/
class WdbeQPphList {

public:
	WdbeQPphList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMUnit;
	std::string stubRefWdbeMUnit;
	Sbecore::ubigint refWdbeMModule;
	std::string stubRefWdbeMModule;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPphList: recordset of TblWdbeQPphList
	*/
class ListWdbeQPphList {

public:
	ListWdbeQPphList();
	ListWdbeQPphList(const ListWdbeQPphList& src);
	~ListWdbeQPphList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPphList* rec);

	ListWdbeQPphList& operator=(const ListWdbeQPphList& src);

public:
	std::vector<WdbeQPphList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPphList: C++ wrapper for table TblWdbeQPphList
	*/
class TblWdbeQPphList {

public:
	TblWdbeQPphList();
	virtual ~TblWdbeQPphList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPphList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPphList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPphList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPphList& rst, WdbeQPphList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");
	virtual void insertRst(ListWdbeQPphList& rst);
	virtual void updateRec(WdbeQPphList* rec);
	virtual void updateRst(ListWdbeQPphList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPphList: C++ wrapper for table TblWdbeQPphList (MySQL database)
	*/
class MyTblWdbeQPphList : public TblWdbeQPphList, public Sbecore::MyTable {

public:
	MyTblWdbeQPphList();
	~MyTblWdbeQPphList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphList& rst);

	Sbecore::ubigint insertRec(WdbeQPphList* rec);
	void insertRst(ListWdbeQPphList& rst);
	void updateRec(WdbeQPphList* rec);
	void updateRst(ListWdbeQPphList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPphList: C++ wrapper for table TblWdbeQPphList (PgSQL database)
	*/
class PgTblWdbeQPphList : public TblWdbeQPphList, public Sbecore::PgTable {

public:
	PgTblWdbeQPphList();
	~PgTblWdbeQPphList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPphList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPphList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPphList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPphList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphList& rst);

	Sbecore::ubigint insertRec(WdbeQPphList* rec);
	void insertRst(ListWdbeQPphList& rst);
	void updateRec(WdbeQPphList* rec);
	void updateRst(ListWdbeQPphList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphList& rst);
};
#endif

#endif

