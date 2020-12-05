/**
	* \file WdbeAVControlPar.h
	* database access for table TblWdbeAVControlPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAVCONTROLPAR_H
#define WDBEAVCONTROLPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAVControlPar: record of TblWdbeAVControlPar
	*/
class WdbeAVControlPar {

public:
	WdbeAVControlPar(const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVControl = 0, const Sbecore::ubigint x1RefWdbeMUser = 0, const Sbecore::uint x2IxWdbeVLocale = 0, const std::string Par = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixWdbeVControl;
	Sbecore::ubigint x1RefWdbeMUser;
	Sbecore::uint x2IxWdbeVLocale;
	std::string Par;
	std::string Val;

public:
	bool operator==(const WdbeAVControlPar& comp);
	bool operator!=(const WdbeAVControlPar& comp);
};

/**
	* ListWdbeAVControlPar: recordset of TblWdbeAVControlPar
	*/
class ListWdbeAVControlPar {

public:
	ListWdbeAVControlPar();
	ListWdbeAVControlPar(const ListWdbeAVControlPar& src);
	~ListWdbeAVControlPar();

	void clear();
	unsigned int size() const;
	void append(WdbeAVControlPar* rec);

	WdbeAVControlPar* operator[](const Sbecore::uint ix);
	ListWdbeAVControlPar& operator=(const ListWdbeAVControlPar& src);
	bool operator==(const ListWdbeAVControlPar& comp);
	bool operator!=(const ListWdbeAVControlPar& comp);

public:
	std::vector<WdbeAVControlPar*> nodes;
};

/**
	* TblWdbeAVControlPar: C++ wrapper for table TblWdbeAVControlPar
	*/
class TblWdbeAVControlPar {

public:

public:
	TblWdbeAVControlPar();
	virtual ~TblWdbeAVControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAVControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVControlPar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAVControlPar* rec);
	Sbecore::ubigint insertNewRec(WdbeAVControlPar** rec = NULL, const Sbecore::uint ixWdbeVControl = 0, const Sbecore::ubigint x1RefWdbeMUser = 0, const Sbecore::uint x2IxWdbeVLocale = 0, const std::string Par = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAVControlPar& rst, WdbeAVControlPar** rec = NULL, const Sbecore::uint ixWdbeVControl = 0, const Sbecore::ubigint x1RefWdbeMUser = 0, const Sbecore::uint x2IxWdbeVLocale = 0, const std::string Par = "", const std::string Val = "");
	virtual void insertRst(ListWdbeAVControlPar& rst, bool transact = false);
	virtual void updateRec(WdbeAVControlPar* rec);
	virtual void updateRst(ListWdbeAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, Sbecore::ubigint& ref);
	virtual bool loadValByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAVControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAVControlPar: C++ wrapper for table TblWdbeAVControlPar (MySQL database)
	*/
class MyTblWdbeAVControlPar : public TblWdbeAVControlPar, public Sbecore::MyTable {

public:
	MyTblWdbeAVControlPar();
	~MyTblWdbeAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVControlPar& rst);

	Sbecore::ubigint insertRec(WdbeAVControlPar* rec);
	void insertRst(ListWdbeAVControlPar& rst, bool transact = false);
	void updateRec(WdbeAVControlPar* rec);
	void updateRst(ListWdbeAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAVControlPar: C++ wrapper for table TblWdbeAVControlPar (PgSQL database)
	*/
class PgTblWdbeAVControlPar : public TblWdbeAVControlPar, public Sbecore::PgTable {

public:
	PgTblWdbeAVControlPar();
	~PgTblWdbeAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAVControlPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAVControlPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAVControlPar& rst);

	Sbecore::ubigint insertRec(WdbeAVControlPar* rec);
	void insertRst(ListWdbeAVControlPar& rst, bool transact = false);
	void updateRec(WdbeAVControlPar* rec);
	void updateRst(ListWdbeAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWdbeVControl, Sbecore::ubigint x1RefWdbeMUser, std::string Par, std::string& Val);
};
#endif

#endif

