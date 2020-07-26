/**
	* \file WdbeMMachine.h
	* database access for table TblWdbeMMachine (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMMACHINE_H
#define WDBEMMACHINE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMMachine: record of TblWdbeMMachine
	*/
class WdbeMMachine {

public:
	WdbeMMachine(const Sbecore::ubigint ref = 0, const std::string srefKPlatform = "", const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	std::string srefKPlatform;
	std::string sref;
	Sbecore::ubigint cchRefWdbeMMachine;
	std::string Comment;

public:
	bool operator==(const WdbeMMachine& comp);
	bool operator!=(const WdbeMMachine& comp);
};

/**
	* ListWdbeMMachine: recordset of TblWdbeMMachine
	*/
class ListWdbeMMachine {

public:
	ListWdbeMMachine();
	ListWdbeMMachine(const ListWdbeMMachine& src);
	~ListWdbeMMachine();

	void clear();
	unsigned int size() const;
	void append(WdbeMMachine* rec);

	WdbeMMachine* operator[](const Sbecore::uint ix);
	ListWdbeMMachine& operator=(const ListWdbeMMachine& src);
	bool operator==(const ListWdbeMMachine& comp);
	bool operator!=(const ListWdbeMMachine& comp);

public:
	std::vector<WdbeMMachine*> nodes;
};

/**
	* TblWdbeMMachine: C++ wrapper for table TblWdbeMMachine
	*/
class TblWdbeMMachine {

public:

public:
	TblWdbeMMachine();
	virtual ~TblWdbeMMachine();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMMachine** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMMachine& rst);

	virtual Sbecore::ubigint insertRec(WdbeMMachine* rec);
	Sbecore::ubigint insertNewRec(WdbeMMachine** rec = NULL, const std::string srefKPlatform = "", const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMMachine& rst, WdbeMMachine** rec = NULL, const std::string srefKPlatform = "", const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMMachine& rst, bool transact = false);
	virtual void updateRec(WdbeMMachine* rec);
	virtual void updateRst(ListWdbeMMachine& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMMachine** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMMachine& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMMachine: C++ wrapper for table TblWdbeMMachine (MySQL database)
	*/
class MyTblWdbeMMachine : public TblWdbeMMachine, public Sbecore::MyTable {

public:
	MyTblWdbeMMachine();
	~MyTblWdbeMMachine();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMMachine& rst);

	Sbecore::ubigint insertRec(WdbeMMachine* rec);
	void insertRst(ListWdbeMMachine& rst, bool transact = false);
	void updateRec(WdbeMMachine* rec);
	void updateRst(ListWdbeMMachine& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMMachine** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMMachine: C++ wrapper for table TblWdbeMMachine (PgSQL database)
	*/
class PgTblWdbeMMachine : public TblWdbeMMachine, public Sbecore::PgTable {

public:
	PgTblWdbeMMachine();
	~PgTblWdbeMMachine();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMMachine** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMMachine& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMMachine** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMMachine& rst);

	Sbecore::ubigint insertRec(WdbeMMachine* rec);
	void insertRst(ListWdbeMMachine& rst, bool transact = false);
	void updateRec(WdbeMMachine* rec);
	void updateRst(ListWdbeMMachine& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMMachine** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

