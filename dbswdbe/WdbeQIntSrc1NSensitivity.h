/**
	* \file WdbeQIntSrc1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQIntSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQINTSRC1NSENSITIVITY_H
#define WDBEQINTSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQIntSrc1NSensitivity: record of TblWdbeQIntSrc1NSensitivity
	*/
class WdbeQIntSrc1NSensitivity {

public:
	WdbeQIntSrc1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQIntSrc1NSensitivity: recordset of TblWdbeQIntSrc1NSensitivity
	*/
class ListWdbeQIntSrc1NSensitivity {

public:
	ListWdbeQIntSrc1NSensitivity();
	ListWdbeQIntSrc1NSensitivity(const ListWdbeQIntSrc1NSensitivity& src);
	~ListWdbeQIntSrc1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQIntSrc1NSensitivity* rec);

	ListWdbeQIntSrc1NSensitivity& operator=(const ListWdbeQIntSrc1NSensitivity& src);

public:
	std::vector<WdbeQIntSrc1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQIntSrc1NSensitivity: C++ wrapper for table TblWdbeQIntSrc1NSensitivity
	*/
class TblWdbeQIntSrc1NSensitivity {

public:
	TblWdbeQIntSrc1NSensitivity();
	virtual ~TblWdbeQIntSrc1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQIntSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntSrc1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQIntSrc1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQIntSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQIntSrc1NSensitivity& rst, WdbeQIntSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQIntSrc1NSensitivity& rst);
	virtual void updateRec(WdbeQIntSrc1NSensitivity* rec);
	virtual void updateRst(ListWdbeQIntSrc1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntSrc1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQIntSrc1NSensitivity: C++ wrapper for table TblWdbeQIntSrc1NSensitivity (MySQL database)
	*/
class MyTblWdbeQIntSrc1NSensitivity : public TblWdbeQIntSrc1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQIntSrc1NSensitivity();
	~MyTblWdbeQIntSrc1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQIntSrc1NSensitivity* rec);
	void insertRst(ListWdbeQIntSrc1NSensitivity& rst);
	void updateRec(WdbeQIntSrc1NSensitivity* rec);
	void updateRst(ListWdbeQIntSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntSrc1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQIntSrc1NSensitivity: C++ wrapper for table TblWdbeQIntSrc1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQIntSrc1NSensitivity : public TblWdbeQIntSrc1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQIntSrc1NSensitivity();
	~PgTblWdbeQIntSrc1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQIntSrc1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQIntSrc1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQIntSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQIntSrc1NSensitivity* rec);
	void insertRst(ListWdbeQIntSrc1NSensitivity& rst);
	void updateRec(WdbeQIntSrc1NSensitivity* rec);
	void updateRst(ListWdbeQIntSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQIntSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQIntSrc1NSensitivity& rst);
};
#endif

#endif
