/**
	* \file WdbeMUsergroup.h
	* database access for table TblWdbeMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMUSERGROUP_H
#define WDBEMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMUsergroup: record of TblWdbeMUsergroup
	*/
class WdbeMUsergroup {

public:
	WdbeMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeMUsergroup& comp);
	bool operator!=(const WdbeMUsergroup& comp);
};

/**
	* ListWdbeMUsergroup: recordset of TblWdbeMUsergroup
	*/
class ListWdbeMUsergroup {

public:
	ListWdbeMUsergroup();
	ListWdbeMUsergroup(const ListWdbeMUsergroup& src);
	~ListWdbeMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WdbeMUsergroup* rec);

	WdbeMUsergroup* operator[](const Sbecore::uint ix);
	ListWdbeMUsergroup& operator=(const ListWdbeMUsergroup& src);
	bool operator==(const ListWdbeMUsergroup& comp);
	bool operator!=(const ListWdbeMUsergroup& comp);

public:
	std::vector<WdbeMUsergroup*> nodes;
};

/**
	* TblWdbeMUsergroup: C++ wrapper for table TblWdbeMUsergroup
	*/
class TblWdbeMUsergroup {

public:

public:
	TblWdbeMUsergroup();
	virtual ~TblWdbeMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WdbeMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WdbeMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMUsergroup& rst, WdbeMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMUsergroup& rst, bool transact = false);
	virtual void updateRec(WdbeMUsergroup* rec);
	virtual void updateRst(ListWdbeMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMUsergroup** rec);
	virtual bool loadRecBySrf(std::string sref, WdbeMUsergroup** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMUsergroup: C++ wrapper for table TblWdbeMUsergroup (MySQL database)
	*/
class MyTblWdbeMUsergroup : public TblWdbeMUsergroup, public Sbecore::MyTable {

public:
	MyTblWdbeMUsergroup();
	~MyTblWdbeMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeMUsergroup* rec);
	void insertRst(ListWdbeMUsergroup& rst, bool transact = false);
	void updateRec(WdbeMUsergroup* rec);
	void updateRst(ListWdbeMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WdbeMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMUsergroup: C++ wrapper for table TblWdbeMUsergroup (PgSQL database)
	*/
class PgTblWdbeMUsergroup : public TblWdbeMUsergroup, public Sbecore::PgTable {

public:
	PgTblWdbeMUsergroup();
	~PgTblWdbeMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeMUsergroup* rec);
	void insertRst(ListWdbeMUsergroup& rst, bool transact = false);
	void updateRec(WdbeMUsergroup* rec);
	void updateRst(ListWdbeMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WdbeMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
