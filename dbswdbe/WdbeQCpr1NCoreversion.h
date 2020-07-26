/**
	* \file WdbeQCpr1NCoreversion.h
	* Dbs and XML wrapper for table TblWdbeQCpr1NCoreversion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQCPR1NCOREVERSION_H
#define WDBEQCPR1NCOREVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCpr1NCoreversion: record of TblWdbeQCpr1NCoreversion
	*/
class WdbeQCpr1NCoreversion {

public:
	WdbeQCpr1NCoreversion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQCpr1NCoreversion: recordset of TblWdbeQCpr1NCoreversion
	*/
class ListWdbeQCpr1NCoreversion {

public:
	ListWdbeQCpr1NCoreversion();
	ListWdbeQCpr1NCoreversion(const ListWdbeQCpr1NCoreversion& src);
	~ListWdbeQCpr1NCoreversion();

	void clear();
	unsigned int size() const;
	void append(WdbeQCpr1NCoreversion* rec);

	ListWdbeQCpr1NCoreversion& operator=(const ListWdbeQCpr1NCoreversion& src);

public:
	std::vector<WdbeQCpr1NCoreversion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCpr1NCoreversion: C++ wrapper for table TblWdbeQCpr1NCoreversion
	*/
class TblWdbeQCpr1NCoreversion {

public:
	TblWdbeQCpr1NCoreversion();
	virtual ~TblWdbeQCpr1NCoreversion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCpr1NCoreversion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCpr1NCoreversion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCpr1NCoreversion* rec);
	Sbecore::ubigint insertNewRec(WdbeQCpr1NCoreversion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCpr1NCoreversion& rst, WdbeQCpr1NCoreversion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQCpr1NCoreversion& rst);
	virtual void updateRec(WdbeQCpr1NCoreversion* rec);
	virtual void updateRst(ListWdbeQCpr1NCoreversion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCpr1NCoreversion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCpr1NCoreversion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCpr1NCoreversion: C++ wrapper for table TblWdbeQCpr1NCoreversion (MySQL database)
	*/
class MyTblWdbeQCpr1NCoreversion : public TblWdbeQCpr1NCoreversion, public Sbecore::MyTable {

public:
	MyTblWdbeQCpr1NCoreversion();
	~MyTblWdbeQCpr1NCoreversion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCpr1NCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeQCpr1NCoreversion* rec);
	void insertRst(ListWdbeQCpr1NCoreversion& rst);
	void updateRec(WdbeQCpr1NCoreversion* rec);
	void updateRst(ListWdbeQCpr1NCoreversion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCpr1NCoreversion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCpr1NCoreversion: C++ wrapper for table TblWdbeQCpr1NCoreversion (PgSQL database)
	*/
class PgTblWdbeQCpr1NCoreversion : public TblWdbeQCpr1NCoreversion, public Sbecore::PgTable {

public:
	PgTblWdbeQCpr1NCoreversion();
	~PgTblWdbeQCpr1NCoreversion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCpr1NCoreversion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCpr1NCoreversion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCpr1NCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeQCpr1NCoreversion* rec);
	void insertRst(ListWdbeQCpr1NCoreversion& rst);
	void updateRec(WdbeQCpr1NCoreversion* rec);
	void updateRst(ListWdbeQCpr1NCoreversion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCpr1NCoreversion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCpr1NCoreversion& rst);
};
#endif

#endif

