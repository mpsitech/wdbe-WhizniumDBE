/**
	* \file WdbeMUser.h
	* database access for table TblWdbeMUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMUSER_H
#define WDBEMUSER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMUserState TblWdbeMUser::VecVState

/**
	* WdbeMUser: record of TblWdbeMUser
	*/
class WdbeMUser {

public:
	WdbeMUser(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWdbeVLocale = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refRUsergroup;
	Sbecore::ubigint refWdbeMUsergroup;
	Sbecore::ubigint refWdbeMPerson;
	std::string sref;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWdbeVLocale;
	Sbecore::uint ixWdbeVUserlevel;
	std::string Password;
	std::string Fullkey;
	std::string Comment;

public:
	bool operator==(const WdbeMUser& comp);
	bool operator!=(const WdbeMUser& comp);
};

/**
	* ListWdbeMUser: recordset of TblWdbeMUser
	*/
class ListWdbeMUser {

public:
	ListWdbeMUser();
	ListWdbeMUser(const ListWdbeMUser& src);
	~ListWdbeMUser();

	void clear();
	unsigned int size() const;
	void append(WdbeMUser* rec);

	WdbeMUser* operator[](const Sbecore::uint ix);
	ListWdbeMUser& operator=(const ListWdbeMUser& src);
	bool operator==(const ListWdbeMUser& comp);
	bool operator!=(const ListWdbeMUser& comp);

public:
	std::vector<WdbeMUser*> nodes;
};

/**
	* TblWdbeMUser: C++ wrapper for table TblWdbeMUser
	*/
class TblWdbeMUser {

public:
	/**
		* VecVState (full: VecWdbeVMUserState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint ACT = 1;
		static const Sbecore::uint DSG = 2;
		static const Sbecore::uint DUE = 3;
		static const Sbecore::uint EXP = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeMUser();
	virtual ~TblWdbeMUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUser& rst);

	virtual Sbecore::ubigint insertRec(WdbeMUser* rec);
	Sbecore::ubigint insertNewRec(WdbeMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWdbeVLocale = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMUser& rst, WdbeMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWdbeMUsergroup = 0, const Sbecore::ubigint refWdbeMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWdbeVLocale = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMUser& rst, bool transact = false);
	virtual void updateRec(WdbeMUser* rec);
	virtual void updateRst(ListWdbeMUser& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMUser** rec);
	virtual bool loadRecByPrs(Sbecore::ubigint refWdbeMPerson, WdbeMUser** rec);
	virtual bool loadRecBySrf(std::string sref, WdbeMUser** rec);
	virtual bool loadRecBySrfPwd(std::string sref, std::string Password, WdbeMUser** rec);
	virtual bool loadRefByPrs(Sbecore::ubigint refWdbeMPerson, Sbecore::ubigint& ref);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMUser: C++ wrapper for table TblWdbeMUser (MySQL database)
	*/
class MyTblWdbeMUser : public TblWdbeMUser, public Sbecore::MyTable {

public:
	MyTblWdbeMUser();
	~MyTblWdbeMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUser& rst);

	Sbecore::ubigint insertRec(WdbeMUser* rec);
	void insertRst(ListWdbeMUser& rst, bool transact = false);
	void updateRec(WdbeMUser* rec);
	void updateRst(ListWdbeMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWdbeMPerson, WdbeMUser** rec);
	bool loadRecBySrf(std::string sref, WdbeMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WdbeMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWdbeMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMUser: C++ wrapper for table TblWdbeMUser (PgSQL database)
	*/
class PgTblWdbeMUser : public TblWdbeMUser, public Sbecore::PgTable {

public:
	PgTblWdbeMUser();
	~PgTblWdbeMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMUser& rst);

	Sbecore::ubigint insertRec(WdbeMUser* rec);
	void insertRst(ListWdbeMUser& rst, bool transact = false);
	void updateRec(WdbeMUser* rec);
	void updateRst(ListWdbeMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWdbeMPerson, WdbeMUser** rec);
	bool loadRecBySrf(std::string sref, WdbeMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WdbeMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWdbeMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWdbeMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
