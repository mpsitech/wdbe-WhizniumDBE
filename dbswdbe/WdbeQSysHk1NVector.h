/**
	* \file WdbeQSysHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQSysHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSYSHK1NVECTOR_H
#define WDBEQSYSHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSysHk1NVector: record of TblWdbeQSysHk1NVector
	*/
class WdbeQSysHk1NVector {

public:
	WdbeQSysHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSysHk1NVector: recordset of TblWdbeQSysHk1NVector
	*/
class ListWdbeQSysHk1NVector {

public:
	ListWdbeQSysHk1NVector();
	ListWdbeQSysHk1NVector(const ListWdbeQSysHk1NVector& src);
	~ListWdbeQSysHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQSysHk1NVector* rec);

	ListWdbeQSysHk1NVector& operator=(const ListWdbeQSysHk1NVector& src);

public:
	std::vector<WdbeQSysHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSysHk1NVector: C++ wrapper for table TblWdbeQSysHk1NVector
	*/
class TblWdbeQSysHk1NVector {

public:
	TblWdbeQSysHk1NVector();
	virtual ~TblWdbeQSysHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSysHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSysHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQSysHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSysHk1NVector& rst, WdbeQSysHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSysHk1NVector& rst);
	virtual void updateRec(WdbeQSysHk1NVector* rec);
	virtual void updateRst(ListWdbeQSysHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSysHk1NVector: C++ wrapper for table TblWdbeQSysHk1NVector (MySQL database)
	*/
class MyTblWdbeQSysHk1NVector : public TblWdbeQSysHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQSysHk1NVector();
	~MyTblWdbeQSysHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQSysHk1NVector* rec);
	void insertRst(ListWdbeQSysHk1NVector& rst);
	void updateRec(WdbeQSysHk1NVector* rec);
	void updateRst(ListWdbeQSysHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSysHk1NVector: C++ wrapper for table TblWdbeQSysHk1NVector (PgSQL database)
	*/
class PgTblWdbeQSysHk1NVector : public TblWdbeQSysHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQSysHk1NVector();
	~PgTblWdbeQSysHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSysHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSysHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQSysHk1NVector* rec);
	void insertRst(ListWdbeQSysHk1NVector& rst);
	void updateRec(WdbeQSysHk1NVector* rec);
	void updateRst(ListWdbeQSysHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysHk1NVector& rst);
};
#endif

#endif

