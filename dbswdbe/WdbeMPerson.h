/**
	* \file WdbeMPerson.h
	* database access for table TblWdbeMPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMPERSON_H
#define WDBEMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMPersonSex TblWdbeMPerson::VecVSex
#define VecWdbeWMPersonDerivate TblWdbeMPerson::VecWDerivate

/**
	* WdbeMPerson: record of TblWdbeMPerson
	*/
class WdbeMPerson {

public:
	WdbeMPerson(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixWDerivate;
	Sbecore::uint ixVSex;
	std::string Title;
	std::string Firstname;
	Sbecore::ubigint refJLastname;
	std::string Lastname;
	Sbecore::ubigint telRefADetail;
	std::string telVal;
	Sbecore::ubigint emlRefADetail;
	std::string emlVal;
	std::string Salutation;

public:
	bool operator==(const WdbeMPerson& comp);
	bool operator!=(const WdbeMPerson& comp);
};

/**
	* ListWdbeMPerson: recordset of TblWdbeMPerson
	*/
class ListWdbeMPerson {

public:
	ListWdbeMPerson();
	ListWdbeMPerson(const ListWdbeMPerson& src);
	~ListWdbeMPerson();

	void clear();
	unsigned int size() const;
	void append(WdbeMPerson* rec);

	WdbeMPerson* operator[](const Sbecore::uint ix);
	ListWdbeMPerson& operator=(const ListWdbeMPerson& src);
	bool operator==(const ListWdbeMPerson& comp);
	bool operator!=(const ListWdbeMPerson& comp);

public:
	std::vector<WdbeMPerson*> nodes;
};

/**
	* TblWdbeMPerson: C++ wrapper for table TblWdbeMPerson
	*/
class TblWdbeMPerson {

public:
	/**
		* VecVSex (full: VecWdbeVMPersonSex)
		*/
	class VecVSex {

	public:
		static const Sbecore::uint F = 1;
		static const Sbecore::uint M = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWDerivate (full: VecWdbeWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const Sbecore::uint USR = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMPerson();
	virtual ~TblWdbeMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPerson& rst);

	virtual Sbecore::ubigint insertRec(WdbeMPerson* rec);
	Sbecore::ubigint insertNewRec(WdbeMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMPerson& rst, WdbeMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	virtual void insertRst(ListWdbeMPerson& rst, bool transact = false);
	virtual void updateRec(WdbeMPerson* rec);
	virtual void updateRst(ListWdbeMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMPerson** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMPerson: C++ wrapper for table TblWdbeMPerson (MySQL database)
	*/
class MyTblWdbeMPerson : public TblWdbeMPerson, public Sbecore::MyTable {

public:
	MyTblWdbeMPerson();
	~MyTblWdbeMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPerson& rst);

	Sbecore::ubigint insertRec(WdbeMPerson* rec);
	void insertRst(ListWdbeMPerson& rst, bool transact = false);
	void updateRec(WdbeMPerson* rec);
	void updateRst(ListWdbeMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPerson** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMPerson: C++ wrapper for table TblWdbeMPerson (PgSQL database)
	*/
class PgTblWdbeMPerson : public TblWdbeMPerson, public Sbecore::PgTable {

public:
	PgTblWdbeMPerson();
	~PgTblWdbeMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPerson& rst);

	Sbecore::ubigint insertRec(WdbeMPerson* rec);
	void insertRst(ListWdbeMPerson& rst, bool transact = false);
	void updateRec(WdbeMPerson* rec);
	void updateRst(ListWdbeMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPerson** rec);
};
#endif

#endif
