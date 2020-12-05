/**
	* \file WdbeQUsgAAccess.h
	* Dbs and XML wrapper for table TblWdbeQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSGAACCESS_H
#define WDBEQUSGAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsgAAccess: record of TblWdbeQUsgAAccess
	*/
class WdbeQUsgAAccess {

public:
	WdbeQUsgAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxWdbeVFeatgroup;
	std::string srefX1IxWdbeVFeatgroup;
	std::string titX1IxWdbeVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWdbeWAccess;
	std::string srefsIxWdbeWAccess;
	std::string titsIxWdbeWAccess;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUsgAAccess: recordset of TblWdbeQUsgAAccess
	*/
class ListWdbeQUsgAAccess {

public:
	ListWdbeQUsgAAccess();
	ListWdbeQUsgAAccess(const ListWdbeQUsgAAccess& src);
	~ListWdbeQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsgAAccess* rec);

	ListWdbeQUsgAAccess& operator=(const ListWdbeQUsgAAccess& src);

public:
	std::vector<WdbeQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsgAAccess: C++ wrapper for table TblWdbeQUsgAAccess
	*/
class TblWdbeQUsgAAccess {

public:
	TblWdbeQUsgAAccess();
	virtual ~TblWdbeQUsgAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgAAccess& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsgAAccess* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsgAAccess& rst, WdbeQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");
	virtual void insertRst(ListWdbeQUsgAAccess& rst);
	virtual void updateRec(WdbeQUsgAAccess* rec);
	virtual void updateRst(ListWdbeQUsgAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsgAAccess: C++ wrapper for table TblWdbeQUsgAAccess (MySQL database)
	*/
class MyTblWdbeQUsgAAccess : public TblWdbeQUsgAAccess, public Sbecore::MyTable {

public:
	MyTblWdbeQUsgAAccess();
	~MyTblWdbeQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WdbeQUsgAAccess* rec);
	void insertRst(ListWdbeQUsgAAccess& rst);
	void updateRec(WdbeQUsgAAccess* rec);
	void updateRst(ListWdbeQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsgAAccess: C++ wrapper for table TblWdbeQUsgAAccess (PgSQL database)
	*/
class PgTblWdbeQUsgAAccess : public TblWdbeQUsgAAccess, public Sbecore::PgTable {

public:
	PgTblWdbeQUsgAAccess();
	~PgTblWdbeQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsgAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WdbeQUsgAAccess* rec);
	void insertRst(ListWdbeQUsgAAccess& rst);
	void updateRec(WdbeQUsgAAccess* rec);
	void updateRst(ListWdbeQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsgAAccess& rst);
};
#endif

#endif

