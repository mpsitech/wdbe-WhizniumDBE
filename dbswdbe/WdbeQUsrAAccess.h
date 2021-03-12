/**
	* \file WdbeQUsrAAccess.h
	* Dbs and XML wrapper for table TblWdbeQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSRAACCESS_H
#define WDBEQUSRAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUsrAAccess: record of TblWdbeQUsrAAccess
	*/
class WdbeQUsrAAccess {

public:
	WdbeQUsrAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUsrAAccess: recordset of TblWdbeQUsrAAccess
	*/
class ListWdbeQUsrAAccess {

public:
	ListWdbeQUsrAAccess();
	ListWdbeQUsrAAccess(const ListWdbeQUsrAAccess& src);
	~ListWdbeQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(WdbeQUsrAAccess* rec);

	ListWdbeQUsrAAccess& operator=(const ListWdbeQUsrAAccess& src);

public:
	std::vector<WdbeQUsrAAccess*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUsrAAccess: C++ wrapper for table TblWdbeQUsrAAccess
	*/
class TblWdbeQUsrAAccess {

public:
	TblWdbeQUsrAAccess();
	virtual ~TblWdbeQUsrAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrAAccess& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUsrAAccess* rec);
	Sbecore::ubigint insertNewRec(WdbeQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUsrAAccess& rst, WdbeQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string srefX1IxWdbeVFeatgroup = "", const std::string titX1IxWdbeVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0, const std::string srefsIxWdbeWAccess = "", const std::string titsIxWdbeWAccess = "");
	virtual void insertRst(ListWdbeQUsrAAccess& rst);
	virtual void updateRec(WdbeQUsrAAccess* rec);
	virtual void updateRst(ListWdbeQUsrAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUsrAAccess: C++ wrapper for table TblWdbeQUsrAAccess (MySQL database)
	*/
class MyTblWdbeQUsrAAccess : public TblWdbeQUsrAAccess, public Sbecore::MyTable {

public:
	MyTblWdbeQUsrAAccess();
	~MyTblWdbeQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WdbeQUsrAAccess* rec);
	void insertRst(ListWdbeQUsrAAccess& rst);
	void updateRec(WdbeQUsrAAccess* rec);
	void updateRst(ListWdbeQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUsrAAccess: C++ wrapper for table TblWdbeQUsrAAccess (PgSQL database)
	*/
class PgTblWdbeQUsrAAccess : public TblWdbeQUsrAAccess, public Sbecore::PgTable {

public:
	PgTblWdbeQUsrAAccess();
	~PgTblWdbeQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUsrAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WdbeQUsrAAccess* rec);
	void insertRst(ListWdbeQUsrAAccess& rst);
	void updateRec(WdbeQUsrAAccess* rec);
	void updateRst(ListWdbeQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUsrAAccess& rst);
};
#endif

#endif
