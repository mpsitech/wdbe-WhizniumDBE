/**
	* \file WdbeQUnt1NPeripheral.h
	* Dbs and XML wrapper for table TblWdbeQUnt1NPeripheral (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNT1NPERIPHERAL_H
#define WDBEQUNT1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUnt1NPeripheral: record of TblWdbeQUnt1NPeripheral
	*/
class WdbeQUnt1NPeripheral {

public:
	WdbeQUnt1NPeripheral(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUnt1NPeripheral: recordset of TblWdbeQUnt1NPeripheral
	*/
class ListWdbeQUnt1NPeripheral {

public:
	ListWdbeQUnt1NPeripheral();
	ListWdbeQUnt1NPeripheral(const ListWdbeQUnt1NPeripheral& src);
	~ListWdbeQUnt1NPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeQUnt1NPeripheral* rec);

	ListWdbeQUnt1NPeripheral& operator=(const ListWdbeQUnt1NPeripheral& src);

public:
	std::vector<WdbeQUnt1NPeripheral*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUnt1NPeripheral: C++ wrapper for table TblWdbeQUnt1NPeripheral
	*/
class TblWdbeQUnt1NPeripheral {

public:
	TblWdbeQUnt1NPeripheral();
	virtual ~TblWdbeQUnt1NPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUnt1NPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeQUnt1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUnt1NPeripheral& rst, WdbeQUnt1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUnt1NPeripheral& rst);
	virtual void updateRec(WdbeQUnt1NPeripheral* rec);
	virtual void updateRst(ListWdbeQUnt1NPeripheral& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUnt1NPeripheral: C++ wrapper for table TblWdbeQUnt1NPeripheral (MySQL database)
	*/
class MyTblWdbeQUnt1NPeripheral : public TblWdbeQUnt1NPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeQUnt1NPeripheral();
	~MyTblWdbeQUnt1NPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NPeripheral* rec);
	void insertRst(ListWdbeQUnt1NPeripheral& rst);
	void updateRec(WdbeQUnt1NPeripheral* rec);
	void updateRst(ListWdbeQUnt1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NPeripheral& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUnt1NPeripheral: C++ wrapper for table TblWdbeQUnt1NPeripheral (PgSQL database)
	*/
class PgTblWdbeQUnt1NPeripheral : public TblWdbeQUnt1NPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeQUnt1NPeripheral();
	~PgTblWdbeQUnt1NPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUnt1NPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUnt1NPeripheral& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NPeripheral* rec);
	void insertRst(ListWdbeQUnt1NPeripheral& rst);
	void updateRec(WdbeQUnt1NPeripheral* rec);
	void updateRst(ListWdbeQUnt1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NPeripheral& rst);
};
#endif

#endif

