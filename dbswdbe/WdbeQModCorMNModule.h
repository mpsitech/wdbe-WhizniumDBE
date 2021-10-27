/**
	* \file WdbeQModCorMNModule.h
	* Dbs and XML wrapper for table TblWdbeQModCorMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODCORMNMODULE_H
#define WDBEQMODCORMNMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCorMNModule: record of TblWdbeQModCorMNModule
	*/
class WdbeQModCorMNModule {

public:
	WdbeQModCorMNModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModCorMNModule: recordset of TblWdbeQModCorMNModule
	*/
class ListWdbeQModCorMNModule {

public:
	ListWdbeQModCorMNModule();
	ListWdbeQModCorMNModule(const ListWdbeQModCorMNModule& src);
	~ListWdbeQModCorMNModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCorMNModule* rec);

	ListWdbeQModCorMNModule& operator=(const ListWdbeQModCorMNModule& src);

public:
	std::vector<WdbeQModCorMNModule*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCorMNModule: C++ wrapper for table TblWdbeQModCorMNModule
	*/
class TblWdbeQModCorMNModule {

public:
	TblWdbeQModCorMNModule();
	virtual ~TblWdbeQModCorMNModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCorMNModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCorMNModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCorMNModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCorMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCorMNModule& rst, WdbeQModCorMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQModCorMNModule& rst);
	virtual void updateRec(WdbeQModCorMNModule* rec);
	virtual void updateRst(ListWdbeQModCorMNModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCorMNModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCorMNModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCorMNModule: C++ wrapper for table TblWdbeQModCorMNModule (MySQL database)
	*/
class MyTblWdbeQModCorMNModule : public TblWdbeQModCorMNModule, public Sbecore::MyTable {

public:
	MyTblWdbeQModCorMNModule();
	~MyTblWdbeQModCorMNModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCorMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQModCorMNModule* rec);
	void insertRst(ListWdbeQModCorMNModule& rst);
	void updateRec(WdbeQModCorMNModule* rec);
	void updateRst(ListWdbeQModCorMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCorMNModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCorMNModule: C++ wrapper for table TblWdbeQModCorMNModule (PgSQL database)
	*/
class PgTblWdbeQModCorMNModule : public TblWdbeQModCorMNModule, public Sbecore::PgTable {

public:
	PgTblWdbeQModCorMNModule();
	~PgTblWdbeQModCorMNModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCorMNModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCorMNModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCorMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQModCorMNModule* rec);
	void insertRst(ListWdbeQModCorMNModule& rst);
	void updateRec(WdbeQModCorMNModule* rec);
	void updateRst(ListWdbeQModCorMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCorMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCorMNModule& rst);
};
#endif

#endif
