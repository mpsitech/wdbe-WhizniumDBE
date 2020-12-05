/**
	* \file WdbeQPinAPar.h
	* Dbs and XML wrapper for table TblWdbeQPinAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPINAPAR_H
#define WDBEQPINAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPinAPar: record of TblWdbeQPinAPar
	*/
class WdbeQPinAPar {

public:
	WdbeQPinAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

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
	* ListWdbeQPinAPar: recordset of TblWdbeQPinAPar
	*/
class ListWdbeQPinAPar {

public:
	ListWdbeQPinAPar();
	ListWdbeQPinAPar(const ListWdbeQPinAPar& src);
	~ListWdbeQPinAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQPinAPar* rec);

	ListWdbeQPinAPar& operator=(const ListWdbeQPinAPar& src);

public:
	std::vector<WdbeQPinAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPinAPar: C++ wrapper for table TblWdbeQPinAPar
	*/
class TblWdbeQPinAPar {

public:
	TblWdbeQPinAPar();
	virtual ~TblWdbeQPinAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPinAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPinAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQPinAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPinAPar& rst, WdbeQPinAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQPinAPar& rst);
	virtual void updateRec(WdbeQPinAPar* rec);
	virtual void updateRst(ListWdbeQPinAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPinAPar: C++ wrapper for table TblWdbeQPinAPar (MySQL database)
	*/
class MyTblWdbeQPinAPar : public TblWdbeQPinAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQPinAPar();
	~MyTblWdbeQPinAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinAPar& rst);

	Sbecore::ubigint insertRec(WdbeQPinAPar* rec);
	void insertRst(ListWdbeQPinAPar& rst);
	void updateRec(WdbeQPinAPar* rec);
	void updateRst(ListWdbeQPinAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPinAPar: C++ wrapper for table TblWdbeQPinAPar (PgSQL database)
	*/
class PgTblWdbeQPinAPar : public TblWdbeQPinAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQPinAPar();
	~PgTblWdbeQPinAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPinAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPinAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinAPar& rst);

	Sbecore::ubigint insertRec(WdbeQPinAPar* rec);
	void insertRst(ListWdbeQPinAPar& rst);
	void updateRec(WdbeQPinAPar* rec);
	void updateRst(ListWdbeQPinAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinAPar& rst);
};
#endif

#endif

