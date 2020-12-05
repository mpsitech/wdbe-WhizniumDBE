/**
	* \file WdbeHistRMUserUniversal.h
	* database access for table TblWdbeHistRMUserUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEHISTRMUSERUNIVERSAL_H
#define WDBEHISTRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeHistRMUserUniversal: record of TblWdbeHistRMUserUniversal
	*/
class WdbeHistRMUserUniversal {

public:
	WdbeHistRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVCard = 0, const Sbecore::uint ixWdbeVPreset = 0, const Sbecore::uint preIxWdbeVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMUser;
	Sbecore::uint unvIxWdbeVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWdbeVCard;
	Sbecore::uint ixWdbeVPreset;
	Sbecore::uint preIxWdbeVMaintable;
	Sbecore::ubigint preUref;
	Sbecore::uint start;

public:
	bool operator==(const WdbeHistRMUserUniversal& comp);
	bool operator!=(const WdbeHistRMUserUniversal& comp);
};

/**
	* ListWdbeHistRMUserUniversal: recordset of TblWdbeHistRMUserUniversal
	*/
class ListWdbeHistRMUserUniversal {

public:
	ListWdbeHistRMUserUniversal();
	ListWdbeHistRMUserUniversal(const ListWdbeHistRMUserUniversal& src);
	~ListWdbeHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WdbeHistRMUserUniversal* rec);

	WdbeHistRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWdbeHistRMUserUniversal& operator=(const ListWdbeHistRMUserUniversal& src);
	bool operator==(const ListWdbeHistRMUserUniversal& comp);
	bool operator!=(const ListWdbeHistRMUserUniversal& comp);

public:
	std::vector<WdbeHistRMUserUniversal*> nodes;
};

/**
	* TblWdbeHistRMUserUniversal: C++ wrapper for table TblWdbeHistRMUserUniversal
	*/
class TblWdbeHistRMUserUniversal {

public:

public:
	TblWdbeHistRMUserUniversal();
	virtual ~TblWdbeHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeHistRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WdbeHistRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WdbeHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVCard = 0, const Sbecore::uint ixWdbeVPreset = 0, const Sbecore::uint preIxWdbeVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeHistRMUserUniversal& rst, WdbeHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWdbeMUser = 0, const Sbecore::uint unvIxWdbeVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWdbeVCard = 0, const Sbecore::uint ixWdbeVPreset = 0, const Sbecore::uint preIxWdbeVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	virtual void insertRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WdbeHistRMUserUniversal* rec);
	virtual void updateRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeHistRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWdbeVCard, WdbeHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::uint ixWdbeVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint ixWdbeVCard, const bool append, ListWdbeHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeHistRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeHistRMUserUniversal: C++ wrapper for table TblWdbeHistRMUserUniversal (MySQL database)
	*/
class MyTblWdbeHistRMUserUniversal : public TblWdbeHistRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWdbeHistRMUserUniversal();
	~MyTblWdbeHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WdbeHistRMUserUniversal* rec);
	void insertRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WdbeHistRMUserUniversal* rec);
	void updateRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWdbeVCard, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::uint ixWdbeVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint ixWdbeVCard, const bool append, ListWdbeHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeHistRMUserUniversal: C++ wrapper for table TblWdbeHistRMUserUniversal (PgSQL database)
	*/
class PgTblWdbeHistRMUserUniversal : public TblWdbeHistRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWdbeHistRMUserUniversal();
	~PgTblWdbeHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeHistRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WdbeHistRMUserUniversal* rec);
	void insertRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WdbeHistRMUserUniversal* rec);
	void updateRst(ListWdbeHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWdbeVCard, WdbeHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint unvIxWdbeVMaintable, Sbecore::uint ixWdbeVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWdbeMUser, Sbecore::uint ixWdbeVCard, const bool append, ListWdbeHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#endif

