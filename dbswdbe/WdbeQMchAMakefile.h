/**
	* \file WdbeQMchAMakefile.h
	* Dbs and XML wrapper for table TblWdbeQMchAMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCHAMAKEFILE_H
#define WDBEQMCHAMAKEFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMchAMakefile: record of TblWdbeQMchAMakefile
	*/
class WdbeQMchAMakefile {

public:
	WdbeQMchAMakefile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQMchAMakefile: recordset of TblWdbeQMchAMakefile
	*/
class ListWdbeQMchAMakefile {

public:
	ListWdbeQMchAMakefile();
	ListWdbeQMchAMakefile(const ListWdbeQMchAMakefile& src);
	~ListWdbeQMchAMakefile();

	void clear();
	unsigned int size() const;
	void append(WdbeQMchAMakefile* rec);

	ListWdbeQMchAMakefile& operator=(const ListWdbeQMchAMakefile& src);

public:
	std::vector<WdbeQMchAMakefile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMchAMakefile: C++ wrapper for table TblWdbeQMchAMakefile
	*/
class TblWdbeQMchAMakefile {

public:
	TblWdbeQMchAMakefile();
	virtual ~TblWdbeQMchAMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAMakefile& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMchAMakefile* rec);
	Sbecore::ubigint insertNewRec(WdbeQMchAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMchAMakefile& rst, WdbeQMchAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQMchAMakefile& rst);
	virtual void updateRec(WdbeQMchAMakefile* rec);
	virtual void updateRst(ListWdbeQMchAMakefile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAMakefile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMchAMakefile: C++ wrapper for table TblWdbeQMchAMakefile (MySQL database)
	*/
class MyTblWdbeQMchAMakefile : public TblWdbeQMchAMakefile, public Sbecore::MyTable {

public:
	MyTblWdbeQMchAMakefile();
	~MyTblWdbeQMchAMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAMakefile& rst);

	Sbecore::ubigint insertRec(WdbeQMchAMakefile* rec);
	void insertRst(ListWdbeQMchAMakefile& rst);
	void updateRec(WdbeQMchAMakefile* rec);
	void updateRst(ListWdbeQMchAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAMakefile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMchAMakefile: C++ wrapper for table TblWdbeQMchAMakefile (PgSQL database)
	*/
class PgTblWdbeQMchAMakefile : public TblWdbeQMchAMakefile, public Sbecore::PgTable {

public:
	PgTblWdbeQMchAMakefile();
	~PgTblWdbeQMchAMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMchAMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMchAMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMchAMakefile& rst);

	Sbecore::ubigint insertRec(WdbeQMchAMakefile* rec);
	void insertRst(ListWdbeQMchAMakefile& rst);
	void updateRec(WdbeQMchAMakefile* rec);
	void updateRst(ListWdbeQMchAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMchAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMchAMakefile& rst);
};
#endif

#endif
