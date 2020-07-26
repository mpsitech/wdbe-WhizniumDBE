/**
	* \file WdbeQBnk1NPin.h
	* Dbs and XML wrapper for table TblWdbeQBnk1NPin (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQBNK1NPIN_H
#define WDBEQBNK1NPIN_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQBnk1NPin: record of TblWdbeQBnk1NPin
	*/
class WdbeQBnk1NPin {

public:
	WdbeQBnk1NPin(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQBnk1NPin: recordset of TblWdbeQBnk1NPin
	*/
class ListWdbeQBnk1NPin {

public:
	ListWdbeQBnk1NPin();
	ListWdbeQBnk1NPin(const ListWdbeQBnk1NPin& src);
	~ListWdbeQBnk1NPin();

	void clear();
	unsigned int size() const;
	void append(WdbeQBnk1NPin* rec);

	ListWdbeQBnk1NPin& operator=(const ListWdbeQBnk1NPin& src);

public:
	std::vector<WdbeQBnk1NPin*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQBnk1NPin: C++ wrapper for table TblWdbeQBnk1NPin
	*/
class TblWdbeQBnk1NPin {

public:
	TblWdbeQBnk1NPin();
	virtual ~TblWdbeQBnk1NPin();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQBnk1NPin** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnk1NPin& rst);

	virtual Sbecore::ubigint insertRec(WdbeQBnk1NPin* rec);
	Sbecore::ubigint insertNewRec(WdbeQBnk1NPin** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQBnk1NPin& rst, WdbeQBnk1NPin** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQBnk1NPin& rst);
	virtual void updateRec(WdbeQBnk1NPin* rec);
	virtual void updateRst(ListWdbeQBnk1NPin& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnk1NPin** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnk1NPin& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQBnk1NPin: C++ wrapper for table TblWdbeQBnk1NPin (MySQL database)
	*/
class MyTblWdbeQBnk1NPin : public TblWdbeQBnk1NPin, public Sbecore::MyTable {

public:
	MyTblWdbeQBnk1NPin();
	~MyTblWdbeQBnk1NPin();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnk1NPin& rst);

	Sbecore::ubigint insertRec(WdbeQBnk1NPin* rec);
	void insertRst(ListWdbeQBnk1NPin& rst);
	void updateRec(WdbeQBnk1NPin* rec);
	void updateRst(ListWdbeQBnk1NPin& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnk1NPin& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQBnk1NPin: C++ wrapper for table TblWdbeQBnk1NPin (PgSQL database)
	*/
class PgTblWdbeQBnk1NPin : public TblWdbeQBnk1NPin, public Sbecore::PgTable {

public:
	PgTblWdbeQBnk1NPin();
	~PgTblWdbeQBnk1NPin();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQBnk1NPin& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQBnk1NPin& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQBnk1NPin& rst);

	Sbecore::ubigint insertRec(WdbeQBnk1NPin* rec);
	void insertRst(ListWdbeQBnk1NPin& rst);
	void updateRec(WdbeQBnk1NPin* rec);
	void updateRst(ListWdbeQBnk1NPin& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQBnk1NPin** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQBnk1NPin& rst);
};
#endif

#endif

