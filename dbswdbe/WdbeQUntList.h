/**
	* \file WdbeQUntList.h
	* Dbs and XML wrapper for table TblWdbeQUntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTLIST_H
#define WDBEQUNTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntList: record of TblWdbeQUntList
	*/
class WdbeQUntList {

public:
	WdbeQUntList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string Fullsref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::ubigint refWdbeMSystem;
	std::string stubRefWdbeMSystem;
	Sbecore::ubigint refWdbeMModule;
	std::string stubRefWdbeMModule;
	std::string srefKPackage;
	std::string titSrefKPackage;
	bool Easy;
	std::string yesnoEasy;
	std::string srefKToolch;
	std::string titSrefKToolch;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntList: recordset of TblWdbeQUntList
	*/
class ListWdbeQUntList {

public:
	ListWdbeQUntList();
	ListWdbeQUntList(const ListWdbeQUntList& src);
	~ListWdbeQUntList();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntList* rec);

	ListWdbeQUntList& operator=(const ListWdbeQUntList& src);

public:
	std::vector<WdbeQUntList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntList: C++ wrapper for table TblWdbeQUntList
	*/
class TblWdbeQUntList {

public:
	TblWdbeQUntList();
	virtual ~TblWdbeQUntList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntList* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntList& rst, WdbeQUntList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");
	virtual void insertRst(ListWdbeQUntList& rst);
	virtual void updateRec(WdbeQUntList* rec);
	virtual void updateRst(ListWdbeQUntList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntList: C++ wrapper for table TblWdbeQUntList (MySQL database)
	*/
class MyTblWdbeQUntList : public TblWdbeQUntList, public Sbecore::MyTable {

public:
	MyTblWdbeQUntList();
	~MyTblWdbeQUntList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntList& rst);

	Sbecore::ubigint insertRec(WdbeQUntList* rec);
	void insertRst(ListWdbeQUntList& rst);
	void updateRec(WdbeQUntList* rec);
	void updateRst(ListWdbeQUntList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntList: C++ wrapper for table TblWdbeQUntList (PgSQL database)
	*/
class PgTblWdbeQUntList : public TblWdbeQUntList, public Sbecore::PgTable {

public:
	PgTblWdbeQUntList();
	~PgTblWdbeQUntList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntList& rst);

	Sbecore::ubigint insertRec(WdbeQUntList* rec);
	void insertRst(ListWdbeQUntList& rst);
	void updateRec(WdbeQUntList* rec);
	void updateRst(ListWdbeQUntList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntList& rst);
};
#endif

#endif
