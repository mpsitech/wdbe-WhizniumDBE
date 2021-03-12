/**
	* \file WdbeQUsr1NSession.h
	* Dbs and XML wrapper for table TblWdbeQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSR1NSESSION_H
#define WDBEQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsr1NSession: record of TblWdbeQUsr1NSession
	*/
class WdbeQUsr1NSession {

public:
	WdbeQUsr1NSession(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUsr1NSession: recordset of TblWdbeQUsr1NSession
	*/
class ListWdbeQUsr1NSession {

public:
	ListWdbeQUsr1NSession();
	ListWdbeQUsr1NSession(const ListWdbeQUsr1NSession& src);
	~ListWdbeQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsr1NSession* rec);

	ListWdbeQUsr1NSession& operator=(const ListWdbeQUsr1NSession& src);

public:
	std::vector<WdbeQUsr1NSession*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsr1NSession: C++ wrapper for table TblWdbeQUsr1NSession
	*/
class TblWdbeQUsr1NSession {

public:
	TblWdbeQUsr1NSession();
	virtual ~TblWdbeQUsr1NSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsr1NSession& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsr1NSession* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsr1NSession& rst, WdbeQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUsr1NSession& rst);
	virtual void updateRec(WdbeQUsr1NSession* rec);
	virtual void updateRst(ListWdbeQUsr1NSession& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsr1NSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsr1NSession: C++ wrapper for table TblWdbeQUsr1NSession (MySQL database)
	*/
class MyTblWdbeQUsr1NSession : public TblWdbeQUsr1NSession, public Sbecore::MyTable {

public:
	MyTblWdbeQUsr1NSession();
	~MyTblWdbeQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WdbeQUsr1NSession* rec);
	void insertRst(ListWdbeQUsr1NSession& rst);
	void updateRec(WdbeQUsr1NSession* rec);
	void updateRst(ListWdbeQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsr1NSession: C++ wrapper for table TblWdbeQUsr1NSession (PgSQL database)
	*/
class PgTblWdbeQUsr1NSession : public TblWdbeQUsr1NSession, public Sbecore::PgTable {

public:
	PgTblWdbeQUsr1NSession();
	~PgTblWdbeQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsr1NSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WdbeQUsr1NSession* rec);
	void insertRst(ListWdbeQUsr1NSession& rst);
	void updateRec(WdbeQUsr1NSession* rec);
	void updateRst(ListWdbeQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsr1NSession& rst);
};
#endif

#endif
