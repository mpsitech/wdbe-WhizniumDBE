/**
	* \file WdbeQVer1NRelease.h
	* Dbs and XML wrapper for table TblWdbeQVer1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVER1NRELEASE_H
#define WDBEQVER1NRELEASE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVer1NRelease: record of TblWdbeQVer1NRelease
	*/
class WdbeQVer1NRelease {

public:
	WdbeQVer1NRelease(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQVer1NRelease: recordset of TblWdbeQVer1NRelease
	*/
class ListWdbeQVer1NRelease {

public:
	ListWdbeQVer1NRelease();
	ListWdbeQVer1NRelease(const ListWdbeQVer1NRelease& src);
	~ListWdbeQVer1NRelease();

	void clear();
	unsigned int size() const;
	void append(WdbeQVer1NRelease* rec);

	ListWdbeQVer1NRelease& operator=(const ListWdbeQVer1NRelease& src);

public:
	std::vector<WdbeQVer1NRelease*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVer1NRelease: C++ wrapper for table TblWdbeQVer1NRelease
	*/
class TblWdbeQVer1NRelease {

public:
	TblWdbeQVer1NRelease();
	virtual ~TblWdbeQVer1NRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NRelease& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVer1NRelease* rec);
	Sbecore::ubigint insertNewRec(WdbeQVer1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVer1NRelease& rst, WdbeQVer1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVer1NRelease& rst);
	virtual void updateRec(WdbeQVer1NRelease* rec);
	virtual void updateRst(ListWdbeQVer1NRelease& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NRelease** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVer1NRelease: C++ wrapper for table TblWdbeQVer1NRelease (MySQL database)
	*/
class MyTblWdbeQVer1NRelease : public TblWdbeQVer1NRelease, public Sbecore::MyTable {

public:
	MyTblWdbeQVer1NRelease();
	~MyTblWdbeQVer1NRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NRelease* rec);
	void insertRst(ListWdbeQVer1NRelease& rst);
	void updateRec(WdbeQVer1NRelease* rec);
	void updateRst(ListWdbeQVer1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NRelease& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVer1NRelease: C++ wrapper for table TblWdbeQVer1NRelease (PgSQL database)
	*/
class PgTblWdbeQVer1NRelease : public TblWdbeQVer1NRelease, public Sbecore::PgTable {

public:
	PgTblWdbeQVer1NRelease();
	~PgTblWdbeQVer1NRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVer1NRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVer1NRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NRelease* rec);
	void insertRst(ListWdbeQVer1NRelease& rst);
	void updateRec(WdbeQVer1NRelease* rec);
	void updateRst(ListWdbeQVer1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NRelease& rst);
};
#endif

#endif

