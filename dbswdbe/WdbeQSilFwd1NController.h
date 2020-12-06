/**
	* \file WdbeQSilFwd1NController.h
	* Dbs and XML wrapper for table TblWdbeQSilFwd1NController (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILFWD1NCONTROLLER_H
#define WDBEQSILFWD1NCONTROLLER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSilFwd1NController: record of TblWdbeQSilFwd1NController
	*/
class WdbeQSilFwd1NController {

public:
	WdbeQSilFwd1NController(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSilFwd1NController: recordset of TblWdbeQSilFwd1NController
	*/
class ListWdbeQSilFwd1NController {

public:
	ListWdbeQSilFwd1NController();
	ListWdbeQSilFwd1NController(const ListWdbeQSilFwd1NController& src);
	~ListWdbeQSilFwd1NController();

	void clear();
	unsigned int size() const;
	void append(WdbeQSilFwd1NController* rec);

	ListWdbeQSilFwd1NController& operator=(const ListWdbeQSilFwd1NController& src);

public:
	std::vector<WdbeQSilFwd1NController*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSilFwd1NController: C++ wrapper for table TblWdbeQSilFwd1NController
	*/
class TblWdbeQSilFwd1NController {

public:
	TblWdbeQSilFwd1NController();
	virtual ~TblWdbeQSilFwd1NController();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSilFwd1NController** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilFwd1NController& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSilFwd1NController* rec);
	Sbecore::ubigint insertNewRec(WdbeQSilFwd1NController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSilFwd1NController& rst, WdbeQSilFwd1NController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSilFwd1NController& rst);
	virtual void updateRec(WdbeQSilFwd1NController* rec);
	virtual void updateRst(ListWdbeQSilFwd1NController& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilFwd1NController** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilFwd1NController& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSilFwd1NController: C++ wrapper for table TblWdbeQSilFwd1NController (MySQL database)
	*/
class MyTblWdbeQSilFwd1NController : public TblWdbeQSilFwd1NController, public Sbecore::MyTable {

public:
	MyTblWdbeQSilFwd1NController();
	~MyTblWdbeQSilFwd1NController();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilFwd1NController& rst);

	Sbecore::ubigint insertRec(WdbeQSilFwd1NController* rec);
	void insertRst(ListWdbeQSilFwd1NController& rst);
	void updateRec(WdbeQSilFwd1NController* rec);
	void updateRst(ListWdbeQSilFwd1NController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilFwd1NController& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSilFwd1NController: C++ wrapper for table TblWdbeQSilFwd1NController (PgSQL database)
	*/
class PgTblWdbeQSilFwd1NController : public TblWdbeQSilFwd1NController, public Sbecore::PgTable {

public:
	PgTblWdbeQSilFwd1NController();
	~PgTblWdbeQSilFwd1NController();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSilFwd1NController& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSilFwd1NController& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSilFwd1NController& rst);

	Sbecore::ubigint insertRec(WdbeQSilFwd1NController* rec);
	void insertRst(ListWdbeQSilFwd1NController& rst);
	void updateRec(WdbeQSilFwd1NController* rec);
	void updateRst(ListWdbeQSilFwd1NController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSilFwd1NController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSilFwd1NController& rst);
};
#endif

#endif
