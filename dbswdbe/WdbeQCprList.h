/**
	* \file WdbeQCprList.h
	* Dbs and XML wrapper for table TblWdbeQCprList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCPRLIST_H
#define WDBEQCPRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCprList: record of TblWdbeQCprList
	*/
class WdbeQCprList {

public:
	WdbeQCprList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string stubRefWdbeMCoreversion = "", const std::string Giturl = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string sref;
	std::string Title;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWdbeMCoreversion;
	std::string stubRefWdbeMCoreversion;
	std::string Giturl;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCprList: recordset of TblWdbeQCprList
	*/
class ListWdbeQCprList {

public:
	ListWdbeQCprList();
	ListWdbeQCprList(const ListWdbeQCprList& src);
	~ListWdbeQCprList();

	void clear();
	unsigned int size() const;
	void append(WdbeQCprList* rec);

	ListWdbeQCprList& operator=(const ListWdbeQCprList& src);

public:
	std::vector<WdbeQCprList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCprList: C++ wrapper for table TblWdbeQCprList
	*/
class TblWdbeQCprList {

public:
	TblWdbeQCprList();
	virtual ~TblWdbeQCprList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCprList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCprList* rec);
	Sbecore::ubigint insertNewRec(WdbeQCprList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string stubRefWdbeMCoreversion = "", const std::string Giturl = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCprList& rst, WdbeQCprList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string stubRefWdbeMCoreversion = "", const std::string Giturl = "");
	virtual void insertRst(ListWdbeQCprList& rst);
	virtual void updateRec(WdbeQCprList* rec);
	virtual void updateRst(ListWdbeQCprList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCprList: C++ wrapper for table TblWdbeQCprList (MySQL database)
	*/
class MyTblWdbeQCprList : public TblWdbeQCprList, public Sbecore::MyTable {

public:
	MyTblWdbeQCprList();
	~MyTblWdbeQCprList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCprList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprList& rst);

	Sbecore::ubigint insertRec(WdbeQCprList* rec);
	void insertRst(ListWdbeQCprList& rst);
	void updateRec(WdbeQCprList* rec);
	void updateRst(ListWdbeQCprList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCprList: C++ wrapper for table TblWdbeQCprList (PgSQL database)
	*/
class PgTblWdbeQCprList : public TblWdbeQCprList, public Sbecore::PgTable {

public:
	PgTblWdbeQCprList();
	~PgTblWdbeQCprList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCprList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCprList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCprList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCprList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCprList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprList& rst);

	Sbecore::ubigint insertRec(WdbeQCprList* rec);
	void insertRst(ListWdbeQCprList& rst);
	void updateRec(WdbeQCprList* rec);
	void updateRst(ListWdbeQCprList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprList& rst);
};
#endif

#endif
