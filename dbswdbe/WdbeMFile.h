/**
	* \file WdbeMFile.h
	* database access for table TblWdbeMFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMFILE_H
#define WDBEMFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMFileRefTbl TblWdbeMFile::VecVRefTbl

/**
	* WdbeMFile: record of TblWdbeMFile
	*/
class WdbeMFile {

public:
	WdbeMFile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWdbeCFile;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string osrefKContent;
	Sbecore::uint Archived;
	std::string Filename;
	std::string Archivename;
	std::string srefKMimetype;
	Sbecore::usmallint Size;
	std::string Comment;

public:
	bool operator==(const WdbeMFile& comp);
	bool operator!=(const WdbeMFile& comp);
};

/**
	* ListWdbeMFile: recordset of TblWdbeMFile
	*/
class ListWdbeMFile {

public:
	ListWdbeMFile();
	ListWdbeMFile(const ListWdbeMFile& src);
	~ListWdbeMFile();

	void clear();
	unsigned int size() const;
	void append(WdbeMFile* rec);

	WdbeMFile* operator[](const Sbecore::uint ix);
	ListWdbeMFile& operator=(const ListWdbeMFile& src);
	bool operator==(const ListWdbeMFile& comp);
	bool operator!=(const ListWdbeMFile& comp);

public:
	std::vector<WdbeMFile*> nodes;
};

/**
	* TblWdbeMFile: C++ wrapper for table TblWdbeMFile
	*/
class TblWdbeMFile {

public:
	/**
		* VecVRefTbl (full: VecWdbeVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint MTP = 2;
		static const Sbecore::uint VER = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMFile();
	virtual ~TblWdbeMFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFile& rst);

	virtual Sbecore::ubigint insertRec(WdbeMFile* rec);
	Sbecore::ubigint insertNewRec(WdbeMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMFile& rst, WdbeMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWdbeCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMFile& rst, bool transact = false);
	virtual void updateRec(WdbeMFile* rec);
	virtual void updateRst(ListWdbeMFile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMFile** rec);
	virtual bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFile, const bool append, ListWdbeMFile& rst);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMFile& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMFile: C++ wrapper for table TblWdbeMFile (MySQL database)
	*/
class MyTblWdbeMFile : public TblWdbeMFile, public Sbecore::MyTable {

public:
	MyTblWdbeMFile();
	~MyTblWdbeMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFile& rst);

	Sbecore::ubigint insertRec(WdbeMFile* rec);
	void insertRst(ListWdbeMFile& rst, bool transact = false);
	void updateRec(WdbeMFile* rec);
	void updateRst(ListWdbeMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFile, const bool append, ListWdbeMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMFile: C++ wrapper for table TblWdbeMFile (PgSQL database)
	*/
class PgTblWdbeMFile : public TblWdbeMFile, public Sbecore::PgTable {

public:
	PgTblWdbeMFile();
	~PgTblWdbeMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMFile& rst);

	Sbecore::ubigint insertRec(WdbeMFile* rec);
	void insertRst(ListWdbeMFile& rst, bool transact = false);
	void updateRec(WdbeMFile* rec);
	void updateRst(ListWdbeMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWdbeCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWdbeCFile, const bool append, ListWdbeMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMFile& rst);
};
#endif

#endif
