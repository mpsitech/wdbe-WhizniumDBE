/**
	* \file WdbeQErrList.h
	* Dbs and XML wrapper for table TblWdbeQErrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQERRLIST_H
#define WDBEQERRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQErrList: record of TblWdbeQErrList
	*/
class WdbeQErrList {

public:
	WdbeQErrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Fullsref;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQErrList: recordset of TblWdbeQErrList
	*/
class ListWdbeQErrList {

public:
	ListWdbeQErrList();
	ListWdbeQErrList(const ListWdbeQErrList& src);
	~ListWdbeQErrList();

	void clear();
	unsigned int size() const;
	void append(WdbeQErrList* rec);

	ListWdbeQErrList& operator=(const ListWdbeQErrList& src);

public:
	std::vector<WdbeQErrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQErrList: C++ wrapper for table TblWdbeQErrList
	*/
class TblWdbeQErrList {

public:
	TblWdbeQErrList();
	virtual ~TblWdbeQErrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQErrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQErrList* rec);
	Sbecore::ubigint insertNewRec(WdbeQErrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQErrList& rst, WdbeQErrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWdbeQErrList& rst);
	virtual void updateRec(WdbeQErrList* rec);
	virtual void updateRst(ListWdbeQErrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQErrList: C++ wrapper for table TblWdbeQErrList (MySQL database)
	*/
class MyTblWdbeQErrList : public TblWdbeQErrList, public Sbecore::MyTable {

public:
	MyTblWdbeQErrList();
	~MyTblWdbeQErrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQErrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrList& rst);

	Sbecore::ubigint insertRec(WdbeQErrList* rec);
	void insertRst(ListWdbeQErrList& rst);
	void updateRec(WdbeQErrList* rec);
	void updateRst(ListWdbeQErrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQErrList: C++ wrapper for table TblWdbeQErrList (PgSQL database)
	*/
class PgTblWdbeQErrList : public TblWdbeQErrList, public Sbecore::PgTable {

public:
	PgTblWdbeQErrList();
	~PgTblWdbeQErrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQErrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQErrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQErrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQErrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQErrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrList& rst);

	Sbecore::ubigint insertRec(WdbeQErrList* rec);
	void insertRst(ListWdbeQErrList& rst);
	void updateRec(WdbeQErrList* rec);
	void updateRst(ListWdbeQErrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrList& rst);
};
#endif

#endif

