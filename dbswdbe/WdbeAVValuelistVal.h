/**
	* \file WdbeAVValuelistVal.h
	* database access for table TblWdbeAVValuelistVal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAVVALUELISTVAL_H
#define WDBEAVVALUELISTVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAVValuelistVal: record of TblWdbeAVValuelistVal
	*/
class WdbeAVValuelistVal {

public:
	WdbeAVValuelistVal(const Sbecore::ubigint ref = 0, const Sbecore::uint vlsIxWdbeVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint vlsIxWdbeVValuelist;
	Sbecore::uint vlsNum;
	Sbecore::uint x1IxWdbeVLocale;
	std::string Val;

public:
	bool operator==(const WdbeAVValuelistVal& comp);
	bool operator!=(const WdbeAVValuelistVal& comp);
};

/**
	* ListWdbeAVValuelistVal: recordset of TblWdbeAVValuelistVal
	*/
class ListWdbeAVValuelistVal {

public:
	ListWdbeAVValuelistVal();
	ListWdbeAVValuelistVal(const ListWdbeAVValuelistVal& src);
	~ListWdbeAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(WdbeAVValuelistVal* rec);

	WdbeAVValuelistVal* operator[](const Sbecore::uint ix);
	ListWdbeAVValuelistVal& operator=(const ListWdbeAVValuelistVal& src);
	bool operator==(const ListWdbeAVValuelistVal& comp);
	bool operator!=(const ListWdbeAVValuelistVal& comp);

public:
	std::vector<WdbeAVValuelistVal*> nodes;
};

/**
	* TblWdbeAVValuelistVal: C++ wrapper for table TblWdbeAVValuelistVal
	*/
class TblWdbeAVValuelistVal {

public:

public:
	TblWdbeAVValuelistVal();
	virtual ~TblWdbeAVValuelistVal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVValuelistVal& rst);

	virtual Sbecore::ubigint insertRec(WdbeAVValuelistVal* rec);
	Sbecore::ubigint insertNewRec(WdbeAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWdbeVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAVValuelistVal& rst, WdbeAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWdbeVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string Val = "");
	virtual void insertRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(WdbeAVValuelistVal* rec);
	virtual void updateRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWdbeVValuelist, Sbecore::uint x1IxWdbeVLocale, const bool append, ListWdbeAVValuelistVal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAVValuelistVal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAVValuelistVal: C++ wrapper for table TblWdbeAVValuelistVal (MySQL database)
	*/
class MyTblWdbeAVValuelistVal : public TblWdbeAVValuelistVal, public Sbecore::MyTable {

public:
	MyTblWdbeAVValuelistVal();
	~MyTblWdbeAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WdbeAVValuelistVal* rec);
	void insertRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	void updateRec(WdbeAVValuelistVal* rec);
	void updateRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWdbeVValuelist, Sbecore::uint x1IxWdbeVLocale, const bool append, ListWdbeAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAVValuelistVal: C++ wrapper for table TblWdbeAVValuelistVal (PgSQL database)
	*/
class PgTblWdbeAVValuelistVal : public TblWdbeAVValuelistVal, public Sbecore::PgTable {

public:
	PgTblWdbeAVValuelistVal();
	~PgTblWdbeAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAVValuelistVal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WdbeAVValuelistVal* rec);
	void insertRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	void updateRec(WdbeAVValuelistVal* rec);
	void updateRst(ListWdbeAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWdbeVValuelist, Sbecore::uint x1IxWdbeVLocale, const bool append, ListWdbeAVValuelistVal& rst);
};
#endif

#endif

