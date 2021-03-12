/**
	* \file WdbeMSignal.h
	* database access for table TblWdbeMSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMSIGNAL_H
#define WDBEMSIGNAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMSignalBasetype TblWdbeMSignal::VecVBasetype
#define VecWdbeVMSignalMgeTbl TblWdbeMSignal::VecVMgeTbl

/**
	* WdbeMSignal: record of TblWdbeMSignal
	*/
class WdbeMSignal {

public:
	WdbeMSignal(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeCSignal = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mgeIxVTbl = 0, const Sbecore::ubigint mgeUref = 0, const Sbecore::ubigint refWdbeMVector = 0, const std::string sref = "", const bool Const = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Comb = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const Sbecore::ubigint drvRefWdbeMPort = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWdbeCSignal;
	Sbecore::ubigint mdlRefWdbeMModule;
	Sbecore::uint mdlNum;
	Sbecore::uint mgeIxVTbl;
	Sbecore::ubigint mgeUref;
	Sbecore::ubigint refWdbeMVector;
	std::string sref;
	bool Const;
	std::string srefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;
	std::string Comb;
	std::string Onval;
	std::string Offval;
	bool Defon;
	Sbecore::ubigint drvRefWdbeMPort;
	std::string Comment;

public:
	bool operator==(const WdbeMSignal& comp);
	bool operator!=(const WdbeMSignal& comp);
};

/**
	* ListWdbeMSignal: recordset of TblWdbeMSignal
	*/
class ListWdbeMSignal {

public:
	ListWdbeMSignal();
	ListWdbeMSignal(const ListWdbeMSignal& src);
	~ListWdbeMSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeMSignal* rec);

	WdbeMSignal* operator[](const Sbecore::uint ix);
	ListWdbeMSignal& operator=(const ListWdbeMSignal& src);
	bool operator==(const ListWdbeMSignal& comp);
	bool operator!=(const ListWdbeMSignal& comp);

public:
	std::vector<WdbeMSignal*> nodes;
};

/**
	* TblWdbeMSignal: C++ wrapper for table TblWdbeMSignal
	*/
class TblWdbeMSignal {

public:
	/**
		* VecVBasetype (full: VecWdbeVMSignalBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CLK = 1;
		static const Sbecore::uint HSHK = 2;
		static const Sbecore::uint OPRT = 3;
		static const Sbecore::uint IOPRT = 4;
		static const Sbecore::uint PSB = 5;
		static const Sbecore::uint STRB = 6;
		static const Sbecore::uint OTH = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVMgeTbl (full: VecWdbeVMSignalMgeTbl)
		*/
	class VecVMgeTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint MDL = 2;
		static const Sbecore::uint PRC = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeMSignal();
	virtual ~TblWdbeMSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeMSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeMSignal** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeCSignal = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mgeIxVTbl = 0, const Sbecore::ubigint mgeUref = 0, const Sbecore::ubigint refWdbeMVector = 0, const std::string sref = "", const bool Const = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Comb = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const Sbecore::ubigint drvRefWdbeMPort = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMSignal& rst, WdbeMSignal** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWdbeCSignal = 0, const Sbecore::ubigint mdlRefWdbeMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint mgeIxVTbl = 0, const Sbecore::ubigint mgeUref = 0, const Sbecore::ubigint refWdbeMVector = 0, const std::string sref = "", const bool Const = false, const std::string srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const std::string Comb = "", const std::string Onval = "", const std::string Offval = "", const bool Defon = false, const Sbecore::ubigint drvRefWdbeMPort = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMSignal& rst, bool transact = false);
	virtual void updateRec(WdbeMSignal* rec);
	virtual void updateRst(ListWdbeMSignal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMSignal** rec);
	virtual bool loadRecByVec(Sbecore::ubigint refWdbeMVector, WdbeMSignal** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSignal, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSignal, const bool append, ListWdbeMSignal& rst);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMSignal& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMSignal: C++ wrapper for table TblWdbeMSignal (MySQL database)
	*/
class MyTblWdbeMSignal : public TblWdbeMSignal, public Sbecore::MyTable {

public:
	MyTblWdbeMSignal();
	~MyTblWdbeMSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSignal& rst);

	Sbecore::ubigint insertRec(WdbeMSignal* rec);
	void insertRst(ListWdbeMSignal& rst, bool transact = false);
	void updateRec(WdbeMSignal* rec);
	void updateRst(ListWdbeMSignal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSignal** rec);
	bool loadRecByVec(Sbecore::ubigint refWdbeMVector, WdbeMSignal** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSignal, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSignal, const bool append, ListWdbeMSignal& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMSignal& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMSignal: C++ wrapper for table TblWdbeMSignal (PgSQL database)
	*/
class PgTblWdbeMSignal : public TblWdbeMSignal, public Sbecore::PgTable {

public:
	PgTblWdbeMSignal();
	~PgTblWdbeMSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMSignal& rst);

	Sbecore::ubigint insertRec(WdbeMSignal* rec);
	void insertRst(ListWdbeMSignal& rst, bool transact = false);
	void updateRec(WdbeMSignal* rec);
	void updateRst(ListWdbeMSignal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMSignal** rec);
	bool loadRecByVec(Sbecore::ubigint refWdbeMVector, WdbeMSignal** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCSignal, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCSignal, const bool append, ListWdbeMSignal& rst);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWdbeMModule, const bool append, ListWdbeMSignal& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
