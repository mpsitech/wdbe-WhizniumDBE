/**
	* \file WdbeJMVersionState.h
	* database access for table TblWdbeJMVersionState (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEJMVERSIONSTATE_H
#define WDBEJMVERSIONSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJMVersionState: record of TblWdbeJMVersionState
	*/
class WdbeJMVersionState {

public:
	WdbeJMVersionState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMVersion;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WdbeJMVersionState& comp);
	bool operator!=(const WdbeJMVersionState& comp);
};

/**
	* ListWdbeJMVersionState: recordset of TblWdbeJMVersionState
	*/
class ListWdbeJMVersionState {

public:
	ListWdbeJMVersionState();
	ListWdbeJMVersionState(const ListWdbeJMVersionState& src);
	~ListWdbeJMVersionState();

	void clear();
	unsigned int size() const;
	void append(WdbeJMVersionState* rec);

	WdbeJMVersionState* operator[](const Sbecore::uint ix);
	ListWdbeJMVersionState& operator=(const ListWdbeJMVersionState& src);
	bool operator==(const ListWdbeJMVersionState& comp);
	bool operator!=(const ListWdbeJMVersionState& comp);

public:
	std::vector<WdbeJMVersionState*> nodes;
};

/**
	* TblWdbeJMVersionState: C++ wrapper for table TblWdbeJMVersionState
	*/
class TblWdbeJMVersionState {

public:

public:
	TblWdbeJMVersionState();
	virtual ~TblWdbeJMVersionState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJMVersionState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMVersionState& rst);

	virtual Sbecore::ubigint insertRec(WdbeJMVersionState* rec);
	Sbecore::ubigint insertNewRec(WdbeJMVersionState** rec = NULL, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeJMVersionState& rst, WdbeJMVersionState** rec = NULL, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWdbeJMVersionState& rst, bool transact = false);
	virtual void updateRec(WdbeJMVersionState* rec);
	virtual void updateRst(ListWdbeJMVersionState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJMVersionState** rec);
	virtual bool loadRecByVerSta(Sbecore::ubigint refWdbeMVersion, Sbecore::uint x1Start, WdbeJMVersionState** rec);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeJMVersionState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJMVersionState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJMVersionState: C++ wrapper for table TblWdbeJMVersionState (MySQL database)
	*/
class MyTblWdbeJMVersionState : public TblWdbeJMVersionState, public Sbecore::MyTable {

public:
	MyTblWdbeJMVersionState();
	~MyTblWdbeJMVersionState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMVersionState& rst);

	Sbecore::ubigint insertRec(WdbeJMVersionState* rec);
	void insertRst(ListWdbeJMVersionState& rst, bool transact = false);
	void updateRec(WdbeJMVersionState* rec);
	void updateRst(ListWdbeJMVersionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMVersionState** rec);
	bool loadRecByVerSta(Sbecore::ubigint refWdbeMVersion, Sbecore::uint x1Start, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeJMVersionState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJMVersionState: C++ wrapper for table TblWdbeJMVersionState (PgSQL database)
	*/
class PgTblWdbeJMVersionState : public TblWdbeJMVersionState, public Sbecore::PgTable {

public:
	PgTblWdbeJMVersionState();
	~PgTblWdbeJMVersionState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJMVersionState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJMVersionState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMVersionState& rst);

	Sbecore::ubigint insertRec(WdbeJMVersionState* rec);
	void insertRst(ListWdbeJMVersionState& rst, bool transact = false);
	void updateRec(WdbeJMVersionState* rec);
	void updateRst(ListWdbeJMVersionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMVersionState** rec);
	bool loadRecByVerSta(Sbecore::ubigint refWdbeMVersion, Sbecore::uint x1Start, WdbeJMVersionState** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeJMVersionState& rst);
};
#endif

#endif
