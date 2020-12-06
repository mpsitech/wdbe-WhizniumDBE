/**
	* \file WdbeQUsrList.h
	* Dbs and XML wrapper for table TblWdbeQUsrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSRLIST_H
#define WDBEQUSRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsrList: record of TblWdbeQUsrList
	*/
class WdbeQUsrList {

public:
	WdbeQUsrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMPerson = 0, const std::string stubRefWdbeMPerson = "", const std::string sref = "", const Sbecore::ubigint refWdbeMUsergroup = 0, const std::string stubRefWdbeMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWdbeVLocale = 0, const std::string srefIxWdbeVLocale = "", const std::string titIxWdbeVLocale = "", const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWdbeMPerson;
	std::string stubRefWdbeMPerson;
	std::string sref;
	Sbecore::ubigint refWdbeMUsergroup;
	std::string stubRefWdbeMUsergroup;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixWdbeVLocale;
	std::string srefIxWdbeVLocale;
	std::string titIxWdbeVLocale;
	Sbecore::uint ixWdbeVUserlevel;
	std::string srefIxWdbeVUserlevel;
	std::string titIxWdbeVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUsrList: recordset of TblWdbeQUsrList
	*/
class ListWdbeQUsrList {

public:
	ListWdbeQUsrList();
	ListWdbeQUsrList(const ListWdbeQUsrList& src);
	~ListWdbeQUsrList();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsrList* rec);

	ListWdbeQUsrList& operator=(const ListWdbeQUsrList& src);

public:
	std::vector<WdbeQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsrList: C++ wrapper for table TblWdbeQUsrList
	*/
class TblWdbeQUsrList {

public:
	TblWdbeQUsrList();
	virtual ~TblWdbeQUsrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsrList* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMPerson = 0, const std::string stubRefWdbeMPerson = "", const std::string sref = "", const Sbecore::ubigint refWdbeMUsergroup = 0, const std::string stubRefWdbeMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWdbeVLocale = 0, const std::string srefIxWdbeVLocale = "", const std::string titIxWdbeVLocale = "", const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsrList& rst, WdbeQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWdbeMPerson = 0, const std::string stubRefWdbeMPerson = "", const std::string sref = "", const Sbecore::ubigint refWdbeMUsergroup = 0, const std::string stubRefWdbeMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWdbeVLocale = 0, const std::string srefIxWdbeVLocale = "", const std::string titIxWdbeVLocale = "", const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	virtual void insertRst(ListWdbeQUsrList& rst);
	virtual void updateRec(WdbeQUsrList* rec);
	virtual void updateRst(ListWdbeQUsrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsrList: C++ wrapper for table TblWdbeQUsrList (MySQL database)
	*/
class MyTblWdbeQUsrList : public TblWdbeQUsrList, public Sbecore::MyTable {

public:
	MyTblWdbeQUsrList();
	~MyTblWdbeQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrList& rst);

	Sbecore::ubigint insertRec(WdbeQUsrList* rec);
	void insertRst(ListWdbeQUsrList& rst);
	void updateRec(WdbeQUsrList* rec);
	void updateRst(ListWdbeQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsrList: C++ wrapper for table TblWdbeQUsrList (PgSQL database)
	*/
class PgTblWdbeQUsrList : public TblWdbeQUsrList, public Sbecore::PgTable {

public:
	PgTblWdbeQUsrList();
	~PgTblWdbeQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrList& rst);

	Sbecore::ubigint insertRec(WdbeQUsrList* rec);
	void insertRst(ListWdbeQUsrList& rst);
	void updateRec(WdbeQUsrList* rec);
	void updateRst(ListWdbeQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrList& rst);
};
#endif

#endif
