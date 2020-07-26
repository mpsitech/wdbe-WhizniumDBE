/**
	* \file WdbeMCoreproject.h
	* database access for table TblWdbeMCoreproject (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMCOREPROJECT_H
#define WDBEMCOREPROJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMCoreprojectBasetype TblWdbeMCoreproject::VecVBasetype

/**
	* WdbeMCoreproject: record of TblWdbeMCoreproject
	*/
class WdbeMCoreproject {

public:
	WdbeMCoreproject(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string sref = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWdbeMCoreversion;
	std::string sref;
	std::string Title;
	std::string Giturl;
	std::string Comment;

public:
	bool operator==(const WdbeMCoreproject& comp);
	bool operator!=(const WdbeMCoreproject& comp);
};

/**
	* ListWdbeMCoreproject: recordset of TblWdbeMCoreproject
	*/
class ListWdbeMCoreproject {

public:
	ListWdbeMCoreproject();
	ListWdbeMCoreproject(const ListWdbeMCoreproject& src);
	~ListWdbeMCoreproject();

	void clear();
	unsigned int size() const;
	void append(WdbeMCoreproject* rec);

	WdbeMCoreproject* operator[](const Sbecore::uint ix);
	ListWdbeMCoreproject& operator=(const ListWdbeMCoreproject& src);
	bool operator==(const ListWdbeMCoreproject& comp);
	bool operator!=(const ListWdbeMCoreproject& comp);

public:
	std::vector<WdbeMCoreproject*> nodes;
};

/**
	* TblWdbeMCoreproject: C++ wrapper for table TblWdbeMCoreproject
	*/
class TblWdbeMCoreproject {

public:
	/**
		* VecVBasetype (full: VecWdbeVMCoreprojectBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CUSTIP = 1;
		static const Sbecore::uint MNFIP = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMCoreproject();
	virtual ~TblWdbeMCoreproject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreproject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreproject& rst);

	virtual Sbecore::ubigint insertRec(WdbeMCoreproject* rec);
	Sbecore::ubigint insertNewRec(WdbeMCoreproject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string sref = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMCoreproject& rst, WdbeMCoreproject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMCoreversion = 0, const std::string sref = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMCoreproject& rst, bool transact = false);
	virtual void updateRec(WdbeMCoreproject* rec);
	virtual void updateRst(ListWdbeMCoreproject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreproject** rec);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMCoreproject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMCoreproject: C++ wrapper for table TblWdbeMCoreproject (MySQL database)
	*/
class MyTblWdbeMCoreproject : public TblWdbeMCoreproject, public Sbecore::MyTable {

public:
	MyTblWdbeMCoreproject();
	~MyTblWdbeMCoreproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreproject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreproject& rst);

	Sbecore::ubigint insertRec(WdbeMCoreproject* rec);
	void insertRst(ListWdbeMCoreproject& rst, bool transact = false);
	void updateRec(WdbeMCoreproject* rec);
	void updateRst(ListWdbeMCoreproject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreproject** rec);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMCoreproject: C++ wrapper for table TblWdbeMCoreproject (PgSQL database)
	*/
class PgTblWdbeMCoreproject : public TblWdbeMCoreproject, public Sbecore::PgTable {

public:
	PgTblWdbeMCoreproject();
	~PgTblWdbeMCoreproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMCoreproject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMCoreproject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMCoreproject** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCoreproject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCoreproject& rst);

	Sbecore::ubigint insertRec(WdbeMCoreproject* rec);
	void insertRst(ListWdbeMCoreproject& rst, bool transact = false);
	void updateRec(WdbeMCoreproject* rec);
	void updateRst(ListWdbeMCoreproject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCoreproject** rec);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

