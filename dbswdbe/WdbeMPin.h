/**
	* \file WdbeMPin.h
	* database access for table TblWdbeMPin (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMPIN_H
#define WDBEMPIN_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMPin: record of TblWdbeMPin
	*/
class WdbeMPin {

public:
	WdbeMPin(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCPin = 0, const Sbecore::ubigint refWdbeMBank = 0, const Sbecore::ubigint refJSref = 0, const std::string sref = "", const std::string Location = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCPin;
	Sbecore::ubigint refWdbeMBank;
	Sbecore::ubigint refJSref;
	std::string sref;
	std::string Location;

public:
	bool operator==(const WdbeMPin& comp);
	bool operator!=(const WdbeMPin& comp);
};

/**
	* ListWdbeMPin: recordset of TblWdbeMPin
	*/
class ListWdbeMPin {

public:
	ListWdbeMPin();
	ListWdbeMPin(const ListWdbeMPin& src);
	~ListWdbeMPin();

	void clear();
	unsigned int size() const;
	void append(WdbeMPin* rec);

	WdbeMPin* operator[](const Sbecore::uint ix);
	ListWdbeMPin& operator=(const ListWdbeMPin& src);
	bool operator==(const ListWdbeMPin& comp);
	bool operator!=(const ListWdbeMPin& comp);

public:
	std::vector<WdbeMPin*> nodes;
};

/**
	* TblWdbeMPin: C++ wrapper for table TblWdbeMPin
	*/
class TblWdbeMPin {

public:

public:
	TblWdbeMPin();
	virtual ~TblWdbeMPin();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMPin** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPin& rst);

	virtual Sbecore::ubigint insertRec(WdbeMPin* rec);
	Sbecore::ubigint insertNewRec(WdbeMPin** rec = NULL, const Sbecore::ubigint refWdbeCPin = 0, const Sbecore::ubigint refWdbeMBank = 0, const Sbecore::ubigint refJSref = 0, const std::string sref = "", const std::string Location = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMPin& rst, WdbeMPin** rec = NULL, const Sbecore::ubigint refWdbeCPin = 0, const Sbecore::ubigint refWdbeMBank = 0, const Sbecore::ubigint refJSref = 0, const std::string sref = "", const std::string Location = "");
	virtual void insertRst(ListWdbeMPin& rst, bool transact = false);
	virtual void updateRec(WdbeMPin* rec);
	virtual void updateRst(ListWdbeMPin& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMPin** rec);
	virtual Sbecore::ubigint loadRefsByBnk(Sbecore::ubigint refWdbeMBank, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByBnk(Sbecore::ubigint refWdbeMBank, const bool append, ListWdbeMPin& rst);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPin, const bool append, ListWdbeMPin& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMPin& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMPin: C++ wrapper for table TblWdbeMPin (MySQL database)
	*/
class MyTblWdbeMPin : public TblWdbeMPin, public Sbecore::MyTable {

public:
	MyTblWdbeMPin();
	~MyTblWdbeMPin();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPin** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPin& rst);

	Sbecore::ubigint insertRec(WdbeMPin* rec);
	void insertRst(ListWdbeMPin& rst, bool transact = false);
	void updateRec(WdbeMPin* rec);
	void updateRst(ListWdbeMPin& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPin** rec);
	Sbecore::ubigint loadRefsByBnk(Sbecore::ubigint refWdbeMBank, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBnk(Sbecore::ubigint refWdbeMBank, const bool append, ListWdbeMPin& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPin, const bool append, ListWdbeMPin& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMPin: C++ wrapper for table TblWdbeMPin (PgSQL database)
	*/
class PgTblWdbeMPin : public TblWdbeMPin, public Sbecore::PgTable {

public:
	PgTblWdbeMPin();
	~PgTblWdbeMPin();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMPin** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMPin& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMPin** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMPin& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPin** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPin& rst);

	Sbecore::ubigint insertRec(WdbeMPin* rec);
	void insertRst(ListWdbeMPin& rst, bool transact = false);
	void updateRec(WdbeMPin* rec);
	void updateRst(ListWdbeMPin& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPin** rec);
	Sbecore::ubigint loadRefsByBnk(Sbecore::ubigint refWdbeMBank, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPin, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBnk(Sbecore::ubigint refWdbeMBank, const bool append, ListWdbeMPin& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPin, const bool append, ListWdbeMPin& rst);
};
#endif

#endif

