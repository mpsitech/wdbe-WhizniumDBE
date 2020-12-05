/**
	* \file WdbeQUnt1NTarget.h
	* Dbs and XML wrapper for table TblWdbeQUnt1NTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNT1NTARGET_H
#define WDBEQUNT1NTARGET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUnt1NTarget: record of TblWdbeQUnt1NTarget
	*/
class WdbeQUnt1NTarget {

public:
	WdbeQUnt1NTarget(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUnt1NTarget: recordset of TblWdbeQUnt1NTarget
	*/
class ListWdbeQUnt1NTarget {

public:
	ListWdbeQUnt1NTarget();
	ListWdbeQUnt1NTarget(const ListWdbeQUnt1NTarget& src);
	~ListWdbeQUnt1NTarget();

	void clear();
	unsigned int size() const;
	void append(WdbeQUnt1NTarget* rec);

	ListWdbeQUnt1NTarget& operator=(const ListWdbeQUnt1NTarget& src);

public:
	std::vector<WdbeQUnt1NTarget*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUnt1NTarget: C++ wrapper for table TblWdbeQUnt1NTarget
	*/
class TblWdbeQUnt1NTarget {

public:
	TblWdbeQUnt1NTarget();
	virtual ~TblWdbeQUnt1NTarget();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NTarget** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NTarget& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUnt1NTarget* rec);
	Sbecore::ubigint insertNewRec(WdbeQUnt1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUnt1NTarget& rst, WdbeQUnt1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUnt1NTarget& rst);
	virtual void updateRec(WdbeQUnt1NTarget* rec);
	virtual void updateRst(ListWdbeQUnt1NTarget& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NTarget** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NTarget& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUnt1NTarget: C++ wrapper for table TblWdbeQUnt1NTarget (MySQL database)
	*/
class MyTblWdbeQUnt1NTarget : public TblWdbeQUnt1NTarget, public Sbecore::MyTable {

public:
	MyTblWdbeQUnt1NTarget();
	~MyTblWdbeQUnt1NTarget();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NTarget* rec);
	void insertRst(ListWdbeQUnt1NTarget& rst);
	void updateRec(WdbeQUnt1NTarget* rec);
	void updateRst(ListWdbeQUnt1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NTarget& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUnt1NTarget: C++ wrapper for table TblWdbeQUnt1NTarget (PgSQL database)
	*/
class PgTblWdbeQUnt1NTarget : public TblWdbeQUnt1NTarget, public Sbecore::PgTable {

public:
	PgTblWdbeQUnt1NTarget();
	~PgTblWdbeQUnt1NTarget();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUnt1NTarget& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUnt1NTarget& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NTarget* rec);
	void insertRst(ListWdbeQUnt1NTarget& rst);
	void updateRec(WdbeQUnt1NTarget* rec);
	void updateRst(ListWdbeQUnt1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NTarget& rst);
};
#endif

#endif

