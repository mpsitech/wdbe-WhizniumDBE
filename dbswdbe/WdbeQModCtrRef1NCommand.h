/**
	* \file WdbeQModCtrRef1NCommand.h
	* Dbs and XML wrapper for table TblWdbeQModCtrRef1NCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRREF1NCOMMAND_H
#define WDBEQMODCTRREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCtrRef1NCommand: record of TblWdbeQModCtrRef1NCommand
	*/
class WdbeQModCtrRef1NCommand {

public:
	WdbeQModCtrRef1NCommand(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQModCtrRef1NCommand: recordset of TblWdbeQModCtrRef1NCommand
	*/
class ListWdbeQModCtrRef1NCommand {

public:
	ListWdbeQModCtrRef1NCommand();
	ListWdbeQModCtrRef1NCommand(const ListWdbeQModCtrRef1NCommand& src);
	~ListWdbeQModCtrRef1NCommand();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCtrRef1NCommand* rec);

	ListWdbeQModCtrRef1NCommand& operator=(const ListWdbeQModCtrRef1NCommand& src);

public:
	std::vector<WdbeQModCtrRef1NCommand*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCtrRef1NCommand: C++ wrapper for table TblWdbeQModCtrRef1NCommand
	*/
class TblWdbeQModCtrRef1NCommand {

public:
	TblWdbeQModCtrRef1NCommand();
	virtual ~TblWdbeQModCtrRef1NCommand();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NCommand& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCtrRef1NCommand* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCtrRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCtrRef1NCommand& rst, WdbeQModCtrRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQModCtrRef1NCommand& rst);
	virtual void updateRec(WdbeQModCtrRef1NCommand* rec);
	virtual void updateRst(ListWdbeQModCtrRef1NCommand& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NCommand& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCtrRef1NCommand: C++ wrapper for table TblWdbeQModCtrRef1NCommand (MySQL database)
	*/
class MyTblWdbeQModCtrRef1NCommand : public TblWdbeQModCtrRef1NCommand, public Sbecore::MyTable {

public:
	MyTblWdbeQModCtrRef1NCommand();
	~MyTblWdbeQModCtrRef1NCommand();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrRef1NCommand* rec);
	void insertRst(ListWdbeQModCtrRef1NCommand& rst);
	void updateRec(WdbeQModCtrRef1NCommand* rec);
	void updateRst(ListWdbeQModCtrRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NCommand& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCtrRef1NCommand: C++ wrapper for table TblWdbeQModCtrRef1NCommand (PgSQL database)
	*/
class PgTblWdbeQModCtrRef1NCommand : public TblWdbeQModCtrRef1NCommand, public Sbecore::PgTable {

public:
	PgTblWdbeQModCtrRef1NCommand();
	~PgTblWdbeQModCtrRef1NCommand();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCtrRef1NCommand& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCtrRef1NCommand& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrRef1NCommand* rec);
	void insertRst(ListWdbeQModCtrRef1NCommand& rst);
	void updateRec(WdbeQModCtrRef1NCommand* rec);
	void updateRst(ListWdbeQModCtrRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrRef1NCommand& rst);
};
#endif

#endif
