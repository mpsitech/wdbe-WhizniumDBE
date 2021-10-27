/**
	* \file WdbeMSegment.h
	* database access for table TblWdbeMSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMSEGMENT_H
#define WDBEMSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMSegment: record of TblWdbeMSegment
	*/
class WdbeMSegment {

public:
	WdbeMSegment(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCSegment = 0, const Sbecore::ubigint pplRefWdbeMPipeline = 0, const Sbecore::uint pplNum = 0, const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string sref = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCSegment;
	Sbecore::ubigint pplRefWdbeMPipeline;
	Sbecore::uint pplNum;
	Sbecore::ubigint supRefWdbeMSegment;
	std::string sref;
	std::string Infmt;
	std::string Outfmt;
	Sbecore::usmallint Latency;
	std::string Comment;

public:
	bool operator==(const WdbeMSegment& comp);
	bool operator!=(const WdbeMSegment& comp);
};

/**
	* ListWdbeMSegment: recordset of TblWdbeMSegment
	*/
class ListWdbeMSegment {

public:
	ListWdbeMSegment();
	ListWdbeMSegment(const ListWdbeMSegment& src);
	~ListWdbeMSegment();

	void clear();
	unsigned int size() const;
	void append(WdbeMSegment* rec);

	WdbeMSegment* operator[](const Sbecore::uint ix);
	ListWdbeMSegment& operator=(const ListWdbeMSegment& src);
	bool operator==(const ListWdbeMSegment& comp);
	bool operator!=(const ListWdbeMSegment& comp);

public:
	std::vector<WdbeMSegment*> nodes;
};

/**
	* TblWdbeMSegment: C++ wrapper for table TblWdbeMSegment
	*/
class TblWdbeMSegment {

public:

public:
	TblWdbeMSegment();
	virtual ~TblWdbeMSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSegment& rst);

	virtual Sbecore::ubigint insertRec(WdbeMSegment* rec);
	Sbecore::ubigint insertNewRec(WdbeMSegment** rec = NULL, const Sbecore::ubigint refWdbeCSegment = 0, const Sbecore::ubigint pplRefWdbeMPipeline = 0, const Sbecore::uint pplNum = 0, const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string sref = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMSegment& rst, WdbeMSegment** rec = NULL, const Sbecore::ubigint refWdbeCSegment = 0, const Sbecore::ubigint pplRefWdbeMPipeline = 0, const Sbecore::uint pplNum = 0, const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string sref = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMSegment& rst, bool transact = false);
	virtual void updateRec(WdbeMSegment* rec);
	virtual void updateRst(ListWdbeMSegment& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMSegment** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMSegment, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSegment, const bool append, ListWdbeMSegment& rst);
	virtual Sbecore::ubigint loadRstByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, ListWdbeMSegment& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, ListWdbeMSegment& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMSegment);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMSegment& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWdbeMSegment& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWdbeMSegment& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMSegment: C++ wrapper for table TblWdbeMSegment (MySQL database)
	*/
class MyTblWdbeMSegment : public TblWdbeMSegment, public Sbecore::MyTable {

public:
	MyTblWdbeMSegment();
	~MyTblWdbeMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSegment& rst);

	Sbecore::ubigint insertRec(WdbeMSegment* rec);
	void insertRst(ListWdbeMSegment& rst, bool transact = false);
	void updateRec(WdbeMSegment* rec);
	void updateRst(ListWdbeMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSegment** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMSegment, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSegment, const bool append, ListWdbeMSegment& rst);
	Sbecore::ubigint loadRstByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, ListWdbeMSegment& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, ListWdbeMSegment& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMSegment);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMSegment: C++ wrapper for table TblWdbeMSegment (PgSQL database)
	*/
class PgTblWdbeMSegment : public TblWdbeMSegment, public Sbecore::PgTable {

public:
	PgTblWdbeMSegment();
	~PgTblWdbeMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSegment& rst);

	Sbecore::ubigint insertRec(WdbeMSegment* rec);
	void insertRst(ListWdbeMSegment& rst, bool transact = false);
	void updateRec(WdbeMSegment* rec);
	void updateRst(ListWdbeMSegment& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSegment** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMSegment, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSegment, const bool append, ListWdbeMSegment& rst);
	Sbecore::ubigint loadRstByPpl(Sbecore::ubigint pplRefWdbeMPipeline, const bool append, ListWdbeMSegment& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMSegment, const bool append, ListWdbeMSegment& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMSegment);
};
#endif

#endif
