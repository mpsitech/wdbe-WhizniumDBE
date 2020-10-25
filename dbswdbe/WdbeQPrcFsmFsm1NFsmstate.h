/**
	* \file WdbeQPrcFsmFsm1NFsmstate.h
	* Dbs and XML wrapper for table TblWdbeQPrcFsmFsm1NFsmstate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPRCFSMFSM1NFSMSTATE_H
#define WDBEQPRCFSMFSM1NFSMSTATE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcFsmFsm1NFsmstate: record of TblWdbeQPrcFsmFsm1NFsmstate
	*/
class WdbeQPrcFsmFsm1NFsmstate {

public:
	WdbeQPrcFsmFsm1NFsmstate(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint fsmNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint fsmNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrcFsmFsm1NFsmstate: recordset of TblWdbeQPrcFsmFsm1NFsmstate
	*/
class ListWdbeQPrcFsmFsm1NFsmstate {

public:
	ListWdbeQPrcFsmFsm1NFsmstate();
	ListWdbeQPrcFsmFsm1NFsmstate(const ListWdbeQPrcFsmFsm1NFsmstate& src);
	~ListWdbeQPrcFsmFsm1NFsmstate();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcFsmFsm1NFsmstate* rec);

	ListWdbeQPrcFsmFsm1NFsmstate& operator=(const ListWdbeQPrcFsmFsm1NFsmstate& src);

public:
	std::vector<WdbeQPrcFsmFsm1NFsmstate*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcFsmFsm1NFsmstate: C++ wrapper for table TblWdbeQPrcFsmFsm1NFsmstate
	*/
class TblWdbeQPrcFsmFsm1NFsmstate {

public:
	TblWdbeQPrcFsmFsm1NFsmstate();
	virtual ~TblWdbeQPrcFsmFsm1NFsmstate();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmFsm1NFsmstate** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcFsmFsm1NFsmstate** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint fsmNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcFsmFsm1NFsmstate& rst, WdbeQPrcFsmFsm1NFsmstate** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint fsmNum = 0);
	virtual void insertRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	virtual void updateRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	virtual void updateRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmFsm1NFsmstate** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcFsmFsm1NFsmstate: C++ wrapper for table TblWdbeQPrcFsmFsm1NFsmstate (MySQL database)
	*/
class MyTblWdbeQPrcFsmFsm1NFsmstate : public TblWdbeQPrcFsmFsm1NFsmstate, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcFsmFsm1NFsmstate();
	~MyTblWdbeQPrcFsmFsm1NFsmstate();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);

	Sbecore::ubigint insertRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	void insertRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	void updateRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	void updateRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcFsmFsm1NFsmstate: C++ wrapper for table TblWdbeQPrcFsmFsm1NFsmstate (PgSQL database)
	*/
class PgTblWdbeQPrcFsmFsm1NFsmstate : public TblWdbeQPrcFsmFsm1NFsmstate, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcFsmFsm1NFsmstate();
	~PgTblWdbeQPrcFsmFsm1NFsmstate();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);

	Sbecore::ubigint insertRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	void insertRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	void updateRec(WdbeQPrcFsmFsm1NFsmstate* rec);
	void updateRst(ListWdbeQPrcFsmFsm1NFsmstate& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcFsmFsm1NFsmstate** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcFsmFsm1NFsmstate& rst);
};
#endif

#endif

