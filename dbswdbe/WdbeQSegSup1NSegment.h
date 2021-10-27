/**
	* \file WdbeQSegSup1NSegment.h
	* Dbs and XML wrapper for table TblWdbeQSegSup1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSEGSUP1NSEGMENT_H
#define WDBEQSEGSUP1NSEGMENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSegSup1NSegment: record of TblWdbeQSegSup1NSegment
	*/
class WdbeQSegSup1NSegment {

public:
	WdbeQSegSup1NSegment(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSegSup1NSegment: recordset of TblWdbeQSegSup1NSegment
	*/
class ListWdbeQSegSup1NSegment {

public:
	ListWdbeQSegSup1NSegment();
	ListWdbeQSegSup1NSegment(const ListWdbeQSegSup1NSegment& src);
	~ListWdbeQSegSup1NSegment();

	void clear();
	unsigned int size() const;
	void append(WdbeQSegSup1NSegment* rec);

	ListWdbeQSegSup1NSegment& operator=(const ListWdbeQSegSup1NSegment& src);

public:
	std::vector<WdbeQSegSup1NSegment*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSegSup1NSegment: C++ wrapper for table TblWdbeQSegSup1NSegment
	*/
class TblWdbeQSegSup1NSegment {

public:
	TblWdbeQSegSup1NSegment();
	virtual ~TblWdbeQSegSup1NSegment();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSegSup1NSegment** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegSup1NSegment& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSegSup1NSegment* rec);
	Sbecore::ubigint insertNewRec(WdbeQSegSup1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSegSup1NSegment& rst, WdbeQSegSup1NSegment** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSegSup1NSegment& rst);
	virtual void updateRec(WdbeQSegSup1NSegment* rec);
	virtual void updateRst(ListWdbeQSegSup1NSegment& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegSup1NSegment** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegSup1NSegment& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSegSup1NSegment: C++ wrapper for table TblWdbeQSegSup1NSegment (MySQL database)
	*/
class MyTblWdbeQSegSup1NSegment : public TblWdbeQSegSup1NSegment, public Sbecore::MyTable {

public:
	MyTblWdbeQSegSup1NSegment();
	~MyTblWdbeQSegSup1NSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegSup1NSegment& rst);

	Sbecore::ubigint insertRec(WdbeQSegSup1NSegment* rec);
	void insertRst(ListWdbeQSegSup1NSegment& rst);
	void updateRec(WdbeQSegSup1NSegment* rec);
	void updateRst(ListWdbeQSegSup1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegSup1NSegment& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSegSup1NSegment: C++ wrapper for table TblWdbeQSegSup1NSegment (PgSQL database)
	*/
class PgTblWdbeQSegSup1NSegment : public TblWdbeQSegSup1NSegment, public Sbecore::PgTable {

public:
	PgTblWdbeQSegSup1NSegment();
	~PgTblWdbeQSegSup1NSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSegSup1NSegment& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSegSup1NSegment& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSegSup1NSegment& rst);

	Sbecore::ubigint insertRec(WdbeQSegSup1NSegment* rec);
	void insertRst(ListWdbeQSegSup1NSegment& rst);
	void updateRec(WdbeQSegSup1NSegment* rec);
	void updateRst(ListWdbeQSegSup1NSegment& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSegSup1NSegment** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSegSup1NSegment& rst);
};
#endif

#endif
