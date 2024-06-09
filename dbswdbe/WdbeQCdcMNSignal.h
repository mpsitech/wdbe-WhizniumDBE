/**
	* \file WdbeQCdcMNSignal.h
	* Dbs and XML wrapper for table TblWdbeQCdcMNSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCDCMNSIGNAL_H
#define WDBEQCDCMNSIGNAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCdcMNSignal: record of TblWdbeQCdcMNSignal
	*/
class WdbeQCdcMNSignal {

public:
	WdbeQCdcMNSignal(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixVDir;
	std::string srefIxVDir;
	std::string titIxVDir;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCdcMNSignal: recordset of TblWdbeQCdcMNSignal
	*/
class ListWdbeQCdcMNSignal {

public:
	ListWdbeQCdcMNSignal();
	ListWdbeQCdcMNSignal(const ListWdbeQCdcMNSignal& src);
	~ListWdbeQCdcMNSignal();

	void clear();
	unsigned int size() const;
	void append(WdbeQCdcMNSignal* rec);

	ListWdbeQCdcMNSignal& operator=(const ListWdbeQCdcMNSignal& src);

public:
	std::vector<WdbeQCdcMNSignal*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCdcMNSignal: C++ wrapper for table TblWdbeQCdcMNSignal
	*/
class TblWdbeQCdcMNSignal {

public:
	TblWdbeQCdcMNSignal();
	virtual ~TblWdbeQCdcMNSignal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcMNSignal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcMNSignal& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCdcMNSignal* rec);
	Sbecore::ubigint insertNewRec(WdbeQCdcMNSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCdcMNSignal& rst, WdbeQCdcMNSignal** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");
	virtual void insertRst(ListWdbeQCdcMNSignal& rst);
	virtual void updateRec(WdbeQCdcMNSignal* rec);
	virtual void updateRst(ListWdbeQCdcMNSignal& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcMNSignal** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcMNSignal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCdcMNSignal: C++ wrapper for table TblWdbeQCdcMNSignal (MySQL database)
	*/
class MyTblWdbeQCdcMNSignal : public TblWdbeQCdcMNSignal, public Sbecore::MyTable {

public:
	MyTblWdbeQCdcMNSignal();
	~MyTblWdbeQCdcMNSignal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcMNSignal& rst);

	Sbecore::ubigint insertRec(WdbeQCdcMNSignal* rec);
	void insertRst(ListWdbeQCdcMNSignal& rst);
	void updateRec(WdbeQCdcMNSignal* rec);
	void updateRst(ListWdbeQCdcMNSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcMNSignal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCdcMNSignal: C++ wrapper for table TblWdbeQCdcMNSignal (PgSQL database)
	*/
class PgTblWdbeQCdcMNSignal : public TblWdbeQCdcMNSignal, public Sbecore::PgTable {

public:
	PgTblWdbeQCdcMNSignal();
	~PgTblWdbeQCdcMNSignal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCdcMNSignal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCdcMNSignal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCdcMNSignal& rst);

	Sbecore::ubigint insertRec(WdbeQCdcMNSignal* rec);
	void insertRst(ListWdbeQCdcMNSignal& rst);
	void updateRec(WdbeQCdcMNSignal* rec);
	void updateRst(ListWdbeQCdcMNSignal& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCdcMNSignal** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCdcMNSignal& rst);
};
#endif

#endif
