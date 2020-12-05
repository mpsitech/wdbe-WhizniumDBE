/**
	* \file WdbeQSil1NBank.h
	* Dbs and XML wrapper for table TblWdbeQSil1NBank (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NBANK_H
#define WDBEQSIL1NBANK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSil1NBank: record of TblWdbeQSil1NBank
	*/
class WdbeQSil1NBank {

public:
	WdbeQSil1NBank(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQSil1NBank: recordset of TblWdbeQSil1NBank
	*/
class ListWdbeQSil1NBank {

public:
	ListWdbeQSil1NBank();
	ListWdbeQSil1NBank(const ListWdbeQSil1NBank& src);
	~ListWdbeQSil1NBank();

	void clear();
	unsigned int size() const;
	void append(WdbeQSil1NBank* rec);

	ListWdbeQSil1NBank& operator=(const ListWdbeQSil1NBank& src);

public:
	std::vector<WdbeQSil1NBank*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSil1NBank: C++ wrapper for table TblWdbeQSil1NBank
	*/
class TblWdbeQSil1NBank {

public:
	TblWdbeQSil1NBank();
	virtual ~TblWdbeQSil1NBank();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NBank** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NBank& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSil1NBank* rec);
	Sbecore::ubigint insertNewRec(WdbeQSil1NBank** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSil1NBank& rst, WdbeQSil1NBank** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQSil1NBank& rst);
	virtual void updateRec(WdbeQSil1NBank* rec);
	virtual void updateRst(ListWdbeQSil1NBank& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NBank** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NBank& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSil1NBank: C++ wrapper for table TblWdbeQSil1NBank (MySQL database)
	*/
class MyTblWdbeQSil1NBank : public TblWdbeQSil1NBank, public Sbecore::MyTable {

public:
	MyTblWdbeQSil1NBank();
	~MyTblWdbeQSil1NBank();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NBank& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NBank* rec);
	void insertRst(ListWdbeQSil1NBank& rst);
	void updateRec(WdbeQSil1NBank* rec);
	void updateRst(ListWdbeQSil1NBank& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NBank& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSil1NBank: C++ wrapper for table TblWdbeQSil1NBank (PgSQL database)
	*/
class PgTblWdbeQSil1NBank : public TblWdbeQSil1NBank, public Sbecore::PgTable {

public:
	PgTblWdbeQSil1NBank();
	~PgTblWdbeQSil1NBank();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSil1NBank& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSil1NBank& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSil1NBank& rst);

	Sbecore::ubigint insertRec(WdbeQSil1NBank* rec);
	void insertRst(ListWdbeQSil1NBank& rst);
	void updateRec(WdbeQSil1NBank* rec);
	void updateRst(ListWdbeQSil1NBank& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSil1NBank** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSil1NBank& rst);
};
#endif

#endif

