/**
	* \file WdbeQMchSup1NMachine.h
	* Dbs and XML wrapper for table TblWdbeQMchSup1NMachine (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCHSUP1NMACHINE_H
#define WDBEQMCHSUP1NMACHINE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMchSup1NMachine: record of TblWdbeQMchSup1NMachine
	*/
class WdbeQMchSup1NMachine {

public:
	WdbeQMchSup1NMachine(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMchSup1NMachine: recordset of TblWdbeQMchSup1NMachine
	*/
class ListWdbeQMchSup1NMachine {

public:
	ListWdbeQMchSup1NMachine();
	ListWdbeQMchSup1NMachine(const ListWdbeQMchSup1NMachine& src);
	~ListWdbeQMchSup1NMachine();

	void clear();
	unsigned int size() const;
	void append(WdbeQMchSup1NMachine* rec);

	ListWdbeQMchSup1NMachine& operator=(const ListWdbeQMchSup1NMachine& src);

public:
	std::vector<WdbeQMchSup1NMachine*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMchSup1NMachine: C++ wrapper for table TblWdbeQMchSup1NMachine
	*/
class TblWdbeQMchSup1NMachine {

public:
	TblWdbeQMchSup1NMachine();
	virtual ~TblWdbeQMchSup1NMachine();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMchSup1NMachine** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchSup1NMachine& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMchSup1NMachine* rec);
	Sbecore::ubigint insertNewRec(WdbeQMchSup1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMchSup1NMachine& rst, WdbeQMchSup1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMchSup1NMachine& rst);
	virtual void updateRec(WdbeQMchSup1NMachine* rec);
	virtual void updateRst(ListWdbeQMchSup1NMachine& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchSup1NMachine** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchSup1NMachine& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMchSup1NMachine: C++ wrapper for table TblWdbeQMchSup1NMachine (MySQL database)
	*/
class MyTblWdbeQMchSup1NMachine : public TblWdbeQMchSup1NMachine, public Sbecore::MyTable {

public:
	MyTblWdbeQMchSup1NMachine();
	~MyTblWdbeQMchSup1NMachine();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchSup1NMachine& rst);

	Sbecore::ubigint insertRec(WdbeQMchSup1NMachine* rec);
	void insertRst(ListWdbeQMchSup1NMachine& rst);
	void updateRec(WdbeQMchSup1NMachine* rec);
	void updateRst(ListWdbeQMchSup1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchSup1NMachine& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMchSup1NMachine: C++ wrapper for table TblWdbeQMchSup1NMachine (PgSQL database)
	*/
class PgTblWdbeQMchSup1NMachine : public TblWdbeQMchSup1NMachine, public Sbecore::PgTable {

public:
	PgTblWdbeQMchSup1NMachine();
	~PgTblWdbeQMchSup1NMachine();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMchSup1NMachine& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMchSup1NMachine& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchSup1NMachine& rst);

	Sbecore::ubigint insertRec(WdbeQMchSup1NMachine* rec);
	void insertRst(ListWdbeQMchSup1NMachine& rst);
	void updateRec(WdbeQMchSup1NMachine* rec);
	void updateRst(ListWdbeQMchSup1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchSup1NMachine& rst);
};
#endif

#endif
