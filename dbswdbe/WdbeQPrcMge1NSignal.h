/**
	* \file WdbeQPrcMge1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQPrcMge1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCMGE1NSIGNAL_H
#define WDBEQPRCMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcMge1NSignal: record of TblWdbeQPrcMge1NSignal
	*/
class WdbeQPrcMge1NSignal {

public:
	WdbeQPrcMge1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQPrcMge1NSignal: recordset of TblWdbeQPrcMge1NSignal
	*/
class ListWdbeQPrcMge1NSignal {

public:
	ListWdbeQPrcMge1NSignal();
	ListWdbeQPrcMge1NSignal(const ListWdbeQPrcMge1NSignal& src);
	~ListWdbeQPrcMge1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcMge1NSignal* rec);

	ListWdbeQPrcMge1NSignal& operator=(const ListWdbeQPrcMge1NSignal& src);

public:
	std::vector<WdbeQPrcMge1NSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcMge1NSignal: C++ wrapper for table TblWdbeQPrcMge1NSignal
	*/
class TblWdbeQPrcMge1NSignal {

public:
	TblWdbeQPrcMge1NSignal();
	virtual ~TblWdbeQPrcMge1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcMge1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcMge1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcMge1NSignal& rst, WdbeQPrcMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQPrcMge1NSignal& rst);
	virtual void updateRec(WdbeQPrcMge1NSignal* rec);
	virtual void updateRst(ListWdbeQPrcMge1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcMge1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcMge1NSignal: C++ wrapper for table TblWdbeQPrcMge1NSignal (MySQL database)
	*/
class MyTblWdbeQPrcMge1NSignal : public TblWdbeQPrcMge1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcMge1NSignal();
	~MyTblWdbeQPrcMge1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQPrcMge1NSignal* rec);
	void insertRst(ListWdbeQPrcMge1NSignal& rst);
	void updateRec(WdbeQPrcMge1NSignal* rec);
	void updateRst(ListWdbeQPrcMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcMge1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcMge1NSignal: C++ wrapper for table TblWdbeQPrcMge1NSignal (PgSQL database)
	*/
class PgTblWdbeQPrcMge1NSignal : public TblWdbeQPrcMge1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcMge1NSignal();
	~PgTblWdbeQPrcMge1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcMge1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcMge1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQPrcMge1NSignal* rec);
	void insertRst(ListWdbeQPrcMge1NSignal& rst);
	void updateRec(WdbeQPrcMge1NSignal* rec);
	void updateRst(ListWdbeQPrcMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcMge1NSignal& rst);
};
#endif

#endif
