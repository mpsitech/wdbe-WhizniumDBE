/**
	* \file WdbeQSilRef1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQSilRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSILREF1NSIGNAL_H
#define WDBEQSILREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilRef1NSignal: record of TblWdbeQSilRef1NSignal
	*/
class WdbeQSilRef1NSignal {

public:
	WdbeQSilRef1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQSilRef1NSignal: recordset of TblWdbeQSilRef1NSignal
	*/
class ListWdbeQSilRef1NSignal {

public:
	ListWdbeQSilRef1NSignal();
	ListWdbeQSilRef1NSignal(const ListWdbeQSilRef1NSignal& src);
	~ListWdbeQSilRef1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilRef1NSignal* rec);

	ListWdbeQSilRef1NSignal& operator=(const ListWdbeQSilRef1NSignal& src);

public:
	std::vector<WdbeQSilRef1NSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilRef1NSignal: C++ wrapper for table TblWdbeQSilRef1NSignal
	*/
class TblWdbeQSilRef1NSignal {

public:
	TblWdbeQSilRef1NSignal();
	virtual ~TblWdbeQSilRef1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilRef1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilRef1NSignal& rst, WdbeQSilRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQSilRef1NSignal& rst);
	virtual void updateRec(WdbeQSilRef1NSignal* rec);
	virtual void updateRst(ListWdbeQSilRef1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilRef1NSignal: C++ wrapper for table TblWdbeQSilRef1NSignal (MySQL database)
	*/
class MyTblWdbeQSilRef1NSignal : public TblWdbeQSilRef1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQSilRef1NSignal();
	~MyTblWdbeQSilRef1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NSignal* rec);
	void insertRst(ListWdbeQSilRef1NSignal& rst);
	void updateRec(WdbeQSilRef1NSignal* rec);
	void updateRst(ListWdbeQSilRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilRef1NSignal: C++ wrapper for table TblWdbeQSilRef1NSignal (PgSQL database)
	*/
class PgTblWdbeQSilRef1NSignal : public TblWdbeQSilRef1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQSilRef1NSignal();
	~PgTblWdbeQSilRef1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilRef1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilRef1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NSignal* rec);
	void insertRst(ListWdbeQSilRef1NSignal& rst);
	void updateRec(WdbeQSilRef1NSignal* rec);
	void updateRst(ListWdbeQSilRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NSignal& rst);
};
#endif

#endif
