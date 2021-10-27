/**
	* \file WdbeQUntRef1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQUntRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQUNTREF1NSIGNAL_H
#define WDBEQUNTREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntRef1NSignal: record of TblWdbeQUntRef1NSignal
	*/
class WdbeQUntRef1NSignal {

public:
	WdbeQUntRef1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntRef1NSignal: recordset of TblWdbeQUntRef1NSignal
	*/
class ListWdbeQUntRef1NSignal {

public:
	ListWdbeQUntRef1NSignal();
	ListWdbeQUntRef1NSignal(const ListWdbeQUntRef1NSignal& src);
	~ListWdbeQUntRef1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntRef1NSignal* rec);

	ListWdbeQUntRef1NSignal& operator=(const ListWdbeQUntRef1NSignal& src);

public:
	std::vector<WdbeQUntRef1NSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntRef1NSignal: C++ wrapper for table TblWdbeQUntRef1NSignal
	*/
class TblWdbeQUntRef1NSignal {

public:
	TblWdbeQUntRef1NSignal();
	virtual ~TblWdbeQUntRef1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntRef1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntRef1NSignal& rst, WdbeQUntRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQUntRef1NSignal& rst);
	virtual void updateRec(WdbeQUntRef1NSignal* rec);
	virtual void updateRst(ListWdbeQUntRef1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntRef1NSignal: C++ wrapper for table TblWdbeQUntRef1NSignal (MySQL database)
	*/
class MyTblWdbeQUntRef1NSignal : public TblWdbeQUntRef1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQUntRef1NSignal();
	~MyTblWdbeQUntRef1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NSignal* rec);
	void insertRst(ListWdbeQUntRef1NSignal& rst);
	void updateRec(WdbeQUntRef1NSignal* rec);
	void updateRst(ListWdbeQUntRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntRef1NSignal: C++ wrapper for table TblWdbeQUntRef1NSignal (PgSQL database)
	*/
class PgTblWdbeQUntRef1NSignal : public TblWdbeQUntRef1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQUntRef1NSignal();
	~PgTblWdbeQUntRef1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntRef1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntRef1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NSignal* rec);
	void insertRst(ListWdbeQUntRef1NSignal& rst);
	void updateRec(WdbeQUntRef1NSignal* rec);
	void updateRst(ListWdbeQUntRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NSignal& rst);
};
#endif

#endif
