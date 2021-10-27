/**
	* \file WdbeQIntList.h
	* Dbs and XML wrapper for table TblWdbeQIntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQINTLIST_H
#define WDBEQINTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQIntList: record of TblWdbeQIntList
	*/
class WdbeQIntList {

public:
	WdbeQIntList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMUnit;
	std::string stubRefWdbeMUnit;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQIntList: recordset of TblWdbeQIntList
	*/
class ListWdbeQIntList {

public:
	ListWdbeQIntList();
	ListWdbeQIntList(const ListWdbeQIntList& src);
	~ListWdbeQIntList();

	void clear();
	unsigned int size() const;
	void append(WdbeQIntList* rec);

	ListWdbeQIntList& operator=(const ListWdbeQIntList& src);

public:
	std::vector<WdbeQIntList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQIntList: C++ wrapper for table TblWdbeQIntList
	*/
class TblWdbeQIntList {

public:
	TblWdbeQIntList();
	virtual ~TblWdbeQIntList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQIntList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQIntList* rec);
	Sbecore::ubigint insertNewRec(WdbeQIntList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQIntList& rst, WdbeQIntList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	virtual void insertRst(ListWdbeQIntList& rst);
	virtual void updateRec(WdbeQIntList* rec);
	virtual void updateRst(ListWdbeQIntList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQIntList: C++ wrapper for table TblWdbeQIntList (MySQL database)
	*/
class MyTblWdbeQIntList : public TblWdbeQIntList, public Sbecore::MyTable {

public:
	MyTblWdbeQIntList();
	~MyTblWdbeQIntList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQIntList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntList& rst);

	Sbecore::ubigint insertRec(WdbeQIntList* rec);
	void insertRst(ListWdbeQIntList& rst);
	void updateRec(WdbeQIntList* rec);
	void updateRst(ListWdbeQIntList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQIntList: C++ wrapper for table TblWdbeQIntList (PgSQL database)
	*/
class PgTblWdbeQIntList : public TblWdbeQIntList, public Sbecore::PgTable {

public:
	PgTblWdbeQIntList();
	~PgTblWdbeQIntList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQIntList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQIntList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQIntList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQIntList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQIntList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntList& rst);

	Sbecore::ubigint insertRec(WdbeQIntList* rec);
	void insertRst(ListWdbeQIntList& rst);
	void updateRec(WdbeQIntList* rec);
	void updateRst(ListWdbeQIntList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntList& rst);
};
#endif

#endif
