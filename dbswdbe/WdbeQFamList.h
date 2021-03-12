/**
	* \file WdbeQFamList.h
	* Dbs and XML wrapper for table TblWdbeQFamList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFAMLIST_H
#define WDBEQFAMLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQFamList: record of TblWdbeQFamList
	*/
class WdbeQFamList {

public:
	WdbeQFamList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string srefKVendor = "", const std::string titSrefKVendor = "", const std::string Title = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string srefKVendor;
	std::string titSrefKVendor;
	std::string Title;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQFamList: recordset of TblWdbeQFamList
	*/
class ListWdbeQFamList {

public:
	ListWdbeQFamList();
	ListWdbeQFamList(const ListWdbeQFamList& src);
	~ListWdbeQFamList();

	void clear();
	unsigned int size() const;
	void append(WdbeQFamList* rec);

	ListWdbeQFamList& operator=(const ListWdbeQFamList& src);

public:
	std::vector<WdbeQFamList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQFamList: C++ wrapper for table TblWdbeQFamList
	*/
class TblWdbeQFamList {

public:
	TblWdbeQFamList();
	virtual ~TblWdbeQFamList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQFamList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFamList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQFamList* rec);
	Sbecore::ubigint insertNewRec(WdbeQFamList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string srefKVendor = "", const std::string titSrefKVendor = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQFamList& rst, WdbeQFamList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string srefKVendor = "", const std::string titSrefKVendor = "", const std::string Title = "");
	virtual void insertRst(ListWdbeQFamList& rst);
	virtual void updateRec(WdbeQFamList* rec);
	virtual void updateRst(ListWdbeQFamList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQFamList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFamList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQFamList: C++ wrapper for table TblWdbeQFamList (MySQL database)
	*/
class MyTblWdbeQFamList : public TblWdbeQFamList, public Sbecore::MyTable {

public:
	MyTblWdbeQFamList();
	~MyTblWdbeQFamList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFamList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFamList& rst);

	Sbecore::ubigint insertRec(WdbeQFamList* rec);
	void insertRst(ListWdbeQFamList& rst);
	void updateRec(WdbeQFamList* rec);
	void updateRst(ListWdbeQFamList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFamList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFamList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQFamList: C++ wrapper for table TblWdbeQFamList (PgSQL database)
	*/
class PgTblWdbeQFamList : public TblWdbeQFamList, public Sbecore::PgTable {

public:
	PgTblWdbeQFamList();
	~PgTblWdbeQFamList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQFamList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQFamList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQFamList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQFamList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFamList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFamList& rst);

	Sbecore::ubigint insertRec(WdbeQFamList* rec);
	void insertRst(ListWdbeQFamList& rst);
	void updateRec(WdbeQFamList* rec);
	void updateRst(ListWdbeQFamList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFamList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFamList& rst);
};
#endif

#endif
