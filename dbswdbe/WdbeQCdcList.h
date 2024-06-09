/**
	* \file WdbeQCdcList.h
	* Dbs and XML wrapper for table TblWdbeQCdcList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCDCLIST_H
#define WDBEQCDCLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCdcList: record of TblWdbeQCdcList
	*/
class WdbeQCdcList {

public:
	WdbeQCdcList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeMModule;
	std::string stubRefWdbeMModule;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCdcList: recordset of TblWdbeQCdcList
	*/
class ListWdbeQCdcList {

public:
	ListWdbeQCdcList();
	ListWdbeQCdcList(const ListWdbeQCdcList& src);
	~ListWdbeQCdcList();

	void clear();
	unsigned int size() const;
	void append(WdbeQCdcList* rec);

	ListWdbeQCdcList& operator=(const ListWdbeQCdcList& src);

public:
	std::vector<WdbeQCdcList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCdcList: C++ wrapper for table TblWdbeQCdcList
	*/
class TblWdbeQCdcList {

public:
	TblWdbeQCdcList();
	virtual ~TblWdbeQCdcList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCdcList* rec);
	Sbecore::ubigint insertNewRec(WdbeQCdcList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCdcList& rst, WdbeQCdcList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "");
	virtual void insertRst(ListWdbeQCdcList& rst);
	virtual void updateRec(WdbeQCdcList* rec);
	virtual void updateRst(ListWdbeQCdcList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCdcList: C++ wrapper for table TblWdbeQCdcList (MySQL database)
	*/
class MyTblWdbeQCdcList : public TblWdbeQCdcList, public Sbecore::MyTable {

public:
	MyTblWdbeQCdcList();
	~MyTblWdbeQCdcList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcList& rst);

	Sbecore::ubigint insertRec(WdbeQCdcList* rec);
	void insertRst(ListWdbeQCdcList& rst);
	void updateRec(WdbeQCdcList* rec);
	void updateRst(ListWdbeQCdcList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCdcList: C++ wrapper for table TblWdbeQCdcList (PgSQL database)
	*/
class PgTblWdbeQCdcList : public TblWdbeQCdcList, public Sbecore::PgTable {

public:
	PgTblWdbeQCdcList();
	~PgTblWdbeQCdcList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCdcList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCdcList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCdcList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCdcList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcList& rst);

	Sbecore::ubigint insertRec(WdbeQCdcList* rec);
	void insertRst(ListWdbeQCdcList& rst);
	void updateRec(WdbeQCdcList* rec);
	void updateRst(ListWdbeQCdcList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcList& rst);
};
#endif

#endif
