/**
	* \file WdbeMCdc.h
	* database access for table TblWdbeMCdc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEMCDC_H
#define WDBEMCDC_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMCdc: record of TblWdbeMCdc
	*/
class WdbeMCdc {

public:
	WdbeMCdc(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string fckSrefWdbeMSignal = "", const std::string farSrefWdbeMSignal = "", const std::string sckSrefWdbeMSignal = "", const std::string sarSrefWdbeMSignal = "", const double Ratio = 0.0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMModule;
	std::string fckSrefWdbeMSignal;
	std::string farSrefWdbeMSignal;
	std::string sckSrefWdbeMSignal;
	std::string sarSrefWdbeMSignal;
	double Ratio;

public:
	bool operator==(const WdbeMCdc& comp);
	bool operator!=(const WdbeMCdc& comp);
};

/**
	* ListWdbeMCdc: recordset of TblWdbeMCdc
	*/
class ListWdbeMCdc {

public:
	ListWdbeMCdc();
	ListWdbeMCdc(const ListWdbeMCdc& src);
	~ListWdbeMCdc();

	void clear();
	unsigned int size() const;
	void append(WdbeMCdc* rec);

	WdbeMCdc* operator[](const Sbecore::uint ix);
	ListWdbeMCdc& operator=(const ListWdbeMCdc& src);
	bool operator==(const ListWdbeMCdc& comp);
	bool operator!=(const ListWdbeMCdc& comp);

public:
	std::vector<WdbeMCdc*> nodes;
};

/**
	* TblWdbeMCdc: C++ wrapper for table TblWdbeMCdc
	*/
class TblWdbeMCdc {

public:

public:
	TblWdbeMCdc();
	virtual ~TblWdbeMCdc();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMCdc** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCdc& rst);

	virtual Sbecore::ubigint insertRec(WdbeMCdc* rec);
	Sbecore::ubigint insertNewRec(WdbeMCdc** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const std::string fckSrefWdbeMSignal = "", const std::string farSrefWdbeMSignal = "", const std::string sckSrefWdbeMSignal = "", const std::string sarSrefWdbeMSignal = "", const double Ratio = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMCdc& rst, WdbeMCdc** rec = NULL, const Sbecore::ubigint refWdbeMModule = 0, const std::string fckSrefWdbeMSignal = "", const std::string farSrefWdbeMSignal = "", const std::string sckSrefWdbeMSignal = "", const std::string sarSrefWdbeMSignal = "", const double Ratio = 0.0);
	virtual void insertRst(ListWdbeMCdc& rst, bool transact = false);
	virtual void updateRec(WdbeMCdc* rec);
	virtual void updateRst(ListWdbeMCdc& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMCdc** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMCdc& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMCdc& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMCdc: C++ wrapper for table TblWdbeMCdc (MySQL database)
	*/
class MyTblWdbeMCdc : public TblWdbeMCdc, public Sbecore::MyTable {

public:
	MyTblWdbeMCdc();
	~MyTblWdbeMCdc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCdc& rst);

	Sbecore::ubigint insertRec(WdbeMCdc* rec);
	void insertRst(ListWdbeMCdc& rst, bool transact = false);
	void updateRec(WdbeMCdc* rec);
	void updateRst(ListWdbeMCdc& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCdc** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMCdc& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMCdc: C++ wrapper for table TblWdbeMCdc (PgSQL database)
	*/
class PgTblWdbeMCdc : public TblWdbeMCdc, public Sbecore::PgTable {

public:
	PgTblWdbeMCdc();
	~PgTblWdbeMCdc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMCdc** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMCdc& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMCdc** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMCdc& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCdc& rst);

	Sbecore::ubigint insertRec(WdbeMCdc* rec);
	void insertRst(ListWdbeMCdc& rst, bool transact = false);
	void updateRec(WdbeMCdc* rec);
	void updateRst(ListWdbeMCdc& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCdc** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWdbeMModule, const bool append, ListWdbeMCdc& rst);
};
#endif

#endif
