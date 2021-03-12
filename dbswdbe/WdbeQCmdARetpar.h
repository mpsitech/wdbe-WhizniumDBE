/**
	* \file WdbeQCmdARetpar.h
	* Dbs and XML wrapper for table TblWdbeQCmdARetpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCMDARETPAR_H
#define WDBEQCMDARETPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmdARetpar: record of TblWdbeQCmdARetpar
	*/
class WdbeQCmdARetpar {

public:
	WdbeQCmdARetpar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint cmdNum;
	std::string sref;
	Sbecore::uint ixWdbeVPartype;
	std::string srefIxWdbeVPartype;
	std::string titIxWdbeVPartype;
	Sbecore::ubigint refWdbeMVector;
	std::string stubRefWdbeMVector;
	Sbecore::utinyint Length;
	std::string Comment;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmdARetpar: recordset of TblWdbeQCmdARetpar
	*/
class ListWdbeQCmdARetpar {

public:
	ListWdbeQCmdARetpar();
	ListWdbeQCmdARetpar(const ListWdbeQCmdARetpar& src);
	~ListWdbeQCmdARetpar();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmdARetpar* rec);

	ListWdbeQCmdARetpar& operator=(const ListWdbeQCmdARetpar& src);

public:
	std::vector<WdbeQCmdARetpar*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmdARetpar: C++ wrapper for table TblWdbeQCmdARetpar
	*/
class TblWdbeQCmdARetpar {

public:
	TblWdbeQCmdARetpar();
	virtual ~TblWdbeQCmdARetpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdARetpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdARetpar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmdARetpar* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmdARetpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmdARetpar& rst, WdbeQCmdARetpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeQCmdARetpar& rst);
	virtual void updateRec(WdbeQCmdARetpar* rec);
	virtual void updateRst(ListWdbeQCmdARetpar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdARetpar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdARetpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmdARetpar: C++ wrapper for table TblWdbeQCmdARetpar (MySQL database)
	*/
class MyTblWdbeQCmdARetpar : public TblWdbeQCmdARetpar, public Sbecore::MyTable {

public:
	MyTblWdbeQCmdARetpar();
	~MyTblWdbeQCmdARetpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdARetpar& rst);

	Sbecore::ubigint insertRec(WdbeQCmdARetpar* rec);
	void insertRst(ListWdbeQCmdARetpar& rst);
	void updateRec(WdbeQCmdARetpar* rec);
	void updateRst(ListWdbeQCmdARetpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdARetpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmdARetpar: C++ wrapper for table TblWdbeQCmdARetpar (PgSQL database)
	*/
class PgTblWdbeQCmdARetpar : public TblWdbeQCmdARetpar, public Sbecore::PgTable {

public:
	PgTblWdbeQCmdARetpar();
	~PgTblWdbeQCmdARetpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmdARetpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmdARetpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdARetpar& rst);

	Sbecore::ubigint insertRec(WdbeQCmdARetpar* rec);
	void insertRst(ListWdbeQCmdARetpar& rst);
	void updateRec(WdbeQCmdARetpar* rec);
	void updateRst(ListWdbeQCmdARetpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdARetpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdARetpar& rst);
};
#endif

#endif
