/**
	* \file WdbeRMCdcMSignal.h
	* database access for table TblWdbeRMCdcMSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBERMCDCMSIGNAL_H
#define WDBERMCDCMSIGNAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVRMCdcMSignalDir TblWdbeRMCdcMSignal::VecVDir

/**
	* WdbeRMCdcMSignal: record of TblWdbeRMCdcMSignal
	*/
class WdbeRMCdcMSignal {

public:
	WdbeRMCdcMSignal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMCdc = 0, const Sbecore::ubigint refWdbeMSignal = 0, const Sbecore::uint ixVDir = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMCdc;
	Sbecore::ubigint refWdbeMSignal;
	Sbecore::uint ixVDir;

public:
	bool operator==(const WdbeRMCdcMSignal& comp);
	bool operator!=(const WdbeRMCdcMSignal& comp);
};

/**
	* ListWdbeRMCdcMSignal: recordset of TblWdbeRMCdcMSignal
	*/
class ListWdbeRMCdcMSignal {

public:
	ListWdbeRMCdcMSignal();
	ListWdbeRMCdcMSignal(const ListWdbeRMCdcMSignal& src);
	~ListWdbeRMCdcMSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeRMCdcMSignal* rec);

	WdbeRMCdcMSignal* operator[](const Sbecore::uint ix);
	ListWdbeRMCdcMSignal& operator=(const ListWdbeRMCdcMSignal& src);
	bool operator==(const ListWdbeRMCdcMSignal& comp);
	bool operator!=(const ListWdbeRMCdcMSignal& comp);

public:
	std::vector<WdbeRMCdcMSignal*> nodes;
};

/**
	* TblWdbeRMCdcMSignal: C++ wrapper for table TblWdbeRMCdcMSignal
	*/
class TblWdbeRMCdcMSignal {

public:
	/**
		* VecVDir (full: VecWdbeVRMCdcMSignalDir)
		*/
	class VecVDir {

	public:
		static const Sbecore::uint FTS = 1;
		static const Sbecore::uint STF = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeRMCdcMSignal();
	virtual ~TblWdbeRMCdcMSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMCdcMSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCdcMSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMCdcMSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeRMCdcMSignal** rec = NULL, const Sbecore::ubigint refWdbeMCdc = 0, const Sbecore::ubigint refWdbeMSignal = 0, const Sbecore::uint ixVDir = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMCdcMSignal& rst, WdbeRMCdcMSignal** rec = NULL, const Sbecore::ubigint refWdbeMCdc = 0, const Sbecore::ubigint refWdbeMSignal = 0, const Sbecore::uint ixVDir = 0);
	virtual void insertRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	virtual void updateRec(WdbeRMCdcMSignal* rec);
	virtual void updateRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCdcMSignal** rec);
	virtual Sbecore::ubigint loadRefsByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, ListWdbeRMCdcMSignal& rst);
	virtual Sbecore::ubigint loadRstBySig(Sbecore::ubigint refWdbeMSignal, const bool append, ListWdbeRMCdcMSignal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMCdcMSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMCdcMSignal: C++ wrapper for table TblWdbeRMCdcMSignal (MySQL database)
	*/
class MyTblWdbeRMCdcMSignal : public TblWdbeRMCdcMSignal, public Sbecore::MyTable {

public:
	MyTblWdbeRMCdcMSignal();
	~MyTblWdbeRMCdcMSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCdcMSignal& rst);

	Sbecore::ubigint insertRec(WdbeRMCdcMSignal* rec);
	void insertRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	void updateRec(WdbeRMCdcMSignal* rec);
	void updateRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRefsByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, ListWdbeRMCdcMSignal& rst);
	Sbecore::ubigint loadRstBySig(Sbecore::ubigint refWdbeMSignal, const bool append, ListWdbeRMCdcMSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMCdcMSignal: C++ wrapper for table TblWdbeRMCdcMSignal (PgSQL database)
	*/
class PgTblWdbeRMCdcMSignal : public TblWdbeRMCdcMSignal, public Sbecore::PgTable {

public:
	PgTblWdbeRMCdcMSignal();
	~PgTblWdbeRMCdcMSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMCdcMSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMCdcMSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMCdcMSignal& rst);

	Sbecore::ubigint insertRec(WdbeRMCdcMSignal* rec);
	void insertRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	void updateRec(WdbeRMCdcMSignal* rec);
	void updateRst(ListWdbeRMCdcMSignal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMCdcMSignal** rec);
	Sbecore::ubigint loadRefsByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCdc(Sbecore::ubigint refWdbeMCdc, const bool append, ListWdbeRMCdcMSignal& rst);
	Sbecore::ubigint loadRstBySig(Sbecore::ubigint refWdbeMSignal, const bool append, ListWdbeRMCdcMSignal& rst);
};
#endif

#endif
