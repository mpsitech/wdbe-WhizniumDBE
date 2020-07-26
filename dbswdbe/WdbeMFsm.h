/**
	* \file WdbeMFsm.h
	* database access for table TblWdbeMFsm (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMFSM_H
#define WDBEMFSM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMFsm: record of TblWdbeMFsm
	*/
class WdbeMFsm {

public:
	WdbeMFsm(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMProcess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMProcess;

public:
	bool operator==(const WdbeMFsm& comp);
	bool operator!=(const WdbeMFsm& comp);
};

/**
	* ListWdbeMFsm: recordset of TblWdbeMFsm
	*/
class ListWdbeMFsm {

public:
	ListWdbeMFsm();
	ListWdbeMFsm(const ListWdbeMFsm& src);
	~ListWdbeMFsm();

	void clear();
	unsigned int size() const;
	void append(WdbeMFsm* rec);

	WdbeMFsm* operator[](const Sbecore::uint ix);
	ListWdbeMFsm& operator=(const ListWdbeMFsm& src);
	bool operator==(const ListWdbeMFsm& comp);
	bool operator!=(const ListWdbeMFsm& comp);

public:
	std::vector<WdbeMFsm*> nodes;
};

/**
	* TblWdbeMFsm: C++ wrapper for table TblWdbeMFsm
	*/
class TblWdbeMFsm {

public:

public:
	TblWdbeMFsm();
	virtual ~TblWdbeMFsm();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMFsm** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsm& rst);

	virtual Sbecore::ubigint insertRec(WdbeMFsm* rec);
	Sbecore::ubigint insertNewRec(WdbeMFsm** rec = NULL, const Sbecore::ubigint refWdbeMProcess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMFsm& rst, WdbeMFsm** rec = NULL, const Sbecore::ubigint refWdbeMProcess = 0);
	virtual void insertRst(ListWdbeMFsm& rst, bool transact = false);
	virtual void updateRec(WdbeMFsm* rec);
	virtual void updateRst(ListWdbeMFsm& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsm** rec);
	virtual bool loadRecByPrc(Sbecore::ubigint refWdbeMProcess, WdbeMFsm** rec);
	virtual Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint refWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMFsm& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMFsm: C++ wrapper for table TblWdbeMFsm (MySQL database)
	*/
class MyTblWdbeMFsm : public TblWdbeMFsm, public Sbecore::MyTable {

public:
	MyTblWdbeMFsm();
	~MyTblWdbeMFsm();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFsm** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsm& rst);

	Sbecore::ubigint insertRec(WdbeMFsm* rec);
	void insertRst(ListWdbeMFsm& rst, bool transact = false);
	void updateRec(WdbeMFsm* rec);
	void updateRst(ListWdbeMFsm& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsm** rec);
	bool loadRecByPrc(Sbecore::ubigint refWdbeMProcess, WdbeMFsm** rec);
	Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint refWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMFsm: C++ wrapper for table TblWdbeMFsm (PgSQL database)
	*/
class PgTblWdbeMFsm : public TblWdbeMFsm, public Sbecore::PgTable {

public:
	PgTblWdbeMFsm();
	~PgTblWdbeMFsm();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMFsm** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMFsm& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMFsm** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFsm** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFsm& rst);

	Sbecore::ubigint insertRec(WdbeMFsm* rec);
	void insertRst(ListWdbeMFsm& rst, bool transact = false);
	void updateRec(WdbeMFsm* rec);
	void updateRst(ListWdbeMFsm& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFsm** rec);
	bool loadRecByPrc(Sbecore::ubigint refWdbeMProcess, WdbeMFsm** rec);
	Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint refWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

