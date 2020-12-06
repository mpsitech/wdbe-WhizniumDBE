/**
	* \file WdbeAMModulePar.h
	* database access for table TblWdbeAMModulePar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMMODULEPAR_H
#define WDBEAMMODULEPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMModulePar: record of TblWdbeAMModulePar
	*/
class WdbeAMModulePar {

public:
	WdbeAMModulePar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint mdlRefWdbeMModule;
	Sbecore::uint mdlNum;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WdbeAMModulePar& comp);
	bool operator!=(const WdbeAMModulePar& comp);
};

/**
	* ListWdbeAMModulePar: recordset of TblWdbeAMModulePar
	*/
class ListWdbeAMModulePar {

public:
	ListWdbeAMModulePar();
	ListWdbeAMModulePar(const ListWdbeAMModulePar& src);
	~ListWdbeAMModulePar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMModulePar* rec);

	WdbeAMModulePar* operator[](const Sbecore::uint ix);
	ListWdbeAMModulePar& operator=(const ListWdbeAMModulePar& src);
	bool operator==(const ListWdbeAMModulePar& comp);
	bool operator!=(const ListWdbeAMModulePar& comp);

public:
	std::vector<WdbeAMModulePar*> nodes;
};

/**
	* TblWdbeAMModulePar: C++ wrapper for table TblWdbeAMModulePar
	*/
class TblWdbeAMModulePar {

public:

public:
	TblWdbeAMModulePar();
	virtual ~TblWdbeAMModulePar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMModulePar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMModulePar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMModulePar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMModulePar** rec = NULL, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMModulePar& rst, WdbeAMModulePar** rec = NULL, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAMModulePar& rst, bool transact = false);
	virtual void updateRec(WdbeAMModulePar* rec);
	virtual void updateRst(ListWdbeAMModulePar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMModulePar** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeAMModulePar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMModulePar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMModulePar: C++ wrapper for table TblWdbeAMModulePar (MySQL database)
	*/
class MyTblWdbeAMModulePar : public TblWdbeAMModulePar, public Sbecore::MyTable {

public:
	MyTblWdbeAMModulePar();
	~MyTblWdbeAMModulePar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMModulePar& rst);

	Sbecore::ubigint insertRec(WdbeAMModulePar* rec);
	void insertRst(ListWdbeAMModulePar& rst, bool transact = false);
	void updateRec(WdbeAMModulePar* rec);
	void updateRst(ListWdbeAMModulePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeAMModulePar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMModulePar: C++ wrapper for table TblWdbeAMModulePar (PgSQL database)
	*/
class PgTblWdbeAMModulePar : public TblWdbeAMModulePar, public Sbecore::PgTable {

public:
	PgTblWdbeAMModulePar();
	~PgTblWdbeAMModulePar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMModulePar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMModulePar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMModulePar& rst);

	Sbecore::ubigint insertRec(WdbeAMModulePar* rec);
	void insertRst(ListWdbeAMModulePar& rst, bool transact = false);
	void updateRec(WdbeAMModulePar* rec);
	void updateRst(ListWdbeAMModulePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMModulePar** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeAMModulePar& rst);
};
#endif

#endif
