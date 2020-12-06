/**
	* \file WdbeQPrtList.h
	* Dbs and XML wrapper for table TblWdbeQPrtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRTLIST_H
#define WDBEQPRTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrtList: record of TblWdbeQPrtList
	*/
class WdbeQPrtList {

public:
	WdbeQPrtList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mdlIxVCat = 0, const std::string srefMdlIxVCat = "", const std::string titMdlIxVCat = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint mdlRefWdbeMModule;
	std::string stubMdlRefWdbeMModule;
	Sbecore::uint mdlIxVCat;
	std::string srefMdlIxVCat;
	std::string titMdlIxVCat;
	Sbecore::uint ixVDir;
	std::string srefIxVDir;
	std::string titIxVDir;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrtList: recordset of TblWdbeQPrtList
	*/
class ListWdbeQPrtList {

public:
	ListWdbeQPrtList();
	ListWdbeQPrtList(const ListWdbeQPrtList& src);
	~ListWdbeQPrtList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrtList* rec);

	ListWdbeQPrtList& operator=(const ListWdbeQPrtList& src);

public:
	std::vector<WdbeQPrtList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrtList: C++ wrapper for table TblWdbeQPrtList
	*/
class TblWdbeQPrtList {

public:
	TblWdbeQPrtList();
	virtual ~TblWdbeQPrtList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrtList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mdlIxVCat = 0, const std::string srefMdlIxVCat = "", const std::string titMdlIxVCat = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrtList& rst, WdbeQPrtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint mdlRefWdbeMModule = 0, const std::string stubMdlRefWdbeMModule = "", const Sbecore::uint mdlIxVCat = 0, const std::string srefMdlIxVCat = "", const std::string titMdlIxVCat = "", const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	virtual void insertRst(ListWdbeQPrtList& rst);
	virtual void updateRec(WdbeQPrtList* rec);
	virtual void updateRst(ListWdbeQPrtList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrtList: C++ wrapper for table TblWdbeQPrtList (MySQL database)
	*/
class MyTblWdbeQPrtList : public TblWdbeQPrtList, public Sbecore::MyTable {

public:
	MyTblWdbeQPrtList();
	~MyTblWdbeQPrtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtList& rst);

	Sbecore::ubigint insertRec(WdbeQPrtList* rec);
	void insertRst(ListWdbeQPrtList& rst);
	void updateRec(WdbeQPrtList* rec);
	void updateRst(ListWdbeQPrtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrtList: C++ wrapper for table TblWdbeQPrtList (PgSQL database)
	*/
class PgTblWdbeQPrtList : public TblWdbeQPrtList, public Sbecore::PgTable {

public:
	PgTblWdbeQPrtList();
	~PgTblWdbeQPrtList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrtList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrtList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrtList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtList& rst);

	Sbecore::ubigint insertRec(WdbeQPrtList* rec);
	void insertRst(ListWdbeQPrtList& rst);
	void updateRec(WdbeQPrtList* rec);
	void updateRst(ListWdbeQPrtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtList& rst);
};
#endif

#endif
