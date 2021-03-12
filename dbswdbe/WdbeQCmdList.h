/**
	* \file WdbeQCmdList.h
	* Dbs and XML wrapper for table TblWdbeQCmdList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCMDLIST_H
#define WDBEQCMDLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmdList: record of TblWdbeQCmdList
	*/
class WdbeQCmdList {

public:
	WdbeQCmdList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixVRettype = 0, const std::string srefIxVRettype = "", const std::string titIxVRettype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Fullsref;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::uint ixVRettype;
	std::string srefIxVRettype;
	std::string titIxVRettype;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmdList: recordset of TblWdbeQCmdList
	*/
class ListWdbeQCmdList {

public:
	ListWdbeQCmdList();
	ListWdbeQCmdList(const ListWdbeQCmdList& src);
	~ListWdbeQCmdList();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmdList* rec);

	ListWdbeQCmdList& operator=(const ListWdbeQCmdList& src);

public:
	std::vector<WdbeQCmdList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmdList: C++ wrapper for table TblWdbeQCmdList
	*/
class TblWdbeQCmdList {

public:
	TblWdbeQCmdList();
	virtual ~TblWdbeQCmdList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmdList* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixVRettype = 0, const std::string srefIxVRettype = "", const std::string titIxVRettype = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmdList& rst, WdbeQCmdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixVRettype = 0, const std::string srefIxVRettype = "", const std::string titIxVRettype = "");
	virtual void insertRst(ListWdbeQCmdList& rst);
	virtual void updateRec(WdbeQCmdList* rec);
	virtual void updateRst(ListWdbeQCmdList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmdList: C++ wrapper for table TblWdbeQCmdList (MySQL database)
	*/
class MyTblWdbeQCmdList : public TblWdbeQCmdList, public Sbecore::MyTable {

public:
	MyTblWdbeQCmdList();
	~MyTblWdbeQCmdList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdList& rst);

	Sbecore::ubigint insertRec(WdbeQCmdList* rec);
	void insertRst(ListWdbeQCmdList& rst);
	void updateRec(WdbeQCmdList* rec);
	void updateRst(ListWdbeQCmdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmdList: C++ wrapper for table TblWdbeQCmdList (PgSQL database)
	*/
class PgTblWdbeQCmdList : public TblWdbeQCmdList, public Sbecore::PgTable {

public:
	PgTblWdbeQCmdList();
	~PgTblWdbeQCmdList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmdList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmdList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmdList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmdList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdList& rst);

	Sbecore::ubigint insertRec(WdbeQCmdList* rec);
	void insertRst(ListWdbeQCmdList& rst);
	void updateRec(WdbeQCmdList* rec);
	void updateRst(ListWdbeQCmdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdList& rst);
};
#endif

#endif
