/**
	* \file WdbeQCvrAIp.h
	* Dbs and XML wrapper for table TblWdbeQCvrAIp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRAIP_H
#define WDBEQCVRAIP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCvrAIp: record of TblWdbeQCvrAIp
	*/
class WdbeQCvrAIp {

public:
	WdbeQCvrAIp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string srefIxVTagtype = "", const std::string titIxVTagtype = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint cvrNum;
	std::string sref;
	Sbecore::uint ixVTagtype;
	std::string srefIxVTagtype;
	std::string titIxVTagtype;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCvrAIp: recordset of TblWdbeQCvrAIp
	*/
class ListWdbeQCvrAIp {

public:
	ListWdbeQCvrAIp();
	ListWdbeQCvrAIp(const ListWdbeQCvrAIp& src);
	~ListWdbeQCvrAIp();

	void clear();
	unsigned int size() const;
	void append(WdbeQCvrAIp* rec);

	ListWdbeQCvrAIp& operator=(const ListWdbeQCvrAIp& src);

public:
	std::vector<WdbeQCvrAIp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCvrAIp: C++ wrapper for table TblWdbeQCvrAIp
	*/
class TblWdbeQCvrAIp {

public:
	TblWdbeQCvrAIp();
	virtual ~TblWdbeQCvrAIp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAIp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAIp& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCvrAIp* rec);
	Sbecore::ubigint insertNewRec(WdbeQCvrAIp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string srefIxVTagtype = "", const std::string titIxVTagtype = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCvrAIp& rst, WdbeQCvrAIp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const Sbecore::uint ixVTagtype = 0, const std::string srefIxVTagtype = "", const std::string titIxVTagtype = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQCvrAIp& rst);
	virtual void updateRec(WdbeQCvrAIp* rec);
	virtual void updateRst(ListWdbeQCvrAIp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAIp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAIp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCvrAIp: C++ wrapper for table TblWdbeQCvrAIp (MySQL database)
	*/
class MyTblWdbeQCvrAIp : public TblWdbeQCvrAIp, public Sbecore::MyTable {

public:
	MyTblWdbeQCvrAIp();
	~MyTblWdbeQCvrAIp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAIp& rst);

	Sbecore::ubigint insertRec(WdbeQCvrAIp* rec);
	void insertRst(ListWdbeQCvrAIp& rst);
	void updateRec(WdbeQCvrAIp* rec);
	void updateRst(ListWdbeQCvrAIp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAIp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCvrAIp: C++ wrapper for table TblWdbeQCvrAIp (PgSQL database)
	*/
class PgTblWdbeQCvrAIp : public TblWdbeQCvrAIp, public Sbecore::PgTable {

public:
	PgTblWdbeQCvrAIp();
	~PgTblWdbeQCvrAIp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCvrAIp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCvrAIp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAIp& rst);

	Sbecore::ubigint insertRec(WdbeQCvrAIp* rec);
	void insertRst(ListWdbeQCvrAIp& rst);
	void updateRec(WdbeQCvrAIp* rec);
	void updateRst(ListWdbeQCvrAIp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAIp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAIp& rst);
};
#endif

#endif
