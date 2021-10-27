/**
	* \file WdbeQModRef1NVariable.h
	* Dbs and XML wrapper for table TblWdbeQModRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NVARIABLE_H
#define WDBEQMODREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModRef1NVariable: record of TblWdbeQModRef1NVariable
	*/
class WdbeQModRef1NVariable {

public:
	WdbeQModRef1NVariable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQModRef1NVariable: recordset of TblWdbeQModRef1NVariable
	*/
class ListWdbeQModRef1NVariable {

public:
	ListWdbeQModRef1NVariable();
	ListWdbeQModRef1NVariable(const ListWdbeQModRef1NVariable& src);
	~ListWdbeQModRef1NVariable();

	void clear();
	unsigned int size() const;
	void append(WdbeQModRef1NVariable* rec);

	ListWdbeQModRef1NVariable& operator=(const ListWdbeQModRef1NVariable& src);

public:
	std::vector<WdbeQModRef1NVariable*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModRef1NVariable: C++ wrapper for table TblWdbeQModRef1NVariable
	*/
class TblWdbeQModRef1NVariable {

public:
	TblWdbeQModRef1NVariable();
	virtual ~TblWdbeQModRef1NVariable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NVariable& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModRef1NVariable* rec);
	Sbecore::ubigint insertNewRec(WdbeQModRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModRef1NVariable& rst, WdbeQModRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQModRef1NVariable& rst);
	virtual void updateRec(WdbeQModRef1NVariable* rec);
	virtual void updateRst(ListWdbeQModRef1NVariable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NVariable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModRef1NVariable: C++ wrapper for table TblWdbeQModRef1NVariable (MySQL database)
	*/
class MyTblWdbeQModRef1NVariable : public TblWdbeQModRef1NVariable, public Sbecore::MyTable {

public:
	MyTblWdbeQModRef1NVariable();
	~MyTblWdbeQModRef1NVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NVariable* rec);
	void insertRst(ListWdbeQModRef1NVariable& rst);
	void updateRec(WdbeQModRef1NVariable* rec);
	void updateRst(ListWdbeQModRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NVariable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModRef1NVariable: C++ wrapper for table TblWdbeQModRef1NVariable (PgSQL database)
	*/
class PgTblWdbeQModRef1NVariable : public TblWdbeQModRef1NVariable, public Sbecore::PgTable {

public:
	PgTblWdbeQModRef1NVariable();
	~PgTblWdbeQModRef1NVariable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModRef1NVariable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModRef1NVariable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NVariable* rec);
	void insertRst(ListWdbeQModRef1NVariable& rst);
	void updateRec(WdbeQModRef1NVariable* rec);
	void updateRst(ListWdbeQModRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NVariable& rst);
};
#endif

#endif
