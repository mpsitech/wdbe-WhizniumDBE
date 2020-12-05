/**
	* \file WdbeQFam1NUnit.h
	* Dbs and XML wrapper for table TblWdbeQFam1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFAM1NUNIT_H
#define WDBEQFAM1NUNIT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQFam1NUnit: record of TblWdbeQFam1NUnit
	*/
class WdbeQFam1NUnit {

public:
	WdbeQFam1NUnit(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQFam1NUnit: recordset of TblWdbeQFam1NUnit
	*/
class ListWdbeQFam1NUnit {

public:
	ListWdbeQFam1NUnit();
	ListWdbeQFam1NUnit(const ListWdbeQFam1NUnit& src);
	~ListWdbeQFam1NUnit();

	void clear();
	unsigned int size() const;
	void append(WdbeQFam1NUnit* rec);

	ListWdbeQFam1NUnit& operator=(const ListWdbeQFam1NUnit& src);

public:
	std::vector<WdbeQFam1NUnit*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQFam1NUnit: C++ wrapper for table TblWdbeQFam1NUnit
	*/
class TblWdbeQFam1NUnit {

public:
	TblWdbeQFam1NUnit();
	virtual ~TblWdbeQFam1NUnit();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQFam1NUnit** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFam1NUnit& rst);

	virtual Sbecore::ubigint insertRec(WdbeQFam1NUnit* rec);
	Sbecore::ubigint insertNewRec(WdbeQFam1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQFam1NUnit& rst, WdbeQFam1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQFam1NUnit& rst);
	virtual void updateRec(WdbeQFam1NUnit* rec);
	virtual void updateRst(ListWdbeQFam1NUnit& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQFam1NUnit** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFam1NUnit& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQFam1NUnit: C++ wrapper for table TblWdbeQFam1NUnit (MySQL database)
	*/
class MyTblWdbeQFam1NUnit : public TblWdbeQFam1NUnit, public Sbecore::MyTable {

public:
	MyTblWdbeQFam1NUnit();
	~MyTblWdbeQFam1NUnit();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFam1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQFam1NUnit* rec);
	void insertRst(ListWdbeQFam1NUnit& rst);
	void updateRec(WdbeQFam1NUnit* rec);
	void updateRst(ListWdbeQFam1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFam1NUnit& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQFam1NUnit: C++ wrapper for table TblWdbeQFam1NUnit (PgSQL database)
	*/
class PgTblWdbeQFam1NUnit : public TblWdbeQFam1NUnit, public Sbecore::PgTable {

public:
	PgTblWdbeQFam1NUnit();
	~PgTblWdbeQFam1NUnit();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQFam1NUnit& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQFam1NUnit& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFam1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQFam1NUnit* rec);
	void insertRst(ListWdbeQFam1NUnit& rst);
	void updateRec(WdbeQFam1NUnit* rec);
	void updateRst(ListWdbeQFam1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFam1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFam1NUnit& rst);
};
#endif

#endif

