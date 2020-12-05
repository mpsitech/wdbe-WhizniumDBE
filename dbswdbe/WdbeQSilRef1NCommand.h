/**
	* \file WdbeQSilRef1NCommand.h
	* Dbs and XML wrapper for table TblWdbeQSilRef1NCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILREF1NCOMMAND_H
#define WDBEQSILREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilRef1NCommand: record of TblWdbeQSilRef1NCommand
	*/
class WdbeQSilRef1NCommand {

public:
	WdbeQSilRef1NCommand(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);

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
	* ListWdbeQSilRef1NCommand: recordset of TblWdbeQSilRef1NCommand
	*/
class ListWdbeQSilRef1NCommand {

public:
	ListWdbeQSilRef1NCommand();
	ListWdbeQSilRef1NCommand(const ListWdbeQSilRef1NCommand& src);
	~ListWdbeQSilRef1NCommand();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilRef1NCommand* rec);

	ListWdbeQSilRef1NCommand& operator=(const ListWdbeQSilRef1NCommand& src);

public:
	std::vector<WdbeQSilRef1NCommand*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilRef1NCommand: C++ wrapper for table TblWdbeQSilRef1NCommand
	*/
class TblWdbeQSilRef1NCommand {

public:
	TblWdbeQSilRef1NCommand();
	virtual ~TblWdbeQSilRef1NCommand();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NCommand& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilRef1NCommand* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilRef1NCommand& rst, WdbeQSilRef1NCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint refNum = 0);
	virtual void insertRst(ListWdbeQSilRef1NCommand& rst);
	virtual void updateRec(WdbeQSilRef1NCommand* rec);
	virtual void updateRst(ListWdbeQSilRef1NCommand& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NCommand** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NCommand& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilRef1NCommand: C++ wrapper for table TblWdbeQSilRef1NCommand (MySQL database)
	*/
class MyTblWdbeQSilRef1NCommand : public TblWdbeQSilRef1NCommand, public Sbecore::MyTable {

public:
	MyTblWdbeQSilRef1NCommand();
	~MyTblWdbeQSilRef1NCommand();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NCommand* rec);
	void insertRst(ListWdbeQSilRef1NCommand& rst);
	void updateRec(WdbeQSilRef1NCommand* rec);
	void updateRst(ListWdbeQSilRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NCommand& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilRef1NCommand: C++ wrapper for table TblWdbeQSilRef1NCommand (PgSQL database)
	*/
class PgTblWdbeQSilRef1NCommand : public TblWdbeQSilRef1NCommand, public Sbecore::PgTable {

public:
	PgTblWdbeQSilRef1NCommand();
	~PgTblWdbeQSilRef1NCommand();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilRef1NCommand& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilRef1NCommand& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilRef1NCommand& rst);

	Sbecore::ubigint insertRec(WdbeQSilRef1NCommand* rec);
	void insertRst(ListWdbeQSilRef1NCommand& rst);
	void updateRec(WdbeQSilRef1NCommand* rec);
	void updateRst(ListWdbeQSilRef1NCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilRef1NCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilRef1NCommand& rst);
};
#endif

#endif

