/**
	* \file WdbeMSession.h
	* database access for table TblWdbeMSession (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMSESSION_H
#define WDBEMSESSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMSession: record of TblWdbeMSession
	*/
class WdbeMSession {

public:
	WdbeMSession(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::uint start;
	Sbecore::uint stop;
	std::string Ip;

public:
	bool operator==(const WdbeMSession& comp);
	bool operator!=(const WdbeMSession& comp);
};

/**
	* ListWdbeMSession: recordset of TblWdbeMSession
	*/
class ListWdbeMSession {

public:
	ListWdbeMSession();
	ListWdbeMSession(const ListWdbeMSession& src);
	~ListWdbeMSession();

	void clear();
	unsigned int size() const;
	void append(WdbeMSession* rec);

	WdbeMSession* operator[](const Sbecore::uint ix);
	ListWdbeMSession& operator=(const ListWdbeMSession& src);
	bool operator==(const ListWdbeMSession& comp);
	bool operator!=(const ListWdbeMSession& comp);

public:
	std::vector<WdbeMSession*> nodes;
};

/**
	* TblWdbeMSession: C++ wrapper for table TblWdbeMSession
	*/
class TblWdbeMSession {

public:

public:
	TblWdbeMSession();
	virtual ~TblWdbeMSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSession& rst);

	virtual Sbecore::ubigint insertRec(WdbeMSession* rec);
	Sbecore::ubigint insertNewRec(WdbeMSession** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMSession& rst, WdbeMSession** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	virtual void insertRst(ListWdbeMSession& rst, bool transact = false);
	virtual void updateRec(WdbeMSession* rec);
	virtual void updateRst(ListWdbeMSession& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMSession** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeMSession& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMSession: C++ wrapper for table TblWdbeMSession (MySQL database)
	*/
class MyTblWdbeMSession : public TblWdbeMSession, public Sbecore::MyTable {

public:
	MyTblWdbeMSession();
	~MyTblWdbeMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSession& rst);

	Sbecore::ubigint insertRec(WdbeMSession* rec);
	void insertRst(ListWdbeMSession& rst, bool transact = false);
	void updateRec(WdbeMSession* rec);
	void updateRst(ListWdbeMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeMSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMSession: C++ wrapper for table TblWdbeMSession (PgSQL database)
	*/
class PgTblWdbeMSession : public TblWdbeMSession, public Sbecore::PgTable {

public:
	PgTblWdbeMSession();
	~PgTblWdbeMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSession& rst);

	Sbecore::ubigint insertRec(WdbeMSession* rec);
	void insertRst(ListWdbeMSession& rst, bool transact = false);
	void updateRec(WdbeMSession* rec);
	void updateRst(ListWdbeMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeMSession& rst);
};
#endif

#endif

