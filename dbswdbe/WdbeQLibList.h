/**
	* \file WdbeQLibList.h
	* Dbs and XML wrapper for table TblWdbeQLibList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQLIBLIST_H
#define WDBEQLIBLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQLibList: record of TblWdbeQLibList
	*/
class WdbeQLibList {

public:
	WdbeQLibList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string Version;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQLibList: recordset of TblWdbeQLibList
	*/
class ListWdbeQLibList {

public:
	ListWdbeQLibList();
	ListWdbeQLibList(const ListWdbeQLibList& src);
	~ListWdbeQLibList();

	void clear();
	unsigned int size() const;
	void append(WdbeQLibList* rec);

	ListWdbeQLibList& operator=(const ListWdbeQLibList& src);

public:
	std::vector<WdbeQLibList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQLibList: C++ wrapper for table TblWdbeQLibList
	*/
class TblWdbeQLibList {

public:
	TblWdbeQLibList();
	virtual ~TblWdbeQLibList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQLibList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQLibList* rec);
	Sbecore::ubigint insertNewRec(WdbeQLibList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQLibList& rst, WdbeQLibList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "");
	virtual void insertRst(ListWdbeQLibList& rst);
	virtual void updateRec(WdbeQLibList* rec);
	virtual void updateRst(ListWdbeQLibList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQLibList: C++ wrapper for table TblWdbeQLibList (MySQL database)
	*/
class MyTblWdbeQLibList : public TblWdbeQLibList, public Sbecore::MyTable {

public:
	MyTblWdbeQLibList();
	~MyTblWdbeQLibList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibList& rst);

	Sbecore::ubigint insertRec(WdbeQLibList* rec);
	void insertRst(ListWdbeQLibList& rst);
	void updateRec(WdbeQLibList* rec);
	void updateRst(ListWdbeQLibList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQLibList: C++ wrapper for table TblWdbeQLibList (PgSQL database)
	*/
class PgTblWdbeQLibList : public TblWdbeQLibList, public Sbecore::PgTable {

public:
	PgTblWdbeQLibList();
	~PgTblWdbeQLibList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQLibList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQLibList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQLibList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQLibList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibList& rst);

	Sbecore::ubigint insertRec(WdbeQLibList* rec);
	void insertRst(ListWdbeQLibList& rst);
	void updateRec(WdbeQLibList* rec);
	void updateRst(ListWdbeQLibList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibList& rst);
};
#endif

#endif

