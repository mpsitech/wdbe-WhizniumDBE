/**
	* \file WdbeAMCommandRetpar.cpp
	* database access for table TblWdbeAMCommandRetpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMCommandRetpar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMCommandRetpar
 ******************************************************************************/

WdbeAMCommandRetpar::WdbeAMCommandRetpar(
			const ubigint ref
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) :
			ref(ref)
			, cmdRefWdbeMCommand(cmdRefWdbeMCommand)
			, cmdNum(cmdNum)
			, sref(sref)
			, ixWdbeVPartype(ixWdbeVPartype)
			, refWdbeMVector(refWdbeMVector)
			, Length(Length)
			, Comment(Comment)
		{
};

bool WdbeAMCommandRetpar::operator==(
			const WdbeAMCommandRetpar& comp
		) {
	return false;
};

bool WdbeAMCommandRetpar::operator!=(
			const WdbeAMCommandRetpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMCommandRetpar
 ******************************************************************************/

ListWdbeAMCommandRetpar::ListWdbeAMCommandRetpar() {
};

ListWdbeAMCommandRetpar::ListWdbeAMCommandRetpar(
			const ListWdbeAMCommandRetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMCommandRetpar(*(src.nodes[i]));
};

ListWdbeAMCommandRetpar::~ListWdbeAMCommandRetpar() {
	clear();
};

void ListWdbeAMCommandRetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMCommandRetpar::size() const {
	return(nodes.size());
};

void ListWdbeAMCommandRetpar::append(
			WdbeAMCommandRetpar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMCommandRetpar* ListWdbeAMCommandRetpar::operator[](
			const uint ix
		) {
	WdbeAMCommandRetpar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMCommandRetpar& ListWdbeAMCommandRetpar::operator=(
			const ListWdbeAMCommandRetpar& src
		) {
	WdbeAMCommandRetpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMCommandRetpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMCommandRetpar::operator==(
			const ListWdbeAMCommandRetpar& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWdbeAMCommandRetpar::operator!=(
			const ListWdbeAMCommandRetpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMCommandRetpar
 ******************************************************************************/

TblWdbeAMCommandRetpar::TblWdbeAMCommandRetpar() {
};

TblWdbeAMCommandRetpar::~TblWdbeAMCommandRetpar() {
};

bool TblWdbeAMCommandRetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandRetpar** rec
		) {
	return false;
};

ubigint TblWdbeAMCommandRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	return 0;
};

ubigint TblWdbeAMCommandRetpar::insertRec(
			WdbeAMCommandRetpar* rec
		) {
	return 0;
};

ubigint TblWdbeAMCommandRetpar::insertNewRec(
			WdbeAMCommandRetpar** rec
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCommandRetpar* _rec = NULL;

	_rec = new WdbeAMCommandRetpar(0, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMCommandRetpar::appendNewRecToRst(
			ListWdbeAMCommandRetpar& rst
			, WdbeAMCommandRetpar** rec
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCommandRetpar* _rec = NULL;

	retval = insertNewRec(&_rec, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMCommandRetpar::insertRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
};

void TblWdbeAMCommandRetpar::updateRec(
			WdbeAMCommandRetpar* rec
		) {
};

void TblWdbeAMCommandRetpar::updateRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
};

void TblWdbeAMCommandRetpar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMCommandRetpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandRetpar** rec
		) {
	return false;
};

ubigint TblWdbeAMCommandRetpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMCommandRetpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	return 0;
};

ubigint TblWdbeAMCommandRetpar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	ubigint numload = 0;
	WdbeAMCommandRetpar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMCommandRetpar
 ******************************************************************************/

MyTblWdbeAMCommandRetpar::MyTblWdbeAMCommandRetpar() :
			TblWdbeAMCommandRetpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMCommandRetpar::~MyTblWdbeAMCommandRetpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMCommandRetpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMCommandRetpar (cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMCommandRetpar SET cmdRefWdbeMCommand = ?, cmdNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMCommandRetpar WHERE ref = ?", false);
};

bool MyTblWdbeAMCommandRetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandRetpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMCommandRetpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCommandRetpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCommandRetpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMCommandRetpar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->cmdRefWdbeMCommand = atoll((char*) dbrow[1]); else _rec->cmdRefWdbeMCommand = 0;
		if (dbrow[2]) _rec->cmdNum = atol((char*) dbrow[2]); else _rec->cmdNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixWdbeVPartype = atol((char*) dbrow[4]); else _rec->ixWdbeVPartype = 0;
		if (dbrow[5]) _rec->refWdbeMVector = atoll((char*) dbrow[5]); else _rec->refWdbeMVector = 0;
		if (dbrow[6]) _rec->Length = atoi((char*) dbrow[6]); else _rec->Length = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMCommandRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMCommandRetpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCommandRetpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCommandRetpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMCommandRetpar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->cmdRefWdbeMCommand = atoll((char*) dbrow[1]); else rec->cmdRefWdbeMCommand = 0;
			if (dbrow[2]) rec->cmdNum = atol((char*) dbrow[2]); else rec->cmdNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixWdbeVPartype = atol((char*) dbrow[4]); else rec->ixWdbeVPartype = 0;
			if (dbrow[5]) rec->refWdbeMVector = atoll((char*) dbrow[5]); else rec->refWdbeMVector = 0;
			if (dbrow[6]) rec->Length = atoi((char*) dbrow[6]); else rec->Length = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMCommandRetpar::insertRec(
			WdbeAMCommandRetpar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cmdRefWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cmdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMCommandRetpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMCommandRetpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMCommandRetpar::insertRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMCommandRetpar::updateRec(
			WdbeAMCommandRetpar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cmdRefWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cmdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMCommandRetpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMCommandRetpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMCommandRetpar::updateRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMCommandRetpar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMCommandRetpar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMCommandRetpar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMCommandRetpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandRetpar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMCommandRetpar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMCommandRetpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(cmdRefWdbeMCommand) + "", append, refs);
};

ubigint MyTblWdbeAMCommandRetpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	return loadRstBySQL("SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(cmdRefWdbeMCommand) + " ORDER BY cmdNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMCommandRetpar
 ******************************************************************************/

PgTblWdbeAMCommandRetpar::PgTblWdbeAMCommandRetpar() :
			TblWdbeAMCommandRetpar()
			, PgTable()
		{
};

PgTblWdbeAMCommandRetpar::~PgTblWdbeAMCommandRetpar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMCommandRetpar::initStatements() {
	createStatement("TblWdbeAMCommandRetpar_insertRec", "INSERT INTO TblWdbeAMCommandRetpar (cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWdbeAMCommandRetpar_updateRec", "UPDATE TblWdbeAMCommandRetpar SET cmdRefWdbeMCommand = $1, cmdNum = $2, sref = $3, ixWdbeVPartype = $4, refWdbeMVector = $5, Length = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWdbeAMCommandRetpar_removeRecByRef", "DELETE FROM TblWdbeAMCommandRetpar WHERE ref = $1", 1);

	createStatement("TblWdbeAMCommandRetpar_loadRecByRef", "SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMCommandRetpar WHERE ref = $1", 1);
	createStatement("TblWdbeAMCommandRetpar_loadRefsByCmd", "SELECT ref FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = $1", 1);
	createStatement("TblWdbeAMCommandRetpar_loadRstByCmd", "SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = $1 ORDER BY cmdNum ASC", 1);
};

bool PgTblWdbeAMCommandRetpar::loadRec(
			PGresult* res
			, WdbeAMCommandRetpar** rec
		) {
	char* ptr;

	WdbeAMCommandRetpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMCommandRetpar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdrefwdbemcommand"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->cmdRefWdbeMCommand = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->cmdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVPartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Length = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMCommandRetpar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMCommandRetpar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdrefwdbemcommand"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAMCommandRetpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->cmdRefWdbeMCommand = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->cmdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeVPartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Length = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMCommandRetpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMCommandRetpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCommandRetpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMCommandRetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandRetpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCommandRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMCommandRetpar::insertRec(
			WdbeAMCommandRetpar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _cmdRefWdbeMCommand = htonl64(rec->cmdRefWdbeMCommand);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMCommandRetpar_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMCommandRetpar::insertRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMCommandRetpar::updateRec(
			WdbeAMCommandRetpar* rec
		) {
	PGresult* res;

	ubigint _cmdRefWdbeMCommand = htonl64(rec->cmdRefWdbeMCommand);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMCommandRetpar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMCommandRetpar::updateRst(
			ListWdbeAMCommandRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMCommandRetpar::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeAMCommandRetpar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCommandRetpar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMCommandRetpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandRetpar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeAMCommandRetpar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMCommandRetpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _cmdRefWdbeMCommand = htonl64(cmdRefWdbeMCommand);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMCommandRetpar_loadRefsByCmd", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMCommandRetpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandRetpar& rst
		) {
	ubigint _cmdRefWdbeMCommand = htonl64(cmdRefWdbeMCommand);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMCommandRetpar_loadRstByCmd", 1, vals, l, f, append, rst);
};

#endif
