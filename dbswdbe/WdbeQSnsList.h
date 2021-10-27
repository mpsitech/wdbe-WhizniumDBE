/**
	* \file WdbeQSnsList.h
	* Dbs and XML wrapper for table TblWdbeQSnsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSNSLIST_H
#define WDBEQSNSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSnsList: record of TblWdbeQSnsList
	*/
class WdbeQSnsList {

public:
	WdbeQSnsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint srcIxVTbl = 0, const std::string srefSrcIxVTbl = "", const std::string titSrcIxVTbl = "", const Sbecore::ubigint srcUref = 0, const std::string stubSrcUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::uint srcIxVTbl;
	std::string srefSrcIxVTbl;
	std::string titSrcIxVTbl;
	Sbecore::ubigint srcUref;
	std::string stubSrcUref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSnsList: recordset of TblWdbeQSnsList
	*/
class ListWdbeQSnsList {

public:
	ListWdbeQSnsList();
	ListWdbeQSnsList(const ListWdbeQSnsList& src);
	~ListWdbeQSnsList();

	void clear();
	unsigned int size() const;
	void append(WdbeQSnsList* rec);

	ListWdbeQSnsList& operator=(const ListWdbeQSnsList& src);

public:
	std::vector<WdbeQSnsList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSnsList: C++ wrapper for table TblWdbeQSnsList
	*/
class TblWdbeQSnsList {

public:
	TblWdbeQSnsList();
	virtual ~TblWdbeQSnsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSnsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSnsList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSnsList* rec);
	Sbecore::ubigint insertNewRec(WdbeQSnsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint srcIxVTbl = 0, const std::string srefSrcIxVTbl = "", const std::string titSrcIxVTbl = "", const Sbecore::ubigint srcUref = 0, const std::string stubSrcUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSnsList& rst, WdbeQSnsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint srcIxVTbl = 0, const std::string srefSrcIxVTbl = "", const std::string titSrcIxVTbl = "", const Sbecore::ubigint srcUref = 0, const std::string stubSrcUref = "");
	virtual void insertRst(ListWdbeQSnsList& rst);
	virtual void updateRec(WdbeQSnsList* rec);
	virtual void updateRst(ListWdbeQSnsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSnsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSnsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSnsList: C++ wrapper for table TblWdbeQSnsList (MySQL database)
	*/
class MyTblWdbeQSnsList : public TblWdbeQSnsList, public Sbecore::MyTable {

public:
	MyTblWdbeQSnsList();
	~MyTblWdbeQSnsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSnsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSnsList& rst);

	Sbecore::ubigint insertRec(WdbeQSnsList* rec);
	void insertRst(ListWdbeQSnsList& rst);
	void updateRec(WdbeQSnsList* rec);
	void updateRst(ListWdbeQSnsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSnsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSnsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSnsList: C++ wrapper for table TblWdbeQSnsList (PgSQL database)
	*/
class PgTblWdbeQSnsList : public TblWdbeQSnsList, public Sbecore::PgTable {

public:
	PgTblWdbeQSnsList();
	~PgTblWdbeQSnsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSnsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSnsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSnsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSnsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSnsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSnsList& rst);

	Sbecore::ubigint insertRec(WdbeQSnsList* rec);
	void insertRst(ListWdbeQSnsList& rst);
	void updateRec(WdbeQSnsList* rec);
	void updateRst(ListWdbeQSnsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSnsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSnsList& rst);
};
#endif

#endif
