/**
	* \file WdbeQCprMNPerson.h
	* Dbs and XML wrapper for table TblWdbeQCprMNPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCPRMNPERSON_H
#define WDBEQCPRMNPERSON_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCprMNPerson: record of TblWdbeQCprMNPerson
	*/
class WdbeQCprMNPerson {

public:
	WdbeQCprMNPerson(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQCprMNPerson: recordset of TblWdbeQCprMNPerson
	*/
class ListWdbeQCprMNPerson {

public:
	ListWdbeQCprMNPerson();
	ListWdbeQCprMNPerson(const ListWdbeQCprMNPerson& src);
	~ListWdbeQCprMNPerson();

	void clear();
	unsigned int size() const;
	void append(WdbeQCprMNPerson* rec);

	ListWdbeQCprMNPerson& operator=(const ListWdbeQCprMNPerson& src);

public:
	std::vector<WdbeQCprMNPerson*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCprMNPerson: C++ wrapper for table TblWdbeQCprMNPerson
	*/
class TblWdbeQCprMNPerson {

public:
	TblWdbeQCprMNPerson();
	virtual ~TblWdbeQCprMNPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCprMNPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprMNPerson& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCprMNPerson* rec);
	Sbecore::ubigint insertNewRec(WdbeQCprMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCprMNPerson& rst, WdbeQCprMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQCprMNPerson& rst);
	virtual void updateRec(WdbeQCprMNPerson* rec);
	virtual void updateRst(ListWdbeQCprMNPerson& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprMNPerson** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprMNPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCprMNPerson: C++ wrapper for table TblWdbeQCprMNPerson (MySQL database)
	*/
class MyTblWdbeQCprMNPerson : public TblWdbeQCprMNPerson, public Sbecore::MyTable {

public:
	MyTblWdbeQCprMNPerson();
	~MyTblWdbeQCprMNPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprMNPerson& rst);

	Sbecore::ubigint insertRec(WdbeQCprMNPerson* rec);
	void insertRst(ListWdbeQCprMNPerson& rst);
	void updateRec(WdbeQCprMNPerson* rec);
	void updateRst(ListWdbeQCprMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprMNPerson& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCprMNPerson: C++ wrapper for table TblWdbeQCprMNPerson (PgSQL database)
	*/
class PgTblWdbeQCprMNPerson : public TblWdbeQCprMNPerson, public Sbecore::PgTable {

public:
	PgTblWdbeQCprMNPerson();
	~PgTblWdbeQCprMNPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCprMNPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCprMNPerson& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCprMNPerson& rst);

	Sbecore::ubigint insertRec(WdbeQCprMNPerson* rec);
	void insertRst(ListWdbeQCprMNPerson& rst);
	void updateRec(WdbeQCprMNPerson* rec);
	void updateRst(ListWdbeQCprMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCprMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCprMNPerson& rst);
};
#endif

#endif
