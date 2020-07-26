/**
	* \file WdbeQMtpMdl1NPort.h
	* Dbs and XML wrapper for table TblWdbeQMtpMdl1NPort (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPMDL1NPORT_H
#define WDBEQMTPMDL1NPORT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpMdl1NPort: record of TblWdbeQMtpMdl1NPort
	*/
class WdbeQMtpMdl1NPort {

public:
	WdbeQMtpMdl1NPort(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

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
	* ListWdbeQMtpMdl1NPort: recordset of TblWdbeQMtpMdl1NPort
	*/
class ListWdbeQMtpMdl1NPort {

public:
	ListWdbeQMtpMdl1NPort();
	ListWdbeQMtpMdl1NPort(const ListWdbeQMtpMdl1NPort& src);
	~ListWdbeQMtpMdl1NPort();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpMdl1NPort* rec);

	ListWdbeQMtpMdl1NPort& operator=(const ListWdbeQMtpMdl1NPort& src);

public:
	std::vector<WdbeQMtpMdl1NPort*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpMdl1NPort: C++ wrapper for table TblWdbeQMtpMdl1NPort
	*/
class TblWdbeQMtpMdl1NPort {

public:
	TblWdbeQMtpMdl1NPort();
	virtual ~TblWdbeQMtpMdl1NPort();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NPort** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NPort& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpMdl1NPort* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpMdl1NPort** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpMdl1NPort& rst, WdbeQMtpMdl1NPort** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWdbeQMtpMdl1NPort& rst);
	virtual void updateRec(WdbeQMtpMdl1NPort* rec);
	virtual void updateRst(ListWdbeQMtpMdl1NPort& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NPort** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NPort& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpMdl1NPort: C++ wrapper for table TblWdbeQMtpMdl1NPort (MySQL database)
	*/
class MyTblWdbeQMtpMdl1NPort : public TblWdbeQMtpMdl1NPort, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpMdl1NPort();
	~MyTblWdbeQMtpMdl1NPort();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NPort& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMdl1NPort* rec);
	void insertRst(ListWdbeQMtpMdl1NPort& rst);
	void updateRec(WdbeQMtpMdl1NPort* rec);
	void updateRst(ListWdbeQMtpMdl1NPort& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NPort& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpMdl1NPort: C++ wrapper for table TblWdbeQMtpMdl1NPort (PgSQL database)
	*/
class PgTblWdbeQMtpMdl1NPort : public TblWdbeQMtpMdl1NPort, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpMdl1NPort();
	~PgTblWdbeQMtpMdl1NPort();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpMdl1NPort& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpMdl1NPort& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMdl1NPort& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMdl1NPort* rec);
	void insertRst(ListWdbeQMtpMdl1NPort& rst);
	void updateRec(WdbeQMtpMdl1NPort* rec);
	void updateRst(ListWdbeQMtpMdl1NPort& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMdl1NPort** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMdl1NPort& rst);
};
#endif

#endif

