/**
	* \file WdbeQUntSil1NUnit.h
	* Dbs and XML wrapper for table TblWdbeQUntSil1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTSIL1NUNIT_H
#define WDBEQUNTSIL1NUNIT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntSil1NUnit: record of TblWdbeQUntSil1NUnit
	*/
class WdbeQUntSil1NUnit {

public:
	WdbeQUntSil1NUnit(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUntSil1NUnit: recordset of TblWdbeQUntSil1NUnit
	*/
class ListWdbeQUntSil1NUnit {

public:
	ListWdbeQUntSil1NUnit();
	ListWdbeQUntSil1NUnit(const ListWdbeQUntSil1NUnit& src);
	~ListWdbeQUntSil1NUnit();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntSil1NUnit* rec);

	ListWdbeQUntSil1NUnit& operator=(const ListWdbeQUntSil1NUnit& src);

public:
	std::vector<WdbeQUntSil1NUnit*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntSil1NUnit: C++ wrapper for table TblWdbeQUntSil1NUnit
	*/
class TblWdbeQUntSil1NUnit {

public:
	TblWdbeQUntSil1NUnit();
	virtual ~TblWdbeQUntSil1NUnit();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntSil1NUnit** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntSil1NUnit& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntSil1NUnit* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntSil1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntSil1NUnit& rst, WdbeQUntSil1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUntSil1NUnit& rst);
	virtual void updateRec(WdbeQUntSil1NUnit* rec);
	virtual void updateRst(ListWdbeQUntSil1NUnit& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntSil1NUnit** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntSil1NUnit& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntSil1NUnit: C++ wrapper for table TblWdbeQUntSil1NUnit (MySQL database)
	*/
class MyTblWdbeQUntSil1NUnit : public TblWdbeQUntSil1NUnit, public Sbecore::MyTable {

public:
	MyTblWdbeQUntSil1NUnit();
	~MyTblWdbeQUntSil1NUnit();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntSil1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQUntSil1NUnit* rec);
	void insertRst(ListWdbeQUntSil1NUnit& rst);
	void updateRec(WdbeQUntSil1NUnit* rec);
	void updateRst(ListWdbeQUntSil1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntSil1NUnit& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntSil1NUnit: C++ wrapper for table TblWdbeQUntSil1NUnit (PgSQL database)
	*/
class PgTblWdbeQUntSil1NUnit : public TblWdbeQUntSil1NUnit, public Sbecore::PgTable {

public:
	PgTblWdbeQUntSil1NUnit();
	~PgTblWdbeQUntSil1NUnit();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntSil1NUnit& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntSil1NUnit& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntSil1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQUntSil1NUnit* rec);
	void insertRst(ListWdbeQUntSil1NUnit& rst);
	void updateRec(WdbeQUntSil1NUnit* rec);
	void updateRst(ListWdbeQUntSil1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntSil1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntSil1NUnit& rst);
};
#endif

#endif
