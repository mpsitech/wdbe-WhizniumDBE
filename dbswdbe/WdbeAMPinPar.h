/**
	* \file WdbeAMPinPar.h
	* database access for table TblWdbeAMPinPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMPINPAR_H
#define WDBEAMPINPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMPinPar: record of TblWdbeAMPinPar
	*/
class WdbeAMPinPar {

public:
	WdbeAMPinPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMPin = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMPin;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WdbeAMPinPar& comp);
	bool operator!=(const WdbeAMPinPar& comp);
};

/**
	* ListWdbeAMPinPar: recordset of TblWdbeAMPinPar
	*/
class ListWdbeAMPinPar {

public:
	ListWdbeAMPinPar();
	ListWdbeAMPinPar(const ListWdbeAMPinPar& src);
	~ListWdbeAMPinPar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMPinPar* rec);

	WdbeAMPinPar* operator[](const Sbecore::uint ix);
	ListWdbeAMPinPar& operator=(const ListWdbeAMPinPar& src);
	bool operator==(const ListWdbeAMPinPar& comp);
	bool operator!=(const ListWdbeAMPinPar& comp);

public:
	std::vector<WdbeAMPinPar*> nodes;
};

/**
	* TblWdbeAMPinPar: C++ wrapper for table TblWdbeAMPinPar
	*/
class TblWdbeAMPinPar {

public:

public:
	TblWdbeAMPinPar();
	virtual ~TblWdbeAMPinPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMPinPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPinPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMPinPar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMPinPar** rec = NULL, const Sbecore::ubigint refWdbeMPin = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMPinPar& rst, WdbeAMPinPar** rec = NULL, const Sbecore::ubigint refWdbeMPin = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMPinPar& rst, bool transact = false);
	virtual void updateRec(WdbeAMPinPar* rec);
	virtual void updateRst(ListWdbeAMPinPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPinPar** rec);
	virtual Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeAMPinPar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMPinPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMPinPar: C++ wrapper for table TblWdbeAMPinPar (MySQL database)
	*/
class MyTblWdbeAMPinPar : public TblWdbeAMPinPar, public Sbecore::MyTable {

public:
	MyTblWdbeAMPinPar();
	~MyTblWdbeAMPinPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPinPar& rst);

	Sbecore::ubigint insertRec(WdbeAMPinPar* rec);
	void insertRst(ListWdbeAMPinPar& rst, bool transact = false);
	void updateRec(WdbeAMPinPar* rec);
	void updateRst(ListWdbeAMPinPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeAMPinPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMPinPar: C++ wrapper for table TblWdbeAMPinPar (PgSQL database)
	*/
class PgTblWdbeAMPinPar : public TblWdbeAMPinPar, public Sbecore::PgTable {

public:
	PgTblWdbeAMPinPar();
	~PgTblWdbeAMPinPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMPinPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMPinPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPinPar& rst);

	Sbecore::ubigint insertRec(WdbeAMPinPar* rec);
	void insertRst(ListWdbeAMPinPar& rst, bool transact = false);
	void updateRec(WdbeAMPinPar* rec);
	void updateRst(ListWdbeAMPinPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPinPar** rec);
	Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeAMPinPar& rst);
};
#endif

#endif
