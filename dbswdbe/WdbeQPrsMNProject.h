/**
	* \file WdbeQPrsMNProject.h
	* Dbs and XML wrapper for table TblWdbeQPrsMNProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRSMNPROJECT_H
#define WDBEQPRSMNPROJECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrsMNProject: record of TblWdbeQPrsMNProject
	*/
class WdbeQPrsMNProject {

public:
	WdbeQPrsMNProject(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQPrsMNProject: recordset of TblWdbeQPrsMNProject
	*/
class ListWdbeQPrsMNProject {

public:
	ListWdbeQPrsMNProject();
	ListWdbeQPrsMNProject(const ListWdbeQPrsMNProject& src);
	~ListWdbeQPrsMNProject();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrsMNProject* rec);

	ListWdbeQPrsMNProject& operator=(const ListWdbeQPrsMNProject& src);

public:
	std::vector<WdbeQPrsMNProject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrsMNProject: C++ wrapper for table TblWdbeQPrsMNProject
	*/
class TblWdbeQPrsMNProject {

public:
	TblWdbeQPrsMNProject();
	virtual ~TblWdbeQPrsMNProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNProject& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrsMNProject* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrsMNProject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrsMNProject& rst, WdbeQPrsMNProject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWdbeQPrsMNProject& rst);
	virtual void updateRec(WdbeQPrsMNProject* rec);
	virtual void updateRst(ListWdbeQPrsMNProject& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNProject** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrsMNProject: C++ wrapper for table TblWdbeQPrsMNProject (MySQL database)
	*/
class MyTblWdbeQPrsMNProject : public TblWdbeQPrsMNProject, public Sbecore::MyTable {

public:
	MyTblWdbeQPrsMNProject();
	~MyTblWdbeQPrsMNProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNProject& rst);

	Sbecore::ubigint insertRec(WdbeQPrsMNProject* rec);
	void insertRst(ListWdbeQPrsMNProject& rst);
	void updateRec(WdbeQPrsMNProject* rec);
	void updateRst(ListWdbeQPrsMNProject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNProject& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrsMNProject: C++ wrapper for table TblWdbeQPrsMNProject (PgSQL database)
	*/
class PgTblWdbeQPrsMNProject : public TblWdbeQPrsMNProject, public Sbecore::PgTable {

public:
	PgTblWdbeQPrsMNProject();
	~PgTblWdbeQPrsMNProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrsMNProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrsMNProject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsMNProject& rst);

	Sbecore::ubigint insertRec(WdbeQPrsMNProject* rec);
	void insertRst(ListWdbeQPrsMNProject& rst);
	void updateRec(WdbeQPrsMNProject* rec);
	void updateRst(ListWdbeQPrsMNProject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsMNProject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsMNProject& rst);
};
#endif

#endif

