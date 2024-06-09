/**
	* \file WdbeQMod1NCdc.h
	* Dbs and XML wrapper for table TblWdbeQMod1NCdc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQMOD1NCDC_H
#define WDBEQMOD1NCDC_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMod1NCdc: record of TblWdbeQMod1NCdc
	*/
class WdbeQMod1NCdc {

public:
	WdbeQMod1NCdc(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWdbeQMod1NCdc: recordset of TblWdbeQMod1NCdc
	*/
class ListWdbeQMod1NCdc {

public:
	ListWdbeQMod1NCdc();
	ListWdbeQMod1NCdc(const ListWdbeQMod1NCdc& src);
	~ListWdbeQMod1NCdc();

	void clear();
	unsigned int size() const;
	void append(WdbeQMod1NCdc* rec);

	ListWdbeQMod1NCdc& operator=(const ListWdbeQMod1NCdc& src);

public:
	std::vector<WdbeQMod1NCdc*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMod1NCdc: C++ wrapper for table TblWdbeQMod1NCdc
	*/
class TblWdbeQMod1NCdc {

public:
	TblWdbeQMod1NCdc();
	virtual ~TblWdbeQMod1NCdc();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NCdc** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NCdc& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMod1NCdc* rec);
	Sbecore::ubigint insertNewRec(WdbeQMod1NCdc** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMod1NCdc& rst, WdbeQMod1NCdc** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMod1NCdc& rst);
	virtual void updateRec(WdbeQMod1NCdc* rec);
	virtual void updateRst(ListWdbeQMod1NCdc& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NCdc** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NCdc& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMod1NCdc: C++ wrapper for table TblWdbeQMod1NCdc (MySQL database)
	*/
class MyTblWdbeQMod1NCdc : public TblWdbeQMod1NCdc, public Sbecore::MyTable {

public:
	MyTblWdbeQMod1NCdc();
	~MyTblWdbeQMod1NCdc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NCdc& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NCdc* rec);
	void insertRst(ListWdbeQMod1NCdc& rst);
	void updateRec(WdbeQMod1NCdc* rec);
	void updateRst(ListWdbeQMod1NCdc& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NCdc& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMod1NCdc: C++ wrapper for table TblWdbeQMod1NCdc (PgSQL database)
	*/
class PgTblWdbeQMod1NCdc : public TblWdbeQMod1NCdc, public Sbecore::PgTable {

public:
	PgTblWdbeQMod1NCdc();
	~PgTblWdbeQMod1NCdc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMod1NCdc& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMod1NCdc& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMod1NCdc& rst);

	Sbecore::ubigint insertRec(WdbeQMod1NCdc* rec);
	void insertRst(ListWdbeQMod1NCdc& rst);
	void updateRec(WdbeQMod1NCdc* rec);
	void updateRst(ListWdbeQMod1NCdc& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMod1NCdc** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMod1NCdc& rst);
};
#endif

#endif
