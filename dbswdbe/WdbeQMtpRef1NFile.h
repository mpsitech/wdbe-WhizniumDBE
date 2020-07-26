/**
	* \file WdbeQMtpRef1NFile.h
	* Dbs and XML wrapper for table TblWdbeQMtpRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPREF1NFILE_H
#define WDBEQMTPREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WdbeQMtpRef1NFile: record of TblWdbeQMtpRef1NFile
	*/
class WdbeQMtpRef1NFile {

public:
	WdbeQMtpRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWdbeQMtpRef1NFile: recordset of TblWdbeQMtpRef1NFile
	*/
class ListWdbeQMtpRef1NFile {

public:
	ListWdbeQMtpRef1NFile();
	ListWdbeQMtpRef1NFile(const ListWdbeQMtpRef1NFile& src);
	~ListWdbeQMtpRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WdbeQMtpRef1NFile* rec);

	ListWdbeQMtpRef1NFile& operator=(const ListWdbeQMtpRef1NFile& src);

public:
	std::vector<WdbeQMtpRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWdbeQMtpRef1NFile: C++ wrapper for table TblWdbeQMtpRef1NFile
	*/
class TblWdbeQMtpRef1NFile {

public:
	TblWdbeQMtpRef1NFile();
	virtual ~TblWdbeQMtpRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WdbeQMtpRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WdbeQMtpRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeQMtpRef1NFile& rst, WdbeQMtpRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWdbeQMtpRef1NFile& rst);
	virtual void updateRec(WdbeQMtpRef1NFile* rec);
	virtual void updateRst(ListWdbeQMtpRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeQMtpRef1NFile: C++ wrapper for table TblWdbeQMtpRef1NFile (MySQL database)
	*/
class MyTblWdbeQMtpRef1NFile : public TblWdbeQMtpRef1NFile, public Sbecore::MyTable {

public:
	MyTblWdbeQMtpRef1NFile();
	~MyTblWdbeQMtpRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NFile& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NFile* rec);
	void insertRst(ListWdbeQMtpRef1NFile& rst);
	void updateRec(WdbeQMtpRef1NFile* rec);
	void updateRst(ListWdbeQMtpRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeQMtpRef1NFile: C++ wrapper for table TblWdbeQMtpRef1NFile (PgSQL database)
	*/
class PgTblWdbeQMtpRef1NFile : public TblWdbeQMtpRef1NFile, public Sbecore::PgTable {

public:
	PgTblWdbeQMtpRef1NFile();
	~PgTblWdbeQMtpRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeQMtpRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeQMtpRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeQMtpRef1NFile& rst);

	Sbecore::ubigint insertRec(WdbeQMtpRef1NFile* rec);
	void insertRst(ListWdbeQMtpRef1NFile& rst);
	void updateRec(WdbeQMtpRef1NFile* rec);
	void updateRst(ListWdbeQMtpRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WdbeQMtpRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWdbeQMtpRef1NFile& rst);
};
#endif

#endif

