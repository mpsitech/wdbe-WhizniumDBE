/**
	* \file WdbeQModCor1NImbuf.h
	* Dbs and XML wrapper for table TblWdbeQModCor1NImbuf (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODCOR1NIMBUF_H
#define WDBEQMODCOR1NIMBUF_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCor1NImbuf: record of TblWdbeQModCor1NImbuf
	*/
class WdbeQModCor1NImbuf {

public:
	WdbeQModCor1NImbuf(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQModCor1NImbuf: recordset of TblWdbeQModCor1NImbuf
	*/
class ListWdbeQModCor1NImbuf {

public:
	ListWdbeQModCor1NImbuf();
	ListWdbeQModCor1NImbuf(const ListWdbeQModCor1NImbuf& src);
	~ListWdbeQModCor1NImbuf();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCor1NImbuf* rec);

	ListWdbeQModCor1NImbuf& operator=(const ListWdbeQModCor1NImbuf& src);

public:
	std::vector<WdbeQModCor1NImbuf*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCor1NImbuf: C++ wrapper for table TblWdbeQModCor1NImbuf
	*/
class TblWdbeQModCor1NImbuf {

public:
	TblWdbeQModCor1NImbuf();
	virtual ~TblWdbeQModCor1NImbuf();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCor1NImbuf** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCor1NImbuf& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCor1NImbuf* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCor1NImbuf** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCor1NImbuf& rst, WdbeQModCor1NImbuf** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModCor1NImbuf& rst);
	virtual void updateRec(WdbeQModCor1NImbuf* rec);
	virtual void updateRst(ListWdbeQModCor1NImbuf& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCor1NImbuf** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCor1NImbuf& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCor1NImbuf: C++ wrapper for table TblWdbeQModCor1NImbuf (MySQL database)
	*/
class MyTblWdbeQModCor1NImbuf : public TblWdbeQModCor1NImbuf, public Sbecore::MyTable {

public:
	MyTblWdbeQModCor1NImbuf();
	~MyTblWdbeQModCor1NImbuf();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCor1NImbuf& rst);

	Sbecore::ubigint insertRec(WdbeQModCor1NImbuf* rec);
	void insertRst(ListWdbeQModCor1NImbuf& rst);
	void updateRec(WdbeQModCor1NImbuf* rec);
	void updateRst(ListWdbeQModCor1NImbuf& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCor1NImbuf& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCor1NImbuf: C++ wrapper for table TblWdbeQModCor1NImbuf (PgSQL database)
	*/
class PgTblWdbeQModCor1NImbuf : public TblWdbeQModCor1NImbuf, public Sbecore::PgTable {

public:
	PgTblWdbeQModCor1NImbuf();
	~PgTblWdbeQModCor1NImbuf();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCor1NImbuf& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCor1NImbuf& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCor1NImbuf& rst);

	Sbecore::ubigint insertRec(WdbeQModCor1NImbuf* rec);
	void insertRst(ListWdbeQModCor1NImbuf& rst);
	void updateRec(WdbeQModCor1NImbuf* rec);
	void updateRst(ListWdbeQModCor1NImbuf& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCor1NImbuf** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCor1NImbuf& rst);
};
#endif

#endif

