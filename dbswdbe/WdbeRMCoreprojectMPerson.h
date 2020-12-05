/**
	* \file WdbeRMCoreprojectMPerson.h
	* database access for table TblWdbeRMCoreprojectMPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBERMCOREPROJECTMPERSON_H
#define WDBERMCOREPROJECTMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMCoreprojectMPerson: record of TblWdbeRMCoreprojectMPerson
	*/
class WdbeRMCoreprojectMPerson {

public:
	WdbeRMCoreprojectMPerson(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string srefKFunction = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	Sbecore::uint x1Stopd;
	Sbecore::ubigint refWdbeMCoreproject;
	Sbecore::ubigint refWdbeMPerson;
	std::string srefKFunction;

public:
	bool operator==(const WdbeRMCoreprojectMPerson& comp);
	bool operator!=(const WdbeRMCoreprojectMPerson& comp);
};

/**
	* ListWdbeRMCoreprojectMPerson: recordset of TblWdbeRMCoreprojectMPerson
	*/
class ListWdbeRMCoreprojectMPerson {

public:
	ListWdbeRMCoreprojectMPerson();
	ListWdbeRMCoreprojectMPerson(const ListWdbeRMCoreprojectMPerson& src);
	~ListWdbeRMCoreprojectMPerson();

	void clear();
	unsigned int size() const;
	void append(WdbeRMCoreprojectMPerson* rec);

	WdbeRMCoreprojectMPerson* operator[](const Sbecore::uint ix);
	ListWdbeRMCoreprojectMPerson& operator=(const ListWdbeRMCoreprojectMPerson& src);
	bool operator==(const ListWdbeRMCoreprojectMPerson& comp);
	bool operator!=(const ListWdbeRMCoreprojectMPerson& comp);

public:
	std::vector<WdbeRMCoreprojectMPerson*> nodes;
};

/**
	* TblWdbeRMCoreprojectMPerson: C++ wrapper for table TblWdbeRMCoreprojectMPerson
	*/
class TblWdbeRMCoreprojectMPerson {

public:

public:
	TblWdbeRMCoreprojectMPerson();
	virtual ~TblWdbeRMCoreprojectMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMCoreprojectMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCoreprojectMPerson& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMCoreprojectMPerson* rec);
	Sbecore::ubigint insertNewRec(WdbeRMCoreprojectMPerson** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string srefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMCoreprojectMPerson& rst, WdbeRMCoreprojectMPerson** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string srefKFunction = "");
	virtual void insertRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	virtual void updateRec(WdbeRMCoreprojectMPerson* rec);
	virtual void updateRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCoreprojectMPerson** rec);
	virtual Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeRMCoreprojectMPerson& rst);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMCoreprojectMPerson& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMCoreprojectMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMCoreprojectMPerson: C++ wrapper for table TblWdbeRMCoreprojectMPerson (MySQL database)
	*/
class MyTblWdbeRMCoreprojectMPerson : public TblWdbeRMCoreprojectMPerson, public Sbecore::MyTable {

public:
	MyTblWdbeRMCoreprojectMPerson();
	~MyTblWdbeRMCoreprojectMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCoreprojectMPerson& rst);

	Sbecore::ubigint insertRec(WdbeRMCoreprojectMPerson* rec);
	void insertRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	void updateRec(WdbeRMCoreprojectMPerson* rec);
	void updateRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeRMCoreprojectMPerson& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMCoreprojectMPerson& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMCoreprojectMPerson: C++ wrapper for table TblWdbeRMCoreprojectMPerson (PgSQL database)
	*/
class PgTblWdbeRMCoreprojectMPerson : public TblWdbeRMCoreprojectMPerson, public Sbecore::PgTable {

public:
	PgTblWdbeRMCoreprojectMPerson();
	~PgTblWdbeRMCoreprojectMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMCoreprojectMPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMCoreprojectMPerson& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCoreprojectMPerson& rst);

	Sbecore::ubigint insertRec(WdbeRMCoreprojectMPerson* rec);
	void insertRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	void updateRec(WdbeRMCoreprojectMPerson* rec);
	void updateRst(ListWdbeRMCoreprojectMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCoreprojectMPerson** rec);
	Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeRMCoreprojectMPerson& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMCoreprojectMPerson& rst);
};
#endif

#endif

