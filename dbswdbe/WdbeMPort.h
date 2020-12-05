/**
	* \file WdbeMPort.h
	* database access for table TblWdbeMPort (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMPORT_H
#define WDBEMPORT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMPortDir TblWdbeMPort::VecVDir
#define VecWdbeVMPortMdlCat TblWdbeMPort::VecVMdlCat

/**
	* WdbeMPort: record of TblWdbeMPort
	*/
class WdbeMPort {

public:
	WdbeMPort(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWdbeCPort = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mdlIxVCat = 0, const std::string sref = "", const Sbecore::uint ixVDir = 0, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string cpiSrefWdbeMPin = "", const std::string cprSrefWdbeMPort = "", const std::string csiSrefWdbeMSignal = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWdbeCPort;
	Sbecore::ubigint mdlRefWdbeMModule;
	Sbecore::uint mdlNum;
	Sbecore::uint mdlIxVCat;
	std::string sref;
	Sbecore::uint ixVDir;
	std::string srefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;
	std::string Defval;
	std::string cpiSrefWdbeMPin;
	std::string cprSrefWdbeMPort;
	std::string csiSrefWdbeMSignal;
	std::string Comment;

public:
	bool operator==(const WdbeMPort& comp);
	bool operator!=(const WdbeMPort& comp);
};

/**
	* ListWdbeMPort: recordset of TblWdbeMPort
	*/
class ListWdbeMPort {

public:
	ListWdbeMPort();
	ListWdbeMPort(const ListWdbeMPort& src);
	~ListWdbeMPort();

	void clear();
	unsigned int size() const;
	void append(WdbeMPort* rec);

	WdbeMPort* operator[](const Sbecore::uint ix);
	ListWdbeMPort& operator=(const ListWdbeMPort& src);
	bool operator==(const ListWdbeMPort& comp);
	bool operator!=(const ListWdbeMPort& comp);

public:
	std::vector<WdbeMPort*> nodes;
};

/**
	* TblWdbeMPort: C++ wrapper for table TblWdbeMPort
	*/
class TblWdbeMPort {

public:
	/**
		* VecVDir (full: VecWdbeVMPortDir)
		*/
	class VecVDir {

	public:
		static const Sbecore::uint IN = 1;
		static const Sbecore::uint INOUT = 2;
		static const Sbecore::uint OUT = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVMdlCat (full: VecWdbeVMPortMdlCat)
		*/
	class VecVMdlCat {

	public:
		static const Sbecore::uint RESET = 1;
		static const Sbecore::uint CLK = 2;
		static const Sbecore::uint RTEWRP = 3;
		static const Sbecore::uint RTETOP = 4;
		static const Sbecore::uint CMDBUS = 5;
		static const Sbecore::uint IMB = 6;
		static const Sbecore::uint RTESUP = 7;
		static const Sbecore::uint RTEPIN = 8;
		static const Sbecore::uint DBG = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMPort();
	virtual ~TblWdbeMPort();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMPort** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPort& rst);

	virtual Sbecore::ubigint insertRec(WdbeMPort* rec);
	Sbecore::ubigint insertNewRec(WdbeMPort** rec = NULL, const Sbecore::ubigint refWdbeCPort = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mdlIxVCat = 0, const std::string sref = "", const Sbecore::uint ixVDir = 0, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string cpiSrefWdbeMPin = "", const std::string cprSrefWdbeMPort = "", const std::string csiSrefWdbeMSignal = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMPort& rst, WdbeMPort** rec = NULL, const Sbecore::ubigint refWdbeCPort = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mdlIxVCat = 0, const std::string sref = "", const Sbecore::uint ixVDir = 0, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Defval = "", const std::string cpiSrefWdbeMPin = "", const std::string cprSrefWdbeMPort = "", const std::string csiSrefWdbeMSignal = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMPort& rst, bool transact = false);
	virtual void updateRec(WdbeMPort* rec);
	virtual void updateRst(ListWdbeMPort& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMPort** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPort, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPort, const bool append, ListWdbeMPort& rst);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMPort& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMPort& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMPort: C++ wrapper for table TblWdbeMPort (MySQL database)
	*/
class MyTblWdbeMPort : public TblWdbeMPort, public Sbecore::MyTable {

public:
	MyTblWdbeMPort();
	~MyTblWdbeMPort();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPort& rst);

	Sbecore::ubigint insertRec(WdbeMPort* rec);
	void insertRst(ListWdbeMPort& rst, bool transact = false);
	void updateRec(WdbeMPort* rec);
	void updateRst(ListWdbeMPort& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPort** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPort, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPort, const bool append, ListWdbeMPort& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMPort& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMPort: C++ wrapper for table TblWdbeMPort (PgSQL database)
	*/
class PgTblWdbeMPort : public TblWdbeMPort, public Sbecore::PgTable {

public:
	PgTblWdbeMPort();
	~PgTblWdbeMPort();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMPort** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMPort& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMPort** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMPort& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMPort& rst);

	Sbecore::ubigint insertRec(WdbeMPort* rec);
	void insertRst(ListWdbeMPort& rst, bool transact = false);
	void updateRec(WdbeMPort* rec);
	void updateRst(ListWdbeMPort& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMPort** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCPort, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCPort, const bool append, ListWdbeMPort& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMPort& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

