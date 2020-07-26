/**
	* \file WdbeQUnt1NBank.h
	* Dbs and XML wrapper for table TblWdbeQUnt1NBank (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQUNT1NBANK_H
#define WDBEQUNT1NBANK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQUnt1NBank: record of TblWdbeQUnt1NBank
	*/
class WdbeQUnt1NBank {

public:
	WdbeQUnt1NBank(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQUnt1NBank: recordset of TblWdbeQUnt1NBank
	*/
class ListWdbeQUnt1NBank {

public:
	ListWdbeQUnt1NBank();
	ListWdbeQUnt1NBank(const ListWdbeQUnt1NBank& src);
	~ListWdbeQUnt1NBank();

	void clear();
	unsigned int size() const;
	void append(WdbeQUnt1NBank* rec);

	ListWdbeQUnt1NBank& operator=(const ListWdbeQUnt1NBank& src);

public:
	std::vector<WdbeQUnt1NBank*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQUnt1NBank: C++ wrapper for table TblWdbeQUnt1NBank
	*/
class TblWdbeQUnt1NBank {

public:
	TblWdbeQUnt1NBank();
	virtual ~TblWdbeQUnt1NBank();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NBank** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NBank& rst);

	virtual Sbecore::ubigint insertRec(WdbeQUnt1NBank* rec);
	Sbecore::ubigint insertNewRec(WdbeQUnt1NBank** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQUnt1NBank& rst, WdbeQUnt1NBank** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQUnt1NBank& rst);
	virtual void updateRec(WdbeQUnt1NBank* rec);
	virtual void updateRst(ListWdbeQUnt1NBank& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NBank** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NBank& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQUnt1NBank: C++ wrapper for table TblWdbeQUnt1NBank (MySQL database)
	*/
class MyTblWdbeQUnt1NBank : public TblWdbeQUnt1NBank, public Sbecore::MyTable {

public:
	MyTblWdbeQUnt1NBank();
	~MyTblWdbeQUnt1NBank();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NBank& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NBank* rec);
	void insertRst(ListWdbeQUnt1NBank& rst);
	void updateRec(WdbeQUnt1NBank* rec);
	void updateRst(ListWdbeQUnt1NBank& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NBank& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQUnt1NBank: C++ wrapper for table TblWdbeQUnt1NBank (PgSQL database)
	*/
class PgTblWdbeQUnt1NBank : public TblWdbeQUnt1NBank, public Sbecore::PgTable {

public:
	PgTblWdbeQUnt1NBank();
	~PgTblWdbeQUnt1NBank();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQUnt1NBank& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQUnt1NBank& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQUnt1NBank& rst);

	Sbecore::ubigint insertRec(WdbeQUnt1NBank* rec);
	void insertRst(ListWdbeQUnt1NBank& rst);
	void updateRec(WdbeQUnt1NBank* rec);
	void updateRst(ListWdbeQUnt1NBank& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQUnt1NBank** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQUnt1NBank& rst);
};
#endif

#endif

