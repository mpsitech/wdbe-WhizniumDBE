/**
	* \file WdbeQGenList.h
	* Dbs and XML wrapper for table TblWdbeQGenList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQGENLIST_H
#define WDBEQGENLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQGenList: record of TblWdbeQGenList
	*/
class WdbeQGenList {

public:
	WdbeQGenList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint mdlRefWdbeMModule;
	std::string stubMdlRefWdbeMModule;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQGenList: recordset of TblWdbeQGenList
	*/
class ListWdbeQGenList {

public:
	ListWdbeQGenList();
	ListWdbeQGenList(const ListWdbeQGenList& src);
	~ListWdbeQGenList();

	void clear();
	unsigned int size() const;
	void append(WdbeQGenList* rec);

	ListWdbeQGenList& operator=(const ListWdbeQGenList& src);

public:
	std::vector<WdbeQGenList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQGenList: C++ wrapper for table TblWdbeQGenList
	*/
class TblWdbeQGenList {

public:
	TblWdbeQGenList();
	virtual ~TblWdbeQGenList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQGenList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQGenList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQGenList* rec);
	Sbecore::ubigint insertNewRec(WdbeQGenList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQGenList& rst, WdbeQGenList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	virtual void insertRst(ListWdbeQGenList& rst);
	virtual void updateRec(WdbeQGenList* rec);
	virtual void updateRst(ListWdbeQGenList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQGenList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQGenList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQGenList: C++ wrapper for table TblWdbeQGenList (MySQL database)
	*/
class MyTblWdbeQGenList : public TblWdbeQGenList, public Sbecore::MyTable {

public:
	MyTblWdbeQGenList();
	~MyTblWdbeQGenList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQGenList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQGenList& rst);

	Sbecore::ubigint insertRec(WdbeQGenList* rec);
	void insertRst(ListWdbeQGenList& rst);
	void updateRec(WdbeQGenList* rec);
	void updateRst(ListWdbeQGenList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQGenList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQGenList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQGenList: C++ wrapper for table TblWdbeQGenList (PgSQL database)
	*/
class PgTblWdbeQGenList : public TblWdbeQGenList, public Sbecore::PgTable {

public:
	PgTblWdbeQGenList();
	~PgTblWdbeQGenList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQGenList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQGenList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQGenList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQGenList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQGenList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQGenList& rst);

	Sbecore::ubigint insertRec(WdbeQGenList* rec);
	void insertRst(ListWdbeQGenList& rst);
	void updateRec(WdbeQGenList* rec);
	void updateRst(ListWdbeQGenList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQGenList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQGenList& rst);
};
#endif

#endif

