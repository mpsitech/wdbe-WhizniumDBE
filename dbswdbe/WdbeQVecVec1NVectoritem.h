/**
	* \file WdbeQVecVec1NVectoritem.h
	* Dbs and XML wrapper for table TblWdbeQVecVec1NVectoritem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVECVEC1NVECTORITEM_H
#define WDBEQVECVEC1NVECTORITEM_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVecVec1NVectoritem: record of TblWdbeQVecVec1NVectoritem
	*/
class WdbeQVecVec1NVectoritem {

public:
	WdbeQVecVec1NVectoritem(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint vecNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVecVec1NVectoritem: recordset of TblWdbeQVecVec1NVectoritem
	*/
class ListWdbeQVecVec1NVectoritem {

public:
	ListWdbeQVecVec1NVectoritem();
	ListWdbeQVecVec1NVectoritem(const ListWdbeQVecVec1NVectoritem& src);
	~ListWdbeQVecVec1NVectoritem();

	void clear();
	unsigned int size() const;
	void append(WdbeQVecVec1NVectoritem* rec);

	ListWdbeQVecVec1NVectoritem& operator=(const ListWdbeQVecVec1NVectoritem& src);

public:
	std::vector<WdbeQVecVec1NVectoritem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVecVec1NVectoritem: C++ wrapper for table TblWdbeQVecVec1NVectoritem
	*/
class TblWdbeQVecVec1NVectoritem {

public:
	TblWdbeQVecVec1NVectoritem();
	virtual ~TblWdbeQVecVec1NVectoritem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVecVec1NVectoritem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecVec1NVectoritem& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVecVec1NVectoritem* rec);
	Sbecore::ubigint insertNewRec(WdbeQVecVec1NVectoritem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVecVec1NVectoritem& rst, WdbeQVecVec1NVectoritem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);
	virtual void insertRst(ListWdbeQVecVec1NVectoritem& rst);
	virtual void updateRec(WdbeQVecVec1NVectoritem* rec);
	virtual void updateRst(ListWdbeQVecVec1NVectoritem& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecVec1NVectoritem** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecVec1NVectoritem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVecVec1NVectoritem: C++ wrapper for table TblWdbeQVecVec1NVectoritem (MySQL database)
	*/
class MyTblWdbeQVecVec1NVectoritem : public TblWdbeQVecVec1NVectoritem, public Sbecore::MyTable {

public:
	MyTblWdbeQVecVec1NVectoritem();
	~MyTblWdbeQVecVec1NVectoritem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecVec1NVectoritem& rst);

	Sbecore::ubigint insertRec(WdbeQVecVec1NVectoritem* rec);
	void insertRst(ListWdbeQVecVec1NVectoritem& rst);
	void updateRec(WdbeQVecVec1NVectoritem* rec);
	void updateRst(ListWdbeQVecVec1NVectoritem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecVec1NVectoritem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVecVec1NVectoritem: C++ wrapper for table TblWdbeQVecVec1NVectoritem (PgSQL database)
	*/
class PgTblWdbeQVecVec1NVectoritem : public TblWdbeQVecVec1NVectoritem, public Sbecore::PgTable {

public:
	PgTblWdbeQVecVec1NVectoritem();
	~PgTblWdbeQVecVec1NVectoritem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVecVec1NVectoritem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVecVec1NVectoritem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecVec1NVectoritem& rst);

	Sbecore::ubigint insertRec(WdbeQVecVec1NVectoritem* rec);
	void insertRst(ListWdbeQVecVec1NVectoritem& rst);
	void updateRec(WdbeQVecVec1NVectoritem* rec);
	void updateRst(ListWdbeQVecVec1NVectoritem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecVec1NVectoritem& rst);
};
#endif

#endif
