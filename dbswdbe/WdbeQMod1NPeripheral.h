/**
	* \file WdbeQMod1NPeripheral.h
	* Dbs and XML wrapper for table TblWdbeQMod1NPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMOD1NPERIPHERAL_H
#define WDBEQMOD1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMod1NPeripheral: record of TblWdbeQMod1NPeripheral
	*/
class WdbeQMod1NPeripheral {

public:
	WdbeQMod1NPeripheral(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMod1NPeripheral: recordset of TblWdbeQMod1NPeripheral
	*/
class ListWdbeQMod1NPeripheral {

public:
	ListWdbeQMod1NPeripheral();
	ListWdbeQMod1NPeripheral(const ListWdbeQMod1NPeripheral& src);
	~ListWdbeQMod1NPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeQMod1NPeripheral* rec);

	ListWdbeQMod1NPeripheral& operator=(const ListWdbeQMod1NPeripheral& src);

public:
	std::vector<WdbeQMod1NPeripheral*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMod1NPeripheral: C++ wrapper for table TblWdbeQMod1NPeripheral
	*/
class TblWdbeQMod1NPeripheral {

public:
	TblWdbeQMod1NPeripheral();
	virtual ~TblWdbeQMod1NPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMod1NPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeQMod1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMod1NPeripheral& rst, WdbeQMod1NPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMod1NPeripheral& rst);
	virtual void updateRec(WdbeQMod1NPeripheral* rec);
	virtual void updateRst(ListWdbeQMod1NPeripheral& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NPeripheral** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMod1NPeripheral: C++ wrapper for table TblWdbeQMod1NPeripheral (MySQL database)
	*/
class MyTblWdbeQMod1NPeripheral : public TblWdbeQMod1NPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeQMod1NPeripheral();
	~MyTblWdbeQMod1NPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NPeripheral* rec);
	void insertRst(ListWdbeQMod1NPeripheral& rst);
	void updateRec(WdbeQMod1NPeripheral* rec);
	void updateRst(ListWdbeQMod1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NPeripheral& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMod1NPeripheral: C++ wrapper for table TblWdbeQMod1NPeripheral (PgSQL database)
	*/
class PgTblWdbeQMod1NPeripheral : public TblWdbeQMod1NPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeQMod1NPeripheral();
	~PgTblWdbeQMod1NPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMod1NPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMod1NPeripheral& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NPeripheral* rec);
	void insertRst(ListWdbeQMod1NPeripheral& rst);
	void updateRec(WdbeQMod1NPeripheral* rec);
	void updateRst(ListWdbeQMod1NPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NPeripheral& rst);
};
#endif

#endif
