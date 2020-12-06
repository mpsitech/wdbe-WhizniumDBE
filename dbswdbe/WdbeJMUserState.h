/**
	* \file WdbeJMUserState.h
	* database access for table TblWdbeJMUserState (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEJMUSERSTATE_H
#define WDBEJMUSERSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJMUserState: record of TblWdbeJMUserState
	*/
class WdbeJMUserState {

public:
	WdbeJMUserState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WdbeJMUserState& comp);
	bool operator!=(const WdbeJMUserState& comp);
};

/**
	* ListWdbeJMUserState: recordset of TblWdbeJMUserState
	*/
class ListWdbeJMUserState {

public:
	ListWdbeJMUserState();
	ListWdbeJMUserState(const ListWdbeJMUserState& src);
	~ListWdbeJMUserState();

	void clear();
	unsigned int size() const;
	void append(WdbeJMUserState* rec);

	WdbeJMUserState* operator[](const Sbecore::uint ix);
	ListWdbeJMUserState& operator=(const ListWdbeJMUserState& src);
	bool operator==(const ListWdbeJMUserState& comp);
	bool operator!=(const ListWdbeJMUserState& comp);

public:
	std::vector<WdbeJMUserState*> nodes;
};

/**
	* TblWdbeJMUserState: C++ wrapper for table TblWdbeJMUserState
	*/
class TblWdbeJMUserState {

public:

public:
	TblWdbeJMUserState();
	virtual ~TblWdbeJMUserState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJMUserState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMUserState& rst);

	virtual Sbecore::ubigint insertRec(WdbeJMUserState* rec);
	Sbecore::ubigint insertNewRec(WdbeJMUserState** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeJMUserState& rst, WdbeJMUserState** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWdbeJMUserState& rst, bool transact = false);
	virtual void updateRec(WdbeJMUserState* rec);
	virtual void updateRst(ListWdbeJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJMUserState** rec);
	virtual bool loadRecByUsrSta(Sbecore::ubigint refWdbeMUser, Sbecore::uint x1Start, WdbeJMUserState** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeJMUserState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJMUserState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJMUserState: C++ wrapper for table TblWdbeJMUserState (MySQL database)
	*/
class MyTblWdbeJMUserState : public TblWdbeJMUserState, public Sbecore::MyTable {

public:
	MyTblWdbeJMUserState();
	~MyTblWdbeJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMUserState& rst);

	Sbecore::ubigint insertRec(WdbeJMUserState* rec);
	void insertRst(ListWdbeJMUserState& rst, bool transact = false);
	void updateRec(WdbeJMUserState* rec);
	void updateRst(ListWdbeJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWdbeMUser, Sbecore::uint x1Start, WdbeJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeJMUserState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJMUserState: C++ wrapper for table TblWdbeJMUserState (PgSQL database)
	*/
class PgTblWdbeJMUserState : public TblWdbeJMUserState, public Sbecore::PgTable {

public:
	PgTblWdbeJMUserState();
	~PgTblWdbeJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJMUserState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJMUserState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMUserState& rst);

	Sbecore::ubigint insertRec(WdbeJMUserState* rec);
	void insertRst(ListWdbeJMUserState& rst, bool transact = false);
	void updateRec(WdbeJMUserState* rec);
	void updateRst(ListWdbeJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWdbeMUser, Sbecore::uint x1Start, WdbeJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeJMUserState& rst);
};
#endif

#endif
