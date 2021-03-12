/**
	* \file WdbeQSilSil1NUnit.h
	* Dbs and XML wrapper for table TblWdbeQSilSil1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILSIL1NUNIT_H
#define WDBEQSILSIL1NUNIT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilSil1NUnit: record of TblWdbeQSilSil1NUnit
	*/
class WdbeQSilSil1NUnit {

public:
	WdbeQSilSil1NUnit(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSilSil1NUnit: recordset of TblWdbeQSilSil1NUnit
	*/
class ListWdbeQSilSil1NUnit {

public:
	ListWdbeQSilSil1NUnit();
	ListWdbeQSilSil1NUnit(const ListWdbeQSilSil1NUnit& src);
	~ListWdbeQSilSil1NUnit();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilSil1NUnit* rec);

	ListWdbeQSilSil1NUnit& operator=(const ListWdbeQSilSil1NUnit& src);

public:
	std::vector<WdbeQSilSil1NUnit*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilSil1NUnit: C++ wrapper for table TblWdbeQSilSil1NUnit
	*/
class TblWdbeQSilSil1NUnit {

public:
	TblWdbeQSilSil1NUnit();
	virtual ~TblWdbeQSilSil1NUnit();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilSil1NUnit** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilSil1NUnit& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilSil1NUnit* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilSil1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilSil1NUnit& rst, WdbeQSilSil1NUnit** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSilSil1NUnit& rst);
	virtual void updateRec(WdbeQSilSil1NUnit* rec);
	virtual void updateRst(ListWdbeQSilSil1NUnit& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilSil1NUnit** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilSil1NUnit& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilSil1NUnit: C++ wrapper for table TblWdbeQSilSil1NUnit (MySQL database)
	*/
class MyTblWdbeQSilSil1NUnit : public TblWdbeQSilSil1NUnit, public Sbecore::MyTable {

public:
	MyTblWdbeQSilSil1NUnit();
	~MyTblWdbeQSilSil1NUnit();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilSil1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQSilSil1NUnit* rec);
	void insertRst(ListWdbeQSilSil1NUnit& rst);
	void updateRec(WdbeQSilSil1NUnit* rec);
	void updateRst(ListWdbeQSilSil1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilSil1NUnit& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilSil1NUnit: C++ wrapper for table TblWdbeQSilSil1NUnit (PgSQL database)
	*/
class PgTblWdbeQSilSil1NUnit : public TblWdbeQSilSil1NUnit, public Sbecore::PgTable {

public:
	PgTblWdbeQSilSil1NUnit();
	~PgTblWdbeQSilSil1NUnit();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilSil1NUnit& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilSil1NUnit& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilSil1NUnit& rst);

	Sbecore::ubigint insertRec(WdbeQSilSil1NUnit* rec);
	void insertRst(ListWdbeQSilSil1NUnit& rst);
	void updateRec(WdbeQSilSil1NUnit* rec);
	void updateRst(ListWdbeQSilSil1NUnit& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilSil1NUnit** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilSil1NUnit& rst);
};
#endif

#endif
