/**
	* \file WdbeQPinList.h
	* Dbs and XML wrapper for table TblWdbeQPinList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPINLIST_H
#define WDBEQPINLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPinList: record of TblWdbeQPinList
	*/
class WdbeQPinList {

public:
	WdbeQPinList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMBank = 0, const std::string stubRefWdbeMBank = "", const std::string Location = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMBank;
	std::string stubRefWdbeMBank;
	std::string Location;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPinList: recordset of TblWdbeQPinList
	*/
class ListWdbeQPinList {

public:
	ListWdbeQPinList();
	ListWdbeQPinList(const ListWdbeQPinList& src);
	~ListWdbeQPinList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPinList* rec);

	ListWdbeQPinList& operator=(const ListWdbeQPinList& src);

public:
	std::vector<WdbeQPinList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPinList: C++ wrapper for table TblWdbeQPinList
	*/
class TblWdbeQPinList {

public:
	TblWdbeQPinList();
	virtual ~TblWdbeQPinList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPinList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPinList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPinList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMBank = 0, const std::string stubRefWdbeMBank = "", const std::string Location = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPinList& rst, WdbeQPinList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMBank = 0, const std::string stubRefWdbeMBank = "", const std::string Location = "");
	virtual void insertRst(ListWdbeQPinList& rst);
	virtual void updateRec(WdbeQPinList* rec);
	virtual void updateRst(ListWdbeQPinList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPinList: C++ wrapper for table TblWdbeQPinList (MySQL database)
	*/
class MyTblWdbeQPinList : public TblWdbeQPinList, public Sbecore::MyTable {

public:
	MyTblWdbeQPinList();
	~MyTblWdbeQPinList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPinList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinList& rst);

	Sbecore::ubigint insertRec(WdbeQPinList* rec);
	void insertRst(ListWdbeQPinList& rst);
	void updateRec(WdbeQPinList* rec);
	void updateRst(ListWdbeQPinList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPinList: C++ wrapper for table TblWdbeQPinList (PgSQL database)
	*/
class PgTblWdbeQPinList : public TblWdbeQPinList, public Sbecore::PgTable {

public:
	PgTblWdbeQPinList();
	~PgTblWdbeQPinList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPinList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPinList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPinList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPinList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPinList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPinList& rst);

	Sbecore::ubigint insertRec(WdbeQPinList* rec);
	void insertRst(ListWdbeQPinList& rst);
	void updateRec(WdbeQPinList* rec);
	void updateRst(ListWdbeQPinList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPinList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPinList& rst);
};
#endif

#endif

