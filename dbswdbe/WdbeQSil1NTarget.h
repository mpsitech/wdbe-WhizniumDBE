/**
	* \file WdbeQSil1NTarget.h
	* Dbs and XML wrapper for table TblWdbeQSil1NTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NTARGET_H
#define WDBEQSIL1NTARGET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSil1NTarget: record of TblWdbeQSil1NTarget
	*/
class WdbeQSil1NTarget {

public:
	WdbeQSil1NTarget(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSil1NTarget: recordset of TblWdbeQSil1NTarget
	*/
class ListWdbeQSil1NTarget {

public:
	ListWdbeQSil1NTarget();
	ListWdbeQSil1NTarget(const ListWdbeQSil1NTarget& src);
	~ListWdbeQSil1NTarget();

	void clear();
	unsigned int size() const;
	void append(WdbeQSil1NTarget* rec);

	ListWdbeQSil1NTarget& operator=(const ListWdbeQSil1NTarget& src);

public:
	std::vector<WdbeQSil1NTarget*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSil1NTarget: C++ wrapper for table TblWdbeQSil1NTarget
	*/
class TblWdbeQSil1NTarget {

public:
	TblWdbeQSil1NTarget();
	virtual ~TblWdbeQSil1NTarget();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NTarget** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NTarget& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSil1NTarget* rec);
	Sbecore::ubigint insertNewRec(WdbeQSil1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSil1NTarget& rst, WdbeQSil1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSil1NTarget& rst);
	virtual void updateRec(WdbeQSil1NTarget* rec);
	virtual void updateRst(ListWdbeQSil1NTarget& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NTarget** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NTarget& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSil1NTarget: C++ wrapper for table TblWdbeQSil1NTarget (MySQL database)
	*/
class MyTblWdbeQSil1NTarget : public TblWdbeQSil1NTarget, public Sbecore::MyTable {

public:
	MyTblWdbeQSil1NTarget();
	~MyTblWdbeQSil1NTarget();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NTarget* rec);
	void insertRst(ListWdbeQSil1NTarget& rst);
	void updateRec(WdbeQSil1NTarget* rec);
	void updateRst(ListWdbeQSil1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NTarget& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSil1NTarget: C++ wrapper for table TblWdbeQSil1NTarget (PgSQL database)
	*/
class PgTblWdbeQSil1NTarget : public TblWdbeQSil1NTarget, public Sbecore::PgTable {

public:
	PgTblWdbeQSil1NTarget();
	~PgTblWdbeQSil1NTarget();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSil1NTarget& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSil1NTarget& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NTarget* rec);
	void insertRst(ListWdbeQSil1NTarget& rst);
	void updateRec(WdbeQSil1NTarget* rec);
	void updateRst(ListWdbeQSil1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NTarget& rst);
};
#endif

#endif

