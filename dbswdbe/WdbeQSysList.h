/**
	* \file WdbeQSysList.h
	* Dbs and XML wrapper for table TblWdbeQSysList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSYSLIST_H
#define WDBEQSYSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSysList: record of TblWdbeQSysList
	*/
class WdbeQSysList {

public:
	WdbeQSysList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMVersion;
	std::string stubRefWdbeMVersion;
	Sbecore::ubigint refWdbeMUnit;
	std::string stubRefWdbeMUnit;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSysList: recordset of TblWdbeQSysList
	*/
class ListWdbeQSysList {

public:
	ListWdbeQSysList();
	ListWdbeQSysList(const ListWdbeQSysList& src);
	~ListWdbeQSysList();

	void clear();
	unsigned int size() const;
	void append(WdbeQSysList* rec);

	ListWdbeQSysList& operator=(const ListWdbeQSysList& src);

public:
	std::vector<WdbeQSysList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSysList: C++ wrapper for table TblWdbeQSysList
	*/
class TblWdbeQSysList {

public:
	TblWdbeQSysList();
	virtual ~TblWdbeQSysList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSysList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSysList* rec);
	Sbecore::ubigint insertNewRec(WdbeQSysList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSysList& rst, WdbeQSysList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	virtual void insertRst(ListWdbeQSysList& rst);
	virtual void updateRec(WdbeQSysList* rec);
	virtual void updateRst(ListWdbeQSysList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSysList: C++ wrapper for table TblWdbeQSysList (MySQL database)
	*/
class MyTblWdbeQSysList : public TblWdbeQSysList, public Sbecore::MyTable {

public:
	MyTblWdbeQSysList();
	~MyTblWdbeQSysList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysList& rst);

	Sbecore::ubigint insertRec(WdbeQSysList* rec);
	void insertRst(ListWdbeQSysList& rst);
	void updateRec(WdbeQSysList* rec);
	void updateRst(ListWdbeQSysList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSysList: C++ wrapper for table TblWdbeQSysList (PgSQL database)
	*/
class PgTblWdbeQSysList : public TblWdbeQSysList, public Sbecore::PgTable {

public:
	PgTblWdbeQSysList();
	~PgTblWdbeQSysList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSysList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSysList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSysList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSysList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysList& rst);

	Sbecore::ubigint insertRec(WdbeQSysList* rec);
	void insertRst(ListWdbeQSysList& rst);
	void updateRec(WdbeQSysList* rec);
	void updateRst(ListWdbeQSysList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysList& rst);
};
#endif

#endif
