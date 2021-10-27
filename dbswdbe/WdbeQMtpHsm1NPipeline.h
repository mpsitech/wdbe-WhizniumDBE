/**
	* \file WdbeQMtpHsm1NPipeline.h
	* Dbs and XML wrapper for table TblWdbeQMtpHsm1NPipeline (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPHSM1NPIPELINE_H
#define WDBEQMTPHSM1NPIPELINE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpHsm1NPipeline: record of TblWdbeQMtpHsm1NPipeline
	*/
class WdbeQMtpHsm1NPipeline {

public:
	WdbeQMtpHsm1NPipeline(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpHsm1NPipeline: recordset of TblWdbeQMtpHsm1NPipeline
	*/
class ListWdbeQMtpHsm1NPipeline {

public:
	ListWdbeQMtpHsm1NPipeline();
	ListWdbeQMtpHsm1NPipeline(const ListWdbeQMtpHsm1NPipeline& src);
	~ListWdbeQMtpHsm1NPipeline();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpHsm1NPipeline* rec);

	ListWdbeQMtpHsm1NPipeline& operator=(const ListWdbeQMtpHsm1NPipeline& src);

public:
	std::vector<WdbeQMtpHsm1NPipeline*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpHsm1NPipeline: C++ wrapper for table TblWdbeQMtpHsm1NPipeline
	*/
class TblWdbeQMtpHsm1NPipeline {

public:
	TblWdbeQMtpHsm1NPipeline();
	virtual ~TblWdbeQMtpHsm1NPipeline();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpHsm1NPipeline** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpHsm1NPipeline& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpHsm1NPipeline* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpHsm1NPipeline** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpHsm1NPipeline& rst, WdbeQMtpHsm1NPipeline** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpHsm1NPipeline& rst);
	virtual void updateRec(WdbeQMtpHsm1NPipeline* rec);
	virtual void updateRst(ListWdbeQMtpHsm1NPipeline& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpHsm1NPipeline** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpHsm1NPipeline& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpHsm1NPipeline: C++ wrapper for table TblWdbeQMtpHsm1NPipeline (MySQL database)
	*/
class MyTblWdbeQMtpHsm1NPipeline : public TblWdbeQMtpHsm1NPipeline, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpHsm1NPipeline();
	~MyTblWdbeQMtpHsm1NPipeline();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpHsm1NPipeline& rst);

	Sbecore::ubigint insertRec(WdbeQMtpHsm1NPipeline* rec);
	void insertRst(ListWdbeQMtpHsm1NPipeline& rst);
	void updateRec(WdbeQMtpHsm1NPipeline* rec);
	void updateRst(ListWdbeQMtpHsm1NPipeline& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpHsm1NPipeline& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpHsm1NPipeline: C++ wrapper for table TblWdbeQMtpHsm1NPipeline (PgSQL database)
	*/
class PgTblWdbeQMtpHsm1NPipeline : public TblWdbeQMtpHsm1NPipeline, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpHsm1NPipeline();
	~PgTblWdbeQMtpHsm1NPipeline();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpHsm1NPipeline& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpHsm1NPipeline& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpHsm1NPipeline& rst);

	Sbecore::ubigint insertRec(WdbeQMtpHsm1NPipeline* rec);
	void insertRst(ListWdbeQMtpHsm1NPipeline& rst);
	void updateRec(WdbeQMtpHsm1NPipeline* rec);
	void updateRst(ListWdbeQMtpHsm1NPipeline& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpHsm1NPipeline** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpHsm1NPipeline& rst);
};
#endif

#endif
