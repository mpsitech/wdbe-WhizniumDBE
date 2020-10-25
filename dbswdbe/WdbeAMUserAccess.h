/**
	* \file WdbeAMUserAccess.h
	* database access for table TblWdbeAMUserAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEAMUSERACCESS_H
#define WDBEAMUSERACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMUserAccess: record of TblWdbeAMUserAccess
	*/
class WdbeAMUserAccess {

public:
	WdbeAMUserAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::uint x1IxWdbeVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWdbeWAccess;

public:
	bool operator==(const WdbeAMUserAccess& comp);
	bool operator!=(const WdbeAMUserAccess& comp);
};

/**
	* ListWdbeAMUserAccess: recordset of TblWdbeAMUserAccess
	*/
class ListWdbeAMUserAccess {

public:
	ListWdbeAMUserAccess();
	ListWdbeAMUserAccess(const ListWdbeAMUserAccess& src);
	~ListWdbeAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(WdbeAMUserAccess* rec);

	WdbeAMUserAccess* operator[](const Sbecore::uint ix);
	ListWdbeAMUserAccess& operator=(const ListWdbeAMUserAccess& src);
	bool operator==(const ListWdbeAMUserAccess& comp);
	bool operator!=(const ListWdbeAMUserAccess& comp);

public:
	std::vector<WdbeAMUserAccess*> nodes;
};

/**
	* TblWdbeAMUserAccess: C++ wrapper for table TblWdbeAMUserAccess
	*/
class TblWdbeAMUserAccess {

public:

public:
	TblWdbeAMUserAccess();
	virtual ~TblWdbeAMUserAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMUserAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUserAccess& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMUserAccess* rec);
	Sbecore::ubigint insertNewRec(WdbeAMUserAccess** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMUserAccess& rst, WdbeAMUserAccess** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
	virtual void insertRst(ListWdbeAMUserAccess& rst, bool transact = false);
	virtual void updateRec(WdbeAMUserAccess* rec);
	virtual void updateRst(ListWdbeAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUserAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeAMUserAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMUserAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMUserAccess: C++ wrapper for table TblWdbeAMUserAccess (MySQL database)
	*/
class MyTblWdbeAMUserAccess : public TblWdbeAMUserAccess, public Sbecore::MyTable {

public:
	MyTblWdbeAMUserAccess();
	~MyTblWdbeAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUserAccess& rst);

	Sbecore::ubigint insertRec(WdbeAMUserAccess* rec);
	void insertRst(ListWdbeAMUserAccess& rst, bool transact = false);
	void updateRec(WdbeAMUserAccess* rec);
	void updateRst(ListWdbeAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeAMUserAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMUserAccess: C++ wrapper for table TblWdbeAMUserAccess (PgSQL database)
	*/
class PgTblWdbeAMUserAccess : public TblWdbeAMUserAccess, public Sbecore::PgTable {

public:
	PgTblWdbeAMUserAccess();
	~PgTblWdbeAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMUserAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUserAccess& rst);

	Sbecore::ubigint insertRec(WdbeAMUserAccess* rec);
	void insertRst(ListWdbeAMUserAccess& rst, bool transact = false);
	void updateRec(WdbeAMUserAccess* rec);
	void updateRst(ListWdbeAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWdbeMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWdbeMUser, const bool append, ListWdbeAMUserAccess& rst);
};
#endif

#endif

