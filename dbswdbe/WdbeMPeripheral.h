/**
	* \file WdbeMPeripheral.h
	* database access for table TblWdbeMPeripheral (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMPERIPHERAL_H
#define WDBEMPERIPHERAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMPeripheral: record of TblWdbeMPeripheral
	*/
class WdbeMPeripheral {

public:
	WdbeMPeripheral(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUnit;
	Sbecore::ubigint refWdbeMModule;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeMPeripheral& comp);
	bool operator!=(const WdbeMPeripheral& comp);
};

/**
	* ListWdbeMPeripheral: recordset of TblWdbeMPeripheral
	*/
class ListWdbeMPeripheral {

public:
	ListWdbeMPeripheral();
	ListWdbeMPeripheral(const ListWdbeMPeripheral& src);
	~ListWdbeMPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeMPeripheral* rec);

	WdbeMPeripheral* operator[](const Sbecore::uint ix);
	ListWdbeMPeripheral& operator=(const ListWdbeMPeripheral& src);
	bool operator==(const ListWdbeMPeripheral& comp);
	bool operator!=(const ListWdbeMPeripheral& comp);

public:
	std::vector<WdbeMPeripheral*> nodes;
};

/**
	* TblWdbeMPeripheral: C++ wrapper for table TblWdbeMPeripheral
	*/
class TblWdbeMPeripheral {

public:

public:
	TblWdbeMPeripheral();
	virtual ~TblWdbeMPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeMPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeMPeripheral** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMPeripheral& rst, WdbeMPeripheral** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMPeripheral& rst, bool transact = false);
	virtual void updateRec(WdbeMPeripheral* rec);
	virtual void updateRst(ListWdbeMPeripheral& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMPeripheral** rec);
	virtual Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMPeripheral& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMPeripheral: C++ wrapper for table TblWdbeMPeripheral (MySQL database)
	*/
class MyTblWdbeMPeripheral : public TblWdbeMPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeMPeripheral();
	~MyTblWdbeMPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeMPeripheral* rec);
	void insertRst(ListWdbeMPeripheral& rst, bool transact = false);
	void updateRec(WdbeMPeripheral* rec);
	void updateRst(ListWdbeMPeripheral& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMPeripheral& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMPeripheral: C++ wrapper for table TblWdbeMPeripheral (PgSQL database)
	*/
class PgTblWdbeMPeripheral : public TblWdbeMPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeMPeripheral();
	~PgTblWdbeMPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMPeripheral& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeMPeripheral* rec);
	void insertRst(ListWdbeMPeripheral& rst, bool transact = false);
	void updateRec(WdbeMPeripheral* rec);
	void updateRst(ListWdbeMPeripheral& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPeripheral** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMPeripheral& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

