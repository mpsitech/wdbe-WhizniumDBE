/**
	* \file WdbeQSilHk1NModule.h
	* Dbs and XML wrapper for table TblWdbeQSilHk1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILHK1NMODULE_H
#define WDBEQSILHK1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilHk1NModule: record of TblWdbeQSilHk1NModule
	*/
class WdbeQSilHk1NModule {

public:
	WdbeQSilHk1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint hkNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSilHk1NModule: recordset of TblWdbeQSilHk1NModule
	*/
class ListWdbeQSilHk1NModule {

public:
	ListWdbeQSilHk1NModule();
	ListWdbeQSilHk1NModule(const ListWdbeQSilHk1NModule& src);
	~ListWdbeQSilHk1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilHk1NModule* rec);

	ListWdbeQSilHk1NModule& operator=(const ListWdbeQSilHk1NModule& src);

public:
	std::vector<WdbeQSilHk1NModule*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilHk1NModule: C++ wrapper for table TblWdbeQSilHk1NModule
	*/
class TblWdbeQSilHk1NModule {

public:
	TblWdbeQSilHk1NModule();
	virtual ~TblWdbeQSilHk1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilHk1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilHk1NModule& rst, WdbeQSilHk1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWdbeQSilHk1NModule& rst);
	virtual void updateRec(WdbeQSilHk1NModule* rec);
	virtual void updateRst(ListWdbeQSilHk1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilHk1NModule: C++ wrapper for table TblWdbeQSilHk1NModule (MySQL database)
	*/
class MyTblWdbeQSilHk1NModule : public TblWdbeQSilHk1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQSilHk1NModule();
	~MyTblWdbeQSilHk1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQSilHk1NModule* rec);
	void insertRst(ListWdbeQSilHk1NModule& rst);
	void updateRec(WdbeQSilHk1NModule* rec);
	void updateRst(ListWdbeQSilHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilHk1NModule: C++ wrapper for table TblWdbeQSilHk1NModule (PgSQL database)
	*/
class PgTblWdbeQSilHk1NModule : public TblWdbeQSilHk1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQSilHk1NModule();
	~PgTblWdbeQSilHk1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilHk1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilHk1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilHk1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQSilHk1NModule* rec);
	void insertRst(ListWdbeQSilHk1NModule& rst);
	void updateRec(WdbeQSilHk1NModule* rec);
	void updateRst(ListWdbeQSilHk1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilHk1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilHk1NModule& rst);
};
#endif

#endif
