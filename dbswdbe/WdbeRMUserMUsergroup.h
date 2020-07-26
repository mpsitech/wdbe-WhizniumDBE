/**
	* \file WdbeRMUserMUsergroup.h
	* database access for table TblWdbeRMUserMUsergroup (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBERMUSERMUSERGROUP_H
#define WDBERMUSERMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMUserMUsergroup: record of TblWdbeRMUserMUsergroup
	*/
class WdbeRMUserMUsergroup {

public:
	WdbeRMUserMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint ixWdbeVUserlevel = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::ubigint refWdbeMUsergroup;
	Sbecore::uint ixWdbeVUserlevel;

public:
	bool operator==(const WdbeRMUserMUsergroup& comp);
	bool operator!=(const WdbeRMUserMUsergroup& comp);
};

/**
	* ListWdbeRMUserMUsergroup: recordset of TblWdbeRMUserMUsergroup
	*/
class ListWdbeRMUserMUsergroup {

public:
	ListWdbeRMUserMUsergroup();
	ListWdbeRMUserMUsergroup(const ListWdbeRMUserMUsergroup& src);
	~ListWdbeRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WdbeRMUserMUsergroup* rec);

	WdbeRMUserMUsergroup* operator[](const Sbecore::uint ix);
	ListWdbeRMUserMUsergroup& operator=(const ListWdbeRMUserMUsergroup& src);
	bool operator==(const ListWdbeRMUserMUsergroup& comp);
	bool operator!=(const ListWdbeRMUserMUsergroup& comp);

public:
	std::vector<WdbeRMUserMUsergroup*> nodes;
};

/**
	* TblWdbeRMUserMUsergroup: C++ wrapper for table TblWdbeRMUserMUsergroup
	*/
class TblWdbeRMUserMUsergroup {

public:

public:
	TblWdbeRMUserMUsergroup();
	virtual ~TblWdbeRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUserMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMUserMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WdbeRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint ixWdbeVUserlevel = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMUserMUsergroup& rst, WdbeRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint ixWdbeVUserlevel = 0);
	virtual void insertRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(WdbeRMUserMUsergroup* rec);
	virtual void updateRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeRMUserMUsergroup& rst);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMUserMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMUserMUsergroup: C++ wrapper for table TblWdbeRMUserMUsergroup (MySQL database)
	*/
class MyTblWdbeRMUserMUsergroup : public TblWdbeRMUserMUsergroup, public Sbecore::MyTable {

public:
	MyTblWdbeRMUserMUsergroup();
	~MyTblWdbeRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeRMUserMUsergroup* rec);
	void insertRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WdbeRMUserMUsergroup* rec);
	void updateRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMUserMUsergroup: C++ wrapper for table TblWdbeRMUserMUsergroup (PgSQL database)
	*/
class PgTblWdbeRMUserMUsergroup : public TblWdbeRMUserMUsergroup, public Sbecore::PgTable {

public:
	PgTblWdbeRMUserMUsergroup();
	~PgTblWdbeRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMUserMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeRMUserMUsergroup* rec);
	void insertRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WdbeRMUserMUsergroup* rec);
	void updateRst(ListWdbeRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeRMUserMUsergroup& rst);
};
#endif

#endif

