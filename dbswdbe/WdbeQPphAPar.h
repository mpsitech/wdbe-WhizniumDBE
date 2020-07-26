/**
	* \file WdbeQPphAPar.h
	* Dbs and XML wrapper for table TblWdbeQPphAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPPHAPAR_H
#define WDBEQPPHAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPphAPar: record of TblWdbeQPphAPar
	*/
class WdbeQPphAPar {

public:
	WdbeQPphAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPphAPar: recordset of TblWdbeQPphAPar
	*/
class ListWdbeQPphAPar {

public:
	ListWdbeQPphAPar();
	ListWdbeQPphAPar(const ListWdbeQPphAPar& src);
	~ListWdbeQPphAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQPphAPar* rec);

	ListWdbeQPphAPar& operator=(const ListWdbeQPphAPar& src);

public:
	std::vector<WdbeQPphAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPphAPar: C++ wrapper for table TblWdbeQPphAPar
	*/
class TblWdbeQPphAPar {

public:
	TblWdbeQPphAPar();
	virtual ~TblWdbeQPphAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPphAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPphAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQPphAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPphAPar& rst, WdbeQPphAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQPphAPar& rst);
	virtual void updateRec(WdbeQPphAPar* rec);
	virtual void updateRst(ListWdbeQPphAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPphAPar: C++ wrapper for table TblWdbeQPphAPar (MySQL database)
	*/
class MyTblWdbeQPphAPar : public TblWdbeQPphAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQPphAPar();
	~MyTblWdbeQPphAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphAPar& rst);

	Sbecore::ubigint insertRec(WdbeQPphAPar* rec);
	void insertRst(ListWdbeQPphAPar& rst);
	void updateRec(WdbeQPphAPar* rec);
	void updateRst(ListWdbeQPphAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPphAPar: C++ wrapper for table TblWdbeQPphAPar (PgSQL database)
	*/
class PgTblWdbeQPphAPar : public TblWdbeQPphAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQPphAPar();
	~PgTblWdbeQPphAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPphAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPphAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphAPar& rst);

	Sbecore::ubigint insertRec(WdbeQPphAPar* rec);
	void insertRst(ListWdbeQPphAPar& rst);
	void updateRec(WdbeQPphAPar* rec);
	void updateRst(ListWdbeQPphAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphAPar& rst);
};
#endif

#endif

