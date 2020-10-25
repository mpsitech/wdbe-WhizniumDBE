/**
	* \file WdbeQUntHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQUntHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNTHK1NVECTOR_H
#define WDBEQUNTHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntHk1NVector: record of TblWdbeQUntHk1NVector
	*/
class WdbeQUntHk1NVector {

public:
	WdbeQUntHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntHk1NVector: recordset of TblWdbeQUntHk1NVector
	*/
class ListWdbeQUntHk1NVector {

public:
	ListWdbeQUntHk1NVector();
	ListWdbeQUntHk1NVector(const ListWdbeQUntHk1NVector& src);
	~ListWdbeQUntHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntHk1NVector* rec);

	ListWdbeQUntHk1NVector& operator=(const ListWdbeQUntHk1NVector& src);

public:
	std::vector<WdbeQUntHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntHk1NVector: C++ wrapper for table TblWdbeQUntHk1NVector
	*/
class TblWdbeQUntHk1NVector {

public:
	TblWdbeQUntHk1NVector();
	virtual ~TblWdbeQUntHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntHk1NVector& rst, WdbeQUntHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUntHk1NVector& rst);
	virtual void updateRec(WdbeQUntHk1NVector* rec);
	virtual void updateRst(ListWdbeQUntHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntHk1NVector: C++ wrapper for table TblWdbeQUntHk1NVector (MySQL database)
	*/
class MyTblWdbeQUntHk1NVector : public TblWdbeQUntHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQUntHk1NVector();
	~MyTblWdbeQUntHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQUntHk1NVector* rec);
	void insertRst(ListWdbeQUntHk1NVector& rst);
	void updateRec(WdbeQUntHk1NVector* rec);
	void updateRst(ListWdbeQUntHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntHk1NVector: C++ wrapper for table TblWdbeQUntHk1NVector (PgSQL database)
	*/
class PgTblWdbeQUntHk1NVector : public TblWdbeQUntHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQUntHk1NVector();
	~PgTblWdbeQUntHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQUntHk1NVector* rec);
	void insertRst(ListWdbeQUntHk1NVector& rst);
	void updateRec(WdbeQUntHk1NVector* rec);
	void updateRst(ListWdbeQUntHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NVector& rst);
};
#endif

#endif

