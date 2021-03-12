/**
	* \file WdbeQFstAStep.h
	* Dbs and XML wrapper for table TblWdbeQFstAStep (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFSTASTEP_H
#define WDBEQFSTASTEP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQFstAStep: record of TblWdbeQFstAStep
	*/
class WdbeQFstAStep {

public:
	WdbeQFstAStep(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string stubFnxRefWdbeMFsmstate = "", const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint fstNum;
	Sbecore::ubigint fnxRefWdbeMFsmstate;
	std::string stubFnxRefWdbeMFsmstate;
	std::string Cond1;
	std::string Ip1;
	std::string Cond2;
	std::string Ip2;
	std::string Cond3;
	std::string Ip3;
	std::string Cond4;
	std::string Ip4;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQFstAStep: recordset of TblWdbeQFstAStep
	*/
class ListWdbeQFstAStep {

public:
	ListWdbeQFstAStep();
	ListWdbeQFstAStep(const ListWdbeQFstAStep& src);
	~ListWdbeQFstAStep();

	void clear();
	unsigned int size() const;
	void append(WdbeQFstAStep* rec);

	ListWdbeQFstAStep& operator=(const ListWdbeQFstAStep& src);

public:
	std::vector<WdbeQFstAStep*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQFstAStep: C++ wrapper for table TblWdbeQFstAStep
	*/
class TblWdbeQFstAStep {

public:
	TblWdbeQFstAStep();
	virtual ~TblWdbeQFstAStep();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQFstAStep** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstAStep& rst);

	virtual Sbecore::ubigint insertRec(WdbeQFstAStep* rec);
	Sbecore::ubigint insertNewRec(WdbeQFstAStep** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string stubFnxRefWdbeMFsmstate = "", const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQFstAStep& rst, WdbeQFstAStep** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string stubFnxRefWdbeMFsmstate = "", const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");
	virtual void insertRst(ListWdbeQFstAStep& rst);
	virtual void updateRec(WdbeQFstAStep* rec);
	virtual void updateRst(ListWdbeQFstAStep& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstAStep** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstAStep& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQFstAStep: C++ wrapper for table TblWdbeQFstAStep (MySQL database)
	*/
class MyTblWdbeQFstAStep : public TblWdbeQFstAStep, public Sbecore::MyTable {

public:
	MyTblWdbeQFstAStep();
	~MyTblWdbeQFstAStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstAStep& rst);

	Sbecore::ubigint insertRec(WdbeQFstAStep* rec);
	void insertRst(ListWdbeQFstAStep& rst);
	void updateRec(WdbeQFstAStep* rec);
	void updateRst(ListWdbeQFstAStep& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstAStep& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQFstAStep: C++ wrapper for table TblWdbeQFstAStep (PgSQL database)
	*/
class PgTblWdbeQFstAStep : public TblWdbeQFstAStep, public Sbecore::PgTable {

public:
	PgTblWdbeQFstAStep();
	~PgTblWdbeQFstAStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQFstAStep& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQFstAStep& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQFstAStep& rst);

	Sbecore::ubigint insertRec(WdbeQFstAStep* rec);
	void insertRst(ListWdbeQFstAStep& rst);
	void updateRec(WdbeQFstAStep* rec);
	void updateRst(ListWdbeQFstAStep& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQFstAStep** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQFstAStep& rst);
};
#endif

#endif
