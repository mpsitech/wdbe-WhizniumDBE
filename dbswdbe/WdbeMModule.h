/**
	* \file WdbeMModule.h
	* database access for table TblWdbeMModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMMODULE_H
#define WDBEMMODULE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMModuleBasetype TblWdbeMModule::VecVBasetype
#define VecWdbeVMModuleHkTbl TblWdbeMModule::VecVHkTbl
#define VecWdbeWMModuleSubset TblWdbeMModule::VecWSubset

/**
	* WdbeMModule: record of TblWdbeMModule
	*/
class WdbeMModule {

public:
	WdbeMModule(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::ubigint supRefWdbeMModule = 0, const Sbecore::ubigint tplRefWdbeMModule = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint refWdbeMImbuf = 0, const std::string sref = "", const std::string Srefrule = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::uint hkIxVTbl;
	Sbecore::ubigint hkUref;
	Sbecore::uint hkNum;
	Sbecore::ubigint supRefWdbeMModule;
	Sbecore::ubigint tplRefWdbeMModule;
	Sbecore::ubigint refWdbeMController;
	Sbecore::ubigint refWdbeMImbuf;
	std::string sref;
	std::string Srefrule;
	std::string Comment;

public:
	bool operator==(const WdbeMModule& comp);
	bool operator!=(const WdbeMModule& comp);
};

/**
	* ListWdbeMModule: recordset of TblWdbeMModule
	*/
class ListWdbeMModule {

public:
	ListWdbeMModule();
	ListWdbeMModule(const ListWdbeMModule& src);
	~ListWdbeMModule();

	void clear();
	unsigned int size() const;
	void append(WdbeMModule* rec);

	WdbeMModule* operator[](const Sbecore::uint ix);
	ListWdbeMModule& operator=(const ListWdbeMModule& src);
	bool operator==(const ListWdbeMModule& comp);
	bool operator!=(const ListWdbeMModule& comp);

public:
	std::vector<WdbeMModule*> nodes;
};

/**
	* TblWdbeMModule: C++ wrapper for table TblWdbeMModule
	*/
class TblWdbeMModule {

public:
	/**
		* VecVBasetype (full: VecWdbeVMModuleBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint TOP = 1;
		static const Sbecore::uint HOSTIF = 2;
		static const Sbecore::uint EHOSTIF = 3;
		static const Sbecore::uint CMDBUS = 4;
		static const Sbecore::uint CMDINV = 5;
		static const Sbecore::uint CMDRET = 6;
		static const Sbecore::uint IMBUF = 7;
		static const Sbecore::uint MNFCORE = 8;
		static const Sbecore::uint MNFPRIM = 9;
		static const Sbecore::uint CTR = 10;
		static const Sbecore::uint FWDCTR = 11;
		static const Sbecore::uint ECTR = 12;
		static const Sbecore::uint WRP = 13;
		static const Sbecore::uint OTH = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVHkTbl (full: VecWdbeVMModuleHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint CVR = 2;
		static const Sbecore::uint UNT = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWdbeWMModuleSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWDBEBMMODULEMCT = 1;
		static const Sbecore::uint SBSWDBEBMMODULEMIB = 2;
		static const Sbecore::uint SBSWDBEBMMODULEMOD = 4;
		static const Sbecore::uint SBSWDBEBMMODULEMTP = 8;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);
	};

public:
	TblWdbeMModule();
	virtual ~TblWdbeMModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMModule& rst);

	virtual Sbecore::ubigint insertRec(WdbeMModule* rec);
	Sbecore::ubigint insertNewRec(WdbeMModule** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::ubigint supRefWdbeMModule = 0, const Sbecore::ubigint tplRefWdbeMModule = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint refWdbeMImbuf = 0, const std::string sref = "", const std::string Srefrule = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMModule& rst, WdbeMModule** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::ubigint supRefWdbeMModule = 0, const Sbecore::ubigint tplRefWdbeMModule = 0, const Sbecore::ubigint refWdbeMController = 0, const Sbecore::ubigint refWdbeMImbuf = 0, const std::string sref = "", const std::string Srefrule = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMModule& rst, bool transact = false);
	virtual void updateRec(WdbeMModule* rec);
	virtual void updateRst(ListWdbeMModule& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMModule** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual bool loadRecByCtr(Sbecore::ubigint refWdbeMController, WdbeMModule** rec);
	virtual bool loadRecByImb(Sbecore::ubigint refWdbeMImbuf, WdbeMModule** rec);
	virtual bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMModule, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMModule& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, ListWdbeMModule& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMModule);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMModule& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWdbeMModule& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWdbeMModule& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMModule: C++ wrapper for table TblWdbeMModule (MySQL database)
	*/
class MyTblWdbeMModule : public TblWdbeMModule, public Sbecore::MyTable {

public:
	MyTblWdbeMModule();
	~MyTblWdbeMModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMModule& rst);

	Sbecore::ubigint insertRec(WdbeMModule* rec);
	void insertRst(ListWdbeMModule& rst, bool transact = false);
	void updateRec(WdbeMModule* rec);
	void updateRst(ListWdbeMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMModule** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRecByCtr(Sbecore::ubigint refWdbeMController, WdbeMModule** rec);
	bool loadRecByImb(Sbecore::ubigint refWdbeMImbuf, WdbeMModule** rec);
	bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMModule, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMModule& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, ListWdbeMModule& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMModule);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMModule: C++ wrapper for table TblWdbeMModule (PgSQL database)
	*/
class PgTblWdbeMModule : public TblWdbeMModule, public Sbecore::PgTable {

public:
	PgTblWdbeMModule();
	~PgTblWdbeMModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMModule& rst);

	Sbecore::ubigint insertRec(WdbeMModule* rec);
	void insertRst(ListWdbeMModule& rst, bool transact = false);
	void updateRec(WdbeMModule* rec);
	void updateRst(ListWdbeMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMModule** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRecByCtr(Sbecore::ubigint refWdbeMController, WdbeMModule** rec);
	bool loadRecByImb(Sbecore::ubigint refWdbeMImbuf, WdbeMModule** rec);
	bool loadRefBySupSrf(Sbecore::ubigint supRefWdbeMModule, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMModule& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWdbeMModule, const bool append, ListWdbeMModule& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWdbeMModule);
};
#endif

#endif
