/**
	* \file WdbeQMtpKHdltype.h
	* Dbs and XML wrapper for table TblWdbeQMtpKHdltype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPKHDLTYPE_H
#define WDBEQMTPKHDLTYPE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpKHdltype: record of TblWdbeQMtpKHdltype
	*/
class WdbeQMtpKHdltype {

public:
	WdbeQMtpKHdltype(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

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
	* ListWdbeQMtpKHdltype: recordset of TblWdbeQMtpKHdltype
	*/
class ListWdbeQMtpKHdltype {

public:
	ListWdbeQMtpKHdltype();
	ListWdbeQMtpKHdltype(const ListWdbeQMtpKHdltype& src);
	~ListWdbeQMtpKHdltype();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpKHdltype* rec);

	ListWdbeQMtpKHdltype& operator=(const ListWdbeQMtpKHdltype& src);

public:
	std::vector<WdbeQMtpKHdltype*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpKHdltype: C++ wrapper for table TblWdbeQMtpKHdltype
	*/
class TblWdbeQMtpKHdltype {

public:
	TblWdbeQMtpKHdltype();
	virtual ~TblWdbeQMtpKHdltype();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKHdltype** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKHdltype& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpKHdltype* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpKHdltype& rst, WdbeQMtpKHdltype** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQMtpKHdltype& rst);
	virtual void updateRec(WdbeQMtpKHdltype* rec);
	virtual void updateRst(ListWdbeQMtpKHdltype& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKHdltype** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKHdltype& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpKHdltype: C++ wrapper for table TblWdbeQMtpKHdltype (MySQL database)
	*/
class MyTblWdbeQMtpKHdltype : public TblWdbeQMtpKHdltype, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpKHdltype();
	~MyTblWdbeQMtpKHdltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQMtpKHdltype* rec);
	void insertRst(ListWdbeQMtpKHdltype& rst);
	void updateRec(WdbeQMtpKHdltype* rec);
	void updateRst(ListWdbeQMtpKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKHdltype& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpKHdltype: C++ wrapper for table TblWdbeQMtpKHdltype (PgSQL database)
	*/
class PgTblWdbeQMtpKHdltype : public TblWdbeQMtpKHdltype, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpKHdltype();
	~PgTblWdbeQMtpKHdltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpKHdltype& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpKHdltype& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKHdltype& rst);

	Sbecore::ubigint insertRec(WdbeQMtpKHdltype* rec);
	void insertRst(ListWdbeQMtpKHdltype& rst);
	void updateRec(WdbeQMtpKHdltype* rec);
	void updateRst(ListWdbeQMtpKHdltype& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKHdltype** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKHdltype& rst);
};
#endif

#endif

