/**
	* \file WdbeQMtpList.h
	* Dbs and XML wrapper for table TblWdbeQMtpList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPLIST_H
#define WDBEQMTPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpList: record of TblWdbeQMtpList
	*/
class WdbeQMtpList {

public:
	WdbeQMtpList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string Srefrule = "");

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
	std::string Srefrule;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQMtpList: recordset of TblWdbeQMtpList
	*/
class ListWdbeQMtpList {

public:
	ListWdbeQMtpList();
	ListWdbeQMtpList(const ListWdbeQMtpList& src);
	~ListWdbeQMtpList();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpList* rec);

	ListWdbeQMtpList& operator=(const ListWdbeQMtpList& src);

public:
	std::vector<WdbeQMtpList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpList: C++ wrapper for table TblWdbeQMtpList
	*/
class TblWdbeQMtpList {

public:
	TblWdbeQMtpList();
	virtual ~TblWdbeQMtpList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpList* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string Srefrule = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpList& rst, WdbeQMtpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string Srefrule = "");
	virtual void insertRst(ListWdbeQMtpList& rst);
	virtual void updateRec(WdbeQMtpList* rec);
	virtual void updateRst(ListWdbeQMtpList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpList: C++ wrapper for table TblWdbeQMtpList (MySQL database)
	*/
class MyTblWdbeQMtpList : public TblWdbeQMtpList, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpList();
	~MyTblWdbeQMtpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpList& rst);

	Sbecore::ubigint insertRec(WdbeQMtpList* rec);
	void insertRst(ListWdbeQMtpList& rst);
	void updateRec(WdbeQMtpList* rec);
	void updateRst(ListWdbeQMtpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpList: C++ wrapper for table TblWdbeQMtpList (PgSQL database)
	*/
class PgTblWdbeQMtpList : public TblWdbeQMtpList, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpList();
	~PgTblWdbeQMtpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpList& rst);

	Sbecore::ubigint insertRec(WdbeQMtpList* rec);
	void insertRst(ListWdbeQMtpList& rst);
	void updateRec(WdbeQMtpList* rec);
	void updateRst(ListWdbeQMtpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpList& rst);
};
#endif

#endif
