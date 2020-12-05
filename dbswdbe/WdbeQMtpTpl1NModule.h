/**
	* \file WdbeQMtpTpl1NModule.h
	* Dbs and XML wrapper for table TblWdbeQMtpTpl1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPTPL1NMODULE_H
#define WDBEQMTPTPL1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpTpl1NModule: record of TblWdbeQMtpTpl1NModule
	*/
class WdbeQMtpTpl1NModule {

public:
	WdbeQMtpTpl1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpTpl1NModule: recordset of TblWdbeQMtpTpl1NModule
	*/
class ListWdbeQMtpTpl1NModule {

public:
	ListWdbeQMtpTpl1NModule();
	ListWdbeQMtpTpl1NModule(const ListWdbeQMtpTpl1NModule& src);
	~ListWdbeQMtpTpl1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpTpl1NModule* rec);

	ListWdbeQMtpTpl1NModule& operator=(const ListWdbeQMtpTpl1NModule& src);

public:
	std::vector<WdbeQMtpTpl1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpTpl1NModule: C++ wrapper for table TblWdbeQMtpTpl1NModule
	*/
class TblWdbeQMtpTpl1NModule {

public:
	TblWdbeQMtpTpl1NModule();
	virtual ~TblWdbeQMtpTpl1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpTpl1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpTpl1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpTpl1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpTpl1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpTpl1NModule& rst, WdbeQMtpTpl1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpTpl1NModule& rst);
	virtual void updateRec(WdbeQMtpTpl1NModule* rec);
	virtual void updateRst(ListWdbeQMtpTpl1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpTpl1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpTpl1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpTpl1NModule: C++ wrapper for table TblWdbeQMtpTpl1NModule (MySQL database)
	*/
class MyTblWdbeQMtpTpl1NModule : public TblWdbeQMtpTpl1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpTpl1NModule();
	~MyTblWdbeQMtpTpl1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpTpl1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQMtpTpl1NModule* rec);
	void insertRst(ListWdbeQMtpTpl1NModule& rst);
	void updateRec(WdbeQMtpTpl1NModule* rec);
	void updateRst(ListWdbeQMtpTpl1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpTpl1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpTpl1NModule: C++ wrapper for table TblWdbeQMtpTpl1NModule (PgSQL database)
	*/
class PgTblWdbeQMtpTpl1NModule : public TblWdbeQMtpTpl1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpTpl1NModule();
	~PgTblWdbeQMtpTpl1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpTpl1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpTpl1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpTpl1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQMtpTpl1NModule* rec);
	void insertRst(ListWdbeQMtpTpl1NModule& rst);
	void updateRec(WdbeQMtpTpl1NModule* rec);
	void updateRst(ListWdbeQMtpTpl1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpTpl1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpTpl1NModule& rst);
};
#endif

#endif

