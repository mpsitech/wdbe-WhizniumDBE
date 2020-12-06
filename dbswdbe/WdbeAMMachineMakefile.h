/**
	* \file WdbeAMMachineMakefile.h
	* database access for table TblWdbeAMMachineMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMMACHINEMAKEFILE_H
#define WDBEAMMACHINEMAKEFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMMachineMakefile: record of TblWdbeAMMachineMakefile
	*/
class WdbeAMMachineMakefile {

public:
	WdbeAMMachineMakefile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMMachine;
	std::string x1SrefKTag;
	std::string Val;

public:
	bool operator==(const WdbeAMMachineMakefile& comp);
	bool operator!=(const WdbeAMMachineMakefile& comp);
};

/**
	* ListWdbeAMMachineMakefile: recordset of TblWdbeAMMachineMakefile
	*/
class ListWdbeAMMachineMakefile {

public:
	ListWdbeAMMachineMakefile();
	ListWdbeAMMachineMakefile(const ListWdbeAMMachineMakefile& src);
	~ListWdbeAMMachineMakefile();

	void clear();
	unsigned int size() const;
	void append(WdbeAMMachineMakefile* rec);

	WdbeAMMachineMakefile* operator[](const Sbecore::uint ix);
	ListWdbeAMMachineMakefile& operator=(const ListWdbeAMMachineMakefile& src);
	bool operator==(const ListWdbeAMMachineMakefile& comp);
	bool operator!=(const ListWdbeAMMachineMakefile& comp);

public:
	std::vector<WdbeAMMachineMakefile*> nodes;
};

/**
	* TblWdbeAMMachineMakefile: C++ wrapper for table TblWdbeAMMachineMakefile
	*/
class TblWdbeAMMachineMakefile {

public:

public:
	TblWdbeAMMachineMakefile();
	virtual ~TblWdbeAMMachineMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachineMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachineMakefile& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMMachineMakefile* rec);
	Sbecore::ubigint insertNewRec(WdbeAMMachineMakefile** rec = NULL, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMMachineMakefile& rst, WdbeAMMachineMakefile** rec = NULL, const Sbecore::ubigint refWdbeMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	virtual void updateRec(WdbeAMMachineMakefile* rec);
	virtual void updateRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachineMakefile** rec);
	virtual Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachineMakefile& rst);
	virtual bool loadValByMchTag(Sbecore::ubigint refWdbeMMachine, std::string x1SrefKTag, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMMachineMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMMachineMakefile: C++ wrapper for table TblWdbeAMMachineMakefile (MySQL database)
	*/
class MyTblWdbeAMMachineMakefile : public TblWdbeAMMachineMakefile, public Sbecore::MyTable {

public:
	MyTblWdbeAMMachineMakefile();
	~MyTblWdbeAMMachineMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachineMakefile& rst);

	Sbecore::ubigint insertRec(WdbeAMMachineMakefile* rec);
	void insertRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	void updateRec(WdbeAMMachineMakefile* rec);
	void updateRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachineMakefile& rst);
	bool loadValByMchTag(Sbecore::ubigint refWdbeMMachine, std::string x1SrefKTag, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMMachineMakefile: C++ wrapper for table TblWdbeAMMachineMakefile (PgSQL database)
	*/
class PgTblWdbeAMMachineMakefile : public TblWdbeAMMachineMakefile, public Sbecore::PgTable {

public:
	PgTblWdbeAMMachineMakefile();
	~PgTblWdbeAMMachineMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMMachineMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMMachineMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMMachineMakefile& rst);

	Sbecore::ubigint insertRec(WdbeAMMachineMakefile* rec);
	void insertRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	void updateRec(WdbeAMMachineMakefile* rec);
	void updateRst(ListWdbeAMMachineMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMMachineMakefile** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWdbeMMachine, const bool append, ListWdbeAMMachineMakefile& rst);
	bool loadValByMchTag(Sbecore::ubigint refWdbeMMachine, std::string x1SrefKTag, std::string& Val);
};
#endif

#endif
