/**
	* \file WdbeQPrcList.h
	* Dbs and XML wrapper for table TblWdbeQPrcList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPRCLIST_H
#define WDBEQPRCLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcList: record of TblWdbeQPrcList
	*/
class WdbeQPrcList {

public:
	WdbeQPrcList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const bool Falling = false, const std::string yesnoFalling = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWdbeMModule;
	std::string stubRefWdbeMModule;
	bool Falling;
	std::string yesnoFalling;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcList: recordset of TblWdbeQPrcList
	*/
class ListWdbeQPrcList {

public:
	ListWdbeQPrcList();
	ListWdbeQPrcList(const ListWdbeQPrcList& src);
	~ListWdbeQPrcList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcList* rec);

	ListWdbeQPrcList& operator=(const ListWdbeQPrcList& src);

public:
	std::vector<WdbeQPrcList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcList: C++ wrapper for table TblWdbeQPrcList
	*/
class TblWdbeQPrcList {

public:
	TblWdbeQPrcList();
	virtual ~TblWdbeQPrcList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const bool Falling = false, const std::string yesnoFalling = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcList& rst, WdbeQPrcList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWdbeMModule = 0, const std::string stubRefWdbeMModule = "", const bool Falling = false, const std::string yesnoFalling = "");
	virtual void insertRst(ListWdbeQPrcList& rst);
	virtual void updateRec(WdbeQPrcList* rec);
	virtual void updateRst(ListWdbeQPrcList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcList: C++ wrapper for table TblWdbeQPrcList (MySQL database)
	*/
class MyTblWdbeQPrcList : public TblWdbeQPrcList, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcList();
	~MyTblWdbeQPrcList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcList& rst);

	Sbecore::ubigint insertRec(WdbeQPrcList* rec);
	void insertRst(ListWdbeQPrcList& rst);
	void updateRec(WdbeQPrcList* rec);
	void updateRst(ListWdbeQPrcList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcList: C++ wrapper for table TblWdbeQPrcList (PgSQL database)
	*/
class PgTblWdbeQPrcList : public TblWdbeQPrcList, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcList();
	~PgTblWdbeQPrcList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcList& rst);

	Sbecore::ubigint insertRec(WdbeQPrcList* rec);
	void insertRst(ListWdbeQPrcList& rst);
	void updateRec(WdbeQPrcList* rec);
	void updateRst(ListWdbeQPrcList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcList& rst);
};
#endif

#endif

