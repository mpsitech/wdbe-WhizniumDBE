/**
	* \file WdbeQPrj1NVersion.h
	* Dbs and XML wrapper for table TblWdbeQPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJ1NVERSION_H
#define WDBEQPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrj1NVersion: record of TblWdbeQPrj1NVersion
	*/
class WdbeQPrj1NVersion {

public:
	WdbeQPrj1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQPrj1NVersion: recordset of TblWdbeQPrj1NVersion
	*/
class ListWdbeQPrj1NVersion {

public:
	ListWdbeQPrj1NVersion();
	ListWdbeQPrj1NVersion(const ListWdbeQPrj1NVersion& src);
	~ListWdbeQPrj1NVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrj1NVersion* rec);

	ListWdbeQPrj1NVersion& operator=(const ListWdbeQPrj1NVersion& src);

public:
	std::vector<WdbeQPrj1NVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrj1NVersion: C++ wrapper for table TblWdbeQPrj1NVersion
	*/
class TblWdbeQPrj1NVersion {

public:
	TblWdbeQPrj1NVersion();
	virtual ~TblWdbeQPrj1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrj1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrj1NVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrj1NVersion& rst, WdbeQPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQPrj1NVersion& rst);
	virtual void updateRec(WdbeQPrj1NVersion* rec);
	virtual void updateRst(ListWdbeQPrj1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrj1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrj1NVersion: C++ wrapper for table TblWdbeQPrj1NVersion (MySQL database)
	*/
class MyTblWdbeQPrj1NVersion : public TblWdbeQPrj1NVersion, public Sbecore::MyTable {

public:
	MyTblWdbeQPrj1NVersion();
	~MyTblWdbeQPrj1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQPrj1NVersion* rec);
	void insertRst(ListWdbeQPrj1NVersion& rst);
	void updateRec(WdbeQPrj1NVersion* rec);
	void updateRst(ListWdbeQPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrj1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrj1NVersion: C++ wrapper for table TblWdbeQPrj1NVersion (PgSQL database)
	*/
class PgTblWdbeQPrj1NVersion : public TblWdbeQPrj1NVersion, public Sbecore::PgTable {

public:
	PgTblWdbeQPrj1NVersion();
	~PgTblWdbeQPrj1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrj1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrj1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WdbeQPrj1NVersion* rec);
	void insertRst(ListWdbeQPrj1NVersion& rst);
	void updateRec(WdbeQPrj1NVersion* rec);
	void updateRst(ListWdbeQPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrj1NVersion& rst);
};
#endif

#endif

