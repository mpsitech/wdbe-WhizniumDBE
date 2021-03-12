/**
	* \file WdbeQModList.h
	* Dbs and XML wrapper for table TblWdbeQModList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODLIST_H
#define WDBEQMODLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModList: record of TblWdbeQModList
	*/
class WdbeQModList {

public:
	WdbeQModList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::ubigint supRefWdbeMModule = 0, const std::string stubSupRefWdbeMModule = "", const Sbecore::ubigint tplRefWdbeMModule = 0, const std::string stubTplRefWdbeMModule = "", const std::string Srefrule = "");

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
	Sbecore::ubigint supRefWdbeMModule;
	std::string stubSupRefWdbeMModule;
	Sbecore::ubigint tplRefWdbeMModule;
	std::string stubTplRefWdbeMModule;
	std::string Srefrule;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModList: recordset of TblWdbeQModList
	*/
class ListWdbeQModList {

public:
	ListWdbeQModList();
	ListWdbeQModList(const ListWdbeQModList& src);
	~ListWdbeQModList();

	void clear();
	unsigned int size() const;
	void append(WdbeQModList* rec);

	ListWdbeQModList& operator=(const ListWdbeQModList& src);

public:
	std::vector<WdbeQModList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModList: C++ wrapper for table TblWdbeQModList
	*/
class TblWdbeQModList {

public:
	TblWdbeQModList();
	virtual ~TblWdbeQModList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModList* rec);
	Sbecore::ubigint insertNewRec(WdbeQModList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::ubigint supRefWdbeMModule = 0, const std::string stubSupRefWdbeMModule = "", const Sbecore::ubigint tplRefWdbeMModule = 0, const std::string stubTplRefWdbeMModule = "", const std::string Srefrule = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModList& rst, WdbeQModList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::ubigint supRefWdbeMModule = 0, const std::string stubSupRefWdbeMModule = "", const Sbecore::ubigint tplRefWdbeMModule = 0, const std::string stubTplRefWdbeMModule = "", const std::string Srefrule = "");
	virtual void insertRst(ListWdbeQModList& rst);
	virtual void updateRec(WdbeQModList* rec);
	virtual void updateRst(ListWdbeQModList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModList: C++ wrapper for table TblWdbeQModList (MySQL database)
	*/
class MyTblWdbeQModList : public TblWdbeQModList, public Sbecore::MyTable {

public:
	MyTblWdbeQModList();
	~MyTblWdbeQModList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModList& rst);

	Sbecore::ubigint insertRec(WdbeQModList* rec);
	void insertRst(ListWdbeQModList& rst);
	void updateRec(WdbeQModList* rec);
	void updateRst(ListWdbeQModList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModList: C++ wrapper for table TblWdbeQModList (PgSQL database)
	*/
class PgTblWdbeQModList : public TblWdbeQModList, public Sbecore::PgTable {

public:
	PgTblWdbeQModList();
	~PgTblWdbeQModList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModList& rst);

	Sbecore::ubigint insertRec(WdbeQModList* rec);
	void insertRst(ListWdbeQModList& rst);
	void updateRec(WdbeQModList* rec);
	void updateRst(ListWdbeQModList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModList& rst);
};
#endif

#endif
