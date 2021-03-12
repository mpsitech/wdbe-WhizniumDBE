/**
	* \file WdbeQSelect.h
	* Dbs and XML wrapper for table TblWdbeQSelect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSELECT_H
#define WDBEQSELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSelect: record of TblWdbeQSelect
	*/
class WdbeQSelect {

public:
	WdbeQSelect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::uint ix;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSelect: recordset of TblWdbeQSelect
	*/
class ListWdbeQSelect {

public:
	ListWdbeQSelect();
	ListWdbeQSelect(const ListWdbeQSelect& src);
	~ListWdbeQSelect();

	void clear();
	unsigned int size() const;
	void append(WdbeQSelect* rec);

	ListWdbeQSelect& operator=(const ListWdbeQSelect& src);

public:
	std::vector<WdbeQSelect*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSelect: C++ wrapper for table TblWdbeQSelect
	*/
class TblWdbeQSelect {

public:
	TblWdbeQSelect();
	virtual ~TblWdbeQSelect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSelect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSelect& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSelect* rec);
	Sbecore::ubigint insertNewRec(WdbeQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSelect& rst, WdbeQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQSelect& rst);
	virtual void updateRec(WdbeQSelect* rec);
	virtual void updateRst(ListWdbeQSelect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSelect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSelect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSelect: C++ wrapper for table TblWdbeQSelect (MySQL database)
	*/
class MyTblWdbeQSelect : public TblWdbeQSelect, public Sbecore::MyTable {

public:
	MyTblWdbeQSelect();
	~MyTblWdbeQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSelect& rst);

	Sbecore::ubigint insertRec(WdbeQSelect* rec);
	void insertRst(ListWdbeQSelect& rst);
	void updateRec(WdbeQSelect* rec);
	void updateRst(ListWdbeQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSelect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSelect: C++ wrapper for table TblWdbeQSelect (PgSQL database)
	*/
class PgTblWdbeQSelect : public TblWdbeQSelect, public Sbecore::PgTable {

public:
	PgTblWdbeQSelect();
	~PgTblWdbeQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSelect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSelect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSelect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSelect& rst);

	Sbecore::ubigint insertRec(WdbeQSelect* rec);
	void insertRst(ListWdbeQSelect& rst);
	void updateRec(WdbeQSelect* rec);
	void updateRst(ListWdbeQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSelect& rst);
};
#endif

#endif
