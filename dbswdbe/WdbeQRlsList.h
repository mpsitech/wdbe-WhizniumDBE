/**
	* \file WdbeQRlsList.h
	* Dbs and XML wrapper for table TblWdbeQRlsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQRLSLIST_H
#define WDBEQRLSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQRlsList: record of TblWdbeQRlsList
	*/
class WdbeQRlsList {

public:
	WdbeQRlsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMMachine = 0, const std::string stubRefWdbeMMachine = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWdbeMVersion;
	std::string stubRefWdbeMVersion;
	Sbecore::ubigint refWdbeMMachine;
	std::string stubRefWdbeMMachine;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQRlsList: recordset of TblWdbeQRlsList
	*/
class ListWdbeQRlsList {

public:
	ListWdbeQRlsList();
	ListWdbeQRlsList(const ListWdbeQRlsList& src);
	~ListWdbeQRlsList();

	void clear();
	unsigned int size() const;
	void append(WdbeQRlsList* rec);

	ListWdbeQRlsList& operator=(const ListWdbeQRlsList& src);

public:
	std::vector<WdbeQRlsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQRlsList: C++ wrapper for table TblWdbeQRlsList
	*/
class TblWdbeQRlsList {

public:
	TblWdbeQRlsList();
	virtual ~TblWdbeQRlsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQRlsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQRlsList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQRlsList* rec);
	Sbecore::ubigint insertNewRec(WdbeQRlsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMMachine = 0, const std::string stubRefWdbeMMachine = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQRlsList& rst, WdbeQRlsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWdbeMVersion = 0, const std::string stubRefWdbeMVersion = "", const Sbecore::ubigint refWdbeMMachine = 0, const std::string stubRefWdbeMMachine = "");
	virtual void insertRst(ListWdbeQRlsList& rst);
	virtual void updateRec(WdbeQRlsList* rec);
	virtual void updateRst(ListWdbeQRlsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQRlsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQRlsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQRlsList: C++ wrapper for table TblWdbeQRlsList (MySQL database)
	*/
class MyTblWdbeQRlsList : public TblWdbeQRlsList, public Sbecore::MyTable {

public:
	MyTblWdbeQRlsList();
	~MyTblWdbeQRlsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQRlsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQRlsList& rst);

	Sbecore::ubigint insertRec(WdbeQRlsList* rec);
	void insertRst(ListWdbeQRlsList& rst);
	void updateRec(WdbeQRlsList* rec);
	void updateRst(ListWdbeQRlsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQRlsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQRlsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQRlsList: C++ wrapper for table TblWdbeQRlsList (PgSQL database)
	*/
class PgTblWdbeQRlsList : public TblWdbeQRlsList, public Sbecore::PgTable {

public:
	PgTblWdbeQRlsList();
	~PgTblWdbeQRlsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQRlsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQRlsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQRlsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQRlsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQRlsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQRlsList& rst);

	Sbecore::ubigint insertRec(WdbeQRlsList* rec);
	void insertRst(ListWdbeQRlsList& rst);
	void updateRec(WdbeQRlsList* rec);
	void updateRst(ListWdbeQRlsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQRlsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQRlsList& rst);
};
#endif

#endif

