/**
	* \file WdbeQModCtrMNCommand.h
	* Dbs and XML wrapper for table TblWdbeQModCtrMNCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRMNCOMMAND_H
#define WDBEQMODCTRMNCOMMAND_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQModCtrMNCommand: record of TblWdbeQModCtrMNCommand
	*/
class WdbeQModCtrMNCommand {

public:
	WdbeQModCtrMNCommand(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::ubigint ivrRefWdbeMSignal;
	std::string stubIvrRefWdbeMSignal;
	Sbecore::ubigint rvrRefWdbeMSignal;
	std::string stubRvrRefWdbeMSignal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQModCtrMNCommand: recordset of TblWdbeQModCtrMNCommand
	*/
class ListWdbeQModCtrMNCommand {

public:
	ListWdbeQModCtrMNCommand();
	ListWdbeQModCtrMNCommand(const ListWdbeQModCtrMNCommand& src);
	~ListWdbeQModCtrMNCommand();

	void clear();
	unsigned int size() const;
	void append(WdbeQModCtrMNCommand* rec);

	ListWdbeQModCtrMNCommand& operator=(const ListWdbeQModCtrMNCommand& src);

public:
	std::vector<WdbeQModCtrMNCommand*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQModCtrMNCommand: C++ wrapper for table TblWdbeQModCtrMNCommand
	*/
class TblWdbeQModCtrMNCommand {

public:
	TblWdbeQModCtrMNCommand();
	virtual ~TblWdbeQModCtrMNCommand();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrMNCommand** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrMNCommand& rst);

	virtual Sbecore::ubigint insertRec(WdbeQModCtrMNCommand* rec);
	Sbecore::ubigint insertNewRec(WdbeQModCtrMNCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQModCtrMNCommand& rst, WdbeQModCtrMNCommand** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");
	virtual void insertRst(ListWdbeQModCtrMNCommand& rst);
	virtual void updateRec(WdbeQModCtrMNCommand* rec);
	virtual void updateRst(ListWdbeQModCtrMNCommand& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrMNCommand** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrMNCommand& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQModCtrMNCommand: C++ wrapper for table TblWdbeQModCtrMNCommand (MySQL database)
	*/
class MyTblWdbeQModCtrMNCommand : public TblWdbeQModCtrMNCommand, public Sbecore::MyTable {

public:
	MyTblWdbeQModCtrMNCommand();
	~MyTblWdbeQModCtrMNCommand();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrMNCommand& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrMNCommand* rec);
	void insertRst(ListWdbeQModCtrMNCommand& rst);
	void updateRec(WdbeQModCtrMNCommand* rec);
	void updateRst(ListWdbeQModCtrMNCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrMNCommand& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQModCtrMNCommand: C++ wrapper for table TblWdbeQModCtrMNCommand (PgSQL database)
	*/
class PgTblWdbeQModCtrMNCommand : public TblWdbeQModCtrMNCommand, public Sbecore::PgTable {

public:
	PgTblWdbeQModCtrMNCommand();
	~PgTblWdbeQModCtrMNCommand();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQModCtrMNCommand& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQModCtrMNCommand& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQModCtrMNCommand& rst);

	Sbecore::ubigint insertRec(WdbeQModCtrMNCommand* rec);
	void insertRst(ListWdbeQModCtrMNCommand& rst);
	void updateRec(WdbeQModCtrMNCommand* rec);
	void updateRst(ListWdbeQModCtrMNCommand& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQModCtrMNCommand** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQModCtrMNCommand& rst);
};
#endif

#endif
