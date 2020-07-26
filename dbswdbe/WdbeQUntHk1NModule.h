/**
	* \file WdbeQUntHk1NModule.h
	* Dbs and XML wrapper for table TblWdbeQUntHk1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQUNTHK1NMODULE_H
#define WDBEQUNTHK1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntHk1NModule: record of TblWdbeQUntHk1NModule
	*/
class WdbeQUntHk1NModule {

public:
	WdbeQUntHk1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint hkNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntHk1NModule: recordset of TblWdbeQUntHk1NModule
	*/
class ListWdbeQUntHk1NModule {

public:
	ListWdbeQUntHk1NModule();
	ListWdbeQUntHk1NModule(const ListWdbeQUntHk1NModule& src);
	~ListWdbeQUntHk1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntHk1NModule* rec);

	ListWdbeQUntHk1NModule& operator=(const ListWdbeQUntHk1NModule& src);

public:
	std::vector<WdbeQUntHk1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntHk1NModule: C++ wrapper for table TblWdbeQUntHk1NModule
	*/
class TblWdbeQUntHk1NModule {

public:
	TblWdbeQUntHk1NModule();
	virtual ~TblWdbeQUntHk1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntHk1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntHk1NModule& rst, WdbeQUntHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWdbeQUntHk1NModule& rst);
	virtual void updateRec(WdbeQUntHk1NModule* rec);
	virtual void updateRst(ListWdbeQUntHk1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntHk1NModule: C++ wrapper for table TblWdbeQUntHk1NModule (MySQL database)
	*/
class MyTblWdbeQUntHk1NModule : public TblWdbeQUntHk1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQUntHk1NModule();
	~MyTblWdbeQUntHk1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQUntHk1NModule* rec);
	void insertRst(ListWdbeQUntHk1NModule& rst);
	void updateRec(WdbeQUntHk1NModule* rec);
	void updateRst(ListWdbeQUntHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntHk1NModule: C++ wrapper for table TblWdbeQUntHk1NModule (PgSQL database)
	*/
class PgTblWdbeQUntHk1NModule : public TblWdbeQUntHk1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQUntHk1NModule();
	~PgTblWdbeQUntHk1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntHk1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntHk1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQUntHk1NModule* rec);
	void insertRst(ListWdbeQUntHk1NModule& rst);
	void updateRec(WdbeQUntHk1NModule* rec);
	void updateRst(ListWdbeQUntHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntHk1NModule& rst);
};
#endif

#endif

