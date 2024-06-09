/**
	* \file WdbeMComponent.h
	* database access for table TblWdbeMComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEMCOMPONENT_H
#define WDBEMCOMPONENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMComponentBasetype TblWdbeMComponent::VecVBasetype

/**
	* WdbeMComponent: record of TblWdbeMComponent
	*/
class WdbeMComponent {

public:
	WdbeMComponent(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWdbeMVersion;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WdbeMComponent& comp);
	bool operator!=(const WdbeMComponent& comp);
};

/**
	* ListWdbeMComponent: recordset of TblWdbeMComponent
	*/
class ListWdbeMComponent {

public:
	ListWdbeMComponent();
	ListWdbeMComponent(const ListWdbeMComponent& src);
	~ListWdbeMComponent();

	void clear();
	unsigned int size() const;
	void append(WdbeMComponent* rec);

	WdbeMComponent* operator[](const Sbecore::uint ix);
	ListWdbeMComponent& operator=(const ListWdbeMComponent& src);
	bool operator==(const ListWdbeMComponent& comp);
	bool operator!=(const ListWdbeMComponent& comp);

public:
	std::vector<WdbeMComponent*> nodes;
};

/**
	* TblWdbeMComponent: C++ wrapper for table TblWdbeMComponent
	*/
class TblWdbeMComponent {

public:
	/**
		* VecVBasetype (full: VecWdbeVMComponentBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint DEV = 1;
		static const Sbecore::uint EZDEV = 2;
		static const Sbecore::uint FPGA = 3;
		static const Sbecore::uint MCU = 4;
		static const Sbecore::uint TERM = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeMComponent();
	virtual ~TblWdbeMComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMComponent& rst);

	virtual Sbecore::ubigint insertRec(WdbeMComponent* rec);
	Sbecore::ubigint insertNewRec(WdbeMComponent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMComponent& rst, WdbeMComponent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMComponent& rst, bool transact = false);
	virtual void updateRec(WdbeMComponent* rec);
	virtual void updateRst(ListWdbeMComponent& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMComponent** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMComponent& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMComponent: C++ wrapper for table TblWdbeMComponent (MySQL database)
	*/
class MyTblWdbeMComponent : public TblWdbeMComponent, public Sbecore::MyTable {

public:
	MyTblWdbeMComponent();
	~MyTblWdbeMComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMComponent& rst);

	Sbecore::ubigint insertRec(WdbeMComponent* rec);
	void insertRst(ListWdbeMComponent& rst, bool transact = false);
	void updateRec(WdbeMComponent* rec);
	void updateRst(ListWdbeMComponent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMComponent** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMComponent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMComponent: C++ wrapper for table TblWdbeMComponent (PgSQL database)
	*/
class PgTblWdbeMComponent : public TblWdbeMComponent, public Sbecore::PgTable {

public:
	PgTblWdbeMComponent();
	~PgTblWdbeMComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMComponent& rst);

	Sbecore::ubigint insertRec(WdbeMComponent* rec);
	void insertRst(ListWdbeMComponent& rst, bool transact = false);
	void updateRec(WdbeMComponent* rec);
	void updateRst(ListWdbeMComponent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMComponent** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWdbeMVersion, const bool append, ListWdbeMComponent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
