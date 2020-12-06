/**
	* \file WdbeQPrjList.h
	* Dbs and XML wrapper for table TblWdbeQPrjList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJLIST_H
#define WDBEQPRJLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrjList: record of TblWdbeQPrjList
	*/
class WdbeQPrjList {

public:
	WdbeQPrjList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string Giturl = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	Sbecore::ubigint refWdbeMVersion;
	std::string stubRefWdbeMVersion;
	bool Easy;
	std::string yesnoEasy;
	std::string Giturl;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrjList: recordset of TblWdbeQPrjList
	*/
class ListWdbeQPrjList {

public:
	ListWdbeQPrjList();
	ListWdbeQPrjList(const ListWdbeQPrjList& src);
	~ListWdbeQPrjList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrjList* rec);

	ListWdbeQPrjList& operator=(const ListWdbeQPrjList& src);

public:
	std::vector<WdbeQPrjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrjList: C++ wrapper for table TblWdbeQPrjList
	*/
class TblWdbeQPrjList {

public:
	TblWdbeQPrjList();
	virtual ~TblWdbeQPrjList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrjList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string Giturl = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrjList& rst, WdbeQPrjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const bool Easy = false, const std::string yesnoEasy = "", const std::string Giturl = "");
	virtual void insertRst(ListWdbeQPrjList& rst);
	virtual void updateRec(WdbeQPrjList* rec);
	virtual void updateRst(ListWdbeQPrjList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrjList: C++ wrapper for table TblWdbeQPrjList (MySQL database)
	*/
class MyTblWdbeQPrjList : public TblWdbeQPrjList, public Sbecore::MyTable {

public:
	MyTblWdbeQPrjList();
	~MyTblWdbeQPrjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjList& rst);

	Sbecore::ubigint insertRec(WdbeQPrjList* rec);
	void insertRst(ListWdbeQPrjList& rst);
	void updateRec(WdbeQPrjList* rec);
	void updateRst(ListWdbeQPrjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrjList: C++ wrapper for table TblWdbeQPrjList (PgSQL database)
	*/
class PgTblWdbeQPrjList : public TblWdbeQPrjList, public Sbecore::PgTable {

public:
	PgTblWdbeQPrjList();
	~PgTblWdbeQPrjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrjList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrjList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrjList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrjList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjList& rst);

	Sbecore::ubigint insertRec(WdbeQPrjList* rec);
	void insertRst(ListWdbeQPrjList& rst);
	void updateRec(WdbeQPrjList* rec);
	void updateRst(ListWdbeQPrjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjList& rst);
};
#endif

#endif
