/**
	* \file WdbeQPrcFsmHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQPrcFsmHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Feb 2024
  */
// IP header --- ABOVE

#ifndef WDBEQPRCFSMHK1NVECTOR_H
#define WDBEQPRCFSMHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcFsmHk1NVector: record of TblWdbeQPrcFsmHk1NVector
	*/
class WdbeQPrcFsmHk1NVector {

public:
	WdbeQPrcFsmHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcFsmHk1NVector: recordset of TblWdbeQPrcFsmHk1NVector
	*/
class ListWdbeQPrcFsmHk1NVector {

public:
	ListWdbeQPrcFsmHk1NVector();
	ListWdbeQPrcFsmHk1NVector(const ListWdbeQPrcFsmHk1NVector& src);
	~ListWdbeQPrcFsmHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcFsmHk1NVector* rec);

	ListWdbeQPrcFsmHk1NVector& operator=(const ListWdbeQPrcFsmHk1NVector& src);

public:
	std::vector<WdbeQPrcFsmHk1NVector*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcFsmHk1NVector: C++ wrapper for table TblWdbeQPrcFsmHk1NVector
	*/
class TblWdbeQPrcFsmHk1NVector {

public:
	TblWdbeQPrcFsmHk1NVector();
	virtual ~TblWdbeQPrcFsmHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcFsmHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcFsmHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcFsmHk1NVector& rst, WdbeQPrcFsmHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQPrcFsmHk1NVector& rst);
	virtual void updateRec(WdbeQPrcFsmHk1NVector* rec);
	virtual void updateRst(ListWdbeQPrcFsmHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcFsmHk1NVector: C++ wrapper for table TblWdbeQPrcFsmHk1NVector (MySQL database)
	*/
class MyTblWdbeQPrcFsmHk1NVector : public TblWdbeQPrcFsmHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcFsmHk1NVector();
	~MyTblWdbeQPrcFsmHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQPrcFsmHk1NVector* rec);
	void insertRst(ListWdbeQPrcFsmHk1NVector& rst);
	void updateRec(WdbeQPrcFsmHk1NVector* rec);
	void updateRst(ListWdbeQPrcFsmHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcFsmHk1NVector: C++ wrapper for table TblWdbeQPrcFsmHk1NVector (PgSQL database)
	*/
class PgTblWdbeQPrcFsmHk1NVector : public TblWdbeQPrcFsmHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcFsmHk1NVector();
	~PgTblWdbeQPrcFsmHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcFsmHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcFsmHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQPrcFsmHk1NVector* rec);
	void insertRst(ListWdbeQPrcFsmHk1NVector& rst);
	void updateRec(WdbeQPrcFsmHk1NVector* rec);
	void updateRst(ListWdbeQPrcFsmHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmHk1NVector& rst);
};
#endif

#endif
