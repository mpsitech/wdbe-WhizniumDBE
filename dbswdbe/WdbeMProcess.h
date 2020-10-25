/**
	* \file WdbeMProcess.h
	* database access for table TblWdbeMProcess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMPROCESS_H
#define WDBEMPROCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMProcess: record of TblWdbeMProcess
	*/
class WdbeMProcess {

public:
	WdbeMProcess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMFsm = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const bool Falling = false, const std::string Syncrst = "", const bool Extip = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMModule;
	Sbecore::ubigint refWdbeMFsm;
	std::string sref;
	std::string clkSrefWdbeMSignal;
	std::string asrSrefWdbeMSignal;
	bool Falling;
	std::string Syncrst;
	bool Extip;
	std::string Comment;

public:
	bool operator==(const WdbeMProcess& comp);
	bool operator!=(const WdbeMProcess& comp);
};

/**
	* ListWdbeMProcess: recordset of TblWdbeMProcess
	*/
class ListWdbeMProcess {

public:
	ListWdbeMProcess();
	ListWdbeMProcess(const ListWdbeMProcess& src);
	~ListWdbeMProcess();

	void clear();
	unsigned int size() const;
	void append(WdbeMProcess* rec);

	WdbeMProcess* operator[](const Sbecore::uint ix);
	ListWdbeMProcess& operator=(const ListWdbeMProcess& src);
	bool operator==(const ListWdbeMProcess& comp);
	bool operator!=(const ListWdbeMProcess& comp);

public:
	std::vector<WdbeMProcess*> nodes;
};

/**
	* TblWdbeMProcess: C++ wrapper for table TblWdbeMProcess
	*/
class TblWdbeMProcess {

public:

public:
	TblWdbeMProcess();
	virtual ~TblWdbeMProcess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMProcess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProcess& rst);

	virtual Sbecore::ubigint insertRec(WdbeMProcess* rec);
	Sbecore::ubigint insertNewRec(WdbeMProcess** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMFsm = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const bool Falling = false, const std::string Syncrst = "", const bool Extip = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMProcess& rst, WdbeMProcess** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint refWdbeMFsm = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const bool Falling = false, const std::string Syncrst = "", const bool Extip = false, const std::string Comment = "");
	virtual void insertRst(ListWdbeMProcess& rst, bool transact = false);
	virtual void updateRec(WdbeMProcess* rec);
	virtual void updateRst(ListWdbeMProcess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMProcess** rec);
	virtual bool loadRecByFsm(Sbecore::ubigint refWdbeMFsm, WdbeMProcess** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMProcess& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMProcess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMProcess: C++ wrapper for table TblWdbeMProcess (MySQL database)
	*/
class MyTblWdbeMProcess : public TblWdbeMProcess, public Sbecore::MyTable {

public:
	MyTblWdbeMProcess();
	~MyTblWdbeMProcess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMProcess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProcess& rst);

	Sbecore::ubigint insertRec(WdbeMProcess* rec);
	void insertRst(ListWdbeMProcess& rst, bool transact = false);
	void updateRec(WdbeMProcess* rec);
	void updateRst(ListWdbeMProcess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMProcess** rec);
	bool loadRecByFsm(Sbecore::ubigint refWdbeMFsm, WdbeMProcess** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMProcess& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMProcess: C++ wrapper for table TblWdbeMProcess (PgSQL database)
	*/
class PgTblWdbeMProcess : public TblWdbeMProcess, public Sbecore::PgTable {

public:
	PgTblWdbeMProcess();
	~PgTblWdbeMProcess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMProcess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMProcess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMProcess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMProcess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMProcess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProcess& rst);

	Sbecore::ubigint insertRec(WdbeMProcess* rec);
	void insertRst(ListWdbeMProcess& rst, bool transact = false);
	void updateRec(WdbeMProcess* rec);
	void updateRst(ListWdbeMProcess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMProcess** rec);
	bool loadRecByFsm(Sbecore::ubigint refWdbeMFsm, WdbeMProcess** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMProcess& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

