/**
	* \file WdbeMTarget.h
	* database access for table TblWdbeMTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTARGET_H
#define WDBEMTARGET_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMTarget: record of TblWdbeMTarget
	*/
class WdbeMTarget {

public:
	WdbeMTarget(const Sbecore::ubigint ref = 0, const Sbecore::ubigint sysRefWdbeMSystem = 0, const Sbecore::uint sysNum = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string rteSrefsWdbeMModule = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint sysRefWdbeMSystem;
	Sbecore::uint sysNum;
	Sbecore::ubigint refWdbeMUnit;
	std::string sref;
	std::string rteSrefsWdbeMModule;
	std::string Comment;

public:
	bool operator==(const WdbeMTarget& comp);
	bool operator!=(const WdbeMTarget& comp);
};

/**
	* ListWdbeMTarget: recordset of TblWdbeMTarget
	*/
class ListWdbeMTarget {

public:
	ListWdbeMTarget();
	ListWdbeMTarget(const ListWdbeMTarget& src);
	~ListWdbeMTarget();

	void clear();
	unsigned int size() const;
	void append(WdbeMTarget* rec);

	WdbeMTarget* operator[](const Sbecore::uint ix);
	ListWdbeMTarget& operator=(const ListWdbeMTarget& src);
	bool operator==(const ListWdbeMTarget& comp);
	bool operator!=(const ListWdbeMTarget& comp);

public:
	std::vector<WdbeMTarget*> nodes;
};

/**
	* TblWdbeMTarget: C++ wrapper for table TblWdbeMTarget
	*/
class TblWdbeMTarget {

public:

public:
	TblWdbeMTarget();
	virtual ~TblWdbeMTarget();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMTarget** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMTarget& rst);

	virtual Sbecore::ubigint insertRec(WdbeMTarget* rec);
	Sbecore::ubigint insertNewRec(WdbeMTarget** rec = NULL, const Sbecore::ubigint sysRefWdbeMSystem = 0, const Sbecore::uint sysNum = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string rteSrefsWdbeMModule = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMTarget& rst, WdbeMTarget** rec = NULL, const Sbecore::ubigint sysRefWdbeMSystem = 0, const Sbecore::uint sysNum = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string rteSrefsWdbeMModule = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMTarget& rst, bool transact = false);
	virtual void updateRec(WdbeMTarget* rec);
	virtual void updateRst(ListWdbeMTarget& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMTarget** rec);
	virtual Sbecore::ubigint loadRefsBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, ListWdbeMTarget& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMTarget& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMTarget: C++ wrapper for table TblWdbeMTarget (MySQL database)
	*/
class MyTblWdbeMTarget : public TblWdbeMTarget, public Sbecore::MyTable {

public:
	MyTblWdbeMTarget();
	~MyTblWdbeMTarget();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMTarget& rst);

	Sbecore::ubigint insertRec(WdbeMTarget* rec);
	void insertRst(ListWdbeMTarget& rst, bool transact = false);
	void updateRec(WdbeMTarget* rec);
	void updateRst(ListWdbeMTarget& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMTarget** rec);
	Sbecore::ubigint loadRefsBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, ListWdbeMTarget& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMTarget: C++ wrapper for table TblWdbeMTarget (PgSQL database)
	*/
class PgTblWdbeMTarget : public TblWdbeMTarget, public Sbecore::PgTable {

public:
	PgTblWdbeMTarget();
	~PgTblWdbeMTarget();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMTarget** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMTarget& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMTarget** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMTarget& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMTarget& rst);

	Sbecore::ubigint insertRec(WdbeMTarget* rec);
	void insertRst(ListWdbeMTarget& rst, bool transact = false);
	void updateRec(WdbeMTarget* rec);
	void updateRst(ListWdbeMTarget& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMTarget** rec);
	Sbecore::ubigint loadRefsBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySys(Sbecore::ubigint sysRefWdbeMSystem, const bool append, ListWdbeMTarget& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
