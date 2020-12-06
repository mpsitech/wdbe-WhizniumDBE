/**
	* \file WdbeMController.h
	* database access for table TblWdbeMController (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMCONTROLLER_H
#define WDBEMCONTROLLER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMController: record of TblWdbeMController
	*/
class WdbeMController {

public:
	WdbeMController(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint fwdRefWdbeMUnit = 0, const std::string Fullsref = "", const Sbecore::ubigint clrRefWdbeMSignal = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMModule;
	Sbecore::ubigint fwdRefWdbeMUnit;
	std::string Fullsref;
	Sbecore::ubigint clrRefWdbeMSignal;

public:
	bool operator==(const WdbeMController& comp);
	bool operator!=(const WdbeMController& comp);
};

/**
	* ListWdbeMController: recordset of TblWdbeMController
	*/
class ListWdbeMController {

public:
	ListWdbeMController();
	ListWdbeMController(const ListWdbeMController& src);
	~ListWdbeMController();

	void clear();
	unsigned int size() const;
	void append(WdbeMController* rec);

	WdbeMController* operator[](const Sbecore::uint ix);
	ListWdbeMController& operator=(const ListWdbeMController& src);
	bool operator==(const ListWdbeMController& comp);
	bool operator!=(const ListWdbeMController& comp);

public:
	std::vector<WdbeMController*> nodes;
};

/**
	* TblWdbeMController: C++ wrapper for table TblWdbeMController
	*/
class TblWdbeMController {

public:

public:
	TblWdbeMController();
	virtual ~TblWdbeMController();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMController** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMController& rst);

	virtual Sbecore::ubigint insertRec(WdbeMController* rec);
	Sbecore::ubigint insertNewRec(WdbeMController** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint fwdRefWdbeMUnit = 0, const std::string Fullsref = "", const Sbecore::ubigint clrRefWdbeMSignal = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMController& rst, WdbeMController** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::ubigint fwdRefWdbeMUnit = 0, const std::string Fullsref = "", const Sbecore::ubigint clrRefWdbeMSignal = 0);
	virtual void insertRst(ListWdbeMController& rst, bool transact = false);
	virtual void updateRec(WdbeMController* rec);
	virtual void updateRst(ListWdbeMController& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMController** rec);
	virtual bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	virtual bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMController** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMController& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMController: C++ wrapper for table TblWdbeMController (MySQL database)
	*/
class MyTblWdbeMController : public TblWdbeMController, public Sbecore::MyTable {

public:
	MyTblWdbeMController();
	~MyTblWdbeMController();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMController& rst);

	Sbecore::ubigint insertRec(WdbeMController* rec);
	void insertRst(ListWdbeMController& rst, bool transact = false);
	void updateRec(WdbeMController* rec);
	void updateRst(ListWdbeMController& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMController** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMController** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMController: C++ wrapper for table TblWdbeMController (PgSQL database)
	*/
class PgTblWdbeMController : public TblWdbeMController, public Sbecore::PgTable {

public:
	PgTblWdbeMController();
	~PgTblWdbeMController();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMController** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMController& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMController** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMController& rst);

	Sbecore::ubigint insertRec(WdbeMController* rec);
	void insertRst(ListWdbeMController& rst, bool transact = false);
	void updateRec(WdbeMController* rec);
	void updateRst(ListWdbeMController& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMController** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMController** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
