/**
	* \file WdbeAMErrorPar.h
	* database access for table TblWdbeAMErrorPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAMERRORPAR_H
#define WDBEAMERRORPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMErrorPar: record of TblWdbeAMErrorPar
	*/
class WdbeAMErrorPar {

public:
	WdbeAMErrorPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint errRefWdbeMError = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint errRefWdbeMError;
	Sbecore::uint errNum;
	std::string sref;
	Sbecore::uint ixWdbeVPartype;
	Sbecore::ubigint refWdbeMVector;
	Sbecore::utinyint Length;
	std::string Comment;

public:
	bool operator==(const WdbeAMErrorPar& comp);
	bool operator!=(const WdbeAMErrorPar& comp);
};

/**
	* ListWdbeAMErrorPar: recordset of TblWdbeAMErrorPar
	*/
class ListWdbeAMErrorPar {

public:
	ListWdbeAMErrorPar();
	ListWdbeAMErrorPar(const ListWdbeAMErrorPar& src);
	~ListWdbeAMErrorPar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMErrorPar* rec);

	WdbeAMErrorPar* operator[](const Sbecore::uint ix);
	ListWdbeAMErrorPar& operator=(const ListWdbeAMErrorPar& src);
	bool operator==(const ListWdbeAMErrorPar& comp);
	bool operator!=(const ListWdbeAMErrorPar& comp);

public:
	std::vector<WdbeAMErrorPar*> nodes;
};

/**
	* TblWdbeAMErrorPar: C++ wrapper for table TblWdbeAMErrorPar
	*/
class TblWdbeAMErrorPar {

public:

public:
	TblWdbeAMErrorPar();
	virtual ~TblWdbeAMErrorPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMErrorPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMErrorPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMErrorPar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMErrorPar** rec = NULL, const Sbecore::ubigint errRefWdbeMError = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMErrorPar& rst, WdbeAMErrorPar** rec = NULL, const Sbecore::ubigint errRefWdbeMError = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeAMErrorPar& rst, bool transact = false);
	virtual void updateRec(WdbeAMErrorPar* rec);
	virtual void updateRst(ListWdbeAMErrorPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMErrorPar** rec);
	virtual Sbecore::ubigint loadRefsByErr(Sbecore::ubigint errRefWdbeMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByErr(Sbecore::ubigint errRefWdbeMError, const bool append, ListWdbeAMErrorPar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMErrorPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMErrorPar: C++ wrapper for table TblWdbeAMErrorPar (MySQL database)
	*/
class MyTblWdbeAMErrorPar : public TblWdbeAMErrorPar, public Sbecore::MyTable {

public:
	MyTblWdbeAMErrorPar();
	~MyTblWdbeAMErrorPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMErrorPar& rst);

	Sbecore::ubigint insertRec(WdbeAMErrorPar* rec);
	void insertRst(ListWdbeAMErrorPar& rst, bool transact = false);
	void updateRec(WdbeAMErrorPar* rec);
	void updateRst(ListWdbeAMErrorPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRefsByErr(Sbecore::ubigint errRefWdbeMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByErr(Sbecore::ubigint errRefWdbeMError, const bool append, ListWdbeAMErrorPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMErrorPar: C++ wrapper for table TblWdbeAMErrorPar (PgSQL database)
	*/
class PgTblWdbeAMErrorPar : public TblWdbeAMErrorPar, public Sbecore::PgTable {

public:
	PgTblWdbeAMErrorPar();
	~PgTblWdbeAMErrorPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMErrorPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMErrorPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMErrorPar& rst);

	Sbecore::ubigint insertRec(WdbeAMErrorPar* rec);
	void insertRst(ListWdbeAMErrorPar& rst, bool transact = false);
	void updateRec(WdbeAMErrorPar* rec);
	void updateRst(ListWdbeAMErrorPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMErrorPar** rec);
	Sbecore::ubigint loadRefsByErr(Sbecore::ubigint errRefWdbeMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByErr(Sbecore::ubigint errRefWdbeMError, const bool append, ListWdbeAMErrorPar& rst);
};
#endif

#endif

