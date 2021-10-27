/**
	* \file WdbeMImbuf.h
	* database access for table TblWdbeMImbuf (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMIMBUF_H
#define WDBEMIMBUF_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMImbufRotype TblWdbeMImbuf::VecVRotype

/**
	* WdbeMImbuf: record of TblWdbeMImbuf
	*/
class WdbeMImbuf {

public:
	WdbeMImbuf(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVRotype = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string Fullsref = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const Sbecore::utinyint Prio = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVRotype;
	Sbecore::ubigint refWdbeMModule;
	std::string Fullsref;
	Sbecore::usmallint Width;
	std::string Minmax;
	Sbecore::utinyint Prio;

public:
	bool operator==(const WdbeMImbuf& comp);
	bool operator!=(const WdbeMImbuf& comp);
};

/**
	* ListWdbeMImbuf: recordset of TblWdbeMImbuf
	*/
class ListWdbeMImbuf {

public:
	ListWdbeMImbuf();
	ListWdbeMImbuf(const ListWdbeMImbuf& src);
	~ListWdbeMImbuf();

	void clear();
	unsigned int size() const;
	void append(WdbeMImbuf* rec);

	WdbeMImbuf* operator[](const Sbecore::uint ix);
	ListWdbeMImbuf& operator=(const ListWdbeMImbuf& src);
	bool operator==(const ListWdbeMImbuf& comp);
	bool operator!=(const ListWdbeMImbuf& comp);

public:
	std::vector<WdbeMImbuf*> nodes;
};

/**
	* TblWdbeMImbuf: C++ wrapper for table TblWdbeMImbuf
	*/
class TblWdbeMImbuf {

public:
	/**
		* VecVRotype (full: VecWdbeVMImbufRotype)
		*/
	class VecVRotype {

	public:
		static const Sbecore::uint SNGATMT = 1;
		static const Sbecore::uint MULTATMT = 2;
		static const Sbecore::uint STRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	TblWdbeMImbuf();
	virtual ~TblWdbeMImbuf();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMImbuf** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMImbuf& rst);

	virtual Sbecore::ubigint insertRec(WdbeMImbuf* rec);
	Sbecore::ubigint insertNewRec(WdbeMImbuf** rec = NULL, const Sbecore::uint ixVRotype = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string Fullsref = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const Sbecore::utinyint Prio = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeMImbuf& rst, WdbeMImbuf** rec = NULL, const Sbecore::uint ixVRotype = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string Fullsref = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "", const Sbecore::utinyint Prio = 0);
	virtual void insertRst(ListWdbeMImbuf& rst, bool transact = false);
	virtual void updateRec(WdbeMImbuf* rec);
	virtual void updateRst(ListWdbeMImbuf& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMImbuf** rec);
	virtual bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	virtual bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMImbuf** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMImbuf& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMImbuf: C++ wrapper for table TblWdbeMImbuf (MySQL database)
	*/
class MyTblWdbeMImbuf : public TblWdbeMImbuf, public Sbecore::MyTable {

public:
	MyTblWdbeMImbuf();
	~MyTblWdbeMImbuf();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMImbuf** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMImbuf& rst);

	Sbecore::ubigint insertRec(WdbeMImbuf* rec);
	void insertRst(ListWdbeMImbuf& rst, bool transact = false);
	void updateRec(WdbeMImbuf* rec);
	void updateRst(ListWdbeMImbuf& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMImbuf** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMImbuf** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMImbuf: C++ wrapper for table TblWdbeMImbuf (PgSQL database)
	*/
class PgTblWdbeMImbuf : public TblWdbeMImbuf, public Sbecore::PgTable {

public:
	PgTblWdbeMImbuf();
	~PgTblWdbeMImbuf();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMImbuf** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMImbuf& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMImbuf** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMImbuf** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMImbuf& rst);

	Sbecore::ubigint insertRec(WdbeMImbuf* rec);
	void insertRst(ListWdbeMImbuf& rst, bool transact = false);
	void updateRec(WdbeMImbuf* rec);
	void updateRst(ListWdbeMImbuf& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMImbuf** rec);
	bool loadFsrByRef(Sbecore::ubigint ref, std::string& Fullsref);
	bool loadRecByMdl(Sbecore::ubigint refWdbeMModule, WdbeMImbuf** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWdbeMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
