/**
	* \file WdbeQModRef1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQModRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NSENSITIVITY_H
#define WDBEQMODREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModRef1NSensitivity: record of TblWdbeQModRef1NSensitivity
	*/
class WdbeQModRef1NSensitivity {

public:
	WdbeQModRef1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQModRef1NSensitivity: recordset of TblWdbeQModRef1NSensitivity
	*/
class ListWdbeQModRef1NSensitivity {

public:
	ListWdbeQModRef1NSensitivity();
	ListWdbeQModRef1NSensitivity(const ListWdbeQModRef1NSensitivity& src);
	~ListWdbeQModRef1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQModRef1NSensitivity* rec);

	ListWdbeQModRef1NSensitivity& operator=(const ListWdbeQModRef1NSensitivity& src);

public:
	std::vector<WdbeQModRef1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModRef1NSensitivity: C++ wrapper for table TblWdbeQModRef1NSensitivity
	*/
class TblWdbeQModRef1NSensitivity {

public:
	TblWdbeQModRef1NSensitivity();
	virtual ~TblWdbeQModRef1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModRef1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQModRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModRef1NSensitivity& rst, WdbeQModRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQModRef1NSensitivity& rst);
	virtual void updateRec(WdbeQModRef1NSensitivity* rec);
	virtual void updateRst(ListWdbeQModRef1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModRef1NSensitivity: C++ wrapper for table TblWdbeQModRef1NSensitivity (MySQL database)
	*/
class MyTblWdbeQModRef1NSensitivity : public TblWdbeQModRef1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQModRef1NSensitivity();
	~MyTblWdbeQModRef1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NSensitivity* rec);
	void insertRst(ListWdbeQModRef1NSensitivity& rst);
	void updateRec(WdbeQModRef1NSensitivity* rec);
	void updateRst(ListWdbeQModRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModRef1NSensitivity: C++ wrapper for table TblWdbeQModRef1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQModRef1NSensitivity : public TblWdbeQModRef1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQModRef1NSensitivity();
	~PgTblWdbeQModRef1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModRef1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModRef1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQModRef1NSensitivity* rec);
	void insertRst(ListWdbeQModRef1NSensitivity& rst);
	void updateRec(WdbeQModRef1NSensitivity* rec);
	void updateRst(ListWdbeQModRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModRef1NSensitivity& rst);
};
#endif

#endif
