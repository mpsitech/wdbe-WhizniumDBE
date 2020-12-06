/**
	* \file WdbeMGeneric.h
	* database access for table TblWdbeMGeneric (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMGENERIC_H
#define WDBEMGENERIC_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMGeneric: record of TblWdbeMGeneric
	*/
class WdbeMGeneric {

public:
	WdbeMGeneric(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCGeneric = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string sref = "", const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string srcSrefWdbeMGeneric = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCGeneric;
	Sbecore::ubigint mdlRefWdbeMModule;
	Sbecore::uint mdlNum;
	std::string sref;
	std::string srefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;
	std::string Defval;
	std::string srcSrefWdbeMGeneric;
	std::string Comment;

public:
	bool operator==(const WdbeMGeneric& comp);
	bool operator!=(const WdbeMGeneric& comp);
};

/**
	* ListWdbeMGeneric: recordset of TblWdbeMGeneric
	*/
class ListWdbeMGeneric {

public:
	ListWdbeMGeneric();
	ListWdbeMGeneric(const ListWdbeMGeneric& src);
	~ListWdbeMGeneric();

	void clear();
	unsigned int size() const;
	void append(WdbeMGeneric* rec);

	WdbeMGeneric* operator[](const Sbecore::uint ix);
	ListWdbeMGeneric& operator=(const ListWdbeMGeneric& src);
	bool operator==(const ListWdbeMGeneric& comp);
	bool operator!=(const ListWdbeMGeneric& comp);

public:
	std::vector<WdbeMGeneric*> nodes;
};

/**
	* TblWdbeMGeneric: C++ wrapper for table TblWdbeMGeneric
	*/
class TblWdbeMGeneric {

public:

public:
	TblWdbeMGeneric();
	virtual ~TblWdbeMGeneric();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMGeneric** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMGeneric& rst);

	virtual Sbecore::ubigint insertRec(WdbeMGeneric* rec);
	Sbecore::ubigint insertNewRec(WdbeMGeneric** rec = NULL, const Sbecore::ubigint refWdbeCGeneric = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string sref = "", const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string srcSrefWdbeMGeneric = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMGeneric& rst, WdbeMGeneric** rec = NULL, const Sbecore::ubigint refWdbeCGeneric = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const std::string sref = "", const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string srcSrefWdbeMGeneric = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMGeneric& rst, bool transact = false);
	virtual void updateRec(WdbeMGeneric* rec);
	virtual void updateRst(ListWdbeMGeneric& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMGeneric** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, ListWdbeMGeneric& rst);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMGeneric& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMGeneric& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMGeneric: C++ wrapper for table TblWdbeMGeneric (MySQL database)
	*/
class MyTblWdbeMGeneric : public TblWdbeMGeneric, public Sbecore::MyTable {

public:
	MyTblWdbeMGeneric();
	~MyTblWdbeMGeneric();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMGeneric& rst);

	Sbecore::ubigint insertRec(WdbeMGeneric* rec);
	void insertRst(ListWdbeMGeneric& rst, bool transact = false);
	void updateRec(WdbeMGeneric* rec);
	void updateRst(ListWdbeMGeneric& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMGeneric** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, ListWdbeMGeneric& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMGeneric& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMGeneric: C++ wrapper for table TblWdbeMGeneric (PgSQL database)
	*/
class PgTblWdbeMGeneric : public TblWdbeMGeneric, public Sbecore::PgTable {

public:
	PgTblWdbeMGeneric();
	~PgTblWdbeMGeneric();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMGeneric** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMGeneric& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMGeneric** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMGeneric& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMGeneric& rst);

	Sbecore::ubigint insertRec(WdbeMGeneric* rec);
	void insertRst(ListWdbeMGeneric& rst, bool transact = false);
	void updateRec(WdbeMGeneric* rec);
	void updateRst(ListWdbeMGeneric& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMGeneric** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCGeneric, const bool append, ListWdbeMGeneric& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMGeneric& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
