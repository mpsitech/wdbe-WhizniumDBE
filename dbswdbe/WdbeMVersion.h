/**
	* \file WdbeMVersion.h
	* database access for table TblWdbeMVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMVERSION_H
#define WDBEMVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMVersionState TblWdbeMVersion::VecVState

/**
	* WdbeMVersion: record of TblWdbeMVersion
	*/
class WdbeMVersion {

public:
	WdbeMVersion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMProject = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const std::string About = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWdbeMProject;
	Sbecore::ubigint bvrRefWdbeMVersion;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	std::string About;
	std::string Comment;

public:
	bool operator==(const WdbeMVersion& comp);
	bool operator!=(const WdbeMVersion& comp);
};

/**
	* ListWdbeMVersion: recordset of TblWdbeMVersion
	*/
class ListWdbeMVersion {

public:
	ListWdbeMVersion();
	ListWdbeMVersion(const ListWdbeMVersion& src);
	~ListWdbeMVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeMVersion* rec);

	WdbeMVersion* operator[](const Sbecore::uint ix);
	ListWdbeMVersion& operator=(const ListWdbeMVersion& src);
	bool operator==(const ListWdbeMVersion& comp);
	bool operator!=(const ListWdbeMVersion& comp);

public:
	std::vector<WdbeMVersion*> nodes;
};

/**
	* TblWdbeMVersion: C++ wrapper for table TblWdbeMVersion
	*/
class TblWdbeMVersion {

public:
	/**
		* VecVState (full: VecWdbeVMVersionState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint NEWCRE = 1;
		static const Sbecore::uint NEWIMP = 2;
		static const Sbecore::uint DSNBSCDD = 3;
		static const Sbecore::uint READY = 4;
		static const Sbecore::uint ABANDON = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMVersion();
	virtual ~TblWdbeMVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeMVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeMVersion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMProject = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const std::string About = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMVersion& rst, WdbeMVersion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMProject = 0, const Sbecore::ubigint bvrRefWdbeMVersion = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const std::string About = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMVersion& rst, bool transact = false);
	virtual void updateRec(WdbeMVersion* rec);
	virtual void updateRst(ListWdbeMVersion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMVersion** rec);
	virtual Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeMVersion& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMVersion: C++ wrapper for table TblWdbeMVersion (MySQL database)
	*/
class MyTblWdbeMVersion : public TblWdbeMVersion, public Sbecore::MyTable {

public:
	MyTblWdbeMVersion();
	~MyTblWdbeMVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVersion& rst);

	Sbecore::ubigint insertRec(WdbeMVersion* rec);
	void insertRst(ListWdbeMVersion& rst, bool transact = false);
	void updateRec(WdbeMVersion* rec);
	void updateRst(ListWdbeMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVersion** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeMVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMVersion: C++ wrapper for table TblWdbeMVersion (PgSQL database)
	*/
class PgTblWdbeMVersion : public TblWdbeMVersion, public Sbecore::PgTable {

public:
	PgTblWdbeMVersion();
	~PgTblWdbeMVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVersion& rst);

	Sbecore::ubigint insertRec(WdbeMVersion* rec);
	void insertRst(ListWdbeMVersion& rst, bool transact = false);
	void updateRec(WdbeMVersion* rec);
	void updateRst(ListWdbeMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVersion** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeMVersion& rst);
};
#endif

#endif

