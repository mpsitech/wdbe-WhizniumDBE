/**
	* \file WdbeQSilList.h
	* Dbs and XML wrapper for table TblWdbeQSilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILLIST_H
#define WDBEQSILLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilList: record of TblWdbeQSilList
	*/
class WdbeQSilList {

public:
	WdbeQSilList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSilList: recordset of TblWdbeQSilList
	*/
class ListWdbeQSilList {

public:
	ListWdbeQSilList();
	ListWdbeQSilList(const ListWdbeQSilList& src);
	~ListWdbeQSilList();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilList* rec);

	ListWdbeQSilList& operator=(const ListWdbeQSilList& src);

public:
	std::vector<WdbeQSilList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilList: C++ wrapper for table TblWdbeQSilList
	*/
class TblWdbeQSilList {

public:
	TblWdbeQSilList();
	virtual ~TblWdbeQSilList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilList* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilList& rst, WdbeQSilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint refWdbeMSystem = 0, const std::string stubRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");
	virtual void insertRst(ListWdbeQSilList& rst);
	virtual void updateRec(WdbeQSilList* rec);
	virtual void updateRst(ListWdbeQSilList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilList: C++ wrapper for table TblWdbeQSilList (MySQL database)
	*/
class MyTblWdbeQSilList : public TblWdbeQSilList, public Sbecore::MyTable {

public:
	MyTblWdbeQSilList();
	~MyTblWdbeQSilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilList& rst);

	Sbecore::ubigint insertRec(WdbeQSilList* rec);
	void insertRst(ListWdbeQSilList& rst);
	void updateRec(WdbeQSilList* rec);
	void updateRst(ListWdbeQSilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilList: C++ wrapper for table TblWdbeQSilList (PgSQL database)
	*/
class PgTblWdbeQSilList : public TblWdbeQSilList, public Sbecore::PgTable {

public:
	PgTblWdbeQSilList();
	~PgTblWdbeQSilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilList& rst);

	Sbecore::ubigint insertRec(WdbeQSilList* rec);
	void insertRst(ListWdbeQSilList& rst);
	void updateRec(WdbeQSilList* rec);
	void updateRst(ListWdbeQSilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilList& rst);
};
#endif

#endif
