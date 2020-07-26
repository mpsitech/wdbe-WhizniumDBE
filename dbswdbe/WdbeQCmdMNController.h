/**
	* \file WdbeQCmdMNController.h
	* Dbs and XML wrapper for table TblWdbeQCmdMNController (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQCMDMNCONTROLLER_H
#define WDBEQCMDMNCONTROLLER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQCmdMNController: record of TblWdbeQCmdMNController
	*/
class WdbeQCmdMNController {

public:
	WdbeQCmdMNController(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");

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
	* ListWdbeQCmdMNController: recordset of TblWdbeQCmdMNController
	*/
class ListWdbeQCmdMNController {

public:
	ListWdbeQCmdMNController();
	ListWdbeQCmdMNController(const ListWdbeQCmdMNController& src);
	~ListWdbeQCmdMNController();

	void clear();
	unsigned int size() const;
	void append(WdbeQCmdMNController* rec);

	ListWdbeQCmdMNController& operator=(const ListWdbeQCmdMNController& src);

public:
	std::vector<WdbeQCmdMNController*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQCmdMNController: C++ wrapper for table TblWdbeQCmdMNController
	*/
class TblWdbeQCmdMNController {

public:
	TblWdbeQCmdMNController();
	virtual ~TblWdbeQCmdMNController();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdMNController** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdMNController& rst);

	virtual Sbecore::ubigint insertRec(WdbeQCmdMNController* rec);
	Sbecore::ubigint insertNewRec(WdbeQCmdMNController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQCmdMNController& rst, WdbeQCmdMNController** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const std::string stubIvrRefWdbeMSignal = "", const Sbecore::ubigint rvrRefWdbeMSignal = 0, const std::string stubRvrRefWdbeMSignal = "");
	virtual void insertRst(ListWdbeQCmdMNController& rst);
	virtual void updateRec(WdbeQCmdMNController* rec);
	virtual void updateRst(ListWdbeQCmdMNController& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdMNController** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdMNController& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQCmdMNController: C++ wrapper for table TblWdbeQCmdMNController (MySQL database)
	*/
class MyTblWdbeQCmdMNController : public TblWdbeQCmdMNController, public Sbecore::MyTable {

public:
	MyTblWdbeQCmdMNController();
	~MyTblWdbeQCmdMNController();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdMNController& rst);

	Sbecore::ubigint insertRec(WdbeQCmdMNController* rec);
	void insertRst(ListWdbeQCmdMNController& rst);
	void updateRec(WdbeQCmdMNController* rec);
	void updateRst(ListWdbeQCmdMNController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdMNController& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQCmdMNController: C++ wrapper for table TblWdbeQCmdMNController (PgSQL database)
	*/
class PgTblWdbeQCmdMNController : public TblWdbeQCmdMNController, public Sbecore::PgTable {

public:
	PgTblWdbeQCmdMNController();
	~PgTblWdbeQCmdMNController();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQCmdMNController& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQCmdMNController& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQCmdMNController& rst);

	Sbecore::ubigint insertRec(WdbeQCmdMNController* rec);
	void insertRst(ListWdbeQCmdMNController& rst);
	void updateRec(WdbeQCmdMNController* rec);
	void updateRst(ListWdbeQCmdMNController& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQCmdMNController** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQCmdMNController& rst);
};
#endif

#endif

