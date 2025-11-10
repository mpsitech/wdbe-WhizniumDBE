/**
	* \file WdbeQCmdHk1NVector.h
	* Dbs and XML wrapper for table TblWdbeQCmdHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
  */
// IP header --- ABOVE

#ifndef WDBEQCMDHK1NVECTOR_H
#define WDBEQCMDHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmdHk1NVector: record of TblWdbeQCmdHk1NVector
	*/
class WdbeQCmdHk1NVector {

public:
	WdbeQCmdHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmdHk1NVector: recordset of TblWdbeQCmdHk1NVector
	*/
class ListWdbeQCmdHk1NVector {

public:
	ListWdbeQCmdHk1NVector();
	ListWdbeQCmdHk1NVector(const ListWdbeQCmdHk1NVector& src);
	~ListWdbeQCmdHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmdHk1NVector* rec);

	ListWdbeQCmdHk1NVector& operator=(const ListWdbeQCmdHk1NVector& src);

public:
	std::vector<WdbeQCmdHk1NVector*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmdHk1NVector: C++ wrapper for table TblWdbeQCmdHk1NVector
	*/
class TblWdbeQCmdHk1NVector {

public:
	TblWdbeQCmdHk1NVector();
	virtual ~TblWdbeQCmdHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmdHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmdHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmdHk1NVector& rst, WdbeQCmdHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQCmdHk1NVector& rst);
	virtual void updateRec(WdbeQCmdHk1NVector* rec);
	virtual void updateRst(ListWdbeQCmdHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmdHk1NVector: C++ wrapper for table TblWdbeQCmdHk1NVector (MySQL database)
	*/
class MyTblWdbeQCmdHk1NVector : public TblWdbeQCmdHk1NVector, public Sbecore::MyTable {

public:
	MyTblWdbeQCmdHk1NVector();
	~MyTblWdbeQCmdHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQCmdHk1NVector* rec);
	void insertRst(ListWdbeQCmdHk1NVector& rst);
	void updateRec(WdbeQCmdHk1NVector* rec);
	void updateRst(ListWdbeQCmdHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmdHk1NVector: C++ wrapper for table TblWdbeQCmdHk1NVector (PgSQL database)
	*/
class PgTblWdbeQCmdHk1NVector : public TblWdbeQCmdHk1NVector, public Sbecore::PgTable {

public:
	PgTblWdbeQCmdHk1NVector();
	~PgTblWdbeQCmdHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmdHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmdHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdHk1NVector& rst);

	Sbecore::ubigint insertRec(WdbeQCmdHk1NVector* rec);
	void insertRst(ListWdbeQCmdHk1NVector& rst);
	void updateRec(WdbeQCmdHk1NVector* rec);
	void updateRst(ListWdbeQCmdHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdHk1NVector& rst);
};
#endif

#endif
