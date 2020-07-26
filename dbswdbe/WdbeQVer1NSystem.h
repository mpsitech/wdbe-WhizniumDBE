/**
	* \file WdbeQVer1NSystem.h
	* Dbs and XML wrapper for table TblWdbeQVer1NSystem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQVER1NSYSTEM_H
#define WDBEQVER1NSYSTEM_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVer1NSystem: record of TblWdbeQVer1NSystem
	*/
class WdbeQVer1NSystem {

public:
	WdbeQVer1NSystem(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQVer1NSystem: recordset of TblWdbeQVer1NSystem
	*/
class ListWdbeQVer1NSystem {

public:
	ListWdbeQVer1NSystem();
	ListWdbeQVer1NSystem(const ListWdbeQVer1NSystem& src);
	~ListWdbeQVer1NSystem();

	void clear();
	unsigned int size() const;
	void append(WdbeQVer1NSystem* rec);

	ListWdbeQVer1NSystem& operator=(const ListWdbeQVer1NSystem& src);

public:
	std::vector<WdbeQVer1NSystem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVer1NSystem: C++ wrapper for table TblWdbeQVer1NSystem
	*/
class TblWdbeQVer1NSystem {

public:
	TblWdbeQVer1NSystem();
	virtual ~TblWdbeQVer1NSystem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NSystem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NSystem& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVer1NSystem* rec);
	Sbecore::ubigint insertNewRec(WdbeQVer1NSystem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVer1NSystem& rst, WdbeQVer1NSystem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVer1NSystem& rst);
	virtual void updateRec(WdbeQVer1NSystem* rec);
	virtual void updateRst(ListWdbeQVer1NSystem& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NSystem** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NSystem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVer1NSystem: C++ wrapper for table TblWdbeQVer1NSystem (MySQL database)
	*/
class MyTblWdbeQVer1NSystem : public TblWdbeQVer1NSystem, public Sbecore::MyTable {

public:
	MyTblWdbeQVer1NSystem();
	~MyTblWdbeQVer1NSystem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NSystem& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NSystem* rec);
	void insertRst(ListWdbeQVer1NSystem& rst);
	void updateRec(WdbeQVer1NSystem* rec);
	void updateRst(ListWdbeQVer1NSystem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NSystem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVer1NSystem: C++ wrapper for table TblWdbeQVer1NSystem (PgSQL database)
	*/
class PgTblWdbeQVer1NSystem : public TblWdbeQVer1NSystem, public Sbecore::PgTable {

public:
	PgTblWdbeQVer1NSystem();
	~PgTblWdbeQVer1NSystem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVer1NSystem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVer1NSystem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NSystem& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NSystem* rec);
	void insertRst(ListWdbeQVer1NSystem& rst);
	void updateRec(WdbeQVer1NSystem* rec);
	void updateRst(ListWdbeQVer1NSystem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NSystem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NSystem& rst);
};
#endif

#endif

