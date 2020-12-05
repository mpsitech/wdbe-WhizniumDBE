/**
	* \file WdbeRMCommandMController.h
	* database access for table TblWdbeRMCommandMController (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBERMCOMMANDMCONTROLLER_H
#define WDBERMCOMMANDMCONTROLLER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMCommandMController: record of TblWdbeRMCommandMController
	*/
class WdbeRMCommandMController {

public:
	WdbeRMCommandMController(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMCommand = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMCommand;
	Sbecore::ubigint refWdbeMController;
	Sbecore::ubigint ivrRefWdbeMSignal;
	Sbecore::ubigint rvrRefWdbeMSignal;

public:
	bool operator==(const WdbeRMCommandMController& comp);
	bool operator!=(const WdbeRMCommandMController& comp);
};

/**
	* ListWdbeRMCommandMController: recordset of TblWdbeRMCommandMController
	*/
class ListWdbeRMCommandMController {

public:
	ListWdbeRMCommandMController();
	ListWdbeRMCommandMController(const ListWdbeRMCommandMController& src);
	~ListWdbeRMCommandMController();

	void clear();
	unsigned int size() const;
	void append(WdbeRMCommandMController* rec);

	WdbeRMCommandMController* operator[](const Sbecore::uint ix);
	ListWdbeRMCommandMController& operator=(const ListWdbeRMCommandMController& src);
	bool operator==(const ListWdbeRMCommandMController& comp);
	bool operator!=(const ListWdbeRMCommandMController& comp);

public:
	std::vector<WdbeRMCommandMController*> nodes;
};

/**
	* TblWdbeRMCommandMController: C++ wrapper for table TblWdbeRMCommandMController
	*/
class TblWdbeRMCommandMController {

public:

public:
	TblWdbeRMCommandMController();
	virtual ~TblWdbeRMCommandMController();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMCommandMController** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCommandMController& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMCommandMController* rec);
	Sbecore::ubigint insertNewRec(WdbeRMCommandMController** rec = NULL, const Sbecore::ubigint refWdbeMCommand = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMCommandMController& rst, WdbeRMCommandMController** rec = NULL, const Sbecore::ubigint refWdbeMCommand = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0);
	virtual void insertRst(ListWdbeRMCommandMController& rst, bool transact = false);
	virtual void updateRec(WdbeRMCommandMController* rec);
	virtual void updateRst(ListWdbeRMCommandMController& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCommandMController** rec);
	virtual Sbecore::ubigint loadRefsByCtr(Sbecore::ubigint refWdbeMController, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCmd(Sbecore::ubigint refWdbeMCommand, const bool append, ListWdbeRMCommandMController& rst);
	virtual Sbecore::ubigint loadRstByCtr(Sbecore::ubigint refWdbeMController, const bool append, ListWdbeRMCommandMController& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMCommandMController& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMCommandMController: C++ wrapper for table TblWdbeRMCommandMController (MySQL database)
	*/
class MyTblWdbeRMCommandMController : public TblWdbeRMCommandMController, public Sbecore::MyTable {

public:
	MyTblWdbeRMCommandMController();
	~MyTblWdbeRMCommandMController();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCommandMController& rst);

	Sbecore::ubigint insertRec(WdbeRMCommandMController* rec);
	void insertRst(ListWdbeRMCommandMController& rst, bool transact = false);
	void updateRec(WdbeRMCommandMController* rec);
	void updateRst(ListWdbeRMCommandMController& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRefsByCtr(Sbecore::ubigint refWdbeMController, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint refWdbeMCommand, const bool append, ListWdbeRMCommandMController& rst);
	Sbecore::ubigint loadRstByCtr(Sbecore::ubigint refWdbeMController, const bool append, ListWdbeRMCommandMController& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMCommandMController: C++ wrapper for table TblWdbeRMCommandMController (PgSQL database)
	*/
class PgTblWdbeRMCommandMController : public TblWdbeRMCommandMController, public Sbecore::PgTable {

public:
	PgTblWdbeRMCommandMController();
	~PgTblWdbeRMCommandMController();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMCommandMController& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMCommandMController& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCommandMController& rst);

	Sbecore::ubigint insertRec(WdbeRMCommandMController* rec);
	void insertRst(ListWdbeRMCommandMController& rst, bool transact = false);
	void updateRec(WdbeRMCommandMController* rec);
	void updateRst(ListWdbeRMCommandMController& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCommandMController** rec);
	Sbecore::ubigint loadRefsByCtr(Sbecore::ubigint refWdbeMController, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint refWdbeMCommand, const bool append, ListWdbeRMCommandMController& rst);
	Sbecore::ubigint loadRstByCtr(Sbecore::ubigint refWdbeMController, const bool append, ListWdbeRMCommandMController& rst);
};
#endif

#endif

