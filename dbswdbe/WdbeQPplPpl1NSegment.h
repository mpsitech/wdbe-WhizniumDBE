/**
	* \file WdbeQPplPpl1NSegment.h
	* Dbs and XML wrapper for table TblWdbeQPplPpl1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPLPPL1NSEGMENT_H
#define WDBEQPPLPPL1NSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPplPpl1NSegment: record of TblWdbeQPplPpl1NSegment
	*/
class WdbeQPplPpl1NSegment {

public:
	WdbeQPplPpl1NSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint pplNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint pplNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPplPpl1NSegment: recordset of TblWdbeQPplPpl1NSegment
	*/
class ListWdbeQPplPpl1NSegment {

public:
	ListWdbeQPplPpl1NSegment();
	ListWdbeQPplPpl1NSegment(const ListWdbeQPplPpl1NSegment& src);
	~ListWdbeQPplPpl1NSegment();

	void clear();
	unsigned int size() const;
	void append(WdbeQPplPpl1NSegment* rec);

	ListWdbeQPplPpl1NSegment& operator=(const ListWdbeQPplPpl1NSegment& src);

public:
	std::vector<WdbeQPplPpl1NSegment*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPplPpl1NSegment: C++ wrapper for table TblWdbeQPplPpl1NSegment
	*/
class TblWdbeQPplPpl1NSegment {

public:
	TblWdbeQPplPpl1NSegment();
	virtual ~TblWdbeQPplPpl1NSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPplPpl1NSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplPpl1NSegment& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPplPpl1NSegment* rec);
	Sbecore::ubigint insertNewRec(WdbeQPplPpl1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint pplNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPplPpl1NSegment& rst, WdbeQPplPpl1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint pplNum = 0);
	virtual void insertRst(ListWdbeQPplPpl1NSegment& rst);
	virtual void updateRec(WdbeQPplPpl1NSegment* rec);
	virtual void updateRst(ListWdbeQPplPpl1NSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplPpl1NSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplPpl1NSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPplPpl1NSegment: C++ wrapper for table TblWdbeQPplPpl1NSegment (MySQL database)
	*/
class MyTblWdbeQPplPpl1NSegment : public TblWdbeQPplPpl1NSegment, public Sbecore::MyTable {

public:
	MyTblWdbeQPplPpl1NSegment();
	~MyTblWdbeQPplPpl1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplPpl1NSegment& rst);

	Sbecore::ubigint insertRec(WdbeQPplPpl1NSegment* rec);
	void insertRst(ListWdbeQPplPpl1NSegment& rst);
	void updateRec(WdbeQPplPpl1NSegment* rec);
	void updateRst(ListWdbeQPplPpl1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplPpl1NSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPplPpl1NSegment: C++ wrapper for table TblWdbeQPplPpl1NSegment (PgSQL database)
	*/
class PgTblWdbeQPplPpl1NSegment : public TblWdbeQPplPpl1NSegment, public Sbecore::PgTable {

public:
	PgTblWdbeQPplPpl1NSegment();
	~PgTblWdbeQPplPpl1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPplPpl1NSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPplPpl1NSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPplPpl1NSegment& rst);

	Sbecore::ubigint insertRec(WdbeQPplPpl1NSegment* rec);
	void insertRst(ListWdbeQPplPpl1NSegment& rst);
	void updateRec(WdbeQPplPpl1NSegment* rec);
	void updateRst(ListWdbeQPplPpl1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPplPpl1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPplPpl1NSegment& rst);
};
#endif

#endif
