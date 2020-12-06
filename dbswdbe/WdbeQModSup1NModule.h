/**
	* \file WdbeQModSup1NModule.h
	* Dbs and XML wrapper for table TblWdbeQModSup1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODSUP1NMODULE_H
#define WDBEQMODSUP1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModSup1NModule: record of TblWdbeQModSup1NModule
	*/
class WdbeQModSup1NModule {

public:
	WdbeQModSup1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModSup1NModule: recordset of TblWdbeQModSup1NModule
	*/
class ListWdbeQModSup1NModule {

public:
	ListWdbeQModSup1NModule();
	ListWdbeQModSup1NModule(const ListWdbeQModSup1NModule& src);
	~ListWdbeQModSup1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQModSup1NModule* rec);

	ListWdbeQModSup1NModule& operator=(const ListWdbeQModSup1NModule& src);

public:
	std::vector<WdbeQModSup1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModSup1NModule: C++ wrapper for table TblWdbeQModSup1NModule
	*/
class TblWdbeQModSup1NModule {

public:
	TblWdbeQModSup1NModule();
	virtual ~TblWdbeQModSup1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModSup1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModSup1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModSup1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQModSup1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModSup1NModule& rst, WdbeQModSup1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModSup1NModule& rst);
	virtual void updateRec(WdbeQModSup1NModule* rec);
	virtual void updateRst(ListWdbeQModSup1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModSup1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModSup1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModSup1NModule: C++ wrapper for table TblWdbeQModSup1NModule (MySQL database)
	*/
class MyTblWdbeQModSup1NModule : public TblWdbeQModSup1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQModSup1NModule();
	~MyTblWdbeQModSup1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModSup1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQModSup1NModule* rec);
	void insertRst(ListWdbeQModSup1NModule& rst);
	void updateRec(WdbeQModSup1NModule* rec);
	void updateRst(ListWdbeQModSup1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModSup1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModSup1NModule: C++ wrapper for table TblWdbeQModSup1NModule (PgSQL database)
	*/
class PgTblWdbeQModSup1NModule : public TblWdbeQModSup1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQModSup1NModule();
	~PgTblWdbeQModSup1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModSup1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModSup1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModSup1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQModSup1NModule* rec);
	void insertRst(ListWdbeQModSup1NModule& rst);
	void updateRec(WdbeQModSup1NModule* rec);
	void updateRst(ListWdbeQModSup1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModSup1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModSup1NModule& rst);
};
#endif

#endif
