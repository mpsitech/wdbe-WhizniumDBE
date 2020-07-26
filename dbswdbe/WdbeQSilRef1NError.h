/**
	* \file WdbeQSilRef1NError.h
	* Dbs and XML wrapper for table TblWdbeQSilRef1NError (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSILREF1NERROR_H
#define WDBEQSILREF1NERROR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilRef1NError: record of TblWdbeQSilRef1NError
	*/
class WdbeQSilRef1NError {

public:
	WdbeQSilRef1NError(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQSilRef1NError: recordset of TblWdbeQSilRef1NError
	*/
class ListWdbeQSilRef1NError {

public:
	ListWdbeQSilRef1NError();
	ListWdbeQSilRef1NError(const ListWdbeQSilRef1NError& src);
	~ListWdbeQSilRef1NError();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilRef1NError* rec);

	ListWdbeQSilRef1NError& operator=(const ListWdbeQSilRef1NError& src);

public:
	std::vector<WdbeQSilRef1NError*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilRef1NError: C++ wrapper for table TblWdbeQSilRef1NError
	*/
class TblWdbeQSilRef1NError {

public:
	TblWdbeQSilRef1NError();
	virtual ~TblWdbeQSilRef1NError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NError& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilRef1NError* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilRef1NError& rst, WdbeQSilRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQSilRef1NError& rst);
	virtual void updateRec(WdbeQSilRef1NError* rec);
	virtual void updateRst(ListWdbeQSilRef1NError& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NError** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilRef1NError: C++ wrapper for table TblWdbeQSilRef1NError (MySQL database)
	*/
class MyTblWdbeQSilRef1NError : public TblWdbeQSilRef1NError, public Sbecore::MyTable {

public:
	MyTblWdbeQSilRef1NError();
	~MyTblWdbeQSilRef1NError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NError* rec);
	void insertRst(ListWdbeQSilRef1NError& rst);
	void updateRec(WdbeQSilRef1NError* rec);
	void updateRst(ListWdbeQSilRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilRef1NError: C++ wrapper for table TblWdbeQSilRef1NError (PgSQL database)
	*/
class PgTblWdbeQSilRef1NError : public TblWdbeQSilRef1NError, public Sbecore::PgTable {

public:
	PgTblWdbeQSilRef1NError();
	~PgTblWdbeQSilRef1NError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilRef1NError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilRef1NError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NError* rec);
	void insertRst(ListWdbeQSilRef1NError& rst);
	void updateRec(WdbeQSilRef1NError* rec);
	void updateRst(ListWdbeQSilRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NError& rst);
};
#endif

#endif

