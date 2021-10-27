/**
	* \file WdbeQModMNPeripheral.h
	* Dbs and XML wrapper for table TblWdbeQModMNPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODMNPERIPHERAL_H
#define WDBEQMODMNPERIPHERAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModMNPeripheral: record of TblWdbeQModMNPeripheral
	*/
class WdbeQModMNPeripheral {

public:
	WdbeQModMNPeripheral(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWdbeQModMNPeripheral: recordset of TblWdbeQModMNPeripheral
	*/
class ListWdbeQModMNPeripheral {

public:
	ListWdbeQModMNPeripheral();
	ListWdbeQModMNPeripheral(const ListWdbeQModMNPeripheral& src);
	~ListWdbeQModMNPeripheral();

	void clear();
	unsigned int size() const;
	void append(WdbeQModMNPeripheral* rec);

	ListWdbeQModMNPeripheral& operator=(const ListWdbeQModMNPeripheral& src);

public:
	std::vector<WdbeQModMNPeripheral*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModMNPeripheral: C++ wrapper for table TblWdbeQModMNPeripheral
	*/
class TblWdbeQModMNPeripheral {

public:
	TblWdbeQModMNPeripheral();
	virtual ~TblWdbeQModMNPeripheral();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModMNPeripheral** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMNPeripheral& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModMNPeripheral* rec);
	Sbecore::ubigint insertNewRec(WdbeQModMNPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModMNPeripheral& rst, WdbeQModMNPeripheral** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWdbeQModMNPeripheral& rst);
	virtual void updateRec(WdbeQModMNPeripheral* rec);
	virtual void updateRst(ListWdbeQModMNPeripheral& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMNPeripheral** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMNPeripheral& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModMNPeripheral: C++ wrapper for table TblWdbeQModMNPeripheral (MySQL database)
	*/
class MyTblWdbeQModMNPeripheral : public TblWdbeQModMNPeripheral, public Sbecore::MyTable {

public:
	MyTblWdbeQModMNPeripheral();
	~MyTblWdbeQModMNPeripheral();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMNPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQModMNPeripheral* rec);
	void insertRst(ListWdbeQModMNPeripheral& rst);
	void updateRec(WdbeQModMNPeripheral* rec);
	void updateRst(ListWdbeQModMNPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMNPeripheral& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModMNPeripheral: C++ wrapper for table TblWdbeQModMNPeripheral (PgSQL database)
	*/
class PgTblWdbeQModMNPeripheral : public TblWdbeQModMNPeripheral, public Sbecore::PgTable {

public:
	PgTblWdbeQModMNPeripheral();
	~PgTblWdbeQModMNPeripheral();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModMNPeripheral& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModMNPeripheral& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModMNPeripheral& rst);

	Sbecore::ubigint insertRec(WdbeQModMNPeripheral* rec);
	void insertRst(ListWdbeQModMNPeripheral& rst);
	void updateRec(WdbeQModMNPeripheral* rec);
	void updateRst(ListWdbeQModMNPeripheral& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModMNPeripheral** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModMNPeripheral& rst);
};
#endif

#endif
