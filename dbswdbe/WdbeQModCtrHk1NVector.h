/**
	* \file WdbeQModCtrHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQModCtrHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRHK1NVECTOR_H
#define WDBEQMODCTRHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCtrHk1NVector: record of TblWdbeQModCtrHk1NVector
	*/
class WdbeQModCtrHk1NVector {

public:
	WdbeQModCtrHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQModCtrHk1NVector: recordset of TblWdbeQModCtrHk1NVector
	*/
class ListWdbeQModCtrHk1NVector {

public:
	ListWdbeQModCtrHk1NVector();
	ListWdbeQModCtrHk1NVector(const ListWdbeQModCtrHk1NVector& src);
	~ListWdbeQModCtrHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCtrHk1NVector* rec);

	ListWdbeQModCtrHk1NVector& operator=(const ListWdbeQModCtrHk1NVector& src);

public:
	std::vector<WdbeQModCtrHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCtrHk1NVector: C++ wrapper for table TblWdbeQModCtrHk1NVector
	*/
class TblWdbeQModCtrHk1NVector {

public:
	TblWdbeQModCtrHk1NVector();
	virtual ~TblWdbeQModCtrHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCtrHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCtrHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCtrHk1NVector& rst, WdbeQModCtrHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModCtrHk1NVector& rst);
	virtual void updateRec(WdbeQModCtrHk1NVector* rec);
	virtual void updateRst(ListWdbeQModCtrHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCtrHk1NVector: C++ wrapper for table TblWdbeQModCtrHk1NVector (MySQL database)
	*/
class MyTblWdbeQModCtrHk1NVector : public TblWdbeQModCtrHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQModCtrHk1NVector();
	~MyTblWdbeQModCtrHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrHk1NVector* rec);
	void insertRst(ListWdbeQModCtrHk1NVector& rst);
	void updateRec(WdbeQModCtrHk1NVector* rec);
	void updateRst(ListWdbeQModCtrHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCtrHk1NVector: C++ wrapper for table TblWdbeQModCtrHk1NVector (PgSQL database)
	*/
class PgTblWdbeQModCtrHk1NVector : public TblWdbeQModCtrHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQModCtrHk1NVector();
	~PgTblWdbeQModCtrHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCtrHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCtrHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrHk1NVector* rec);
	void insertRst(ListWdbeQModCtrHk1NVector& rst);
	void updateRec(WdbeQModCtrHk1NVector* rec);
	void updateRst(ListWdbeQModCtrHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrHk1NVector& rst);
};
#endif

#endif

