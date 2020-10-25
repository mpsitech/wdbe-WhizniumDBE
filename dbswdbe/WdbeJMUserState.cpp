/**
	* \file WdbeJMUserState.cpp
	* database access for table TblWdbeJMUserState (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeJMUserState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJMUserState
 ******************************************************************************/

WdbeJMUserState::WdbeJMUserState(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WdbeJMUserState::operator==(
			const WdbeJMUserState& comp
		) {
	return false;
};

bool WdbeJMUserState::operator!=(
			const WdbeJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJMUserState
 ******************************************************************************/

ListWdbeJMUserState::ListWdbeJMUserState() {
};

ListWdbeJMUserState::ListWdbeJMUserState(
			const ListWdbeJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJMUserState(*(src.nodes[i]));
};

ListWdbeJMUserState::~ListWdbeJMUserState() {
	clear();
};

void ListWdbeJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJMUserState::size() const {
	return(nodes.size());
};

void ListWdbeJMUserState::append(
			WdbeJMUserState* rec
		) {
	nodes.push_back(rec);
};

WdbeJMUserState* ListWdbeJMUserState::operator[](
			const uint ix
		) {
	WdbeJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJMUserState& ListWdbeJMUserState::operator=(
			const ListWdbeJMUserState& src
		) {
	WdbeJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJMUserState::operator==(
			const ListWdbeJMUserState& comp
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

bool ListWdbeJMUserState::operator!=(
			const ListWdbeJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJMUserState
 ******************************************************************************/

TblWdbeJMUserState::TblWdbeJMUserState() {
};

TblWdbeJMUserState::~TblWdbeJMUserState() {
};

bool TblWdbeJMUserState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMUserState** rec
		) {
	return false;
};

ubigint TblWdbeJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	return 0;
};

ubigint TblWdbeJMUserState::insertRec(
			WdbeJMUserState* rec
		) {
	return 0;
};

ubigint TblWdbeJMUserState::insertNewRec(
			WdbeJMUserState** rec
			, const ubigint refWdbeMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMUserState* _rec = NULL;

	_rec = new WdbeJMUserState(0, refWdbeMUser, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJMUserState::appendNewRecToRst(
			ListWdbeJMUserState& rst
			, WdbeJMUserState** rec
			, const ubigint refWdbeMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WdbeJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJMUserState::insertRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
};

void TblWdbeJMUserState::updateRec(
			WdbeJMUserState* rec
		) {
};

void TblWdbeJMUserState::updateRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
};

void TblWdbeJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJMUserState::loadRecByRef(
			ubigint ref
			, WdbeJMUserState** rec
		) {
	return false;
};

bool TblWdbeJMUserState::loadRecByUsrSta(
			ubigint refWdbeMUser
			, uint x1Start
			, WdbeJMUserState** rec
		) {
	return false;
};

ubigint TblWdbeJMUserState::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJMUserState::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	return 0;
};

ubigint TblWdbeJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	ubigint numload = 0;
	WdbeJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJMUserState
 ******************************************************************************/

MyTblWdbeJMUserState::MyTblWdbeJMUserState() :
			TblWdbeJMUserState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJMUserState::~MyTblWdbeJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJMUserState (refWdbeMUser, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJMUserState SET refWdbeMUser = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJMUserState WHERE ref = ?", false);
};

bool MyTblWdbeJMUserState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMUserState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMUserState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMUserState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMUserState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJMUserState::insertRec(
			WdbeJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJMUserState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJMUserState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJMUserState::insertRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJMUserState::updateRec(
			WdbeJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJMUserState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJMUserState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJMUserState::updateRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJMUserState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJMUserState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJMUserState::loadRecByRef(
			ubigint ref
			, WdbeJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJMUserState::loadRecByUsrSta(
			ubigint refWdbeMUser
			, uint x1Start
			, WdbeJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMUser, x1Start, ixVState FROM TblWdbeJMUserState WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWdbeJMUserState::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJMUserState WHERE refWdbeMUser = " + to_string(refWdbeMUser) + "", append, refs);
};

ubigint MyTblWdbeJMUserState::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, x1Start, ixVState FROM TblWdbeJMUserState WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJMUserState
 ******************************************************************************/

PgTblWdbeJMUserState::PgTblWdbeJMUserState() :
			TblWdbeJMUserState()
			, PgTable()
		{
};

PgTblWdbeJMUserState::~PgTblWdbeJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJMUserState::initStatements() {
	createStatement("TblWdbeJMUserState_insertRec", "INSERT INTO TblWdbeJMUserState (refWdbeMUser, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeJMUserState_updateRec", "UPDATE TblWdbeJMUserState SET refWdbeMUser = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeJMUserState_removeRecByRef", "DELETE FROM TblWdbeJMUserState WHERE ref = $1", 1);

	createStatement("TblWdbeJMUserState_loadRecByRef", "SELECT ref, refWdbeMUser, x1Start, ixVState FROM TblWdbeJMUserState WHERE ref = $1", 1);
	createStatement("TblWdbeJMUserState_loadRecByUsrSta", "SELECT ref, refWdbeMUser, x1Start, ixVState FROM TblWdbeJMUserState WHERE refWdbeMUser = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWdbeJMUserState_loadRefsByUsr", "SELECT ref FROM TblWdbeJMUserState WHERE refWdbeMUser = $1", 1);
	createStatement("TblWdbeJMUserState_loadRstByUsr", "SELECT ref, refWdbeMUser, x1Start, ixVState FROM TblWdbeJMUserState WHERE refWdbeMUser = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWdbeJMUserState::loadRec(
			PGresult* res
			, WdbeJMUserState** rec
		) {
	char* ptr;

	WdbeJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WdbeJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMUserState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMUserState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJMUserState::loadRecBySQL(
			const string& sqlstr
			, WdbeJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMUserState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMUserState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJMUserState::insertRec(
			WdbeJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMUserState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMUserState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJMUserState::insertRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJMUserState::updateRec(
			WdbeJMUserState* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
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

	res = PQexecPrepared(dbs, "TblWdbeJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMUserState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJMUserState::updateRst(
			ListWdbeJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMUserState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJMUserState::loadRecByRef(
			ubigint ref
			, WdbeJMUserState** rec
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

	return loadRecByStmt("TblWdbeJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJMUserState::loadRecByUsrSta(
			ubigint refWdbeMUser
			, uint x1Start
			, WdbeJMUserState** rec
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJMUserState::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJMUserState::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeJMUserState& rst
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

