/**
	* \file WdbeRMPersonMProject.h
	* database access for table TblWdbeRMPersonMProject (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBERMPERSONMPROJECT_H
#define WDBERMPERSONMPROJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeRMPersonMProject: record of TblWdbeRMPersonMProject
	*/
class WdbeRMPersonMProject {

public:
	WdbeRMPersonMProject(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::ubigint refWdbeMProject = 0, const std::string srefKFunction = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	Sbecore::uint x1Stopd;
	Sbecore::ubigint refWdbeMPerson;
	Sbecore::ubigint refWdbeMProject;
	std::string srefKFunction;

public:
	bool operator==(const WdbeRMPersonMProject& comp);
	bool operator!=(const WdbeRMPersonMProject& comp);
};

/**
	* ListWdbeRMPersonMProject: recordset of TblWdbeRMPersonMProject
	*/
class ListWdbeRMPersonMProject {

public:
	ListWdbeRMPersonMProject();
	ListWdbeRMPersonMProject(const ListWdbeRMPersonMProject& src);
	~ListWdbeRMPersonMProject();

	void clear();
	unsigned int size() const;
	void append(WdbeRMPersonMProject* rec);

	WdbeRMPersonMProject* operator[](const Sbecore::uint ix);
	ListWdbeRMPersonMProject& operator=(const ListWdbeRMPersonMProject& src);
	bool operator==(const ListWdbeRMPersonMProject& comp);
	bool operator!=(const ListWdbeRMPersonMProject& comp);

public:
	std::vector<WdbeRMPersonMProject*> nodes;
};

/**
	* TblWdbeRMPersonMProject: C++ wrapper for table TblWdbeRMPersonMProject
	*/
class TblWdbeRMPersonMProject {

public:

public:
	TblWdbeRMPersonMProject();
	virtual ~TblWdbeRMPersonMProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeRMPersonMProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMPersonMProject& rst);

	virtual Sbecore::ubigint insertRec(WdbeRMPersonMProject* rec);
	Sbecore::ubigint insertNewRec(WdbeRMPersonMProject** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::ubigint refWdbeMProject = 0, const std::string srefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeRMPersonMProject& rst, WdbeRMPersonMProject** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWdbeMPerson = 0, const Sbecore::ubigint refWdbeMProject = 0, const std::string srefKFunction = "");
	virtual void insertRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	virtual void updateRec(WdbeRMPersonMProject* rec);
	virtual void updateRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeRMPersonMProject** rec);
	virtual Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeRMPersonMProject& rst);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMPersonMProject& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeRMPersonMProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeRMPersonMProject: C++ wrapper for table TblWdbeRMPersonMProject (MySQL database)
	*/
class MyTblWdbeRMPersonMProject : public TblWdbeRMPersonMProject, public Sbecore::MyTable {

public:
	MyTblWdbeRMPersonMProject();
	~MyTblWdbeRMPersonMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMPersonMProject& rst);

	Sbecore::ubigint insertRec(WdbeRMPersonMProject* rec);
	void insertRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	void updateRec(WdbeRMPersonMProject* rec);
	void updateRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeRMPersonMProject& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMPersonMProject& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeRMPersonMProject: C++ wrapper for table TblWdbeRMPersonMProject (PgSQL database)
	*/
class PgTblWdbeRMPersonMProject : public TblWdbeRMPersonMProject, public Sbecore::PgTable {

public:
	PgTblWdbeRMPersonMProject();
	~PgTblWdbeRMPersonMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeRMPersonMProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeRMPersonMProject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeRMPersonMProject& rst);

	Sbecore::ubigint insertRec(WdbeRMPersonMProject* rec);
	void insertRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	void updateRec(WdbeRMPersonMProject* rec);
	void updateRst(ListWdbeRMPersonMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeRMPersonMProject** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWdbeMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWdbeMProject, const bool append, ListWdbeRMPersonMProject& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWdbeMPerson, const bool append, ListWdbeRMPersonMProject& rst);
};
#endif

#endif

