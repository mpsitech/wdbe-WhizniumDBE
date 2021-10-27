/**
	* \file WdbeMPipeline.h
	* database access for table TblWdbeMPipeline (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMPIPELINE_H
#define WDBEMPIPELINE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMPipeline: record of TblWdbeMPipeline
	*/
class WdbeMPipeline {

public:
	WdbeMPipeline(const Sbecore::ubigint ref = 0, const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string clgSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const Sbecore::usmallint Depth = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint hsmRefWdbeMModule;
	std::string sref;
	std::string clkSrefWdbeMSignal;
	std::string clgSrefWdbeMSignal;
	std::string asrSrefWdbeMSignal;
	Sbecore::usmallint Depth;
	std::string Comment;

public:
	bool operator==(const WdbeMPipeline& comp);
	bool operator!=(const WdbeMPipeline& comp);
};

/**
	* ListWdbeMPipeline: recordset of TblWdbeMPipeline
	*/
class ListWdbeMPipeline {

public:
	ListWdbeMPipeline();
	ListWdbeMPipeline(const ListWdbeMPipeline& src);
	~ListWdbeMPipeline();

	void clear();
	unsigned int size() const;
	void append(WdbeMPipeline* rec);

	WdbeMPipeline* operator[](const Sbecore::uint ix);
	ListWdbeMPipeline& operator=(const ListWdbeMPipeline& src);
	bool operator==(const ListWdbeMPipeline& comp);
	bool operator!=(const ListWdbeMPipeline& comp);

public:
	std::vector<WdbeMPipeline*> nodes;
};

/**
	* TblWdbeMPipeline: C++ wrapper for table TblWdbeMPipeline
	*/
class TblWdbeMPipeline {

public:

public:
	TblWdbeMPipeline();
	virtual ~TblWdbeMPipeline();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMPipeline** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPipeline& rst);

	virtual Sbecore::ubigint insertRec(WdbeMPipeline* rec);
	Sbecore::ubigint insertNewRec(WdbeMPipeline** rec = NULL, const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string clgSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const Sbecore::usmallint Depth = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMPipeline& rst, WdbeMPipeline** rec = NULL, const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string sref = "", const std::string clkSrefWdbeMSignal = "", const std::string clgSrefWdbeMSignal = "", const std::string asrSrefWdbeMSignal = "", const Sbecore::usmallint Depth = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMPipeline& rst, bool transact = false);
	virtual void updateRec(WdbeMPipeline* rec);
	virtual void updateRst(ListWdbeMPipeline& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMPipeline** rec);
	virtual Sbecore::ubigint loadRefsByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, ListWdbeMPipeline& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMPipeline& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMPipeline: C++ wrapper for table TblWdbeMPipeline (MySQL database)
	*/
class MyTblWdbeMPipeline : public TblWdbeMPipeline, public Sbecore::MyTable {

public:
	MyTblWdbeMPipeline();
	~MyTblWdbeMPipeline();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPipeline& rst);

	Sbecore::ubigint insertRec(WdbeMPipeline* rec);
	void insertRst(ListWdbeMPipeline& rst, bool transact = false);
	void updateRec(WdbeMPipeline* rec);
	void updateRst(ListWdbeMPipeline& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPipeline** rec);
	Sbecore::ubigint loadRefsByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, ListWdbeMPipeline& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMPipeline: C++ wrapper for table TblWdbeMPipeline (PgSQL database)
	*/
class PgTblWdbeMPipeline : public TblWdbeMPipeline, public Sbecore::PgTable {

public:
	PgTblWdbeMPipeline();
	~PgTblWdbeMPipeline();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMPipeline** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMPipeline& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMPipeline** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMPipeline& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPipeline& rst);

	Sbecore::ubigint insertRec(WdbeMPipeline* rec);
	void insertRst(ListWdbeMPipeline& rst, bool transact = false);
	void updateRec(WdbeMPipeline* rec);
	void updateRst(ListWdbeMPipeline& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPipeline** rec);
	Sbecore::ubigint loadRefsByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHsm(Sbecore::ubigint hsmRefWdbeMModule, const bool append, ListWdbeMPipeline& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
