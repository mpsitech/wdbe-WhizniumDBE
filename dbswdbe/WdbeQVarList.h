/**
	* \file WdbeQVarList.h
	* Dbs and XML wrapper for table TblWdbeQVarList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQVARLIST_H
#define WDBEQVARLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVarList: record of TblWdbeQVarList
	*/
class WdbeQVarList {

public:
	WdbeQVarList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint prcRefWdbeMProcess = 0, const std::string stubPrcRefWdbeMProcess = "", const bool Const = false, const std::string yesnoConst = "", const bool Falling = false, const std::string yesnoFalling = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint prcRefWdbeMProcess;
	std::string stubPrcRefWdbeMProcess;
	bool Const;
	std::string yesnoConst;
	bool Falling;
	std::string yesnoFalling;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVarList: recordset of TblWdbeQVarList
	*/
class ListWdbeQVarList {

public:
	ListWdbeQVarList();
	ListWdbeQVarList(const ListWdbeQVarList& src);
	~ListWdbeQVarList();

	void clear();
	unsigned int size() const;
	void append(WdbeQVarList* rec);

	ListWdbeQVarList& operator=(const ListWdbeQVarList& src);

public:
	std::vector<WdbeQVarList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVarList: C++ wrapper for table TblWdbeQVarList
	*/
class TblWdbeQVarList {

public:
	TblWdbeQVarList();
	virtual ~TblWdbeQVarList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVarList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVarList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVarList* rec);
	Sbecore::ubigint insertNewRec(WdbeQVarList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint prcRefWdbeMProcess = 0, const std::string stubPrcRefWdbeMProcess = "", const bool Const = false, const std::string yesnoConst = "", const bool Falling = false, const std::string yesnoFalling = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVarList& rst, WdbeQVarList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint prcRefWdbeMProcess = 0, const std::string stubPrcRefWdbeMProcess = "", const bool Const = false, const std::string yesnoConst = "", const bool Falling = false, const std::string yesnoFalling = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");
	virtual void insertRst(ListWdbeQVarList& rst);
	virtual void updateRec(WdbeQVarList* rec);
	virtual void updateRst(ListWdbeQVarList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVarList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVarList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVarList: C++ wrapper for table TblWdbeQVarList (MySQL database)
	*/
class MyTblWdbeQVarList : public TblWdbeQVarList, public Sbecore::MyTable {

public:
	MyTblWdbeQVarList();
	~MyTblWdbeQVarList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVarList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVarList& rst);

	Sbecore::ubigint insertRec(WdbeQVarList* rec);
	void insertRst(ListWdbeQVarList& rst);
	void updateRec(WdbeQVarList* rec);
	void updateRst(ListWdbeQVarList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVarList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVarList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVarList: C++ wrapper for table TblWdbeQVarList (PgSQL database)
	*/
class PgTblWdbeQVarList : public TblWdbeQVarList, public Sbecore::PgTable {

public:
	PgTblWdbeQVarList();
	~PgTblWdbeQVarList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVarList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVarList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVarList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVarList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVarList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVarList& rst);

	Sbecore::ubigint insertRec(WdbeQVarList* rec);
	void insertRst(ListWdbeQVarList& rst);
	void updateRec(WdbeQVarList* rec);
	void updateRst(ListWdbeQVarList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVarList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVarList& rst);
};
#endif

#endif

