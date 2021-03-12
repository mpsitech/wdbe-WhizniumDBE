/**
	* \file WdbeQMtpKParKey.h
	* Dbs and XML wrapper for table TblWdbeQMtpKParKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPKPARKEY_H
#define WDBEQMTPKPARKEY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpKParKey: record of TblWdbeQMtpKParKey
	*/
class WdbeQMtpKParKey {

public:
	WdbeQMtpKParKey(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

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
	* ListWdbeQMtpKParKey: recordset of TblWdbeQMtpKParKey
	*/
class ListWdbeQMtpKParKey {

public:
	ListWdbeQMtpKParKey();
	ListWdbeQMtpKParKey(const ListWdbeQMtpKParKey& src);
	~ListWdbeQMtpKParKey();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpKParKey* rec);

	ListWdbeQMtpKParKey& operator=(const ListWdbeQMtpKParKey& src);

public:
	std::vector<WdbeQMtpKParKey*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpKParKey: C++ wrapper for table TblWdbeQMtpKParKey
	*/
class TblWdbeQMtpKParKey {

public:
	TblWdbeQMtpKParKey();
	virtual ~TblWdbeQMtpKParKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKParKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKParKey& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpKParKey* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpKParKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpKParKey& rst, WdbeQMtpKParKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQMtpKParKey& rst);
	virtual void updateRec(WdbeQMtpKParKey* rec);
	virtual void updateRst(ListWdbeQMtpKParKey& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKParKey** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKParKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpKParKey: C++ wrapper for table TblWdbeQMtpKParKey (MySQL database)
	*/
class MyTblWdbeQMtpKParKey : public TblWdbeQMtpKParKey, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpKParKey();
	~MyTblWdbeQMtpKParKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKParKey& rst);

	Sbecore::ubigint insertRec(WdbeQMtpKParKey* rec);
	void insertRst(ListWdbeQMtpKParKey& rst);
	void updateRec(WdbeQMtpKParKey* rec);
	void updateRst(ListWdbeQMtpKParKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKParKey& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpKParKey: C++ wrapper for table TblWdbeQMtpKParKey (PgSQL database)
	*/
class PgTblWdbeQMtpKParKey : public TblWdbeQMtpKParKey, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpKParKey();
	~PgTblWdbeQMtpKParKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpKParKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpKParKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpKParKey& rst);

	Sbecore::ubigint insertRec(WdbeQMtpKParKey* rec);
	void insertRst(ListWdbeQMtpKParKey& rst);
	void updateRec(WdbeQMtpKParKey* rec);
	void updateRst(ListWdbeQMtpKParKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpKParKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpKParKey& rst);
};
#endif

#endif
