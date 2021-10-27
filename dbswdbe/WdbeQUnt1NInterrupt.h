/**
	* \file WdbeQUnt1NInterrupt.h
	* Dbs and XML wrapper for table TblWdbeQUnt1NInterrupt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQUNT1NINTERRUPT_H
#define WDBEQUNT1NINTERRUPT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUnt1NInterrupt: record of TblWdbeQUnt1NInterrupt
	*/
class WdbeQUnt1NInterrupt {

public:
	WdbeQUnt1NInterrupt(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUnt1NInterrupt: recordset of TblWdbeQUnt1NInterrupt
	*/
class ListWdbeQUnt1NInterrupt {

public:
	ListWdbeQUnt1NInterrupt();
	ListWdbeQUnt1NInterrupt(const ListWdbeQUnt1NInterrupt& src);
	~ListWdbeQUnt1NInterrupt();

	void clear();
	unsigned int size() const;
	void append(WdbeQUnt1NInterrupt* rec);

	ListWdbeQUnt1NInterrupt& operator=(const ListWdbeQUnt1NInterrupt& src);

public:
	std::vector<WdbeQUnt1NInterrupt*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUnt1NInterrupt: C++ wrapper for table TblWdbeQUnt1NInterrupt
	*/
class TblWdbeQUnt1NInterrupt {

public:
	TblWdbeQUnt1NInterrupt();
	virtual ~TblWdbeQUnt1NInterrupt();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NInterrupt** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NInterrupt& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUnt1NInterrupt* rec);
	Sbecore::ubigint insertNewRec(WdbeQUnt1NInterrupt** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUnt1NInterrupt& rst, WdbeQUnt1NInterrupt** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUnt1NInterrupt& rst);
	virtual void updateRec(WdbeQUnt1NInterrupt* rec);
	virtual void updateRst(ListWdbeQUnt1NInterrupt& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NInterrupt** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NInterrupt& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUnt1NInterrupt: C++ wrapper for table TblWdbeQUnt1NInterrupt (MySQL database)
	*/
class MyTblWdbeQUnt1NInterrupt : public TblWdbeQUnt1NInterrupt, public Sbecore::MyTable {

public:
	MyTblWdbeQUnt1NInterrupt();
	~MyTblWdbeQUnt1NInterrupt();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NInterrupt* rec);
	void insertRst(ListWdbeQUnt1NInterrupt& rst);
	void updateRec(WdbeQUnt1NInterrupt* rec);
	void updateRst(ListWdbeQUnt1NInterrupt& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NInterrupt& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUnt1NInterrupt: C++ wrapper for table TblWdbeQUnt1NInterrupt (PgSQL database)
	*/
class PgTblWdbeQUnt1NInterrupt : public TblWdbeQUnt1NInterrupt, public Sbecore::PgTable {

public:
	PgTblWdbeQUnt1NInterrupt();
	~PgTblWdbeQUnt1NInterrupt();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUnt1NInterrupt& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUnt1NInterrupt& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NInterrupt& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NInterrupt* rec);
	void insertRst(ListWdbeQUnt1NInterrupt& rst);
	void updateRec(WdbeQUnt1NInterrupt* rec);
	void updateRst(ListWdbeQUnt1NInterrupt& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NInterrupt** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NInterrupt& rst);
};
#endif

#endif
