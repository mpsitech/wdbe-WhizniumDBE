/**
	* \file WdbeMInterrupt.cpp
	* database access for table TblWdbeMInterrupt (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeMInterrupt.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMInterrupt
 ******************************************************************************/

WdbeMInterrupt::WdbeMInterrupt(
			const ubigint ref
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) :
			ref(ref)
			, refWdbeMUnit(refWdbeMUnit)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WdbeMInterrupt::operator==(
			const WdbeMInterrupt& comp
		) {
	return false;
};

bool WdbeMInterrupt::operator!=(
			const WdbeMInterrupt& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMInterrupt
 ******************************************************************************/

ListWdbeMInterrupt::ListWdbeMInterrupt() {
};

ListWdbeMInterrupt::ListWdbeMInterrupt(
			const ListWdbeMInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMInterrupt(*(src.nodes[i]));
};

ListWdbeMInterrupt::~ListWdbeMInterrupt() {
	clear();
};

void ListWdbeMInterrupt::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMInterrupt::size() const {
	return(nodes.size());
};

void ListWdbeMInterrupt::append(
			WdbeMInterrupt* rec
		) {
	nodes.push_back(rec);
};

WdbeMInterrupt* ListWdbeMInterrupt::operator[](
			const uint ix
		) {
	WdbeMInterrupt* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMInterrupt& ListWdbeMInterrupt::operator=(
			const ListWdbeMInterrupt& src
		) {
	WdbeMInterrupt* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMInterrupt(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMInterrupt::operator==(
			const ListWdbeMInterrupt& comp
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

bool ListWdbeMInterrupt::operator!=(
			const ListWdbeMInterrupt& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMInterrupt
 ******************************************************************************/

TblWdbeMInterrupt::TblWdbeMInterrupt() {
};

TblWdbeMInterrupt::~TblWdbeMInterrupt() {
};

bool TblWdbeMInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeMInterrupt** rec
		) {
	return false;
};

ubigint TblWdbeMInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	return 0;
};

ubigint TblWdbeMInterrupt::insertRec(
			WdbeMInterrupt* rec
		) {
	return 0;
};

ubigint TblWdbeMInterrupt::insertNewRec(
			WdbeMInterrupt** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMInterrupt* _rec = NULL;

	_rec = new WdbeMInterrupt(0, refWdbeMUnit, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMInterrupt::appendNewRecToRst(
			ListWdbeMInterrupt& rst
			, WdbeMInterrupt** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMInterrupt* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUnit, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMInterrupt::insertRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
};

void TblWdbeMInterrupt::updateRec(
			WdbeMInterrupt* rec
		) {
};

void TblWdbeMInterrupt::updateRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
};

void TblWdbeMInterrupt::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMInterrupt::loadRecByRef(
			ubigint ref
			, WdbeMInterrupt** rec
		) {
	return false;
};

ubigint TblWdbeMInterrupt::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMInterrupt::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	return 0;
};

bool TblWdbeMInterrupt::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMInterrupt::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	ubigint numload = 0;
	WdbeMInterrupt* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMInterrupt
 ******************************************************************************/

MyTblWdbeMInterrupt::MyTblWdbeMInterrupt() :
			TblWdbeMInterrupt()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMInterrupt::~MyTblWdbeMInterrupt() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMInterrupt::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMInterrupt (refWdbeMUnit, sref, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMInterrupt SET refWdbeMUnit = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMInterrupt WHERE ref = ?", false);
};

bool MyTblWdbeMInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeMInterrupt** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMInterrupt* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMInterrupt::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMInterrupt::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMInterrupt();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUnit = atoll((char*) dbrow[1]); else _rec->refWdbeMUnit = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMInterrupt* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMInterrupt::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMInterrupt::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMInterrupt();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUnit = atoll((char*) dbrow[1]); else rec->refWdbeMUnit = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMInterrupt::insertRec(
			WdbeMInterrupt* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMInterrupt::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMInterrupt::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMInterrupt::insertRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMInterrupt::updateRec(
			WdbeMInterrupt* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMInterrupt::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMInterrupt::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMInterrupt::updateRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMInterrupt::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMInterrupt::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMInterrupt::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMInterrupt::loadRecByRef(
			ubigint ref
			, WdbeMInterrupt** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMInterrupt WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMInterrupt::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMInterrupt WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + "", append, refs);
};

ubigint MyTblWdbeMInterrupt::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMInterrupt WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMInterrupt::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMInterrupt WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMInterrupt
 ******************************************************************************/

PgTblWdbeMInterrupt::PgTblWdbeMInterrupt() :
			TblWdbeMInterrupt()
			, PgTable()
		{
};

PgTblWdbeMInterrupt::~PgTblWdbeMInterrupt() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMInterrupt::initStatements() {
	createStatement("TblWdbeMInterrupt_insertRec", "INSERT INTO TblWdbeMInterrupt (refWdbeMUnit, sref, Comment) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeMInterrupt_updateRec", "UPDATE TblWdbeMInterrupt SET refWdbeMUnit = $1, sref = $2, Comment = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeMInterrupt_removeRecByRef", "DELETE FROM TblWdbeMInterrupt WHERE ref = $1", 1);

	createStatement("TblWdbeMInterrupt_loadRecByRef", "SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMInterrupt WHERE ref = $1", 1);
	createStatement("TblWdbeMInterrupt_loadRefsByUnt", "SELECT ref FROM TblWdbeMInterrupt WHERE refWdbeMUnit = $1", 1);
	createStatement("TblWdbeMInterrupt_loadRstByUnt", "SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMInterrupt WHERE refWdbeMUnit = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMInterrupt_loadSrfByRef", "SELECT sref FROM TblWdbeMInterrupt WHERE ref = $1", 1);
};

bool PgTblWdbeMInterrupt::loadRec(
			PGresult* res
			, WdbeMInterrupt** rec
		) {
	char* ptr;

	WdbeMInterrupt* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMInterrupt();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMInterrupt::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMInterrupt* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMInterrupt();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMInterrupt::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMInterrupt** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMInterrupt::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMInterrupt::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMInterrupt::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeMInterrupt** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMInterrupt::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMInterrupt::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMInterrupt::insertRec(
			WdbeMInterrupt* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMInterrupt_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMInterrupt::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMInterrupt::insertRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMInterrupt::updateRec(
			WdbeMInterrupt* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMInterrupt_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMInterrupt::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMInterrupt::updateRst(
			ListWdbeMInterrupt& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMInterrupt::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMInterrupt_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMInterrupt::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMInterrupt::loadRecByRef(
			ubigint ref
			, WdbeMInterrupt** rec
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

	return loadRecByStmt("TblWdbeMInterrupt_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMInterrupt::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMInterrupt_loadRefsByUnt", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMInterrupt::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMInterrupt& rst
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMInterrupt_loadRstByUnt", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMInterrupt::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMInterrupt_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
