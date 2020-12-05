/**
	* \file WdbeRMUserMUsergroup.cpp
	* database access for table TblWdbeRMUserMUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeRMUserMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMUserMUsergroup
 ******************************************************************************/

WdbeRMUserMUsergroup::WdbeRMUserMUsergroup(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const ubigint refWdbeMUsergroup
			, const uint ixWdbeVUserlevel
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->refWdbeMUsergroup = refWdbeMUsergroup;
	this->ixWdbeVUserlevel = ixWdbeVUserlevel;
};

bool WdbeRMUserMUsergroup::operator==(
			const WdbeRMUserMUsergroup& comp
		) {
	return false;
};

bool WdbeRMUserMUsergroup::operator!=(
			const WdbeRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMUserMUsergroup
 ******************************************************************************/

ListWdbeRMUserMUsergroup::ListWdbeRMUserMUsergroup() {
};

ListWdbeRMUserMUsergroup::ListWdbeRMUserMUsergroup(
			const ListWdbeRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMUserMUsergroup(*(src.nodes[i]));
};

ListWdbeRMUserMUsergroup::~ListWdbeRMUserMUsergroup() {
	clear();
};

void ListWdbeRMUserMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListWdbeRMUserMUsergroup::append(
			WdbeRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WdbeRMUserMUsergroup* ListWdbeRMUserMUsergroup::operator[](
			const uint ix
		) {
	WdbeRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMUserMUsergroup& ListWdbeRMUserMUsergroup::operator=(
			const ListWdbeRMUserMUsergroup& src
		) {
	WdbeRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMUserMUsergroup::operator==(
			const ListWdbeRMUserMUsergroup& comp
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

bool ListWdbeRMUserMUsergroup::operator!=(
			const ListWdbeRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMUserMUsergroup
 ******************************************************************************/

TblWdbeRMUserMUsergroup::TblWdbeRMUserMUsergroup() {
};

TblWdbeRMUserMUsergroup::~TblWdbeRMUserMUsergroup() {
};

bool TblWdbeRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWdbeRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWdbeRMUserMUsergroup::insertRec(
			WdbeRMUserMUsergroup* rec
		) {
	return 0;
};

ubigint TblWdbeRMUserMUsergroup::insertNewRec(
			WdbeRMUserMUsergroup** rec
			, const ubigint refWdbeMUser
			, const ubigint refWdbeMUsergroup
			, const uint ixWdbeVUserlevel
		) {
	ubigint retval = 0;
	WdbeRMUserMUsergroup* _rec = NULL;

	_rec = new WdbeRMUserMUsergroup(0, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMUserMUsergroup::appendNewRecToRst(
			ListWdbeRMUserMUsergroup& rst
			, WdbeRMUserMUsergroup** rec
			, const ubigint refWdbeMUser
			, const ubigint refWdbeMUsergroup
			, const uint ixWdbeVUserlevel
		) {
	ubigint retval = 0;
	WdbeRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMUserMUsergroup::insertRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWdbeRMUserMUsergroup::updateRec(
			WdbeRMUserMUsergroup* rec
		) {
};

void TblWdbeRMUserMUsergroup::updateRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWdbeRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WdbeRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWdbeRMUserMUsergroup::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWdbeRMUserMUsergroup::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWdbeRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	WdbeRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMUserMUsergroup
 ******************************************************************************/

MyTblWdbeRMUserMUsergroup::MyTblWdbeRMUserMUsergroup() :
			TblWdbeRMUserMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMUserMUsergroup::~MyTblWdbeRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMUserMUsergroup (refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMUserMUsergroup SET refWdbeMUser = ?, refWdbeMUsergroup = ?, ixWdbeVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblWdbeRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMUserMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMUserMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->refWdbeMUsergroup = atoll((char*) dbrow[2]); else _rec->refWdbeMUsergroup = 0;
		if (dbrow[3]) _rec->ixWdbeVUserlevel = atol((char*) dbrow[3]); else _rec->ixWdbeVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMUserMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMUserMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->refWdbeMUsergroup = atoll((char*) dbrow[2]); else rec->refWdbeMUsergroup = 0;
			if (dbrow[3]) rec->ixWdbeVUserlevel = atol((char*) dbrow[3]); else rec->ixWdbeVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMUserMUsergroup::insertRec(
			WdbeRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMUserMUsergroup::insertRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMUserMUsergroup::updateRec(
			WdbeRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMUserMUsergroup::updateRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMUserMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WdbeRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMUserMUsergroup::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel FROM TblWdbeRMUserMUsergroup WHERE refWdbeMUsergroup = " + to_string(refWdbeMUsergroup) + "", append, rst);
};

ubigint MyTblWdbeRMUserMUsergroup::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel FROM TblWdbeRMUserMUsergroup WHERE refWdbeMUser = " + to_string(refWdbeMUser) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMUserMUsergroup
 ******************************************************************************/

PgTblWdbeRMUserMUsergroup::PgTblWdbeRMUserMUsergroup() :
			TblWdbeRMUserMUsergroup()
			, PgTable()
		{
};

PgTblWdbeRMUserMUsergroup::~PgTblWdbeRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMUserMUsergroup::initStatements() {
	createStatement("TblWdbeRMUserMUsergroup_insertRec", "INSERT INTO TblWdbeRMUserMUsergroup (refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeRMUserMUsergroup_updateRec", "UPDATE TblWdbeRMUserMUsergroup SET refWdbeMUser = $1, refWdbeMUsergroup = $2, ixWdbeVUserlevel = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeRMUserMUsergroup_removeRecByRef", "DELETE FROM TblWdbeRMUserMUsergroup WHERE ref = $1", 1);

	createStatement("TblWdbeRMUserMUsergroup_loadRecByRef", "SELECT ref, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel FROM TblWdbeRMUserMUsergroup WHERE ref = $1", 1);
	createStatement("TblWdbeRMUserMUsergroup_loadRstByUsg", "SELECT ref, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel FROM TblWdbeRMUserMUsergroup WHERE refWdbeMUsergroup = $1", 1);
	createStatement("TblWdbeRMUserMUsergroup_loadRstByUsr", "SELECT ref, refWdbeMUser, refWdbeMUsergroup, ixWdbeVUserlevel FROM TblWdbeRMUserMUsergroup WHERE refWdbeMUser = $1", 1);
};

bool PgTblWdbeRMUserMUsergroup::loadRec(
			PGresult* res
			, WdbeRMUserMUsergroup** rec
		) {
	char* ptr;

	WdbeRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "ixwdbevuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWdbeVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "ixwdbevuserlevel")
		};

		while (numread < numrow) {
			rec = new WdbeRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWdbeVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMUserMUsergroup::insertRec(
			WdbeRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_refWdbeMUsergroup,
		(char*) &_ixWdbeVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMUserMUsergroup::insertRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMUserMUsergroup::updateRec(
			WdbeRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_refWdbeMUsergroup,
		(char*) &_ixWdbeVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMUserMUsergroup::updateRst(
			ListWdbeRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMUserMUsergroup::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WdbeRMUserMUsergroup** rec
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

	return loadRecByStmt("TblWdbeRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMUserMUsergroup::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	ubigint _refWdbeMUsergroup = htonl64(refWdbeMUsergroup);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMUserMUsergroup::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeRMUserMUsergroup& rst
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

