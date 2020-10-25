/**
	* \file WdbeQMchAPar.h
	* Dbs and XML wrapper for table TblWdbeQMchAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMCHAPAR_H
#define WDBEQMCHAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMchAPar: record of TblWdbeQMchAPar
	*/
class WdbeQMchAPar {

public:
	WdbeQMchAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

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
	* ListWdbeQMchAPar: recordset of TblWdbeQMchAPar
	*/
class ListWdbeQMchAPar {

public:
	ListWdbeQMchAPar();
	ListWdbeQMchAPar(const ListWdbeQMchAPar& src);
	~ListWdbeQMchAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQMchAPar* rec);

	ListWdbeQMchAPar& operator=(const ListWdbeQMchAPar& src);

public:
	std::vector<WdbeQMchAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMchAPar: C++ wrapper for table TblWdbeQMchAPar
	*/
class TblWdbeQMchAPar {

public:
	TblWdbeQMchAPar();
	virtual ~TblWdbeQMchAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMchAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQMchAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMchAPar& rst, WdbeQMchAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQMchAPar& rst);
	virtual void updateRec(WdbeQMchAPar* rec);
	virtual void updateRst(ListWdbeQMchAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMchAPar: C++ wrapper for table TblWdbeQMchAPar (MySQL database)
	*/
class MyTblWdbeQMchAPar : public TblWdbeQMchAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQMchAPar();
	~MyTblWdbeQMchAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAPar& rst);

	Sbecore::ubigint insertRec(WdbeQMchAPar* rec);
	void insertRst(ListWdbeQMchAPar& rst);
	void updateRec(WdbeQMchAPar* rec);
	void updateRst(ListWdbeQMchAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMchAPar: C++ wrapper for table TblWdbeQMchAPar (PgSQL database)
	*/
class PgTblWdbeQMchAPar : public TblWdbeQMchAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQMchAPar();
	~PgTblWdbeQMchAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMchAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMchAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAPar& rst);

	Sbecore::ubigint insertRec(WdbeQMchAPar* rec);
	void insertRst(ListWdbeQMchAPar& rst);
	void updateRec(WdbeQMchAPar* rec);
	void updateRst(ListWdbeQMchAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAPar& rst);
};
#endif

#endif

