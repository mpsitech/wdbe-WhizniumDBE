/**
	* \file WdbeQMtpAPar.h
	* Dbs and XML wrapper for table TblWdbeQMtpAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPAPAR_H
#define WDBEQMTPAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpAPar: record of TblWdbeQMtpAPar
	*/
class WdbeQMtpAPar {

public:
	WdbeQMtpAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

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
	* ListWdbeQMtpAPar: recordset of TblWdbeQMtpAPar
	*/
class ListWdbeQMtpAPar {

public:
	ListWdbeQMtpAPar();
	ListWdbeQMtpAPar(const ListWdbeQMtpAPar& src);
	~ListWdbeQMtpAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpAPar* rec);

	ListWdbeQMtpAPar& operator=(const ListWdbeQMtpAPar& src);

public:
	std::vector<WdbeQMtpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpAPar: C++ wrapper for table TblWdbeQMtpAPar
	*/
class TblWdbeQMtpAPar {

public:
	TblWdbeQMtpAPar();
	virtual ~TblWdbeQMtpAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpAPar& rst, WdbeQMtpAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mdlNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQMtpAPar& rst);
	virtual void updateRec(WdbeQMtpAPar* rec);
	virtual void updateRst(ListWdbeQMtpAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpAPar: C++ wrapper for table TblWdbeQMtpAPar (MySQL database)
	*/
class MyTblWdbeQMtpAPar : public TblWdbeQMtpAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpAPar();
	~MyTblWdbeQMtpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpAPar& rst);

	Sbecore::ubigint insertRec(WdbeQMtpAPar* rec);
	void insertRst(ListWdbeQMtpAPar& rst);
	void updateRec(WdbeQMtpAPar* rec);
	void updateRst(ListWdbeQMtpAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpAPar: C++ wrapper for table TblWdbeQMtpAPar (PgSQL database)
	*/
class PgTblWdbeQMtpAPar : public TblWdbeQMtpAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpAPar();
	~PgTblWdbeQMtpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpAPar& rst);

	Sbecore::ubigint insertRec(WdbeQMtpAPar* rec);
	void insertRst(ListWdbeQMtpAPar& rst);
	void updateRec(WdbeQMtpAPar* rec);
	void updateRst(ListWdbeQMtpAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpAPar& rst);
};
#endif

#endif

