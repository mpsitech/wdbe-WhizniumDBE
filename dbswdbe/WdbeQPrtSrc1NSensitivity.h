/**
	* \file WdbeQPrtSrc1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQPrtSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRTSRC1NSENSITIVITY_H
#define WDBEQPRTSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrtSrc1NSensitivity: record of TblWdbeQPrtSrc1NSensitivity
	*/
class WdbeQPrtSrc1NSensitivity {

public:
	WdbeQPrtSrc1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQPrtSrc1NSensitivity: recordset of TblWdbeQPrtSrc1NSensitivity
	*/
class ListWdbeQPrtSrc1NSensitivity {

public:
	ListWdbeQPrtSrc1NSensitivity();
	ListWdbeQPrtSrc1NSensitivity(const ListWdbeQPrtSrc1NSensitivity& src);
	~ListWdbeQPrtSrc1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrtSrc1NSensitivity* rec);

	ListWdbeQPrtSrc1NSensitivity& operator=(const ListWdbeQPrtSrc1NSensitivity& src);

public:
	std::vector<WdbeQPrtSrc1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrtSrc1NSensitivity: C++ wrapper for table TblWdbeQPrtSrc1NSensitivity
	*/
class TblWdbeQPrtSrc1NSensitivity {

public:
	TblWdbeQPrtSrc1NSensitivity();
	virtual ~TblWdbeQPrtSrc1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrtSrc1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrtSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrtSrc1NSensitivity& rst, WdbeQPrtSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQPrtSrc1NSensitivity& rst);
	virtual void updateRec(WdbeQPrtSrc1NSensitivity* rec);
	virtual void updateRst(ListWdbeQPrtSrc1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrtSrc1NSensitivity: C++ wrapper for table TblWdbeQPrtSrc1NSensitivity (MySQL database)
	*/
class MyTblWdbeQPrtSrc1NSensitivity : public TblWdbeQPrtSrc1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQPrtSrc1NSensitivity();
	~MyTblWdbeQPrtSrc1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQPrtSrc1NSensitivity* rec);
	void insertRst(ListWdbeQPrtSrc1NSensitivity& rst);
	void updateRec(WdbeQPrtSrc1NSensitivity* rec);
	void updateRst(ListWdbeQPrtSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrtSrc1NSensitivity: C++ wrapper for table TblWdbeQPrtSrc1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQPrtSrc1NSensitivity : public TblWdbeQPrtSrc1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQPrtSrc1NSensitivity();
	~PgTblWdbeQPrtSrc1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQPrtSrc1NSensitivity* rec);
	void insertRst(ListWdbeQPrtSrc1NSensitivity& rst);
	void updateRec(WdbeQPrtSrc1NSensitivity* rec);
	void updateRst(ListWdbeQPrtSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrtSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrtSrc1NSensitivity& rst);
};
#endif

#endif
