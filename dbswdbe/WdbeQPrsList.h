/**
	* \file WdbeQPrsList.h
	* Dbs and XML wrapper for table TblWdbeQPrsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPRSLIST_H
#define WDBEQPRSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQPrsList: record of TblWdbeQPrsList
	*/
class WdbeQPrsList {

public:
	WdbeQPrsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	Sbecore::uint ixVSex;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQPrsList: recordset of TblWdbeQPrsList
	*/
class ListWdbeQPrsList {

public:
	ListWdbeQPrsList();
	ListWdbeQPrsList(const ListWdbeQPrsList& src);
	~ListWdbeQPrsList();

	void clear();
	unsigned int size() const;
	void append(WdbeQPrsList* rec);

	ListWdbeQPrsList& operator=(const ListWdbeQPrsList& src);

public:
	std::vector<WdbeQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQPrsList: C++ wrapper for table TblWdbeQPrsList
	*/
class TblWdbeQPrsList {

public:
	TblWdbeQPrsList();
	virtual ~TblWdbeQPrsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsList& rst);

	virtual Sbecore::ubigint insertRec(WdbeQPrsList* rec);
	Sbecore::ubigint insertNewRec(WdbeQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQPrsList& rst, WdbeQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	virtual void insertRst(ListWdbeQPrsList& rst);
	virtual void updateRec(WdbeQPrsList* rec);
	virtual void updateRst(ListWdbeQPrsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQPrsList: C++ wrapper for table TblWdbeQPrsList (MySQL database)
	*/
class MyTblWdbeQPrsList : public TblWdbeQPrsList, public Sbecore::MyTable {

public:
	MyTblWdbeQPrsList();
	~MyTblWdbeQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsList& rst);

	Sbecore::ubigint insertRec(WdbeQPrsList* rec);
	void insertRst(ListWdbeQPrsList& rst);
	void updateRec(WdbeQPrsList* rec);
	void updateRst(ListWdbeQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQPrsList: C++ wrapper for table TblWdbeQPrsList (PgSQL database)
	*/
class PgTblWdbeQPrsList : public TblWdbeQPrsList, public Sbecore::PgTable {

public:
	PgTblWdbeQPrsList();
	~PgTblWdbeQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQPrsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQPrsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQPrsList& rst);

	Sbecore::ubigint insertRec(WdbeQPrsList* rec);
	void insertRst(ListWdbeQPrsList& rst);
	void updateRec(WdbeQPrsList* rec);
	void updateRst(ListWdbeQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQPrsList& rst);
};
#endif

#endif

