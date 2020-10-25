/**
	* \file WdbeQMch1NRelease.h
	* Dbs and XML wrapper for table TblWdbeQMch1NRelease (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMCH1NRELEASE_H
#define WDBEQMCH1NRELEASE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMch1NRelease: record of TblWdbeQMch1NRelease
	*/
class WdbeQMch1NRelease {

public:
	WdbeQMch1NRelease(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMch1NRelease: recordset of TblWdbeQMch1NRelease
	*/
class ListWdbeQMch1NRelease {

public:
	ListWdbeQMch1NRelease();
	ListWdbeQMch1NRelease(const ListWdbeQMch1NRelease& src);
	~ListWdbeQMch1NRelease();

	void clear();
	unsigned int size() const;
	void append(WdbeQMch1NRelease* rec);

	ListWdbeQMch1NRelease& operator=(const ListWdbeQMch1NRelease& src);

public:
	std::vector<WdbeQMch1NRelease*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMch1NRelease: C++ wrapper for table TblWdbeQMch1NRelease
	*/
class TblWdbeQMch1NRelease {

public:
	TblWdbeQMch1NRelease();
	virtual ~TblWdbeQMch1NRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMch1NRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMch1NRelease& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMch1NRelease* rec);
	Sbecore::ubigint insertNewRec(WdbeQMch1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMch1NRelease& rst, WdbeQMch1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMch1NRelease& rst);
	virtual void updateRec(WdbeQMch1NRelease* rec);
	virtual void updateRst(ListWdbeQMch1NRelease& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMch1NRelease** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMch1NRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMch1NRelease: C++ wrapper for table TblWdbeQMch1NRelease (MySQL database)
	*/
class MyTblWdbeQMch1NRelease : public TblWdbeQMch1NRelease, public Sbecore::MyTable {

public:
	MyTblWdbeQMch1NRelease();
	~MyTblWdbeQMch1NRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMch1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQMch1NRelease* rec);
	void insertRst(ListWdbeQMch1NRelease& rst);
	void updateRec(WdbeQMch1NRelease* rec);
	void updateRst(ListWdbeQMch1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMch1NRelease& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMch1NRelease: C++ wrapper for table TblWdbeQMch1NRelease (PgSQL database)
	*/
class PgTblWdbeQMch1NRelease : public TblWdbeQMch1NRelease, public Sbecore::PgTable {

public:
	PgTblWdbeQMch1NRelease();
	~PgTblWdbeQMch1NRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMch1NRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMch1NRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMch1NRelease& rst);

	Sbecore::ubigint insertRec(WdbeQMch1NRelease* rec);
	void insertRst(ListWdbeQMch1NRelease& rst);
	void updateRec(WdbeQMch1NRelease* rec);
	void updateRst(ListWdbeQMch1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMch1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMch1NRelease& rst);
};
#endif

#endif

