/**
	* \file WdbeAMCommandRetpar.h
	* database access for table TblWdbeAMCommandRetpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEAMCOMMANDRETPAR_H
#define WDBEAMCOMMANDRETPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMCommandRetpar: record of TblWdbeAMCommandRetpar
	*/
class WdbeAMCommandRetpar {

public:
	WdbeAMCommandRetpar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint cmdRefWdbeMCommand;
	Sbecore::uint cmdNum;
	std::string sref;
	Sbecore::uint ixWdbeVPartype;
	Sbecore::ubigint refWdbeMVector;
	Sbecore::utinyint Length;
	std::string Comment;

public:
	bool operator==(const WdbeAMCommandRetpar& comp);
	bool operator!=(const WdbeAMCommandRetpar& comp);
};

/**
	* ListWdbeAMCommandRetpar: recordset of TblWdbeAMCommandRetpar
	*/
class ListWdbeAMCommandRetpar {

public:
	ListWdbeAMCommandRetpar();
	ListWdbeAMCommandRetpar(const ListWdbeAMCommandRetpar& src);
	~ListWdbeAMCommandRetpar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMCommandRetpar* rec);

	WdbeAMCommandRetpar* operator[](const Sbecore::uint ix);
	ListWdbeAMCommandRetpar& operator=(const ListWdbeAMCommandRetpar& src);
	bool operator==(const ListWdbeAMCommandRetpar& comp);
	bool operator!=(const ListWdbeAMCommandRetpar& comp);

public:
	std::vector<WdbeAMCommandRetpar*> nodes;
};

/**
	* TblWdbeAMCommandRetpar: C++ wrapper for table TblWdbeAMCommandRetpar
	*/
class TblWdbeAMCommandRetpar {

public:

public:
	TblWdbeAMCommandRetpar();
	virtual ~TblWdbeAMCommandRetpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandRetpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandRetpar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMCommandRetpar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMCommandRetpar** rec = NULL, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMCommandRetpar& rst, WdbeAMCommandRetpar** rec = NULL, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	virtual void updateRec(WdbeAMCommandRetpar* rec);
	virtual void updateRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandRetpar** rec);
	virtual Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandRetpar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMCommandRetpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMCommandRetpar: C++ wrapper for table TblWdbeAMCommandRetpar (MySQL database)
	*/
class MyTblWdbeAMCommandRetpar : public TblWdbeAMCommandRetpar, public Sbecore::MyTable {

public:
	MyTblWdbeAMCommandRetpar();
	~MyTblWdbeAMCommandRetpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandRetpar& rst);

	Sbecore::ubigint insertRec(WdbeAMCommandRetpar* rec);
	void insertRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	void updateRec(WdbeAMCommandRetpar* rec);
	void updateRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandRetpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMCommandRetpar: C++ wrapper for table TblWdbeAMCommandRetpar (PgSQL database)
	*/
class PgTblWdbeAMCommandRetpar : public TblWdbeAMCommandRetpar, public Sbecore::PgTable {

public:
	PgTblWdbeAMCommandRetpar();
	~PgTblWdbeAMCommandRetpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMCommandRetpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMCommandRetpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandRetpar& rst);

	Sbecore::ubigint insertRec(WdbeAMCommandRetpar* rec);
	void insertRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	void updateRec(WdbeAMCommandRetpar* rec);
	void updateRst(ListWdbeAMCommandRetpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandRetpar** rec);
	Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandRetpar& rst);
};
#endif

#endif

