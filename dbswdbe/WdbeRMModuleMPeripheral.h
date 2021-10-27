/**
	* \file WdbeRMModuleMPeripheral.h
	* database access for table TblWdbeRMModuleMPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBERMMODULEMPERIPHERAL_H
#define WDBERMMODULEMPERIPHERAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMModuleMPeripheral: record of TblWdbeRMModuleMPeripheral
	*/
class WdbeRMModuleMPeripheral {

public:
	WdbeRMModuleMPeripheral(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMPeripheral = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMModule;
	Sbecore::ubigint refWdbeMPeripheral;

public:
	bool operator==(const WdbeRMModuleMPeripheral& comp);
	bool operator!=(const WdbeRMModuleMPeripheral& comp);
};

/**
	* ListWdbeRMModuleMPeripheral: recordset of TblWdbeRMModuleMPeripheral
	*/
class ListWdbeRMModuleMPeripheral {

public:
	ListWdbeRMModuleMPeripheral();
	ListWdbeRMModuleMPeripheral(const ListWdbeRMModuleMPeripheral& src);
	~ListWdbeRMModuleMPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeRMModuleMPeripheral* rec);

	WdbeRMModuleMPeripheral* operator[](const Sbecore::uint ix);
	ListWdbeRMModuleMPeripheral& operator=(const ListWdbeRMModuleMPeripheral& src);
	bool operator==(const ListWdbeRMModuleMPeripheral& comp);
	bool operator!=(const ListWdbeRMModuleMPeripheral& comp);

public:
	std::vector<WdbeRMModuleMPeripheral*> nodes;
};

/**
	* TblWdbeRMModuleMPeripheral: C++ wrapper for table TblWdbeRMModuleMPeripheral
	*/
class TblWdbeRMModuleMPeripheral {

public:

public:
	TblWdbeRMModuleMPeripheral();
	virtual ~TblWdbeRMModuleMPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMModuleMPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeRMModuleMPeripheral** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMPeripheral = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMModuleMPeripheral& rst, WdbeRMModuleMPeripheral** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMPeripheral = 0);
	virtual void insertRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	virtual void updateRec(WdbeRMModuleMPeripheral* rec);
	virtual void updateRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMPeripheral** rec);
	virtual Sbecore::ubigint loadMdlsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refWdbeMModules);
	virtual Sbecore::ubigint loadPphsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refWdbeMPeripherals);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMModuleMPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMModuleMPeripheral: C++ wrapper for table TblWdbeRMModuleMPeripheral (MySQL database)
	*/
class MyTblWdbeRMModuleMPeripheral : public TblWdbeRMModuleMPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeRMModuleMPeripheral();
	~MyTblWdbeRMModuleMPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeRMModuleMPeripheral* rec);
	void insertRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	void updateRec(WdbeRMModuleMPeripheral* rec);
	void updateRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMPeripheral** rec);
	Sbecore::ubigint loadMdlsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refWdbeMModules);
	Sbecore::ubigint loadPphsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refWdbeMPeripherals);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMModuleMPeripheral: C++ wrapper for table TblWdbeRMModuleMPeripheral (PgSQL database)
	*/
class PgTblWdbeRMModuleMPeripheral : public TblWdbeRMModuleMPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeRMModuleMPeripheral();
	~PgTblWdbeRMModuleMPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMModuleMPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMModuleMPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMModuleMPeripheral** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMModuleMPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMModuleMPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeRMModuleMPeripheral* rec);
	void insertRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	void updateRec(WdbeRMModuleMPeripheral* rec);
	void updateRst(ListWdbeRMModuleMPeripheral& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMModuleMPeripheral** rec);
	Sbecore::ubigint loadMdlsByPph(Sbecore::ubigint refWdbeMPeripheral, const bool append, std::vector<Sbecore::ubigint>& refWdbeMModules);
	Sbecore::ubigint loadPphsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refWdbeMPeripherals);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
