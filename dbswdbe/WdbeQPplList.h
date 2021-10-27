/**
	* \file WdbeQPplList.h
	* Dbs and XML wrapper for table TblWdbeQPplList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPLLIST_H
#define WDBEQPPLLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPplList: record of TblWdbeQPplList
	*/
class WdbeQPplList {

public:
	WdbeQPplList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string stubHsmRefWdbeMModule = "", const Sbecore::usmallint Depth = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint hsmRefWdbeMModule;
	std::string stubHsmRefWdbeMModule;
	Sbecore::usmallint Depth;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPplList: recordset of TblWdbeQPplList
	*/
class ListWdbeQPplList {

public:
	ListWdbeQPplList();
	ListWdbeQPplList(const ListWdbeQPplList& src);
	~ListWdbeQPplList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPplList* rec);

	ListWdbeQPplList& operator=(const ListWdbeQPplList& src);

public:
	std::vector<WdbeQPplList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPplList: C++ wrapper for table TblWdbeQPplList
	*/
class TblWdbeQPplList {

public:
	TblWdbeQPplList();
	virtual ~TblWdbeQPplList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPplList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPplList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPplList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string stubHsmRefWdbeMModule = "", const Sbecore::usmallint Depth = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPplList& rst, WdbeQPplList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint hsmRefWdbeMModule = 0, const std::string stubHsmRefWdbeMModule = "", const Sbecore::usmallint Depth = 0);
	virtual void insertRst(ListWdbeQPplList& rst);
	virtual void updateRec(WdbeQPplList* rec);
	virtual void updateRst(ListWdbeQPplList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPplList: C++ wrapper for table TblWdbeQPplList (MySQL database)
	*/
class MyTblWdbeQPplList : public TblWdbeQPplList, public Sbecore::MyTable {

public:
	MyTblWdbeQPplList();
	~MyTblWdbeQPplList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPplList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplList& rst);

	Sbecore::ubigint insertRec(WdbeQPplList* rec);
	void insertRst(ListWdbeQPplList& rst);
	void updateRec(WdbeQPplList* rec);
	void updateRst(ListWdbeQPplList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPplList: C++ wrapper for table TblWdbeQPplList (PgSQL database)
	*/
class PgTblWdbeQPplList : public TblWdbeQPplList, public Sbecore::PgTable {

public:
	PgTblWdbeQPplList();
	~PgTblWdbeQPplList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPplList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPplList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPplList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPplList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPplList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplList& rst);

	Sbecore::ubigint insertRec(WdbeQPplList* rec);
	void insertRst(ListWdbeQPplList& rst);
	void updateRec(WdbeQPplList* rec);
	void updateRst(ListWdbeQPplList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplList& rst);
};
#endif

#endif
