/**
	* \file WdbeQModMdl1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQModMdl1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODMDL1NSIGNAL_H
#define WDBEQMODMDL1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModMdl1NSignal: record of TblWdbeQModMdl1NSignal
	*/
class WdbeQModMdl1NSignal {

public:
	WdbeQModMdl1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

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
	* ListWdbeQModMdl1NSignal: recordset of TblWdbeQModMdl1NSignal
	*/
class ListWdbeQModMdl1NSignal {

public:
	ListWdbeQModMdl1NSignal();
	ListWdbeQModMdl1NSignal(const ListWdbeQModMdl1NSignal& src);
	~ListWdbeQModMdl1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQModMdl1NSignal* rec);

	ListWdbeQModMdl1NSignal& operator=(const ListWdbeQModMdl1NSignal& src);

public:
	std::vector<WdbeQModMdl1NSignal*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModMdl1NSignal: C++ wrapper for table TblWdbeQModMdl1NSignal
	*/
class TblWdbeQModMdl1NSignal {

public:
	TblWdbeQModMdl1NSignal();
	virtual ~TblWdbeQModMdl1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModMdl1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQModMdl1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModMdl1NSignal& rst, WdbeQModMdl1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWdbeQModMdl1NSignal& rst);
	virtual void updateRec(WdbeQModMdl1NSignal* rec);
	virtual void updateRst(ListWdbeQModMdl1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModMdl1NSignal: C++ wrapper for table TblWdbeQModMdl1NSignal (MySQL database)
	*/
class MyTblWdbeQModMdl1NSignal : public TblWdbeQModMdl1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQModMdl1NSignal();
	~MyTblWdbeQModMdl1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NSignal* rec);
	void insertRst(ListWdbeQModMdl1NSignal& rst);
	void updateRec(WdbeQModMdl1NSignal* rec);
	void updateRst(ListWdbeQModMdl1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModMdl1NSignal: C++ wrapper for table TblWdbeQModMdl1NSignal (PgSQL database)
	*/
class PgTblWdbeQModMdl1NSignal : public TblWdbeQModMdl1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQModMdl1NSignal();
	~PgTblWdbeQModMdl1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModMdl1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModMdl1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMdl1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQModMdl1NSignal* rec);
	void insertRst(ListWdbeQModMdl1NSignal& rst);
	void updateRec(WdbeQModMdl1NSignal* rec);
	void updateRst(ListWdbeQModMdl1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMdl1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMdl1NSignal& rst);
};
#endif

#endif

