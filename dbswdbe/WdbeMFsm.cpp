/**
	* \file WdbeMFsm.cpp
	* database access for table TblWdbeMFsm (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMFsm.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMFsm
 ******************************************************************************/

WdbeMFsm::WdbeMFsm(
			const ubigint ref
			, const ubigint refWdbeMProcess
		) {

	this->ref = ref;
	this->refWdbeMProcess = refWdbeMProcess;
};

bool WdbeMFsm::operator==(
			const WdbeMFsm& comp
		) {
	return false;
};

bool WdbeMFsm::operator!=(
			const WdbeMFsm& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMFsm
 ******************************************************************************/

ListWdbeMFsm::ListWdbeMFsm() {
};

ListWdbeMFsm::ListWdbeMFsm(
			const ListWdbeMFsm& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMFsm(*(src.nodes[i]));
};

ListWdbeMFsm::~ListWdbeMFsm() {
	clear();
};

void ListWdbeMFsm::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMFsm::size() const {
	return(nodes.size());
};

void ListWdbeMFsm::append(
			WdbeMFsm* rec
		) {
	nodes.push_back(rec);
};

WdbeMFsm* ListWdbeMFsm::operator[](
			const uint ix
		) {
	WdbeMFsm* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMFsm& ListWdbeMFsm::operator=(
			const ListWdbeMFsm& src
		) {
	WdbeMFsm* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMFsm(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMFsm::operator==(
			const ListWdbeMFsm& comp
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

bool ListWdbeMFsm::operator!=(
			const ListWdbeMFsm& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMFsm
 ******************************************************************************/

TblWdbeMFsm::TblWdbeMFsm() {
};

TblWdbeMFsm::~TblWdbeMFsm() {
};

bool TblWdbeMFsm::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsm** rec
		) {
	return false;
};

ubigint TblWdbeMFsm::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsm& rst
		) {
	return 0;
};

ubigint TblWdbeMFsm::insertRec(
			WdbeMFsm* rec
		) {
	return 0;
};

ubigint TblWdbeMFsm::insertNewRec(
			WdbeMFsm** rec
			, const ubigint refWdbeMProcess
		) {
	ubigint retval = 0;
	WdbeMFsm* _rec = NULL;

	_rec = new WdbeMFsm(0, refWdbeMProcess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMFsm::appendNewRecToRst(
			ListWdbeMFsm& rst
			, WdbeMFsm** rec
			, const ubigint refWdbeMProcess
		) {
	ubigint retval = 0;
	WdbeMFsm* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMProcess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMFsm::insertRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
};

void TblWdbeMFsm::updateRec(
			WdbeMFsm* rec
		) {
};

void TblWdbeMFsm::updateRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
};

void TblWdbeMFsm::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMFsm::loadRecByRef(
			ubigint ref
			, WdbeMFsm** rec
		) {
	return false;
};

bool TblWdbeMFsm::loadRecByPrc(
			ubigint refWdbeMProcess
			, WdbeMFsm** rec
		) {
	return false;
};

ubigint TblWdbeMFsm::loadRefsByPrc(
			ubigint refWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMFsm::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMFsm& rst
		) {
	ubigint numload = 0;
	WdbeMFsm* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMFsm
 ******************************************************************************/

MyTblWdbeMFsm::MyTblWdbeMFsm() :
			TblWdbeMFsm()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMFsm::~MyTblWdbeMFsm() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMFsm::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMFsm (refWdbeMProcess) VALUES (?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMFsm SET refWdbeMProcess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMFsm WHERE ref = ?", false);
};

bool MyTblWdbeMFsm::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsm** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMFsm* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFsm::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFsm::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeMFsm();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMProcess = atoll((char*) dbrow[1]); else _rec->refWdbeMProcess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMFsm::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsm& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMFsm* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFsm::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFsm::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeMFsm();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMProcess = atoll((char*) dbrow[1]); else rec->refWdbeMProcess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMFsm::insertRec(
			WdbeMFsm* rec
		) {
	unsigned long l[1]; my_bool n[1]; my_bool e[1];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMProcess,&(l[0]),&(n[0]),&(e[0]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMFsm::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMFsm::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMFsm::insertRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMFsm::updateRec(
			WdbeMFsm* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMProcess,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->ref,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMFsm::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMFsm::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMFsm::updateRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMFsm::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMFsm::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMFsm::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMFsm::loadRecByRef(
			ubigint ref
			, WdbeMFsm** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMFsm WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMFsm::loadRecByPrc(
			ubigint refWdbeMProcess
			, WdbeMFsm** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMProcess FROM TblWdbeMFsm WHERE refWdbeMProcess = " + to_string(refWdbeMProcess) + "", rec);
};

ubigint MyTblWdbeMFsm::loadRefsByPrc(
			ubigint refWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMFsm WHERE refWdbeMProcess = " + to_string(refWdbeMProcess) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMFsm
 ******************************************************************************/

PgTblWdbeMFsm::PgTblWdbeMFsm() :
			TblWdbeMFsm()
			, PgTable()
		{
};

PgTblWdbeMFsm::~PgTblWdbeMFsm() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMFsm::initStatements() {
	createStatement("TblWdbeMFsm_insertRec", "INSERT INTO TblWdbeMFsm (refWdbeMProcess) VALUES ($1) RETURNING ref", 1);
	createStatement("TblWdbeMFsm_updateRec", "UPDATE TblWdbeMFsm SET refWdbeMProcess = $1 WHERE ref = $2", 2);
	createStatement("TblWdbeMFsm_removeRecByRef", "DELETE FROM TblWdbeMFsm WHERE ref = $1", 1);

	createStatement("TblWdbeMFsm_loadRecByRef", "SELECT ref, refWdbeMProcess FROM TblWdbeMFsm WHERE ref = $1", 1);
	createStatement("TblWdbeMFsm_loadRecByPrc", "SELECT ref, refWdbeMProcess FROM TblWdbeMFsm WHERE refWdbeMProcess = $1", 1);
	createStatement("TblWdbeMFsm_loadRefsByPrc", "SELECT ref FROM TblWdbeMFsm WHERE refWdbeMProcess = $1", 1);
};

bool PgTblWdbeMFsm::loadRec(
			PGresult* res
			, WdbeMFsm** rec
		) {
	char* ptr;

	WdbeMFsm* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMFsm();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemprocess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMProcess = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMFsm::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMFsm& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMFsm* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemprocess")
		};

		while (numread < numrow) {
			rec = new WdbeMFsm();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMProcess = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMFsm::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMFsm** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsm::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMFsm::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsm** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsm::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFsm::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsm& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsm::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMFsm::insertRec(
			WdbeMFsm* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMProcess = htonl64(rec->refWdbeMProcess);

	const char* vals[] = {
		(char*) &_refWdbeMProcess
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeMFsm_insertRec", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsm::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMFsm::insertRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMFsm::updateRec(
			WdbeMFsm* rec
		) {
	PGresult* res;

	ubigint _refWdbeMProcess = htonl64(rec->refWdbeMProcess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMProcess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMFsm_updateRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFsm::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMFsm::updateRst(
			ListWdbeMFsm& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMFsm::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMFsm_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFsm::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMFsm::loadRecByRef(
			ubigint ref
			, WdbeMFsm** rec
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

	return loadRecByStmt("TblWdbeMFsm_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMFsm::loadRecByPrc(
			ubigint refWdbeMProcess
			, WdbeMFsm** rec
		) {
	ubigint _refWdbeMProcess = htonl64(refWdbeMProcess);

	const char* vals[] = {
		(char*) &_refWdbeMProcess
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMFsm_loadRecByPrc", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMFsm::loadRefsByPrc(
			ubigint refWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMProcess = htonl64(refWdbeMProcess);

	const char* vals[] = {
		(char*) &_refWdbeMProcess
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMFsm_loadRefsByPrc", 1, vals, l, f, append, refs);
};

#endif
