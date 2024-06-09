/**
	* \file WdbeQVer1NComponent.h
	* Dbs and XML wrapper for table TblWdbeQVer1NComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQVER1NCOMPONENT_H
#define WDBEQVER1NCOMPONENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVer1NComponent: record of TblWdbeQVer1NComponent
	*/
class WdbeQVer1NComponent {

public:
	WdbeQVer1NComponent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQVer1NComponent: recordset of TblWdbeQVer1NComponent
	*/
class ListWdbeQVer1NComponent {

public:
	ListWdbeQVer1NComponent();
	ListWdbeQVer1NComponent(const ListWdbeQVer1NComponent& src);
	~ListWdbeQVer1NComponent();

	void clear();
	unsigned int size() const;
	void append(WdbeQVer1NComponent* rec);

	ListWdbeQVer1NComponent& operator=(const ListWdbeQVer1NComponent& src);

public:
	std::vector<WdbeQVer1NComponent*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVer1NComponent: C++ wrapper for table TblWdbeQVer1NComponent
	*/
class TblWdbeQVer1NComponent {

public:
	TblWdbeQVer1NComponent();
	virtual ~TblWdbeQVer1NComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NComponent& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVer1NComponent* rec);
	Sbecore::ubigint insertNewRec(WdbeQVer1NComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVer1NComponent& rst, WdbeQVer1NComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVer1NComponent& rst);
	virtual void updateRec(WdbeQVer1NComponent* rec);
	virtual void updateRst(ListWdbeQVer1NComponent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NComponent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVer1NComponent: C++ wrapper for table TblWdbeQVer1NComponent (MySQL database)
	*/
class MyTblWdbeQVer1NComponent : public TblWdbeQVer1NComponent, public Sbecore::MyTable {

public:
	MyTblWdbeQVer1NComponent();
	~MyTblWdbeQVer1NComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NComponent& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NComponent* rec);
	void insertRst(ListWdbeQVer1NComponent& rst);
	void updateRec(WdbeQVer1NComponent* rec);
	void updateRst(ListWdbeQVer1NComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NComponent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVer1NComponent: C++ wrapper for table TblWdbeQVer1NComponent (PgSQL database)
	*/
class PgTblWdbeQVer1NComponent : public TblWdbeQVer1NComponent, public Sbecore::PgTable {

public:
	PgTblWdbeQVer1NComponent();
	~PgTblWdbeQVer1NComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVer1NComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVer1NComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVer1NComponent& rst);

	Sbecore::ubigint insertRec(WdbeQVer1NComponent* rec);
	void insertRst(ListWdbeQVer1NComponent& rst);
	void updateRec(WdbeQVer1NComponent* rec);
	void updateRst(ListWdbeQVer1NComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVer1NComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVer1NComponent& rst);
};
#endif

#endif
