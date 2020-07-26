/**
	* \file WdbeJMCoreversionState.h
	* database access for table TblWdbeJMCoreversionState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEJMCOREVERSIONSTATE_H
#define WDBEJMCOREVERSIONSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJMCoreversionState: record of TblWdbeJMCoreversionState
	*/
class WdbeJMCoreversionState {

public:
	WdbeJMCoreversionState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMCoreversion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMCoreversion;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WdbeJMCoreversionState& comp);
	bool operator!=(const WdbeJMCoreversionState& comp);
};

/**
	* ListWdbeJMCoreversionState: recordset of TblWdbeJMCoreversionState
	*/
class ListWdbeJMCoreversionState {

public:
	ListWdbeJMCoreversionState();
	ListWdbeJMCoreversionState(const ListWdbeJMCoreversionState& src);
	~ListWdbeJMCoreversionState();

	void clear();
	unsigned int size() const;
	void append(WdbeJMCoreversionState* rec);

	WdbeJMCoreversionState* operator[](const Sbecore::uint ix);
	ListWdbeJMCoreversionState& operator=(const ListWdbeJMCoreversionState& src);
	bool operator==(const ListWdbeJMCoreversionState& comp);
	bool operator!=(const ListWdbeJMCoreversionState& comp);

public:
	std::vector<WdbeJMCoreversionState*> nodes;
};

/**
	* TblWdbeJMCoreversionState: C++ wrapper for table TblWdbeJMCoreversionState
	*/
class TblWdbeJMCoreversionState {

public:

public:
	TblWdbeJMCoreversionState();
	virtual ~TblWdbeJMCoreversionState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJMCoreversionState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMCoreversionState& rst);

	virtual Sbecore::ubigint insertRec(WdbeJMCoreversionState* rec);
	Sbecore::ubigint insertNewRec(WdbeJMCoreversionState** rec = NULL, const Sbecore::ubigint refWdbeMCoreversion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeJMCoreversionState& rst, WdbeJMCoreversionState** rec = NULL, const Sbecore::ubigint refWdbeMCoreversion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	virtual void updateRec(WdbeJMCoreversionState* rec);
	virtual void updateRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJMCoreversionState** rec);
	virtual bool loadRecByCvrSta(Sbecore::ubigint refWdbeMCoreversion, Sbecore::uint x1Start, WdbeJMCoreversionState** rec);
	virtual Sbecore::ubigint loadRefsByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, ListWdbeJMCoreversionState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJMCoreversionState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJMCoreversionState: C++ wrapper for table TblWdbeJMCoreversionState (MySQL database)
	*/
class MyTblWdbeJMCoreversionState : public TblWdbeJMCoreversionState, public Sbecore::MyTable {

public:
	MyTblWdbeJMCoreversionState();
	~MyTblWdbeJMCoreversionState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMCoreversionState& rst);

	Sbecore::ubigint insertRec(WdbeJMCoreversionState* rec);
	void insertRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	void updateRec(WdbeJMCoreversionState* rec);
	void updateRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMCoreversionState** rec);
	bool loadRecByCvrSta(Sbecore::ubigint refWdbeMCoreversion, Sbecore::uint x1Start, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRefsByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, ListWdbeJMCoreversionState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJMCoreversionState: C++ wrapper for table TblWdbeJMCoreversionState (PgSQL database)
	*/
class PgTblWdbeJMCoreversionState : public TblWdbeJMCoreversionState, public Sbecore::PgTable {

public:
	PgTblWdbeJMCoreversionState();
	~PgTblWdbeJMCoreversionState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJMCoreversionState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJMCoreversionState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMCoreversionState& rst);

	Sbecore::ubigint insertRec(WdbeJMCoreversionState* rec);
	void insertRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	void updateRec(WdbeJMCoreversionState* rec);
	void updateRst(ListWdbeJMCoreversionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMCoreversionState** rec);
	bool loadRecByCvrSta(Sbecore::ubigint refWdbeMCoreversion, Sbecore::uint x1Start, WdbeJMCoreversionState** rec);
	Sbecore::ubigint loadRefsByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint refWdbeMCoreversion, const bool append, ListWdbeJMCoreversionState& rst);
};
#endif

#endif

