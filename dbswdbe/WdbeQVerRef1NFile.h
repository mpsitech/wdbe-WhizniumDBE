/**
	* \file WdbeQVerRef1NFile.h
	* Dbs and XML wrapper for table TblWdbeQVerRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVERREF1NFILE_H
#define WDBEQVERREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQVerRef1NFile: record of TblWdbeQVerRef1NFile
	*/
class WdbeQVerRef1NFile {

public:
	WdbeQVerRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQVerRef1NFile: recordset of TblWdbeQVerRef1NFile
	*/
class ListWdbeQVerRef1NFile {

public:
	ListWdbeQVerRef1NFile();
	ListWdbeQVerRef1NFile(const ListWdbeQVerRef1NFile& src);
	~ListWdbeQVerRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WdbeQVerRef1NFile* rec);

	ListWdbeQVerRef1NFile& operator=(const ListWdbeQVerRef1NFile& src);

public:
	std::vector<WdbeQVerRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQVerRef1NFile: C++ wrapper for table TblWdbeQVerRef1NFile
	*/
class TblWdbeQVerRef1NFile {

public:
	TblWdbeQVerRef1NFile();
	virtual ~TblWdbeQVerRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQVerRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WdbeQVerRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WdbeQVerRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQVerRef1NFile& rst, WdbeQVerRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQVerRef1NFile& rst);
	virtual void updateRec(WdbeQVerRef1NFile* rec);
	virtual void updateRst(ListWdbeQVerRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQVerRef1NFile: C++ wrapper for table TblWdbeQVerRef1NFile (MySQL database)
	*/
class MyTblWdbeQVerRef1NFile : public TblWdbeQVerRef1NFile, public Sbecore::MyTable {

public:
	MyTblWdbeQVerRef1NFile();
	~MyTblWdbeQVerRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerRef1NFile& rst);

	Sbecore::ubigint insertRec(WdbeQVerRef1NFile* rec);
	void insertRst(ListWdbeQVerRef1NFile& rst);
	void updateRec(WdbeQVerRef1NFile* rec);
	void updateRst(ListWdbeQVerRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQVerRef1NFile: C++ wrapper for table TblWdbeQVerRef1NFile (PgSQL database)
	*/
class PgTblWdbeQVerRef1NFile : public TblWdbeQVerRef1NFile, public Sbecore::PgTable {

public:
	PgTblWdbeQVerRef1NFile();
	~PgTblWdbeQVerRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQVerRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQVerRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQVerRef1NFile& rst);

	Sbecore::ubigint insertRec(WdbeQVerRef1NFile* rec);
	void insertRst(ListWdbeQVerRef1NFile& rst);
	void updateRec(WdbeQVerRef1NFile* rec);
	void updateRst(ListWdbeQVerRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQVerRef1NFile& rst);
};
#endif

#endif
