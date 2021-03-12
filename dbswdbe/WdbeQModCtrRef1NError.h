/**
	* \file WdbeQModCtrRef1NError.h
	* Dbs and XML wrapper for table TblWdbeQModCtrRef1NError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRREF1NERROR_H
#define WDBEQMODCTRREF1NERROR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCtrRef1NError: record of TblWdbeQModCtrRef1NError
	*/
class WdbeQModCtrRef1NError {

public:
	WdbeQModCtrRef1NError(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModCtrRef1NError: recordset of TblWdbeQModCtrRef1NError
	*/
class ListWdbeQModCtrRef1NError {

public:
	ListWdbeQModCtrRef1NError();
	ListWdbeQModCtrRef1NError(const ListWdbeQModCtrRef1NError& src);
	~ListWdbeQModCtrRef1NError();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCtrRef1NError* rec);

	ListWdbeQModCtrRef1NError& operator=(const ListWdbeQModCtrRef1NError& src);

public:
	std::vector<WdbeQModCtrRef1NError*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCtrRef1NError: C++ wrapper for table TblWdbeQModCtrRef1NError
	*/
class TblWdbeQModCtrRef1NError {

public:
	TblWdbeQModCtrRef1NError();
	virtual ~TblWdbeQModCtrRef1NError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NError& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCtrRef1NError* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCtrRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCtrRef1NError& rst, WdbeQModCtrRef1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQModCtrRef1NError& rst);
	virtual void updateRec(WdbeQModCtrRef1NError* rec);
	virtual void updateRst(ListWdbeQModCtrRef1NError& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NError** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCtrRef1NError: C++ wrapper for table TblWdbeQModCtrRef1NError (MySQL database)
	*/
class MyTblWdbeQModCtrRef1NError : public TblWdbeQModCtrRef1NError, public Sbecore::MyTable {

public:
	MyTblWdbeQModCtrRef1NError();
	~MyTblWdbeQModCtrRef1NError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrRef1NError* rec);
	void insertRst(ListWdbeQModCtrRef1NError& rst);
	void updateRec(WdbeQModCtrRef1NError* rec);
	void updateRst(ListWdbeQModCtrRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCtrRef1NError: C++ wrapper for table TblWdbeQModCtrRef1NError (PgSQL database)
	*/
class PgTblWdbeQModCtrRef1NError : public TblWdbeQModCtrRef1NError, public Sbecore::PgTable {

public:
	PgTblWdbeQModCtrRef1NError();
	~PgTblWdbeQModCtrRef1NError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCtrRef1NError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCtrRef1NError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NError& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrRef1NError* rec);
	void insertRst(ListWdbeQModCtrRef1NError& rst);
	void updateRec(WdbeQModCtrRef1NError* rec);
	void updateRst(ListWdbeQModCtrRef1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NError& rst);
};
#endif

#endif
