/**
	* \file WdbeQCmp1NRelease.h
	* Dbs and XML wrapper for table TblWdbeQCmp1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMP1NRELEASE_H
#define WDBEQCMP1NRELEASE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmp1NRelease: record of TblWdbeQCmp1NRelease
	*/
class WdbeQCmp1NRelease {

public:
	WdbeQCmp1NRelease(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmp1NRelease: recordset of TblWdbeQCmp1NRelease
	*/
class ListWdbeQCmp1NRelease {

public:
	ListWdbeQCmp1NRelease();
	ListWdbeQCmp1NRelease(const ListWdbeQCmp1NRelease& src);
	~ListWdbeQCmp1NRelease();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmp1NRelease* rec);

	ListWdbeQCmp1NRelease& operator=(const ListWdbeQCmp1NRelease& src);

public:
	std::vector<WdbeQCmp1NRelease*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmp1NRelease: C++ wrapper for table TblWdbeQCmp1NRelease
	*/
class TblWdbeQCmp1NRelease {

public:
	TblWdbeQCmp1NRelease();
	virtual ~TblWdbeQCmp1NRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmp1NRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmp1NRelease& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmp1NRelease* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmp1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmp1NRelease& rst, WdbeQCmp1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQCmp1NRelease& rst);
	virtual void updateRec(WdbeQCmp1NRelease* rec);
	virtual void updateRst(ListWdbeQCmp1NRelease& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmp1NRelease** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmp1NRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmp1NRelease: C++ wrapper for table TblWdbeQCmp1NRelease (MySQL database)
	*/
class MyTblWdbeQCmp1NRelease : public TblWdbeQCmp1NRelease, public Sbecore::MyTable {

public:
	MyTblWdbeQCmp1NRelease();
	~MyTblWdbeQCmp1NRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmp1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQCmp1NRelease* rec);
	void insertRst(ListWdbeQCmp1NRelease& rst);
	void updateRec(WdbeQCmp1NRelease* rec);
	void updateRst(ListWdbeQCmp1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmp1NRelease& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmp1NRelease: C++ wrapper for table TblWdbeQCmp1NRelease (PgSQL database)
	*/
class PgTblWdbeQCmp1NRelease : public TblWdbeQCmp1NRelease, public Sbecore::PgTable {

public:
	PgTblWdbeQCmp1NRelease();
	~PgTblWdbeQCmp1NRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmp1NRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmp1NRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmp1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQCmp1NRelease* rec);
	void insertRst(ListWdbeQCmp1NRelease& rst);
	void updateRec(WdbeQCmp1NRelease* rec);
	void updateRst(ListWdbeQCmp1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmp1NRelease& rst);
};
#endif

#endif
