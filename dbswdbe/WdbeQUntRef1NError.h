/**
	* \file WdbeQUntRef1NError.h
	* Dbs and XML wrapper for table TblWdbeQUntRef1NError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTREF1NERROR_H
#define WDBEQUNTREF1NERROR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntRef1NError: record of TblWdbeQUntRef1NError
	*/
class WdbeQUntRef1NError {

public:
	WdbeQUntRef1NError(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntRef1NError: recordset of TblWdbeQUntRef1NError
	*/
class ListWdbeQUntRef1NError {

public:
	ListWdbeQUntRef1NError();
	ListWdbeQUntRef1NError(const ListWdbeQUntRef1NError& src);
	~ListWdbeQUntRef1NError();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntRef1NError* rec);

	ListWdbeQUntRef1NError& operator=(const ListWdbeQUntRef1NError& src);

public:
	std::vector<WdbeQUntRef1NError*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntRef1NError: C++ wrapper for table TblWdbeQUntRef1NError
	*/
class TblWdbeQUntRef1NError {

public:
	TblWdbeQUntRef1NError();
	virtual ~TblWdbeQUntRef1NError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NError& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntRef1NError* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntRef1NError& rst, WdbeQUntRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQUntRef1NError& rst);
	virtual void updateRec(WdbeQUntRef1NError* rec);
	virtual void updateRst(ListWdbeQUntRef1NError& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NError** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntRef1NError: C++ wrapper for table TblWdbeQUntRef1NError (MySQL database)
	*/
class MyTblWdbeQUntRef1NError : public TblWdbeQUntRef1NError, public Sbecore::MyTable {

public:
	MyTblWdbeQUntRef1NError();
	~MyTblWdbeQUntRef1NError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NError* rec);
	void insertRst(ListWdbeQUntRef1NError& rst);
	void updateRec(WdbeQUntRef1NError* rec);
	void updateRst(ListWdbeQUntRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntRef1NError: C++ wrapper for table TblWdbeQUntRef1NError (PgSQL database)
	*/
class PgTblWdbeQUntRef1NError : public TblWdbeQUntRef1NError, public Sbecore::PgTable {

public:
	PgTblWdbeQUntRef1NError();
	~PgTblWdbeQUntRef1NError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntRef1NError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntRef1NError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NError* rec);
	void insertRst(ListWdbeQUntRef1NError& rst);
	void updateRec(WdbeQUntRef1NError* rec);
	void updateRst(ListWdbeQUntRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NError& rst);
};
#endif

#endif
