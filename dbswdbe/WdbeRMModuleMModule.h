/**
	* \file WdbeRMModuleMModule.h
	* database access for table TblWdbeRMModuleMModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBERMMODULEMMODULE_H
#define WDBERMMODULEMMODULE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMModuleMModule: record of TblWdbeRMModuleMModule
	*/
class WdbeRMModuleMModule {

public:
	WdbeRMModuleMModule(const Sbecore::ubigint ref = 0, const Sbecore::ubigint ctdRefWdbeMModule = 0, const Sbecore::ubigint corRefWdbeMModule = 0, const std::string srefKFunction = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint ctdRefWdbeMModule;
	Sbecore::ubigint corRefWdbeMModule;
	std::string srefKFunction;

public:
	bool operator==(const WdbeRMModuleMModule& comp);
	bool operator!=(const WdbeRMModuleMModule& comp);
};

/**
	* ListWdbeRMModuleMModule: recordset of TblWdbeRMModuleMModule
	*/
class ListWdbeRMModuleMModule {

public:
	ListWdbeRMModuleMModule();
	ListWdbeRMModuleMModule(const ListWdbeRMModuleMModule& src);
	~ListWdbeRMModuleMModule();

	void clear();
	unsigned int size() const;
	void append(WdbeRMModuleMModule* rec);

	WdbeRMModuleMModule* operator[](const Sbecore::uint ix);
	ListWdbeRMModuleMModule& operator=(const ListWdbeRMModuleMModule& src);
	bool operator==(const ListWdbeRMModuleMModule& comp);
	bool operator!=(const ListWdbeRMModuleMModule& comp);

public:
	std::vector<WdbeRMModuleMModule*> nodes;
};

/**
	* TblWdbeRMModuleMModule: C++ wrapper for table TblWdbeRMModuleMModule
	*/
class TblWdbeRMModuleMModule {

public:

public:
	TblWdbeRMModuleMModule();
	virtual ~TblWdbeRMModuleMModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMModuleMModule* rec);
	Sbecore::ubigint insertNewRec(WdbeRMModuleMModule** rec = NULL, const Sbecore::ubigint ctdRefWdbeMModule = 0, const Sbecore::ubigint corRefWdbeMModule = 0, const std::string srefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMModuleMModule& rst, WdbeRMModuleMModule** rec = NULL, const Sbecore::ubigint ctdRefWdbeMModule = 0, const Sbecore::ubigint corRefWdbeMModule = 0, const std::string srefKFunction = "");
	virtual void insertRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	virtual void updateRec(WdbeRMModuleMModule* rec);
	virtual void updateRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMModule** rec);
	virtual Sbecore::ubigint loadRefsByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCor(Sbecore::ubigint corRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
	virtual Sbecore::ubigint loadRstByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMModuleMModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMModuleMModule: C++ wrapper for table TblWdbeRMModuleMModule (MySQL database)
	*/
class MyTblWdbeRMModuleMModule : public TblWdbeRMModuleMModule, public Sbecore::MyTable {

public:
	MyTblWdbeRMModuleMModule();
	~MyTblWdbeRMModuleMModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMModule& rst);

	Sbecore::ubigint insertRec(WdbeRMModuleMModule* rec);
	void insertRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	void updateRec(WdbeRMModuleMModule* rec);
	void updateRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRefsByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCor(Sbecore::ubigint corRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
	Sbecore::ubigint loadRstByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMModuleMModule: C++ wrapper for table TblWdbeRMModuleMModule (PgSQL database)
	*/
class PgTblWdbeRMModuleMModule : public TblWdbeRMModuleMModule, public Sbecore::PgTable {

public:
	PgTblWdbeRMModuleMModule();
	~PgTblWdbeRMModuleMModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMModuleMModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMModuleMModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMModule& rst);

	Sbecore::ubigint insertRec(WdbeRMModuleMModule* rec);
	void insertRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	void updateRec(WdbeRMModuleMModule* rec);
	void updateRst(ListWdbeRMModuleMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMModule** rec);
	Sbecore::ubigint loadRefsByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCor(Sbecore::ubigint corRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
	Sbecore::ubigint loadRstByCtd(Sbecore::ubigint ctdRefWdbeMModule, const bool append, ListWdbeRMModuleMModule& rst);
};
#endif

#endif
