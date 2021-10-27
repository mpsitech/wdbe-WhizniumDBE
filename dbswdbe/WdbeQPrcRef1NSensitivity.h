/**
	* \file WdbeQPrcRef1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQPrcRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRCREF1NSENSITIVITY_H
#define WDBEQPRCREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrcRef1NSensitivity: record of TblWdbeQPrcRef1NSensitivity
	*/
class WdbeQPrcRef1NSensitivity {

public:
	WdbeQPrcRef1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQPrcRef1NSensitivity: recordset of TblWdbeQPrcRef1NSensitivity
	*/
class ListWdbeQPrcRef1NSensitivity {

public:
	ListWdbeQPrcRef1NSensitivity();
	ListWdbeQPrcRef1NSensitivity(const ListWdbeQPrcRef1NSensitivity& src);
	~ListWdbeQPrcRef1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrcRef1NSensitivity* rec);

	ListWdbeQPrcRef1NSensitivity& operator=(const ListWdbeQPrcRef1NSensitivity& src);

public:
	std::vector<WdbeQPrcRef1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrcRef1NSensitivity: C++ wrapper for table TblWdbeQPrcRef1NSensitivity
	*/
class TblWdbeQPrcRef1NSensitivity {

public:
	TblWdbeQPrcRef1NSensitivity();
	virtual ~TblWdbeQPrcRef1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrcRef1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrcRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrcRef1NSensitivity& rst, WdbeQPrcRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQPrcRef1NSensitivity& rst);
	virtual void updateRec(WdbeQPrcRef1NSensitivity* rec);
	virtual void updateRst(ListWdbeQPrcRef1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrcRef1NSensitivity: C++ wrapper for table TblWdbeQPrcRef1NSensitivity (MySQL database)
	*/
class MyTblWdbeQPrcRef1NSensitivity : public TblWdbeQPrcRef1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQPrcRef1NSensitivity();
	~MyTblWdbeQPrcRef1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQPrcRef1NSensitivity* rec);
	void insertRst(ListWdbeQPrcRef1NSensitivity& rst);
	void updateRec(WdbeQPrcRef1NSensitivity* rec);
	void updateRst(ListWdbeQPrcRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrcRef1NSensitivity: C++ wrapper for table TblWdbeQPrcRef1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQPrcRef1NSensitivity : public TblWdbeQPrcRef1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQPrcRef1NSensitivity();
	~PgTblWdbeQPrcRef1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrcRef1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrcRef1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrcRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQPrcRef1NSensitivity* rec);
	void insertRst(ListWdbeQPrcRef1NSensitivity& rst);
	void updateRec(WdbeQPrcRef1NSensitivity* rec);
	void updateRst(ListWdbeQPrcRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrcRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrcRef1NSensitivity& rst);
};
#endif

#endif
