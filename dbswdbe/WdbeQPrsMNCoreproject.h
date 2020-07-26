/**
	* \file WdbeQPrsMNCoreproject.h
	* Dbs and XML wrapper for table TblWdbeQPrsMNCoreproject (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPRSMNCOREPROJECT_H
#define WDBEQPRSMNCOREPROJECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrsMNCoreproject: record of TblWdbeQPrsMNCoreproject
	*/
class WdbeQPrsMNCoreproject {

public:
	WdbeQPrsMNCoreproject(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	std::string ftmX1Startd;
	Sbecore::uint x1Stopd;
	std::string ftmX1Stopd;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrsMNCoreproject: recordset of TblWdbeQPrsMNCoreproject
	*/
class ListWdbeQPrsMNCoreproject {

public:
	ListWdbeQPrsMNCoreproject();
	ListWdbeQPrsMNCoreproject(const ListWdbeQPrsMNCoreproject& src);
	~ListWdbeQPrsMNCoreproject();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrsMNCoreproject* rec);

	ListWdbeQPrsMNCoreproject& operator=(const ListWdbeQPrsMNCoreproject& src);

public:
	std::vector<WdbeQPrsMNCoreproject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrsMNCoreproject: C++ wrapper for table TblWdbeQPrsMNCoreproject
	*/
class TblWdbeQPrsMNCoreproject {

public:
	TblWdbeQPrsMNCoreproject();
	virtual ~TblWdbeQPrsMNCoreproject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNCoreproject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNCoreproject& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrsMNCoreproject* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrsMNCoreproject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrsMNCoreproject& rst, WdbeQPrsMNCoreproject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQPrsMNCoreproject& rst);
	virtual void updateRec(WdbeQPrsMNCoreproject* rec);
	virtual void updateRst(ListWdbeQPrsMNCoreproject& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNCoreproject** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNCoreproject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrsMNCoreproject: C++ wrapper for table TblWdbeQPrsMNCoreproject (MySQL database)
	*/
class MyTblWdbeQPrsMNCoreproject : public TblWdbeQPrsMNCoreproject, public Sbecore::MyTable {

public:
	MyTblWdbeQPrsMNCoreproject();
	~MyTblWdbeQPrsMNCoreproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNCoreproject& rst);

	Sbecore::ubigint insertRec(WdbeQPrsMNCoreproject* rec);
	void insertRst(ListWdbeQPrsMNCoreproject& rst);
	void updateRec(WdbeQPrsMNCoreproject* rec);
	void updateRst(ListWdbeQPrsMNCoreproject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNCoreproject& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrsMNCoreproject: C++ wrapper for table TblWdbeQPrsMNCoreproject (PgSQL database)
	*/
class PgTblWdbeQPrsMNCoreproject : public TblWdbeQPrsMNCoreproject, public Sbecore::PgTable {

public:
	PgTblWdbeQPrsMNCoreproject();
	~PgTblWdbeQPrsMNCoreproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrsMNCoreproject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrsMNCoreproject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNCoreproject& rst);

	Sbecore::ubigint insertRec(WdbeQPrsMNCoreproject* rec);
	void insertRst(ListWdbeQPrsMNCoreproject& rst);
	void updateRec(WdbeQPrsMNCoreproject* rec);
	void updateRst(ListWdbeQPrsMNCoreproject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNCoreproject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNCoreproject& rst);
};
#endif

#endif

