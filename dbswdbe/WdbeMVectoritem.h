/**
	* \file WdbeMVectoritem.h
	* database access for table TblWdbeMVectoritem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMVECTORITEM_H
#define WDBEMVECTORITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMVectoritem: record of TblWdbeMVectoritem
	*/
class WdbeMVectoritem {

public:
	WdbeMVectoritem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint vecRefWdbeMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint vecRefWdbeMVector;
	Sbecore::uint vecNum;
	std::string sref;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WdbeMVectoritem& comp);
	bool operator!=(const WdbeMVectoritem& comp);
};

/**
	* ListWdbeMVectoritem: recordset of TblWdbeMVectoritem
	*/
class ListWdbeMVectoritem {

public:
	ListWdbeMVectoritem();
	ListWdbeMVectoritem(const ListWdbeMVectoritem& src);
	~ListWdbeMVectoritem();

	void clear();
	unsigned int size() const;
	void append(WdbeMVectoritem* rec);

	WdbeMVectoritem* operator[](const Sbecore::uint ix);
	ListWdbeMVectoritem& operator=(const ListWdbeMVectoritem& src);
	bool operator==(const ListWdbeMVectoritem& comp);
	bool operator!=(const ListWdbeMVectoritem& comp);

public:
	std::vector<WdbeMVectoritem*> nodes;
};

/**
	* TblWdbeMVectoritem: C++ wrapper for table TblWdbeMVectoritem
	*/
class TblWdbeMVectoritem {

public:

public:
	TblWdbeMVectoritem();
	virtual ~TblWdbeMVectoritem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMVectoritem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVectoritem& rst);

	virtual Sbecore::ubigint insertRec(WdbeMVectoritem* rec);
	Sbecore::ubigint insertNewRec(WdbeMVectoritem** rec = NULL, const Sbecore::ubigint vecRefWdbeMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMVectoritem& rst, WdbeMVectoritem** rec = NULL, const Sbecore::ubigint vecRefWdbeMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMVectoritem& rst, bool transact = false);
	virtual void updateRec(WdbeMVectoritem* rec);
	virtual void updateRst(ListWdbeMVectoritem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMVectoritem** rec);
	virtual Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, ListWdbeMVectoritem& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMVectoritem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMVectoritem: C++ wrapper for table TblWdbeMVectoritem (MySQL database)
	*/
class MyTblWdbeMVectoritem : public TblWdbeMVectoritem, public Sbecore::MyTable {

public:
	MyTblWdbeMVectoritem();
	~MyTblWdbeMVectoritem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVectoritem& rst);

	Sbecore::ubigint insertRec(WdbeMVectoritem* rec);
	void insertRst(ListWdbeMVectoritem& rst, bool transact = false);
	void updateRec(WdbeMVectoritem* rec);
	void updateRst(ListWdbeMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, ListWdbeMVectoritem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMVectoritem: C++ wrapper for table TblWdbeMVectoritem (PgSQL database)
	*/
class PgTblWdbeMVectoritem : public TblWdbeMVectoritem, public Sbecore::PgTable {

public:
	PgTblWdbeMVectoritem();
	~PgTblWdbeMVectoritem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMVectoritem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMVectoritem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVectoritem& rst);

	Sbecore::ubigint insertRec(WdbeMVectoritem* rec);
	void insertRst(ListWdbeMVectoritem& rst, bool transact = false);
	void updateRec(WdbeMVectoritem* rec);
	void updateRst(ListWdbeMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVectoritem** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWdbeMVector, const bool append, ListWdbeMVectoritem& rst);
};
#endif

#endif

