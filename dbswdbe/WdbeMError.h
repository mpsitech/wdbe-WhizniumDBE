/**
	* \file WdbeMError.h
	* database access for table TblWdbeMError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMERROR_H
#define WDBEMERROR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMErrorRefTbl TblWdbeMError::VecVRefTbl

/**
	* WdbeMError: record of TblWdbeMError
	*/
class WdbeMError {

public:
	WdbeMError(const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::ubigint traRefWdbeMSignal = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint refNum;
	std::string sref;
	std::string Fullsref;
	Sbecore::ubigint traRefWdbeMSignal;
	std::string Comment;

public:
	bool operator==(const WdbeMError& comp);
	bool operator!=(const WdbeMError& comp);
};

/**
	* ListWdbeMError: recordset of TblWdbeMError
	*/
class ListWdbeMError {

public:
	ListWdbeMError();
	ListWdbeMError(const ListWdbeMError& src);
	~ListWdbeMError();

	void clear();
	unsigned int size() const;
	void append(WdbeMError* rec);

	WdbeMError* operator[](const Sbecore::uint ix);
	ListWdbeMError& operator=(const ListWdbeMError& src);
	bool operator==(const ListWdbeMError& comp);
	bool operator!=(const ListWdbeMError& comp);

public:
	std::vector<WdbeMError*> nodes;
};

/**
	* TblWdbeMError: C++ wrapper for table TblWdbeMError
	*/
class TblWdbeMError {

public:
	/**
		* VecVRefTbl (full: VecWdbeVMErrorRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint CTR = 1;
		static const Sbecore::uint UNT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMError();
	virtual ~TblWdbeMError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMError& rst);

	virtual Sbecore::ubigint insertRec(WdbeMError* rec);
	Sbecore::ubigint insertNewRec(WdbeMError** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::ubigint traRefWdbeMSignal = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMError& rst, WdbeMError** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::ubigint traRefWdbeMSignal = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMError& rst, bool transact = false);
	virtual void updateRec(WdbeMError* rec);
	virtual void updateRst(ListWdbeMError& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMError** rec);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMError& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMError: C++ wrapper for table TblWdbeMError (MySQL database)
	*/
class MyTblWdbeMError : public TblWdbeMError, public Sbecore::MyTable {

public:
	MyTblWdbeMError();
	~MyTblWdbeMError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMError& rst);

	Sbecore::ubigint insertRec(WdbeMError* rec);
	void insertRst(ListWdbeMError& rst, bool transact = false);
	void updateRec(WdbeMError* rec);
	void updateRst(ListWdbeMError& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMError** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMError: C++ wrapper for table TblWdbeMError (PgSQL database)
	*/
class PgTblWdbeMError : public TblWdbeMError, public Sbecore::PgTable {

public:
	PgTblWdbeMError();
	~PgTblWdbeMError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMError& rst);

	Sbecore::ubigint insertRec(WdbeMError* rec);
	void insertRst(ListWdbeMError& rst, bool transact = false);
	void updateRec(WdbeMError* rec);
	void updateRst(ListWdbeMError& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMError** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMError& rst);
};
#endif

#endif
