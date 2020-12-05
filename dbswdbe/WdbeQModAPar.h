/**
	* \file WdbeQModAPar.h
	* Dbs and XML wrapper for table TblWdbeQModAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODAPAR_H
#define WDBEQMODAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModAPar: record of TblWdbeQModAPar
	*/
class WdbeQModAPar {

public:
	WdbeQModAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint mdlNum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModAPar: recordset of TblWdbeQModAPar
	*/
class ListWdbeQModAPar {

public:
	ListWdbeQModAPar();
	ListWdbeQModAPar(const ListWdbeQModAPar& src);
	~ListWdbeQModAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQModAPar* rec);

	ListWdbeQModAPar& operator=(const ListWdbeQModAPar& src);

public:
	std::vector<WdbeQModAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModAPar: C++ wrapper for table TblWdbeQModAPar
	*/
class TblWdbeQModAPar {

public:
	TblWdbeQModAPar();
	virtual ~TblWdbeQModAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQModAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModAPar& rst, WdbeQModAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQModAPar& rst);
	virtual void updateRec(WdbeQModAPar* rec);
	virtual void updateRst(ListWdbeQModAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModAPar: C++ wrapper for table TblWdbeQModAPar (MySQL database)
	*/
class MyTblWdbeQModAPar : public TblWdbeQModAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQModAPar();
	~MyTblWdbeQModAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModAPar& rst);

	Sbecore::ubigint insertRec(WdbeQModAPar* rec);
	void insertRst(ListWdbeQModAPar& rst);
	void updateRec(WdbeQModAPar* rec);
	void updateRst(ListWdbeQModAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModAPar: C++ wrapper for table TblWdbeQModAPar (PgSQL database)
	*/
class PgTblWdbeQModAPar : public TblWdbeQModAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQModAPar();
	~PgTblWdbeQModAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModAPar& rst);

	Sbecore::ubigint insertRec(WdbeQModAPar* rec);
	void insertRst(ListWdbeQModAPar& rst);
	void updateRec(WdbeQModAPar* rec);
	void updateRst(ListWdbeQModAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModAPar& rst);
};
#endif

#endif

