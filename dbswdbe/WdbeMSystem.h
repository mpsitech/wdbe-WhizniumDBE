/**
	* \file WdbeMSystem.h
	* database access for table TblWdbeMSystem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMSYSTEM_H
#define WDBEMSYSTEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMSystem: record of TblWdbeMSystem
	*/
class WdbeMSystem {

public:
	WdbeMSystem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMVersion;
	Sbecore::ubigint refWdbeMUnit;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeMSystem& comp);
	bool operator!=(const WdbeMSystem& comp);
};

/**
	* ListWdbeMSystem: recordset of TblWdbeMSystem
	*/
class ListWdbeMSystem {

public:
	ListWdbeMSystem();
	ListWdbeMSystem(const ListWdbeMSystem& src);
	~ListWdbeMSystem();

	void clear();
	unsigned int size() const;
	void append(WdbeMSystem* rec);

	WdbeMSystem* operator[](const Sbecore::uint ix);
	ListWdbeMSystem& operator=(const ListWdbeMSystem& src);
	bool operator==(const ListWdbeMSystem& comp);
	bool operator!=(const ListWdbeMSystem& comp);

public:
	std::vector<WdbeMSystem*> nodes;
};

/**
	* TblWdbeMSystem: C++ wrapper for table TblWdbeMSystem
	*/
class TblWdbeMSystem {

public:

public:
	TblWdbeMSystem();
	virtual ~TblWdbeMSystem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMSystem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSystem& rst);

	virtual Sbecore::ubigint insertRec(WdbeMSystem* rec);
	Sbecore::ubigint insertNewRec(WdbeMSystem** rec = NULL, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMSystem& rst, WdbeMSystem** rec = NULL, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMSystem& rst, bool transact = false);
	virtual void updateRec(WdbeMSystem* rec);
	virtual void updateRst(ListWdbeMSystem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMSystem** rec);
	virtual bool loadRecByUnt(Sbecore::ubigint refWdbeMUnit, WdbeMSystem** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMSystem& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMSystem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMSystem: C++ wrapper for table TblWdbeMSystem (MySQL database)
	*/
class MyTblWdbeMSystem : public TblWdbeMSystem, public Sbecore::MyTable {

public:
	MyTblWdbeMSystem();
	~MyTblWdbeMSystem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSystem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSystem& rst);

	Sbecore::ubigint insertRec(WdbeMSystem* rec);
	void insertRst(ListWdbeMSystem& rst, bool transact = false);
	void updateRec(WdbeMSystem* rec);
	void updateRst(ListWdbeMSystem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSystem** rec);
	bool loadRecByUnt(Sbecore::ubigint refWdbeMUnit, WdbeMSystem** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMSystem& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMSystem: C++ wrapper for table TblWdbeMSystem (PgSQL database)
	*/
class PgTblWdbeMSystem : public TblWdbeMSystem, public Sbecore::PgTable {

public:
	PgTblWdbeMSystem();
	~PgTblWdbeMSystem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMSystem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMSystem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMSystem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMSystem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSystem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSystem& rst);

	Sbecore::ubigint insertRec(WdbeMSystem* rec);
	void insertRst(ListWdbeMSystem& rst, bool transact = false);
	void updateRec(WdbeMSystem* rec);
	void updateRst(ListWdbeMSystem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSystem** rec);
	bool loadRecByUnt(Sbecore::ubigint refWdbeMUnit, WdbeMSystem** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMSystem& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

