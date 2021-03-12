/**
	* \file WdbeQFilList.h
	* Dbs and XML wrapper for table TblWdbeQFilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFILLIST_H
#define WDBEQFILLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQFilList: record of TblWdbeQFilList
	*/
class WdbeQFilList {

public:
	WdbeQFilList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Filename;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::usmallint Size;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQFilList: recordset of TblWdbeQFilList
	*/
class ListWdbeQFilList {

public:
	ListWdbeQFilList();
	ListWdbeQFilList(const ListWdbeQFilList& src);
	~ListWdbeQFilList();

	void clear();
	unsigned int size() const;
	void append(WdbeQFilList* rec);

	ListWdbeQFilList& operator=(const ListWdbeQFilList& src);

public:
	std::vector<WdbeQFilList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQFilList: C++ wrapper for table TblWdbeQFilList
	*/
class TblWdbeQFilList {

public:
	TblWdbeQFilList();
	virtual ~TblWdbeQFilList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQFilList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFilList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQFilList* rec);
	Sbecore::ubigint insertNewRec(WdbeQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQFilList& rst, WdbeQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	virtual void insertRst(ListWdbeQFilList& rst);
	virtual void updateRec(WdbeQFilList* rec);
	virtual void updateRst(ListWdbeQFilList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQFilList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFilList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQFilList: C++ wrapper for table TblWdbeQFilList (MySQL database)
	*/
class MyTblWdbeQFilList : public TblWdbeQFilList, public Sbecore::MyTable {

public:
	MyTblWdbeQFilList();
	~MyTblWdbeQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFilList& rst);

	Sbecore::ubigint insertRec(WdbeQFilList* rec);
	void insertRst(ListWdbeQFilList& rst);
	void updateRec(WdbeQFilList* rec);
	void updateRst(ListWdbeQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFilList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQFilList: C++ wrapper for table TblWdbeQFilList (PgSQL database)
	*/
class PgTblWdbeQFilList : public TblWdbeQFilList, public Sbecore::PgTable {

public:
	PgTblWdbeQFilList();
	~PgTblWdbeQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQFilList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQFilList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQFilList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQFilList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFilList& rst);

	Sbecore::ubigint insertRec(WdbeQFilList* rec);
	void insertRst(ListWdbeQFilList& rst);
	void updateRec(WdbeQFilList* rec);
	void updateRst(ListWdbeQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFilList& rst);
};
#endif

#endif
