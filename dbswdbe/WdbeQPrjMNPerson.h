/**
	* \file WdbeQPrjMNPerson.h
	* Dbs and XML wrapper for table TblWdbeQPrjMNPerson (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPRJMNPERSON_H
#define WDBEQPRJMNPERSON_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrjMNPerson: record of TblWdbeQPrjMNPerson
	*/
class WdbeQPrjMNPerson {

public:
	WdbeQPrjMNPerson(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQPrjMNPerson: recordset of TblWdbeQPrjMNPerson
	*/
class ListWdbeQPrjMNPerson {

public:
	ListWdbeQPrjMNPerson();
	ListWdbeQPrjMNPerson(const ListWdbeQPrjMNPerson& src);
	~ListWdbeQPrjMNPerson();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrjMNPerson* rec);

	ListWdbeQPrjMNPerson& operator=(const ListWdbeQPrjMNPerson& src);

public:
	std::vector<WdbeQPrjMNPerson*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrjMNPerson: C++ wrapper for table TblWdbeQPrjMNPerson
	*/
class TblWdbeQPrjMNPerson {

public:
	TblWdbeQPrjMNPerson();
	virtual ~TblWdbeQPrjMNPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjMNPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjMNPerson& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrjMNPerson* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrjMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrjMNPerson& rst, WdbeQPrjMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQPrjMNPerson& rst);
	virtual void updateRec(WdbeQPrjMNPerson* rec);
	virtual void updateRst(ListWdbeQPrjMNPerson& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjMNPerson** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjMNPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrjMNPerson: C++ wrapper for table TblWdbeQPrjMNPerson (MySQL database)
	*/
class MyTblWdbeQPrjMNPerson : public TblWdbeQPrjMNPerson, public Sbecore::MyTable {

public:
	MyTblWdbeQPrjMNPerson();
	~MyTblWdbeQPrjMNPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjMNPerson& rst);

	Sbecore::ubigint insertRec(WdbeQPrjMNPerson* rec);
	void insertRst(ListWdbeQPrjMNPerson& rst);
	void updateRec(WdbeQPrjMNPerson* rec);
	void updateRst(ListWdbeQPrjMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjMNPerson& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrjMNPerson: C++ wrapper for table TblWdbeQPrjMNPerson (PgSQL database)
	*/
class PgTblWdbeQPrjMNPerson : public TblWdbeQPrjMNPerson, public Sbecore::PgTable {

public:
	PgTblWdbeQPrjMNPerson();
	~PgTblWdbeQPrjMNPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrjMNPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrjMNPerson& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrjMNPerson& rst);

	Sbecore::ubigint insertRec(WdbeQPrjMNPerson* rec);
	void insertRst(ListWdbeQPrjMNPerson& rst);
	void updateRec(WdbeQPrjMNPerson* rec);
	void updateRst(ListWdbeQPrjMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrjMNPerson& rst);
};
#endif

#endif

