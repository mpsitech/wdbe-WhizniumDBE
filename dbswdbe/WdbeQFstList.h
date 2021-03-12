/**
	* \file WdbeQFstList.h
	* Dbs and XML wrapper for table TblWdbeQFstList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFSTLIST_H
#define WDBEQFSTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQFstList: record of TblWdbeQFstList
	*/
class WdbeQFstList {

public:
	WdbeQFstList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint fsmRefWdbeMFsm = 0, const std::string stubFsmRefWdbeMFsm = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint fsmRefWdbeMFsm;
	std::string stubFsmRefWdbeMFsm;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQFstList: recordset of TblWdbeQFstList
	*/
class ListWdbeQFstList {

public:
	ListWdbeQFstList();
	ListWdbeQFstList(const ListWdbeQFstList& src);
	~ListWdbeQFstList();

	void clear();
	unsigned int size() const;
	void append(WdbeQFstList* rec);

	ListWdbeQFstList& operator=(const ListWdbeQFstList& src);

public:
	std::vector<WdbeQFstList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQFstList: C++ wrapper for table TblWdbeQFstList
	*/
class TblWdbeQFstList {

public:
	TblWdbeQFstList();
	virtual ~TblWdbeQFstList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQFstList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQFstList* rec);
	Sbecore::ubigint insertNewRec(WdbeQFstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint fsmRefWdbeMFsm = 0, const std::string stubFsmRefWdbeMFsm = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQFstList& rst, WdbeQFstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint fsmRefWdbeMFsm = 0, const std::string stubFsmRefWdbeMFsm = "");
	virtual void insertRst(ListWdbeQFstList& rst);
	virtual void updateRec(WdbeQFstList* rec);
	virtual void updateRst(ListWdbeQFstList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQFstList: C++ wrapper for table TblWdbeQFstList (MySQL database)
	*/
class MyTblWdbeQFstList : public TblWdbeQFstList, public Sbecore::MyTable {

public:
	MyTblWdbeQFstList();
	~MyTblWdbeQFstList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstList& rst);

	Sbecore::ubigint insertRec(WdbeQFstList* rec);
	void insertRst(ListWdbeQFstList& rst);
	void updateRec(WdbeQFstList* rec);
	void updateRst(ListWdbeQFstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQFstList: C++ wrapper for table TblWdbeQFstList (PgSQL database)
	*/
class PgTblWdbeQFstList : public TblWdbeQFstList, public Sbecore::PgTable {

public:
	PgTblWdbeQFstList();
	~PgTblWdbeQFstList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQFstList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQFstList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQFstList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQFstList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstList& rst);

	Sbecore::ubigint insertRec(WdbeQFstList* rec);
	void insertRst(ListWdbeQFstList& rst);
	void updateRec(WdbeQFstList* rec);
	void updateRst(ListWdbeQFstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstList& rst);
};
#endif

#endif
