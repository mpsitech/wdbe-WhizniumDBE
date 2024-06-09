/**
	* \file WdbeQLibMNComponent.h
	* Dbs and XML wrapper for table TblWdbeQLibMNComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQLIBMNCOMPONENT_H
#define WDBEQLIBMNCOMPONENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQLibMNComponent: record of TblWdbeQLibMNComponent
	*/
class WdbeQLibMNComponent {

public:
	WdbeQLibMNComponent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQLibMNComponent: recordset of TblWdbeQLibMNComponent
	*/
class ListWdbeQLibMNComponent {

public:
	ListWdbeQLibMNComponent();
	ListWdbeQLibMNComponent(const ListWdbeQLibMNComponent& src);
	~ListWdbeQLibMNComponent();

	void clear();
	unsigned int size() const;
	void append(WdbeQLibMNComponent* rec);

	ListWdbeQLibMNComponent& operator=(const ListWdbeQLibMNComponent& src);

public:
	std::vector<WdbeQLibMNComponent*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQLibMNComponent: C++ wrapper for table TblWdbeQLibMNComponent
	*/
class TblWdbeQLibMNComponent {

public:
	TblWdbeQLibMNComponent();
	virtual ~TblWdbeQLibMNComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNComponent& rst);

	virtual Sbecore::ubigint insertRec(WdbeQLibMNComponent* rec);
	Sbecore::ubigint insertNewRec(WdbeQLibMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQLibMNComponent& rst, WdbeQLibMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQLibMNComponent& rst);
	virtual void updateRec(WdbeQLibMNComponent* rec);
	virtual void updateRst(ListWdbeQLibMNComponent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNComponent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQLibMNComponent: C++ wrapper for table TblWdbeQLibMNComponent (MySQL database)
	*/
class MyTblWdbeQLibMNComponent : public TblWdbeQLibMNComponent, public Sbecore::MyTable {

public:
	MyTblWdbeQLibMNComponent();
	~MyTblWdbeQLibMNComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNComponent& rst);

	Sbecore::ubigint insertRec(WdbeQLibMNComponent* rec);
	void insertRst(ListWdbeQLibMNComponent& rst);
	void updateRec(WdbeQLibMNComponent* rec);
	void updateRst(ListWdbeQLibMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNComponent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQLibMNComponent: C++ wrapper for table TblWdbeQLibMNComponent (PgSQL database)
	*/
class PgTblWdbeQLibMNComponent : public TblWdbeQLibMNComponent, public Sbecore::PgTable {

public:
	PgTblWdbeQLibMNComponent();
	~PgTblWdbeQLibMNComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQLibMNComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQLibMNComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQLibMNComponent& rst);

	Sbecore::ubigint insertRec(WdbeQLibMNComponent* rec);
	void insertRst(ListWdbeQLibMNComponent& rst);
	void updateRec(WdbeQLibMNComponent* rec);
	void updateRst(ListWdbeQLibMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQLibMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQLibMNComponent& rst);
};
#endif

#endif
