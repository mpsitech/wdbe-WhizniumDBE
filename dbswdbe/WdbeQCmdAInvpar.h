/**
	* \file WdbeQCmdAInvpar.h
	* Dbs and XML wrapper for table TblWdbeQCmdAInvpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCMDAINVPAR_H
#define WDBEQCMDAINVPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmdAInvpar: record of TblWdbeQCmdAInvpar
	*/
class WdbeQCmdAInvpar {

public:
	WdbeQCmdAInvpar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string stubRefWdbeMVectoritem = "", const std::string Comment = "");

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
	std::string Defval;
	Sbecore::ubigint refWdbeMVectoritem;
	std::string stubRefWdbeMVectoritem;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCmdAInvpar: recordset of TblWdbeQCmdAInvpar
	*/
class ListWdbeQCmdAInvpar {

public:
	ListWdbeQCmdAInvpar();
	ListWdbeQCmdAInvpar(const ListWdbeQCmdAInvpar& src);
	~ListWdbeQCmdAInvpar();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmdAInvpar* rec);

	ListWdbeQCmdAInvpar& operator=(const ListWdbeQCmdAInvpar& src);

public:
	std::vector<WdbeQCmdAInvpar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmdAInvpar: C++ wrapper for table TblWdbeQCmdAInvpar
	*/
class TblWdbeQCmdAInvpar {

public:
	TblWdbeQCmdAInvpar();
	virtual ~TblWdbeQCmdAInvpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdAInvpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdAInvpar& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmdAInvpar* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmdAInvpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string stubRefWdbeMVectoritem = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmdAInvpar& rst, WdbeQCmdAInvpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string srefIxWdbeVPartype = "", const std::string titIxWdbeVPartype = "", const Sbecore::ubigint refWdbeMVector = 0, const std::string stubRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string stubRefWdbeMVectoritem = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQCmdAInvpar& rst);
	virtual void updateRec(WdbeQCmdAInvpar* rec);
	virtual void updateRst(ListWdbeQCmdAInvpar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdAInvpar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdAInvpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmdAInvpar: C++ wrapper for table TblWdbeQCmdAInvpar (MySQL database)
	*/
class MyTblWdbeQCmdAInvpar : public TblWdbeQCmdAInvpar, public Sbecore::MyTable {

public:
	MyTblWdbeQCmdAInvpar();
	~MyTblWdbeQCmdAInvpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdAInvpar& rst);

	Sbecore::ubigint insertRec(WdbeQCmdAInvpar* rec);
	void insertRst(ListWdbeQCmdAInvpar& rst);
	void updateRec(WdbeQCmdAInvpar* rec);
	void updateRst(ListWdbeQCmdAInvpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdAInvpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmdAInvpar: C++ wrapper for table TblWdbeQCmdAInvpar (PgSQL database)
	*/
class PgTblWdbeQCmdAInvpar : public TblWdbeQCmdAInvpar, public Sbecore::PgTable {

public:
	PgTblWdbeQCmdAInvpar();
	~PgTblWdbeQCmdAInvpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmdAInvpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmdAInvpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdAInvpar& rst);

	Sbecore::ubigint insertRec(WdbeQCmdAInvpar* rec);
	void insertRst(ListWdbeQCmdAInvpar& rst);
	void updateRec(WdbeQCmdAInvpar* rec);
	void updateRst(ListWdbeQCmdAInvpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdAInvpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdAInvpar& rst);
};
#endif

#endif
