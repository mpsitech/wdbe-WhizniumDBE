/**
	* \file WdbeQPrcKHdltype.h
	* Dbs and XML wrapper for table TblWdbeQPrcKHdltype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCKHDLTYPE_H
#define WDBEQPRCKHDLTYPE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcKHdltype: record of TblWdbeQPrcKHdltype
	*/
class WdbeQPrcKHdltype {

public:
	WdbeQPrcKHdltype(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint klsNum;
	bool Fixed;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcKHdltype: recordset of TblWdbeQPrcKHdltype
	*/
class ListWdbeQPrcKHdltype {

public:
	ListWdbeQPrcKHdltype();
	ListWdbeQPrcKHdltype(const ListWdbeQPrcKHdltype& src);
	~ListWdbeQPrcKHdltype();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcKHdltype* rec);

	ListWdbeQPrcKHdltype& operator=(const ListWdbeQPrcKHdltype& src);

public:
	std::vector<WdbeQPrcKHdltype*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcKHdltype: C++ wrapper for table TblWdbeQPrcKHdltype
	*/
class TblWdbeQPrcKHdltype {

public:
	TblWdbeQPrcKHdltype();
	virtual ~TblWdbeQPrcKHdltype();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcKHdltype** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcKHdltype& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcKHdltype* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcKHdltype& rst, WdbeQPrcKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQPrcKHdltype& rst);
	virtual void updateRec(WdbeQPrcKHdltype* rec);
	virtual void updateRst(ListWdbeQPrcKHdltype& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcKHdltype** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcKHdltype& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcKHdltype: C++ wrapper for table TblWdbeQPrcKHdltype (MySQL database)
	*/
class MyTblWdbeQPrcKHdltype : public TblWdbeQPrcKHdltype, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcKHdltype();
	~MyTblWdbeQPrcKHdltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQPrcKHdltype* rec);
	void insertRst(ListWdbeQPrcKHdltype& rst);
	void updateRec(WdbeQPrcKHdltype* rec);
	void updateRst(ListWdbeQPrcKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcKHdltype& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcKHdltype: C++ wrapper for table TblWdbeQPrcKHdltype (PgSQL database)
	*/
class PgTblWdbeQPrcKHdltype : public TblWdbeQPrcKHdltype, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcKHdltype();
	~PgTblWdbeQPrcKHdltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcKHdltype& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcKHdltype& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQPrcKHdltype* rec);
	void insertRst(ListWdbeQPrcKHdltype& rst);
	void updateRec(WdbeQPrcKHdltype* rec);
	void updateRst(ListWdbeQPrcKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcKHdltype& rst);
};
#endif

#endif
