/**
	* \file WdbeMVariable.h
	* database access for table TblWdbeMVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMVARIABLE_H
#define WDBEMVARIABLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMVariable: record of TblWdbeMVariable
	*/
class WdbeMVariable {

public:
	WdbeMVariable(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCVariable = 0, const Sbecore::ubigint prcRefWdbeMProcess = 0, const Sbecore::uint prcNum = 0, const std::string sref = "", const bool Const = false, const bool Falling = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCVariable;
	Sbecore::ubigint prcRefWdbeMProcess;
	Sbecore::uint prcNum;
	std::string sref;
	bool Const;
	bool Falling;
	std::string srefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;
	std::string Onval;
	std::string Offval;
	bool Defon;
	std::string Comment;

public:
	bool operator==(const WdbeMVariable& comp);
	bool operator!=(const WdbeMVariable& comp);
};

/**
	* ListWdbeMVariable: recordset of TblWdbeMVariable
	*/
class ListWdbeMVariable {

public:
	ListWdbeMVariable();
	ListWdbeMVariable(const ListWdbeMVariable& src);
	~ListWdbeMVariable();

	void clear();
	unsigned int size() const;
	void append(WdbeMVariable* rec);

	WdbeMVariable* operator[](const Sbecore::uint ix);
	ListWdbeMVariable& operator=(const ListWdbeMVariable& src);
	bool operator==(const ListWdbeMVariable& comp);
	bool operator!=(const ListWdbeMVariable& comp);

public:
	std::vector<WdbeMVariable*> nodes;
};

/**
	* TblWdbeMVariable: C++ wrapper for table TblWdbeMVariable
	*/
class TblWdbeMVariable {

public:

public:
	TblWdbeMVariable();
	virtual ~TblWdbeMVariable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMVariable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVariable& rst);

	virtual Sbecore::ubigint insertRec(WdbeMVariable* rec);
	Sbecore::ubigint insertNewRec(WdbeMVariable** rec = NULL, const Sbecore::ubigint refWdbeCVariable = 0, const Sbecore::ubigint prcRefWdbeMProcess = 0, const Sbecore::uint prcNum = 0, const std::string sref = "", const bool Const = false, const bool Falling = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMVariable& rst, WdbeMVariable** rec = NULL, const Sbecore::ubigint refWdbeCVariable = 0, const Sbecore::ubigint prcRefWdbeMProcess = 0, const Sbecore::uint prcNum = 0, const std::string sref = "", const bool Const = false, const bool Falling = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const std::string Comment = "");
	virtual void insertRst(ListWdbeMVariable& rst, bool transact = false);
	virtual void updateRec(WdbeMVariable* rec);
	virtual void updateRst(ListWdbeMVariable& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMVariable** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCVariable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCVariable, const bool append, ListWdbeMVariable& rst);
	virtual Sbecore::ubigint loadRstByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, ListWdbeMVariable& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMVariable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMVariable: C++ wrapper for table TblWdbeMVariable (MySQL database)
	*/
class MyTblWdbeMVariable : public TblWdbeMVariable, public Sbecore::MyTable {

public:
	MyTblWdbeMVariable();
	~MyTblWdbeMVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVariable& rst);

	Sbecore::ubigint insertRec(WdbeMVariable* rec);
	void insertRst(ListWdbeMVariable& rst, bool transact = false);
	void updateRec(WdbeMVariable* rec);
	void updateRst(ListWdbeMVariable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVariable** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCVariable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCVariable, const bool append, ListWdbeMVariable& rst);
	Sbecore::ubigint loadRstByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, ListWdbeMVariable& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMVariable: C++ wrapper for table TblWdbeMVariable (PgSQL database)
	*/
class PgTblWdbeMVariable : public TblWdbeMVariable, public Sbecore::PgTable {

public:
	PgTblWdbeMVariable();
	~PgTblWdbeMVariable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMVariable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMVariable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMVariable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMVariable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVariable& rst);

	Sbecore::ubigint insertRec(WdbeMVariable* rec);
	void insertRst(ListWdbeMVariable& rst, bool transact = false);
	void updateRec(WdbeMVariable* rec);
	void updateRst(ListWdbeMVariable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVariable** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCVariable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCVariable, const bool append, ListWdbeMVariable& rst);
	Sbecore::ubigint loadRstByPrc(Sbecore::ubigint prcRefWdbeMProcess, const bool append, ListWdbeMVariable& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

