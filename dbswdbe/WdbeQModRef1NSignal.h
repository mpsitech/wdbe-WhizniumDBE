/**
	* \file WdbeQModRef1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQModRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NSIGNAL_H
#define WDBEQMODREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModRef1NSignal: record of TblWdbeQModRef1NSignal
	*/
class WdbeQModRef1NSignal {

public:
	WdbeQModRef1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQModRef1NSignal: recordset of TblWdbeQModRef1NSignal
	*/
class ListWdbeQModRef1NSignal {

public:
	ListWdbeQModRef1NSignal();
	ListWdbeQModRef1NSignal(const ListWdbeQModRef1NSignal& src);
	~ListWdbeQModRef1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQModRef1NSignal* rec);

	ListWdbeQModRef1NSignal& operator=(const ListWdbeQModRef1NSignal& src);

public:
	std::vector<WdbeQModRef1NSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModRef1NSignal: C++ wrapper for table TblWdbeQModRef1NSignal
	*/
class TblWdbeQModRef1NSignal {

public:
	TblWdbeQModRef1NSignal();
	virtual ~TblWdbeQModRef1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModRef1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQModRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModRef1NSignal& rst, WdbeQModRef1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQModRef1NSignal& rst);
	virtual void updateRec(WdbeQModRef1NSignal* rec);
	virtual void updateRst(ListWdbeQModRef1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModRef1NSignal: C++ wrapper for table TblWdbeQModRef1NSignal (MySQL database)
	*/
class MyTblWdbeQModRef1NSignal : public TblWdbeQModRef1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQModRef1NSignal();
	~MyTblWdbeQModRef1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NSignal* rec);
	void insertRst(ListWdbeQModRef1NSignal& rst);
	void updateRec(WdbeQModRef1NSignal* rec);
	void updateRst(ListWdbeQModRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModRef1NSignal: C++ wrapper for table TblWdbeQModRef1NSignal (PgSQL database)
	*/
class PgTblWdbeQModRef1NSignal : public TblWdbeQModRef1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQModRef1NSignal();
	~PgTblWdbeQModRef1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModRef1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModRef1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NSignal* rec);
	void insertRst(ListWdbeQModRef1NSignal& rst);
	void updateRec(WdbeQModRef1NSignal* rec);
	void updateRst(ListWdbeQModRef1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSignal& rst);
};
#endif

#endif
