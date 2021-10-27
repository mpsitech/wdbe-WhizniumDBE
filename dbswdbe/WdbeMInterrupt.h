/**
	* \file WdbeMInterrupt.h
	* database access for table TblWdbeMInterrupt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMINTERRUPT_H
#define WDBEMINTERRUPT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMInterrupt: record of TblWdbeMInterrupt
	*/
class WdbeMInterrupt {

public:
	WdbeMInterrupt(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUnit;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeMInterrupt& comp);
	bool operator!=(const WdbeMInterrupt& comp);
};

/**
	* ListWdbeMInterrupt: recordset of TblWdbeMInterrupt
	*/
class ListWdbeMInterrupt {

public:
	ListWdbeMInterrupt();
	ListWdbeMInterrupt(const ListWdbeMInterrupt& src);
	~ListWdbeMInterrupt();

	void clear();
	unsigned int size() const;
	void append(WdbeMInterrupt* rec);

	WdbeMInterrupt* operator[](const Sbecore::uint ix);
	ListWdbeMInterrupt& operator=(const ListWdbeMInterrupt& src);
	bool operator==(const ListWdbeMInterrupt& comp);
	bool operator!=(const ListWdbeMInterrupt& comp);

public:
	std::vector<WdbeMInterrupt*> nodes;
};

/**
	* TblWdbeMInterrupt: C++ wrapper for table TblWdbeMInterrupt
	*/
class TblWdbeMInterrupt {

public:

public:
	TblWdbeMInterrupt();
	virtual ~TblWdbeMInterrupt();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMInterrupt** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMInterrupt& rst);

	virtual Sbecore::ubigint insertRec(WdbeMInterrupt* rec);
	Sbecore::ubigint insertNewRec(WdbeMInterrupt** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMInterrupt& rst, WdbeMInterrupt** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMInterrupt& rst, bool transact = false);
	virtual void updateRec(WdbeMInterrupt* rec);
	virtual void updateRst(ListWdbeMInterrupt& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMInterrupt** rec);
	virtual Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMInterrupt& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMInterrupt& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMInterrupt: C++ wrapper for table TblWdbeMInterrupt (MySQL database)
	*/
class MyTblWdbeMInterrupt : public TblWdbeMInterrupt, public Sbecore::MyTable {

public:
	MyTblWdbeMInterrupt();
	~MyTblWdbeMInterrupt();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeMInterrupt* rec);
	void insertRst(ListWdbeMInterrupt& rst, bool transact = false);
	void updateRec(WdbeMInterrupt* rec);
	void updateRst(ListWdbeMInterrupt& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMInterrupt& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMInterrupt: C++ wrapper for table TblWdbeMInterrupt (PgSQL database)
	*/
class PgTblWdbeMInterrupt : public TblWdbeMInterrupt, public Sbecore::PgTable {

public:
	PgTblWdbeMInterrupt();
	~PgTblWdbeMInterrupt();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMInterrupt& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMInterrupt& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeMInterrupt* rec);
	void insertRst(ListWdbeMInterrupt& rst, bool transact = false);
	void updateRec(WdbeMInterrupt* rec);
	void updateRst(ListWdbeMInterrupt& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMInterrupt** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMInterrupt& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
