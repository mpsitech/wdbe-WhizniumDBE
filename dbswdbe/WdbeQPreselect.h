/**
	* \file WdbeQPreselect.h
	* Dbs and XML wrapper for table TblWdbeQPreselect (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPRESELECT_H
#define WDBEQPRESELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPreselect: record of TblWdbeQPreselect
	*/
class WdbeQPreselect {

public:
	WdbeQPreselect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPreselect: recordset of TblWdbeQPreselect
	*/
class ListWdbeQPreselect {

public:
	ListWdbeQPreselect();
	ListWdbeQPreselect(const ListWdbeQPreselect& src);
	~ListWdbeQPreselect();

	void clear();
	unsigned int size() const;
	void append(WdbeQPreselect* rec);

	ListWdbeQPreselect& operator=(const ListWdbeQPreselect& src);

public:
	std::vector<WdbeQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPreselect: C++ wrapper for table TblWdbeQPreselect
	*/
class TblWdbeQPreselect {

public:
	TblWdbeQPreselect();
	virtual ~TblWdbeQPreselect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPreselect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPreselect& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPreselect* rec);
	Sbecore::ubigint insertNewRec(WdbeQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPreselect& rst, WdbeQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQPreselect& rst);
	virtual void updateRec(WdbeQPreselect* rec);
	virtual void updateRst(ListWdbeQPreselect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPreselect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPreselect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPreselect: C++ wrapper for table TblWdbeQPreselect (MySQL database)
	*/
class MyTblWdbeQPreselect : public TblWdbeQPreselect, public Sbecore::MyTable {

public:
	MyTblWdbeQPreselect();
	~MyTblWdbeQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPreselect& rst);

	Sbecore::ubigint insertRec(WdbeQPreselect* rec);
	void insertRst(ListWdbeQPreselect& rst);
	void updateRec(WdbeQPreselect* rec);
	void updateRst(ListWdbeQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPreselect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPreselect: C++ wrapper for table TblWdbeQPreselect (PgSQL database)
	*/
class PgTblWdbeQPreselect : public TblWdbeQPreselect, public Sbecore::PgTable {

public:
	PgTblWdbeQPreselect();
	~PgTblWdbeQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPreselect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPreselect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPreselect& rst);

	Sbecore::ubigint insertRec(WdbeQPreselect* rec);
	void insertRst(ListWdbeQPreselect& rst);
	void updateRec(WdbeQPreselect* rec);
	void updateRst(ListWdbeQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPreselect& rst);
};
#endif

#endif

