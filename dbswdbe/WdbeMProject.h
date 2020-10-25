/**
	* \file WdbeMProject.h
	* database access for table TblWdbeMProject (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMPROJECT_H
#define WDBEMPROJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMProject: record of TblWdbeMProject
	*/
class WdbeMProject {

public:
	WdbeMProject(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string Short = "", const std::string Title = "", const bool Easy = false, const std::string Giturl = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWdbeMVersion;
	std::string Short;
	std::string Title;
	bool Easy;
	std::string Giturl;
	std::string Comment;

public:
	bool operator==(const WdbeMProject& comp);
	bool operator!=(const WdbeMProject& comp);
};

/**
	* ListWdbeMProject: recordset of TblWdbeMProject
	*/
class ListWdbeMProject {

public:
	ListWdbeMProject();
	ListWdbeMProject(const ListWdbeMProject& src);
	~ListWdbeMProject();

	void clear();
	unsigned int size() const;
	void append(WdbeMProject* rec);

	WdbeMProject* operator[](const Sbecore::uint ix);
	ListWdbeMProject& operator=(const ListWdbeMProject& src);
	bool operator==(const ListWdbeMProject& comp);
	bool operator!=(const ListWdbeMProject& comp);

public:
	std::vector<WdbeMProject*> nodes;
};

/**
	* TblWdbeMProject: C++ wrapper for table TblWdbeMProject
	*/
class TblWdbeMProject {

public:

public:
	TblWdbeMProject();
	virtual ~TblWdbeMProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProject& rst);

	virtual Sbecore::ubigint insertRec(WdbeMProject* rec);
	Sbecore::ubigint insertNewRec(WdbeMProject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string Short = "", const std::string Title = "", const bool Easy = false, const std::string Giturl = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMProject& rst, WdbeMProject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string Short = "", const std::string Title = "", const bool Easy = false, const std::string Giturl = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMProject& rst, bool transact = false);
	virtual void updateRec(WdbeMProject* rec);
	virtual void updateRst(ListWdbeMProject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMProject** rec);
	virtual bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMProject: C++ wrapper for table TblWdbeMProject (MySQL database)
	*/
class MyTblWdbeMProject : public TblWdbeMProject, public Sbecore::MyTable {

public:
	MyTblWdbeMProject();
	~MyTblWdbeMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProject& rst);

	Sbecore::ubigint insertRec(WdbeMProject* rec);
	void insertRst(ListWdbeMProject& rst, bool transact = false);
	void updateRec(WdbeMProject* rec);
	void updateRst(ListWdbeMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMProject** rec);
	bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMProject: C++ wrapper for table TblWdbeMProject (PgSQL database)
	*/
class PgTblWdbeMProject : public TblWdbeMProject, public Sbecore::PgTable {

public:
	PgTblWdbeMProject();
	~PgTblWdbeMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMProject** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMProject& rst);

	Sbecore::ubigint insertRec(WdbeMProject* rec);
	void insertRst(ListWdbeMProject& rst, bool transact = false);
	void updateRec(WdbeMProject* rec);
	void updateRst(ListWdbeMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMProject** rec);
	bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

