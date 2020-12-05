/**
	* \file WdbeQCvrHk1NModule.h
	* Dbs and XML wrapper for table TblWdbeQCvrHk1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRHK1NMODULE_H
#define WDBEQCVRHK1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCvrHk1NModule: record of TblWdbeQCvrHk1NModule
	*/
class WdbeQCvrHk1NModule {

public:
	WdbeQCvrHk1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

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
	* ListWdbeQCvrHk1NModule: recordset of TblWdbeQCvrHk1NModule
	*/
class ListWdbeQCvrHk1NModule {

public:
	ListWdbeQCvrHk1NModule();
	ListWdbeQCvrHk1NModule(const ListWdbeQCvrHk1NModule& src);
	~ListWdbeQCvrHk1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQCvrHk1NModule* rec);

	ListWdbeQCvrHk1NModule& operator=(const ListWdbeQCvrHk1NModule& src);

public:
	std::vector<WdbeQCvrHk1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCvrHk1NModule: C++ wrapper for table TblWdbeQCvrHk1NModule
	*/
class TblWdbeQCvrHk1NModule {

public:
	TblWdbeQCvrHk1NModule();
	virtual ~TblWdbeQCvrHk1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrHk1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrHk1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCvrHk1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQCvrHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCvrHk1NModule& rst, WdbeQCvrHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWdbeQCvrHk1NModule& rst);
	virtual void updateRec(WdbeQCvrHk1NModule* rec);
	virtual void updateRst(ListWdbeQCvrHk1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrHk1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrHk1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCvrHk1NModule: C++ wrapper for table TblWdbeQCvrHk1NModule (MySQL database)
	*/
class MyTblWdbeQCvrHk1NModule : public TblWdbeQCvrHk1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQCvrHk1NModule();
	~MyTblWdbeQCvrHk1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQCvrHk1NModule* rec);
	void insertRst(ListWdbeQCvrHk1NModule& rst);
	void updateRec(WdbeQCvrHk1NModule* rec);
	void updateRst(ListWdbeQCvrHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrHk1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCvrHk1NModule: C++ wrapper for table TblWdbeQCvrHk1NModule (PgSQL database)
	*/
class PgTblWdbeQCvrHk1NModule : public TblWdbeQCvrHk1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQCvrHk1NModule();
	~PgTblWdbeQCvrHk1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCvrHk1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCvrHk1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQCvrHk1NModule* rec);
	void insertRst(ListWdbeQCvrHk1NModule& rst);
	void updateRec(WdbeQCvrHk1NModule* rec);
	void updateRst(ListWdbeQCvrHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrHk1NModule& rst);
};
#endif

#endif

