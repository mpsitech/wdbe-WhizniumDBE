/**
	* \file WdbeQPphMNModule.h
	* Dbs and XML wrapper for table TblWdbeQPphMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPHMNMODULE_H
#define WDBEQPPHMNMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPphMNModule: record of TblWdbeQPphMNModule
	*/
class WdbeQPphMNModule {

public:
	WdbeQPphMNModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPphMNModule: recordset of TblWdbeQPphMNModule
	*/
class ListWdbeQPphMNModule {

public:
	ListWdbeQPphMNModule();
	ListWdbeQPphMNModule(const ListWdbeQPphMNModule& src);
	~ListWdbeQPphMNModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQPphMNModule* rec);

	ListWdbeQPphMNModule& operator=(const ListWdbeQPphMNModule& src);

public:
	std::vector<WdbeQPphMNModule*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPphMNModule: C++ wrapper for table TblWdbeQPphMNModule
	*/
class TblWdbeQPphMNModule {

public:
	TblWdbeQPphMNModule();
	virtual ~TblWdbeQPphMNModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPphMNModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphMNModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPphMNModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQPphMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPphMNModule& rst, WdbeQPphMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQPphMNModule& rst);
	virtual void updateRec(WdbeQPphMNModule* rec);
	virtual void updateRst(ListWdbeQPphMNModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphMNModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphMNModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPphMNModule: C++ wrapper for table TblWdbeQPphMNModule (MySQL database)
	*/
class MyTblWdbeQPphMNModule : public TblWdbeQPphMNModule, public Sbecore::MyTable {

public:
	MyTblWdbeQPphMNModule();
	~MyTblWdbeQPphMNModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQPphMNModule* rec);
	void insertRst(ListWdbeQPphMNModule& rst);
	void updateRec(WdbeQPphMNModule* rec);
	void updateRst(ListWdbeQPphMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphMNModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPphMNModule: C++ wrapper for table TblWdbeQPphMNModule (PgSQL database)
	*/
class PgTblWdbeQPphMNModule : public TblWdbeQPphMNModule, public Sbecore::PgTable {

public:
	PgTblWdbeQPphMNModule();
	~PgTblWdbeQPphMNModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPphMNModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPphMNModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPphMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQPphMNModule* rec);
	void insertRst(ListWdbeQPphMNModule& rst);
	void updateRec(WdbeQPphMNModule* rec);
	void updateRst(ListWdbeQPphMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPphMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPphMNModule& rst);
};
#endif

#endif
