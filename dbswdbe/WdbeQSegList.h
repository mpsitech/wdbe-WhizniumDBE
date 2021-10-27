/**
	* \file WdbeQSegList.h
	* Dbs and XML wrapper for table TblWdbeQSegList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSEGLIST_H
#define WDBEQSEGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSegList: record of TblWdbeQSegList
	*/
class WdbeQSegList {

public:
	WdbeQSegList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint pplRefWdbeMPipeline = 0, const std::string stubPplRefWdbeMPipeline = "", const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string stubSupRefWdbeMSegment = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint pplRefWdbeMPipeline;
	std::string stubPplRefWdbeMPipeline;
	Sbecore::ubigint supRefWdbeMSegment;
	std::string stubSupRefWdbeMSegment;
	std::string Infmt;
	std::string Outfmt;
	Sbecore::usmallint Latency;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSegList: recordset of TblWdbeQSegList
	*/
class ListWdbeQSegList {

public:
	ListWdbeQSegList();
	ListWdbeQSegList(const ListWdbeQSegList& src);
	~ListWdbeQSegList();

	void clear();
	unsigned int size() const;
	void append(WdbeQSegList* rec);

	ListWdbeQSegList& operator=(const ListWdbeQSegList& src);

public:
	std::vector<WdbeQSegList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSegList: C++ wrapper for table TblWdbeQSegList
	*/
class TblWdbeQSegList {

public:
	TblWdbeQSegList();
	virtual ~TblWdbeQSegList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSegList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSegList* rec);
	Sbecore::ubigint insertNewRec(WdbeQSegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint pplRefWdbeMPipeline = 0, const std::string stubPplRefWdbeMPipeline = "", const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string stubSupRefWdbeMSegment = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSegList& rst, WdbeQSegList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint pplRefWdbeMPipeline = 0, const std::string stubPplRefWdbeMPipeline = "", const Sbecore::ubigint supRefWdbeMSegment = 0, const std::string stubSupRefWdbeMSegment = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0);
	virtual void insertRst(ListWdbeQSegList& rst);
	virtual void updateRec(WdbeQSegList* rec);
	virtual void updateRst(ListWdbeQSegList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSegList: C++ wrapper for table TblWdbeQSegList (MySQL database)
	*/
class MyTblWdbeQSegList : public TblWdbeQSegList, public Sbecore::MyTable {

public:
	MyTblWdbeQSegList();
	~MyTblWdbeQSegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegList& rst);

	Sbecore::ubigint insertRec(WdbeQSegList* rec);
	void insertRst(ListWdbeQSegList& rst);
	void updateRec(WdbeQSegList* rec);
	void updateRst(ListWdbeQSegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSegList: C++ wrapper for table TblWdbeQSegList (PgSQL database)
	*/
class PgTblWdbeQSegList : public TblWdbeQSegList, public Sbecore::PgTable {

public:
	PgTblWdbeQSegList();
	~PgTblWdbeQSegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSegList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSegList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSegList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSegList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSegList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegList& rst);

	Sbecore::ubigint insertRec(WdbeQSegList* rec);
	void insertRst(ListWdbeQSegList& rst);
	void updateRec(WdbeQSegList* rec);
	void updateRst(ListWdbeQSegList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegList& rst);
};
#endif

#endif
