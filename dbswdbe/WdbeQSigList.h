/**
	* \file WdbeQSigList.h
	* Dbs and XML wrapper for table TblWdbeQSigList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIGLIST_H
#define WDBEQSIGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSigList: record of TblWdbeQSigList
	*/
class WdbeQSigList {

public:
	WdbeQSigList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mgeIxVTbl = 0, const std::string srefMgeIxVTbl = "", const std::string titMgeIxVTbl = "", const Sbecore::ubigint mgeUref = 0, const std::string stubMgeUref = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const bool Const = false, const std::string yesnoConst = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint mdlRefWdbeMModule;
	std::string stubMdlRefWdbeMModule;
	Sbecore::uint mgeIxVTbl;
	std::string srefMgeIxVTbl;
	std::string titMgeIxVTbl;
	Sbecore::ubigint mgeUref;
	std::string stubMgeUref;
	Sbecore::ubigint refWdbeMVector;
	std::string stubRefWdbeMVector;
	bool Const;
	std::string yesnoConst;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSigList: recordset of TblWdbeQSigList
	*/
class ListWdbeQSigList {

public:
	ListWdbeQSigList();
	ListWdbeQSigList(const ListWdbeQSigList& src);
	~ListWdbeQSigList();

	void clear();
	unsigned int size() const;
	void append(WdbeQSigList* rec);

	ListWdbeQSigList& operator=(const ListWdbeQSigList& src);

public:
	std::vector<WdbeQSigList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSigList: C++ wrapper for table TblWdbeQSigList
	*/
class TblWdbeQSigList {

public:
	TblWdbeQSigList();
	virtual ~TblWdbeQSigList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSigList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSigList* rec);
	Sbecore::ubigint insertNewRec(WdbeQSigList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mgeIxVTbl = 0, const std::string srefMgeIxVTbl = "", const std::string titMgeIxVTbl = "", const Sbecore::ubigint mgeUref = 0, const std::string stubMgeUref = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const bool Const = false, const std::string yesnoConst = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSigList& rst, WdbeQSigList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mgeIxVTbl = 0, const std::string srefMgeIxVTbl = "", const std::string titMgeIxVTbl = "", const Sbecore::ubigint mgeUref = 0, const std::string stubMgeUref = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const bool Const = false, const std::string yesnoConst = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	virtual void insertRst(ListWdbeQSigList& rst);
	virtual void updateRec(WdbeQSigList* rec);
	virtual void updateRst(ListWdbeQSigList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSigList: C++ wrapper for table TblWdbeQSigList (MySQL database)
	*/
class MyTblWdbeQSigList : public TblWdbeQSigList, public Sbecore::MyTable {

public:
	MyTblWdbeQSigList();
	~MyTblWdbeQSigList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigList& rst);

	Sbecore::ubigint insertRec(WdbeQSigList* rec);
	void insertRst(ListWdbeQSigList& rst);
	void updateRec(WdbeQSigList* rec);
	void updateRst(ListWdbeQSigList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSigList: C++ wrapper for table TblWdbeQSigList (PgSQL database)
	*/
class PgTblWdbeQSigList : public TblWdbeQSigList, public Sbecore::PgTable {

public:
	PgTblWdbeQSigList();
	~PgTblWdbeQSigList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSigList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSigList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSigList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSigList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigList& rst);

	Sbecore::ubigint insertRec(WdbeQSigList* rec);
	void insertRst(ListWdbeQSigList& rst);
	void updateRec(WdbeQSigList* rec);
	void updateRst(ListWdbeQSigList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigList& rst);
};
#endif

#endif
