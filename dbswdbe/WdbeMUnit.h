/**
	* \file WdbeMUnit.h
	* database access for table TblWdbeMUnit (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMUNIT_H
#define WDBEMUNIT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMUnitBasetype TblWdbeMUnit::VecVBasetype
#define VecWdbeVMUnitRefTbl TblWdbeMUnit::VecVRefTbl
#define VecWdbeWMUnitSubset TblWdbeMUnit::VecWSubset

/**
	* WdbeMUnit: record of TblWdbeMUnit
	*/
class WdbeMUnit {

public:
	WdbeMUnit(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint silRefWdbeMUnit = 0, const Sbecore::ubigint refWdbeMSystem = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const std::string srefKPackage = "", const bool Easy = false, const std::string srefKToolch = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint silRefWdbeMUnit;
	Sbecore::ubigint refWdbeMSystem;
	Sbecore::ubigint refWdbeMModule;
	std::string sref;
	std::string Title;
	std::string Fullsref;
	std::string srefKPackage;
	bool Easy;
	std::string srefKToolch;
	std::string Comment;

public:
	bool operator==(const WdbeMUnit& comp);
	bool operator!=(const WdbeMUnit& comp);
};

/**
	* ListWdbeMUnit: recordset of TblWdbeMUnit
	*/
class ListWdbeMUnit {

public:
	ListWdbeMUnit();
	ListWdbeMUnit(const ListWdbeMUnit& src);
	~ListWdbeMUnit();

	void clear();
	unsigned int size() const;
	void append(WdbeMUnit* rec);

	WdbeMUnit* operator[](const Sbecore::uint ix);
	ListWdbeMUnit& operator=(const ListWdbeMUnit& src);
	bool operator==(const ListWdbeMUnit& comp);
	bool operator!=(const ListWdbeMUnit& comp);

public:
	std::vector<WdbeMUnit*> nodes;
};

/**
	* TblWdbeMUnit: C++ wrapper for table TblWdbeMUnit
	*/
class TblWdbeMUnit {

public:
	/**
		* VecVBasetype (full: VecWdbeVMUnitBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint FPGA = 1;
		static const Sbecore::uint MCU = 2;
		static const Sbecore::uint OTH = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWdbeVMUnitRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint FAM = 2;
		static const Sbecore::uint VER = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWdbeWMUnitSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWDBEBMUNITSIL = 1;
		static const Sbecore::uint SBSWDBEBMUNITUNI = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);
	};

public:
	TblWdbeMUnit();
	virtual ~TblWdbeMUnit();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMUnit** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUnit& rst);

	virtual Sbecore::ubigint insertRec(WdbeMUnit* rec);
	Sbecore::ubigint insertNewRec(WdbeMUnit** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint silRefWdbeMUnit = 0, const Sbecore::ubigint refWdbeMSystem = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const std::string srefKPackage = "", const bool Easy = false, const std::string srefKToolch = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMUnit& rst, WdbeMUnit** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint silRefWdbeMUnit = 0, const Sbecore::ubigint refWdbeMSystem = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const std::string srefKPackage = "", const bool Easy = false, const std::string srefKToolch = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMUnit& rst, bool transact = false);
	virtual void updateRec(WdbeMUnit* rec);
	virtual void updateRst(ListWdbeMUnit& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMUnit** rec);
	virtual bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	virtual bool loadRecBySys(Sbecore::ubigint refWdbeMSystem, WdbeMUnit** rec);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMUnit& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMUnit& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMUnit: C++ wrapper for table TblWdbeMUnit (MySQL database)
	*/
class MyTblWdbeMUnit : public TblWdbeMUnit, public Sbecore::MyTable {

public:
	MyTblWdbeMUnit();
	~MyTblWdbeMUnit();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUnit& rst);

	Sbecore::ubigint insertRec(WdbeMUnit* rec);
	void insertRst(ListWdbeMUnit& rst, bool transact = false);
	void updateRec(WdbeMUnit* rec);
	void updateRst(ListWdbeMUnit& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUnit** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecBySys(Sbecore::ubigint refWdbeMSystem, WdbeMUnit** rec);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMUnit& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMUnit: C++ wrapper for table TblWdbeMUnit (PgSQL database)
	*/
class PgTblWdbeMUnit : public TblWdbeMUnit, public Sbecore::PgTable {

public:
	PgTblWdbeMUnit();
	~PgTblWdbeMUnit();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMUnit** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMUnit& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMUnit** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMUnit& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUnit& rst);

	Sbecore::ubigint insertRec(WdbeMUnit* rec);
	void insertRst(ListWdbeMUnit& rst, bool transact = false);
	void updateRec(WdbeMUnit* rec);
	void updateRst(ListWdbeMUnit& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUnit** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecBySys(Sbecore::ubigint refWdbeMSystem, WdbeMUnit** rec);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMUnit& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

