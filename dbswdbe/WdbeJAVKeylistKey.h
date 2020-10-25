/**
	* \file WdbeJAVKeylistKey.h
	* database access for table TblWdbeJAVKeylistKey (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEJAVKEYLISTKEY_H
#define WDBEJAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJAVKeylistKey: record of TblWdbeJAVKeylistKey
	*/
class WdbeJAVKeylistKey {

public:
	WdbeJAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeAVKeylistKey = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeAVKeylistKey;
	Sbecore::uint x1IxWdbeVLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WdbeJAVKeylistKey& comp);
	bool operator!=(const WdbeJAVKeylistKey& comp);
};

/**
	* ListWdbeJAVKeylistKey: recordset of TblWdbeJAVKeylistKey
	*/
class ListWdbeJAVKeylistKey {

public:
	ListWdbeJAVKeylistKey();
	ListWdbeJAVKeylistKey(const ListWdbeJAVKeylistKey& src);
	~ListWdbeJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WdbeJAVKeylistKey* rec);

	WdbeJAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWdbeJAVKeylistKey& operator=(const ListWdbeJAVKeylistKey& src);
	bool operator==(const ListWdbeJAVKeylistKey& comp);
	bool operator!=(const ListWdbeJAVKeylistKey& comp);

public:
	std::vector<WdbeJAVKeylistKey*> nodes;
};

/**
	* TblWdbeJAVKeylistKey: C++ wrapper for table TblWdbeJAVKeylistKey
	*/
class TblWdbeJAVKeylistKey {

public:

public:
	TblWdbeJAVKeylistKey();
	virtual ~TblWdbeJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WdbeJAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WdbeJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWdbeAVKeylistKey = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeJAVKeylistKey& rst, WdbeJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWdbeAVKeylistKey = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WdbeJAVKeylistKey* rec);
	virtual void updateRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, WdbeJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, ListWdbeJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJAVKeylistKey: C++ wrapper for table TblWdbeJAVKeylistKey (MySQL database)
	*/
class MyTblWdbeJAVKeylistKey : public TblWdbeJAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWdbeJAVKeylistKey();
	~MyTblWdbeJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WdbeJAVKeylistKey* rec);
	void insertRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	void updateRec(WdbeJAVKeylistKey* rec);
	void updateRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, ListWdbeJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJAVKeylistKey: C++ wrapper for table TblWdbeJAVKeylistKey (PgSQL database)
	*/
class PgTblWdbeJAVKeylistKey : public TblWdbeJAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWdbeJAVKeylistKey();
	~PgTblWdbeJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WdbeJAVKeylistKey* rec);
	void insertRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	void updateRec(WdbeJAVKeylistKey* rec);
	void updateRst(ListWdbeJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, WdbeJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWdbeAVKeylistKey, const bool append, ListWdbeJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWdbeAVKeylistKey, Sbecore::uint x1IxWdbeVLocale, std::string& Title);
};
#endif

#endif

