/**
	* \file WdbeQMtpMge1NSignal.h
	* Dbs and XML wrapper for table TblWdbeQMtpMge1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPMGE1NSIGNAL_H
#define WDBEQMTPMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpMge1NSignal: record of TblWdbeQMtpMge1NSignal
	*/
class WdbeQMtpMge1NSignal {

public:
	WdbeQMtpMge1NSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpMge1NSignal: recordset of TblWdbeQMtpMge1NSignal
	*/
class ListWdbeQMtpMge1NSignal {

public:
	ListWdbeQMtpMge1NSignal();
	ListWdbeQMtpMge1NSignal(const ListWdbeQMtpMge1NSignal& src);
	~ListWdbeQMtpMge1NSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpMge1NSignal* rec);

	ListWdbeQMtpMge1NSignal& operator=(const ListWdbeQMtpMge1NSignal& src);

public:
	std::vector<WdbeQMtpMge1NSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpMge1NSignal: C++ wrapper for table TblWdbeQMtpMge1NSignal
	*/
class TblWdbeQMtpMge1NSignal {

public:
	TblWdbeQMtpMge1NSignal();
	virtual ~TblWdbeQMtpMge1NSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMge1NSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpMge1NSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpMge1NSignal& rst, WdbeQMtpMge1NSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpMge1NSignal& rst);
	virtual void updateRec(WdbeQMtpMge1NSignal* rec);
	virtual void updateRst(ListWdbeQMtpMge1NSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMge1NSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMge1NSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpMge1NSignal: C++ wrapper for table TblWdbeQMtpMge1NSignal (MySQL database)
	*/
class MyTblWdbeQMtpMge1NSignal : public TblWdbeQMtpMge1NSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpMge1NSignal();
	~MyTblWdbeQMtpMge1NSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMge1NSignal* rec);
	void insertRst(ListWdbeQMtpMge1NSignal& rst);
	void updateRec(WdbeQMtpMge1NSignal* rec);
	void updateRst(ListWdbeQMtpMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMge1NSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpMge1NSignal: C++ wrapper for table TblWdbeQMtpMge1NSignal (PgSQL database)
	*/
class PgTblWdbeQMtpMge1NSignal : public TblWdbeQMtpMge1NSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpMge1NSignal();
	~PgTblWdbeQMtpMge1NSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpMge1NSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpMge1NSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpMge1NSignal& rst);

	Sbecore::ubigint insertRec(WdbeQMtpMge1NSignal* rec);
	void insertRst(ListWdbeQMtpMge1NSignal& rst);
	void updateRec(WdbeQMtpMge1NSignal* rec);
	void updateRst(ListWdbeQMtpMge1NSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpMge1NSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpMge1NSignal& rst);
};
#endif

#endif
