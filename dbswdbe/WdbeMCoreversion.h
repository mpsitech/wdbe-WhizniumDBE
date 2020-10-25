/**
	* \file WdbeMCoreversion.h
	* database access for table TblWdbeMCoreversion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMCOREVERSION_H
#define WDBEMCOREVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMCoreversionState TblWdbeMCoreversion::VecVState
#define VecWdbeWMCoreversionSpectype TblWdbeMCoreversion::VecWSpectype

/**
	* WdbeMCoreversion: record of TblWdbeMCoreversion
	*/
class WdbeMCoreversion {

public:
	WdbeMCoreversion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWSpectype = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWdbeMCoreproject;
	Sbecore::ubigint bcvRefWdbeMCoreversion;
	Sbecore::ubigint refWdbeMModule;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWSpectype;

public:
	bool operator==(const WdbeMCoreversion& comp);
	bool operator!=(const WdbeMCoreversion& comp);
};

/**
	* ListWdbeMCoreversion: recordset of TblWdbeMCoreversion
	*/
class ListWdbeMCoreversion {

public:
	ListWdbeMCoreversion();
	ListWdbeMCoreversion(const ListWdbeMCoreversion& src);
	~ListWdbeMCoreversion();

	void clear();
	unsigned int size() const;
	void append(WdbeMCoreversion* rec);

	WdbeMCoreversion* operator[](const Sbecore::uint ix);
	ListWdbeMCoreversion& operator=(const ListWdbeMCoreversion& src);
	bool operator==(const ListWdbeMCoreversion& comp);
	bool operator!=(const ListWdbeMCoreversion& comp);

public:
	std::vector<WdbeMCoreversion*> nodes;
};

/**
	* TblWdbeMCoreversion: C++ wrapper for table TblWdbeMCoreversion
	*/
class TblWdbeMCoreversion {

public:
	/**
		* VecVState (full: VecWdbeVMCoreversionState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint DEV = 1;
		static const Sbecore::uint PROD = 2;
		static const Sbecore::uint ABANDON = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSpectype (full: VecWdbeWMCoreversionSpectype)
		*/
	class VecWSpectype {

	public:
		static const Sbecore::uint MBSCTD = 1;
		static const Sbecore::uint MBSCBU = 2;
		static const Sbecore::uint MDET = 4;
		static const Sbecore::uint TPLFIL = 8;
		static const Sbecore::uint PLH = 16;
		static const Sbecore::uint IP = 32;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMCoreversion();
	virtual ~TblWdbeMCoreversion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreversion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreversion& rst);

	virtual Sbecore::ubigint insertRec(WdbeMCoreversion* rec);
	Sbecore::ubigint insertNewRec(WdbeMCoreversion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWSpectype = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMCoreversion& rst, WdbeMCoreversion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMCoreproject = 0, const Sbecore::ubigint bcvRefWdbeMCoreversion = 0, const Sbecore::ubigint refWdbeMModule = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWSpectype = 0);
	virtual void insertRst(ListWdbeMCoreversion& rst, bool transact = false);
	virtual void updateRec(WdbeMCoreversion* rec);
	virtual void updateRst(ListWdbeMCoreversion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreversion** rec);
	virtual Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeMCoreversion& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMCoreversion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMCoreversion: C++ wrapper for table TblWdbeMCoreversion (MySQL database)
	*/
class MyTblWdbeMCoreversion : public TblWdbeMCoreversion, public Sbecore::MyTable {

public:
	MyTblWdbeMCoreversion();
	~MyTblWdbeMCoreversion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeMCoreversion* rec);
	void insertRst(ListWdbeMCoreversion& rst, bool transact = false);
	void updateRec(WdbeMCoreversion* rec);
	void updateRst(ListWdbeMCoreversion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeMCoreversion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMCoreversion: C++ wrapper for table TblWdbeMCoreversion (PgSQL database)
	*/
class PgTblWdbeMCoreversion : public TblWdbeMCoreversion, public Sbecore::PgTable {

public:
	PgTblWdbeMCoreversion();
	~PgTblWdbeMCoreversion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMCoreversion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMCoreversion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeMCoreversion* rec);
	void insertRst(ListWdbeMCoreversion& rst, bool transact = false);
	void updateRec(WdbeMCoreversion* rec);
	void updateRst(ListWdbeMCoreversion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreversion** rec);
	Sbecore::ubigint loadRefsByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpr(Sbecore::ubigint refWdbeMCoreproject, const bool append, ListWdbeMCoreversion& rst);
};
#endif

#endif

