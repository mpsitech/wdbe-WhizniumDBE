/**
	* \file WdbeQPrjPrj1NVersion.h
	* Dbs and XML wrapper for table TblWdbeQPrjPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJPRJ1NVERSION_H
#define WDBEQPRJPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrjPrj1NVersion: record of TblWdbeQPrjPrj1NVersion
	*/
class WdbeQPrjPrj1NVersion {

public:
	WdbeQPrjPrj1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint prjNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrjPrj1NVersion: recordset of TblWdbeQPrjPrj1NVersion
	*/
class ListWdbeQPrjPrj1NVersion {

public:
	ListWdbeQPrjPrj1NVersion();
	ListWdbeQPrjPrj1NVersion(const ListWdbeQPrjPrj1NVersion& src);
	~ListWdbeQPrjPrj1NVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrjPrj1NVersion* rec);

	ListWdbeQPrjPrj1NVersion& operator=(const ListWdbeQPrjPrj1NVersion& src);

public:
	std::vector<WdbeQPrjPrj1NVersion*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrjPrj1NVersion: C++ wrapper for table TblWdbeQPrjPrj1NVersion
	*/
class TblWdbeQPrjPrj1NVersion {

public:
	TblWdbeQPrjPrj1NVersion();
	virtual ~TblWdbeQPrjPrj1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjPrj1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrjPrj1NVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrjPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrjPrj1NVersion& rst, WdbeQPrjPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	virtual void insertRst(ListWdbeQPrjPrj1NVersion& rst);
	virtual void updateRec(WdbeQPrjPrj1NVersion* rec);
	virtual void updateRst(ListWdbeQPrjPrj1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjPrj1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrjPrj1NVersion: C++ wrapper for table TblWdbeQPrjPrj1NVersion (MySQL database)
	*/
class MyTblWdbeQPrjPrj1NVersion : public TblWdbeQPrjPrj1NVersion, public Sbecore::MyTable {

public:
	MyTblWdbeQPrjPrj1NVersion();
	~MyTblWdbeQPrjPrj1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQPrjPrj1NVersion* rec);
	void insertRst(ListWdbeQPrjPrj1NVersion& rst);
	void updateRec(WdbeQPrjPrj1NVersion* rec);
	void updateRst(ListWdbeQPrjPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjPrj1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrjPrj1NVersion: C++ wrapper for table TblWdbeQPrjPrj1NVersion (PgSQL database)
	*/
class PgTblWdbeQPrjPrj1NVersion : public TblWdbeQPrjPrj1NVersion, public Sbecore::PgTable {

public:
	PgTblWdbeQPrjPrj1NVersion();
	~PgTblWdbeQPrjPrj1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrjPrj1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrjPrj1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQPrjPrj1NVersion* rec);
	void insertRst(ListWdbeQPrjPrj1NVersion& rst);
	void updateRec(WdbeQPrjPrj1NVersion* rec);
	void updateRst(ListWdbeQPrjPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjPrj1NVersion& rst);
};
#endif

#endif
