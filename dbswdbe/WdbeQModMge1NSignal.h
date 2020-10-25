/**
	* \file WdbeQModMge1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQModMge1NSignal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMODMGE1NSIGNAL_H
#define WDBEQMODMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModMge1NSignal: record of TblWdbeQModMge1NSignal
	*/
class WdbeQModMge1NSignal {

public:
	WdbeQModMge1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQModMge1NSignal: recordset of TblWdbeQModMge1NSignal
	*/
class ListWdbeQModMge1NSignal {

public:
	ListWdbeQModMge1NSignal();
	ListWdbeQModMge1NSignal(const ListWdbeQModMge1NSignal& src);
	~ListWdbeQModMge1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQModMge1NSignal* rec);

	ListWdbeQModMge1NSignal& operator=(const ListWdbeQModMge1NSignal& src);

public:
	std::vector<WdbeQModMge1NSignal*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModMge1NSignal: C++ wrapper for table TblWdbeQModMge1NSignal
	*/
class TblWdbeQModMge1NSignal {

public:
	TblWdbeQModMge1NSignal();
	virtual ~TblWdbeQModMge1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMge1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModMge1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQModMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModMge1NSignal& rst, WdbeQModMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModMge1NSignal& rst);
	virtual void updateRec(WdbeQModMge1NSignal* rec);
	virtual void updateRst(ListWdbeQModMge1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMge1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModMge1NSignal: C++ wrapper for table TblWdbeQModMge1NSignal (MySQL database)
	*/
class MyTblWdbeQModMge1NSignal : public TblWdbeQModMge1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQModMge1NSignal();
	~MyTblWdbeQModMge1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModMge1NSignal* rec);
	void insertRst(ListWdbeQModMge1NSignal& rst);
	void updateRec(WdbeQModMge1NSignal* rec);
	void updateRst(ListWdbeQModMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMge1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModMge1NSignal: C++ wrapper for table TblWdbeQModMge1NSignal (PgSQL database)
	*/
class PgTblWdbeQModMge1NSignal : public TblWdbeQModMge1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQModMge1NSignal();
	~PgTblWdbeQModMge1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModMge1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModMge1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModMge1NSignal* rec);
	void insertRst(ListWdbeQModMge1NSignal& rst);
	void updateRec(WdbeQModMge1NSignal* rec);
	void updateRst(ListWdbeQModMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMge1NSignal& rst);
};
#endif

#endif

