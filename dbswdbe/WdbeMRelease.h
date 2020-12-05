/**
	* \file WdbeMRelease.h
	* database access for table TblWdbeMRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMRELEASE_H
#define WDBEMRELEASE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMReleaseBasetype TblWdbeMRelease::VecVBasetype

/**
	* WdbeMRelease: record of TblWdbeMRelease
	*/
class WdbeMRelease {

public:
	WdbeMRelease(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWdbeMVersion;
	Sbecore::ubigint refWdbeMMachine;
	std::string sref;
	std::string srefsKOption;
	std::string Comment;

public:
	bool operator==(const WdbeMRelease& comp);
	bool operator!=(const WdbeMRelease& comp);
};

/**
	* ListWdbeMRelease: recordset of TblWdbeMRelease
	*/
class ListWdbeMRelease {

public:
	ListWdbeMRelease();
	ListWdbeMRelease(const ListWdbeMRelease& src);
	~ListWdbeMRelease();

	void clear();
	unsigned int size() const;
	void append(WdbeMRelease* rec);

	WdbeMRelease* operator[](const Sbecore::uint ix);
	ListWdbeMRelease& operator=(const ListWdbeMRelease& src);
	bool operator==(const ListWdbeMRelease& comp);
	bool operator!=(const ListWdbeMRelease& comp);

public:
	std::vector<WdbeMRelease*> nodes;
};

/**
	* TblWdbeMRelease: C++ wrapper for table TblWdbeMRelease
	*/
class TblWdbeMRelease {

public:
	/**
		* VecVBasetype (full: VecWdbeVMReleaseBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint DEV = 1;
		static const Sbecore::uint EZDEV = 2;
		static const Sbecore::uint FPGA = 3;
		static const Sbecore::uint MCU = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMRelease();
	virtual ~TblWdbeMRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMRelease& rst);

	virtual Sbecore::ubigint insertRec(WdbeMRelease* rec);
	Sbecore::ubigint insertNewRec(WdbeMRelease** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMRelease& rst, WdbeMRelease** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const Sbecore::ubigint refWdbeMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMRelease& rst, bool transact = false);
	virtual void updateRec(WdbeMRelease* rec);
	virtual void updateRst(ListWdbeMRelease& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMRelease** rec);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMRelease& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMRelease: C++ wrapper for table TblWdbeMRelease (MySQL database)
	*/
class MyTblWdbeMRelease : public TblWdbeMRelease, public Sbecore::MyTable {

public:
	MyTblWdbeMRelease();
	~MyTblWdbeMRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMRelease& rst);

	Sbecore::ubigint insertRec(WdbeMRelease* rec);
	void insertRst(ListWdbeMRelease& rst, bool transact = false);
	void updateRec(WdbeMRelease* rec);
	void updateRst(ListWdbeMRelease& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMRelease** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMRelease& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMRelease: C++ wrapper for table TblWdbeMRelease (PgSQL database)
	*/
class PgTblWdbeMRelease : public TblWdbeMRelease, public Sbecore::PgTable {

public:
	PgTblWdbeMRelease();
	~PgTblWdbeMRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMRelease& rst);

	Sbecore::ubigint insertRec(WdbeMRelease* rec);
	void insertRst(ListWdbeMRelease& rst, bool transact = false);
	void updateRec(WdbeMRelease* rec);
	void updateRst(ListWdbeMRelease& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMRelease** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWdbeMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMRelease& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

