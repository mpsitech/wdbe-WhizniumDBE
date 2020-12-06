/**
	* \file WdbeQModKHdltype.h
	* Dbs and XML wrapper for table TblWdbeQModKHdltype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODKHDLTYPE_H
#define WDBEQMODKHDLTYPE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModKHdltype: record of TblWdbeQModKHdltype
	*/
class WdbeQModKHdltype {

public:
	WdbeQModKHdltype(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModKHdltype: recordset of TblWdbeQModKHdltype
	*/
class ListWdbeQModKHdltype {

public:
	ListWdbeQModKHdltype();
	ListWdbeQModKHdltype(const ListWdbeQModKHdltype& src);
	~ListWdbeQModKHdltype();

	void clear();
	unsigned int size() const;
	void append(WdbeQModKHdltype* rec);

	ListWdbeQModKHdltype& operator=(const ListWdbeQModKHdltype& src);

public:
	std::vector<WdbeQModKHdltype*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModKHdltype: C++ wrapper for table TblWdbeQModKHdltype
	*/
class TblWdbeQModKHdltype {

public:
	TblWdbeQModKHdltype();
	virtual ~TblWdbeQModKHdltype();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModKHdltype** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModKHdltype& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModKHdltype* rec);
	Sbecore::ubigint insertNewRec(WdbeQModKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModKHdltype& rst, WdbeQModKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQModKHdltype& rst);
	virtual void updateRec(WdbeQModKHdltype* rec);
	virtual void updateRst(ListWdbeQModKHdltype& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModKHdltype** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModKHdltype& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModKHdltype: C++ wrapper for table TblWdbeQModKHdltype (MySQL database)
	*/
class MyTblWdbeQModKHdltype : public TblWdbeQModKHdltype, public Sbecore::MyTable {

public:
	MyTblWdbeQModKHdltype();
	~MyTblWdbeQModKHdltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQModKHdltype* rec);
	void insertRst(ListWdbeQModKHdltype& rst);
	void updateRec(WdbeQModKHdltype* rec);
	void updateRst(ListWdbeQModKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModKHdltype& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModKHdltype: C++ wrapper for table TblWdbeQModKHdltype (PgSQL database)
	*/
class PgTblWdbeQModKHdltype : public TblWdbeQModKHdltype, public Sbecore::PgTable {

public:
	PgTblWdbeQModKHdltype();
	~PgTblWdbeQModKHdltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModKHdltype& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModKHdltype& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQModKHdltype* rec);
	void insertRst(ListWdbeQModKHdltype& rst);
	void updateRec(WdbeQModKHdltype* rec);
	void updateRst(ListWdbeQModKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModKHdltype& rst);
};
#endif

#endif
