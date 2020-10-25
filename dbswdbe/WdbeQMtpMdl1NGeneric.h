/**
	* \file WdbeQMtpMdl1NGeneric.h
	* Dbs and XML wrapper for table TblWdbeQMtpMdl1NGeneric (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPMDL1NGENERIC_H
#define WDBEQMTPMDL1NGENERIC_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpMdl1NGeneric: record of TblWdbeQMtpMdl1NGeneric
	*/
class WdbeQMtpMdl1NGeneric {

public:
	WdbeQMtpMdl1NGeneric(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint mdlNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQMtpMdl1NGeneric: recordset of TblWdbeQMtpMdl1NGeneric
	*/
class ListWdbeQMtpMdl1NGeneric {

public:
	ListWdbeQMtpMdl1NGeneric();
	ListWdbeQMtpMdl1NGeneric(const ListWdbeQMtpMdl1NGeneric& src);
	~ListWdbeQMtpMdl1NGeneric();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpMdl1NGeneric* rec);

	ListWdbeQMtpMdl1NGeneric& operator=(const ListWdbeQMtpMdl1NGeneric& src);

public:
	std::vector<WdbeQMtpMdl1NGeneric*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpMdl1NGeneric: C++ wrapper for table TblWdbeQMtpMdl1NGeneric
	*/
class TblWdbeQMtpMdl1NGeneric {

public:
	TblWdbeQMtpMdl1NGeneric();
	virtual ~TblWdbeQMtpMdl1NGeneric();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NGeneric** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NGeneric& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpMdl1NGeneric* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpMdl1NGeneric** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpMdl1NGeneric& rst, WdbeQMtpMdl1NGeneric** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWdbeQMtpMdl1NGeneric& rst);
	virtual void updateRec(WdbeQMtpMdl1NGeneric* rec);
	virtual void updateRst(ListWdbeQMtpMdl1NGeneric& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NGeneric** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NGeneric& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpMdl1NGeneric: C++ wrapper for table TblWdbeQMtpMdl1NGeneric (MySQL database)
	*/
class MyTblWdbeQMtpMdl1NGeneric : public TblWdbeQMtpMdl1NGeneric, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpMdl1NGeneric();
	~MyTblWdbeQMtpMdl1NGeneric();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NGeneric& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMdl1NGeneric* rec);
	void insertRst(ListWdbeQMtpMdl1NGeneric& rst);
	void updateRec(WdbeQMtpMdl1NGeneric* rec);
	void updateRst(ListWdbeQMtpMdl1NGeneric& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NGeneric& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpMdl1NGeneric: C++ wrapper for table TblWdbeQMtpMdl1NGeneric (PgSQL database)
	*/
class PgTblWdbeQMtpMdl1NGeneric : public TblWdbeQMtpMdl1NGeneric, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpMdl1NGeneric();
	~PgTblWdbeQMtpMdl1NGeneric();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpMdl1NGeneric& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpMdl1NGeneric& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NGeneric& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMdl1NGeneric* rec);
	void insertRst(ListWdbeQMtpMdl1NGeneric& rst);
	void updateRec(WdbeQMtpMdl1NGeneric* rec);
	void updateRst(ListWdbeQMtpMdl1NGeneric& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NGeneric** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NGeneric& rst);
};
#endif

#endif

