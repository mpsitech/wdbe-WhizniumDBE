/**
	* \file WdbeQUsgList.h
	* Dbs and XML wrapper for table TblWdbeQUsgList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUSGLIST_H
#define WDBEQUSGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsgList: record of TblWdbeQUsgList
	*/
class WdbeQUsgList {

public:
	WdbeQUsgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");

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

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUsgList: recordset of TblWdbeQUsgList
	*/
class ListWdbeQUsgList {

public:
	ListWdbeQUsgList();
	ListWdbeQUsgList(const ListWdbeQUsgList& src);
	~ListWdbeQUsgList();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsgList* rec);

	ListWdbeQUsgList& operator=(const ListWdbeQUsgList& src);

public:
	std::vector<WdbeQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsgList: C++ wrapper for table TblWdbeQUsgList
	*/
class TblWdbeQUsgList {

public:
	TblWdbeQUsgList();
	virtual ~TblWdbeQUsgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsgList* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsgList& rst, WdbeQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	virtual void insertRst(ListWdbeQUsgList& rst);
	virtual void updateRec(WdbeQUsgList* rec);
	virtual void updateRst(ListWdbeQUsgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsgList: C++ wrapper for table TblWdbeQUsgList (MySQL database)
	*/
class MyTblWdbeQUsgList : public TblWdbeQUsgList, public Sbecore::MyTable {

public:
	MyTblWdbeQUsgList();
	~MyTblWdbeQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgList& rst);

	Sbecore::ubigint insertRec(WdbeQUsgList* rec);
	void insertRst(ListWdbeQUsgList& rst);
	void updateRec(WdbeQUsgList* rec);
	void updateRst(ListWdbeQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsgList: C++ wrapper for table TblWdbeQUsgList (PgSQL database)
	*/
class PgTblWdbeQUsgList : public TblWdbeQUsgList, public Sbecore::PgTable {

public:
	PgTblWdbeQUsgList();
	~PgTblWdbeQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgList& rst);

	Sbecore::ubigint insertRec(WdbeQUsgList* rec);
	void insertRst(ListWdbeQUsgList& rst);
	void updateRec(WdbeQUsgList* rec);
	void updateRst(ListWdbeQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgList& rst);
};
#endif

#endif

