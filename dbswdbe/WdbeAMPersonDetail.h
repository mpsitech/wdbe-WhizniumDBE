/**
	* \file WdbeAMPersonDetail.h
	* database access for table TblWdbeAMPersonDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMPERSONDETAIL_H
#define WDBEAMPERSONDETAIL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMPersonDetail: record of TblWdbeAMPersonDetail
	*/
class WdbeAMPersonDetail {

public:
	WdbeAMPersonDetail(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMPerson;
	std::string x1SrefKType;
	std::string Val;

public:
	bool operator==(const WdbeAMPersonDetail& comp);
	bool operator!=(const WdbeAMPersonDetail& comp);
};

/**
	* ListWdbeAMPersonDetail: recordset of TblWdbeAMPersonDetail
	*/
class ListWdbeAMPersonDetail {

public:
	ListWdbeAMPersonDetail();
	ListWdbeAMPersonDetail(const ListWdbeAMPersonDetail& src);
	~ListWdbeAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(WdbeAMPersonDetail* rec);

	WdbeAMPersonDetail* operator[](const Sbecore::uint ix);
	ListWdbeAMPersonDetail& operator=(const ListWdbeAMPersonDetail& src);
	bool operator==(const ListWdbeAMPersonDetail& comp);
	bool operator!=(const ListWdbeAMPersonDetail& comp);

public:
	std::vector<WdbeAMPersonDetail*> nodes;
};

/**
	* TblWdbeAMPersonDetail: C++ wrapper for table TblWdbeAMPersonDetail
	*/
class TblWdbeAMPersonDetail {

public:

public:
	TblWdbeAMPersonDetail();
	virtual ~TblWdbeAMPersonDetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPersonDetail& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMPersonDetail* rec);
	Sbecore::ubigint insertNewRec(WdbeAMPersonDetail** rec = NULL, const Sbecore::ubigint refWdbeMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMPersonDetail& rst, WdbeAMPersonDetail** rec = NULL, const Sbecore::ubigint refWdbeMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(WdbeAMPersonDetail* rec);
	virtual void updateRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(Sbecore::ubigint refWdbeMPerson, std::string x1SrefKType, WdbeAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeAMPersonDetail& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMPersonDetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMPersonDetail: C++ wrapper for table TblWdbeAMPersonDetail (MySQL database)
	*/
class MyTblWdbeAMPersonDetail : public TblWdbeAMPersonDetail, public Sbecore::MyTable {

public:
	MyTblWdbeAMPersonDetail();
	~MyTblWdbeAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WdbeAMPersonDetail* rec);
	void insertRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	void updateRec(WdbeAMPersonDetail* rec);
	void updateRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWdbeMPerson, std::string x1SrefKType, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMPersonDetail: C++ wrapper for table TblWdbeAMPersonDetail (PgSQL database)
	*/
class PgTblWdbeAMPersonDetail : public TblWdbeAMPersonDetail, public Sbecore::PgTable {

public:
	PgTblWdbeAMPersonDetail();
	~PgTblWdbeAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMPersonDetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WdbeAMPersonDetail* rec);
	void insertRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	void updateRec(WdbeAMPersonDetail* rec);
	void updateRst(ListWdbeAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWdbeMPerson, std::string x1SrefKType, WdbeAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeAMPersonDetail& rst);
};
#endif

#endif

