/**
	* \file WdbeJMVersionState.cpp
	* database access for table TblWdbeJMVersionState (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeJMVersionState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJMVersionState
 ******************************************************************************/

WdbeJMVersionState::WdbeJMVersionState(
			const ubigint ref
			, const ubigint refWdbeMVersion
			, const uint x1Start
			, const uint ixVState
		) :
			ref(ref)
			, refWdbeMVersion(refWdbeMVersion)
			, x1Start(x1Start)
			, ixVState(ixVState)
		{
};

bool WdbeJMVersionState::operator==(
			const WdbeJMVersionState& comp
		) {
	return false;
};

bool WdbeJMVersionState::operator!=(
			const WdbeJMVersionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJMVersionState
 ******************************************************************************/

ListWdbeJMVersionState::ListWdbeJMVersionState() {
};

ListWdbeJMVersionState::ListWdbeJMVersionState(
			const ListWdbeJMVersionState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJMVersionState(*(src.nodes[i]));
};

ListWdbeJMVersionState::~ListWdbeJMVersionState() {
	clear();
};

void ListWdbeJMVersionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJMVersionState::size() const {
	return(nodes.size());
};

void ListWdbeJMVersionState::append(
			WdbeJMVersionState* rec
		) {
	nodes.push_back(rec);
};

WdbeJMVersionState* ListWdbeJMVersionState::operator[](
			const uint ix
		) {
	WdbeJMVersionState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJMVersionState& ListWdbeJMVersionState::operator=(
			const ListWdbeJMVersionState& src
		) {
	WdbeJMVersionState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJMVersionState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJMVersionState::operator==(
			const ListWdbeJMVersionState& comp
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

bool ListWdbeJMVersionState::operator!=(
			const ListWdbeJMVersionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJMVersionState
 ******************************************************************************/

TblWdbeJMVersionState::TblWdbeJMVersionState() {
};

TblWdbeJMVersionState::~TblWdbeJMVersionState() {
};

bool TblWdbeJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMVersionState** rec
		) {
	return false;
};

ubigint TblWdbeJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	return 0;
};

ubigint TblWdbeJMVersionState::insertRec(
			WdbeJMVersionState* rec
		) {
	return 0;
};

ubigint TblWdbeJMVersionState::insertNewRec(
			WdbeJMVersionState** rec
			, const ubigint refWdbeMVersion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMVersionState* _rec = NULL;

	_rec = new WdbeJMVersionState(0, refWdbeMVersion, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJMVersionState::appendNewRecToRst(
			ListWdbeJMVersionState& rst
			, WdbeJMVersionState** rec
			, const ubigint refWdbeMVersion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMVersionState* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMVersion, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJMVersionState::insertRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
};

void TblWdbeJMVersionState::updateRec(
			WdbeJMVersionState* rec
		) {
};

void TblWdbeJMVersionState::updateRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
};

void TblWdbeJMVersionState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJMVersionState::loadRecByRef(
			ubigint ref
			, WdbeJMVersionState** rec
		) {
	return false;
};

bool TblWdbeJMVersionState::loadRecByVerSta(
			ubigint refWdbeMVersion
			, uint x1Start
			, WdbeJMVersionState** rec
		) {
	return false;
};

ubigint TblWdbeJMVersionState::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJMVersionState::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	return 0;
};

ubigint TblWdbeJMVersionState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	ubigint numload = 0;
	WdbeJMVersionState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJMVersionState
 ******************************************************************************/

MyTblWdbeJMVersionState::MyTblWdbeJMVersionState() :
			TblWdbeJMVersionState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJMVersionState::~MyTblWdbeJMVersionState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJMVersionState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJMVersionState (refWdbeMVersion, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJMVersionState SET refWdbeMVersion = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJMVersionState WHERE ref = ?", false);
};

bool MyTblWdbeJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMVersionState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJMVersionState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMVersionState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMVersionState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeJMVersionState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMVersion = atoll((char*) dbrow[1]); else _rec->refWdbeMVersion = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJMVersionState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMVersionState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMVersionState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeJMVersionState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMVersion = atoll((char*) dbrow[1]); else rec->refWdbeMVersion = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJMVersionState::insertRec(
			WdbeJMVersionState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJMVersionState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJMVersionState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJMVersionState::insertRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJMVersionState::updateRec(
			WdbeJMVersionState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJMVersionState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJMVersionState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJMVersionState::updateRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJMVersionState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJMVersionState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJMVersionState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJMVersionState::loadRecByRef(
			ubigint ref
			, WdbeJMVersionState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJMVersionState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJMVersionState::loadRecByVerSta(
			ubigint refWdbeMVersion
			, uint x1Start
			, WdbeJMVersionState** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMVersion, x1Start, ixVState FROM TblWdbeJMVersionState WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWdbeJMVersionState::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJMVersionState WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + "", append, refs);
};

ubigint MyTblWdbeJMVersionState::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMVersion, x1Start, ixVState FROM TblWdbeJMVersionState WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJMVersionState
 ******************************************************************************/

PgTblWdbeJMVersionState::PgTblWdbeJMVersionState() :
			TblWdbeJMVersionState()
			, PgTable()
		{
};

PgTblWdbeJMVersionState::~PgTblWdbeJMVersionState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJMVersionState::initStatements() {
	createStatement("TblWdbeJMVersionState_insertRec", "INSERT INTO TblWdbeJMVersionState (refWdbeMVersion, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeJMVersionState_updateRec", "UPDATE TblWdbeJMVersionState SET refWdbeMVersion = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeJMVersionState_removeRecByRef", "DELETE FROM TblWdbeJMVersionState WHERE ref = $1", 1);

	createStatement("TblWdbeJMVersionState_loadRecByRef", "SELECT ref, refWdbeMVersion, x1Start, ixVState FROM TblWdbeJMVersionState WHERE ref = $1", 1);
	createStatement("TblWdbeJMVersionState_loadRecByVerSta", "SELECT ref, refWdbeMVersion, x1Start, ixVState FROM TblWdbeJMVersionState WHERE refWdbeMVersion = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWdbeJMVersionState_loadRefsByVer", "SELECT ref FROM TblWdbeJMVersionState WHERE refWdbeMVersion = $1", 1);
	createStatement("TblWdbeJMVersionState_loadRstByVer", "SELECT ref, refWdbeMVersion, x1Start, ixVState FROM TblWdbeJMVersionState WHERE refWdbeMVersion = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWdbeJMVersionState::loadRec(
			PGresult* res
			, WdbeJMVersionState** rec
		) {
	char* ptr;

	WdbeJMVersionState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJMVersionState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJMVersionState::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJMVersionState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WdbeJMVersionState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJMVersionState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJMVersionState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMVersionState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMVersionState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMVersionState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMVersionState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMVersionState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMVersionState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJMVersionState::insertRec(
			WdbeJMVersionState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWdbeMVersion,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMVersionState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMVersionState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJMVersionState::insertRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJMVersionState::updateRec(
			WdbeJMVersionState* rec
		) {
	PGresult* res;

	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMVersion,
		(char*) &_x1Start,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMVersionState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMVersionState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJMVersionState::updateRst(
			ListWdbeJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJMVersionState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJMVersionState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMVersionState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJMVersionState::loadRecByRef(
			ubigint ref
			, WdbeJMVersionState** rec
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

	return loadRecByStmt("TblWdbeJMVersionState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJMVersionState::loadRecByVerSta(
			ubigint refWdbeMVersion
			, uint x1Start
			, WdbeJMVersionState** rec
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWdbeMVersion,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJMVersionState_loadRecByVerSta", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJMVersionState::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJMVersionState_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJMVersionState::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeJMVersionState& rst
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJMVersionState_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif
