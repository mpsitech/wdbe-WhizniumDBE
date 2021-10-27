/**
	* \file WdbeMSensitivity.h
	* database access for table TblWdbeMSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMSENSITIVITY_H
#define WDBEMSENSITIVITY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMSensitivityRefTbl TblWdbeMSensitivity::VecVRefTbl
#define VecWdbeVMSensitivitySrcTbl TblWdbeMSensitivity::VecVSrcTbl

/**
	* WdbeMSensitivity: record of TblWdbeMSensitivity
	*/
class WdbeMSensitivity {

public:
	WdbeMSensitivity(const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint srcIxVTbl;
	Sbecore::ubigint srcUref;

public:
	bool operator==(const WdbeMSensitivity& comp);
	bool operator!=(const WdbeMSensitivity& comp);
};

/**
	* ListWdbeMSensitivity: recordset of TblWdbeMSensitivity
	*/
class ListWdbeMSensitivity {

public:
	ListWdbeMSensitivity();
	ListWdbeMSensitivity(const ListWdbeMSensitivity& src);
	~ListWdbeMSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeMSensitivity* rec);

	WdbeMSensitivity* operator[](const Sbecore::uint ix);
	ListWdbeMSensitivity& operator=(const ListWdbeMSensitivity& src);
	bool operator==(const ListWdbeMSensitivity& comp);
	bool operator!=(const ListWdbeMSensitivity& comp);

public:
	std::vector<WdbeMSensitivity*> nodes;
};

/**
	* TblWdbeMSensitivity: C++ wrapper for table TblWdbeMSensitivity
	*/
class TblWdbeMSensitivity {

public:
	/**
		* VecVRefTbl (full: VecWdbeVMSensitivityRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint MDL = 1;
		static const Sbecore::uint PRC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVSrcTbl (full: VecWdbeVMSensitivitySrcTbl)
		*/
	class VecVSrcTbl {

	public:
		static const Sbecore::uint INT = 1;
		static const Sbecore::uint PRT = 2;
		static const Sbecore::uint SIG = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeMSensitivity();
	virtual ~TblWdbeMSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeMSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeMSensitivity** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMSensitivity& rst, WdbeMSensitivity** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0);
	virtual void insertRst(ListWdbeMSensitivity& rst, bool transact = false);
	virtual void updateRec(WdbeMSensitivity* rec);
	virtual void updateRst(ListWdbeMSensitivity& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMSensitivity** rec);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMSensitivity& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMSensitivity: C++ wrapper for table TblWdbeMSensitivity (MySQL database)
	*/
class MyTblWdbeMSensitivity : public TblWdbeMSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeMSensitivity();
	~MyTblWdbeMSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeMSensitivity* rec);
	void insertRst(ListWdbeMSensitivity& rst, bool transact = false);
	void updateRec(WdbeMSensitivity* rec);
	void updateRst(ListWdbeMSensitivity& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMSensitivity: C++ wrapper for table TblWdbeMSensitivity (PgSQL database)
	*/
class PgTblWdbeMSensitivity : public TblWdbeMSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeMSensitivity();
	~PgTblWdbeMSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeMSensitivity* rec);
	void insertRst(ListWdbeMSensitivity& rst, bool transact = false);
	void updateRec(WdbeMSensitivity* rec);
	void updateRst(ListWdbeMSensitivity& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSensitivity** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMSensitivity& rst);
};
#endif

#endif
