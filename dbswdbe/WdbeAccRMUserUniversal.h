/**
	* \file WdbeAccRMUserUniversal.h
	* database access for table TblWdbeAccRMUserUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEACCRMUSERUNIVERSAL_H
#define WDBEACCRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAccRMUserUniversal: record of TblWdbeAccRMUserUniversal
	*/
class WdbeAccRMUserUniversal {

public:
	WdbeAccRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::uint unvIxWdbeVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWdbeVRecaccess;

public:
	bool operator==(const WdbeAccRMUserUniversal& comp);
	bool operator!=(const WdbeAccRMUserUniversal& comp);
};

/**
	* ListWdbeAccRMUserUniversal: recordset of TblWdbeAccRMUserUniversal
	*/
class ListWdbeAccRMUserUniversal {

public:
	ListWdbeAccRMUserUniversal();
	ListWdbeAccRMUserUniversal(const ListWdbeAccRMUserUniversal& src);
	~ListWdbeAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WdbeAccRMUserUniversal* rec);

	WdbeAccRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWdbeAccRMUserUniversal& operator=(const ListWdbeAccRMUserUniversal& src);
	bool operator==(const ListWdbeAccRMUserUniversal& comp);
	bool operator!=(const ListWdbeAccRMUserUniversal& comp);

public:
	std::vector<WdbeAccRMUserUniversal*> nodes;
};

/**
	* TblWdbeAccRMUserUniversal: C++ wrapper for table TblWdbeAccRMUserUniversal
	*/
class TblWdbeAccRMUserUniversal {

public:

public:
	TblWdbeAccRMUserUniversal();
	virtual ~TblWdbeAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAccRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAccRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WdbeAccRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WdbeAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeAccRMUserUniversal& rst, WdbeAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVRecaccess = 0);
	virtual void insertRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WdbeAccRMUserUniversal* rec);
	virtual void updateRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAccRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAccRMUserUniversal: C++ wrapper for table TblWdbeAccRMUserUniversal (MySQL database)
	*/
class MyTblWdbeAccRMUserUniversal : public TblWdbeAccRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWdbeAccRMUserUniversal();
	~MyTblWdbeAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WdbeAccRMUserUniversal* rec);
	void insertRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WdbeAccRMUserUniversal* rec);
	void updateRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAccRMUserUniversal: C++ wrapper for table TblWdbeAccRMUserUniversal (PgSQL database)
	*/
class PgTblWdbeAccRMUserUniversal : public TblWdbeAccRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWdbeAccRMUserUniversal();
	~PgTblWdbeAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAccRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WdbeAccRMUserUniversal* rec);
	void insertRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WdbeAccRMUserUniversal* rec);
	void updateRst(ListWdbeAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, WdbeAccRMUserUniversal** rec);
};
#endif

#endif
