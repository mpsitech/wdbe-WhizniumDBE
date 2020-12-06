/**
	* \file WdbeQSil1NPeripheral.h
	* Dbs and XML wrapper for table TblWdbeQSil1NPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NPERIPHERAL_H
#define WDBEQSIL1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSil1NPeripheral: record of TblWdbeQSil1NPeripheral
	*/
class WdbeQSil1NPeripheral {

public:
	WdbeQSil1NPeripheral(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSil1NPeripheral: recordset of TblWdbeQSil1NPeripheral
	*/
class ListWdbeQSil1NPeripheral {

public:
	ListWdbeQSil1NPeripheral();
	ListWdbeQSil1NPeripheral(const ListWdbeQSil1NPeripheral& src);
	~ListWdbeQSil1NPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeQSil1NPeripheral* rec);

	ListWdbeQSil1NPeripheral& operator=(const ListWdbeQSil1NPeripheral& src);

public:
	std::vector<WdbeQSil1NPeripheral*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSil1NPeripheral: C++ wrapper for table TblWdbeQSil1NPeripheral
	*/
class TblWdbeQSil1NPeripheral {

public:
	TblWdbeQSil1NPeripheral();
	virtual ~TblWdbeQSil1NPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSil1NPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeQSil1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSil1NPeripheral& rst, WdbeQSil1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSil1NPeripheral& rst);
	virtual void updateRec(WdbeQSil1NPeripheral* rec);
	virtual void updateRst(ListWdbeQSil1NPeripheral& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSil1NPeripheral: C++ wrapper for table TblWdbeQSil1NPeripheral (MySQL database)
	*/
class MyTblWdbeQSil1NPeripheral : public TblWdbeQSil1NPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeQSil1NPeripheral();
	~MyTblWdbeQSil1NPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NPeripheral* rec);
	void insertRst(ListWdbeQSil1NPeripheral& rst);
	void updateRec(WdbeQSil1NPeripheral* rec);
	void updateRst(ListWdbeQSil1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NPeripheral& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSil1NPeripheral: C++ wrapper for table TblWdbeQSil1NPeripheral (PgSQL database)
	*/
class PgTblWdbeQSil1NPeripheral : public TblWdbeQSil1NPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeQSil1NPeripheral();
	~PgTblWdbeQSil1NPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSil1NPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSil1NPeripheral& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NPeripheral* rec);
	void insertRst(ListWdbeQSil1NPeripheral& rst);
	void updateRec(WdbeQSil1NPeripheral* rec);
	void updateRst(ListWdbeQSil1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NPeripheral& rst);
};
#endif

#endif
