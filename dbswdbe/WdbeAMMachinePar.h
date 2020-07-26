/**
	* \file WdbeAMMachinePar.h
	* database access for table TblWdbeAMMachinePar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAMMACHINEPAR_H
#define WDBEAMMACHINEPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMMachinePar: record of TblWdbeAMMachinePar
	*/
class WdbeAMMachinePar {

public:
	WdbeAMMachinePar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMMachine;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WdbeAMMachinePar& comp);
	bool operator!=(const WdbeAMMachinePar& comp);
};

/**
	* ListWdbeAMMachinePar: recordset of TblWdbeAMMachinePar
	*/
class ListWdbeAMMachinePar {

public:
	ListWdbeAMMachinePar();
	ListWdbeAMMachinePar(const ListWdbeAMMachinePar& src);
	~ListWdbeAMMachinePar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMMachinePar* rec);

	WdbeAMMachinePar* operator[](const Sbecore::uint ix);
	ListWdbeAMMachinePar& operator=(const ListWdbeAMMachinePar& src);
	bool operator==(const ListWdbeAMMachinePar& comp);
	bool operator!=(const ListWdbeAMMachinePar& comp);

public:
	std::vector<WdbeAMMachinePar*> nodes;
};

/**
	* TblWdbeAMMachinePar: C++ wrapper for table TblWdbeAMMachinePar
	*/
class TblWdbeAMMachinePar {

public:

public:
	TblWdbeAMMachinePar();
	virtual ~TblWdbeAMMachinePar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachinePar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachinePar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMMachinePar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMMachinePar** rec = NULL, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMMachinePar& rst, WdbeAMMachinePar** rec = NULL, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMMachinePar& rst, bool transact = false);
	virtual void updateRec(WdbeAMMachinePar* rec);
	virtual void updateRst(ListWdbeAMMachinePar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachinePar** rec);
	virtual Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachinePar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMMachinePar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMMachinePar: C++ wrapper for table TblWdbeAMMachinePar (MySQL database)
	*/
class MyTblWdbeAMMachinePar : public TblWdbeAMMachinePar, public Sbecore::MyTable {

public:
	MyTblWdbeAMMachinePar();
	~MyTblWdbeAMMachinePar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachinePar& rst);

	Sbecore::ubigint insertRec(WdbeAMMachinePar* rec);
	void insertRst(ListWdbeAMMachinePar& rst, bool transact = false);
	void updateRec(WdbeAMMachinePar* rec);
	void updateRst(ListWdbeAMMachinePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachinePar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMMachinePar: C++ wrapper for table TblWdbeAMMachinePar (PgSQL database)
	*/
class PgTblWdbeAMMachinePar : public TblWdbeAMMachinePar, public Sbecore::PgTable {

public:
	PgTblWdbeAMMachinePar();
	~PgTblWdbeAMMachinePar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMMachinePar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMMachinePar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachinePar& rst);

	Sbecore::ubigint insertRec(WdbeAMMachinePar* rec);
	void insertRst(ListWdbeAMMachinePar& rst, bool transact = false);
	void updateRec(WdbeAMMachinePar* rec);
	void updateRst(ListWdbeAMMachinePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachinePar** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachinePar& rst);
};
#endif

#endif

