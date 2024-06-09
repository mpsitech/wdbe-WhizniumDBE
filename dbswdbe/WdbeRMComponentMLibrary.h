/**
	* \file WdbeRMComponentMLibrary.h
	* database access for table TblWdbeRMComponentMLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBERMCOMPONENTMLIBRARY_H
#define WDBERMCOMPONENTMLIBRARY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMComponentMLibrary: record of TblWdbeRMComponentMLibrary
	*/
class WdbeRMComponentMLibrary {

public:
	WdbeRMComponentMLibrary(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMComponent = 0, const Sbecore::ubigint refWdbeMLibrary = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMComponent;
	Sbecore::ubigint refWdbeMLibrary;

public:
	bool operator==(const WdbeRMComponentMLibrary& comp);
	bool operator!=(const WdbeRMComponentMLibrary& comp);
};

/**
	* ListWdbeRMComponentMLibrary: recordset of TblWdbeRMComponentMLibrary
	*/
class ListWdbeRMComponentMLibrary {

public:
	ListWdbeRMComponentMLibrary();
	ListWdbeRMComponentMLibrary(const ListWdbeRMComponentMLibrary& src);
	~ListWdbeRMComponentMLibrary();

	void clear();
	unsigned int size() const;
	void append(WdbeRMComponentMLibrary* rec);

	WdbeRMComponentMLibrary* operator[](const Sbecore::uint ix);
	ListWdbeRMComponentMLibrary& operator=(const ListWdbeRMComponentMLibrary& src);
	bool operator==(const ListWdbeRMComponentMLibrary& comp);
	bool operator!=(const ListWdbeRMComponentMLibrary& comp);

public:
	std::vector<WdbeRMComponentMLibrary*> nodes;
};

/**
	* TblWdbeRMComponentMLibrary: C++ wrapper for table TblWdbeRMComponentMLibrary
	*/
class TblWdbeRMComponentMLibrary {

public:

public:
	TblWdbeRMComponentMLibrary();
	virtual ~TblWdbeRMComponentMLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMComponentMLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMComponentMLibrary& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMComponentMLibrary* rec);
	Sbecore::ubigint insertNewRec(WdbeRMComponentMLibrary** rec = NULL, const Sbecore::ubigint refWdbeMComponent = 0, const Sbecore::ubigint refWdbeMLibrary = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMComponentMLibrary& rst, WdbeRMComponentMLibrary** rec = NULL, const Sbecore::ubigint refWdbeMComponent = 0, const Sbecore::ubigint refWdbeMLibrary = 0);
	virtual void insertRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	virtual void updateRec(WdbeRMComponentMLibrary* rec);
	virtual void updateRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMComponentMLibrary** rec);
	virtual Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMComponents);
	virtual Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	virtual Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMComponentMLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMComponentMLibrary: C++ wrapper for table TblWdbeRMComponentMLibrary (MySQL database)
	*/
class MyTblWdbeRMComponentMLibrary : public TblWdbeRMComponentMLibrary, public Sbecore::MyTable {

public:
	MyTblWdbeRMComponentMLibrary();
	~MyTblWdbeRMComponentMLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMComponentMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMComponentMLibrary& rst);

	Sbecore::ubigint insertRec(WdbeRMComponentMLibrary* rec);
	void insertRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	void updateRec(WdbeRMComponentMLibrary* rec);
	void updateRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMComponentMLibrary** rec);
	Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMComponents);
	Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMComponentMLibrary: C++ wrapper for table TblWdbeRMComponentMLibrary (PgSQL database)
	*/
class PgTblWdbeRMComponentMLibrary : public TblWdbeRMComponentMLibrary, public Sbecore::PgTable {

public:
	PgTblWdbeRMComponentMLibrary();
	~PgTblWdbeRMComponentMLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMComponentMLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMComponentMLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMComponentMLibrary** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMComponentMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMComponentMLibrary& rst);

	Sbecore::ubigint insertRec(WdbeRMComponentMLibrary* rec);
	void insertRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	void updateRec(WdbeRMComponentMLibrary* rec);
	void updateRst(ListWdbeRMComponentMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMComponentMLibrary** rec);
	Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMComponents);
	Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWdbeMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
