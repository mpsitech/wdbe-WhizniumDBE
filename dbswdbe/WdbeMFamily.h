/**
	* \file WdbeMFamily.h
	* database access for table TblWdbeMFamily (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMFAMILY_H
#define WDBEMFAMILY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMFamily: record of TblWdbeMFamily
	*/
class WdbeMFamily {

public:
	WdbeMFamily(const Sbecore::ubigint ref = 0, const std::string srefKVendor = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	std::string srefKVendor;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WdbeMFamily& comp);
	bool operator!=(const WdbeMFamily& comp);
};

/**
	* ListWdbeMFamily: recordset of TblWdbeMFamily
	*/
class ListWdbeMFamily {

public:
	ListWdbeMFamily();
	ListWdbeMFamily(const ListWdbeMFamily& src);
	~ListWdbeMFamily();

	void clear();
	unsigned int size() const;
	void append(WdbeMFamily* rec);

	WdbeMFamily* operator[](const Sbecore::uint ix);
	ListWdbeMFamily& operator=(const ListWdbeMFamily& src);
	bool operator==(const ListWdbeMFamily& comp);
	bool operator!=(const ListWdbeMFamily& comp);

public:
	std::vector<WdbeMFamily*> nodes;
};

/**
	* TblWdbeMFamily: C++ wrapper for table TblWdbeMFamily
	*/
class TblWdbeMFamily {

public:

public:
	TblWdbeMFamily();
	virtual ~TblWdbeMFamily();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMFamily** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFamily& rst);

	virtual Sbecore::ubigint insertRec(WdbeMFamily* rec);
	Sbecore::ubigint insertNewRec(WdbeMFamily** rec = NULL, const std::string srefKVendor = "", const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMFamily& rst, WdbeMFamily** rec = NULL, const std::string srefKVendor = "", const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMFamily& rst, bool transact = false);
	virtual void updateRec(WdbeMFamily* rec);
	virtual void updateRst(ListWdbeMFamily& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMFamily** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMFamily& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMFamily: C++ wrapper for table TblWdbeMFamily (MySQL database)
	*/
class MyTblWdbeMFamily : public TblWdbeMFamily, public Sbecore::MyTable {

public:
	MyTblWdbeMFamily();
	~MyTblWdbeMFamily();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFamily** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFamily& rst);

	Sbecore::ubigint insertRec(WdbeMFamily* rec);
	void insertRst(ListWdbeMFamily& rst, bool transact = false);
	void updateRec(WdbeMFamily* rec);
	void updateRst(ListWdbeMFamily& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFamily** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMFamily: C++ wrapper for table TblWdbeMFamily (PgSQL database)
	*/
class PgTblWdbeMFamily : public TblWdbeMFamily, public Sbecore::PgTable {

public:
	PgTblWdbeMFamily();
	~PgTblWdbeMFamily();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMFamily** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMFamily& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMFamily** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFamily** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFamily& rst);

	Sbecore::ubigint insertRec(WdbeMFamily* rec);
	void insertRst(ListWdbeMFamily& rst, bool transact = false);
	void updateRec(WdbeMFamily* rec);
	void updateRst(ListWdbeMFamily& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFamily** rec);
};
#endif

#endif

