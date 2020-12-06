/**
	* \file WdbeQVecList.h
	* Dbs and XML wrapper for table TblWdbeQVecList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVECLIST_H
#define WDBEQVECLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVecList: record of TblWdbeQVecList
	*/
class WdbeQVecList {

public:
	WdbeQVecList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::uint hkIxVTbl;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	Sbecore::ubigint hkUref;
	std::string stubHkUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQVecList: recordset of TblWdbeQVecList
	*/
class ListWdbeQVecList {

public:
	ListWdbeQVecList();
	ListWdbeQVecList(const ListWdbeQVecList& src);
	~ListWdbeQVecList();

	void clear();
	unsigned int size() const;
	void append(WdbeQVecList* rec);

	ListWdbeQVecList& operator=(const ListWdbeQVecList& src);

public:
	std::vector<WdbeQVecList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVecList: C++ wrapper for table TblWdbeQVecList
	*/
class TblWdbeQVecList {

public:
	TblWdbeQVecList();
	virtual ~TblWdbeQVecList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVecList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVecList* rec);
	Sbecore::ubigint insertNewRec(WdbeQVecList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVecList& rst, WdbeQVecList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "");
	virtual void insertRst(ListWdbeQVecList& rst);
	virtual void updateRec(WdbeQVecList* rec);
	virtual void updateRst(ListWdbeQVecList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVecList: C++ wrapper for table TblWdbeQVecList (MySQL database)
	*/
class MyTblWdbeQVecList : public TblWdbeQVecList, public Sbecore::MyTable {

public:
	MyTblWdbeQVecList();
	~MyTblWdbeQVecList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVecList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecList& rst);

	Sbecore::ubigint insertRec(WdbeQVecList* rec);
	void insertRst(ListWdbeQVecList& rst);
	void updateRec(WdbeQVecList* rec);
	void updateRst(ListWdbeQVecList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVecList: C++ wrapper for table TblWdbeQVecList (PgSQL database)
	*/
class PgTblWdbeQVecList : public TblWdbeQVecList, public Sbecore::PgTable {

public:
	PgTblWdbeQVecList();
	~PgTblWdbeQVecList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVecList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVecList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVecList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVecList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVecList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVecList& rst);

	Sbecore::ubigint insertRec(WdbeQVecList* rec);
	void insertRst(ListWdbeQVecList& rst);
	void updateRec(WdbeQVecList* rec);
	void updateRst(ListWdbeQVecList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVecList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVecList& rst);
};
#endif

#endif
