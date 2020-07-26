/**
	* \file WdbeQSilHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQSilHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSILHK1NVECTOR_H
#define WDBEQSILHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilHk1NVector: record of TblWdbeQSilHk1NVector
	*/
class WdbeQSilHk1NVector {

public:
	WdbeQSilHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSilHk1NVector: recordset of TblWdbeQSilHk1NVector
	*/
class ListWdbeQSilHk1NVector {

public:
	ListWdbeQSilHk1NVector();
	ListWdbeQSilHk1NVector(const ListWdbeQSilHk1NVector& src);
	~ListWdbeQSilHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilHk1NVector* rec);

	ListWdbeQSilHk1NVector& operator=(const ListWdbeQSilHk1NVector& src);

public:
	std::vector<WdbeQSilHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilHk1NVector: C++ wrapper for table TblWdbeQSilHk1NVector
	*/
class TblWdbeQSilHk1NVector {

public:
	TblWdbeQSilHk1NVector();
	virtual ~TblWdbeQSilHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilHk1NVector& rst, WdbeQSilHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSilHk1NVector& rst);
	virtual void updateRec(WdbeQSilHk1NVector* rec);
	virtual void updateRst(ListWdbeQSilHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilHk1NVector: C++ wrapper for table TblWdbeQSilHk1NVector (MySQL database)
	*/
class MyTblWdbeQSilHk1NVector : public TblWdbeQSilHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQSilHk1NVector();
	~MyTblWdbeQSilHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQSilHk1NVector* rec);
	void insertRst(ListWdbeQSilHk1NVector& rst);
	void updateRec(WdbeQSilHk1NVector* rec);
	void updateRst(ListWdbeQSilHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilHk1NVector: C++ wrapper for table TblWdbeQSilHk1NVector (PgSQL database)
	*/
class PgTblWdbeQSilHk1NVector : public TblWdbeQSilHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQSilHk1NVector();
	~PgTblWdbeQSilHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQSilHk1NVector* rec);
	void insertRst(ListWdbeQSilHk1NVector& rst);
	void updateRec(WdbeQSilHk1NVector* rec);
	void updateRst(ListWdbeQSilHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NVector& rst);
};
#endif

#endif

