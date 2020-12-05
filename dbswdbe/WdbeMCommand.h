/**
	* \file WdbeMCommand.h
	* database access for table TblWdbeMCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEMCOMMAND_H
#define WDBEMCOMMAND_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWdbeVMCommandRefTbl TblWdbeMCommand::VecVRefTbl
#define VecWdbeVMCommandRettype TblWdbeMCommand::VecVRettype

/**
	* WdbeMCommand: record of TblWdbeMCommand
	*/
class WdbeMCommand {

public:
	WdbeMCommand(const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint ixVRettype = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0, const Sbecore::ubigint rerRefWdbeMSignal = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint refNum;
	std::string sref;
	std::string Fullsref;
	Sbecore::uint ixVRettype;
	Sbecore::ubigint ivrRefWdbeMSignal;
	Sbecore::ubigint rvrRefWdbeMSignal;
	Sbecore::ubigint rerRefWdbeMSignal;
	std::string Comment;

public:
	bool operator==(const WdbeMCommand& comp);
	bool operator!=(const WdbeMCommand& comp);
};

/**
	* ListWdbeMCommand: recordset of TblWdbeMCommand
	*/
class ListWdbeMCommand {

public:
	ListWdbeMCommand();
	ListWdbeMCommand(const ListWdbeMCommand& src);
	~ListWdbeMCommand();

	void clear();
	unsigned int size() const;
	void append(WdbeMCommand* rec);

	WdbeMCommand* operator[](const Sbecore::uint ix);
	ListWdbeMCommand& operator=(const ListWdbeMCommand& src);
	bool operator==(const ListWdbeMCommand& comp);
	bool operator!=(const ListWdbeMCommand& comp);

public:
	std::vector<WdbeMCommand*> nodes;
};

/**
	* TblWdbeMCommand: C++ wrapper for table TblWdbeMCommand
	*/
class TblWdbeMCommand {

public:
	/**
		* VecVRefTbl (full: VecWdbeVMCommandRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint CTR = 1;
		static const Sbecore::uint UNT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRettype (full: VecWdbeVMCommandRettype)
		*/
	class VecVRettype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint STATSNG = 2;
		static const Sbecore::uint IMMSNG = 3;
		static const Sbecore::uint DFRSNG = 4;
		static const Sbecore::uint MULT = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWdbeMCommand();
	virtual ~TblWdbeMCommand();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WdbeMCommand** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCommand& rst);

	virtual Sbecore::ubigint insertRec(WdbeMCommand* rec);
	Sbecore::ubigint insertNewRec(WdbeMCommand** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint ixVRettype = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0, const Sbecore::ubigint rerRefWdbeMSignal = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWdbeMCommand& rst, WdbeMCommand** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint refNum = 0, const std::string sref = "", const std::string Fullsref = "", const Sbecore::uint ixVRettype = 0, const Sbecore::ubigint ivrRefWdbeMSignal = 0, const Sbecore::ubigint rvrRefWdbeMSignal = 0, const Sbecore::ubigint rerRefWdbeMSignal = 0, const std::string Comment = "");
	virtual void insertRst(ListWdbeMCommand& rst, bool transact = false);
	virtual void updateRec(WdbeMCommand* rec);
	virtual void updateRst(ListWdbeMCommand& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WdbeMCommand** rec);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMCommand& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWdbeMCommand& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWdbeMCommand: C++ wrapper for table TblWdbeMCommand (MySQL database)
	*/
class MyTblWdbeMCommand : public TblWdbeMCommand, public Sbecore::MyTable {

public:
	MyTblWdbeMCommand();
	~MyTblWdbeMCommand();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCommand& rst);

	Sbecore::ubigint insertRec(WdbeMCommand* rec);
	void insertRst(ListWdbeMCommand& rst, bool transact = false);
	void updateRec(WdbeMCommand* rec);
	void updateRst(ListWdbeMCommand& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCommand** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMCommand& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWdbeMCommand: C++ wrapper for table TblWdbeMCommand (PgSQL database)
	*/
class PgTblWdbeMCommand : public TblWdbeMCommand, public Sbecore::PgTable {

public:
	PgTblWdbeMCommand();
	~PgTblWdbeMCommand();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WdbeMCommand** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWdbeMCommand& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WdbeMCommand** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWdbeMCommand& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WdbeMCommand** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWdbeMCommand& rst);

	Sbecore::ubigint insertRec(WdbeMCommand* rec);
	void insertRst(ListWdbeMCommand& rst, bool transact = false);
	void updateRec(WdbeMCommand* rec);
	void updateRst(ListWdbeMCommand& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WdbeMCommand** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWdbeMCommand& rst);
};
#endif

#endif

