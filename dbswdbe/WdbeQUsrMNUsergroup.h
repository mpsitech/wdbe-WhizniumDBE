/**
	* \file WdbeQUsrMNUsergroup.h
	* Dbs and XML wrapper for table TblWdbeQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSRMNUSERGROUP_H
#define WDBEQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsrMNUsergroup: record of TblWdbeQUsrMNUsergroup
	*/
class WdbeQUsrMNUsergroup {

public:
	WdbeQUsrMNUsergroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

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
	* ListWdbeQUsrMNUsergroup: recordset of TblWdbeQUsrMNUsergroup
	*/
class ListWdbeQUsrMNUsergroup {

public:
	ListWdbeQUsrMNUsergroup();
	ListWdbeQUsrMNUsergroup(const ListWdbeQUsrMNUsergroup& src);
	~ListWdbeQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsrMNUsergroup* rec);

	ListWdbeQUsrMNUsergroup& operator=(const ListWdbeQUsrMNUsergroup& src);

public:
	std::vector<WdbeQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsrMNUsergroup: C++ wrapper for table TblWdbeQUsrMNUsergroup
	*/
class TblWdbeQUsrMNUsergroup {

public:
	TblWdbeQUsrMNUsergroup();
	virtual ~TblWdbeQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrMNUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsrMNUsergroup* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsrMNUsergroup& rst, WdbeQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");
	virtual void insertRst(ListWdbeQUsrMNUsergroup& rst);
	virtual void updateRec(WdbeQUsrMNUsergroup* rec);
	virtual void updateRst(ListWdbeQUsrMNUsergroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrMNUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsrMNUsergroup: C++ wrapper for table TblWdbeQUsrMNUsergroup (MySQL database)
	*/
class MyTblWdbeQUsrMNUsergroup : public TblWdbeQUsrMNUsergroup, public Sbecore::MyTable {

public:
	MyTblWdbeQUsrMNUsergroup();
	~MyTblWdbeQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeQUsrMNUsergroup* rec);
	void insertRst(ListWdbeQUsrMNUsergroup& rst);
	void updateRec(WdbeQUsrMNUsergroup* rec);
	void updateRst(ListWdbeQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsrMNUsergroup: C++ wrapper for table TblWdbeQUsrMNUsergroup (PgSQL database)
	*/
class PgTblWdbeQUsrMNUsergroup : public TblWdbeQUsrMNUsergroup, public Sbecore::PgTable {

public:
	PgTblWdbeQUsrMNUsergroup();
	~PgTblWdbeQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsrMNUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WdbeQUsrMNUsergroup* rec);
	void insertRst(ListWdbeQUsrMNUsergroup& rst);
	void updateRec(WdbeQUsrMNUsergroup* rec);
	void updateRst(ListWdbeQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrMNUsergroup& rst);
};
#endif

#endif
