/**
	* \file WdbeMVector.h
	* database access for table TblWdbeMVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMVECTOR_H
#define WDBEMVECTOR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMVectorBasetype TblWdbeMVector::VecVBasetype
#define VecWdbeVMVectorHkTbl TblWdbeMVector::VecVHkTbl

/**
	* WdbeMVector: record of TblWdbeMVector
	*/
class WdbeMVector {

public:
	WdbeMVector(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const std::string sref = "", const std::string srefsKOption = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::uint hkIxVTbl;
	Sbecore::ubigint hkUref;
	std::string sref;
	std::string srefsKOption;

public:
	bool operator==(const WdbeMVector& comp);
	bool operator!=(const WdbeMVector& comp);
};

/**
	* ListWdbeMVector: recordset of TblWdbeMVector
	*/
class ListWdbeMVector {

public:
	ListWdbeMVector();
	ListWdbeMVector(const ListWdbeMVector& src);
	~ListWdbeMVector();

	void clear();
	unsigned int size() const;
	void append(WdbeMVector* rec);

	WdbeMVector* operator[](const Sbecore::uint ix);
	ListWdbeMVector& operator=(const ListWdbeMVector& src);
	bool operator==(const ListWdbeMVector& comp);
	bool operator!=(const ListWdbeMVector& comp);

public:
	std::vector<WdbeMVector*> nodes;
};

/**
	* TblWdbeMVector: C++ wrapper for table TblWdbeMVector
	*/
class TblWdbeMVector {

public:
	/**
		* VecVBasetype (full: VecWdbeVMVectorBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint IXLIN = 1;
		static const Sbecore::uint TIXLIN = 2;
		static const Sbecore::uint TIXOR = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVHkTbl (full: VecWdbeVMVectorHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const Sbecore::uint CTR = 1;
		static const Sbecore::uint SIG = 2;
		static const Sbecore::uint SYS = 3;
		static const Sbecore::uint UNT = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMVector();
	virtual ~TblWdbeMVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeMVector* rec);
	Sbecore::ubigint insertNewRec(WdbeMVector** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const std::string sref = "", const std::string srefsKOption = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMVector& rst, WdbeMVector** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const std::string sref = "", const std::string srefsKOption = "");
	virtual void insertRst(ListWdbeMVector& rst, bool transact = false);
	virtual void updateRec(WdbeMVector* rec);
	virtual void updateRst(ListWdbeMVector& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMVector** rec);
	virtual bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, WdbeMVector** rec);
	virtual Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMVector& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMVector: C++ wrapper for table TblWdbeMVector (MySQL database)
	*/
class MyTblWdbeMVector : public TblWdbeMVector, public Sbecore::MyTable {

public:
	MyTblWdbeMVector();
	~MyTblWdbeMVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVector& rst);

	Sbecore::ubigint insertRec(WdbeMVector* rec);
	void insertRst(ListWdbeMVector& rst, bool transact = false);
	void updateRec(WdbeMVector* rec);
	void updateRst(ListWdbeMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVector** rec);
	bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, WdbeMVector** rec);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMVector& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMVector: C++ wrapper for table TblWdbeMVector (PgSQL database)
	*/
class PgTblWdbeMVector : public TblWdbeMVector, public Sbecore::PgTable {

public:
	PgTblWdbeMVector();
	~PgTblWdbeMVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMVector& rst);

	Sbecore::ubigint insertRec(WdbeMVector* rec);
	void insertRst(ListWdbeMVector& rst, bool transact = false);
	void updateRec(WdbeMVector* rec);
	void updateRst(ListWdbeMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMVector** rec);
	bool loadRecByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, WdbeMVector** rec);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWdbeMVector& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

