/**
	* \file WdbeQMtpRef1NVariable.h
	* Dbs and XML wrapper for table TblWdbeQMtpRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPREF1NVARIABLE_H
#define WDBEQMTPREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpRef1NVariable: record of TblWdbeQMtpRef1NVariable
	*/
class WdbeQMtpRef1NVariable {

public:
	WdbeQMtpRef1NVariable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQMtpRef1NVariable: recordset of TblWdbeQMtpRef1NVariable
	*/
class ListWdbeQMtpRef1NVariable {

public:
	ListWdbeQMtpRef1NVariable();
	ListWdbeQMtpRef1NVariable(const ListWdbeQMtpRef1NVariable& src);
	~ListWdbeQMtpRef1NVariable();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpRef1NVariable* rec);

	ListWdbeQMtpRef1NVariable& operator=(const ListWdbeQMtpRef1NVariable& src);

public:
	std::vector<WdbeQMtpRef1NVariable*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpRef1NVariable: C++ wrapper for table TblWdbeQMtpRef1NVariable
	*/
class TblWdbeQMtpRef1NVariable {

public:
	TblWdbeQMtpRef1NVariable();
	virtual ~TblWdbeQMtpRef1NVariable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NVariable& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpRef1NVariable* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpRef1NVariable& rst, WdbeQMtpRef1NVariable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQMtpRef1NVariable& rst);
	virtual void updateRec(WdbeQMtpRef1NVariable* rec);
	virtual void updateRst(ListWdbeQMtpRef1NVariable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NVariable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NVariable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpRef1NVariable: C++ wrapper for table TblWdbeQMtpRef1NVariable (MySQL database)
	*/
class MyTblWdbeQMtpRef1NVariable : public TblWdbeQMtpRef1NVariable, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpRef1NVariable();
	~MyTblWdbeQMtpRef1NVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NVariable* rec);
	void insertRst(ListWdbeQMtpRef1NVariable& rst);
	void updateRec(WdbeQMtpRef1NVariable* rec);
	void updateRst(ListWdbeQMtpRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NVariable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpRef1NVariable: C++ wrapper for table TblWdbeQMtpRef1NVariable (PgSQL database)
	*/
class PgTblWdbeQMtpRef1NVariable : public TblWdbeQMtpRef1NVariable, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpRef1NVariable();
	~PgTblWdbeQMtpRef1NVariable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpRef1NVariable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpRef1NVariable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NVariable& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NVariable* rec);
	void insertRst(ListWdbeQMtpRef1NVariable& rst);
	void updateRec(WdbeQMtpRef1NVariable* rec);
	void updateRst(ListWdbeQMtpRef1NVariable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NVariable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NVariable& rst);
};
#endif

#endif
