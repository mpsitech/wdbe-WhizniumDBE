/**
	* \file WdbeRMLibraryMVersion.h
	* database access for table TblWdbeRMLibraryMVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBERMLIBRARYMVERSION_H
#define WDBERMLIBRARYMVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMLibraryMVersion: record of TblWdbeRMLibraryMVersion
	*/
class WdbeRMLibraryMVersion {

public:
	WdbeRMLibraryMVersion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint refWdbeMVersion = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMLibrary;
	Sbecore::ubigint refWdbeMVersion;

public:
	bool operator==(const WdbeRMLibraryMVersion& comp);
	bool operator!=(const WdbeRMLibraryMVersion& comp);
};

/**
	* ListWdbeRMLibraryMVersion: recordset of TblWdbeRMLibraryMVersion
	*/
class ListWdbeRMLibraryMVersion {

public:
	ListWdbeRMLibraryMVersion();
	ListWdbeRMLibraryMVersion(const ListWdbeRMLibraryMVersion& src);
	~ListWdbeRMLibraryMVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeRMLibraryMVersion* rec);

	WdbeRMLibraryMVersion* operator[](const Sbecore::uint ix);
	ListWdbeRMLibraryMVersion& operator=(const ListWdbeRMLibraryMVersion& src);
	bool operator==(const ListWdbeRMLibraryMVersion& comp);
	bool operator!=(const ListWdbeRMLibraryMVersion& comp);

public:
	std::vector<WdbeRMLibraryMVersion*> nodes;
};

/**
	* TblWdbeRMLibraryMVersion: C++ wrapper for table TblWdbeRMLibraryMVersion
	*/
class TblWdbeRMLibraryMVersion {

public:

public:
	TblWdbeRMLibraryMVersion();
	virtual ~TblWdbeRMLibraryMVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMLibraryMVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMLibraryMVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMLibraryMVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeRMLibraryMVersion** rec = NULL, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint refWdbeMVersion = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMLibraryMVersion& rst, WdbeRMLibraryMVersion** rec = NULL, const Sbecore::ubigint refWdbeMLibrary = 0, const Sbecore::ubigint refWdbeMVersion = 0);
	virtual void insertRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	virtual void updateRec(WdbeRMLibraryMVersion* rec);
	virtual void updateRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMLibraryMVersion** rec);
	virtual Sbecore::ubigint loadLibsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadVersByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMVersions);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMLibraryMVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMLibraryMVersion: C++ wrapper for table TblWdbeRMLibraryMVersion (MySQL database)
	*/
class MyTblWdbeRMLibraryMVersion : public TblWdbeRMLibraryMVersion, public Sbecore::MyTable {

public:
	MyTblWdbeRMLibraryMVersion();
	~MyTblWdbeRMLibraryMVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMLibraryMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMLibraryMVersion& rst);

	Sbecore::ubigint insertRec(WdbeRMLibraryMVersion* rec);
	void insertRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	void updateRec(WdbeRMLibraryMVersion* rec);
	void updateRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMLibraryMVersion** rec);
	Sbecore::ubigint loadLibsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadVersByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMVersions);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMLibraryMVersion: C++ wrapper for table TblWdbeRMLibraryMVersion (PgSQL database)
	*/
class PgTblWdbeRMLibraryMVersion : public TblWdbeRMLibraryMVersion, public Sbecore::PgTable {

public:
	PgTblWdbeRMLibraryMVersion();
	~PgTblWdbeRMLibraryMVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMLibraryMVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMLibraryMVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMLibraryMVersion** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMLibraryMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMLibraryMVersion& rst);

	Sbecore::ubigint insertRec(WdbeRMLibraryMVersion* rec);
	void insertRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	void updateRec(WdbeRMLibraryMVersion* rec);
	void updateRst(ListWdbeRMLibraryMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMLibraryMVersion** rec);
	Sbecore::ubigint loadLibsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refWdbeMLibrarys);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadVersByLib(Sbecore::ubigint refWdbeMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWdbeMVersions);
};
#endif

#endif

