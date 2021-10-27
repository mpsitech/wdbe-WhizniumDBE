/**
	* \file WdbeQModHsm1NPipeline.h
	* Dbs and XML wrapper for table TblWdbeQModHsm1NPipeline (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODHSM1NPIPELINE_H
#define WDBEQMODHSM1NPIPELINE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModHsm1NPipeline: record of TblWdbeQModHsm1NPipeline
	*/
class WdbeQModHsm1NPipeline {

public:
	WdbeQModHsm1NPipeline(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModHsm1NPipeline: recordset of TblWdbeQModHsm1NPipeline
	*/
class ListWdbeQModHsm1NPipeline {

public:
	ListWdbeQModHsm1NPipeline();
	ListWdbeQModHsm1NPipeline(const ListWdbeQModHsm1NPipeline& src);
	~ListWdbeQModHsm1NPipeline();

	void clear();
	unsigned int size() const;
	void append(WdbeQModHsm1NPipeline* rec);

	ListWdbeQModHsm1NPipeline& operator=(const ListWdbeQModHsm1NPipeline& src);

public:
	std::vector<WdbeQModHsm1NPipeline*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModHsm1NPipeline: C++ wrapper for table TblWdbeQModHsm1NPipeline
	*/
class TblWdbeQModHsm1NPipeline {

public:
	TblWdbeQModHsm1NPipeline();
	virtual ~TblWdbeQModHsm1NPipeline();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModHsm1NPipeline** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModHsm1NPipeline& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModHsm1NPipeline* rec);
	Sbecore::ubigint insertNewRec(WdbeQModHsm1NPipeline** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModHsm1NPipeline& rst, WdbeQModHsm1NPipeline** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModHsm1NPipeline& rst);
	virtual void updateRec(WdbeQModHsm1NPipeline* rec);
	virtual void updateRst(ListWdbeQModHsm1NPipeline& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModHsm1NPipeline** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModHsm1NPipeline& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModHsm1NPipeline: C++ wrapper for table TblWdbeQModHsm1NPipeline (MySQL database)
	*/
class MyTblWdbeQModHsm1NPipeline : public TblWdbeQModHsm1NPipeline, public Sbecore::MyTable {

public:
	MyTblWdbeQModHsm1NPipeline();
	~MyTblWdbeQModHsm1NPipeline();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModHsm1NPipeline& rst);

	Sbecore::ubigint insertRec(WdbeQModHsm1NPipeline* rec);
	void insertRst(ListWdbeQModHsm1NPipeline& rst);
	void updateRec(WdbeQModHsm1NPipeline* rec);
	void updateRst(ListWdbeQModHsm1NPipeline& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModHsm1NPipeline& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModHsm1NPipeline: C++ wrapper for table TblWdbeQModHsm1NPipeline (PgSQL database)
	*/
class PgTblWdbeQModHsm1NPipeline : public TblWdbeQModHsm1NPipeline, public Sbecore::PgTable {

public:
	PgTblWdbeQModHsm1NPipeline();
	~PgTblWdbeQModHsm1NPipeline();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModHsm1NPipeline& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModHsm1NPipeline& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModHsm1NPipeline& rst);

	Sbecore::ubigint insertRec(WdbeQModHsm1NPipeline* rec);
	void insertRst(ListWdbeQModHsm1NPipeline& rst);
	void updateRec(WdbeQModHsm1NPipeline* rec);
	void updateRst(ListWdbeQModHsm1NPipeline& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModHsm1NPipeline& rst);
};
#endif

#endif
