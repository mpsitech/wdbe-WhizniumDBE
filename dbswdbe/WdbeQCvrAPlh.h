/**
	* \file WdbeQCvrAPlh.h
	* Dbs and XML wrapper for table TblWdbeQCvrAPlh (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRAPLH_H
#define WDBEQCVRAPLH_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCvrAPlh: record of TblWdbeQCvrAPlh
	*/
class WdbeQCvrAPlh {

public:
	WdbeQCvrAPlh(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint cvrNum;
	std::string sref;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQCvrAPlh: recordset of TblWdbeQCvrAPlh
	*/
class ListWdbeQCvrAPlh {

public:
	ListWdbeQCvrAPlh();
	ListWdbeQCvrAPlh(const ListWdbeQCvrAPlh& src);
	~ListWdbeQCvrAPlh();

	void clear();
	unsigned int size() const;
	void append(WdbeQCvrAPlh* rec);

	ListWdbeQCvrAPlh& operator=(const ListWdbeQCvrAPlh& src);

public:
	std::vector<WdbeQCvrAPlh*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCvrAPlh: C++ wrapper for table TblWdbeQCvrAPlh
	*/
class TblWdbeQCvrAPlh {

public:
	TblWdbeQCvrAPlh();
	virtual ~TblWdbeQCvrAPlh();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAPlh** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAPlh& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCvrAPlh* rec);
	Sbecore::ubigint insertNewRec(WdbeQCvrAPlh** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCvrAPlh& rst, WdbeQCvrAPlh** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cvrNum = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWdbeQCvrAPlh& rst);
	virtual void updateRec(WdbeQCvrAPlh* rec);
	virtual void updateRst(ListWdbeQCvrAPlh& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAPlh** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAPlh& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCvrAPlh: C++ wrapper for table TblWdbeQCvrAPlh (MySQL database)
	*/
class MyTblWdbeQCvrAPlh : public TblWdbeQCvrAPlh, public Sbecore::MyTable {

public:
	MyTblWdbeQCvrAPlh();
	~MyTblWdbeQCvrAPlh();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAPlh& rst);

	Sbecore::ubigint insertRec(WdbeQCvrAPlh* rec);
	void insertRst(ListWdbeQCvrAPlh& rst);
	void updateRec(WdbeQCvrAPlh* rec);
	void updateRst(ListWdbeQCvrAPlh& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAPlh& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCvrAPlh: C++ wrapper for table TblWdbeQCvrAPlh (PgSQL database)
	*/
class PgTblWdbeQCvrAPlh : public TblWdbeQCvrAPlh, public Sbecore::PgTable {

public:
	PgTblWdbeQCvrAPlh();
	~PgTblWdbeQCvrAPlh();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCvrAPlh& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCvrAPlh& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCvrAPlh& rst);

	Sbecore::ubigint insertRec(WdbeQCvrAPlh* rec);
	void insertRst(ListWdbeQCvrAPlh& rst);
	void updateRec(WdbeQCvrAPlh* rec);
	void updateRst(ListWdbeQCvrAPlh& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCvrAPlh** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCvrAPlh& rst);
};
#endif

#endif

