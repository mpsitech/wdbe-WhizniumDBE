/**
	* \file WdbeAMCommandInvpar.h
	* database access for table TblWdbeAMCommandInvpar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEAMCOMMANDINVPAR_H
#define WDBEAMCOMMANDINVPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeAMCommandInvpar: record of TblWdbeAMCommandInvpar
	*/
class WdbeAMCommandInvpar {

public:
	WdbeAMCommandInvpar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint cmdRefWdbeMCommand;
	Sbecore::uint cmdNum;
	std::string sref;
	Sbecore::uint ixWdbeVPartype;
	Sbecore::ubigint refWdbeMVector;
	Sbecore::utinyint Length;
	std::string Defval;
	Sbecore::ubigint refWdbeMVectoritem;
	std::string Comment;

public:
	bool operator==(const WdbeAMCommandInvpar& comp);
	bool operator!=(const WdbeAMCommandInvpar& comp);
};

/**
	* ListWdbeAMCommandInvpar: recordset of TblWdbeAMCommandInvpar
	*/
class ListWdbeAMCommandInvpar {

public:
	ListWdbeAMCommandInvpar();
	ListWdbeAMCommandInvpar(const ListWdbeAMCommandInvpar& src);
	~ListWdbeAMCommandInvpar();

	void clear();
	unsigned int size() const;
	void append(WdbeAMCommandInvpar* rec);

	WdbeAMCommandInvpar* operator[](const Sbecore::uint ix);
	ListWdbeAMCommandInvpar& operator=(const ListWdbeAMCommandInvpar& src);
	bool operator==(const ListWdbeAMCommandInvpar& comp);
	bool operator!=(const ListWdbeAMCommandInvpar& comp);

public:
	std::vector<WdbeAMCommandInvpar*> nodes;
};

/**
	* TblWdbeAMCommandInvpar: C++ wrapper for table TblWdbeAMCommandInvpar
	*/
class TblWdbeAMCommandInvpar {

public:

public:
	TblWdbeAMCommandInvpar();
	virtual ~TblWdbeAMCommandInvpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandInvpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandInvpar& rst);

	virtual Sbecore::ubigint insertRec(WdbeAMCommandInvpar* rec);
	Sbecore::ubigint insertNewRec(WdbeAMCommandInvpar** rec = NULL, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeAMCommandInvpar& rst, WdbeAMCommandInvpar** rec = NULL, const Sbecore::ubigint cmdRefWdbeMCommand = 0, const Sbecore::uint cmdNum = 0, const std::string sref = "", const Sbecore::uint ixWdbeVPartype = 0, const Sbecore::ubigint refWdbeMVector = 0, const Sbecore::utinyint Length = 0, const std::string Defval = "", const Sbecore::ubigint refWdbeMVectoritem = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	virtual void updateRec(WdbeAMCommandInvpar* rec);
	virtual void updateRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandInvpar** rec);
	virtual Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandInvpar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeAMCommandInvpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeAMCommandInvpar: C++ wrapper for table TblWdbeAMCommandInvpar (MySQL database)
	*/
class MyTblWdbeAMCommandInvpar : public TblWdbeAMCommandInvpar, public Sbecore::MyTable {

public:
	MyTblWdbeAMCommandInvpar();
	~MyTblWdbeAMCommandInvpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandInvpar& rst);

	Sbecore::ubigint insertRec(WdbeAMCommandInvpar* rec);
	void insertRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	void updateRec(WdbeAMCommandInvpar* rec);
	void updateRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandInvpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeAMCommandInvpar: C++ wrapper for table TblWdbeAMCommandInvpar (PgSQL database)
	*/
class PgTblWdbeAMCommandInvpar : public TblWdbeAMCommandInvpar, public Sbecore::PgTable {

public:
	PgTblWdbeAMCommandInvpar();
	~PgTblWdbeAMCommandInvpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeAMCommandInvpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeAMCommandInvpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeAMCommandInvpar& rst);

	Sbecore::ubigint insertRec(WdbeAMCommandInvpar* rec);
	void insertRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	void updateRec(WdbeAMCommandInvpar* rec);
	void updateRst(ListWdbeAMCommandInvpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeAMCommandInvpar** rec);
	Sbecore::ubigint loadRefsByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmd(Sbecore::ubigint cmdRefWdbeMCommand, const bool append, ListWdbeAMCommandInvpar& rst);
};
#endif

#endif

