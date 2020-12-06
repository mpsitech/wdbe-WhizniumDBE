/**
	* \file WdbeQModMdl1NPort.h
	* Dbs and XML wrapper for table TblWdbeQModMdl1NPort (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODMDL1NPORT_H
#define WDBEQMODMDL1NPORT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModMdl1NPort: record of TblWdbeQModMdl1NPort
	*/
class WdbeQModMdl1NPort {

public:
	WdbeQModMdl1NPort(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

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
	* ListWdbeQModMdl1NPort: recordset of TblWdbeQModMdl1NPort
	*/
class ListWdbeQModMdl1NPort {

public:
	ListWdbeQModMdl1NPort();
	ListWdbeQModMdl1NPort(const ListWdbeQModMdl1NPort& src);
	~ListWdbeQModMdl1NPort();

	void clear();
	unsigned int size() const;
	void append(WdbeQModMdl1NPort* rec);

	ListWdbeQModMdl1NPort& operator=(const ListWdbeQModMdl1NPort& src);

public:
	std::vector<WdbeQModMdl1NPort*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModMdl1NPort: C++ wrapper for table TblWdbeQModMdl1NPort
	*/
class TblWdbeQModMdl1NPort {

public:
	TblWdbeQModMdl1NPort();
	virtual ~TblWdbeQModMdl1NPort();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NPort** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NPort& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModMdl1NPort* rec);
	Sbecore::ubigint insertNewRec(WdbeQModMdl1NPort** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModMdl1NPort& rst, WdbeQModMdl1NPort** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWdbeQModMdl1NPort& rst);
	virtual void updateRec(WdbeQModMdl1NPort* rec);
	virtual void updateRst(ListWdbeQModMdl1NPort& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NPort** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NPort& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModMdl1NPort: C++ wrapper for table TblWdbeQModMdl1NPort (MySQL database)
	*/
class MyTblWdbeQModMdl1NPort : public TblWdbeQModMdl1NPort, public Sbecore::MyTable {

public:
	MyTblWdbeQModMdl1NPort();
	~MyTblWdbeQModMdl1NPort();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NPort& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NPort* rec);
	void insertRst(ListWdbeQModMdl1NPort& rst);
	void updateRec(WdbeQModMdl1NPort* rec);
	void updateRst(ListWdbeQModMdl1NPort& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NPort& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModMdl1NPort: C++ wrapper for table TblWdbeQModMdl1NPort (PgSQL database)
	*/
class PgTblWdbeQModMdl1NPort : public TblWdbeQModMdl1NPort, public Sbecore::PgTable {

public:
	PgTblWdbeQModMdl1NPort();
	~PgTblWdbeQModMdl1NPort();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModMdl1NPort& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModMdl1NPort& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NPort& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NPort* rec);
	void insertRst(ListWdbeQModMdl1NPort& rst);
	void updateRec(WdbeQModMdl1NPort* rec);
	void updateRst(ListWdbeQModMdl1NPort& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NPort** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NPort& rst);
};
#endif

#endif
