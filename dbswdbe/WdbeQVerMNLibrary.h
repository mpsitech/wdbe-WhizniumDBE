/**
	* \file WdbeQVerMNLibrary.h
	* Dbs and XML wrapper for table TblWdbeQVerMNLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQVERMNLIBRARY_H
#define WDBEQVERMNLIBRARY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVerMNLibrary: record of TblWdbeQVerMNLibrary
	*/
class WdbeQVerMNLibrary {

public:
	WdbeQVerMNLibrary(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVerMNLibrary: recordset of TblWdbeQVerMNLibrary
	*/
class ListWdbeQVerMNLibrary {

public:
	ListWdbeQVerMNLibrary();
	ListWdbeQVerMNLibrary(const ListWdbeQVerMNLibrary& src);
	~ListWdbeQVerMNLibrary();

	void clear();
	unsigned int size() const;
	void append(WdbeQVerMNLibrary* rec);

	ListWdbeQVerMNLibrary& operator=(const ListWdbeQVerMNLibrary& src);

public:
	std::vector<WdbeQVerMNLibrary*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVerMNLibrary: C++ wrapper for table TblWdbeQVerMNLibrary
	*/
class TblWdbeQVerMNLibrary {

public:
	TblWdbeQVerMNLibrary();
	virtual ~TblWdbeQVerMNLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVerMNLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerMNLibrary& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVerMNLibrary* rec);
	Sbecore::ubigint insertNewRec(WdbeQVerMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVerMNLibrary& rst, WdbeQVerMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQVerMNLibrary& rst);
	virtual void updateRec(WdbeQVerMNLibrary* rec);
	virtual void updateRst(ListWdbeQVerMNLibrary& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerMNLibrary** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerMNLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVerMNLibrary: C++ wrapper for table TblWdbeQVerMNLibrary (MySQL database)
	*/
class MyTblWdbeQVerMNLibrary : public TblWdbeQVerMNLibrary, public Sbecore::MyTable {

public:
	MyTblWdbeQVerMNLibrary();
	~MyTblWdbeQVerMNLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerMNLibrary& rst);

	Sbecore::ubigint insertRec(WdbeQVerMNLibrary* rec);
	void insertRst(ListWdbeQVerMNLibrary& rst);
	void updateRec(WdbeQVerMNLibrary* rec);
	void updateRst(ListWdbeQVerMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerMNLibrary& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVerMNLibrary: C++ wrapper for table TblWdbeQVerMNLibrary (PgSQL database)
	*/
class PgTblWdbeQVerMNLibrary : public TblWdbeQVerMNLibrary, public Sbecore::PgTable {

public:
	PgTblWdbeQVerMNLibrary();
	~PgTblWdbeQVerMNLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVerMNLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVerMNLibrary& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerMNLibrary& rst);

	Sbecore::ubigint insertRec(WdbeQVerMNLibrary* rec);
	void insertRst(ListWdbeQVerMNLibrary& rst);
	void updateRec(WdbeQVerMNLibrary* rec);
	void updateRst(ListWdbeQVerMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerMNLibrary& rst);
};
#endif

#endif

