/**
	* \file WdbeQLibMNVersion.h
	* Dbs and XML wrapper for table TblWdbeQLibMNVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQLIBMNVERSION_H
#define WDBEQLIBMNVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQLibMNVersion: record of TblWdbeQLibMNVersion
	*/
class WdbeQLibMNVersion {

public:
	WdbeQLibMNVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQLibMNVersion: recordset of TblWdbeQLibMNVersion
	*/
class ListWdbeQLibMNVersion {

public:
	ListWdbeQLibMNVersion();
	ListWdbeQLibMNVersion(const ListWdbeQLibMNVersion& src);
	~ListWdbeQLibMNVersion();

	void clear();
	unsigned int size() const;
	void append(WdbeQLibMNVersion* rec);

	ListWdbeQLibMNVersion& operator=(const ListWdbeQLibMNVersion& src);

public:
	std::vector<WdbeQLibMNVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQLibMNVersion: C++ wrapper for table TblWdbeQLibMNVersion
	*/
class TblWdbeQLibMNVersion {

public:
	TblWdbeQLibMNVersion();
	virtual ~TblWdbeQLibMNVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNVersion& rst);

	virtual Sbecore::ubigint insertRec(WdbeQLibMNVersion* rec);
	Sbecore::ubigint insertNewRec(WdbeQLibMNVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQLibMNVersion& rst, WdbeQLibMNVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQLibMNVersion& rst);
	virtual void updateRec(WdbeQLibMNVersion* rec);
	virtual void updateRst(ListWdbeQLibMNVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQLibMNVersion: C++ wrapper for table TblWdbeQLibMNVersion (MySQL database)
	*/
class MyTblWdbeQLibMNVersion : public TblWdbeQLibMNVersion, public Sbecore::MyTable {

public:
	MyTblWdbeQLibMNVersion();
	~MyTblWdbeQLibMNVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNVersion& rst);

	Sbecore::ubigint insertRec(WdbeQLibMNVersion* rec);
	void insertRst(ListWdbeQLibMNVersion& rst);
	void updateRec(WdbeQLibMNVersion* rec);
	void updateRst(ListWdbeQLibMNVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQLibMNVersion: C++ wrapper for table TblWdbeQLibMNVersion (PgSQL database)
	*/
class PgTblWdbeQLibMNVersion : public TblWdbeQLibMNVersion, public Sbecore::PgTable {

public:
	PgTblWdbeQLibMNVersion();
	~PgTblWdbeQLibMNVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQLibMNVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQLibMNVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNVersion& rst);

	Sbecore::ubigint insertRec(WdbeQLibMNVersion* rec);
	void insertRst(ListWdbeQLibMNVersion& rst);
	void updateRec(WdbeQLibMNVersion* rec);
	void updateRst(ListWdbeQLibMNVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNVersion& rst);
};
#endif

#endif

