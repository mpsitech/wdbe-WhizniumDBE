/**
	* \file WdbeQModMdl1NGeneric.h
	* Dbs and XML wrapper for table TblWdbeQModMdl1NGeneric (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODMDL1NGENERIC_H
#define WDBEQMODMDL1NGENERIC_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModMdl1NGeneric: record of TblWdbeQModMdl1NGeneric
	*/
class WdbeQModMdl1NGeneric {

public:
	WdbeQModMdl1NGeneric(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint mdlNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModMdl1NGeneric: recordset of TblWdbeQModMdl1NGeneric
	*/
class ListWdbeQModMdl1NGeneric {

public:
	ListWdbeQModMdl1NGeneric();
	ListWdbeQModMdl1NGeneric(const ListWdbeQModMdl1NGeneric& src);
	~ListWdbeQModMdl1NGeneric();

	void clear();
	unsigned int size() const;
	void append(WdbeQModMdl1NGeneric* rec);

	ListWdbeQModMdl1NGeneric& operator=(const ListWdbeQModMdl1NGeneric& src);

public:
	std::vector<WdbeQModMdl1NGeneric*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModMdl1NGeneric: C++ wrapper for table TblWdbeQModMdl1NGeneric
	*/
class TblWdbeQModMdl1NGeneric {

public:
	TblWdbeQModMdl1NGeneric();
	virtual ~TblWdbeQModMdl1NGeneric();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NGeneric** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NGeneric& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModMdl1NGeneric* rec);
	Sbecore::ubigint insertNewRec(WdbeQModMdl1NGeneric** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModMdl1NGeneric& rst, WdbeQModMdl1NGeneric** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWdbeQModMdl1NGeneric& rst);
	virtual void updateRec(WdbeQModMdl1NGeneric* rec);
	virtual void updateRst(ListWdbeQModMdl1NGeneric& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NGeneric** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NGeneric& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModMdl1NGeneric: C++ wrapper for table TblWdbeQModMdl1NGeneric (MySQL database)
	*/
class MyTblWdbeQModMdl1NGeneric : public TblWdbeQModMdl1NGeneric, public Sbecore::MyTable {

public:
	MyTblWdbeQModMdl1NGeneric();
	~MyTblWdbeQModMdl1NGeneric();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NGeneric& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NGeneric* rec);
	void insertRst(ListWdbeQModMdl1NGeneric& rst);
	void updateRec(WdbeQModMdl1NGeneric* rec);
	void updateRst(ListWdbeQModMdl1NGeneric& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NGeneric& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModMdl1NGeneric: C++ wrapper for table TblWdbeQModMdl1NGeneric (PgSQL database)
	*/
class PgTblWdbeQModMdl1NGeneric : public TblWdbeQModMdl1NGeneric, public Sbecore::PgTable {

public:
	PgTblWdbeQModMdl1NGeneric();
	~PgTblWdbeQModMdl1NGeneric();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModMdl1NGeneric& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModMdl1NGeneric& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NGeneric& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NGeneric* rec);
	void insertRst(ListWdbeQModMdl1NGeneric& rst);
	void updateRec(WdbeQModMdl1NGeneric* rec);
	void updateRst(ListWdbeQModMdl1NGeneric& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NGeneric& rst);
};
#endif

#endif
