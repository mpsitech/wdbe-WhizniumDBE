/**
	* \file WdbeQPrcPrc1NVariable.h
	* Dbs and XML wrapper for table TblWdbeQPrcPrc1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCPRC1NVARIABLE_H
#define WDBEQPRCPRC1NVARIABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcPrc1NVariable: record of TblWdbeQPrcPrc1NVariable
	*/
class WdbeQPrcPrc1NVariable {

public:
	WdbeQPrcPrc1NVariable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prcNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint prcNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcPrc1NVariable: recordset of TblWdbeQPrcPrc1NVariable
	*/
class ListWdbeQPrcPrc1NVariable {

public:
	ListWdbeQPrcPrc1NVariable();
	ListWdbeQPrcPrc1NVariable(const ListWdbeQPrcPrc1NVariable& src);
	~ListWdbeQPrcPrc1NVariable();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcPrc1NVariable* rec);

	ListWdbeQPrcPrc1NVariable& operator=(const ListWdbeQPrcPrc1NVariable& src);

public:
	std::vector<WdbeQPrcPrc1NVariable*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcPrc1NVariable: C++ wrapper for table TblWdbeQPrcPrc1NVariable
	*/
class TblWdbeQPrcPrc1NVariable {

public:
	TblWdbeQPrcPrc1NVariable();
	virtual ~TblWdbeQPrcPrc1NVariable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcPrc1NVariable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcPrc1NVariable& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcPrc1NVariable* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcPrc1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prcNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcPrc1NVariable& rst, WdbeQPrcPrc1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prcNum = 0);
	virtual void insertRst(ListWdbeQPrcPrc1NVariable& rst);
	virtual void updateRec(WdbeQPrcPrc1NVariable* rec);
	virtual void updateRst(ListWdbeQPrcPrc1NVariable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcPrc1NVariable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcPrc1NVariable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcPrc1NVariable: C++ wrapper for table TblWdbeQPrcPrc1NVariable (MySQL database)
	*/
class MyTblWdbeQPrcPrc1NVariable : public TblWdbeQPrcPrc1NVariable, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcPrc1NVariable();
	~MyTblWdbeQPrcPrc1NVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcPrc1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQPrcPrc1NVariable* rec);
	void insertRst(ListWdbeQPrcPrc1NVariable& rst);
	void updateRec(WdbeQPrcPrc1NVariable* rec);
	void updateRst(ListWdbeQPrcPrc1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcPrc1NVariable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcPrc1NVariable: C++ wrapper for table TblWdbeQPrcPrc1NVariable (PgSQL database)
	*/
class PgTblWdbeQPrcPrc1NVariable : public TblWdbeQPrcPrc1NVariable, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcPrc1NVariable();
	~PgTblWdbeQPrcPrc1NVariable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcPrc1NVariable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcPrc1NVariable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcPrc1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQPrcPrc1NVariable* rec);
	void insertRst(ListWdbeQPrcPrc1NVariable& rst);
	void updateRec(WdbeQPrcPrc1NVariable* rec);
	void updateRst(ListWdbeQPrcPrc1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcPrc1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcPrc1NVariable& rst);
};
#endif

#endif

