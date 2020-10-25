/**
	* \file WdbeJMPersonLastname.h
	* database access for table TblWdbeJMPersonLastname (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEJMPERSONLASTNAME_H
#define WDBEJMPERSONLASTNAME_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeJMPersonLastname: record of TblWdbeJMPersonLastname
	*/
class WdbeJMPersonLastname {

public:
	WdbeJMPersonLastname(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMPerson;
	Sbecore::uint x1Startd;
	std::string Lastname;

public:
	bool operator==(const WdbeJMPersonLastname& comp);
	bool operator!=(const WdbeJMPersonLastname& comp);
};

/**
	* ListWdbeJMPersonLastname: recordset of TblWdbeJMPersonLastname
	*/
class ListWdbeJMPersonLastname {

public:
	ListWdbeJMPersonLastname();
	ListWdbeJMPersonLastname(const ListWdbeJMPersonLastname& src);
	~ListWdbeJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(WdbeJMPersonLastname* rec);

	WdbeJMPersonLastname* operator[](const Sbecore::uint ix);
	ListWdbeJMPersonLastname& operator=(const ListWdbeJMPersonLastname& src);
	bool operator==(const ListWdbeJMPersonLastname& comp);
	bool operator!=(const ListWdbeJMPersonLastname& comp);

public:
	std::vector<WdbeJMPersonLastname*> nodes;
};

/**
	* TblWdbeJMPersonLastname: C++ wrapper for table TblWdbeJMPersonLastname
	*/
class TblWdbeJMPersonLastname {

public:

public:
	TblWdbeJMPersonLastname();
	virtual ~TblWdbeJMPersonLastname();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPersonLastname& rst);

	virtual Sbecore::ubigint insertRec(WdbeJMPersonLastname* rec);
	Sbecore::ubigint insertNewRec(WdbeJMPersonLastname** rec = NULL, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeJMPersonLastname& rst, WdbeJMPersonLastname** rec = NULL, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	virtual void insertRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(WdbeJMPersonLastname* rec);
	virtual void updateRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(Sbecore::ubigint refWdbeMPerson, Sbecore::uint x1Startd, WdbeJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeJMPersonLastname& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeJMPersonLastname& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeJMPersonLastname: C++ wrapper for table TblWdbeJMPersonLastname (MySQL database)
	*/
class MyTblWdbeJMPersonLastname : public TblWdbeJMPersonLastname, public Sbecore::MyTable {

public:
	MyTblWdbeJMPersonLastname();
	~MyTblWdbeJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WdbeJMPersonLastname* rec);
	void insertRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	void updateRec(WdbeJMPersonLastname* rec);
	void updateRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWdbeMPerson, Sbecore::uint x1Startd, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeJMPersonLastname: C++ wrapper for table TblWdbeJMPersonLastname (PgSQL database)
	*/
class PgTblWdbeJMPersonLastname : public TblWdbeJMPersonLastname, public Sbecore::PgTable {

public:
	PgTblWdbeJMPersonLastname();
	~PgTblWdbeJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeJMPersonLastname& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WdbeJMPersonLastname* rec);
	void insertRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	void updateRec(WdbeJMPersonLastname* rec);
	void updateRst(ListWdbeJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWdbeMPerson, Sbecore::uint x1Startd, WdbeJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeJMPersonLastname& rst);
};
#endif

#endif

