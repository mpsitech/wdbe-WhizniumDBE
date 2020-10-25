/**
	* \file WdbeAMUsergroupAccess.h
	* database access for table TblWdbeAMUsergroupAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEAMUSERGROUPACCESS_H
#define WDBEAMUSERGROUPACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMUsergroupAccess: record of TblWdbeAMUsergroupAccess
	*/
class WdbeAMUsergroupAccess {

public:
	WdbeAMUsergroupAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUsergroup;
	Sbecore::uint x1IxWdbeVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWdbeWAccess;

public:
	bool operator==(const WdbeAMUsergroupAccess& comp);
	bool operator!=(const WdbeAMUsergroupAccess& comp);
};

/**
	* ListWdbeAMUsergroupAccess: recordset of TblWdbeAMUsergroupAccess
	*/
class ListWdbeAMUsergroupAccess {

public:
	ListWdbeAMUsergroupAccess();
	ListWdbeAMUsergroupAccess(const ListWdbeAMUsergroupAccess& src);
	~ListWdbeAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(WdbeAMUsergroupAccess* rec);

	WdbeAMUsergroupAccess* operator[](const Sbecore::uint ix);
	ListWdbeAMUsergroupAccess& operator=(const ListWdbeAMUsergroupAccess& src);
	bool operator==(const ListWdbeAMUsergroupAccess& comp);
	bool operator!=(const ListWdbeAMUsergroupAccess& comp);

public:
	std::vector<WdbeAMUsergroupAccess*> nodes;
};

/**
	* TblWdbeAMUsergroupAccess: C++ wrapper for table TblWdbeAMUsergroupAccess
	*/
class TblWdbeAMUsergroupAccess {

public:

public:
	TblWdbeAMUsergroupAccess();
	virtual ~TblWdbeAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUsergroupAccess& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMUsergroupAccess* rec);
	Sbecore::ubigint insertNewRec(WdbeAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMUsergroupAccess& rst, WdbeAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
	virtual void insertRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(WdbeAMUsergroupAccess* rec);
	virtual void updateRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeAMUsergroupAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMUsergroupAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMUsergroupAccess: C++ wrapper for table TblWdbeAMUsergroupAccess (MySQL database)
	*/
class MyTblWdbeAMUsergroupAccess : public TblWdbeAMUsergroupAccess, public Sbecore::MyTable {

public:
	MyTblWdbeAMUsergroupAccess();
	~MyTblWdbeAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WdbeAMUsergroupAccess* rec);
	void insertRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WdbeAMUsergroupAccess* rec);
	void updateRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMUsergroupAccess: C++ wrapper for table TblWdbeAMUsergroupAccess (PgSQL database)
	*/
class PgTblWdbeAMUsergroupAccess : public TblWdbeAMUsergroupAccess, public Sbecore::PgTable {

public:
	PgTblWdbeAMUsergroupAccess();
	~PgTblWdbeAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMUsergroupAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WdbeAMUsergroupAccess* rec);
	void insertRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WdbeAMUsergroupAccess* rec);
	void updateRst(ListWdbeAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, ListWdbeAMUsergroupAccess& rst);
};
#endif

#endif

