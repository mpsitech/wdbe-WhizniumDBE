/**
	* \file WdbeMSession.cpp
	* database access for table TblWdbeMSession (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMSession.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMSession
 ******************************************************************************/

WdbeMSession::WdbeMSession(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool WdbeMSession::operator==(
			const WdbeMSession& comp
		) {
	return false;
};

bool WdbeMSession::operator!=(
			const WdbeMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMSession
 ******************************************************************************/

ListWdbeMSession::ListWdbeMSession() {
};

ListWdbeMSession::ListWdbeMSession(
			const ListWdbeMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMSession(*(src.nodes[i]));
};

ListWdbeMSession::~ListWdbeMSession() {
	clear();
};

void ListWdbeMSession::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMSession::size() const {
	return(nodes.size());
};

void ListWdbeMSession::append(
			WdbeMSession* rec
		) {
	nodes.push_back(rec);
};

WdbeMSession* ListWdbeMSession::operator[](
			const uint ix
		) {
	WdbeMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMSession& ListWdbeMSession::operator=(
			const ListWdbeMSession& src
		) {
	WdbeMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMSession::operator==(
			const ListWdbeMSession& comp
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

bool ListWdbeMSession::operator!=(
			const ListWdbeMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMSession
 ******************************************************************************/

TblWdbeMSession::TblWdbeMSession() {
};

TblWdbeMSession::~TblWdbeMSession() {
};

bool TblWdbeMSession::loadRecBySQL(
			const string& sqlstr
			, WdbeMSession** rec
		) {
	return false;
};

ubigint TblWdbeMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSession& rst
		) {
	return 0;
};

ubigint TblWdbeMSession::insertRec(
			WdbeMSession* rec
		) {
	return 0;
};

ubigint TblWdbeMSession::insertNewRec(
			WdbeMSession** rec
			, const ubigint refWdbeMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WdbeMSession* _rec = NULL;

	_rec = new WdbeMSession(0, refWdbeMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMSession::appendNewRecToRst(
			ListWdbeMSession& rst
			, WdbeMSession** rec
			, const ubigint refWdbeMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WdbeMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMSession::insertRst(
			ListWdbeMSession& rst
			, bool transact
		) {
};

void TblWdbeMSession::updateRec(
			WdbeMSession* rec
		) {
};

void TblWdbeMSession::updateRst(
			ListWdbeMSession& rst
			, bool transact
		) {
};

void TblWdbeMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMSession::loadRecByRef(
			ubigint ref
			, WdbeMSession** rec
		) {
	return false;
};

ubigint TblWdbeMSession::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSession::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeMSession& rst
		) {
	return 0;
};

ubigint TblWdbeMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMSession& rst
		) {
	ubigint numload = 0;
	WdbeMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMSession
 ******************************************************************************/

MyTblWdbeMSession::MyTblWdbeMSession() :
			TblWdbeMSession()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMSession::~MyTblWdbeMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMSession (refWdbeMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMSession SET refWdbeMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMSession WHERE ref = ?", false);
};

bool MyTblWdbeMSession::loadRecBySQL(
			const string& sqlstr
			, WdbeMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSession::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSession::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSession::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSession::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMSession::insertRec(
			WdbeMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMSession::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMSession::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMSession::insertRst(
			ListWdbeMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMSession::updateRec(
			WdbeMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMSession::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMSession::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMSession::updateRst(
			ListWdbeMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMSession::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMSession::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMSession::loadRecByRef(
			ubigint ref
			, WdbeMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMSession WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMSession::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSession WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblWdbeMSession::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeMSession& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, start, stop, Ip FROM TblWdbeMSession WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " ORDER BY start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMSession
 ******************************************************************************/

PgTblWdbeMSession::PgTblWdbeMSession() :
			TblWdbeMSession()
			, PgTable()
		{
};

PgTblWdbeMSession::~PgTblWdbeMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMSession::initStatements() {
	createStatement("TblWdbeMSession_insertRec", "INSERT INTO TblWdbeMSession (refWdbeMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMSession_updateRec", "UPDATE TblWdbeMSession SET refWdbeMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMSession_removeRecByRef", "DELETE FROM TblWdbeMSession WHERE ref = $1", 1);

	createStatement("TblWdbeMSession_loadRecByRef", "SELECT ref, refWdbeMUser, start, stop, Ip FROM TblWdbeMSession WHERE ref = $1", 1);
	createStatement("TblWdbeMSession_loadRefsByUsr", "SELECT ref FROM TblWdbeMSession WHERE refWdbeMUser = $1 ORDER BY start ASC", 1);
	createStatement("TblWdbeMSession_loadRstByUsr", "SELECT ref, refWdbeMUser, start, stop, Ip FROM TblWdbeMSession WHERE refWdbeMUser = $1 ORDER BY start ASC", 1);
};

bool PgTblWdbeMSession::loadRec(
			PGresult* res
			, WdbeMSession** rec
		) {
	char* ptr;

	WdbeMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMSession::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new WdbeMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSession::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSession::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMSession& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSession::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMSession::loadRecBySQL(
			const string& sqlstr
			, WdbeMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSession::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSession::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMSession::insertRec(
			WdbeMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMSession_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSession::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMSession::insertRst(
			ListWdbeMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMSession::updateRec(
			WdbeMSession* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSession::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMSession::updateRst(
			ListWdbeMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMSession::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSession::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMSession::loadRecByRef(
			ubigint ref
			, WdbeMSession** rec
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

	return loadRecByStmt("TblWdbeMSession_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMSession::loadRefsByUsr(
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

	return loadRefsByStmt("TblWdbeMSession_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSession::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeMSession& rst
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSession_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

