/**
	* \file WdbeQVer1NUnit.h
	* Dbs and XML wrapper for table TblWdbeQVer1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVER1NUNIT_H
#define WDBEQVER1NUNIT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVer1NUnit: record of TblWdbeQVer1NUnit
	*/
class WdbeQVer1NUnit {

public:
	WdbeQVer1NUnit(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVer1NUnit: recordset of TblWdbeQVer1NUnit
	*/
class ListWdbeQVer1NUnit {

public:
	ListWdbeQVer1NUnit();
	ListWdbeQVer1NUnit(const ListWdbeQVer1NUnit& src);
	~ListWdbeQVer1NUnit();

	void clear();
	unsigned int size() const;
	void append(WdbeQVer1NUnit* rec);

	ListWdbeQVer1NUnit& operator=(const ListWdbeQVer1NUnit& src);

public:
	std::vector<WdbeQVer1NUnit*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVer1NUnit: C++ wrapper for table TblWdbeQVer1NUnit
	*/
class TblWdbeQVer1NUnit {

public:
	TblWdbeQVer1NUnit();
	virtual ~TblWdbeQVer1NUnit();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NUnit** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NUnit& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVer1NUnit* rec);
	Sbecore::ubigint insertNewRec(WdbeQVer1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVer1NUnit& rst, WdbeQVer1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVer1NUnit& rst);
	virtual void updateRec(WdbeQVer1NUnit* rec);
	virtual void updateRst(ListWdbeQVer1NUnit& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NUnit** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NUnit& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVer1NUnit: C++ wrapper for table TblWdbeQVer1NUnit (MySQL database)
	*/
class MyTblWdbeQVer1NUnit : public TblWdbeQVer1NUnit, public Sbecore::MyTable {

public:
	MyTblWdbeQVer1NUnit();
	~MyTblWdbeQVer1NUnit();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NUnit* rec);
	void insertRst(ListWdbeQVer1NUnit& rst);
	void updateRec(WdbeQVer1NUnit* rec);
	void updateRst(ListWdbeQVer1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NUnit& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVer1NUnit: C++ wrapper for table TblWdbeQVer1NUnit (PgSQL database)
	*/
class PgTblWdbeQVer1NUnit : public TblWdbeQVer1NUnit, public Sbecore::PgTable {

public:
	PgTblWdbeQVer1NUnit();
	~PgTblWdbeQVer1NUnit();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVer1NUnit& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVer1NUnit& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NUnit* rec);
	void insertRst(ListWdbeQVer1NUnit& rst);
	void updateRec(WdbeQVer1NUnit* rec);
	void updateRst(ListWdbeQVer1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NUnit& rst);
};
#endif

#endif

