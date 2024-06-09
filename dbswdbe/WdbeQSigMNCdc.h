/**
	* \file WdbeQSigMNCdc.h
	* Dbs and XML wrapper for table TblWdbeQSigMNCdc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQSIGMNCDC_H
#define WDBEQSIGMNCDC_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQSigMNCdc: record of TblWdbeQSigMNCdc
	*/
class WdbeQSigMNCdc {

public:
	WdbeQSigMNCdc(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixVDir;
	std::string srefIxVDir;
	std::string titIxVDir;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQSigMNCdc: recordset of TblWdbeQSigMNCdc
	*/
class ListWdbeQSigMNCdc {

public:
	ListWdbeQSigMNCdc();
	ListWdbeQSigMNCdc(const ListWdbeQSigMNCdc& src);
	~ListWdbeQSigMNCdc();

	void clear();
	unsigned int size() const;
	void append(WdbeQSigMNCdc* rec);

	ListWdbeQSigMNCdc& operator=(const ListWdbeQSigMNCdc& src);

public:
	std::vector<WdbeQSigMNCdc*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQSigMNCdc: C++ wrapper for table TblWdbeQSigMNCdc
	*/
class TblWdbeQSigMNCdc {

public:
	TblWdbeQSigMNCdc();
	virtual ~TblWdbeQSigMNCdc();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQSigMNCdc** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigMNCdc& rst);

	virtual Sbecore::ubigint insertRec(WdbeQSigMNCdc* rec);
	Sbecore::ubigint insertNewRec(WdbeQSigMNCdc** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQSigMNCdc& rst, WdbeQSigMNCdc** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVDir = 0, const std::string srefIxVDir = "", const std::string titIxVDir = "");
	virtual void insertRst(ListWdbeQSigMNCdc& rst);
	virtual void updateRec(WdbeQSigMNCdc* rec);
	virtual void updateRst(ListWdbeQSigMNCdc& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigMNCdc** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigMNCdc& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQSigMNCdc: C++ wrapper for table TblWdbeQSigMNCdc (MySQL database)
	*/
class MyTblWdbeQSigMNCdc : public TblWdbeQSigMNCdc, public Sbecore::MyTable {

public:
	MyTblWdbeQSigMNCdc();
	~MyTblWdbeQSigMNCdc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigMNCdc& rst);

	Sbecore::ubigint insertRec(WdbeQSigMNCdc* rec);
	void insertRst(ListWdbeQSigMNCdc& rst);
	void updateRec(WdbeQSigMNCdc* rec);
	void updateRst(ListWdbeQSigMNCdc& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigMNCdc& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQSigMNCdc: C++ wrapper for table TblWdbeQSigMNCdc (PgSQL database)
	*/
class PgTblWdbeQSigMNCdc : public TblWdbeQSigMNCdc, public Sbecore::PgTable {

public:
	PgTblWdbeQSigMNCdc();
	~PgTblWdbeQSigMNCdc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQSigMNCdc& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQSigMNCdc& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQSigMNCdc& rst);

	Sbecore::ubigint insertRec(WdbeQSigMNCdc* rec);
	void insertRst(ListWdbeQSigMNCdc& rst);
	void updateRec(WdbeQSigMNCdc* rec);
	void updateRst(ListWdbeQSigMNCdc& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQSigMNCdc** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQSigMNCdc& rst);
};
#endif

#endif
