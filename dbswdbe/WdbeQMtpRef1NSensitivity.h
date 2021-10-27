/**
	* \file WdbeQMtpRef1NSensitivity.h
	* Dbs and XML wrapper for table TblWdbeQMtpRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPREF1NSENSITIVITY_H
#define WDBEQMTPREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpRef1NSensitivity: record of TblWdbeQMtpRef1NSensitivity
	*/
class WdbeQMtpRef1NSensitivity {

public:
	WdbeQMtpRef1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpRef1NSensitivity: recordset of TblWdbeQMtpRef1NSensitivity
	*/
class ListWdbeQMtpRef1NSensitivity {

public:
	ListWdbeQMtpRef1NSensitivity();
	ListWdbeQMtpRef1NSensitivity(const ListWdbeQMtpRef1NSensitivity& src);
	~ListWdbeQMtpRef1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpRef1NSensitivity* rec);

	ListWdbeQMtpRef1NSensitivity& operator=(const ListWdbeQMtpRef1NSensitivity& src);

public:
	std::vector<WdbeQMtpRef1NSensitivity*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpRef1NSensitivity: C++ wrapper for table TblWdbeQMtpRef1NSensitivity
	*/
class TblWdbeQMtpRef1NSensitivity {

public:
	TblWdbeQMtpRef1NSensitivity();
	virtual ~TblWdbeQMtpRef1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpRef1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpRef1NSensitivity& rst, WdbeQMtpRef1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpRef1NSensitivity& rst);
	virtual void updateRec(WdbeQMtpRef1NSensitivity* rec);
	virtual void updateRst(ListWdbeQMtpRef1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpRef1NSensitivity: C++ wrapper for table TblWdbeQMtpRef1NSensitivity (MySQL database)
	*/
class MyTblWdbeQMtpRef1NSensitivity : public TblWdbeQMtpRef1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpRef1NSensitivity();
	~MyTblWdbeQMtpRef1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NSensitivity* rec);
	void insertRst(ListWdbeQMtpRef1NSensitivity& rst);
	void updateRec(WdbeQMtpRef1NSensitivity* rec);
	void updateRst(ListWdbeQMtpRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpRef1NSensitivity: C++ wrapper for table TblWdbeQMtpRef1NSensitivity (PgSQL database)
	*/
class PgTblWdbeQMtpRef1NSensitivity : public TblWdbeQMtpRef1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpRef1NSensitivity();
	~PgTblWdbeQMtpRef1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpRef1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpRef1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NSensitivity& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NSensitivity* rec);
	void insertRst(ListWdbeQMtpRef1NSensitivity& rst);
	void updateRec(WdbeQMtpRef1NSensitivity* rec);
	void updateRst(ListWdbeQMtpRef1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NSensitivity& rst);
};
#endif

#endif
