/**
	* \file WdbeQMod1NProcess.h
	* Dbs and XML wrapper for table TblWdbeQMod1NProcess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMOD1NPROCESS_H
#define WDBEQMOD1NPROCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMod1NProcess: record of TblWdbeQMod1NProcess
	*/
class WdbeQMod1NProcess {

public:
	WdbeQMod1NProcess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMod1NProcess: recordset of TblWdbeQMod1NProcess
	*/
class ListWdbeQMod1NProcess {

public:
	ListWdbeQMod1NProcess();
	ListWdbeQMod1NProcess(const ListWdbeQMod1NProcess& src);
	~ListWdbeQMod1NProcess();

	void clear();
	unsigned int size() const;
	void append(WdbeQMod1NProcess* rec);

	ListWdbeQMod1NProcess& operator=(const ListWdbeQMod1NProcess& src);

public:
	std::vector<WdbeQMod1NProcess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMod1NProcess: C++ wrapper for table TblWdbeQMod1NProcess
	*/
class TblWdbeQMod1NProcess {

public:
	TblWdbeQMod1NProcess();
	virtual ~TblWdbeQMod1NProcess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NProcess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NProcess& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMod1NProcess* rec);
	Sbecore::ubigint insertNewRec(WdbeQMod1NProcess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMod1NProcess& rst, WdbeQMod1NProcess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMod1NProcess& rst);
	virtual void updateRec(WdbeQMod1NProcess* rec);
	virtual void updateRst(ListWdbeQMod1NProcess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NProcess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NProcess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMod1NProcess: C++ wrapper for table TblWdbeQMod1NProcess (MySQL database)
	*/
class MyTblWdbeQMod1NProcess : public TblWdbeQMod1NProcess, public Sbecore::MyTable {

public:
	MyTblWdbeQMod1NProcess();
	~MyTblWdbeQMod1NProcess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NProcess& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NProcess* rec);
	void insertRst(ListWdbeQMod1NProcess& rst);
	void updateRec(WdbeQMod1NProcess* rec);
	void updateRst(ListWdbeQMod1NProcess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NProcess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMod1NProcess: C++ wrapper for table TblWdbeQMod1NProcess (PgSQL database)
	*/
class PgTblWdbeQMod1NProcess : public TblWdbeQMod1NProcess, public Sbecore::PgTable {

public:
	PgTblWdbeQMod1NProcess();
	~PgTblWdbeQMod1NProcess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMod1NProcess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMod1NProcess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NProcess& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NProcess* rec);
	void insertRst(ListWdbeQMod1NProcess& rst);
	void updateRec(WdbeQMod1NProcess* rec);
	void updateRst(ListWdbeQMod1NProcess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NProcess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NProcess& rst);
};
#endif

#endif
