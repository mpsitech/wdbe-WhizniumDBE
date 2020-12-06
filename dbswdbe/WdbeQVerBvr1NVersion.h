/**
	* \file WdbeQVerBvr1NVersion.h
	* Dbs and XML wrapper for table TblWdbeQVerBvr1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVERBVR1NVERSION_H
#define WDBEQVERBVR1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVerBvr1NVersion: record of TblWdbeQVerBvr1NVersion
	*/
class WdbeQVerBvr1NVersion {

public:
	WdbeQVerBvr1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQVerBvr1NVersion: recordset of TblWdbeQVerBvr1NVersion
	*/
class ListWdbeQVerBvr1NVersion {

public:
	ListWdbeQVerBvr1NVersion();
	ListWdbeQVerBvr1NVersion(const ListWdbeQVerBvr1NVersion& src);
	~ListWdbeQVerBvr1NVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeQVerBvr1NVersion* rec);

	ListWdbeQVerBvr1NVersion& operator=(const ListWdbeQVerBvr1NVersion& src);

public:
	std::vector<WdbeQVerBvr1NVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVerBvr1NVersion: C++ wrapper for table TblWdbeQVerBvr1NVersion
	*/
class TblWdbeQVerBvr1NVersion {

public:
	TblWdbeQVerBvr1NVersion();
	virtual ~TblWdbeQVerBvr1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVerBvr1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerBvr1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVerBvr1NVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeQVerBvr1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVerBvr1NVersion& rst, WdbeQVerBvr1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVerBvr1NVersion& rst);
	virtual void updateRec(WdbeQVerBvr1NVersion* rec);
	virtual void updateRst(ListWdbeQVerBvr1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerBvr1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerBvr1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVerBvr1NVersion: C++ wrapper for table TblWdbeQVerBvr1NVersion (MySQL database)
	*/
class MyTblWdbeQVerBvr1NVersion : public TblWdbeQVerBvr1NVersion, public Sbecore::MyTable {

public:
	MyTblWdbeQVerBvr1NVersion();
	~MyTblWdbeQVerBvr1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerBvr1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQVerBvr1NVersion* rec);
	void insertRst(ListWdbeQVerBvr1NVersion& rst);
	void updateRec(WdbeQVerBvr1NVersion* rec);
	void updateRst(ListWdbeQVerBvr1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerBvr1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVerBvr1NVersion: C++ wrapper for table TblWdbeQVerBvr1NVersion (PgSQL database)
	*/
class PgTblWdbeQVerBvr1NVersion : public TblWdbeQVerBvr1NVersion, public Sbecore::PgTable {

public:
	PgTblWdbeQVerBvr1NVersion();
	~PgTblWdbeQVerBvr1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVerBvr1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVerBvr1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerBvr1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQVerBvr1NVersion* rec);
	void insertRst(ListWdbeQVerBvr1NVersion& rst);
	void updateRec(WdbeQVerBvr1NVersion* rec);
	void updateRst(ListWdbeQVerBvr1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerBvr1NVersion& rst);
};
#endif

#endif
