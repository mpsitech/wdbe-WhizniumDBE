/**
	* \file WdbeQUntRef1NCommand.h
	* Dbs and XML wrapper for table TblWdbeQUntRef1NCommand (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQUNTREF1NCOMMAND_H
#define WDBEQUNTREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntRef1NCommand: record of TblWdbeQUntRef1NCommand
	*/
class WdbeQUntRef1NCommand {

public:
	WdbeQUntRef1NCommand(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint refNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQUntRef1NCommand: recordset of TblWdbeQUntRef1NCommand
	*/
class ListWdbeQUntRef1NCommand {

public:
	ListWdbeQUntRef1NCommand();
	ListWdbeQUntRef1NCommand(const ListWdbeQUntRef1NCommand& src);
	~ListWdbeQUntRef1NCommand();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntRef1NCommand* rec);

	ListWdbeQUntRef1NCommand& operator=(const ListWdbeQUntRef1NCommand& src);

public:
	std::vector<WdbeQUntRef1NCommand*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntRef1NCommand: C++ wrapper for table TblWdbeQUntRef1NCommand
	*/
class TblWdbeQUntRef1NCommand {

public:
	TblWdbeQUntRef1NCommand();
	virtual ~TblWdbeQUntRef1NCommand();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NCommand& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntRef1NCommand* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntRef1NCommand& rst, WdbeQUntRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQUntRef1NCommand& rst);
	virtual void updateRec(WdbeQUntRef1NCommand* rec);
	virtual void updateRst(ListWdbeQUntRef1NCommand& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NCommand& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntRef1NCommand: C++ wrapper for table TblWdbeQUntRef1NCommand (MySQL database)
	*/
class MyTblWdbeQUntRef1NCommand : public TblWdbeQUntRef1NCommand, public Sbecore::MyTable {

public:
	MyTblWdbeQUntRef1NCommand();
	~MyTblWdbeQUntRef1NCommand();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NCommand* rec);
	void insertRst(ListWdbeQUntRef1NCommand& rst);
	void updateRec(WdbeQUntRef1NCommand* rec);
	void updateRst(ListWdbeQUntRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NCommand& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntRef1NCommand: C++ wrapper for table TblWdbeQUntRef1NCommand (PgSQL database)
	*/
class PgTblWdbeQUntRef1NCommand : public TblWdbeQUntRef1NCommand, public Sbecore::PgTable {

public:
	PgTblWdbeQUntRef1NCommand();
	~PgTblWdbeQUntRef1NCommand();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntRef1NCommand& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntRef1NCommand& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQUntRef1NCommand* rec);
	void insertRst(ListWdbeQUntRef1NCommand& rst);
	void updateRec(WdbeQUntRef1NCommand* rec);
	void updateRst(ListWdbeQUntRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntRef1NCommand& rst);
};
#endif

#endif

