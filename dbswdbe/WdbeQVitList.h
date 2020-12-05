/**
	* \file WdbeQVitList.h
	* Dbs and XML wrapper for table TblWdbeQVitList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVITLIST_H
#define WDBEQVITLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVitList: record of TblWdbeQVitList
	*/
class WdbeQVitList {

public:
	WdbeQVitList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWdbeMVector = 0, const std::string stubVecRefWdbeMVector = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint vecRefWdbeMVector;
	std::string stubVecRefWdbeMVector;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVitList: recordset of TblWdbeQVitList
	*/
class ListWdbeQVitList {

public:
	ListWdbeQVitList();
	ListWdbeQVitList(const ListWdbeQVitList& src);
	~ListWdbeQVitList();

	void clear();
	unsigned int size() const;
	void append(WdbeQVitList* rec);

	ListWdbeQVitList& operator=(const ListWdbeQVitList& src);

public:
	std::vector<WdbeQVitList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVitList: C++ wrapper for table TblWdbeQVitList
	*/
class TblWdbeQVitList {

public:
	TblWdbeQVitList();
	virtual ~TblWdbeQVitList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVitList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVitList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVitList* rec);
	Sbecore::ubigint insertNewRec(WdbeQVitList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWdbeMVector = 0, const std::string stubVecRefWdbeMVector = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVitList& rst, WdbeQVitList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWdbeMVector = 0, const std::string stubVecRefWdbeMVector = "");
	virtual void insertRst(ListWdbeQVitList& rst);
	virtual void updateRec(WdbeQVitList* rec);
	virtual void updateRst(ListWdbeQVitList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVitList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVitList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVitList: C++ wrapper for table TblWdbeQVitList (MySQL database)
	*/
class MyTblWdbeQVitList : public TblWdbeQVitList, public Sbecore::MyTable {

public:
	MyTblWdbeQVitList();
	~MyTblWdbeQVitList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVitList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVitList& rst);

	Sbecore::ubigint insertRec(WdbeQVitList* rec);
	void insertRst(ListWdbeQVitList& rst);
	void updateRec(WdbeQVitList* rec);
	void updateRst(ListWdbeQVitList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVitList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVitList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVitList: C++ wrapper for table TblWdbeQVitList (PgSQL database)
	*/
class PgTblWdbeQVitList : public TblWdbeQVitList, public Sbecore::PgTable {

public:
	PgTblWdbeQVitList();
	~PgTblWdbeQVitList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVitList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVitList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVitList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVitList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVitList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVitList& rst);

	Sbecore::ubigint insertRec(WdbeQVitList* rec);
	void insertRst(ListWdbeQVitList& rst);
	void updateRec(WdbeQVitList* rec);
	void updateRst(ListWdbeQVitList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVitList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVitList& rst);
};
#endif

#endif

