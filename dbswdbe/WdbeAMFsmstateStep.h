/**
	* \file WdbeAMFsmstateStep.h
	* database access for table TblWdbeAMFsmstateStep (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMFSMSTATESTEP_H
#define WDBEAMFSMSTATESTEP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMFsmstateStep: record of TblWdbeAMFsmstateStep
	*/
class WdbeAMFsmstateStep {

public:
	WdbeAMFsmstateStep(const Sbecore::ubigint ref = 0, const Sbecore::ubigint fstRefWdbeMFsmstate = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint fstRefWdbeMFsmstate;
	Sbecore::uint fstNum;
	Sbecore::ubigint fnxRefWdbeMFsmstate;
	std::string Cond1;
	std::string Ip1;
	std::string Cond2;
	std::string Ip2;
	std::string Cond3;
	std::string Ip3;
	std::string Cond4;
	std::string Ip4;

public:
	bool operator==(const WdbeAMFsmstateStep& comp);
	bool operator!=(const WdbeAMFsmstateStep& comp);
};

/**
	* ListWdbeAMFsmstateStep: recordset of TblWdbeAMFsmstateStep
	*/
class ListWdbeAMFsmstateStep {

public:
	ListWdbeAMFsmstateStep();
	ListWdbeAMFsmstateStep(const ListWdbeAMFsmstateStep& src);
	~ListWdbeAMFsmstateStep();

	void clear();
	unsigned int size() const;
	void append(WdbeAMFsmstateStep* rec);

	WdbeAMFsmstateStep* operator[](const Sbecore::uint ix);
	ListWdbeAMFsmstateStep& operator=(const ListWdbeAMFsmstateStep& src);
	bool operator==(const ListWdbeAMFsmstateStep& comp);
	bool operator!=(const ListWdbeAMFsmstateStep& comp);

public:
	std::vector<WdbeAMFsmstateStep*> nodes;
};

/**
	* TblWdbeAMFsmstateStep: C++ wrapper for table TblWdbeAMFsmstateStep
	*/
class TblWdbeAMFsmstateStep {

public:

public:
	TblWdbeAMFsmstateStep();
	virtual ~TblWdbeAMFsmstateStep();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMFsmstateStep** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMFsmstateStep& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMFsmstateStep* rec);
	Sbecore::ubigint insertNewRec(WdbeAMFsmstateStep** rec = NULL, const Sbecore::ubigint fstRefWdbeMFsmstate = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMFsmstateStep& rst, WdbeAMFsmstateStep** rec = NULL, const Sbecore::ubigint fstRefWdbeMFsmstate = 0, const Sbecore::uint fstNum = 0, const Sbecore::ubigint fnxRefWdbeMFsmstate = 0, const std::string Cond1 = "", const std::string Ip1 = "", const std::string Cond2 = "", const std::string Ip2 = "", const std::string Cond3 = "", const std::string Ip3 = "", const std::string Cond4 = "", const std::string Ip4 = "");
	virtual void insertRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	virtual void updateRec(WdbeAMFsmstateStep* rec);
	virtual void updateRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMFsmstateStep** rec);
	virtual Sbecore::ubigint loadRefsByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, ListWdbeAMFsmstateStep& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMFsmstateStep& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMFsmstateStep: C++ wrapper for table TblWdbeAMFsmstateStep (MySQL database)
	*/
class MyTblWdbeAMFsmstateStep : public TblWdbeAMFsmstateStep, public Sbecore::MyTable {

public:
	MyTblWdbeAMFsmstateStep();
	~MyTblWdbeAMFsmstateStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMFsmstateStep& rst);

	Sbecore::ubigint insertRec(WdbeAMFsmstateStep* rec);
	void insertRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	void updateRec(WdbeAMFsmstateStep* rec);
	void updateRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRefsByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, ListWdbeAMFsmstateStep& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMFsmstateStep: C++ wrapper for table TblWdbeAMFsmstateStep (PgSQL database)
	*/
class PgTblWdbeAMFsmstateStep : public TblWdbeAMFsmstateStep, public Sbecore::PgTable {

public:
	PgTblWdbeAMFsmstateStep();
	~PgTblWdbeAMFsmstateStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMFsmstateStep& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMFsmstateStep& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMFsmstateStep& rst);

	Sbecore::ubigint insertRec(WdbeAMFsmstateStep* rec);
	void insertRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	void updateRec(WdbeAMFsmstateStep* rec);
	void updateRst(ListWdbeAMFsmstateStep& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMFsmstateStep** rec);
	Sbecore::ubigint loadRefsByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByFst(Sbecore::ubigint fstRefWdbeMFsmstate, const bool append, ListWdbeAMFsmstateStep& rst);
};
#endif

#endif
