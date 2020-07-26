/**
	* \file WdbeQLibAMakefile.h
	* Dbs and XML wrapper for table TblWdbeQLibAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQLIBAMAKEFILE_H
#define WDBEQLIBAMAKEFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQLibAMakefile: record of TblWdbeQLibAMakefile
	*/
class WdbeQLibAMakefile {

public:
	WdbeQLibAMakefile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string stubX1RefWdbeMMachine = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint x1RefWdbeMMachine;
	std::string stubX1RefWdbeMMachine;
	std::string x2SrefKTag;
	std::string titX2SrefKTag;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQLibAMakefile: recordset of TblWdbeQLibAMakefile
	*/
class ListWdbeQLibAMakefile {

public:
	ListWdbeQLibAMakefile();
	ListWdbeQLibAMakefile(const ListWdbeQLibAMakefile& src);
	~ListWdbeQLibAMakefile();

	void clear();
	unsigned int size() const;
	void append(WdbeQLibAMakefile* rec);

	ListWdbeQLibAMakefile& operator=(const ListWdbeQLibAMakefile& src);

public:
	std::vector<WdbeQLibAMakefile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQLibAMakefile: C++ wrapper for table TblWdbeQLibAMakefile
	*/
class TblWdbeQLibAMakefile {

public:
	TblWdbeQLibAMakefile();
	virtual ~TblWdbeQLibAMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQLibAMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibAMakefile& rst);

	virtual Sbecore::ubigint insertRec(WdbeQLibAMakefile* rec);
	Sbecore::ubigint insertNewRec(WdbeQLibAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string stubX1RefWdbeMMachine = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQLibAMakefile& rst, WdbeQLibAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWdbeMMachine = 0, const std::string stubX1RefWdbeMMachine = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWdbeQLibAMakefile& rst);
	virtual void updateRec(WdbeQLibAMakefile* rec);
	virtual void updateRst(ListWdbeQLibAMakefile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibAMakefile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibAMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQLibAMakefile: C++ wrapper for table TblWdbeQLibAMakefile (MySQL database)
	*/
class MyTblWdbeQLibAMakefile : public TblWdbeQLibAMakefile, public Sbecore::MyTable {

public:
	MyTblWdbeQLibAMakefile();
	~MyTblWdbeQLibAMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibAMakefile& rst);

	Sbecore::ubigint insertRec(WdbeQLibAMakefile* rec);
	void insertRst(ListWdbeQLibAMakefile& rst);
	void updateRec(WdbeQLibAMakefile* rec);
	void updateRst(ListWdbeQLibAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibAMakefile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQLibAMakefile: C++ wrapper for table TblWdbeQLibAMakefile (PgSQL database)
	*/
class PgTblWdbeQLibAMakefile : public TblWdbeQLibAMakefile, public Sbecore::PgTable {

public:
	PgTblWdbeQLibAMakefile();
	~PgTblWdbeQLibAMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQLibAMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQLibAMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibAMakefile& rst);

	Sbecore::ubigint insertRec(WdbeQLibAMakefile* rec);
	void insertRst(ListWdbeQLibAMakefile& rst);
	void updateRec(WdbeQLibAMakefile* rec);
	void updateRst(ListWdbeQLibAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibAMakefile& rst);
};
#endif

#endif

