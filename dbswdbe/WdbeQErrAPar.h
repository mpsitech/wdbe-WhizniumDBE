/**
	* \file WdbeQErrAPar.h
	* Dbs and XML wrapper for table TblWdbeQErrAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQERRAPAR_H
#define WDBEQERRAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQErrAPar: record of TblWdbeQErrAPar
	*/
class WdbeQErrAPar {

public:
	WdbeQErrAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint errNum;
	std::string sref;
	Sbecore::uint ixWdbeVPartype;
	std::string srefIxWdbeVPartype;
	std::string titIxWdbeVPartype;
	Sbecore::ubigint refWdbeMVector;
	std::string stubRefWdbeMVector;
	Sbecore::utinyint Length;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQErrAPar: recordset of TblWdbeQErrAPar
	*/
class ListWdbeQErrAPar {

public:
	ListWdbeQErrAPar();
	ListWdbeQErrAPar(const ListWdbeQErrAPar& src);
	~ListWdbeQErrAPar();

	void clear();
	unsigned int size() const;
	void append(WdbeQErrAPar* rec);

	ListWdbeQErrAPar& operator=(const ListWdbeQErrAPar& src);

public:
	std::vector<WdbeQErrAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQErrAPar: C++ wrapper for table TblWdbeQErrAPar
	*/
class TblWdbeQErrAPar {

public:
	TblWdbeQErrAPar();
	virtual ~TblWdbeQErrAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQErrAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrAPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQErrAPar* rec);
	Sbecore::ubigint insertNewRec(WdbeQErrAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQErrAPar& rst, WdbeQErrAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint errNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeQErrAPar& rst);
	virtual void updateRec(WdbeQErrAPar* rec);
	virtual void updateRst(ListWdbeQErrAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQErrAPar: C++ wrapper for table TblWdbeQErrAPar (MySQL database)
	*/
class MyTblWdbeQErrAPar : public TblWdbeQErrAPar, public Sbecore::MyTable {

public:
	MyTblWdbeQErrAPar();
	~MyTblWdbeQErrAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrAPar& rst);

	Sbecore::ubigint insertRec(WdbeQErrAPar* rec);
	void insertRst(ListWdbeQErrAPar& rst);
	void updateRec(WdbeQErrAPar* rec);
	void updateRst(ListWdbeQErrAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQErrAPar: C++ wrapper for table TblWdbeQErrAPar (PgSQL database)
	*/
class PgTblWdbeQErrAPar : public TblWdbeQErrAPar, public Sbecore::PgTable {

public:
	PgTblWdbeQErrAPar();
	~PgTblWdbeQErrAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQErrAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQErrAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQErrAPar& rst);

	Sbecore::ubigint insertRec(WdbeQErrAPar* rec);
	void insertRst(ListWdbeQErrAPar& rst);
	void updateRec(WdbeQErrAPar* rec);
	void updateRst(ListWdbeQErrAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQErrAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQErrAPar& rst);
};
#endif

#endif

