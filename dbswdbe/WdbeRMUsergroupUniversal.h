/**
	* \file WdbeRMUsergroupUniversal.h
	* database access for table TblWdbeRMUsergroupUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBERMUSERGROUPUNIVERSAL_H
#define WDBERMUSERGROUPUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMUsergroupUniversal: record of TblWdbeRMUsergroupUniversal
	*/
class WdbeRMUsergroupUniversal {

public:
	WdbeRMUsergroupUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUsergroup;
	Sbecore::uint unvIxWdbeVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWdbeVRecaccess;

public:
	bool operator==(const WdbeRMUsergroupUniversal& comp);
	bool operator!=(const WdbeRMUsergroupUniversal& comp);
};

/**
	* ListWdbeRMUsergroupUniversal: recordset of TblWdbeRMUsergroupUniversal
	*/
class ListWdbeRMUsergroupUniversal {

public:
	ListWdbeRMUsergroupUniversal();
	ListWdbeRMUsergroupUniversal(const ListWdbeRMUsergroupUniversal& src);
	~ListWdbeRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(WdbeRMUsergroupUniversal* rec);

	WdbeRMUsergroupUniversal* operator[](const Sbecore::uint ix);
	ListWdbeRMUsergroupUniversal& operator=(const ListWdbeRMUsergroupUniversal& src);
	bool operator==(const ListWdbeRMUsergroupUniversal& comp);
	bool operator!=(const ListWdbeRMUsergroupUniversal& comp);

public:
	std::vector<WdbeRMUsergroupUniversal*> nodes;
};

/**
	* TblWdbeRMUsergroupUniversal: C++ wrapper for table TblWdbeRMUsergroupUniversal
	*/
class TblWdbeRMUsergroupUniversal {

public:

public:
	TblWdbeRMUsergroupUniversal();
	virtual ~TblWdbeRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMUsergroupUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUsergroupUniversal& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMUsergroupUniversal* rec);
	Sbecore::ubigint insertNewRec(WdbeRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMUsergroupUniversal& rst, WdbeRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);
	virtual void insertRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(WdbeRMUsergroupUniversal* rec);
	virtual void updateRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(Sbecore::ubigint refWdbeMUsergroup, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMUsergroupUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMUsergroupUniversal: C++ wrapper for table TblWdbeRMUsergroupUniversal (MySQL database)
	*/
class MyTblWdbeRMUsergroupUniversal : public TblWdbeRMUsergroupUniversal, public Sbecore::MyTable {

public:
	MyTblWdbeRMUsergroupUniversal();
	~MyTblWdbeRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WdbeRMUsergroupUniversal* rec);
	void insertRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WdbeRMUsergroupUniversal* rec);
	void updateRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWdbeMUsergroup, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMUsergroupUniversal: C++ wrapper for table TblWdbeRMUsergroupUniversal (PgSQL database)
	*/
class PgTblWdbeRMUsergroupUniversal : public TblWdbeRMUsergroupUniversal, public Sbecore::PgTable {

public:
	PgTblWdbeRMUsergroupUniversal();
	~PgTblWdbeRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMUsergroupUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WdbeRMUsergroupUniversal* rec);
	void insertRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WdbeRMUsergroupUniversal* rec);
	void updateRst(ListWdbeRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWdbeMUsergroup, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeRMUsergroupUniversal** rec);
};
#endif

#endif
