/**
	* \file WdbeJMPinSref.h
	* database access for table TblWdbeJMPinSref (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEJMPINSREF_H
#define WDBEJMPINSREF_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJMPinSref: record of TblWdbeJMPinSref
	*/
class WdbeJMPinSref {

public:
	WdbeJMPinSref(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMPin = 0, const Sbecore::ubigint x1RefWdbeMPeripheral = 0, const std::string sref = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMPin;
	Sbecore::ubigint x1RefWdbeMPeripheral;
	std::string sref;

public:
	bool operator==(const WdbeJMPinSref& comp);
	bool operator!=(const WdbeJMPinSref& comp);
};

/**
	* ListWdbeJMPinSref: recordset of TblWdbeJMPinSref
	*/
class ListWdbeJMPinSref {

public:
	ListWdbeJMPinSref();
	ListWdbeJMPinSref(const ListWdbeJMPinSref& src);
	~ListWdbeJMPinSref();

	void clear();
	unsigned int size() const;
	void append(WdbeJMPinSref* rec);

	WdbeJMPinSref* operator[](const Sbecore::uint ix);
	ListWdbeJMPinSref& operator=(const ListWdbeJMPinSref& src);
	bool operator==(const ListWdbeJMPinSref& comp);
	bool operator!=(const ListWdbeJMPinSref& comp);

public:
	std::vector<WdbeJMPinSref*> nodes;
};

/**
	* TblWdbeJMPinSref: C++ wrapper for table TblWdbeJMPinSref
	*/
class TblWdbeJMPinSref {

public:

public:
	TblWdbeJMPinSref();
	virtual ~TblWdbeJMPinSref();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJMPinSref** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPinSref& rst);

	virtual Sbecore::ubigint insertRec(WdbeJMPinSref* rec);
	Sbecore::ubigint insertNewRec(WdbeJMPinSref** rec = NULL, const Sbecore::ubigint refWdbeMPin = 0, const Sbecore::ubigint x1RefWdbeMPeripheral = 0, const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeJMPinSref& rst, WdbeJMPinSref** rec = NULL, const Sbecore::ubigint refWdbeMPin = 0, const Sbecore::ubigint x1RefWdbeMPeripheral = 0, const std::string sref = "");
	virtual void insertRst(ListWdbeJMPinSref& rst, bool transact = false);
	virtual void updateRec(WdbeJMPinSref* rec);
	virtual void updateRst(ListWdbeJMPinSref& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPinSref** rec);
	virtual bool loadRecByPinPph(Sbecore::ubigint refWdbeMPin, Sbecore::ubigint x1RefWdbeMPeripheral, WdbeJMPinSref** rec);
	virtual Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeJMPinSref& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJMPinSref& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJMPinSref: C++ wrapper for table TblWdbeJMPinSref (MySQL database)
	*/
class MyTblWdbeJMPinSref : public TblWdbeJMPinSref, public Sbecore::MyTable {

public:
	MyTblWdbeJMPinSref();
	~MyTblWdbeJMPinSref();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPinSref& rst);

	Sbecore::ubigint insertRec(WdbeJMPinSref* rec);
	void insertRst(ListWdbeJMPinSref& rst, bool transact = false);
	void updateRec(WdbeJMPinSref* rec);
	void updateRst(ListWdbeJMPinSref& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPinSref** rec);
	bool loadRecByPinPph(Sbecore::ubigint refWdbeMPin, Sbecore::ubigint x1RefWdbeMPeripheral, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeJMPinSref& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJMPinSref: C++ wrapper for table TblWdbeJMPinSref (PgSQL database)
	*/
class PgTblWdbeJMPinSref : public TblWdbeJMPinSref, public Sbecore::PgTable {

public:
	PgTblWdbeJMPinSref();
	~PgTblWdbeJMPinSref();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJMPinSref& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJMPinSref& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPinSref& rst);

	Sbecore::ubigint insertRec(WdbeJMPinSref* rec);
	void insertRst(ListWdbeJMPinSref& rst, bool transact = false);
	void updateRec(WdbeJMPinSref* rec);
	void updateRst(ListWdbeJMPinSref& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPinSref** rec);
	bool loadRecByPinPph(Sbecore::ubigint refWdbeMPin, Sbecore::ubigint x1RefWdbeMPeripheral, WdbeJMPinSref** rec);
	Sbecore::ubigint loadRefsByPin(Sbecore::ubigint refWdbeMPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPin(Sbecore::ubigint refWdbeMPin, const bool append, ListWdbeJMPinSref& rst);
};
#endif

#endif

