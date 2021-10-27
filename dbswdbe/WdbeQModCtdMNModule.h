/**
	* \file WdbeQModCtdMNModule.h
	* Dbs and XML wrapper for table TblWdbeQModCtdMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTDMNMODULE_H
#define WDBEQMODCTDMNMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCtdMNModule: record of TblWdbeQModCtdMNModule
	*/
class WdbeQModCtdMNModule {

public:
	WdbeQModCtdMNModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQModCtdMNModule: recordset of TblWdbeQModCtdMNModule
	*/
class ListWdbeQModCtdMNModule {

public:
	ListWdbeQModCtdMNModule();
	ListWdbeQModCtdMNModule(const ListWdbeQModCtdMNModule& src);
	~ListWdbeQModCtdMNModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCtdMNModule* rec);

	ListWdbeQModCtdMNModule& operator=(const ListWdbeQModCtdMNModule& src);

public:
	std::vector<WdbeQModCtdMNModule*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCtdMNModule: C++ wrapper for table TblWdbeQModCtdMNModule
	*/
class TblWdbeQModCtdMNModule {

public:
	TblWdbeQModCtdMNModule();
	virtual ~TblWdbeQModCtdMNModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtdMNModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtdMNModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCtdMNModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCtdMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCtdMNModule& rst, WdbeQModCtdMNModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQModCtdMNModule& rst);
	virtual void updateRec(WdbeQModCtdMNModule* rec);
	virtual void updateRst(ListWdbeQModCtdMNModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtdMNModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtdMNModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCtdMNModule: C++ wrapper for table TblWdbeQModCtdMNModule (MySQL database)
	*/
class MyTblWdbeQModCtdMNModule : public TblWdbeQModCtdMNModule, public Sbecore::MyTable {

public:
	MyTblWdbeQModCtdMNModule();
	~MyTblWdbeQModCtdMNModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtdMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQModCtdMNModule* rec);
	void insertRst(ListWdbeQModCtdMNModule& rst);
	void updateRec(WdbeQModCtdMNModule* rec);
	void updateRst(ListWdbeQModCtdMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtdMNModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCtdMNModule: C++ wrapper for table TblWdbeQModCtdMNModule (PgSQL database)
	*/
class PgTblWdbeQModCtdMNModule : public TblWdbeQModCtdMNModule, public Sbecore::PgTable {

public:
	PgTblWdbeQModCtdMNModule();
	~PgTblWdbeQModCtdMNModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCtdMNModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCtdMNModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtdMNModule& rst);

	Sbecore::ubigint insertRec(WdbeQModCtdMNModule* rec);
	void insertRst(ListWdbeQModCtdMNModule& rst);
	void updateRec(WdbeQModCtdMNModule* rec);
	void updateRst(ListWdbeQModCtdMNModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtdMNModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtdMNModule& rst);
};
#endif

#endif
