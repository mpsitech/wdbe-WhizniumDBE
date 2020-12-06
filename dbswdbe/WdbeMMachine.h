/**
	* \file WdbeMMachine.h
	* database access for table TblWdbeMMachine (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
	WdbeMMachine(const Sbecore::ubigint ref = 0, const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint supRefWdbeMMachine;
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
	Sbecore::ubigint insertNewRec(WdbeMMachine** rec = NULL, const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMMachine& rst, WdbeMMachine** rec = NULL, const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string sref = "", const Sbecore::ubigint cchRefWdbeMMachine = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMMachine& rst, bool transact = false);
	virtual void updateRec(WdbeMMachine* rec);
	virtual void updateRst(ListWdbeMMachine& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMMachine** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, ListWdbeMMachine& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMMachine);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMMachine& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWdbeMMachine& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWdbeMMachine& rst, unsigned int firstix = 0, unsigned int lastix = 0);
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
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, ListWdbeMMachine& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMMachine);
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
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMMachine& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMMachine& rst);

	Sbecore::ubigint insertRec(WdbeMMachine* rec);
	void insertRst(ListWdbeMMachine& rst, bool transact = false);
	void updateRec(WdbeMMachine* rec);
	void updateRst(ListWdbeMMachine& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMMachine** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMMachine, const bool append, ListWdbeMMachine& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMMachine);
};
#endif

#endif
