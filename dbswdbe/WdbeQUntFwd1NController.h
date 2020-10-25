/**
	* \file WdbeQUntFwd1NController.h
	* Dbs and XML wrapper for table TblWdbeQUntFwd1NController (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNTFWD1NCONTROLLER_H
#define WDBEQUNTFWD1NCONTROLLER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUntFwd1NController: record of TblWdbeQUntFwd1NController
	*/
class WdbeQUntFwd1NController {

public:
	WdbeQUntFwd1NController(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUntFwd1NController: recordset of TblWdbeQUntFwd1NController
	*/
class ListWdbeQUntFwd1NController {

public:
	ListWdbeQUntFwd1NController();
	ListWdbeQUntFwd1NController(const ListWdbeQUntFwd1NController& src);
	~ListWdbeQUntFwd1NController();

	void clear();
	unsigned int size() const;
	void append(WdbeQUntFwd1NController* rec);

	ListWdbeQUntFwd1NController& operator=(const ListWdbeQUntFwd1NController& src);

public:
	std::vector<WdbeQUntFwd1NController*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUntFwd1NController: C++ wrapper for table TblWdbeQUntFwd1NController
	*/
class TblWdbeQUntFwd1NController {

public:
	TblWdbeQUntFwd1NController();
	virtual ~TblWdbeQUntFwd1NController();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUntFwd1NController** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntFwd1NController& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUntFwd1NController* rec);
	Sbecore::ubigint insertNewRec(WdbeQUntFwd1NController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUntFwd1NController& rst, WdbeQUntFwd1NController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUntFwd1NController& rst);
	virtual void updateRec(WdbeQUntFwd1NController* rec);
	virtual void updateRst(ListWdbeQUntFwd1NController& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntFwd1NController** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntFwd1NController& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUntFwd1NController: C++ wrapper for table TblWdbeQUntFwd1NController (MySQL database)
	*/
class MyTblWdbeQUntFwd1NController : public TblWdbeQUntFwd1NController, public Sbecore::MyTable {

public:
	MyTblWdbeQUntFwd1NController();
	~MyTblWdbeQUntFwd1NController();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntFwd1NController& rst);

	Sbecore::ubigint insertRec(WdbeQUntFwd1NController* rec);
	void insertRst(ListWdbeQUntFwd1NController& rst);
	void updateRec(WdbeQUntFwd1NController* rec);
	void updateRst(ListWdbeQUntFwd1NController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntFwd1NController& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUntFwd1NController: C++ wrapper for table TblWdbeQUntFwd1NController (PgSQL database)
	*/
class PgTblWdbeQUntFwd1NController : public TblWdbeQUntFwd1NController, public Sbecore::PgTable {

public:
	PgTblWdbeQUntFwd1NController();
	~PgTblWdbeQUntFwd1NController();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUntFwd1NController& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUntFwd1NController& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUntFwd1NController& rst);

	Sbecore::ubigint insertRec(WdbeQUntFwd1NController* rec);
	void insertRst(ListWdbeQUntFwd1NController& rst);
	void updateRec(WdbeQUntFwd1NController* rec);
	void updateRst(ListWdbeQUntFwd1NController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUntFwd1NController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUntFwd1NController& rst);
};
#endif

#endif

