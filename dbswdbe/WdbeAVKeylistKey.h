/**
	* \file WdbeAVKeylistKey.h
	* database access for table TblWdbeAVKeylistKey (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAVKEYLISTKEY_H
#define WDBEAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAVKeylistKey: record of TblWdbeAVKeylistKey
	*/
class WdbeAVKeylistKey {

public:
	WdbeAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::uint klsIxWdbeVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWdbeVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint klsIxWdbeVKeylist;
	Sbecore::uint klsNum;
	Sbecore::uint x1IxWdbeVMaintable;
	Sbecore::ubigint x1Uref;
	bool Fixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WdbeAVKeylistKey& comp);
	bool operator!=(const WdbeAVKeylistKey& comp);
};

/**
	* ListWdbeAVKeylistKey: recordset of TblWdbeAVKeylistKey
	*/
class ListWdbeAVKeylistKey {

public:
	ListWdbeAVKeylistKey();
	ListWdbeAVKeylistKey(const ListWdbeAVKeylistKey& src);
	~ListWdbeAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WdbeAVKeylistKey* rec);

	WdbeAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWdbeAVKeylistKey& operator=(const ListWdbeAVKeylistKey& src);
	bool operator==(const ListWdbeAVKeylistKey& comp);
	bool operator!=(const ListWdbeAVKeylistKey& comp);

public:
	std::vector<WdbeAVKeylistKey*> nodes;
};

/**
	* TblWdbeAVKeylistKey: C++ wrapper for table TblWdbeAVKeylistKey
	*/
class TblWdbeAVKeylistKey {

public:

public:
	TblWdbeAVKeylistKey();
	virtual ~TblWdbeAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WdbeAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WdbeAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWdbeVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWdbeVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAVKeylistKey& rst, WdbeAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWdbeVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWdbeVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WdbeAVKeylistKey* rec);
	virtual void updateRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	virtual bool loadRefByKlsSrf(Sbecore::uint klsIxWdbeVKeylist, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWdbeVKeylist, const bool append, ListWdbeAVKeylistKey& rst);
	virtual Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWdbeAVKeylistKey& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAVKeylistKey: C++ wrapper for table TblWdbeAVKeylistKey (MySQL database)
	*/
class MyTblWdbeAVKeylistKey : public TblWdbeAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWdbeAVKeylistKey();
	~MyTblWdbeAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WdbeAVKeylistKey* rec);
	void insertRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	void updateRec(WdbeAVKeylistKey* rec);
	void updateRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWdbeVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWdbeVKeylist, const bool append, ListWdbeAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWdbeAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAVKeylistKey: C++ wrapper for table TblWdbeAVKeylistKey (PgSQL database)
	*/
class PgTblWdbeAVKeylistKey : public TblWdbeAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWdbeAVKeylistKey();
	~PgTblWdbeAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WdbeAVKeylistKey* rec);
	void insertRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	void updateRec(WdbeAVKeylistKey* rec);
	void updateRst(ListWdbeAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWdbeVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWdbeVKeylist, const bool append, ListWdbeAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWdbeVKeylist, Sbecore::uint x1IxWdbeVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWdbeAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

