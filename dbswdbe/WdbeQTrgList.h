/**
	* \file WdbeQTrgList.h
	* Dbs and XML wrapper for table TblWdbeQTrgList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQTRGLIST_H
#define WDBEQTRGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQTrgList: record of TblWdbeQTrgList
	*/
class WdbeQTrgList {

public:
	WdbeQTrgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint sysRefWdbeMSystem = 0, const std::string stubSysRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint sysRefWdbeMSystem;
	std::string stubSysRefWdbeMSystem;
	Sbecore::ubigint refWdbeMUnit;
	std::string stubRefWdbeMUnit;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQTrgList: recordset of TblWdbeQTrgList
	*/
class ListWdbeQTrgList {

public:
	ListWdbeQTrgList();
	ListWdbeQTrgList(const ListWdbeQTrgList& src);
	~ListWdbeQTrgList();

	void clear();
	unsigned int size() const;
	void append(WdbeQTrgList* rec);

	ListWdbeQTrgList& operator=(const ListWdbeQTrgList& src);

public:
	std::vector<WdbeQTrgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQTrgList: C++ wrapper for table TblWdbeQTrgList
	*/
class TblWdbeQTrgList {

public:
	TblWdbeQTrgList();
	virtual ~TblWdbeQTrgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQTrgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQTrgList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQTrgList* rec);
	Sbecore::ubigint insertNewRec(WdbeQTrgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint sysRefWdbeMSystem = 0, const std::string stubSysRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQTrgList& rst, WdbeQTrgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint sysRefWdbeMSystem = 0, const std::string stubSysRefWdbeMSystem = "", const Sbecore::ubigint refWdbeMUnit = 0, const std::string stubRefWdbeMUnit = "");
	virtual void insertRst(ListWdbeQTrgList& rst);
	virtual void updateRec(WdbeQTrgList* rec);
	virtual void updateRst(ListWdbeQTrgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQTrgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQTrgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQTrgList: C++ wrapper for table TblWdbeQTrgList (MySQL database)
	*/
class MyTblWdbeQTrgList : public TblWdbeQTrgList, public Sbecore::MyTable {

public:
	MyTblWdbeQTrgList();
	~MyTblWdbeQTrgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQTrgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQTrgList& rst);

	Sbecore::ubigint insertRec(WdbeQTrgList* rec);
	void insertRst(ListWdbeQTrgList& rst);
	void updateRec(WdbeQTrgList* rec);
	void updateRst(ListWdbeQTrgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQTrgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQTrgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQTrgList: C++ wrapper for table TblWdbeQTrgList (PgSQL database)
	*/
class PgTblWdbeQTrgList : public TblWdbeQTrgList, public Sbecore::PgTable {

public:
	PgTblWdbeQTrgList();
	~PgTblWdbeQTrgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQTrgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQTrgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQTrgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQTrgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQTrgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQTrgList& rst);

	Sbecore::ubigint insertRec(WdbeQTrgList* rec);
	void insertRst(ListWdbeQTrgList& rst);
	void updateRec(WdbeQTrgList* rec);
	void updateRst(ListWdbeQTrgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQTrgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQTrgList& rst);
};
#endif

#endif

