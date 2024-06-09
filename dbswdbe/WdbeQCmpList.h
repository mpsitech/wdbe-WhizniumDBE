/**
	* \file WdbeQCmpList.h
	* Dbs and XML wrapper for table TblWdbeQCmpList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMPLIST_H
#define WDBEQCMPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmpList: record of TblWdbeQCmpList
	*/
class WdbeQCmpList {

public:
	WdbeQCmpList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWdbeMVersion;
	std::string stubRefWdbeMVersion;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmpList: recordset of TblWdbeQCmpList
	*/
class ListWdbeQCmpList {

public:
	ListWdbeQCmpList();
	ListWdbeQCmpList(const ListWdbeQCmpList& src);
	~ListWdbeQCmpList();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmpList* rec);

	ListWdbeQCmpList& operator=(const ListWdbeQCmpList& src);

public:
	std::vector<WdbeQCmpList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmpList: C++ wrapper for table TblWdbeQCmpList
	*/
class TblWdbeQCmpList {

public:
	TblWdbeQCmpList();
	virtual ~TblWdbeQCmpList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmpList* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmpList& rst, WdbeQCmpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "");
	virtual void insertRst(ListWdbeQCmpList& rst);
	virtual void updateRec(WdbeQCmpList* rec);
	virtual void updateRst(ListWdbeQCmpList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmpList: C++ wrapper for table TblWdbeQCmpList (MySQL database)
	*/
class MyTblWdbeQCmpList : public TblWdbeQCmpList, public Sbecore::MyTable {

public:
	MyTblWdbeQCmpList();
	~MyTblWdbeQCmpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpList& rst);

	Sbecore::ubigint insertRec(WdbeQCmpList* rec);
	void insertRst(ListWdbeQCmpList& rst);
	void updateRec(WdbeQCmpList* rec);
	void updateRst(ListWdbeQCmpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmpList: C++ wrapper for table TblWdbeQCmpList (PgSQL database)
	*/
class PgTblWdbeQCmpList : public TblWdbeQCmpList, public Sbecore::PgTable {

public:
	PgTblWdbeQCmpList();
	~PgTblWdbeQCmpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmpList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmpList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmpList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmpList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpList& rst);

	Sbecore::ubigint insertRec(WdbeQCmpList* rec);
	void insertRst(ListWdbeQCmpList& rst);
	void updateRec(WdbeQCmpList* rec);
	void updateRst(ListWdbeQCmpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpList& rst);
};
#endif

#endif
