/**
	* \file WdbeAMCoreversionIp.h
	* database access for table TblWdbeAMCoreversionIp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAMCOREVERSIONIP_H
#define WDBEAMCOREVERSIONIP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVAMCoreversionIpTagtype TblWdbeAMCoreversionIp::VecVTagtype

/**
	* WdbeAMCoreversionIp: record of TblWdbeAMCoreversionIp
	*/
class WdbeAMCoreversionIp {

public:
	WdbeAMCoreversionIp(const Sbecore::ubigint ref = 0, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint cvrRefWdbeMCoreversion;
	Sbecore::uint cvrNum;
	std::string sref;
	Sbecore::uint ixVTagtype;
	std::string Comment;

public:
	bool operator==(const WdbeAMCoreversionIp& comp);
	bool operator!=(const WdbeAMCoreversionIp& comp);
};

/**
	* ListWdbeAMCoreversionIp: recordset of TblWdbeAMCoreversionIp
	*/
class ListWdbeAMCoreversionIp {

public:
	ListWdbeAMCoreversionIp();
	ListWdbeAMCoreversionIp(const ListWdbeAMCoreversionIp& src);
	~ListWdbeAMCoreversionIp();

	void clear();
	unsigned int size() const;
	void append(WdbeAMCoreversionIp* rec);

	WdbeAMCoreversionIp* operator[](const Sbecore::uint ix);
	ListWdbeAMCoreversionIp& operator=(const ListWdbeAMCoreversionIp& src);
	bool operator==(const ListWdbeAMCoreversionIp& comp);
	bool operator!=(const ListWdbeAMCoreversionIp& comp);

public:
	std::vector<WdbeAMCoreversionIp*> nodes;
};

/**
	* TblWdbeAMCoreversionIp: C++ wrapper for table TblWdbeAMCoreversionIp
	*/
class TblWdbeAMCoreversionIp {

public:
	/**
		* VecVTagtype (full: VecWdbeVAMCoreversionIpTagtype)
		*/
	class VecVTagtype {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;
		static const Sbecore::uint REPL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeAMCoreversionIp();
	virtual ~TblWdbeAMCoreversionIp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionIp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionIp& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMCoreversionIp* rec);
	Sbecore::ubigint insertNewRec(WdbeAMCoreversionIp** rec = NULL, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMCoreversionIp& rst, WdbeAMCoreversionIp** rec = NULL, const Sbecore::ubigint cvrRefWdbeMCoreversion = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	virtual void updateRec(WdbeAMCoreversionIp* rec);
	virtual void updateRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionIp** rec);
	virtual Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionIp& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMCoreversionIp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMCoreversionIp: C++ wrapper for table TblWdbeAMCoreversionIp (MySQL database)
	*/
class MyTblWdbeAMCoreversionIp : public TblWdbeAMCoreversionIp, public Sbecore::MyTable {

public:
	MyTblWdbeAMCoreversionIp();
	~MyTblWdbeAMCoreversionIp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionIp& rst);

	Sbecore::ubigint insertRec(WdbeAMCoreversionIp* rec);
	void insertRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	void updateRec(WdbeAMCoreversionIp* rec);
	void updateRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionIp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMCoreversionIp: C++ wrapper for table TblWdbeAMCoreversionIp (PgSQL database)
	*/
class PgTblWdbeAMCoreversionIp : public TblWdbeAMCoreversionIp, public Sbecore::PgTable {

public:
	PgTblWdbeAMCoreversionIp();
	~PgTblWdbeAMCoreversionIp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMCoreversionIp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMCoreversionIp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCoreversionIp& rst);

	Sbecore::ubigint insertRec(WdbeAMCoreversionIp* rec);
	void insertRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	void updateRec(WdbeAMCoreversionIp* rec);
	void updateRst(ListWdbeAMCoreversionIp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCoreversionIp** rec);
	Sbecore::ubigint loadRstByCvr(Sbecore::ubigint cvrRefWdbeMCoreversion, const bool append, ListWdbeAMCoreversionIp& rst);
};
#endif

#endif

