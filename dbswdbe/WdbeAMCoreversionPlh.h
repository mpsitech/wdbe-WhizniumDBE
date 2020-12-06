/**
	* \file WdbeAMCoreversionPlh.h
	* database access for table TblWdbeAMCoreversionPlh (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMCOREVERSIONPLH_H
#define WDBEAMCOREVERSIONPLH_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMCoreversionPlh: record of TblWdbeAMCoreversionPlh
	*/
class WdbeAMCoreversionPlh {

public:
	WdbeAMCoreversionPlh(const Sbecore::ubigint ref = 0, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint cvrRefWdbeMCoreversion;
	Sbecore::uint cvrNum;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeAMCoreversionPlh& comp);
	bool operator!=(const WdbeAMCoreversionPlh& comp);
};

/**
	* ListWdbeAMCoreversionPlh: recordset of TblWdbeAMCoreversionPlh
	*/
class ListWdbeAMCoreversionPlh {

public:
	ListWdbeAMCoreversionPlh();
	ListWdbeAMCoreversionPlh(const ListWdbeAMCoreversionPlh& src);
	~ListWdbeAMCoreversionPlh();

	void clear();
	unsigned int size() const;
	void append(WdbeAMCoreversionPlh* rec);

	WdbeAMCoreversionPlh* operator[](const Sbecore::uint ix);
	ListWdbeAMCoreversionPlh& operator=(const ListWdbeAMCoreversionPlh& src);
	bool operator==(const ListWdbeAMCoreversionPlh& comp);
	bool operator!=(const ListWdbeAMCoreversionPlh& comp);

public:
	std::vector<WdbeAMCoreversionPlh*> nodes;
};

/**
	* TblWdbeAMCoreversionPlh: C++ wrapper for table TblWdbeAMCoreversionPlh
	*/
class TblWdbeAMCoreversionPlh {

public:

public:
	TblWdbeAMCoreversionPlh();
	virtual ~TblWdbeAMCoreversionPlh();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionPlh** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionPlh& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMCoreversionPlh* rec);
	Sbecore::ubigint insertNewRec(WdbeAMCoreversionPlh** rec = NULL, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMCoreversionPlh& rst, WdbeAMCoreversionPlh** rec = NULL, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	virtual void updateRec(WdbeAMCoreversionPlh* rec);
	virtual void updateRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionPlh** rec);
	virtual Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionPlh& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMCoreversionPlh& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMCoreversionPlh: C++ wrapper for table TblWdbeAMCoreversionPlh (MySQL database)
	*/
class MyTblWdbeAMCoreversionPlh : public TblWdbeAMCoreversionPlh, public Sbecore::MyTable {

public:
	MyTblWdbeAMCoreversionPlh();
	~MyTblWdbeAMCoreversionPlh();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionPlh& rst);

	Sbecore::ubigint insertRec(WdbeAMCoreversionPlh* rec);
	void insertRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	void updateRec(WdbeAMCoreversionPlh* rec);
	void updateRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionPlh& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMCoreversionPlh: C++ wrapper for table TblWdbeAMCoreversionPlh (PgSQL database)
	*/
class PgTblWdbeAMCoreversionPlh : public TblWdbeAMCoreversionPlh, public Sbecore::PgTable {

public:
	PgTblWdbeAMCoreversionPlh();
	~PgTblWdbeAMCoreversionPlh();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMCoreversionPlh& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMCoreversionPlh& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionPlh& rst);

	Sbecore::ubigint insertRec(WdbeAMCoreversionPlh* rec);
	void insertRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	void updateRec(WdbeAMCoreversionPlh* rec);
	void updateRst(ListWdbeAMCoreversionPlh& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionPlh** rec);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionPlh& rst);
};
#endif

#endif
