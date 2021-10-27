/**
	* \file WdbeQSil1NInterrupt.h
	* Dbs and XML wrapper for table TblWdbeQSil1NInterrupt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NINTERRUPT_H
#define WDBEQSIL1NINTERRUPT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSil1NInterrupt: record of TblWdbeQSil1NInterrupt
	*/
class WdbeQSil1NInterrupt {

public:
	WdbeQSil1NInterrupt(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSil1NInterrupt: recordset of TblWdbeQSil1NInterrupt
	*/
class ListWdbeQSil1NInterrupt {

public:
	ListWdbeQSil1NInterrupt();
	ListWdbeQSil1NInterrupt(const ListWdbeQSil1NInterrupt& src);
	~ListWdbeQSil1NInterrupt();

	void clear();
	unsigned int size() const;
	void append(WdbeQSil1NInterrupt* rec);

	ListWdbeQSil1NInterrupt& operator=(const ListWdbeQSil1NInterrupt& src);

public:
	std::vector<WdbeQSil1NInterrupt*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSil1NInterrupt: C++ wrapper for table TblWdbeQSil1NInterrupt
	*/
class TblWdbeQSil1NInterrupt {

public:
	TblWdbeQSil1NInterrupt();
	virtual ~TblWdbeQSil1NInterrupt();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NInterrupt** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NInterrupt& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSil1NInterrupt* rec);
	Sbecore::ubigint insertNewRec(WdbeQSil1NInterrupt** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSil1NInterrupt& rst, WdbeQSil1NInterrupt** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSil1NInterrupt& rst);
	virtual void updateRec(WdbeQSil1NInterrupt* rec);
	virtual void updateRst(ListWdbeQSil1NInterrupt& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NInterrupt** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NInterrupt& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSil1NInterrupt: C++ wrapper for table TblWdbeQSil1NInterrupt (MySQL database)
	*/
class MyTblWdbeQSil1NInterrupt : public TblWdbeQSil1NInterrupt, public Sbecore::MyTable {

public:
	MyTblWdbeQSil1NInterrupt();
	~MyTblWdbeQSil1NInterrupt();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NInterrupt* rec);
	void insertRst(ListWdbeQSil1NInterrupt& rst);
	void updateRec(WdbeQSil1NInterrupt* rec);
	void updateRst(ListWdbeQSil1NInterrupt& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NInterrupt& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSil1NInterrupt: C++ wrapper for table TblWdbeQSil1NInterrupt (PgSQL database)
	*/
class PgTblWdbeQSil1NInterrupt : public TblWdbeQSil1NInterrupt, public Sbecore::PgTable {

public:
	PgTblWdbeQSil1NInterrupt();
	~PgTblWdbeQSil1NInterrupt();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSil1NInterrupt& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSil1NInterrupt& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NInterrupt* rec);
	void insertRst(ListWdbeQSil1NInterrupt& rst);
	void updateRec(WdbeQSil1NInterrupt* rec);
	void updateRst(ListWdbeQSil1NInterrupt& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NInterrupt** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NInterrupt& rst);
};
#endif

#endif
