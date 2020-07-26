/**
	* \file WdbeQSysSys1NTarget.h
	* Dbs and XML wrapper for table TblWdbeQSysSys1NTarget (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSYSSYS1NTARGET_H
#define WDBEQSYSSYS1NTARGET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSysSys1NTarget: record of TblWdbeQSysSys1NTarget
	*/
class WdbeQSysSys1NTarget {

public:
	WdbeQSysSys1NTarget(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint sysNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint sysNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSysSys1NTarget: recordset of TblWdbeQSysSys1NTarget
	*/
class ListWdbeQSysSys1NTarget {

public:
	ListWdbeQSysSys1NTarget();
	ListWdbeQSysSys1NTarget(const ListWdbeQSysSys1NTarget& src);
	~ListWdbeQSysSys1NTarget();

	void clear();
	unsigned int size() const;
	void append(WdbeQSysSys1NTarget* rec);

	ListWdbeQSysSys1NTarget& operator=(const ListWdbeQSysSys1NTarget& src);

public:
	std::vector<WdbeQSysSys1NTarget*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSysSys1NTarget: C++ wrapper for table TblWdbeQSysSys1NTarget
	*/
class TblWdbeQSysSys1NTarget {

public:
	TblWdbeQSysSys1NTarget();
	virtual ~TblWdbeQSysSys1NTarget();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSysSys1NTarget** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysSys1NTarget& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSysSys1NTarget* rec);
	Sbecore::ubigint insertNewRec(WdbeQSysSys1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint sysNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSysSys1NTarget& rst, WdbeQSysSys1NTarget** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint sysNum = 0);
	virtual void insertRst(ListWdbeQSysSys1NTarget& rst);
	virtual void updateRec(WdbeQSysSys1NTarget* rec);
	virtual void updateRst(ListWdbeQSysSys1NTarget& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysSys1NTarget** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysSys1NTarget& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSysSys1NTarget: C++ wrapper for table TblWdbeQSysSys1NTarget (MySQL database)
	*/
class MyTblWdbeQSysSys1NTarget : public TblWdbeQSysSys1NTarget, public Sbecore::MyTable {

public:
	MyTblWdbeQSysSys1NTarget();
	~MyTblWdbeQSysSys1NTarget();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysSys1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQSysSys1NTarget* rec);
	void insertRst(ListWdbeQSysSys1NTarget& rst);
	void updateRec(WdbeQSysSys1NTarget* rec);
	void updateRst(ListWdbeQSysSys1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysSys1NTarget& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSysSys1NTarget: C++ wrapper for table TblWdbeQSysSys1NTarget (PgSQL database)
	*/
class PgTblWdbeQSysSys1NTarget : public TblWdbeQSysSys1NTarget, public Sbecore::PgTable {

public:
	PgTblWdbeQSysSys1NTarget();
	~PgTblWdbeQSysSys1NTarget();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSysSys1NTarget& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSysSys1NTarget& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSysSys1NTarget& rst);

	Sbecore::ubigint insertRec(WdbeQSysSys1NTarget* rec);
	void insertRst(ListWdbeQSysSys1NTarget& rst);
	void updateRec(WdbeQSysSys1NTarget* rec);
	void updateRst(ListWdbeQSysSys1NTarget& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSysSys1NTarget** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSysSys1NTarget& rst);
};
#endif

#endif

