/**
	* \file WdbeQPrsADetail.h
	* Dbs and XML wrapper for table TblWdbeQPrsADetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPRSADETAIL_H
#define WDBEQPRSADETAIL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrsADetail: record of TblWdbeQPrsADetail
	*/
class WdbeQPrsADetail {

public:
	WdbeQPrsADetail(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrsADetail: recordset of TblWdbeQPrsADetail
	*/
class ListWdbeQPrsADetail {

public:
	ListWdbeQPrsADetail();
	ListWdbeQPrsADetail(const ListWdbeQPrsADetail& src);
	~ListWdbeQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrsADetail* rec);

	ListWdbeQPrsADetail& operator=(const ListWdbeQPrsADetail& src);

public:
	std::vector<WdbeQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrsADetail: C++ wrapper for table TblWdbeQPrsADetail
	*/
class TblWdbeQPrsADetail {

public:
	TblWdbeQPrsADetail();
	virtual ~TblWdbeQPrsADetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsADetail& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrsADetail* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrsADetail& rst, WdbeQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQPrsADetail& rst);
	virtual void updateRec(WdbeQPrsADetail* rec);
	virtual void updateRst(ListWdbeQPrsADetail& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsADetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrsADetail: C++ wrapper for table TblWdbeQPrsADetail (MySQL database)
	*/
class MyTblWdbeQPrsADetail : public TblWdbeQPrsADetail, public Sbecore::MyTable {

public:
	MyTblWdbeQPrsADetail();
	~MyTblWdbeQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsADetail& rst);

	Sbecore::ubigint insertRec(WdbeQPrsADetail* rec);
	void insertRst(ListWdbeQPrsADetail& rst);
	void updateRec(WdbeQPrsADetail* rec);
	void updateRst(ListWdbeQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsADetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrsADetail: C++ wrapper for table TblWdbeQPrsADetail (PgSQL database)
	*/
class PgTblWdbeQPrsADetail : public TblWdbeQPrsADetail, public Sbecore::PgTable {

public:
	PgTblWdbeQPrsADetail();
	~PgTblWdbeQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrsADetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsADetail& rst);

	Sbecore::ubigint insertRec(WdbeQPrsADetail* rec);
	void insertRst(ListWdbeQPrsADetail& rst);
	void updateRec(WdbeQPrsADetail* rec);
	void updateRst(ListWdbeQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsADetail& rst);
};
#endif

#endif

