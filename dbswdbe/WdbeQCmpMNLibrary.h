/**
	* \file WdbeQCmpMNLibrary.h
	* Dbs and XML wrapper for table TblWdbeQCmpMNLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMPMNLIBRARY_H
#define WDBEQCMPMNLIBRARY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmpMNLibrary: record of TblWdbeQCmpMNLibrary
	*/
class WdbeQCmpMNLibrary {

public:
	WdbeQCmpMNLibrary(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmpMNLibrary: recordset of TblWdbeQCmpMNLibrary
	*/
class ListWdbeQCmpMNLibrary {

public:
	ListWdbeQCmpMNLibrary();
	ListWdbeQCmpMNLibrary(const ListWdbeQCmpMNLibrary& src);
	~ListWdbeQCmpMNLibrary();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmpMNLibrary* rec);

	ListWdbeQCmpMNLibrary& operator=(const ListWdbeQCmpMNLibrary& src);

public:
	std::vector<WdbeQCmpMNLibrary*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmpMNLibrary: C++ wrapper for table TblWdbeQCmpMNLibrary
	*/
class TblWdbeQCmpMNLibrary {

public:
	TblWdbeQCmpMNLibrary();
	virtual ~TblWdbeQCmpMNLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpMNLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpMNLibrary& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmpMNLibrary* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmpMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmpMNLibrary& rst, WdbeQCmpMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQCmpMNLibrary& rst);
	virtual void updateRec(WdbeQCmpMNLibrary* rec);
	virtual void updateRst(ListWdbeQCmpMNLibrary& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpMNLibrary** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpMNLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmpMNLibrary: C++ wrapper for table TblWdbeQCmpMNLibrary (MySQL database)
	*/
class MyTblWdbeQCmpMNLibrary : public TblWdbeQCmpMNLibrary, public Sbecore::MyTable {

public:
	MyTblWdbeQCmpMNLibrary();
	~MyTblWdbeQCmpMNLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpMNLibrary& rst);

	Sbecore::ubigint insertRec(WdbeQCmpMNLibrary* rec);
	void insertRst(ListWdbeQCmpMNLibrary& rst);
	void updateRec(WdbeQCmpMNLibrary* rec);
	void updateRst(ListWdbeQCmpMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpMNLibrary& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmpMNLibrary: C++ wrapper for table TblWdbeQCmpMNLibrary (PgSQL database)
	*/
class PgTblWdbeQCmpMNLibrary : public TblWdbeQCmpMNLibrary, public Sbecore::PgTable {

public:
	PgTblWdbeQCmpMNLibrary();
	~PgTblWdbeQCmpMNLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmpMNLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmpMNLibrary& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmpMNLibrary& rst);

	Sbecore::ubigint insertRec(WdbeQCmpMNLibrary* rec);
	void insertRst(ListWdbeQCmpMNLibrary& rst);
	void updateRec(WdbeQCmpMNLibrary* rec);
	void updateRst(ListWdbeQCmpMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmpMNLibrary& rst);
};
#endif

#endif
