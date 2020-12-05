/**
	* \file WdbeMLibrary.h
	* database access for table TblWdbeMLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMLIBRARY_H
#define WDBEMLIBRARY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeMLibrary: record of TblWdbeMLibrary
	*/
class WdbeMLibrary {

public:
	WdbeMLibrary(const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string depSrefsWdbeMLibrary = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string Version;
	std::string depSrefsWdbeMLibrary;
	std::string Comment;

public:
	bool operator==(const WdbeMLibrary& comp);
	bool operator!=(const WdbeMLibrary& comp);
};

/**
	* ListWdbeMLibrary: recordset of TblWdbeMLibrary
	*/
class ListWdbeMLibrary {

public:
	ListWdbeMLibrary();
	ListWdbeMLibrary(const ListWdbeMLibrary& src);
	~ListWdbeMLibrary();

	void clear();
	unsigned int size() const;
	void append(WdbeMLibrary* rec);

	WdbeMLibrary* operator[](const Sbecore::uint ix);
	ListWdbeMLibrary& operator=(const ListWdbeMLibrary& src);
	bool operator==(const ListWdbeMLibrary& comp);
	bool operator!=(const ListWdbeMLibrary& comp);

public:
	std::vector<WdbeMLibrary*> nodes;
};

/**
	* TblWdbeMLibrary: C++ wrapper for table TblWdbeMLibrary
	*/
class TblWdbeMLibrary {

public:

public:
	TblWdbeMLibrary();
	virtual ~TblWdbeMLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMLibrary& rst);

	virtual Sbecore::ubigint insertRec(WdbeMLibrary* rec);
	Sbecore::ubigint insertNewRec(WdbeMLibrary** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string depSrefsWdbeMLibrary = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMLibrary& rst, WdbeMLibrary** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string depSrefsWdbeMLibrary = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeMLibrary& rst, bool transact = false);
	virtual void updateRec(WdbeMLibrary* rec);
	virtual void updateRst(ListWdbeMLibrary& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMLibrary** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMLibrary: C++ wrapper for table TblWdbeMLibrary (MySQL database)
	*/
class MyTblWdbeMLibrary : public TblWdbeMLibrary, public Sbecore::MyTable {

public:
	MyTblWdbeMLibrary();
	~MyTblWdbeMLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMLibrary& rst);

	Sbecore::ubigint insertRec(WdbeMLibrary* rec);
	void insertRst(ListWdbeMLibrary& rst, bool transact = false);
	void updateRec(WdbeMLibrary* rec);
	void updateRst(ListWdbeMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMLibrary** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMLibrary: C++ wrapper for table TblWdbeMLibrary (PgSQL database)
	*/
class PgTblWdbeMLibrary : public TblWdbeMLibrary, public Sbecore::PgTable {

public:
	PgTblWdbeMLibrary();
	~PgTblWdbeMLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMLibrary** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMLibrary& rst);

	Sbecore::ubigint insertRec(WdbeMLibrary* rec);
	void insertRst(ListWdbeMLibrary& rst, bool transact = false);
	void updateRec(WdbeMLibrary* rec);
	void updateRst(ListWdbeMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMLibrary** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

