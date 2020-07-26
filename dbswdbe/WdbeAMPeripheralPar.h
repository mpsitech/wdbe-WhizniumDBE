/**
	* \file WdbeAMPeripheralPar.h
	* database access for table TblWdbeAMPeripheralPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAMPERIPHERALPAR_H
#define WDBEAMPERIPHERALPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMPeripheralPar: record of TblWdbeAMPeripheralPar
	*/
class WdbeAMPeripheralPar {

public:
	WdbeAMPeripheralPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMPeripheral = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMPeripheral;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WdbeAMPeripheralPar& comp);
	bool operator!=(const WdbeAMPeripheralPar& comp);
};

/**
	* ListWdbeAMPeripheralPar: recordset of TblWdbeAMPeripheralPar
	*/
class ListWdbeAMPeripheralPar {

public:
	ListWdbeAMPeripheralPar();
	ListWdbeAMPeripheralPar(const ListWdbeAMPeripheralPar& src);
	~ListWdbeAMPeripheralPar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMPeripheralPar* rec);

	WdbeAMPeripheralPar* operator[](const Sbecore::uint ix);
	ListWdbeAMPeripheralPar& operator=(const ListWdbeAMPeripheralPar& src);
	bool operator==(const ListWdbeAMPeripheralPar& comp);
	bool operator!=(const ListWdbeAMPeripheralPar& comp);

public:
	std::vector<WdbeAMPeripheralPar*> nodes;
};

/**
	* TblWdbeAMPeripheralPar: C++ wrapper for table TblWdbeAMPeripheralPar
	*/
class TblWdbeAMPeripheralPar {

public:

public:
	TblWdbeAMPeripheralPar();
	virtual ~TblWdbeAMPeripheralPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMPeripheralPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPeripheralPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMPeripheralPar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMPeripheralPar** rec = NULL, const Sbecore::ubigint refWdbeMPeripheral = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMPeripheralPar& rst, WdbeAMPeripheralPar** rec = NULL, const Sbecore::ubigint refWdbeMPeripheral = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	virtual void updateRec(WdbeAMPeripheralPar* rec);
	virtual void updateRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPeripheralPar** rec);
	virtual Sbecore::ubigint loadRefsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, ListWdbeAMPeripheralPar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMPeripheralPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMPeripheralPar: C++ wrapper for table TblWdbeAMPeripheralPar (MySQL database)
	*/
class MyTblWdbeAMPeripheralPar : public TblWdbeAMPeripheralPar, public Sbecore::MyTable {

public:
	MyTblWdbeAMPeripheralPar();
	~MyTblWdbeAMPeripheralPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPeripheralPar& rst);

	Sbecore::ubigint insertRec(WdbeAMPeripheralPar* rec);
	void insertRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	void updateRec(WdbeAMPeripheralPar* rec);
	void updateRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRefsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, ListWdbeAMPeripheralPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMPeripheralPar: C++ wrapper for table TblWdbeAMPeripheralPar (PgSQL database)
	*/
class PgTblWdbeAMPeripheralPar : public TblWdbeAMPeripheralPar, public Sbecore::PgTable {

public:
	PgTblWdbeAMPeripheralPar();
	~PgTblWdbeAMPeripheralPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMPeripheralPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMPeripheralPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPeripheralPar& rst);

	Sbecore::ubigint insertRec(WdbeAMPeripheralPar* rec);
	void insertRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	void updateRec(WdbeAMPeripheralPar* rec);
	void updateRst(ListWdbeAMPeripheralPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPeripheralPar** rec);
	Sbecore::ubigint loadRefsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, ListWdbeAMPeripheralPar& rst);
};
#endif

#endif

