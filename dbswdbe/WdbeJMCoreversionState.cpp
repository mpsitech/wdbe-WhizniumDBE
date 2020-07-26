/**
	* \file WdbeJMCoreversionState.cpp
	* database access for table TblWdbeJMCoreversionState (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeJMCoreversionState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJMCoreversionState
 ******************************************************************************/

WdbeJMCoreversionState::WdbeJMCoreversionState(
			const ubigint ref
			, const ubigint refWdbeMCoreversion
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWdbeMCoreversion = refWdbeMCoreversion;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WdbeJMCoreversionState::operator==(
			const WdbeJMCoreversionState& comp
		) {
	return false;
};

bool WdbeJMCoreversionState::operator!=(
			const WdbeJMCoreversionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJMCoreversionState
 ******************************************************************************/

ListWdbeJMCoreversionState::ListWdbeJMCoreversionState() {
};

ListWdbeJMCoreversionState::ListWdbeJMCoreversionState(
			const ListWdbeJMCoreversionState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJMCoreversionState(*(src.nodes[i]));
};

ListWdbeJMCoreversionState::~ListWdbeJMCoreversionState() {
	clear();
};

void ListWdbeJMCoreversionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJMCoreversionState::size() const {
	return(nodes.size());
};

void ListWdbeJMCoreversionState::append(
			WdbeJMCoreversionState* rec
		) {
	nodes.push_back(rec);
};

WdbeJMCoreversionState* ListWdbeJMCoreversionState::operator[](
			const uint ix
		) {
	WdbeJMCoreversionState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJMCoreversionState& ListWdbeJMCoreversionState::operator=(
			const ListWdbeJMCoreversionState& src
		) {
	WdbeJMCoreversionState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJMCoreversionState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJMCoreversionState::operator==(
			const ListWdbeJMCoreversionState& comp
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

bool ListWdbeJMCoreversionState::operator!=(
			const ListWdbeJMCoreversionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJMCoreversionState
 ******************************************************************************/

TblWdbeJMCoreversionState::TblWdbeJMCoreversionState() {
};

TblWdbeJMCoreversionState::~TblWdbeJMCoreversionState() {
};

bool TblWdbeJMCoreversionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMCoreversionState** rec
		) {
	return false;
};

ubigint TblWdbeJMCoreversionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	return 0;
};

ubigint TblWdbeJMCoreversionState::insertRec(
			WdbeJMCoreversionState* rec
		) {
	return 0;
};

ubigint TblWdbeJMCoreversionState::insertNewRec(
			WdbeJMCoreversionState** rec
			, const ubigint refWdbeMCoreversion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMCoreversionState* _rec = NULL;

	_rec = new WdbeJMCoreversionState(0, refWdbeMCoreversion, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJMCoreversionState::appendNewRecToRst(
			ListWdbeJMCoreversionState& rst
			, WdbeJMCoreversionState** rec
			, const ubigint refWdbeMCoreversion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMCoreversionState* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMCoreversion, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJMCoreversionState::insertRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
};

void TblWdbeJMCoreversionState::updateRec(
			WdbeJMCoreversionState* rec
		) {
};

void TblWdbeJMCoreversionState::updateRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
};

void TblWdbeJMCoreversionState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJMCoreversionState::loadRecByRef(
			ubigint ref
			, WdbeJMCoreversionState** rec
		) {
	return false;
};

bool TblWdbeJMCoreversionState::loadRecByCvrSta(
			ubigint refWdbeMCoreversion
			, uint x1Start
			, WdbeJMCoreversionState** rec
		) {
	return false;
};

ubigint TblWdbeJMCoreversionState::loadRefsByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJMCoreversionState::loadRstByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	return 0;
};

ubigint TblWdbeJMCoreversionState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	ubigint numload = 0;
	WdbeJMCoreversionState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJMCoreversionState
 ******************************************************************************/

MyTblWdbeJMCoreversionState::MyTblWdbeJMCoreversionState() :
			TblWdbeJMCoreversionState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJMCoreversionState::~MyTblWdbeJMCoreversionState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJMCoreversionState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJMCoreversionState (refWdbeMCoreversion, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJMCoreversionState SET refWdbeMCoreversion = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJMCoreversionState WHERE ref = ?", false);
};

bool MyTblWdbeJMCoreversionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMCoreversionState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJMCoreversionState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMCoreversionState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMCoreversionState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeJMCoreversionState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMCoreversion = atoll((char*) dbrow[1]); else _rec->refWdbeMCoreversion = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJMCoreversionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJMCoreversionState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMCoreversionState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMCoreversionState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeJMCoreversionState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMCoreversion = atoll((char*) dbrow[1]); else rec->refWdbeMCoreversion = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJMCoreversionState::insertRec(
			WdbeJMCoreversionState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJMCoreversionState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJMCoreversionState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJMCoreversionState::insertRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJMCoreversionState::updateRec(
			WdbeJMCoreversionState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJMCoreversionState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJMCoreversionState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJMCoreversionState::updateRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJMCoreversionState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJMCoreversionState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJMCoreversionState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJMCoreversionState::loadRecByRef(
			ubigint ref
			, WdbeJMCoreversionState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJMCoreversionState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJMCoreversionState::loadRecByCvrSta(
			ubigint refWdbeMCoreversion
			, uint x1Start
			, WdbeJMCoreversionState** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMCoreversion, x1Start, ixVState FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = " + to_string(refWdbeMCoreversion) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWdbeJMCoreversionState::loadRefsByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = " + to_string(refWdbeMCoreversion) + "", append, refs);
};

ubigint MyTblWdbeJMCoreversionState::loadRstByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMCoreversion, x1Start, ixVState FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = " + to_string(refWdbeMCoreversion) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJMCoreversionState
 ******************************************************************************/

PgTblWdbeJMCoreversionState::PgTblWdbeJMCoreversionState() :
			TblWdbeJMCoreversionState()
			, PgTable()
		{
};

PgTblWdbeJMCoreversionState::~PgTblWdbeJMCoreversionState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJMCoreversionState::initStatements() {
	createStatement("TblWdbeJMCoreversionState_insertRec", "INSERT INTO TblWdbeJMCoreversionState (refWdbeMCoreversion, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeJMCoreversionState_updateRec", "UPDATE TblWdbeJMCoreversionState SET refWdbeMCoreversion = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeJMCoreversionState_removeRecByRef", "DELETE FROM TblWdbeJMCoreversionState WHERE ref = $1", 1);

	createStatement("TblWdbeJMCoreversionState_loadRecByRef", "SELECT ref, refWdbeMCoreversion, x1Start, ixVState FROM TblWdbeJMCoreversionState WHERE ref = $1", 1);
	createStatement("TblWdbeJMCoreversionState_loadRecByCvrSta", "SELECT ref, refWdbeMCoreversion, x1Start, ixVState FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWdbeJMCoreversionState_loadRefsByCvr", "SELECT ref FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = $1", 1);
	createStatement("TblWdbeJMCoreversionState_loadRstByCvr", "SELECT ref, refWdbeMCoreversion, x1Start, ixVState FROM TblWdbeJMCoreversionState WHERE refWdbeMCoreversion = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWdbeJMCoreversionState::loadRec(
			PGresult* res
			, WdbeJMCoreversionState** rec
		) {
	char* ptr;

	WdbeJMCoreversionState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJMCoreversionState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJMCoreversionState::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJMCoreversionState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WdbeJMCoreversionState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJMCoreversionState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJMCoreversionState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMCoreversionState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJMCoreversionState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMCoreversionState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMCoreversionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJMCoreversionState::insertRec(
			WdbeJMCoreversionState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWdbeMCoreversion,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMCoreversionState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJMCoreversionState::insertRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJMCoreversionState::updateRec(
			WdbeJMCoreversionState* rec
		) {
	PGresult* res;

	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMCoreversion,
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

	res = PQexecPrepared(dbs, "TblWdbeJMCoreversionState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJMCoreversionState::updateRst(
			ListWdbeJMCoreversionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJMCoreversionState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJMCoreversionState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMCoreversionState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJMCoreversionState::loadRecByRef(
			ubigint ref
			, WdbeJMCoreversionState** rec
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

	return loadRecByStmt("TblWdbeJMCoreversionState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJMCoreversionState::loadRecByCvrSta(
			ubigint refWdbeMCoreversion
			, uint x1Start
			, WdbeJMCoreversionState** rec
		) {
	ubigint _refWdbeMCoreversion = htonl64(refWdbeMCoreversion);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWdbeMCoreversion,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJMCoreversionState_loadRecByCvrSta", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJMCoreversionState::loadRefsByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMCoreversion = htonl64(refWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_refWdbeMCoreversion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJMCoreversionState_loadRefsByCvr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJMCoreversionState::loadRstByCvr(
			ubigint refWdbeMCoreversion
			, const bool append
			, ListWdbeJMCoreversionState& rst
		) {
	ubigint _refWdbeMCoreversion = htonl64(refWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_refWdbeMCoreversion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJMCoreversionState_loadRstByCvr", 1, vals, l, f, append, rst);
};

#endif

