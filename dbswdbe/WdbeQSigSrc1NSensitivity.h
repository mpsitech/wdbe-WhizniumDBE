/**
	* \file WdbeQSigSrc1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQSigSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSIGSRC1NSENSITIVITY_H
#define WDBEQSIGSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSigSrc1NSensitivity: record of TblWdbeQSigSrc1NSensitivity
	*/
class WdbeQSigSrc1NSensitivity {

public:
	WdbeQSigSrc1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSigSrc1NSensitivity: recordset of TblWdbeQSigSrc1NSensitivity
	*/
class ListWdbeQSigSrc1NSensitivity {

public:
	ListWdbeQSigSrc1NSensitivity();
	ListWdbeQSigSrc1NSensitivity(const ListWdbeQSigSrc1NSensitivity& src);
	~ListWdbeQSigSrc1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQSigSrc1NSensitivity* rec);

	ListWdbeQSigSrc1NSensitivity& operator=(const ListWdbeQSigSrc1NSensitivity& src);

public:
	std::vector<WdbeQSigSrc1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSigSrc1NSensitivity: C++ wrapper for table TblWdbeQSigSrc1NSensitivity
	*/
class TblWdbeQSigSrc1NSensitivity {

public:
	TblWdbeQSigSrc1NSensitivity();
	virtual ~TblWdbeQSigSrc1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSigSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigSrc1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSigSrc1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQSigSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSigSrc1NSensitivity& rst, WdbeQSigSrc1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSigSrc1NSensitivity& rst);
	virtual void updateRec(WdbeQSigSrc1NSensitivity* rec);
	virtual void updateRst(ListWdbeQSigSrc1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigSrc1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigSrc1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSigSrc1NSensitivity: C++ wrapper for table TblWdbeQSigSrc1NSensitivity (MySQL database)
	*/
class MyTblWdbeQSigSrc1NSensitivity : public TblWdbeQSigSrc1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQSigSrc1NSensitivity();
	~MyTblWdbeQSigSrc1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQSigSrc1NSensitivity* rec);
	void insertRst(ListWdbeQSigSrc1NSensitivity& rst);
	void updateRec(WdbeQSigSrc1NSensitivity* rec);
	void updateRst(ListWdbeQSigSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigSrc1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSigSrc1NSensitivity: C++ wrapper for table TblWdbeQSigSrc1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQSigSrc1NSensitivity : public TblWdbeQSigSrc1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQSigSrc1NSensitivity();
	~PgTblWdbeQSigSrc1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSigSrc1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSigSrc1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigSrc1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQSigSrc1NSensitivity* rec);
	void insertRst(ListWdbeQSigSrc1NSensitivity& rst);
	void updateRec(WdbeQSigSrc1NSensitivity* rec);
	void updateRst(ListWdbeQSigSrc1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigSrc1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigSrc1NSensitivity& rst);
};
#endif

#endif
