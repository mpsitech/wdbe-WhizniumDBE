/**
	* \file WdbeMFsmstate.h
	* database access for table TblWdbeMFsmstate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMFSMSTATE_H
#define WDBEMFSMSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMFsmstate: record of TblWdbeMFsmstate
	*/
class WdbeMFsmstate {

public:
	WdbeMFsmstate(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCFsmstate = 0, const Sbecore::ubigint fsmRefWdbeMFsm = 0, const Sbecore::uint fsmNum = 0, const std::string sref = "", const bool Extip = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCFsmstate;
	Sbecore::ubigint fsmRefWdbeMFsm;
	Sbecore::uint fsmNum;
	std::string sref;
	bool Extip;
	std::string Comment;

public:
	bool operator==(const WdbeMFsmstate& comp);
	bool operator!=(const WdbeMFsmstate& comp);
};

/**
	* ListWdbeMFsmstate: recordset of TblWdbeMFsmstate
	*/
class ListWdbeMFsmstate {

public:
	ListWdbeMFsmstate();
	ListWdbeMFsmstate(const ListWdbeMFsmstate& src);
	~ListWdbeMFsmstate();

	void clear();
	unsigned int size() const;
	void append(WdbeMFsmstate* rec);

	WdbeMFsmstate* operator[](const Sbecore::uint ix);
	ListWdbeMFsmstate& operator=(const ListWdbeMFsmstate& src);
	bool operator==(const ListWdbeMFsmstate& comp);
	bool operator!=(const ListWdbeMFsmstate& comp);

public:
	std::vector<WdbeMFsmstate*> nodes;
};

/**
	* TblWdbeMFsmstate: C++ wrapper for table TblWdbeMFsmstate
	*/
class TblWdbeMFsmstate {

public:

public:
	TblWdbeMFsmstate();
	virtual ~TblWdbeMFsmstate();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMFsmstate** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsmstate& rst);

	virtual Sbecore::ubigint insertRec(WdbeMFsmstate* rec);
	Sbecore::ubigint insertNewRec(WdbeMFsmstate** rec = NULL, const Sbecore::ubigint refWdbeCFsmstate = 0, const Sbecore::ubigint fsmRefWdbeMFsm = 0, const Sbecore::uint fsmNum = 0, const std::string sref = "", const bool Extip = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMFsmstate& rst, WdbeMFsmstate** rec = NULL, const Sbecore::ubigint refWdbeCFsmstate = 0, const Sbecore::ubigint fsmRefWdbeMFsm = 0, const Sbecore::uint fsmNum = 0, const std::string sref = "", const bool Extip = false, const std::string Comment = "");
	virtual void insertRst(ListWdbeMFsmstate& rst, bool transact = false);
	virtual void updateRec(WdbeMFsmstate* rec);
	virtual void updateRst(ListWdbeMFsmstate& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsmstate** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, ListWdbeMFsmstate& rst);
	virtual Sbecore::ubigint loadRstByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, ListWdbeMFsmstate& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMFsmstate& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMFsmstate: C++ wrapper for table TblWdbeMFsmstate (MySQL database)
	*/
class MyTblWdbeMFsmstate : public TblWdbeMFsmstate, public Sbecore::MyTable {

public:
	MyTblWdbeMFsmstate();
	~MyTblWdbeMFsmstate();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsmstate& rst);

	Sbecore::ubigint insertRec(WdbeMFsmstate* rec);
	void insertRst(ListWdbeMFsmstate& rst, bool transact = false);
	void updateRec(WdbeMFsmstate* rec);
	void updateRst(ListWdbeMFsmstate& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, ListWdbeMFsmstate& rst);
	Sbecore::ubigint loadRstByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, ListWdbeMFsmstate& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMFsmstate: C++ wrapper for table TblWdbeMFsmstate (PgSQL database)
	*/
class PgTblWdbeMFsmstate : public TblWdbeMFsmstate, public Sbecore::PgTable {

public:
	PgTblWdbeMFsmstate();
	~PgTblWdbeMFsmstate();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMFsmstate& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMFsmstate& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsmstate& rst);

	Sbecore::ubigint insertRec(WdbeMFsmstate* rec);
	void insertRst(ListWdbeMFsmstate& rst, bool transact = false);
	void updateRec(WdbeMFsmstate* rec);
	void updateRst(ListWdbeMFsmstate& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsmstate** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFsmstate, const bool append, ListWdbeMFsmstate& rst);
	Sbecore::ubigint loadRstByFsm(Sbecore::ubigint fsmRefWdbeMFsm, const bool append, ListWdbeMFsmstate& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

