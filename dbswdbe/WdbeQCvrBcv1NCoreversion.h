/**
	* \file WdbeQCvrBcv1NCoreversion.h
	* Dbs and XML wrapper for table TblWdbeQCvrBcv1NCoreversion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRBCV1NCOREVERSION_H
#define WDBEQCVRBCV1NCOREVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCvrBcv1NCoreversion: record of TblWdbeQCvrBcv1NCoreversion
	*/
class WdbeQCvrBcv1NCoreversion {

public:
	WdbeQCvrBcv1NCoreversion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCvrBcv1NCoreversion: recordset of TblWdbeQCvrBcv1NCoreversion
	*/
class ListWdbeQCvrBcv1NCoreversion {

public:
	ListWdbeQCvrBcv1NCoreversion();
	ListWdbeQCvrBcv1NCoreversion(const ListWdbeQCvrBcv1NCoreversion& src);
	~ListWdbeQCvrBcv1NCoreversion();

	void clear();
	unsigned int size() const;
	void append(WdbeQCvrBcv1NCoreversion* rec);

	ListWdbeQCvrBcv1NCoreversion& operator=(const ListWdbeQCvrBcv1NCoreversion& src);

public:
	std::vector<WdbeQCvrBcv1NCoreversion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCvrBcv1NCoreversion: C++ wrapper for table TblWdbeQCvrBcv1NCoreversion
	*/
class TblWdbeQCvrBcv1NCoreversion {

public:
	TblWdbeQCvrBcv1NCoreversion();
	virtual ~TblWdbeQCvrBcv1NCoreversion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrBcv1NCoreversion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCvrBcv1NCoreversion* rec);
	Sbecore::ubigint insertNewRec(WdbeQCvrBcv1NCoreversion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCvrBcv1NCoreversion& rst, WdbeQCvrBcv1NCoreversion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQCvrBcv1NCoreversion& rst);
	virtual void updateRec(WdbeQCvrBcv1NCoreversion* rec);
	virtual void updateRst(ListWdbeQCvrBcv1NCoreversion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrBcv1NCoreversion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCvrBcv1NCoreversion: C++ wrapper for table TblWdbeQCvrBcv1NCoreversion (MySQL database)
	*/
class MyTblWdbeQCvrBcv1NCoreversion : public TblWdbeQCvrBcv1NCoreversion, public Sbecore::MyTable {

public:
	MyTblWdbeQCvrBcv1NCoreversion();
	~MyTblWdbeQCvrBcv1NCoreversion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeQCvrBcv1NCoreversion* rec);
	void insertRst(ListWdbeQCvrBcv1NCoreversion& rst);
	void updateRec(WdbeQCvrBcv1NCoreversion* rec);
	void updateRst(ListWdbeQCvrBcv1NCoreversion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCvrBcv1NCoreversion: C++ wrapper for table TblWdbeQCvrBcv1NCoreversion (PgSQL database)
	*/
class PgTblWdbeQCvrBcv1NCoreversion : public TblWdbeQCvrBcv1NCoreversion, public Sbecore::PgTable {

public:
	PgTblWdbeQCvrBcv1NCoreversion();
	~PgTblWdbeQCvrBcv1NCoreversion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);

	Sbecore::ubigint insertRec(WdbeQCvrBcv1NCoreversion* rec);
	void insertRst(ListWdbeQCvrBcv1NCoreversion& rst);
	void updateRec(WdbeQCvrBcv1NCoreversion* rec);
	void updateRst(ListWdbeQCvrBcv1NCoreversion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrBcv1NCoreversion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrBcv1NCoreversion& rst);
};
#endif

#endif

