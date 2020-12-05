/**
	* \file WdbeQMchList.h
	* Dbs and XML wrapper for table TblWdbeQMchList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCHLIST_H
#define WDBEQMCHLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMchList: record of TblWdbeQMchList
	*/
class WdbeQMchList {

public:
	WdbeQMchList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string stubSupRefWdbeMMachine = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint supRefWdbeMMachine;
	std::string stubSupRefWdbeMMachine;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQMchList: recordset of TblWdbeQMchList
	*/
class ListWdbeQMchList {

public:
	ListWdbeQMchList();
	ListWdbeQMchList(const ListWdbeQMchList& src);
	~ListWdbeQMchList();

	void clear();
	unsigned int size() const;
	void append(WdbeQMchList* rec);

	ListWdbeQMchList& operator=(const ListWdbeQMchList& src);

public:
	std::vector<WdbeQMchList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMchList: C++ wrapper for table TblWdbeQMchList
	*/
class TblWdbeQMchList {

public:
	TblWdbeQMchList();
	virtual ~TblWdbeQMchList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMchList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMchList* rec);
	Sbecore::ubigint insertNewRec(WdbeQMchList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string stubSupRefWdbeMMachine = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMchList& rst, WdbeQMchList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint supRefWdbeMMachine = 0, const std::string stubSupRefWdbeMMachine = "");
	virtual void insertRst(ListWdbeQMchList& rst);
	virtual void updateRec(WdbeQMchList* rec);
	virtual void updateRst(ListWdbeQMchList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMchList: C++ wrapper for table TblWdbeQMchList (MySQL database)
	*/
class MyTblWdbeQMchList : public TblWdbeQMchList, public Sbecore::MyTable {

public:
	MyTblWdbeQMchList();
	~MyTblWdbeQMchList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchList& rst);

	Sbecore::ubigint insertRec(WdbeQMchList* rec);
	void insertRst(ListWdbeQMchList& rst);
	void updateRec(WdbeQMchList* rec);
	void updateRst(ListWdbeQMchList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMchList: C++ wrapper for table TblWdbeQMchList (PgSQL database)
	*/
class PgTblWdbeQMchList : public TblWdbeQMchList, public Sbecore::PgTable {

public:
	PgTblWdbeQMchList();
	~PgTblWdbeQMchList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMchList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMchList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMchList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMchList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchList& rst);

	Sbecore::ubigint insertRec(WdbeQMchList* rec);
	void insertRst(ListWdbeQMchList& rst);
	void updateRec(WdbeQMchList* rec);
	void updateRst(ListWdbeQMchList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchList& rst);
};
#endif

#endif

