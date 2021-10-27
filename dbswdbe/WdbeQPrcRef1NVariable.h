/**
	* \file WdbeQPrcRef1NVariable.h
	* Dbs and XML wrapper for table TblWdbeQPrcRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRCREF1NVARIABLE_H
#define WDBEQPRCREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcRef1NVariable: record of TblWdbeQPrcRef1NVariable
	*/
class WdbeQPrcRef1NVariable {

public:
	WdbeQPrcRef1NVariable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcRef1NVariable: recordset of TblWdbeQPrcRef1NVariable
	*/
class ListWdbeQPrcRef1NVariable {

public:
	ListWdbeQPrcRef1NVariable();
	ListWdbeQPrcRef1NVariable(const ListWdbeQPrcRef1NVariable& src);
	~ListWdbeQPrcRef1NVariable();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcRef1NVariable* rec);

	ListWdbeQPrcRef1NVariable& operator=(const ListWdbeQPrcRef1NVariable& src);

public:
	std::vector<WdbeQPrcRef1NVariable*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcRef1NVariable: C++ wrapper for table TblWdbeQPrcRef1NVariable
	*/
class TblWdbeQPrcRef1NVariable {

public:
	TblWdbeQPrcRef1NVariable();
	virtual ~TblWdbeQPrcRef1NVariable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NVariable& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcRef1NVariable* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcRef1NVariable& rst, WdbeQPrcRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQPrcRef1NVariable& rst);
	virtual void updateRec(WdbeQPrcRef1NVariable* rec);
	virtual void updateRst(ListWdbeQPrcRef1NVariable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NVariable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcRef1NVariable: C++ wrapper for table TblWdbeQPrcRef1NVariable (MySQL database)
	*/
class MyTblWdbeQPrcRef1NVariable : public TblWdbeQPrcRef1NVariable, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcRef1NVariable();
	~MyTblWdbeQPrcRef1NVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQPrcRef1NVariable* rec);
	void insertRst(ListWdbeQPrcRef1NVariable& rst);
	void updateRec(WdbeQPrcRef1NVariable* rec);
	void updateRst(ListWdbeQPrcRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NVariable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcRef1NVariable: C++ wrapper for table TblWdbeQPrcRef1NVariable (PgSQL database)
	*/
class PgTblWdbeQPrcRef1NVariable : public TblWdbeQPrcRef1NVariable, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcRef1NVariable();
	~PgTblWdbeQPrcRef1NVariable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcRef1NVariable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcRef1NVariable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQPrcRef1NVariable* rec);
	void insertRst(ListWdbeQPrcRef1NVariable& rst);
	void updateRec(WdbeQPrcRef1NVariable* rec);
	void updateRst(ListWdbeQPrcRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NVariable& rst);
};
#endif

#endif
