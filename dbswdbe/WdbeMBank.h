/**
	* \file WdbeMBank.h
	* database access for table TblWdbeMBank (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMBANK_H
#define WDBEMBANK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMBank: record of TblWdbeMBank
	*/
class WdbeMBank {

public:
	WdbeMBank(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string srefKVoltstd = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUnit;
	std::string sref;
	std::string srefKVoltstd;

public:
	bool operator==(const WdbeMBank& comp);
	bool operator!=(const WdbeMBank& comp);
};

/**
	* ListWdbeMBank: recordset of TblWdbeMBank
	*/
class ListWdbeMBank {

public:
	ListWdbeMBank();
	ListWdbeMBank(const ListWdbeMBank& src);
	~ListWdbeMBank();

	void clear();
	unsigned int size() const;
	void append(WdbeMBank* rec);

	WdbeMBank* operator[](const Sbecore::uint ix);
	ListWdbeMBank& operator=(const ListWdbeMBank& src);
	bool operator==(const ListWdbeMBank& comp);
	bool operator!=(const ListWdbeMBank& comp);

public:
	std::vector<WdbeMBank*> nodes;
};

/**
	* TblWdbeMBank: C++ wrapper for table TblWdbeMBank
	*/
class TblWdbeMBank {

public:

public:
	TblWdbeMBank();
	virtual ~TblWdbeMBank();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMBank** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMBank& rst);

	virtual Sbecore::ubigint insertRec(WdbeMBank* rec);
	Sbecore::ubigint insertNewRec(WdbeMBank** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string srefKVoltstd = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMBank& rst, WdbeMBank** rec = NULL, const Sbecore::ubigint refWdbeMUnit = 0, const std::string sref = "", const std::string srefKVoltstd = "");
	virtual void insertRst(ListWdbeMBank& rst, bool transact = false);
	virtual void updateRec(WdbeMBank* rec);
	virtual void updateRst(ListWdbeMBank& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMBank** rec);
	virtual Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMBank& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMBank& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMBank: C++ wrapper for table TblWdbeMBank (MySQL database)
	*/
class MyTblWdbeMBank : public TblWdbeMBank, public Sbecore::MyTable {

public:
	MyTblWdbeMBank();
	~MyTblWdbeMBank();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMBank& rst);

	Sbecore::ubigint insertRec(WdbeMBank* rec);
	void insertRst(ListWdbeMBank& rst, bool transact = false);
	void updateRec(WdbeMBank* rec);
	void updateRst(ListWdbeMBank& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMBank** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMBank& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMBank: C++ wrapper for table TblWdbeMBank (PgSQL database)
	*/
class PgTblWdbeMBank : public TblWdbeMBank, public Sbecore::PgTable {

public:
	PgTblWdbeMBank();
	~PgTblWdbeMBank();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMBank** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMBank& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMBank** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMBank& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMBank& rst);

	Sbecore::ubigint insertRec(WdbeMBank* rec);
	void insertRst(ListWdbeMBank& rst, bool transact = false);
	void updateRec(WdbeMBank* rec);
	void updateRst(ListWdbeMBank& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMBank** rec);
	Sbecore::ubigint loadRefsByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUnt(Sbecore::ubigint refWdbeMUnit, const bool append, ListWdbeMBank& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

