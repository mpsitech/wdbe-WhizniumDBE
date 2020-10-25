/**
	* \file WdbeAMLibraryMakefile.h
	* database access for table TblWdbeAMLibraryMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEAMLIBRARYMAKEFILE_H
#define WDBEAMLIBRARYMAKEFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMLibraryMakefile: record of TblWdbeAMLibraryMakefile
	*/
class WdbeAMLibraryMakefile {

public:
	WdbeAMLibraryMakefile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string x2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMLibrary;
	Sbecore::ubigint x1RefWdbeMMachine;
	std::string x2SrefKTag;
	std::string Val;

public:
	bool operator==(const WdbeAMLibraryMakefile& comp);
	bool operator!=(const WdbeAMLibraryMakefile& comp);
};

/**
	* ListWdbeAMLibraryMakefile: recordset of TblWdbeAMLibraryMakefile
	*/
class ListWdbeAMLibraryMakefile {

public:
	ListWdbeAMLibraryMakefile();
	ListWdbeAMLibraryMakefile(const ListWdbeAMLibraryMakefile& src);
	~ListWdbeAMLibraryMakefile();

	void clear();
	unsigned int size() const;
	void append(WdbeAMLibraryMakefile* rec);

	WdbeAMLibraryMakefile* operator[](const Sbecore::uint ix);
	ListWdbeAMLibraryMakefile& operator=(const ListWdbeAMLibraryMakefile& src);
	bool operator==(const ListWdbeAMLibraryMakefile& comp);
	bool operator!=(const ListWdbeAMLibraryMakefile& comp);

public:
	std::vector<WdbeAMLibraryMakefile*> nodes;
};

/**
	* TblWdbeAMLibraryMakefile: C++ wrapper for table TblWdbeAMLibraryMakefile
	*/
class TblWdbeAMLibraryMakefile {

public:

public:
	TblWdbeAMLibraryMakefile();
	virtual ~TblWdbeAMLibraryMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMLibraryMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMLibraryMakefile& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMLibraryMakefile* rec);
	Sbecore::ubigint insertNewRec(WdbeAMLibraryMakefile** rec = NULL, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string x2SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMLibraryMakefile& rst, WdbeAMLibraryMakefile** rec = NULL, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string x2SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	virtual void updateRec(WdbeAMLibraryMakefile* rec);
	virtual void updateRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMLibraryMakefile** rec);
	virtual Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, ListWdbeAMLibraryMakefile& rst);
	virtual Sbecore::ubigint loadRstByLibMch(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, const bool append, ListWdbeAMLibraryMakefile& rst);
	virtual bool loadValByLibMchTag(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, std::string x2SrefKTag, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMLibraryMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMLibraryMakefile: C++ wrapper for table TblWdbeAMLibraryMakefile (MySQL database)
	*/
class MyTblWdbeAMLibraryMakefile : public TblWdbeAMLibraryMakefile, public Sbecore::MyTable {

public:
	MyTblWdbeAMLibraryMakefile();
	~MyTblWdbeAMLibraryMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMLibraryMakefile& rst);

	Sbecore::ubigint insertRec(WdbeAMLibraryMakefile* rec);
	void insertRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	void updateRec(WdbeAMLibraryMakefile* rec);
	void updateRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, ListWdbeAMLibraryMakefile& rst);
	Sbecore::ubigint loadRstByLibMch(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, const bool append, ListWdbeAMLibraryMakefile& rst);
	bool loadValByLibMchTag(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, std::string x2SrefKTag, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMLibraryMakefile: C++ wrapper for table TblWdbeAMLibraryMakefile (PgSQL database)
	*/
class PgTblWdbeAMLibraryMakefile : public TblWdbeAMLibraryMakefile, public Sbecore::PgTable {

public:
	PgTblWdbeAMLibraryMakefile();
	~PgTblWdbeAMLibraryMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMLibraryMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMLibraryMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMLibraryMakefile& rst);

	Sbecore::ubigint insertRec(WdbeAMLibraryMakefile* rec);
	void insertRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	void updateRec(WdbeAMLibraryMakefile* rec);
	void updateRst(ListWdbeAMLibraryMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMLibraryMakefile** rec);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, ListWdbeAMLibraryMakefile& rst);
	Sbecore::ubigint loadRstByLibMch(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, const bool append, ListWdbeAMLibraryMakefile& rst);
	bool loadValByLibMchTag(Sbecore::ubigint refWdbeMLibrary, Sbecore::ubigint x1RefWdbeMMachine, std::string x2SrefKTag, std::string& Val);
};
#endif

#endif

