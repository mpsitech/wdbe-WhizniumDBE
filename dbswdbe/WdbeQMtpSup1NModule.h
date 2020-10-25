/**
	* \file WdbeQMtpSup1NModule.h
	* Dbs and XML wrapper for table TblWdbeQMtpSup1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPSUP1NMODULE_H
#define WDBEQMTPSUP1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpSup1NModule: record of TblWdbeQMtpSup1NModule
	*/
class WdbeQMtpSup1NModule {

public:
	WdbeQMtpSup1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpSup1NModule: recordset of TblWdbeQMtpSup1NModule
	*/
class ListWdbeQMtpSup1NModule {

public:
	ListWdbeQMtpSup1NModule();
	ListWdbeQMtpSup1NModule(const ListWdbeQMtpSup1NModule& src);
	~ListWdbeQMtpSup1NModule();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpSup1NModule* rec);

	ListWdbeQMtpSup1NModule& operator=(const ListWdbeQMtpSup1NModule& src);

public:
	std::vector<WdbeQMtpSup1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpSup1NModule: C++ wrapper for table TblWdbeQMtpSup1NModule
	*/
class TblWdbeQMtpSup1NModule {

public:
	TblWdbeQMtpSup1NModule();
	virtual ~TblWdbeQMtpSup1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpSup1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpSup1NModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpSup1NModule* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpSup1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpSup1NModule& rst, WdbeQMtpSup1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpSup1NModule& rst);
	virtual void updateRec(WdbeQMtpSup1NModule* rec);
	virtual void updateRst(ListWdbeQMtpSup1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpSup1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpSup1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpSup1NModule: C++ wrapper for table TblWdbeQMtpSup1NModule (MySQL database)
	*/
class MyTblWdbeQMtpSup1NModule : public TblWdbeQMtpSup1NModule, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpSup1NModule();
	~MyTblWdbeQMtpSup1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpSup1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQMtpSup1NModule* rec);
	void insertRst(ListWdbeQMtpSup1NModule& rst);
	void updateRec(WdbeQMtpSup1NModule* rec);
	void updateRst(ListWdbeQMtpSup1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpSup1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpSup1NModule: C++ wrapper for table TblWdbeQMtpSup1NModule (PgSQL database)
	*/
class PgTblWdbeQMtpSup1NModule : public TblWdbeQMtpSup1NModule, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpSup1NModule();
	~PgTblWdbeQMtpSup1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpSup1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpSup1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpSup1NModule& rst);

	Sbecore::ubigint insertRec(WdbeQMtpSup1NModule* rec);
	void insertRst(ListWdbeQMtpSup1NModule& rst);
	void updateRec(WdbeQMtpSup1NModule* rec);
	void updateRst(ListWdbeQMtpSup1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpSup1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpSup1NModule& rst);
};
#endif

#endif

