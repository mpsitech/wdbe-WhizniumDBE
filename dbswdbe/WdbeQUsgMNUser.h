/**
	* \file WdbeQUsgMNUser.h
	* Dbs and XML wrapper for table TblWdbeQUsgMNUser (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUSGMNUSER_H
#define WDBEQUSGMNUSER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsgMNUser: record of TblWdbeQUsgMNUser
	*/
class WdbeQUsgMNUser {

public:
	WdbeQUsgMNUser(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixWdbeVUserlevel;
	std::string srefIxWdbeVUserlevel;
	std::string titIxWdbeVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUsgMNUser: recordset of TblWdbeQUsgMNUser
	*/
class ListWdbeQUsgMNUser {

public:
	ListWdbeQUsgMNUser();
	ListWdbeQUsgMNUser(const ListWdbeQUsgMNUser& src);
	~ListWdbeQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsgMNUser* rec);

	ListWdbeQUsgMNUser& operator=(const ListWdbeQUsgMNUser& src);

public:
	std::vector<WdbeQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsgMNUser: C++ wrapper for table TblWdbeQUsgMNUser
	*/
class TblWdbeQUsgMNUser {

public:
	TblWdbeQUsgMNUser();
	virtual ~TblWdbeQUsgMNUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgMNUser& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsgMNUser* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsgMNUser& rst, WdbeQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	virtual void insertRst(ListWdbeQUsgMNUser& rst);
	virtual void updateRec(WdbeQUsgMNUser* rec);
	virtual void updateRst(ListWdbeQUsgMNUser& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgMNUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsgMNUser: C++ wrapper for table TblWdbeQUsgMNUser (MySQL database)
	*/
class MyTblWdbeQUsgMNUser : public TblWdbeQUsgMNUser, public Sbecore::MyTable {

public:
	MyTblWdbeQUsgMNUser();
	~MyTblWdbeQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WdbeQUsgMNUser* rec);
	void insertRst(ListWdbeQUsgMNUser& rst);
	void updateRec(WdbeQUsgMNUser* rec);
	void updateRst(ListWdbeQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsgMNUser: C++ wrapper for table TblWdbeQUsgMNUser (PgSQL database)
	*/
class PgTblWdbeQUsgMNUser : public TblWdbeQUsgMNUser, public Sbecore::PgTable {

public:
	PgTblWdbeQUsgMNUser();
	~PgTblWdbeQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsgMNUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WdbeQUsgMNUser* rec);
	void insertRst(ListWdbeQUsgMNUser& rst);
	void updateRec(WdbeQUsgMNUser* rec);
	void updateRst(ListWdbeQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgMNUser& rst);
};
#endif

#endif

